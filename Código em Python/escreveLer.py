#escrever e ler files por python

with open('tes.txt', 'w') as writer:
    i = 0
    while i < 10:
       writer.write("\n")
       writer.write(str(i))
       i += 1

with open('tes.txt', 'r') as reader:
    print("{}" .format(reader.name))
    for linha in reader:
        print(linha, end = '') #The end='' is to prevent Python from adding an additional newline to the text that is being printed and only print what is being read from the file.


