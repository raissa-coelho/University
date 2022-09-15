# Vetores 
# só podem ter elementos do mesmo tipo

names <- c("James", "Rita", "Sandra")
print(names[2])

lista <- c("Bianca" = 26, "Raissa" = 26)
print(lista["Bianca"]) # retorna nome e numero
print(lista[["Bianca"]]) # retorna apenas o numero

numeros <- c(23, 4, 122, 76, 45, 100)
print(length(numeros))
print(sum(numeros))
print(sort(numeros))
print(sort(numeros, decreasing = TRUE))

x <- 3:90
print(x)
print(x[x < 15])

x <- seq(1, 10, by = 2)
print(x)

# vetores de mesmo tamanho
v1 <- c(2, 6, 1, 5)
v2 <- c(5, 3, 4, 2)
print(v1 + v2)
print(v1 - v2)
print(v1 * v2)
print(v1 / v2)

# mean and median
v <- c(2, 45, 13, 456, 22, 9, 33)
print(mean(v))
print(median(v))