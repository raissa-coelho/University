#Cadastro de alunos de uma instituição de ensino
#incompleto


class Aluno():

    def ini(self, aluno):
        if aluno == None:
            aluno = {}
        self.aluno = aluno
        return self.aluno

    def Inserir(self, nome, curso, num):
        self.aluno["nome"] = nome
        self.aluno["curso"] = curso
        self.aluno["matricula"] = num
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
        at = al.Inserir(nome, curso, num)

        if self.tam == 0: 
               self.lista[self.tam] = at
               self.tam += 1
        else:
               self.lista[self.tam] = at
               self.tam += 1
        return self.lista
    
     def Remove(self, aluno):
        al = Aluno()
        tam = 0
        for i in range(len(self.lista)):
            al = self.lista[i] 
            if aluno == al["nome"]:
                self.lista.pop(tam)
            else:
                tam = tam + 1
        return self.lista
    
     def listaCurso(self, curso):
         al = Aluno()
         for i in range(len(self.lista)):
            al = self.lista[i] 
            if curso == al["curso"]:
                print(al)
         
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
        elif op == 2:
            aluno = input("Nome: ")
            list = l.Remove(aluno)
        elif op == 3:
            curso = input("Curso: ")
            list = l.listaCurso(curso)
        elif op == 4:
            l.imprimi(list)
        else:
            print("Invalido.")

        print()
        MENU()
        op = int(input("Op:"))

if __name__ == "__main__":
    main()
