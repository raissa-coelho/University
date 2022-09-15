# Usa-se dataframes

x <-  data.frame("id" = 1:3, 
                "name" = c("James", "Amy", "Jake"), 
                "age" = c(42, 18, 50))
print(x)

gender <- factor(c("Male", "Female", "Male"))
print(levels(gender))
print(table(gender))

x$gender <- gender
print(x)