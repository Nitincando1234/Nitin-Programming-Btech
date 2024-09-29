import re
import sys
date=input("Enter the correct date(in dd): ")
month=input("Enter the correct month(in mm): ")
year=input("Enter the correct year(in yyyy): ")
if not(date.isdigit() and month.isdigit() and year.isdigit()):
    print("Date, Month or Year can't be float !")
    sys.exit()
def leap_year(date,month,year):
    if (int(year)%4==0):
        if(int(month)==2):
            if(int(date)>29):
                return False
    else:
        if(month==2):
            if(date>28):
                return False
    return True
validex=r'^(0[1-9]|[2][0-9]|3[1])/(0[1-9]|1[0-2])/[0-9]{4}$'
dateinregex=date+"/"+month+"/"+year
if(leap_year(date,month,year)):
    if(re.match(validex,dateinregex)):
        print("Date is valid")
    else:
        print("Date is invalid")
else:
    print("Date is invalid")