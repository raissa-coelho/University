#Cadastro de nome, e-mail e senha com uso de arquivos txt

class Pessoa():

    def ini(self,pessoa):
        if pessoa == None:
            pessoa = {}
        self.pessoa = pessoa
        return self.pessoa
    
    def Inserir(self, nome, email, senha):
        self.pessoa['nome'] = nome
        self.pessoa['email'] = email
        self.pessoa['senha'] = senha
        return self.pessoa

class Cadastro():

    def ini_cad(self, cadastro):
        if cadastro == None:
           cadastro = {}
           tam = 0
        self.cadastro = cadastro
        self.tam = tam
        return self.cadastro

    def cadas(self, nome, email, senha):
        p = Pessoa()
        p2 = None
        p.ini(p2)
        p2 = p.Inserir(nome, email, senha)

        self.cadastro[self.tam] = p2
        self.tam +=1

        return self.cadastro

    def leFile(self):
        lista = None
        Lista = Cadastro()
        Lista.ini_cad(lista)
        
        with open('Cadastro.txt', 'r') as reader:
            for linha in reader:
                l = linha
                splitLinha = l.split(",")
                nome = splitLinha[0]
                nome = nome.rstrip()
                email = splitLinha[1]
                email = email.rstrip()
                senha = splitLinha[2]
                senha = senha.rstrip()
                lista = Lista.cadas(nome,email,senha)
        self.cadastro = lista
        return self.cadastro
    
    def adiciona(self,nome,email,senha, ca):
        p = Pessoa()
        p2 = None
        p.ini(p2)
        p2 = p.Inserir(nome, email, senha)

        with open('Cadastro.txt', 'a') as writer:
            string = nome + ',' + email + ',' + str(senha)
            writer.write('\n')
            writer.write(string)
        
        tam = 0
        with open('Cadastro.txt', 'r') as reader:
            for linha in reader:
                tam += 1
        
        ca[tam] = p2
        self.cadastro = ca
        return self.cadastro

    def imprimi(self, cadastro):
        if cadastro == None:
            print("Vazia.")
        else:
           for key in cadastro.keys():
               print(cadastro[key])

def MENU():
    print("1.File to list \n2.Add \n3.Imprimi \n0.Sair")

def main():
    MENU()
    list = None
    l = Cadastro()

    op = int(input("Op:"))

    while op != 0:
        if op == 1:
            list = l.leFile()
        elif op == 2:
            nome = input("Nome:")
            email = input("Email:")
            senha = input("Senha:")
            list = l.adiciona(nome, email, senha, list)
        elif op == 3:
            l.imprimi(list)
        else:
            print("Invalido.")

        print()
        MENU()
        op = int(input("Op:"))

if __name__ == "__main__":
    main()







