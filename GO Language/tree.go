//Binary Search tree -- INCOMPLETE
package main

import (
	"fmt"
)

type Nodo struct {
	value    int
	esquerda *Nodo
	direita  *Nodo
}

type Tree struct {
	root *Nodo
}

func (tree *Tree) insert(data int) *Tree {
	if tree.root == nil {
		tree.root = &Nodo{value: data, esquerda: nil, direita: nil}
	} else {
		tree.root.inser(data)
	}
	return tree
}

func (node *Nodo) inser(data int) {
	if node == nil {
		return
	} else if data < node.value {
		if node.esquerda == nil {
			node.esquerda = &Nodo{data, nil, nil}
		} else {
			node.esquerda.inser(data)
		}
	} else {
		if node.direita == nil {
			node.direita = &Nodo{value: data, esquerda: nil, direita: nil}
		} else {
			node.direita.inser(data)
		}
	}
}

func imprime(tree *Nodo) {
	if tree == nil {
		return
	}
	imprime(tree.esquerda)
	fmt.Println(tree.value, "-")
	imprime(tree.direita)
}

func menu() {
	fmt.Println("1.Insere na Árvore")
	fmt.Println("2.Imprime Árvore")
	fmt.Println("0.Sair")
}

func main() {
	tree := &Tree{} // inicialização da árvore
	var op int
	var valor int

	menu()
	fmt.Print("Op:")
	fmt.Scan(&op)

	for op != 0 {
		switch op {
		case 1:
			fmt.Print("Valor:")
			fmt.Scan(&valor)
			tree = tree.insert(valor)
		case 2:
			imprime(tree.root)
		}
		menu()
		fmt.Print("Op:")
		fmt.Scan(&op)
	}

}
