import random

#cria uma lista de números até 50
loteria = [] #lista vazia
for i in range(1,51) : #i é o indice da lista range
    loteria.append(i) #add ao final da lista loteria com append

print(loteria)

print("O número é: ",random.choice(loteria))
