#Grafo com pesos/ Tipo Matriz

class GrafoM():

    def Def(self, col, lin):
        matriz = [ ( [0] * col) for i in range(lin) ]
        self.matriz = matriz
        return matriz
    
    def AddPeso(self, col, lin, peso):
        self.matriz[lin][col] = peso
        return self.matriz
    
    def Imprimi(self, matriz):
        if matriz == None:
            print("Vazia.")
        else:
            print(matriz)

def MENU():
    print("--MENU--")
    print("1.Definir Grafo(Matriz)")
    print("2.Adiconar Peso")
    print("3.Imprimir")
    print("4.Sair")

def main():
    MENU()
    Matriz = None
    mm = GrafoM()
    op = int(input("Op:"))

    while op != 4:
        if op == 1:
            col = int(input("Coluna:"))
            lin = int(input("Linha: "))
            Matriz = mm.Def(col, lin)
        elif op == 2:
            col = int(input("Coluna:"))
            lin = int(input("Linha: "))
            peso = int(input("Peso: "))
            Matriz = mm.AddPeso(col,lin,peso)
        elif op == 3:
            mm.Imprimi(Matriz)
        else:
            print("Invalido.")
        
        print()
        MENU()
        op = int(input("Op:"))

if __name__ == "__main__":
    main()
    
