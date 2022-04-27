from collections import deque

def troca(estado, ant, prox):
    novo_estado = list(estado)
    novo_estado[ant], novo_estado[prox] = novo_estado[prox], novo_estado[ant]
    return "".join(novo_estado)

def expandeNos(estado):
    novo = []

    zero = estado.index('0')

    if zero not in (0,1,2):
        novo.append(troca(estado, zero, zero -3))
    if zero not in (0,3,6):
        novo.append(troca(estado, zero, zero -1))
    if zero not in (2,5,8):
        novo.append(troca(estado, zero, zero +1))
    if zero not in (6,7,8):
        novo.append(troca(estado, zero, zero +3))

    return novo

def imprimir(start, goal, marked):
    caminho = []
    no = goal
    while no != start:
        caminho.append(no)
        no = marked[no]
    caminho.append(start)
    for each in caminho[::-1]:
        print(' '.join(each[:3]))
        print(' '.join(each[3:6]))
        print(' '.join(each[6:]))
        print("-----")


def dfs(start, goal):
    q = [start] #stack
    marked = {start: None}

    while q:
        estado_atual = q.pop()
        if estado_atual == goal:
            break
        for vizinho in expandeNos(estado_atual):
            if vizinho not in marked:
                marked[vizinho] = estado_atual
                q.append(vizinho)
    return marked

def main():
    start = '123506784'
    goal = '123456780'

    marked = dfs(start, goal)

    print("Puzzle: ", start)
    imprimir(start,goal,marked)
    print(len(marked))

if __name__ == '__main__':
    main()