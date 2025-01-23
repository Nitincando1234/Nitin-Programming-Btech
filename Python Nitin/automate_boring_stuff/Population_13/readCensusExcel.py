import openpyxl, pprint

print("Opening Excel workbook...")
wb = openpyxl.load_workbook("Population_by_Census_Tract.xlsx")
sheet= wb["Sheet1"]
# print(sheet)
countyData = {}
print("Reading rows...")
for row in range(2, sheet.max_row + 1):
    state = sheet["B" + str(row)].value
    county = sheet["C" + str(row)].value
    pop = sheet["D" + str(row)].value
    countyData.setdefault(state, {})
    countyData[state].setdefault(county, {"tracts": 0, "pop": 0})
    countyData[state][county]["tracts"] += 1
    countyData[state][county]["pop"] += int(pop)
print("Writing results...")    
resultFile = open("cenus2010.py", "w")
resultFile.write("alldata = " + pprint.pformat(countyData))
resultFile.close()
print("Done. ")