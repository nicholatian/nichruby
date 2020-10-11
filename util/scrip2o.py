#!/usr/bin/env python3
# -*- coding: utf-8 -*-
## PokéScrip bytecode serialiser
##
## This file converts PokéScrip text files into their binary equivalents.
## PokéScrip is a low-level format designed to have a 1:1 semantic correlation
## with the scripting bytecode used in the third generation core series Pokémon
## games for the Nintendo® Game Boy Advance™. It can serve either as a concise,
## close-to-the-metal way to write scripts for these game engines, or as a
## target for higher-level languages, including PretScript and PKS2. The format
## is on the same level as the PokéSnip text encoding format.
##
## This was developed by Alexander Nicholi for use in the Pokémon SwowS fanhack
## made with pokeemerald, a public endeavour. Although there is no licensing
## basis for the game itself, everything under legal copyright here is released
## under the BSD-2-clause licence. I hope you find good use in what I made.

HELP_TEXT = r'''PokéScrip bytecode serialiser
Copyright © 2019 Alexander Nicholi. Released under BSD-2-clause

Usage:-

    scrip2o <input> [output]

    Takes <input>, a PokéScrip source file, and serialises it into bytecode,
    passing symbol resolution to the linker transparently by outputting an
    object code file at [output] (or stdout if omitted). If <input> is ‘-’,
    stdin will be read.
'''

## LEXING:
## same as usual. line-based, lstrip/rstrip, space-separated, etc.

COMMANDS = [
	('nop0', 0x00, []),
	('nop1', 0x01, []),
	('end', 0x02, []),
	('return', 0x03, []),
	('call', 0x04, [(4, True)]),
	('jump', 0x05, [(4, True)]),
	('jumpif', 0x06, [(1, True), (4, True)]),
	('callif', 0x07, [(1, True), (4, True)]),
	('jumpstd', 0x08, [(1, True)]),
	('callstd', 0x09, [(1, True)]),
	('jumpstdif', 0x0A, [(1, True), (1, True)]),
	('callstdif', 0x0B, [(1, True), (1, True)]),
	('returnram', 0x0C, []),
	('die', 0x0D, []),
	('setmvar', 0x0E, [(1, True)]),
	('loadword', 0x0F, [(1, True), (4, True)]),
	('loadbyte', 0x10, [(1, True), (1, True)]),
	('writebytetoaddr', 0x11, [(1, True), (4, True)]),
	('loadbytefromaddr', 0x12, [(1, True), (4, True)]),
	('setptrbyte', 0x13, [(1, True), (4, True)]),
	('copylocal', 0x14, [(1, True), (1, True)]),
	('copybyte', 0x15, [(4, True), (4, True)]),
	('setvar', 0x16, [(2, True), (2, True)]),
	('addvar', 0x17, [(2, True), (2, True)]),
	('subvar', 0x18, [(2, True), (2, True)]),
	('copyvar', 0x19, [(2, True), (2, True)]),
	('setorcopyvar', 0x1A, [(2, True), (2, True)]), # copyvarifnotzero
	('cmploc2loc', 0x1B, [(1, True), (1, True)]),
	('cmploc2val', 0x1C, [(1, True), (1, True)]),
	('cmploc2addr', 0x1D, [(1, True), (4, True)]),
	('cmpaddr2loc', 0x1E, [(4, True), (1, True)]),
	('cmpaddr2val', 0x1F, [(4, True), (1, True)]),
	('cmpaddr2addr', 0x20, [(4, True), (4, True)]),
	('cmpvar2val', 0x21, [(2, True), (2, True)]),
	('cmpvar2var', 0x22, [(2, True), (2, True)]),
	('callnative', 0x23, [(4, True)]),
	('jumpnative', 0x24, [(4, True)]),
	('special', 0x25, [(2, True)]),
	('specialvar', 0x26, [(2, True), (2, True)]),
	('waitstate', 0x27, []),
	('pause', 0x28, [(2, True)]),
	('setflag', 0x29, [(2, True)]),
	('clearflag', 0x2A, [(2, True)]),
	('checkflag', 0x2B, [(2, True)]),
	('initclock', 0x2C, [(2, True), (2, True)]),
	('doclockevents', 0x2D, []),
	('getclock', 0x2E, []),
	('playsfx', 0x2F, [(2, True)]),
	('waitsfx', 0x30, []),
	('playfanfare', 0x31, [(2, True)]),
	('waitfanfare', 0x32, []),
	('playsong', 0x33, [(2, True), (1, True)]),
	('savesong', 0x34, [(2, True)]),
	('fadesongdef', 0x35, []),
	('fadesongnew', 0x36, [(2, True)]),
	('fadesongout', 0x37, [(1, True)]),
	('fadesongin', 0x38, [(1, True)]),
	('warp', 0x39, [(2, True), (1, True), (2, True), (2, True)]),
	('warpsilent', 0x3A, [(2, True), (1, True), (2, True), (2, True)]),
	('warpdoor', 0x3B, [(2, True), (1, True), (2, True), (2, True)]),
	('warphole', 0x3C, [(2, True)]),
	('warpteleport', 0x3D, [(2, True), (1, True), (2, True), (2, True)]),
	('setwarp', 0x3E, [(2, True), (1, True), (2, True), (2, True)]),
	('set127warp', 0x3F, [(2, True), (1, True), (2, True), (2, True)]),
	('setdivewarp', 0x40, [(2, True), (1, True), (2, True), (2, True)]),
	('setholewarp', 0x41, [(2, True), (1, True), (2, True), (2, True)]),
	('getplayerxy', 0x42, [(2, True), (2, True)]),
	('getpartysize', 0x43, []),
	('additem', 0x44, [(2, True), (2, True)]),
	('removeitem', 0x45, [(2, True), (2, True)]),
	('checkitemspace', 0x46, [(2, True), (2, True)]),
	('checkitem', 0x47, [(2, True), (2, True)]),
	('checkitemtype', 0x48, [(2, True)]),
	('addpcitem', 0x49, [(2, True), (2, True)]),
	('checkpcitem', 0x4A, [(2, True), (2, True)]),
	('adddecor', 0x4B, [(2, True)]),
	('removedecor', 0x4C, [(2, True)]),
	('checkdecor', 0x4D, [(2, True)]),
	('checkdecorspace', 0x4E, [(2, True)]),
	('domovmnt', 0x4F, [(2, True), (4, True), (2, False)]),
	('domovmntmap', 0x50, [(2, True), (4, True), (2, True)]),
	('waitmovmnt', 0x51, [(2, True)]),
	('waitmovmntmap', 0x52, [(2, True), (2, True)]),
	('removeobject', 0x53, [(2, True)]),
	('removeobjectmap', 0x54, [(2, True), (2, True)]),
	('addobject', 0x55, [(2, True)]),
	('addobjectmap', 0x56, [(2, True), (2, True)]),
	('setobjectxy', 0x57, [(2, True), (2, True), (2, True)]),
	('showobjectat', 0x58, [(2, True), (2, True)]),
	('hideobjectat', 0x59, [(2, True), (2, True)]),
	('faceplayer', 0x5A, []),
	('turnobject', 0x5B, [(2, True), (1, True)]),
	('tbattle', 0x5C, [
		(1, True), (2, True), (2, True), (4, True),
		(4, False), (4, False), (4, False)
	]),
	('tbattlestart', 0x5D, []),
	('jumpafterbattle', 0x5E, []),
	('jumpbeatenbattle', 0x5F, []),
	('checktflag', 0x60, [(2, True)]),
	('settflag', 0x61, [(2, True)]),
	('cleartflag', 0x62, [(2, True)]),
	('setobjectxyperm', 0x63, [(2, True), (2, True), (2, True)]),
	('moveobjectoffscreen', 0x64, [(2, True)]),
	('setobjectmovmnt', 0x65, [(2, True), (1, True)]),
	('waitmessage', 0x66, []),
	('message', 0x67, [(4, True)]),
	('closemessage', 0x68, []),
	('lockall', 0x69, []),
	('lock', 0x6A, []),
	('releaseall', 0x6B, []),
	('release', 0x6C, []),
	('waitbutton', 0x6D, []),
	('yesnobox', 0x6E, [(1, True), (1, True)]),
	('multichoice', 0x6F, [(1, True), (1, True), (1, True), (1, True)]),
	('multichoicesel', 0x70, [(1, True), (1, True), (1, True),
	                              (1, True), (1, True)]),
	('multichoicegrid', 0x71, [(1, True), (1, True), (1, True), (1, True),
	                           (1, True)]),
	('drawbox', 0x72, []),
	('erasebox', 0x73, [(1, True), (1, True), (1, True), (1, True)]),
	('drawboxtext', 0x74, [(1, True), (1, True), (1, True), (1, True)]),
	('drawpokepic', 0x75, [(2, True), (1, True), (1, True)]),
	('erasepokepic', 0x76, []),
	('drawcontestwinner', 0x77, [(1, True)]),
	('braille', 0x78, [(4, True)]),
	('addmon', 0x79, [(2, True), (1, True), (2, True), (4, True),
	                   (4, True), (1, True)]),
	('addegg', 0x7A, [(2, True)]),
	('setmonmove', 0x7B, [(1, True), (1, True), (2, True)]),
	('checkpartymove', 0x7C, [(2, True)]),
	('bufspecies', 0x7D, [(1, True), (2, True)]),
	('bufleadspecies', 0x7E, [(1, True)]),
	('bufnick', 0x7F, [(1, True), (2, True)]),
	('bufitem', 0x80, [(1, True), (2, True)]),
	('bufdecor', 0x81, [(1, True), (2, True)]),
	('buffmove', 0x82, [(1, True), (2, True)]),
	('bufdecimal', 0x83, [(1, True), (2, True)]),
	('buftextfmt', 0x84, [(1, True), (2, True)]),
	('buftext', 0x85, [(1, True), (4, True)]),
	('mart', 0x86, [(4, True)]),
	('martdecor', 0x87, [(4, True)]),
	('martdecor2', 0x88, [(4, True)]),
	('playslots', 0x89, [(2, True)]),
	('setberrytree', 0x8A, [(1, True), (1, True), (1, True)]),
	('choosecontestmon', 0x8B, []),
	('startcontest', 0x8C, []),
	('showcontestresults', 0x8D, []),
	('contestlinktransfer', 0x8E, []),
	('random', 0x8F, [(2, True)]),
	('addmoney', 0x90, [(4, True), (1, True)]),
	('removemoney', 0x91, [(4, True), (1, True)]),
	('checkmoney', 0x92, [(4, True), (1, True)]),
	('showmoneybox', 0x93, [(1, True), (1, True), (1, True)]),
	('hidemoneybox', 0x94, []),
	('updatemoneybox', 0x95, [(1, True), (1, True)]),
	('getsaleprice', 0x96, [(2, True)]),
	('fadescreen', 0x97, [(1, True)]),
	('fadescreenspeed', 0x98, [(1, True), (1, True)]),
	('setflash', 0x99, [(2, True)]),
	('doflash', 0x9A, [(1, True)]),
	('messagescroll', 0x9B, [(4, True)]),
	('dofieldfx', 0x9C, [(2, True)]),
	('setfieldfxarg', 0x9D, [(1, True), (2, True)]),
	('waitfieldfx', 0x9E, [(2, True)]),
	('setrespawn', 0x9F, [(2, True)]),
	('checkgender', 0xA0, []),
	('playcry', 0xA1, [(2, True), (2, True)]),
	('setblock', 0xA2, [(2, True), (2, True), (2, True), (2, True)]),
	('resetweather', 0xA3, []),
	('setweather', 0xA4, [(2, True)]),
	('doweather', 0xA5, []),
	('setstepcallback', 0xA6, [(1, True)]),
	('setmaplayout', 0xA7, [(2, True)]),
	('setobjectpriority', 0xA8, [(2, True), (2, True), (1, True)]),
	('resetobjectpriority', 0xA9, [(2, True), (2, True)]),
	('createvobject', 0xAA, [(2, True), (1, True), (2, True), (2, True),
	                         (1, True), (1, True)]),
	('turnvobject', 0xAB, [(1, True), (1, True)]),
	('opendoor', 0xAC, [(2, True), (2, True)]),
	('closedoor', 0xAD, [(2, True), (2, True)]),
	('waitdooranim', 0xAE, []),
	('setdooropen', 0xAF, [(2, True), (2, True)]),
	('setdoorclosed', 0xB0, [(2, True), (2, True)]),
	('addelevmenuitem', 0xB1, [(1, True), (2, True), (2, True),
	                           (2, True)]),
	('showelevmenu', 0xB2, []),
	('checkcoins', 0xB3, [(2, True)]),
	('addcoins', 0xB4, [(2, True)]),
	('removecoins', 0xB5, [(2, True)]),
	('setwildbattle', 0xB6, [(2, True), (1, True), (2, True)]),
	('dowildbattle', 0xB7, []),
	('setvaddress', 0xB8, [(4, True)]),
	('vjump', 0xB9, [(4, True)]),
	('vcall', 0xBA, [(4, True)]),
	('vjumpif', 0xBB, [(1, True), (4, True)]),
	('vcallif', 0xBC, [(1, True), (4, True)]),
	('vmessage', 0xBD, [(4, True)]),
	('vloadptr', 0xBE, [(4, True)]),
	('vbuftext', 0xBF, [(1, True), (4, True)]),
	('showcoinsbox', 0xC0, [(1, True), (1, True)]),
	('hidecoinsbox', 0xC1, [(1, True), (1, True)]),
	('updatecoinsbox', 0xC2, [(1, True), (1, True)]),
	('incrgamestat', 0xC3, [(1, True)]),
	('setescapewarp', 0xC4, [(2, True), (1, True), (2, True), (2, True)]),
	('waitcry', 0xC5, []),
	('bufboxname', 0xC6, [(1, True), (2, True)]),
	('textcolor', 0xC7, [(1, True)]),
	('loadhelp', 0xC8, [(4, True)]),
	('unloadhelp', 0xC9, [(4, True)]),
	('signmsg', 0xCA, []),
	('normalmsg', 0xCB, []),
	('cmphvar', 0xCC, [(1, True), (4, True)]),
	('setobedient', 0xCD, [(2, True)]),
	('checkobedience', 0xCE, [(2, True)]),
	('jumpram', 0xCF, []),
	('setwmapflag', 0xD0, [(2, True)]),
	('warpteleport2', 0xD1, [(1, True), (2, True), (1, True), (2, True),
	                         (2, True)]),
	('setmetloc', 0xD2, [(2, True), (1, True)]),
	('mossdeepgym1', 0xD3, [(2, True)]),
	('mossdeepgym2', 0xD4, []),
	('mossdeepgym3', 0xD5, [(2, True)]),
	('mossdeepgym4', 0xD6, []),
	('warp7', 0xD7, [(2, True), (1, True), (2, True), (2, True)]),
	('cmdD8', 0xD8, []),
	('cmdD9', 0xD9, []),
	('hidebox2', 0xDA, []),
	('message3', 0xDB, [(4, True)]),
	('fadescreenswapbufs', 0xDC, [(1, True), (2, True)]),
	('bufclass', 0xDD, [(1, True), (2, True)]),
	('buftrainer', 0xDE, [(1, True), (2, True)]),
	('navcall', 0xDF, [(4, True)]),
	('warp8', 0xE0, [(2, True), (1, True), (2, True), (2, True)]),
	('bufcontesttype', 0xE1, [(1, True), (2, True)]),
	('bufitemplural', 0xE2, [(1, True), (2, True), (2, True)]),
]

# GRAMMAR EXPLAIN
#
# label:
# <command> [arg0, [arg1, [arg2, ...]]]
#
## script blocks terminated by empty line
#
# #define A <val...>
## val may be an integer or another previously defined constant
#
# #info "<text>"
## prints a message at compile time, with an automatic newline.
## see string parsing meta for details
#
# #warn "<text>"
## prints a warning at compile time, with an automatic newline.
## see string parsing meta for details
#
# #fatal
# #fatal "<text>"
## halts compilation, with a variant that takes a string to print (incl.
## automatic newline). will print a stack trace as well, see string parsing
## meta for details
#
# #undef A
## undefine a previously defined constant. errors if it was already undefined
#
# #if[n]def A
## conditional logic in the scrip meta, based on definition
#
# #if A {==,!=,<,>,<=,>=} B
## conditional logic in the scrip meta, based on comparison
#
# #endif
## used with #if[[n]def] to close blocks
#
# /* comment */
# #define LASTRESULT 0x800D
# #define MYOCTAL 0o755
# #ifndef PLAYERFACING
# #define PLAYERFACING 0x800E
# #endif /* PLAYERFACING */
#
# #import "foreigndefs.scrip"
## this imports all exported labels from the scrip file named for use here
#
# label:
# <commands ...>
#
# #export label
## exports label for other files to use, making it opaque to the linker
#
# #byte <byte literal> [...]
# #hword <halfword literal> [...]
# #word <word literal> [...]
## emit binary data from one or more literals.
#
# labels and #defines are properly orthogonal. only the former may ever emit
# symbols, or have effect in the workings of #import or #export directives;
# only the latter may be aliased, undefined, redefined, used in conditional
# meta logic, or provided as data to directives or command arguments.
#
# strings do not exist in this language for emission by the generator at all,
# so #defines cannot use them (the quotes in #imports are pure syntax).
#
# numeric literals may be presented in decimal (without leading zeroes), in
# octal with prefix ‘0o’, in hexadecimal with prefix ‘0x’, or in binary with
# prefix ‘0b’. Numeric literals may use apostrophes as purely cosmetic
# separators to improve legibility.
#
# command statements are newline-terminated, and commands are separated from
# their arguments by whitespace, as are the arguments from each other. blocks
# of commands are terminated by a blank line.

import re

regexps = [
	# comment
	re.compile(r'/\*.*\*/'),
	# empty line
	re.compile(r'^\s*$'),
	# ifdef
	re.compile(r'^\s*#(el)?if(n)?def\s+([A-Za-z_][A-Za-z0-9_]*)\s*$'),
	# if
	re.compile(r'^\s*#(el)?if\s+([A-Za-z0-9_,]+)\s+(==|!=|<=?|>=?)\s+([A-Za-z0-9_,]+)\s*$'),
	# else
	re.compile(r'^\s*#else\s*$'),
	# endif
	re.compile(r'^\s*#endif\s*$'),
	# export
	re.compile(r'^\s*#export\s+([A-Za-z_][A-Za-z0-9_]*)\s*$'),
	# import
	re.compile(r'^\s*#import\s+"([A-Za-z0-9_\-/]+\.[A-Za-z0-9_\-]+)"\s*$'),
	# define
	re.compile(r'^\s*#define\s+([A-Za-z_][A-Za-z0-9_]*)\s+([A-Za-z0-9_,]+)'),
	# undef
	re.compile(r'^\s*#undef\s+([A-Za-z_][A-Za-z0-9_]*)\s*$'),
	# info
	re.compile(r'^\s*#info\s+"(([^"]|\\["\\])+)"\s*$'),
	# warn
	re.compile(r'^\s*#warn\s+"(([^"]|\\["\\])+)"\s*$'),
	# fatal
	re.compile(r'^\s*#fatal\s+"(([^"]|\\["\\])+)"\s*$'),
	# byte
	re.compile(r'^\s*#byte\s+([A-Za-z0-9_,\s]+)\s*$'),
	# hword
	re.compile(r'^\s*#hword\s+([A-Za-z0-9_,\s]+)\s*$'),
	# word
	re.compile(r'^\s*#word\s+([A-Za-z0-9_,\s]+)\s*$'),
	# command
	re.compile(r'^\s*([A-Za-z_][A-Za-z0-9_]*)(\s+[A-Za-z0-9_,:\s]+)?\s*$'),
	# label
	re.compile(r'^\s*([A-Za-z_][A-Za-z0-9_]*):\s*$')
]
EXPR_COMMENT = 0
EXPR_EMPTY = 1
EXPR_IFDEF = 2
EXPR_IF = 3
EXPR_ELSE = 4
EXPR_ENDIF = 5
EXPR_EXPORT = 6
EXPR_IMPORT = 7
EXPR_DEFINE = 8
EXPR_UNDEF = 9
EXPR_INFO = 10
EXPR_WARN = 11
EXPR_FATAL = 12
EXPR_BYTE = 13
EXPR_HWORD = 14
EXPR_WORD = 15
EXPR_COMMAND = 16
EXPR_LABEL = 17
# beyond here is for parser
EXPR_ELIF = 18
EXPR_ELIFDEF = 19
EXPR_IFNDEF = 20
EXPR_ELIFNDEF = 21
regexps_sz = len(regexps)

def lex(indata):
	ret = []
	indata = indata.replace('\r\n', '\n').replace('\r', '\n')
	indata = regexps[EXPR_COMMENT].sub('', indata)
	lines = indata.split('\n')
	i = 0
	lines_sz = len(lines)
	while i < lines_sz:
		match = None
		jndex = -1
		j = 1
		while j < regexps_sz:
			match = regexps[j].fullmatch(lines[i])
			if match != None:
				jndex = j
				break
			j += 1
		if match == None:
			raise Exception('Invalid syntax on line ' + str(i) +
			                ': ' + lines[i])
		if jndex == EXPR_COMMAND:
			cmdargs = match.group(2)
			if cmdargs != None:
				cmdargs = cmdargs.lstrip().split(' ')
			ret.append((jndex, match.group(1), cmdargs))
		elif jndex == EXPR_LABEL:
			ret.append((jndex, match.group(1)))
		elif jndex == EXPR_INFO or jndex == EXPR_WARN or \
		     jndex == EXPR_FATAL:
			ret.append((jndex, match.group(1)))
		elif jndex == EXPR_IF:
			if match.group(1) != None:
				jndex = EXPR_ELIF
			ret.append((jndex, match.groups()[1:]))
		elif jndex == EXPR_IFDEF:
			group2 = match.group(2)
			if match.group(1) != None:
				if group2 != None:
					jndex = EXPR_ELIFNDEF
				else:
					jndex = EXPR_ELIFDEF
			elif group2 != None:
				jndex = EXPR_IFNDEF
			ret.append((jndex, match.groups()[2:]))
		elif jndex == EXPR_EMPTY or jndex == EXPR_ELSE or \
		     jndex == EXPR_ENDIF:
			ret.append((jndex, None))
		elif jndex == EXPR_EXPORT or jndex == EXPR_IMPORT:
			ret.append((jndex, match.group(1)))
		else:
			ret.append((jndex, match.groups()))
		i += 1
	return ret

expr_cmpop = re.compile(r'^([!=<>]=|<|>)$')
expr_num = re.compile(r'^([1-9][0-9,]*|0b[01][01]*|0o[0-7][0-7,]*|' +
                      r'0x[0-9A-Fa-f][0-9A-Fa-f,]*)$')
expr_ident = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)$')

def parse(tokens):
	tokens_sz = len(tokens)
	defines = {}
	globls = []
	imports = []
	cond_level = 0
	cond_block = False
	blocks = {}
	cur_block = None
	for i, token in enumerate(tokens):
		typ = token[0]
		dat = token[1]
		if typ == EXPR_COMMENT:
			continue
		elif typ == EXPR_IF or typ == EXPR_ELIF or \
		     typ == EXPR_IFDEF or typ == EXPR_IFNDEF or \
		     typ == EXPR_ELIFDEF or typ == EXPR_ELIFNDEF:
			cond_level += 1
			if len(dat) != 3:
				raise Exception('Incorrect argument count ' +
				                'passed to conditional')
			lhs = dat[0]
			rhs = dat[2]
			op = dat[1]
			if expr_cmpop.fullmatch(op) == None:
				raise Exception('Bad comparison operator: ' +
				                op)
			if expr_num.fullmatch(lhs):
				lhs = int(lhs, 0)
			elif expr_ident.fullmatch(lhs):
				if lhs in defines:
					lhs = defines[lhs]
				else:
					raise Exception(lhs + ' is undefined')
			else:
				raise Exception('Bad syntax: ' + lhs)
			if expr_num.fullmatch(rhs):
				rhs = int(rhs, 0)
			elif expr_ident.fullmatch(rhs):
				if rhs in defines:
					rhs = defines[rhs]
				else:
					raise Exception(rhs + ' is undefined')
			else:
				raise Exception('Bad syntax: ' + rhs)
			# do the comparison
			truthy = False
			if op == '==':
				truthy = lhs == rhs
			elif op == '!=':
				truthy = lhs != rhs
			elif op == '<':
				truthy = lhs < rhs
			elif op == '<=':
				truthy = lhs <= rhs
			elif op == '>=':
				truthy = lhs >= rhs
			elif op == '>':
				truthy = lhs > rhs
			if typ == EXPR_IFNDEF or typ == EXPR_ELIFNDEF:
				truthy = not truthy
			cond_block = truthy
		elif typ == EXPR_ELSE:
			cond_block = not cond_block
		elif typ == EXPR_ENDIF:
			cond_level -= 1
		elif not cond_block:
			if typ == EXPR_EMPTY:
				cur_block = None
			elif typ == EXPR_DEFINE:
				val = dat[1]
				if expr_num.fullmatch(val):
					val = int(dat[1])
				elif expr_ident.fullmatch(val):
					if val in defines:
						val = defines[val]
					else:
						raise Exception('Undefined value: ' + val)
				else:
					raise Exception('Bad syntax: ' +
					                val)
				defines[dat[0]] = val
			elif typ == EXPR_UNDEF:
				key = dat[0]
				if key not in defines:
					raise Exception('Key ' + key +
					                'is already undefined')
				del defines[key]
			elif typ == EXPR_EXPORT:
				globls.append(dat)
			elif typ == EXPR_IMPORT:
				imports.append(dat)
			elif typ == EXPR_INFO:
				info_print(dat)
			elif typ == EXPR_WARN:
				warn_print(dat)
			elif typ == EXPR_FATAL:
				fatal_print(dat)
				exit()
			elif typ == EXPR_LABEL:
				cur_block = dat
			elif typ == EXPR_COMMAND or typ == EXPR_BYTE or \
			     typ == EXPR_HWORD or typ == EXPR_WORD:
				if cur_block == None:
					raise Exception('Command out of scope')
				if not blocks[cur_block]:
					blocks[cur_block] = []
				kind = dat[0]
				if typ == EXPR_BYTE:
					kind = '#byte'
				elif typ == EXPR_HWORD:
					kind = '#hword'
				elif typ == EXPR_WORD:
					kind = '#word'
				else
				blocks[cur_block].append((kind, dat[1]))
			elif typ == EXPR_BYTE:
				pass
			# TODO: properly parse commands and raws

def convert(indata):
	lexey = lex(indata)
	for lexy in lexey:
		print(lexy)
	return bytes(0)

def main(args):
	argc = len(args)
	if argc <= 1 or \
	(argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	indata = None
	if args[1] == '-':
		# Use stdin
		from sys import stdin
		indata = stdin.read()
	else:
		indata = open(args[1], 'r').read()
	output = convert(indata)
	if argc == 2:
		# Use stdout
		from sys import stdout
		stdout.buffer.write(output)
	else:
		open(args[2], 'wb').write(output)
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
