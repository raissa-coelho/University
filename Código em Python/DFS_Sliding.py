#DFS
cube = [[3,6,7],[2,0,1],[8,4,5]]
goal = "123456780"
visited = []
path = []

#Cria uma matriz de adjacência a partir do cubo
def cube_conv(cube):
    cube_graph = {} #Dicionário de adjacência
    lista = [] #lista de sequência do cubo

    for i in range(3):
        for j in range(3):
            lista.append(cube[i][j])

    #Atribui vizinhos de n -- l1, l2, c1 e c2 são variáveis para não dar IndexError
    n = 0 
    while n < 9:     
        for i in range(3):
            l1 = i-1
            l2 = i+1
            for j in range(3):
                c1 = j-1
                c2 = j+1
                if cube[i][j] == lista[n]:
                    cube_graph[lista[n]] = []
                    if l1 > -1:
                        cube_graph[lista[n]].append(cube[l1][j])
                    if l2 <= 2:
                        cube_graph[lista[n]].append(cube[l2][j])
                    if c1 > -1:
                        cube_graph[lista[n]].append(cube[i][c1])
                    if c2 <= 2:
                        cube_graph[lista[n]].append(cube[i][c2])
        n+=1    

    return cube_graph

def sol(step,cube):
    print("Movimentos: ", step)
    estadoF = [[int(cube[0]),int(cube[1]),int(cube[2])],[int(cube[3]), int(cube[4]), int(cube[5])], [int(cube[6]), int(cube[7]), int(cube[8])] ]
    print("Cubo final: ", estadoF)

def nst(filho, estado):
    zero = estado.find("0")
    st = str(filho)
    filhoE = estado.find(st)

    atual = list(estado)
    atual[filhoE] = "0"
    atual[zero] = st
    novo = "".join(atual)
    
    return novo

def dfs(visited,cube_graph, estado,prox):
    if estado == goal:
        return sol(prox, estado)
    
    xx = cube_graph[prox]
    for i in range(len(xx)):
        if prox == 0:
            path.append(prox)
        elif xx[i] > 0:
            if xx[i] not in path:
                prox = xx[i]
                path.append(prox)

    if estado not in visited:
        visited.append(estado)
        for filho in cube_graph[prox]:
            new_state = nst(filho,estado) 
            dfs(visited,cube_graph, new_state,filho)


iniCube = "".join(str(c) for c in cube[0] + cube[1] + cube[2])
cube_graph = cube_conv(cube)
print(cube_graph)
print(cube)
print("\n")
dfs(visited,cube_graph,iniCube,0)
