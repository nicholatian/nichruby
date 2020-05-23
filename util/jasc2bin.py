#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stderr

def colchan8to5(c):
	return (c & 0xFF) >> 3

def rgb24to555(r, g, b):
	return colchan8to5(r) | (colchan8to5(g) << 5) | \
		(colchan8to5(b) << 10)

def convert(text):
	lines = text.split('\n')
	if lines[0] != 'JASC-PAL' or lines[1] != '0100':
		print('Bad JASC header. Exiting...', file=stderr)
		return None
	for line in lines[2:]:
		col = line.split(' ', 2)
