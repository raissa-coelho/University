from collections import deque

puzzle = [[3,6,7],[2,0,1],[8,4,5]]
goal = "123456780"


def transforma(puzzle):
    lista = []
    puzzle_grafo = {}

    for i in range(3):
        for j in range(3):
            lista.append(puzzle[i][j])
    
    n = 0
    while n < 9:
        for i in range(3):
            linha1 = i - 1
            linha2 = i + 1
            for j in range(3):
                coluna1 = j - 1
                coluna2 = j + 1
                if puzzle[i][j] == lista[n]:
                    puzzle_grafo[lista[n]] = []
                    if linha1 > -1:
                        puzzle_grafo[lista[n]].append(puzzle[linha1][j])
                    if linha2 <= 2:
                        puzzle_grafo[lista[n]].append(puzzle[linha2][j])
                    if coluna1 > -1:
                        puzzle_grafo[lista[n]].append(puzzle[i][coluna1])
                    if coluna2 <= 2:
                        puzzle_grafo[lista[n]].append(puzzle[i][coluna2])
        n+=1
    return puzzle_grafo

def solucao(step, puzzle):
    print("Movimentos: ", step)
    final = [[int(puzzle[0]), int(puzzle[1]), int(puzzle[2])],[int(puzzle[3]), int(puzzle[4]), int(puzzle[5])],[int(puzzle[6]), int(puzzle[7]), int(puzzle[8])]]
    print("Resolvido ", final)

def estado(zero, fim, estado_atual):
    estado_atual = list(estado_atual)
    estado_atual[zero], estado_atual[fim] = estado_atual[fim], estado_atual[zero]
    return "".join(estado_atual)

def bfs(puzzle, puzzle_grafo):
    start = "".join(str(dd) for dd in puzzle[0] + puzzle[1] + puzzle[2])
    visitou = {start}
    q = deque([[start, 0]])

    while q:
        estado_atual , step = q.popleft()

        if estado_atual == goal:
             return solucao(step,estado_atual)
        
        zero = estado_atual.find("0")
        for fim in puzzle_grafo[zero]:
            estado_novo = estado(zero, fim, estado_atual)
            if estado_novo not in visitou and estado_novo is not None:
                q.append([estado_novo, step + 1])
                visitou.add(estado_novo)


puzzle_grafo = transforma(puzzle)
bfs(puzzle, puzzle_grafo)