#!/usr/bin/env python3
# -*- coding: utf-8 -*-
## PokéSnip bytecode serialiser
##
## This program takes ASCII-encoded text of the Pokétext Snippet format (a.k.a.
## snips), and serialises it into its binary equivalent. Like ‘scrip2o’, it
## produces an object code file, passing on symbol resolution to the linker
## transparently.
##
## This was developed by Alexander Nicholi for use in the Pokémon SwowS fanhack
## made with pokeemerald, a public endeavour. Although there is no licensing
## basis for the game itself, everything under legal copyright here is released
## under the BSD-2-clause licence. I hope you find good use in what I made.

HELP_TEXT = r'''PokéSnip bytecode serialiser
Copyright © 2019 Alexander Nicholi. Released under BSD-2-clause

Usage:-

    snip2bin <input> [output]

    Takes <input>, a PokéSnip compatible ASCII text file, and serialises it
    into its binary equivalent, passing symbol resolution onto the linker by
    outputting an object code file [output] (or stdout if omitted). If <input>
    is ‘-’, stdin is read for text input.
'''

TABLE = {
	' ': 0x00, '\\e': 0x1B, '[d]': 0x2A, '&': 0x2D, '+': 0x2E,
	'[Lv]': 0x34, '=': 0x35, ';': 0x36, '[PK]': 0x53, '[MN]': 0x54,
	'[PO]': 0x55, '[KE]': 0x56, '[BL]': 0x56, '[OC]': 0x57, '[K]': 0x58,
	'%': 0x5B, '(': 0x5C, ')': 0x5D, '[U]': 0x79, '[D]': 0x7A, '[L]': 0x7B,
	'[R]': 0x7C, '<': 0x85, '>': 0x86, '0': 0xA1, '1': 0xA2, '2': 0xA3,
	'3': 0xA4, '4': 0xA5, '5': 0xA6, '6': 0xA7, '7': 0xA8, '8': 0xA9,
	'9': 0xAA, '!': 0xAB, '?': 0xAC, '.': 0xAD, '-': 0xAE, '[-]': 0xAF,
	'[.]': 0xB0, '["]': 0xB1, '"': 0xB2, "[']": 0xB3, "'": 0xB4,
	'[m]': 0xB5, '[f]': 0xB6, '$': 0xB7, ',': 0xB8, '[x]': 0xB9,
	'/': 0xBA, 'A': 0xBB, 'B': 0xBC, 'C': 0xBD, 'D': 0xBE, 'E': 0xBF,
	'F': 0xC0, 'G': 0xC1, 'H': 0xC2, 'I': 0xC3, 'J': 0xC4, 'K': 0xC5,
	'L': 0xC6, 'M': 0xC7, 'N': 0xC8, 'O': 0xC9, 'P': 0xCA, 'Q': 0xCB,
	'R': 0xCC, 'S': 0xCD, 'T': 0xCE, 'U': 0xCF, 'V': 0xD0, 'W': 0xD1,
	'X': 0xD2, 'Y': 0xD3, 'Z': 0xD4, 'a': 0xD5, 'b': 0xD6, 'c': 0xD7,
	'd': 0xD8, 'e': 0xD9, 'f': 0xDA, 'g': 0xDB, 'h': 0xDC, 'i': 0xDD,
	'j': 0xDE, 'k': 0xDF, 'l': 0xE0, 'm': 0xE1, 'n': 0xE2, 'o': 0xE3,
	'p': 0xE4, 'q': 0xE5, 'r': 0xE6, 's': 0xE7, 't': 0xE8, 'u': 0xE9,
	'v': 0xEA, 'w': 0xEB, 'x': 0xEC, 'y': 0xED, 'z': 0xEE, ':': 0xF0,
	'\\l': 0xFA, '\\p': 0xFB, '\\c': 0xFC, '\\v': 0xFD, '\\n': 0xFE,
	'\\0': 0xFF
}

def convert(text):
	inbrace = False
	ctrlchar = False
	hexcount = 0
	bracebuf = ''
	pokebuf = []
	hexbuf = ''
	# First, strip all newlines out. They’re insignificant
	text = text.replace('\r', '').replace('\n', '')
	# Now, parse character by character
	for ch in text:
		if hexcount >= 2:
			hexbuf  += ch
			pokebuf += [int(hexbuf, 16)]
			hexbuf   = ''
			hexcount = 0
			ctrlchar = False
		elif hexcount > 0:
			hexbuf   += ch
			hexcount += 1
		elif ch == '[':
			if inbrace:
				raise Exception('Cannot nest brackets/bracing')
			inbrace = True
			bracebuf += ch
		elif ch == ']':
			if not inbrace:
				raise Exception('No matching bracket/brace')
			bracebuf += ch
			inbrace   = False
			thischar  = TABLE[bracebuf]
			bracebuf  = ''
			pokebuf.append(thischar)
		elif ch == '\\':
			if ctrlchar:
				raise Exception('Backslash is not valid alone')
			ctrlchar = True
		elif inbrace:
			bracebuf += ch
		elif ctrlchar:
			if ch == 'h':
				hexcount = 1
			else:
				thischar = TABLE['\\' + ch]
				ctrlchar = False
				pokebuf.append(thischar)
		else:
			thischar = TABLE[ch]
			pokebuf.append(thischar)
	# Terminate the string
	#pokebuf.append(255)
	return bytes(pokebuf)

def main(args):
	argc = len(args)
	if argc <= 1 or (argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	input = None
	if args[1] == '-':
		# Use stdin
		from sys import stdin
		input = stdin.read()
	else:
		input = open(args[1], 'r').read()
	output = convert(input)
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
