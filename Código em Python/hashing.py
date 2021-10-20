
import pandas as pd

class Hash:

    def __init__(self, tamanho):
        self.tamanho = tamanho #tamanho da tabela
        self.lista = dict()    #criação de dicionário
        # pares de [key, value] iniciais
        for i in range(self.tamanho):
            self.lista.setdefault(i, []) 
    
    def insere(self, valor):
        # função hash
        keey = (valor)%(self.tamanho)
        #insere no dicionário
        self.lista[keey].append(valor)

    # imprimi no formato de tabela
    def imprime(self):
       novo = pd.DataFrame(list(self.lista.items()), columns=['Key', 'Value'])
       print(novo)
        
def menu():
    print("[1] Tamanho Tabela")
    print("[2] Insere")
    print("[3] Imprimi")
    print("[4] Sai do Programa")

def main():
    menu()
    op = int(input("Escolha uma opção: "))

    while op != 4:
        if op == 1:
            tam = int(input("Tamanho: "))
            h = Hash(tam)
        elif op == 2:
            v = int(input("Valor: "))
            h.insere(v)
        elif op == 3:
            h.imprime()
        else:
            print("invalido")
    
        print()
        menu()
        op = int(input("Escolha uma opção: "))

if __name__ == '__main__':
    main()
