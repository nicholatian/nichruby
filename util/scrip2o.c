/* -*- coding: utf-8 */
/*
 * PokéScrip bytecode serialiser
 *
 * This file converts PokéScrip text files into their binary equivalents.
 * PokéScrip is a low-level format designed to have a 1:1 semantic correlation
 * with the scripting bytecode used in the third generation core series
 * Pokémon games for the Nintendo® Game Boy Advance™. It can serve either as a
 * concise, close-to-the-metal way to write scripts for these game engines, or
 * as a target for higher-level languages, including PretScript and PKS2. The
 * format is on the same level as the PokéSnip text encoding format.
 */

#include <glib.h>

#define U8_COPY "\302\251"
#define U8_EACUTE "\303\251"
#define U8_L_APOS "\342\200\230"
#define U8_R_APOS "\342\200\231"
#define COPY_YEARS "2019-2020"

typedef guint8 u8;
typedef guint16 u16;
typedef guint32 u32;
typedef guint64 u64;
typedef gint8 s8;
typedef gint16 s16;
typedef gint32 s32;
typedef gint64 s64;

typedef gsize ptri;

enum regexps
{
	EXPR_COMMENT,
	EXPR_EMPTY,
	EXPR_IFDEF,
	EXPR_IF,
	EXPR_ELSE,
	EXPR_ENDIF,
	EXPR_EXPORT,
	EXPR_IMPORT,
	EXPR_DEFINE,
	EXPR_UNDEF,
	EXPR_INFO,
	EXPR_WARN,
	EXPR_FATAL,
	EXPR_BYTE,
	EXPR_HWORD,
	EXPR_WORD,
	EXPR_COMMAND,
	EXPR_LABEL,
	MAX_EXPR
};

enum
{
	TOK_COMMENT,
	TOK_LABEL,
	TOK_COMMAND,
	TOK_CMDARG,
	TOK_DIREC,
	TOK_DIRECARG,
	MAX_TOK
};

struct tok
{
	u8 type;
	const char* start;
	ptri sz;
};

struct tok_arr
{
	struct tok* val;
	ptri sz;
};

struct cmdarg
{
	/* exponent of 2 to get arg size in bytes */
	u8 sz : 2;
	/* is arg required */
	u8 req : 1;
};

struct cmd
{
	const char* name;
	u8 byte;
	struct cmdarg* arg;
	ptri arg_sz;
};

/* NOTE: this string is manually UTF-8 encoded */
static const char* const helptxt_u8 =
	"Pok" U8_EACUTE "Scrip bytecode serialiser\nCopyright " U8_COPY " " COPY_YEARS " Alexander Nicholi. Released under BSD-2-clause\n\nUsage:-\n\n    scrip2o <input> [output]\n\n    Takes <input>, a Pok" U8_EACUTE "Scrip source file, and serialises it into bytecode,\n    passing symbol resolution to the linker transparently by outputting an\n    object code file at [output] (or stdout if omitted). If <input> is " U8_L_APOS "-" U8_R_APOS ",\n    stdin will be read.\n\n";
static const char* const helptxt_asc =
	"PokeScrip bytecode serialiser\nCopyright (C) " COPY_YEARS " Alexander Nicholi. Released under BSD-2-clause\n\nUsage:-\n\n    scrip2o <input> [output]\n\n    Takes <input>, a PokeScrip source file, and serialises it into bytecode,\n    passing symbol resolution to the linker transparently by outputting an\n    object code file at [output] (or stdout if omitted). If <input> is '-',\n    stdin will be read.\n\n";

static const struct cmd commands[256] = {
	{"nop0", 0x00, NULL, 0},
	{"nop1", 0x01, NULL, 0},
	{"end", 0x02, NULL, 0},
	{"return", 0x03, NULL, 0},
	{"call", 0x04, {{2, 1}}, 1},
	{"jump", 0x05, {{2, 1}}, 1},
	{"jumpif", 0x06, {{0, 1}, {2, 1}}, 2},
	{"callif", 0x07, {{0, 1}, {2, 1}}, 2},
	{"jumpstd", 0x08, {{0, 1}}, 1},
	{"callstd", 0x09, {{0, 1}}, 1},
	{"jumpstdif", 0x0A, {{0, 1}, {0, 1}}, 2},
	{"callstdif", 0x0B, {{0, 1}, {0, 1}}, 2},
	{"returnram", 0x0C, NULL, 0},
	{"die", 0x0D, NULL, 0},
	{"setmvar", 0x0E, {{0, 1}}, 1},
	{"loadword", 0x0F, {{0, 1}, {2, 1}}, 2},
	{"loadbyte", 0x10, {{0, 1}, {0, 1}}, 2},
	{"writebytetoaddr", 0x11, {{0, 1}, {2, 1}}, 2},
	{"loadbytefromaddr", 0x12, {{0, 1}, {2, 1}}, 2},
	{"setptrbyte", 0x13, {{0, 1}, {2, 1}}, 2},
	{"copylocal", 0x14, {{0, 1}, {0, 1}}, 2},
	{"copybyte", 0x15, {{2, 1}, {2, 1}}, 2},
	{"setvar", 0x16, {{1, 1}, {1, 1}}, 2},
	{"addvar", 0x17, {{1, 1}, {1, 1}}, 2},
	{"subvar", 0x18, {{1, 1}, {1, 1}}, 2},
	{"copyvar", 0x19, {{1, 1}, {1, 1}}, 2},
	{"setorcopyvar", 0x1A, {{1, 1}, {1, 1}}, 2}, /* copyvarifnotzero */
	{"cmploc2loc", 0x1B, {{0, 1}, {0, 1}}, 2},
	{"cmploc2val", 0x1C, {{0, 1}, {0, 1}}, 2},
	{"cmploc2addr", 0x1D, {{0, 1}, {2, 1}}, 2},
	{"cmpaddr2loc", 0x1E, {{2, 1}, {0, 1}}, 2},
	{"cmpaddr2val", 0x1F, {{2, 1}, {0, 1}}, 2},
	{"cmpaddr2addr", 0x20, {{2, 1}, {2, 1}}, 2},
	{"cmpvar2val", 0x21, {{1, 1}, {1, 1}}, 2},
	{"cmpvar2var", 0x22, {{1, 1}, {1, 1}}, 2},
	{"callnative", 0x23, {{2, 1}}, 1},
	{"jumpnative", 0x24, {{2, 1}}, 1},
	{"special", 0x25, {{2, 1}}, 1},
	{"specialvar", 0x26, {{1, 1}, {1, 1}}, 2},
	{"waitstate", 0x27, NULL, 0},
	{"pause", 0x28, {{2, 1}}, 1},
	{"setflag", 0x29, {{2, 1}}, 1},
	{"clearflag", 0x2A, {{2, 1}}, 1},
	{"checkflag", 0x2B, {{2, 1}}, 1},
	{"initclock", 0x2C, {{1, 1}, {1, 1}}, 2},
	{"doclockevents", 0x2D, NULL, 0},
	{"getclock", 0x2E, NULL, 0},
	{"playsfx", 0x2F, {{2, 1}}, 1},
	{"waitsfx", 0x30, NULL, 0},
	{"playfanfare", 0x31, {{2, 1}}, 1},
	{"waitfanfare", 0x32, NULL, 0},
	{"playsong", 0x33, {{1, 1}, {0, 1}}, 2},
	{"savesong", 0x34, {{2, 1}}, 1},
	{"fadesongdef", 0x35, NULL, 0},
	{"fadesongnew", 0x36, {{2, 1}}, 1},
	{"fadesongout", 0x37, {{0, 1}}, 1},
	{"fadesongin", 0x38, {{0, 1}}, 1},
	{"warp", 0x39, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"warpsilent", 0x3A, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"warpdoor", 0x3B, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"warphole", 0x3C, {{2, 1}}, 1},
	{"warpteleport", 0x3D, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"setwarp", 0x3E, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"set127warp", 0x3F, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"setdivewarp", 0x40, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"setholewarp", 0x41, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"getplayerxy", 0x42, {{1, 1}, {1, 1}}, 2},
	{"getpartysize", 0x43, NULL, 0},
	{"additem", 0x44, {{1, 1}, {1, 1}}, 2},
	{"removeitem", 0x45, {{1, 1}, {1, 1}}, 2},
	{"checkitemspace", 0x46, {{1, 1}, {1, 1}}, 2},
	{"checkitem", 0x47, {{1, 1}, {1, 1}}, 2},
	{"checkitemtype", 0x48, {{2, 1}}, 1},
	{"addpcitem", 0x49, {{1, 1}, {1, 1}}, 2},
	{"checkpcitem", 0x4A, {{1, 1}, {1, 1}}, 2},
	{"adddecor", 0x4B, {{2, 1}}, 1},
	{"removedecor", 0x4C, {{2, 1}}, 1},
	{"checkdecor", 0x4D, {{2, 1}}, 1},
	{"checkdecorspace", 0x4E, {{2, 1}}, 1},
	{"domovmnt", 0x4F, {{1, 1}, {2, 1}, {1, 0}}, 3},
	{"domovmntmap", 0x50, {{1, 1}, {2, 1}, {1, 1}}, 3},
	{"waitmovmnt", 0x51, {{2, 1}}, 1},
	{"waitmovmntmap", 0x52, {{1, 1}, {1, 1}}, 2},
	{"removeobject", 0x53, {{2, 1}}, 1},
	{"removeobjectmap", 0x54, {{1, 1}, {1, 1}}, 2},
	{"addobject", 0x55, {{2, 1}}, 1},
	{"addobjectmap", 0x56, {{1, 1}, {1, 1}}, 2},
	{"setobjectxy", 0x57, {{1, 1}, {1, 1}, {1, 1}}, 3},
	{"showobjectat", 0x58, {{1, 1}, {1, 1}}, 2},
	{"hideobjectat", 0x59, {{1, 1}, {1, 1}}, 2},
	{"faceplayer", 0x5A, NULL, 0},
	{"turnobject", 0x5B, {{1, 1}, {0, 1}}, 2},
	{"tbattle", 0x5C, {
		{1, 1}, {1, 1}, {1, 1}, {2, 1},
		{4, 0}, {2, 0}, {2, 0}
		}, 7},
	{"tbattlestart", 0x5D, NULL, 0},
	{"jumpafterbattle", 0x5E, NULL, 0},
	{"jumpbeatenbattle", 0x5F, NULL, 0},
	{"checktflag", 0x60, {{2, 1}}, 1},
	{"settflag", 0x61, {{2, 1}}, 1},
	{"cleartflag", 0x62, {{2, 1}}, 1},
	{"setobjectxyperm", 0x63, {{1, 1}, {1, 1}, {1, 1}}, 3},
	{"moveobjectoffscreen", 0x64, {{2, 1}}, 1},
	{"setobjectmovmnt", 0x65, {{1, 1}, {0, 1}}, 2},
	{"waitmessage", 0x66, NULL, 0},
	{"message", 0x67, {{2, 1}}, 1},
	{"closemessage", 0x68, NULL, 0},
	{"lockall", 0x69, NULL, 0},
	{"lock", 0x6A, NULL, 0},
	{"releaseall", 0x6B, NULL, 0},
	{"release", 0x6C, NULL, 0},
	{"waitbutton", 0x6D, NULL, 0},
	{"yesnobox", 0x6E, {{0, 1}, {0, 1}}, 2},
	{"multichoice", 0x6F, {{0, 1}, {0, 1}, {0, 1}, {0, 1}}, 4},
	{"multichoicesel", 0x70, {{0, 1}, {0, 1}, {0, 1},
	                              {1, 1}, {0, 1}}, 5},
	{"multichoicegrid", 0x71, {{0, 1}, {0, 1}, {0, 1}, {0, 1},
	                           {1, 1}}, 5},
	{"drawbox", 0x72, NULL, 0},
	{"erasebox", 0x73, {{0, 1}, {0, 1}, {0, 1}, {0, 1}}, 4},
	{"drawboxtext", 0x74, {{0, 1}, {0, 1}, {0, 1}, {0, 1}}, 4},
	{"drawpokepic", 0x75, {{1, 1}, {0, 1}, {0, 1}}, 3},
	{"erasepokepic", 0x76, NULL, 0},
	{"drawcontestwinner", 0x77, {{0, 1}}, 1},
	{"braille", 0x78, {{2, 1}}, 1},
	{"addmon", 0x79, {{1, 1}, {0, 1}, {1, 1}, {2, 1},
	                   {4, 1}, {0, 1}}, 6},
	{"addegg", 0x7A, {{2, 1}}, 1},
	{"setmonmove", 0x7B, {{0, 1}, {0, 1}, {1, 1}}, 3},
	{"checkpartymove", 0x7C, {{2, 1}}, 1},
	{"bufspecies", 0x7D, {{0, 1}, {1, 1}}, 2},
	{"bufleadspecies", 0x7E, {{0, 1}}, 1},
	{"bufnick", 0x7F, {{0, 1}, {1, 1}}, 2},
	{"bufitem", 0x80, {{0, 1}, {1, 1}}, 2},
	{"bufdecor", 0x81, {{0, 1}, {1, 1}}, 2},
	{"buffmove", 0x82, {{0, 1}, {1, 1}}, 2},
	{"bufdecimal", 0x83, {{0, 1}, {1, 1}}, 2},
	{"buftextfmt", 0x84, {{0, 1}, {1, 1}}, 2},
	{"buftext", 0x85, {{0, 1}, {2, 1}}, 2},
	{"mart", 0x86, {{2, 1}}, 1},
	{"martdecor", 0x87, {{2, 1}}, 1},
	{"martdecor2", 0x88, {{2, 1}}, 1},
	{"playslots", 0x89, {{2, 1}}, 1},
	{"setberrytree", 0x8A, {{0, 1}, {0, 1}, {0, 1}}, 3},
	{"choosecontestmon", 0x8B, NULL, 0},
	{"startcontest", 0x8C, NULL, 0},
	{"showcontestresults", 0x8D, NULL, 0},
	{"contestlinktransfer", 0x8E, NULL, 0},
	{"random", 0x8F, {{2, 1}}, 1},
	{"addmoney", 0x90, {{2, 1}, {0, 1}}, 2},
	{"removemoney", 0x91, {{2, 1}, {0, 1}}, 2},
	{"checkmoney", 0x92, {{2, 1}, {0, 1}}, 2},
	{"showmoneybox", 0x93, {{0, 1}, {0, 1}, {0, 1}}, 3},
	{"hidemoneybox", 0x94, NULL, 0},
	{"updatemoneybox", 0x95, {{0, 1}, {0, 1}}, 2},
	{"getsaleprice", 0x96, {{2, 1}}, 1},
	{"fadescreen", 0x97, {{0, 1}}, 1},
	{"fadescreenspeed", 0x98, {{0, 1}, {0, 1}}, 2},
	{"setflash", 0x99, {{2, 1}}, 1},
	{"doflash", 0x9A, {{0, 1}}, 1},
	{"messagescroll", 0x9B, {{2, 1}}, 1},
	{"dofieldfx", 0x9C, {{2, 1}}, 1},
	{"setfieldfxarg", 0x9D, {{0, 1}, {1, 1}}, 2},
	{"waitfieldfx", 0x9E, {{2, 1}}, 1},
	{"setrespawn", 0x9F, {{2, 1}}, 1},
	{"checkgender", 0xA0, NULL, 0},
	{"playcry", 0xA1, {{1, 1}, {1, 1}}, 2},
	{"setblock", 0xA2, {{1, 1}, {1, 1}, {1, 1}, {1, 1}}, 4},
	{"resetweather", 0xA3, NULL, 0},
	{"setweather", 0xA4, {{2, 1}}, 1},
	{"doweather", 0xA5, NULL, 0},
	{"setstepcallback", 0xA6, {{0, 1}}, 1},
	{"setmaplayout", 0xA7, {{2, 1}}, 1},
	{"setobjectpriority", 0xA8, {{1, 1}, {1, 1}, {0, 1}}, 3},
	{"resetobjectpriority", 0xA9, {{1, 1}, {1, 1}}, 2},
	{"createvobject", 0xAA, {{1, 1}, {0, 1}, {1, 1}, {1, 1},
	                         {1, 1}, {0, 1}}, 6},
	{"turnvobject", 0xAB, {{0, 1}, {0, 1}}, 2},
	{"opendoor", 0xAC, {{1, 1}, {1, 1}}, 2},
	{"closedoor", 0xAD, {{1, 1}, {1, 1}}, 2},
	{"waitdooranim", 0xAE, NULL, 0},
	{"setdooropen", 0xAF, {{1, 1}, {1, 1}}, 2},
	{"setdoorclosed", 0xB0, {{1, 1}, {1, 1}}, 2},
	{"addelevmenuitem", 0xB1, {{0, 1}, {1, 1}, {1, 1},
	                           {2, 1}}, 4},
	{"showelevmenu", 0xB2, NULL, 0},
	{"checkcoins", 0xB3, {{2, 1}}, 1},
	{"addcoins", 0xB4, {{2, 1}}, 1},
	{"removecoins", 0xB5, {{2, 1}}, 1},
	{"setwildbattle", 0xB6, {{1, 1}, {0, 1}, {1, 1}}, 3},
	{"dowildbattle", 0xB7, NULL, 0},
	{"setvaddress", 0xB8, {{2, 1}}, 1},
	{"vjump", 0xB9, {{2, 1}}, 1},
	{"vcall", 0xBA, {{2, 1}}, 1},
	{"vjumpif", 0xBB, {{0, 1}, {2, 1}}, 2},
	{"vcallif", 0xBC, {{0, 1}, {2, 1}}, 2},
	{"vmessage", 0xBD, {{2, 1}}, 1},
	{"vloadptr", 0xBE, {{2, 1}}, 1},
	{"vbuftext", 0xBF, {{0, 1}, {2, 1}}, 2},
	{"showcoinsbox", 0xC0, {{0, 1}, {0, 1}}, 2},
	{"hidecoinsbox", 0xC1, {{0, 1}, {0, 1}}, 2},
	{"updatecoinsbox", 0xC2, {{0, 1}, {0, 1}}, 2},
	{"incrgamestat", 0xC3, {{0, 1}}, 1},
	{"setescapewarp", 0xC4, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"waitcry", 0xC5, NULL, 0},
	{"bufboxname", 0xC6, {{0, 1}, {1, 1}}, 2},
	{"textcolor", 0xC7, {{0, 1}}, 1},
	{"loadhelp", 0xC8, {{2, 1}}, 1},
	{"unloadhelp", 0xC9, {{2, 1}}, 1},
	{"signmsg", 0xCA, NULL, 0},
	{"normalmsg", 0xCB, NULL, 0},
	{"cmphvar", 0xCC, {{0, 1}, {2, 1}}, 2},
	{"setobedient", 0xCD, {{2, 1}}, 1},
	{"checkobedience", 0xCE, {{2, 1}}, 1},
	{"jumpram", 0xCF, NULL, 0},
	{"setwmapflag", 0xD0, {{2, 1}}, 1},
	{"warpteleport2", 0xD1, {{0, 1}, {1, 1}, {0, 1}, {1, 1},
	                         {2, 1}}, 5},
	{"setmetloc", 0xD2, {{1, 1}, {0, 1}}, 2},
	{"mossdeepgym1", 0xD3, {{2, 1}}, 1},
	{"mossdeepgym2", 0xD4, NULL, 0},
	{"mossdeepgym3", 0xD5, {{2, 1}}, 1},
	{"mossdeepgym4", 0xD6, NULL, 0},
	{"warp7", 0xD7, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"cmdD8", 0xD8, NULL, 0},
	{"cmdD9", 0xD9, NULL, 0},
	{"hidebox2", 0xDA, NULL, 0},
	{"message3", 0xDB, {{2, 1}}, 1},
	{"fadescreenswapbufs", 0xDC, {{0, 1}, {1, 1}}, 2},
	{"bufclass", 0xDD, {{0, 1}, {1, 1}}, 2},
	{"buftrainer", 0xDE, {{0, 1}, {1, 1}}, 2},
	{"navcall", 0xDF, {{2, 1}}, 1},
	{"warp8", 0xE0, {{1, 1}, {0, 1}, {1, 1}, {1, 1}}, 4},
	{"bufcontesttype", 0xE1, {{0, 1}, {1, 1}}, 2},
	{"bufitemplural", 0xE2, {{0, 1}, {1, 1}, {1, 1}}, 3}
};

/*
 * GRAMMAR EXPLAIN
 *
 * label:
 * <command> [arg0, [arg1, [arg2, ...]]]
 *
 * # script blocks terminated by empty line
 *
 * #define A <val...>
 * # val may be an integer or another previously defined constant
 *
 * #info "<text>"
 * # prints a message at compile time, with an automatic newline.
 * # see string parsing meta for details
 *
 * #warn "<text>"
 * # prints a warning at compile time, with an automatic newline.
 * # see string parsing meta for details
 *
 * #fatal
 * #fatal "<text>"
 * # halts compilation, with a variant that takes a string to print (incl.
 * # automatic newline). will print a stack trace as well, see string parsing
 * # meta for details
 *
 * #undef A
 * # undefine a previously defined constant. errors if it was already undefined
 *
 * #if[n]def A
 * # conditional logic in the scrip meta, based on definition
 *
 * #if A {==,!=,<,>,<=,>=} B
 * # conditional logic in the scrip meta, based on comparison
 *
 * #endif
 * # used with #if[[n]def] to close blocks
 *
 * /* comment */
#if 0
 * #define LASTRESULT 0x800D
 * #define MYOCTAL 0o755
 * #ifndef PLAYERFACING
 * #define PLAYERFACING 0x800E
 * #endif /* PLAYERFACING */
#endif
/*
 *
 * #import "foreigndefs.scrip"
 * # this imports all exported labels from the scrip file named for use here
 *
 * label:
 * <commands ...>
 *
 * #export label
 * # exports label for other files to use, making it opaque to the linker
 *
 * #byte <byte literal> [...]
 * #hword <halfword literal> [...]
 * #word <word literal> [...]
 * # emit binary data from one or more literals.
 *
 * labels and #defines are properly orthogonal. only the former may ever emit
 * symbols, or have effect in the workings of #import or #export directives;
 * only the latter may be aliased, undefined, redefined, used in conditional
 * meta logic, or provided as data to directives or command arguments.
 *
 * strings do not exist in this language for emission by the generator at all,
 * so #defines cannot use them (the quotes in #imports are pure syntax).
 *
 * numeric literals may be presented in decimal (without leading zeroes), in
 * octal with prefix ‘0o’, in hexadecimal with prefix ‘0x’, or in binary with
 * prefix ‘0b’. Numeric literals may use apostrophes as purely cosmetic
 * separators to improve legibility.
 *
 * command statements are newline-terminated, and commands are separated from
 * their arguments by whitespace, as are the arguments from each other. blocks
 * of commands are terminated by a blank line.
 */

struct tok_arr lexer( const char* in )
{
	struct tok_arr ret;

	ret.val = g_malloc( sizeof( struct tok ) * 16 );
	ret.sz = 16;
}
