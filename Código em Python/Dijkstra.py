
from queue import PriorityQueue

class Grafo:
    def __init__(self, vertices):
        self.v = vertices
        self.aresta = [[-1 for i in range(vertices)] for j in range(vertices)]
        self.visitou = []

    def add(self, u, v, peso):
        self.aresta[u][v] = peso
        self.aresta[v][u] = peso

    def dijkstra(self, comeco):
        aux = {v: float('inf') for v in range(self.v)}
        aux[comeco] = 0

        prioridade = PriorityQueue()
        prioridade.put((0,comeco))

        while not prioridade.empty():
            (distancia, atualV) = prioridade.get()
            self.visitou.append(atualV)

            for vizinho in range(self.v):
                if self.aresta[atualV][vizinho] != -1:
                    distancia = self.aresta[atualV][vizinho]
                    if vizinho not in self.visitou:
                        custo_antigo = aux[vizinho]
                        custo_novo = aux[atualV] + distancia
                        if custo_novo < custo_antigo:
                            prioridade.put((custo_novo,vizinho))
                            aux[vizinho] = custo_novo
        return aux

g = Grafo(9)
g.add(0, 1, 4)
g.add(0, 6, 7)
g.add(1, 6, 11)
g.add(1, 7, 20)
g.add(1, 2, 9)
g.add(2, 3, 6)
g.add(2, 4, 2)
g.add(3, 4, 10)
g.add(3, 5, 5)
g.add(4, 5, 15)
g.add(4, 7, 1)
g.add(4, 8, 5)
g.add(5, 8, 12)
g.add(6, 7, 1)
g.add(7, 8, 3)

D = g.dijkstra(0)

for vertex in range(len(D)):
    print("Distance from vertex 0 to vertex", vertex, "is", D[vertex])