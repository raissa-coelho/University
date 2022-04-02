#Bianca Nunes Coelho - 15102880
#Algoritmo de Dijkstra implementado na linguagem python

from numpy import Infinity

#Grafo - Tipo Matriz
class Grafo():

    def define(self, vert):
        matriz = [ ( [0] * vert) for i in range(vert) ]
        self.vert = vert
        self.matriz = matriz
        return matriz
    
    def addPeso(self, col, lin, peso):
        self.matriz[lin][col] = peso
        self.matriz[col][lin] = peso
        return self.matriz
    
    def imprimi(self, matriz):
        if matriz == None:
            print("Vazia.")
        else:
            print(matriz)

    #Distância minima
    def MinD(self, distancia, vt):
        min = Infinity
        for v in range(self.vert):
            if distancia[v] < min and vt[v] == False:
                min = distancia[v]
                min2 = v 
        return min2

    #Algoritmo de Dijkstra
    def dijkstra(self, inicio, destino):
        distancia = [Infinity] * self.vert
        distancia[inicio] = 0
        vt = [False] * self.vert

        for u in range(self.vert):
            minimo = self.MinD(distancia, vt)
            vt[minimo] = True
            for vv in range(self.vert):
                if(self.matriz[minimo][vv] > 0 and vt[vv] == False and distancia[vv] > distancia[minimo] + self.matriz[minimo][vv] ):
                    distancia[vv] = distancia[minimo] + self.matriz[minimo][vv]

        print("Distancia de ", inicio, "para ", destino, "é:", distancia[destino])  
    
#MENU
def MENU():
    print("--MENU--")
    print("1.Número de Vertices")
    print("2.Leitura de Pesos")
    print("3.Menor caminho entre dois vértices(Dijkstra)")
    print("4.Imprimi Grafo")
    print("5.Sair")

#Função Main
def main():
    MENU()
    grafo = None
    gr = Grafo()

    op = int(input("Op:"))

    while op != 5:
        if op == 1:
            
            vert = int(input("Vertices:"))
            if vert > 20:
                print("Inválido.")
                vert = int(input("Vertices:"))
            grafo = gr.define(vert)
        
        elif op == 2:
            lin = int(input("Linha: "))
            col = int(input("Coluna:"))
            peso = int(input("Peso: "))
            if peso < 0:
                print("Erro. Não pode ser negativo.")
                peso = int(input("Peso: "))
            grafo = gr.addPeso(col, lin, peso)
        
        elif op == 3:
            verticeA = int(input("Partida:"))
            verticeB = int(input("Chegada:"))
            gr.dijkstra(verticeA, verticeB)
        
        elif op == 4:
            gr.imprimi(grafo)
        
        else:
            print()
        
        print()
        MENU()
        op = int(input("Op:"))

if __name__ == "__main__":
    main()