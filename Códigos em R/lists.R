# Lists
# podem conter elementos de tipos diferentes

sx <- list("James", "Q", c(2, 4, 8), 42)
print(sx[3])

s <- list("name" = "Bianca", "age" = 26)
print(s$name)

s[["country"]] <- "Brazil"
print(s)

lista1 <- list("A", "B", "C")
lista2 <- list("D", "E")
x <- c(lista1, lista2) # merge two lists

nu <- list(2, 3, 4, 5)
y <- unlist(nu)  # transforma em vetor