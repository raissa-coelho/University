# fazendo import

data <- read.csv("C:/Users/raiss/Downloads/Programas/Jupyter/All_Pokemon.csv")


print(summary(mtcars))
print(var(mtcars$mpg)) # varianceis a measure of spread in a data set.
print(sd(mtcars$mpg))  # standart deviation-measure of dispersion from its mean
print("+++++++++++++++++++++++++++++++++")

# carro com o maior valor de horse power HP
print(mtcars[mtcars$hp == max(mtcars$hp), ])
print("+++++++++++++++++++++++++++++++++")

# fastest car with automatic gearbox
x <- mtcars[mtcars$am == 0, ] # finds all that are am = 0
a <- x[x$qsec == min(x$qsec), ]
print(a)
print("+++++++++++++++++++++++++++++++++")

# Grouping data
ab <- by(mtcars$hp, mtcars$am, mean) # returns an object
print(ab)
print("+++++++++++++++++++++++++++++++++")

bb <- tapply(mtcars$hp, mtcars$am, mean) #returns a matrix
print(bb)