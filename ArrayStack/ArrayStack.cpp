// ArrayStack.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct arraystack {
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arraystack* inicializar(int tamArray);
void duplicarCapacidade(struct arraystack* pilha);
void empilhar(struct arraystack** pilha, int valor);
bool vazia(struct arraystack* pilha);
void desempilhar(struct arraystack* pilha);
int desempilharRetornando(struct arraystack* pilha);
int topo(struct arraystack* pilha);
void imprimir(struct arraystack* pilha);

int main() {
    struct arraystack* pilha = NULL;
    empilhar(&pilha, 10);
    printf("qtdade = %i || topo = %i", pilha->qtdade, topo(pilha));

}

struct arraystack* inicializar(int tamArray) {
    struct arraystack* pilha = (struct arraystack*)malloc(sizeof(struct arraystack));
    pilha->elementos = (int*)calloc(tamArray, sizeof(int));
    pilha->qtdade = 0;
    pilha->tamanho = tamArray;
    return pilha;
}

void duplicarCapacidade(struct arraystack* pilha) {
    pilha->tamanho *= 2;
    int* aux = pilha->elementos;
    if ((pilha->elementos = (int*)realloc(pilha->elementos, sizeof(int) * pilha->tamanho)) == NULL) {
        free(aux);
    }
}

//se a pilha estiver nula, instancie a pilha com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arraystack**
//se a pilha encher, duplique a capacidade do array
void empilhar(struct arraystack** pilha, int valor) {
    if((*pilha) != NULL){
		if((*pilha)->tamanho == (*pilha)->qtdade)
			duplicarCapacidade((*pilha));
		(*pilha)->elementos[(*pilha)->qtdade] = valor;
		(*pilha)->qtdade += 1;
	}
	else{
        (*pilha) = inicializar(10);
        empilhar(pilha,valor);
	}
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct arraystack* pilha) {
    bool aux = true;
    if (pilha != NULL && pilha->qtdade) {
        aux = false;
    }
    return aux;
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct arraystack* pilha) {
    if(pilha != NULL && pilha->qtdade != 0){
		pilha->qtdade--;
	}
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct arraystack* pilha) {
    int aux = INT_MIN;
	if(pilha != NULL && pilha->qtdade != 0){
		aux = pilha->elementos[pilha->qtdade-1];
		pilha->qtdade--;
	}
    return aux;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct arraystack* pilha) {
    int aux = INT_MIN;
	if(pilha != NULL && pilha->qtdade != 0){
		aux = pilha->elementos[pilha->qtdade-1];
	}
	return aux;
}

void imprimir(struct arraystack* pilha) {
    printf("_\n");
    for (int i = pilha->qtdade - 1; i >= 0; i--) {
        printf("%d\n", pilha->elementos[i]);
    }
    printf("_\n\n");
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
