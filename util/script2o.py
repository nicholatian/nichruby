#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def main(args):
	argc = len(args)
	if argc <= 1 or (argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	name = args[1].split('data/')[-1].split('.', 1)[0].replace('/', '_')
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
