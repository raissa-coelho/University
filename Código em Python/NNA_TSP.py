#Algoritmo Aproximativo para TSP
# O (n**2) - pior caso

from queue import Empty
import numpy as np

def TSP_A(grafo,linha,ini):

    passos = 0
    total = 0
    visited = []
    unvisited = []
    vertex = []

    for i in range(linha):
        vertex.append(i)

    unvisited = vertex
    atual = ini
    visited.append(atual)
    unvisited.remove(atual)

    while len(unvisited) != 0:

        j = 0
        col = 0
        num = 0
        peso = 0
        minimo = 10000000000

        while j < len(unvisited):
            num = unvisited[j]
            peso = grafo[atual][num]
            if peso < minimo:
                minimo = peso
                col = num
            j += 1
        
        passos += 1
        total += minimo
        atual = col
        visited.append(atual)
        unvisited.remove(atual)
    
    passos +=1
    peso = grafo[atual][ini]
    total += peso
    print(f'Passos: {passos} Min: {total}')

if __name__ == "__main__":

    file =  open('tsp5_27603.txt', 'r')
    grafo = np.loadtxt(file, dtype = "int") 
    vertex = 0
    for i in range(len(grafo)):
        i += 1
        vertex += 1

    TSP_A(grafo,vertex,0)