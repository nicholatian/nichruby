#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HELP_TEXT = 'Binary to assembly converter\n\nUsage:\n    \n    bin2asm.py [options] <input> [output]\n    Takes the binary file <input> and converts it to its GNU assembly equivalent.\n    If <input> is - then standard input is read.\n\nOptions:\n    -s <sym>  Specify symbol name to assign the data. Useful when reading from stdin.\n'

def run(cmd):
	from subprocess import check_output
	return check_output(cmd).decode()

def convert(inbuf, sym):
	out = '\n.balign 4, 0\n.globl ' + sym + '\n' + sym + ':\n\t.byte '
	li = 0
	for byte in inbuf:
		strbyte = hex(byte).upper()
		if byte < 0x10:
			strbyte = strbyte.replace('0X', '0x0')
		if li == 10:
			out += '\n\t.byte ' + strbyte + ', '
			li   = 1
		else:
			out += strbyte + ', '
			li  += 1
	return out.replace('X', 'x').replace(', \n', '\n')[:-2] + '\n\n'

def main(args):
	argc = len(args)
	if argc <= 1 or (argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	sym = ''
	input = None
	if args[1] != '-':
		sym = args[1].replace('.bin', '')
		input = open(args[1], 'rb').read()
	else:
		# Read from stdin
		from sys import stdin
		input = stdin.buffer.read()
	i = 0
	while i < argc:
		if args[i] == '-s':
			if i + 1 >= argc:
				print('No positional arg for -s provided', file=stderr)
				return 2
			sym = args[i + 1]
			break
		i += 1
	if sym == '':
		print('No symbol name specified', file=stderr)
		return 2
	output = convert(input, sym)
	if argc == 2:
		# Write to stdout
		from sys import stdout
		stdout.write(output)
	else:
		open(args[2], 'w').write(output)
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
