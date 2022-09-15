 # Plots ~

plot(1:10, main = "My chart", xlab = "The x-axis", ylab = "The y-axis")

x <- mtcars$wt
y <- mtcars$drat
plot(x, y, xlab = "weight", ylab = "rear axle ratio")

# uma linha
plot(1:10, type = "l")

#multiplas linhas
line1 <- c(0, 8, 14, 42)
line2 <- c(2, 4, 6, 8)
plot(line1, type = "l", col = "blue")
lines(line2, type = "l", col = "red")

# bars~
barplot(mtcars$hp, names.arg = rownames(mtcars))
barplot(mtcars$hp, horiz = TRUE) #horizontal

# PIE
x <- c(8, 10, 42, 14)
y <- c("A", "B", "C", "D")
pie(x, label = y)

xx <- tapply(mtcars$hp, mtcars$gear, mean)
labels <- names(xx)
pie(xx, label = labels, main = "Average HP by Gears")

# BOXPLOT
boxplot(mtcars$mpg)

# Histogram
hist(mtcars$hp)
