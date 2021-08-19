## just a menu

def menu():
    print("[1] Imprimi texto")
    print("[2] Opção 2")
    print("[3] Sair do Programa")

def op01():
    print("Isso é um texto")

menu()
op = int(input("Escolha uma opção: "))

while op != 3:
    if op == 1:
        op01()
    elif op == 2:
        print("Em manutenção.")
    else:
        print("invalido")
    
    print()
    menu()
    op = int(input("Escolha uma opção: "))

print("Obrigada por escolher esse programa.")
