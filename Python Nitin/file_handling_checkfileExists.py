import os.path
filepath=r'C:\Users\kaila\Downloads\miui_EVERGO_OS1.0.1.0.TGBCNXM_30dc3f8271_13.0.zip'
flag=os.path.isfile(filepath)
if(flag==True):
    print(f"file {filepath} exists")
else:
    print(f"file {filepath} not exists")