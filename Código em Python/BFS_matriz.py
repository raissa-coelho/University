import numpy as np 
from collections import deque as queue

goal = [[1,2,3],[4,5,6],[7,8,0]]

def valido(visitou, linha, coluna):
    if(linha < 0 or coluna < 0 or linha >= 3 or coluna >=3):
        return False
    
    if(visitou[linha][coluna]):
        return False
    
    return True

def bfs(puzzle, visitou, linha, coluna):
    if puzzle == goal:
        return print("Goal reached")

    q = queue()
    q.append((linha, coluna))
    visitou[linha][coluna] = True

    while(len(q) > 0):
        cell = q.popleft()
        x = cell[0]
        y = cell[1]
        print(puzzle[x][y], end = " ")

        for i in range(3):
            adjx = x + dLinha[i]
            adjy = y + dColuna[i]
            if(valido(visitou, adjx, adjy)):
                q.append((adjx,adjy))
                visitou[adjx][adjy] = True


if __name__ == "__main__":
    visitou = [[False for i in range(3)] for i in range(3)]
    dLinha = [-1,0,1,0]
    dColuna = [0,1,0,-1]


    puzzle = [[1,4,5],
              [3,7,8],
              [0,2,6]]
    
    p2 = [[1,2,3],[4,5,6],[7,8,0]]

    bfs(puzzle, visitou, 0,0)