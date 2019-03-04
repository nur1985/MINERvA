#!/usr/bin/env python
import sys
import os
import re
from subprocess import call
from math import ceil
from optparse import OptionParser, TitledHelpFormatter

# decode argument options
formatter = TitledHelpFormatter( max_help_position=22, width = 190 )
parser = OptionParser( formatter = formatter)
parser.add_option("-d", "--dir", "--indir", dest="indir", help="Top level Data directory to begin search for histograms/ntuples (required)", default="none")
parser.add_option("--name", "--hist_name", "--tuple_name", dest="root_fname", help="Filename must match this regular expression to be included (default = '.*root')", default = r'.*root')
parser.add_option("--dir_name", "--dir_name", dest="dir_name", help="Path to file must use this directory to be included", default = "")
parser.add_option("-o","--outfile", dest="outfile", help="Output filename.  Will overwrite existing file (default is MergedRootFiles.root)", default="MergedRootFiles.root")
parser.add_option("--min_run", dest="min_run",help="Minimum run number to to use. Add subrun after slash.  ex. 2160/3 is run 2160 subrun 3.", default = -1)
parser.add_option("--max_run", dest="max_run",help="Maximum run number to to use. Add subrun after slash.  ex. 2160/3 is run 2160 subrun 3.", default = -1)
parser.add_option("--max", "--max_inputs", dest="max_inputs", help="Maximum number of files that can merged in a single hadd command (default = 100)", default = 100)
parser.add_option("--no_clean", dest="no_clean", default=False, action="store_true", help="Do not clean up temporary files.")

if len(sys.argv) < 2 :
  parser.parse_args("--help".split())

(options, args) = parser.parse_args()

indir   = options.indir
root_fname = options.root_fname
dir_name = options.dir_name
outfile = options.outfile
max_inputs = int(options.max_inputs)
min_run = options.min_run
max_run = options.max_run
min_sub = -1
max_sub = -1

#parse run/subrun and convert to ints
m = re.match(r'(\d+)/(\d+)', str(min_run) )
if m:
  min_run = int(m.group(1))
  min_sub = int(m.group(2))
else:
  min_run = int( min_run )
m = re.match(r'(\d+)/(\d+)', str(max_run) )
if m:
  max_run = int(m.group(1))
  max_sub = int(m.group(2))
else:
  max_run = int( max_run )
    

if indir == "none" :
  sys.exit("ERROR: Indir argument is required")

rFiles = []
for root, dirs, files in os.walk(indir):
  for name in files:
    filename = os.path.join(root,name)
    if dir_name != "" and not re.search("/%s/"%dir_name, filename):   #look only in this directory
      continue
    if not re.match(r'%s'%root_fname, name): #look only for files with 'root_fname'
      continue
    
    if min_run != -1 or max_run != -1: #skip runs out of the specified range
      m = re.search(r'_(\d{8})_(\d{4})_', name)
      run = int( m.group(1) )
      subrun = int( m.group(2) )
      if min_run != -1 and run < min_run:
        continue
      if max_run != -1 and run > max_run:
        continue
      if min_run == run and min_sub != -1 and subrun < min_sub:
        continue
      if max_run == run and max_sub != -1 and subrun > max_sub:
        continue
    rFiles.append( filename )

if len(rFiles) > max_inputs:
  nPreFiles = int( ceil( len(rFiles)/max_inputs ) )
  preFileNames = []
  print "There are too many files to merge in a single hadd command, so I will use %d hadds and merge the results." % ( nPreFiles )
  for i in range(0, nPreFiles+1 ):
    preFileName = re.sub( r'(.*)\.root', r'\1_%d.root' % i, outfile )
    tmpFiles = rFiles[ i*max_inputs : (i+1)*max_inputs ]
    if (i+1)*max_inputs > len(rFiles):
      tmpFiles = rFiles[ i*max_inputs : ]
    cmd = "hadd -f %s %s" % ( preFileName, " ".join(tmpFiles) )
    res = call( cmd.split() )
    print "   PreOutputFile %d : Merged %d files with result %d" % ( i, len(tmpFiles), res )
    preFileNames.append(preFileName)
  cmd = "hadd -f %s %s" % ( outfile, " ".join( preFileNames ) )
  res = call( cmd.split() )
  if not options.no_clean:
    cmd = "rm -rf %s" % " ".join(preFileNames)
    call( cmd.split() )
  print "Merged %d pre-output files with result %d.  %d total files merged." % ( nPreFiles, res, len(rFiles) )
else:
  cmd = "hadd -f %s %s" % ( outfile, " ".join(rFiles) )
  res = call( cmd.split() )
  print "Merged %d files with result %d" % ( len(rFiles), res )
