# combinePdfs.py - To combine the multiple pdfs in the current working directory into one single pdf

import PyPDF2, os
pdfFiles = []
for file in os.listdir("."):
    if file.endswith(".pdf"): pdfFiles.append(file)
pdfFiles.sort(key = str.lower)
pdfWriteFile = PyPDF2.PdfWriter()
for filename in pdfFiles:
    pdfReaderObj = PyPDF2.PdfReader(open(filename, "rb"))
    # Loop each page of the pdf except first
    for pageNum in range(1, pdfReaderObj.numPages):
        pageObj = pdfReaderObj.getPage(pageNum)
        pdfWriteFile.addPage(pageObj)
pdfWriteFile.write(open("CombinedPDFS_final.pdf", "wb"))
pdfWriteFile.close()