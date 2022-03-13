#Decrypt a PDF

from PyPDF2 import PdfFileReader, PdfFileWriter

out = PdfFileWriter()
pdf = PdfFileReader("ff.pdf")

if pdf.isEncrypted:
    pdf.decrypt("woody")

    for i in range(pdf.numPages):
        page = pdf.getPage(i)
        out.addPage(page)

    with open("conta.pdf", "wb") as f:
        out.write(f)
    
    print("File decrypted succeddfully.")
else:
    print("File already decrypted.")