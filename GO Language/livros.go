package main

import (
	"fmt"
)

type Books struct {
	nome  string
	autor string
	data  int
}

func insere(novo []Books) []Books {
	var l, a string
	var ano int

	fmt.Print("Livro: ")
	fmt.Scan(&l)
	fmt.Print("Autor:")
	fmt.Scan(&a)
	fmt.Print("Ano:")
	fmt.Scan(&ano)

	novoN := Books{l, a, ano}
	n := append(novo, novoN)

	return n
}

func Imprime(lista []Books) {

	for _, r := range lista {
		fmt.Println()
		fmt.Println("Livro:", r.nome)
		fmt.Println("Autor:", r.autor)
		fmt.Println("Ano:", r.data)
		fmt.Println()
	}

}

func remove(lista []Books) []Books {
	var nome string

	fmt.Print("Nome:")
	fmt.Scan(&nome)

	for i, r := range lista {
		if nome == r.nome {
			lista = append(lista[:i], lista[i+1:]...)
		}
	}
	return lista
}

func menu() {
	fmt.Println("1.Insere")
	fmt.Println("2.Imprime")
	fmt.Println("3.Remove")
	fmt.Println("0.Sair")
}

func main() {
	var lista []Books
	var op int
	menu()

	fmt.Print("Op: ")
	fmt.Scan(&op)

	for op != 0 {
		switch op {
		case 1:
			lista = insere(lista)
		case 2:
			Imprime(lista)
		case 3:
			lista = remove(lista)
		}
		menu()
		fmt.Print("Op: ")
		fmt.Scan(&op)

	}
}
