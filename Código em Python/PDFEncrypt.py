#Encrypt a PDF

from PyPDF2 import PdfFileReader, PdfFileWriter

out = PdfFileWriter()
pdf = PdfFileReader("grafos_exercicios.pdf")

num = pdf.numPages

for i in range(num):
    page = pdf.getPage(i)
    out.addPage(page)

out.encrypt("woody")
with open("ff.pdf", "wb") as f:
    out.write(f)

