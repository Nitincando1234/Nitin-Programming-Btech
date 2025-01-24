# docxToWord.py - To convert the docx file to word file
# Usage: python docxToWord.py <your docx file here>
import win32com.client as win32
import sys, docx, os
if (len(sys.argv) < 2): print("Usage: python docxToWord.py <your docx file here>(Note: Works for cwd files only)"); exit() # cwd = current working directory
document = (" ".join(sys.argv[1: ]))
docxFile =  os.path.join("E:\\Nitin-Programming-Btech\\Python Nitin\\automate_boring_stuff\\DocxToWord_15\\", document)
if not os.path.exists(docxFile): print("File not found"); exit()
pdfFileName = document.replace(".docx", ".pdf")
wdFormatPDF = 17    # Word's numeric code for pdf(s)
wordObj = win32.Dispatch("Word.Application")
wordObj.Visible = False
docObj = wordObj.Documents.Open(docxFile)
docObj.SaveAs(pdfFileName, FileFormat = wdFormatPDF)
docObj.Close()
wordObj.Quit()