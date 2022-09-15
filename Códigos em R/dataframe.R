# data frame

x <-  data.frame("id" = 1:2, 
                "name" = c("James", "Amy"), 
                "age" = c(42, 18))
print(x)

# esses três abaixo fazem a mesma coisa
print(x[[2]])
print(x[["name"]])
print(x$name)
# --

# retorna a coluna
print(x[1])
# --

#retorna o elemento
print(x[[2, 3]])
print(x[[1, "name"]])

# adicionando uma nova coluna
x$country <- c("USA", "Italy")

# filtrando
print(x[x$age > 21, ])
subset(x, age > 21)

# operacoes
mean(x$age)
median(x$age)
sum(x$age)
print(summary(x)) # estatistica de cada coluna