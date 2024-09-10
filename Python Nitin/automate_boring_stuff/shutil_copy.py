import shutil
import os
from pathlib import Path
source_path=Path.cwd() / 'automate_boring_stuff' /'spam.txt'
destination_path=Path.cwd()/ 'automate_boring_stuff' /'spam_copy.txt'
shutil.copy(source_path,destination_path)
shutil.move(destination_path,source_path)
#copytree=copies every folder and files inside the folder
source_path=Path.cwd() / 'automate_boring_stuff' 
destination_path=Path.cwd() / 'automate_boring_stuff' / 'automate_copy'
#shutil.copytree(source_path,destination_path)

#deleting files
print(Path.cwd())
txt_files = list(Path.cwd().glob('*.txt'))
#for unix style regular expressions
for filename in txt_files:
    os.unlink(filename)
