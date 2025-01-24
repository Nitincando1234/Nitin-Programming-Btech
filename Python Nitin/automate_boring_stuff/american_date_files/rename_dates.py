# rename_dates.py - Renames filenames with American MM-DD-YYYY date format
   # to European DD-MM-YYYY.
import shutil, os, re
datePattern = re.compile(r"""^(.*?) 
       ((0|1)?\d)-                  
       ((0|1|2|3)?\d)-              
       ((19|20)\d\d)                
       (.*?)$                       
       """, re.VERBOSE)
for americanFileNames in os.listdir("."):
    matchObject = datePattern.search(americanFileNames)
    if matchObject == None: continue
    beforePart = matchObject.group(1)
    monthPart = matchObject.group(2)
    dayPart = matchObject.group(4)
    yearPart = matchObject.group(6)
    afterPart = matchObject.group(8)

    euroFileNames = beforePart + dayPart + "-" + monthPart + "-" + yearPart
    absPath = os.path.abspath(".")
    americanFileNames = os.path.join(absPath, americanFileNames)
    euroFileNames = os.path.join(absPath, euroFileNames)
    print("Renaming \"%s\" to \"%s\"\n" % (americanFileNames, euroFileNames))
    shutil.move(americanFileNames, euroFileNames)
