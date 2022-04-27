cube = [[3,6,7],[2,0,1],[8,5,4]]
goal = {
        '1': [2,4],
        '2': [1,3,5],
        '3': [2,6],
        '4': [1,5,7],
        '5': [2,4,6,8],
        '6': [3,5,0],
        '7': [4,8],
        '8': [7,5,0],
        '0': [8,6]
        }

cube_graph = {}

def cube_conv(cube):
    lista = []

    for i in range(3):
        for j in range(3):
            lista.append(cube[i][j])
    print(lista)

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

cube_graph = cube_conv(cube)
print(cube_graph)
