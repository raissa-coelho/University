# Problema do Caxeiro Viajante
#Algorítmo Exato utilizando permutações
#Testa todos possíveis caminhos e comparar o resultado do peso para ver qual o mínimo

from itertools import permutations
from sys import maxsize
import numpy as np

def TSP_exact(grafo,ini,linha):
    
    passos = 0
    vertex = []
    for i in range(linha):
        if i != ini:
            vertex.append(i)

    Minimo = maxsize
    prox = permutations(vertex)

    for i in prox:
        atual_peso = 0
        k = ini
        for j in i:
            atual_peso += grafo[k][j]
            k = j
        atual_peso += grafo[k][ini]
        Minimo = min(Minimo, atual_peso)
        #print(f'Passo: {passos} Atual Peso: {Minimo}')
        passos += 1
    
    print(f'Passos: {passos}, Peso: {Minimo}')

if __name__ == "__main__":

    file =  open('tsp1_253.txt', 'r')
    grafo = np.loadtxt(file, dtype = "int") 
    vertex = 0
    for i in range(len(grafo)):
        i += 1
        vertex += 1

    TSP_exact(grafo,0,vertex)

