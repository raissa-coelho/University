#Cadastro de alunos de uma instituição de ensino
#incompleto

class Aluno():

    def ini(self, aluno):
        if aluno == None:
            aluno = {}
        self.aluno = aluno
        return self.aluno

    def Inserir(self, nome, curso, num, tam):
        self.aluno[tam] = []
        self.aluno[tam].append(nome)
        self.aluno[tam].append(curso)
        self.aluno[tam].append(num)
        return self.aluno

class Lista():

     def ini(self, lista):
        if lista == None:
            lista = {}
            tam = 0
        self.lista = lista
        self.tam = tam
        return self.lista
    
     def Cadastro(self, nome, curso, num):
        al = Aluno()
        at = None
        al.ini(at)
        at = al.Inserir(nome, curso, num, self.tam)

        if nome not in self.lista:
            if self.tam == 0: 
               self.lista[self.tam] = []
               self.lista[self.tam].append(at)
               self.tam += 1
            else:
               self.lista[self.tam] = []
               self.lista[self.tam].append(at)
               self.tam += 1
        else:
            print("Já cadastrado.")
        return self.lista
    
     def imprimi(self,lista):
        if lista == None:
            print("Vazia.")
        else:
           for key in lista.keys():
               print(lista[key])
                


def MENU():
    print("--MENU--")
    print("1.Adicionar aluno")
    print("2.Remover aluno")
    print("3.Listar alunos que cursam mesma cadeira")
    print("4.Listar alunos")
    print("0.Sair")

def main():
    MENU()
    list = None
    l = Lista()
    l.ini(list)

    op = int(input("Op:"))

    while op != 0:
        if op == 1:
            nome = input("Nome: ")
            curso = input("Curso: ")
            mat = int(input("Matricula: "))
            list = l.Cadastro(nome, curso, mat)
        elif op == 4:
            l.imprimi(list)
        else:
            print("Invalido.")    

        print()
        MENU()
        op = int(input("Op:"))

if __name__ == "__main__":
    main()