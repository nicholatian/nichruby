#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def main(args):
	if len(args) != 2:
		return 0
	print(args[1].split('data/')[-1].split('.', 1)[0].replace('/', '_'))
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
