class Grafo():

    ## inicia parametros principais
    def __init__(self, tam):
        self.tam = tam
        self.adjMat = [[0]* tam for i in range(tam)]
        self.anterior = [i for i in range(tam)]
    
    ### adiciona aresta na matriz
    def adiciona(self, comeco, fim, peso):
        if comeco > self.tam or fim > self.tam:
            print("invalido")
        else:
            self.adjMat[comeco-1][fim-1] = peso
    
    #### imprimi o grafo
    def imprimi(self):
        for i in range(self.tam):
            print(self.adjMat[i])
    
    ## procura verts
    def procura(self,i):
        while self.anterior[i] != i:
            i = self.anterior[i]
        return i
    
    ## union find 
    def uniao(self,i, j):
        u = self.procura(i)
        v = self.procura(j)
        self.anterior[u] = v

    ## algoritmo kruskal 
    def kruskal(self): 
        vert = 0
        inf = 99999  ## infinito

        for i in range(self.tam):
            self.anterior[i] = i
            
        while vert < self.tam - 1:
            min = inf
            u = -1
            v = -1
            for i in range(self.tam):
                for j in range(self.tam):
                    if self.procura(i) != self.procura(j) and self.adjMat[i][j] < min:
                        min = self.adjMat[i][j]
                        u = i
                        v = j
            self.uniao(u,v)
            print('Vertice {}:  aresta({}, {}) peso:{}'.format(vert, u,v, min))
            vert += 1


def menu():
    print("[1] Vértices")
    print("[2] Pesos(u,v)")
    print("[3] Imprimi Grafo")
    print("[4] Kruskal")
    print("[5] Sair do Programa")
    
def main():
    menu()
    op = int(input("Escolha uma opção: "))

    while op != 5:
        if op == 1:
            vertices = int(input("Numero de vertices: "))
            g = Grafo(vertices)
        elif op == 2:
            inicio = int(input("Vertice A: "))
            fim = int(input("Vertice B: "))
            peso = int(input("Peso: "))
            g.adiciona(inicio,fim,peso)
        elif op == 3:
            g.imprimi()
        elif op == 4:
            g.kruskal()
        else:
            print("invalido")
    
        print()
        menu()
        op = int(input("Escolha uma opção: "))

if __name__ == '__main__':
    main()