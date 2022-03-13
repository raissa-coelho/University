#escrever e ler files por python

fo = open('teste.txt', 'r+')

print("Nome do arquivo: " , fo.name)
fo.write("Reginaldo--58\n")
fo.readline()
fo.write("Bianca--26\n")

fo.close()
