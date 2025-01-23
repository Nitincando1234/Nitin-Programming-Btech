import os
from pathlib import Path
from zipfile import ZipFile
path = Path.cwd()
exampleZip = ZipFile(path / "automate_boring_stuff" / "mockZip.zip")
print(exampleZip.namelist())