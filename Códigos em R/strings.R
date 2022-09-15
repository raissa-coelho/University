# String

t0 <- "Raissa"
t1 <- 17
t2 <- 06
t3 <- 1995
result <- paste(t0, t1, t2, t3, sep = "/")
print(result)

txt <- "Ham and eggs"
txt <- toupper(txt) # tolower
print(txt)

print(nchar(txt))
print(substr(txt, 5, 9))