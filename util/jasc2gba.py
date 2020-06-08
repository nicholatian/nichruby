#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HELP_TEXT = 'JASC <-> GBA 15-bit binary\n\nUsage:\n    \n    jasc2gba.py [options] <input> [output]\n    Takes JASC palette and converts it to GBA binary-compatible 15-bit colour.\n    If <input> is - then standard input is read.\n\nOptions:\n    -b  Force input to be RGB555 binary instead of JASC.\n'

from sys import stderr

def convertback(bin):
	out = 'JASC-PAL\n0100\n'
	cols = []
	i = 0
	binlen = len(bin)
	if binlen % 2 != 0:
		print('Odd byte count in file, perhaps it is corrupt. Exiting...',
			file=stderr)
		return ''
	out += str(int(binlen / 2)) + '\n'
	while i < binlen:
		col = bin[i] | (bin[i + 1] << 8)
		r = (col & 0x1F) << 3
		g = ((col >> 5) & 0x1F) << 3
		b = ((col >> 10) & 0x1F) << 3
		out += str(r) + ' ' + str(g) + ' ' + str(b) + '\n'
		i += 2
	return out

def convert(text):
	lines = text.split('\n')
	if lines[0] != 'JASC-PAL' or lines[1] != '0100':
		print('Bad JASC header. Exiting...', file=stderr)
		return None
	out = []
	for line in lines[3:-1]:
		col = line.split(' ', 2)
		if len(col) != 3:
			print('Warning: invalid colour "' + col + '"', file=stderr)
			continue
		r = (int(col[0]) & 0xFF) >> 3
		g = (int(col[1]) & 0xFF) >> 3
		b = (int(col[2]) & 0xFF) >> 3
		bcol = r | (g << 5) | (b << 10)
		out.append(bcol & 0xFF)
		out.append((bcol >> 8) & 0xFF)
	return bytes(out)

def main(args):
	argc = len(args)
	if argc <= 1 or (argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	infile = None
	reverse = False
	i = 0
	offs = 0
	while i < argc:
		if args[i] == '-b':
			reverse = True
			offs += 1
			break
		i += 1
	if args[1 + offs].endswith('.bin'):
		reverse = True
		infile = open(args[1 + offs], 'rb').read()
	elif args[1 + offs] != '-':
		if reverse:
			infile = open(args[1 + offs], 'rb').read()
		else:
			infile = open(args[1 + offs], 'r').read()
	else:
		# Read from stdin
		from sys import stdin
		if reverse:
			infile = stdin.buffer.read()
		else:
			infile = stdin.read()
	if reverse:
		output = convertback(infile)
	else:
		output = convert(infile)
	if argc == 2 + offs:
		# Write to stdout
		from sys import stdout
		if reverse:
			stdout.write(output)
		else:
			stdout.buffer.write(output)
	else:
		if reverse:
			open(args[2 + offs], 'w').write(output)
		else:
			open(args[2 + offs], 'wb').write(output)
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
