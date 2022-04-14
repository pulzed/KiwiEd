# This util globally updates version numbers across source headers and other places.
#
# WARNING Always run on a clean working tree, then diff and make sure everything is
# in order before commiting to branch!
#
# DEFINITELY don't run if you have no idea what you're doing.

import fileinput
import sys

if len(sys.argv) < 2:
	sys.stdout.write('Specify version!\n')
	sys.exit(0)

substituteVerString = sys.argv[1]

sources = [
	'../src/app.cpp',
	'../src/app.h',
	'../src/config.cpp',
	'../src/config.h',
	'../src/const.cpp',
	'../src/const.h',
	'../src/dlg_about.cpp',
	'../src/dlg_about.h',
	'../src/dlg_settings.cpp',
	'../src/dlg_settings.h',
    '../src/frm_kiwi.cpp',
	'../src/frm_kiwi.h',
	'../src/kiwied.h',
    '../src/util.cpp',
	'../src/util.h'
]

if __name__ == '__main__':
	for sourcefile in sources:
		for i, line in enumerate(fileinput.input(sourcefile, inplace=True)):
			if i == 3:
				nextline = '//  |    -,  | | | |  |   __|  _  |  version ' + substituteVerString
				print(nextline)
			else:
				print(line, end='')
		sys.stdout.write('Successfully written ' + sourcefile + '\n')
