#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HELP_TEXT = 'PNG graphics to object code converter\n\nUsage:\n    \n    gfx2obj.py <input> [output]\n    Takes a PNG file <input>, runs it through grit, tags it with\n    the necessary symbols, and outputs an object code file.\n\ngfx2obj takes all of its metadata hints from the file\nextension provided. It uses this format (regex):\n\n    \\.[148](tn?|b)\\.(il?)?(ml?)?(pl?([0-9]{1,3})?)?\\.png$\n\nThe bpp portion specifies its bits-per-pixel, 4 or 8.\nThe next portion specifies what form the image takes on the GBA:\ntile or bitmap based. If "tn" is used, no tile reduction is done.\nThe next part specifies what kind of outputs to emit (i for\nimage/tileset, m for tilemap, and p for palette), and whether to\ncompress each output (l suffix, using LZ77). The optional numeric\nspecifies exactly how many colours the palette should have, instead\nof the maximum for the given bit depth.\n'

def run(cmd):
	from subprocess import check_output
	return check_output(cmd).decode()

class Metadata:
	img = False
	img_lz = False
	map = False
	map_lz = False
	pal = False
	pal_lz = False
	bpp = ''
	reduce = True
	tile = False
	palct = 0
	def __init__(self, fname):
		splits = fname.split('.')
		if len(splits) < 3:
			raise Exception('Incomplete extension in filename ' + fname)
		self.filetype = splits[-1]
		outs = splits[-2]
		if 'i' in outs:
			self.img = True
		if 'il' in outs:
			self.img_lz = True
		if 'm' in outs:
			self.map = True
		if 'ml' in outs:
			self.map_lz = True
		if 'p' in outs:
			self.pal = True
		if 'pl' in outs:
			self.pal_lz = True
		palct_ = outs.replace('i', '').replace('m', '').replace('p',
			'').replace('l', '')
		if len(palct_) > 0:
			self.palct = int(palct_, 10)
		bpp = splits[-3][0]
		if bpp != '1' and bpp != '4' and bpp != '8':
			raise Exception ('Invalid bpp specified in filename ' + fname)
		self.bpp = bpp
		form = splits[-3][1:]
		if form.startswith('t'):
			self.tile = True
			if form == 'tn':
				self.reduce = False
		elif form != 'b':
			raise Exception('Invalid form specified in filename ' + fname)

def main(args):
	argc = len(args)
	if argc <= 1 or (argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	if args[1] == '-':
		print('Cannot read from standard input!', file=stderr)
		return 2
	from os import sep
	name = args[1].split('data/')[-1].split('.', 1)[0].replace('/', '_')
	meta = Metadata(args[1])
	from uuid import uuid4
	from tempfile import gettempdir
	from os import path
	id = uuid4().hex
	tmpout = path.join(gettempdir(), id)
	gritopts = []
	if meta.img:
		gritopts.append('-g')
		if meta.img_lz:
			gritopts.append('-gzl')
		else:
			gritopts.append('-gz!')
		gritopts.append('-aw256')
		gritopts.append('-ah256')
	else:
		gritopts.append('-g!')
	if meta.tile:
		gritopts.append('-gt')
	else:
		gritopts.append('-gb')
	gritopts.append('-gB' + meta.bpp)
	if meta.map:
		gritopts.append('-m')
		if meta.map_lz:
			gritopts.append('-mzl')
		else:
			gritopts.append('-mz!')
	else:
		gritopts.append('-m!')
	if meta.reduce:
		gritopts.append('-mRtf')
	else:
		gritopts.append('-mR!')
	if meta.pal:
		gritopts.append('-p')
		if meta.pal_lz:
			gritopts.append('-pzl')
		else:
			gritopts.append('-pz!')
		if meta.palct > 0:
			gritopts.append('-pn' + str(meta.palct))
		elif meta.bpp == '8':
			gritopts.append('-pn256')
		elif meta.bpp == '4':
			gritopts.append('-pn16')
		else:
			gritopts.append('-pn2')
	run(['grit', args[1]] + gritopts + ['-ftb', '-fh!', '-o' + tmpout + '.bin'])
	asmfiles = []
	binfiles = []
	if meta.img:
		outname = name + '_img'
		if meta.img_lz:
			outname += '_lz'
		import bin2asm
		bin2asm.main(['bin2asm', tmpout + '.img.bin', tmpout + '.img.s', '-s',
			outname])
		asmfiles.append(tmpout + '.img.s')
		binfiles.append(tmpout + '.img.bin')
	if meta.map:
		outname = name + '_map'
		if meta.map_lz:
			outname += '_lz'
		import bin2asm
		bin2asm.main(['bin2asm', tmpout + '.map.bin', tmpout + '.map.s', '-s',
			outname])
		asmfiles.append(tmpout + '.map.s')
		binfiles.append(tmpout + '.map.bin')
	if meta.pal:
		outname = name + '_pal'
		if meta.pal_lz:
			outname += '_lz'
		import bin2asm
		bin2asm.main(['bin2asm', tmpout + '.pal.bin', tmpout + '.pal.s', '-s',
			outname])
		asmfiles.append(tmpout + '.pal.s')
		binfiles.append(tmpout + '.pal.bin')
	outfname = '/dev/stdout'
	if argc > 2:
		outfname = args[2]
	run(['arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', outfname] + asmfiles)
	from os import remove
	for file in asmfiles:
		remove(file)
	for file in binfiles:
		remove(file)
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
