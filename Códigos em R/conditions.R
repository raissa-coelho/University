
#Conditions

for (x in 1:3) {
    if(x == 2){
        next
    }
    print(x)
}

num <- 3
result <- switch(
    num,
    "One",
    "Two",
    "Three"
)

print(result)

i <- 1
while(i < 10) {
    print(i)
    i <- i + 1
}

for (x in 1:10) {
    print(x)
}