# Function

pow <- function(x, y) {
    result <- x^y  # ou x**y
    print(result)
}
pow(9, 3)

quadrado <- function(x, y=2) {
    resultado <- x^y
    print(resultado)
}
quadrado(5)

div <- function(x, y) {
    result <- x / y
    return(result)
}
a <- div(8, 2)
print(a)