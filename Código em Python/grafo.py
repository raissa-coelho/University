#Grafo direcionado usando lista dicionário em python

#Classe Grafo
class Grafo():

    def ini(self, graf):
        if graf == None:
            graf = {}
        self.graf = graf
        return self.graf

    def addVertice(self, vert):
        if vert not in self.graf:
           self.graf[vert] = []
        return self.graf
    
    def addAresta(self, vert, are):
        if are not in self.graf:
           self.graf[vert].append(are)
           self.graf[are] = []
        else:
           self.graf[vert] = [are]
        return self.graf
    
    
    def remover(self, vert):
       if vert not in self.graf:
           print("Não existe este vértice.")
       else:
            self.graf.pop(vert)
       return self.graf
    
    def Imprime(self, graf):
        if graf == None:
            print("Não há grafo.")
        else:
            print(graf)
    


def MENU():
    print("--MENU--")
    print("1.Adicionar Vertice")
    print("2.Adicionar Arestra")
    print("3.Listagem do Grafo")
    print("4.Remover vértice")
    print("5.Sair")

def main():
    MENU()
    gg = None
    g = Grafo()
    g.ini(gg)

    escolha = int(input("Escolha: "))

    while escolha != 5:
        if escolha == 1:
           vert = int(input("Vertice: "))
           gg = g.addVertice(vert)

        elif escolha == 2:
           vert = int(input("Par(1): "))
           are = int(input("Par(2): "))
           gg = g.addAresta(vert,are)

        elif escolha == 3:
            g.Imprime(gg)

        elif escolha == 4:
            vert = int(input("Vertice Remover: "))
            g.remover(vert)

        else: 
            print("Invalido.")

        print()
        MENU()
        escolha = int(input("Escolha: "))

if __name__ == "__main__":
    main()

