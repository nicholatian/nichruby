#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HELP_TEXT = 'Adobe Colour Table <-> JASC palette converter\n\nUsage:\n    \n    act2jasc.py [-c <count>] <input> [output]\n    Takes the ACT file <input> and converts it to a JASC palette file.\n    Use -c to specify the number of colours; defaults to 256, the\n    size of all ACT palettes. If <input> is "-", then stdin is used.\n'

from sys import stderr

def convert(input, count):
	if count > 256:
		print('Too many colours requested (> 256)', file=stderr)
		return None
	inlen = len(input)
	if inlen < 768:
		print('Insufficient file length for ACT', file=stderr)
		return None
	if inlen == 772:
		incount = input[768] | (input[769] << 8)
		if incount < count:
			print('Requested ' + str(count) + 'colours, but ACT only has ' +
				str(incount), file=stderr)
			return None
		tcol = input[770] | (input[771] << 8)
		if tcol != 0:
			print('Warning: ACT expects transparency to be non-zero index. ' +
				'This might not work as you expect!', file=stderr)
	i = 0
	col = []
	out = 'JASC-PAL\r\n0100\r\n' + str(count) + '\r\n'
	while i < count:
		out += str(input[i * 3]) + ' ' + str(input[(i * 3) + 1]) + ' ' + \
			str(input[(i * 3) + 2]) + '\r\n'
		i += 1
	return out

def main(args):
	argc = len(args)
	if argc <= 1 or (argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	count = 256
	pos = 1 # Position of input arg
	if args[1] == '-c':
		if argc < 4:
			print('Must specify input argument', file=stderr)
			return 2
		count = int(args[2], base=0)
		pos = 3
	input = None
	if args[pos] == '-':
		# Read from stdin
		from sys import stdin
		input = stdin.buffer.read()
	else:
		input = open(args[pos], 'rb').read()
	output = convert(input, count)
	if output == None:
		print('Output failed', file=stderr)
		return 2
	if argc <= pos + 1:
		# Use stdout
		from sys import stdout
		stdout.write(output)
	else:
		open(args[pos + 1], 'w').write(output)
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
