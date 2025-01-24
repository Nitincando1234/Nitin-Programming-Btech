import openpyxl
from openpyxl.chart import Reference, Series, BarChart

wb = openpyxl.load_workbook("produce_data.xlsx")
sheet = wb["Sheet1"]
refObj = Reference(sheet, min_col = 1, min_row = 1, max_col = 4, max_row = 20)
seriesObj = Series(refObj, title = "Bar Chart")
chartObj = BarChart()
chartObj.title = "Bar Chart of I don't Know !"
chartObj.append(seriesObj)
sheet.add_chart(chartObj, "E1")
wb.save("produce_data.xlsx")