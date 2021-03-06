#! /usr/bin/python

import os
import sys
import filecmp
import shutil

input = sys.argv[1]
output = sys.argv[2]
tmp_output = output + '.tmp'
varname = sys.argv[3]

outfile = open(tmp_output, 'w')
print('/* -*- C -*- */', file=outfile)
print('static const char %s [] = ""' % (varname,), file=outfile)
for line in open(input):
    if line.endswith('\n'):
        line = line[:-1]
    print('"' + line.replace('"', '\\"') + '\\n"', file=outfile)
print(';', file=outfile)

outfile.close()

# docopy = False
# try:
#     docopy = not filecmp.cmp(tmp_output, output)
# except:
#     docopy = True
docopy = True

if docopy:
    shutil.copyfile(tmp_output, output)

open(output + '.stamp', 'w').write('stamp\n')

try:
    os.remove(tmp_output)
    os.remove(output + '.stamp')
except:
    pass
