# backupToZip.py - Copies an entire folder and its contents into
# a ZIP file whose filename increments.
import zipfile, os

def backUpToZip(folder):
    folder = os.path.abspath(folder)
    number = 1
    while True:
        zipFileName = os.path.basename(folder) + "_backup_" + str(number) + ".zip"
        if not os.path.exists(zipFileName): break
        number += 1
    print("Backing up to " + zipFileName)
    backupZip = zipfile.ZipFile(zipFileName, "w")
    for foldername, subfolders, filenames in os.walk(folder):
        print("Adding files in " + foldername)
        backupZip.write(foldername)
        for filename in filenames:
            baseFileName = os.path.basename(filename) + "_backup_"
            if (filename.startswith(baseFileName) and filename.endswith(".zip")) or foldername == "BackupToZip_10": continue        # Skip the zip files used for backup
            backupZip.write(os.path.join(foldername, filename))
    backupZip.close()
    print("Done.")
backUpToZip("..\\american_date_files")