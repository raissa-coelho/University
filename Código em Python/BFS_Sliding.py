from collections import deque

cube = [[3,6,7],[2,0,1],[8,5,4]]
goal = "123456780"
cube_graph = {}

#Cria uma matriz de adjacência a partir do cubo
def cube_conv(cube):
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

#Imprime a solução
def solution(step, cube):
    print("Movimentos necessários: ", step)
    answer = [[int(cube[0]),int(cube[1]),int(cube[2])],[int(cube[3]), int(cube[4]), int(cube[5])], [int(cube[6]), int(cube[7]), int(cube[8])] ]
    print("Cubo resolvido: ",answer)

#Define estado novo do cubo
def nstate(vazio, resposta, state_now):
    state_now = list(state_now)
    state_now[vazio],state_now[resposta] = state_now[resposta], state_now[vazio] #lista 
    return "".join(state_now)

#BFS
def bfs(cube,cube_graph):
      iniCube = "".join(str(dd) for dd in cube[0] + cube[1] + cube[2]) # Transforma cubo em apenas uma string

      visited = {iniCube} #Dicionário de estados visitados
      queue = deque([[iniCube, 0]]) #Lista de listas 

      while queue:
          state_now,step = queue.popleft() 
          
          #verifica se já não é a resposta
          if state_now == goal: 
              return solution(step, state_now)

          vazio = state_now.find("0") # procura onde 0 se encontra na string
          for resposta in cube_graph[vazio]:
              state_new = nstate(vazio, resposta, state_now)
              if state_new not in visited and state_new is not None:
                  queue.append([state_new, step + 1])
                  visited.add(state_new)

print("Cubo:", cube)
cube_graph = cube_conv(cube)
print("Grafo do cubo: " , cube_graph)
print("\n")
bfs(cube,cube_graph)
