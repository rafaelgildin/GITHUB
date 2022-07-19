#include <sstream>
#include "tad_fila.h"
#include <iostream>

using namespace std; 

Fila::~Fila() {}

Fila::Fila() {}

Fila::Fila(int max) {
	this->fila = new int(max);
	this->tamanhoMax = max; //TAM MAX da Fila
	this->tamanho = 0; //TAM atual da Fila
	this->ini = -1;
	this->fim = -1;
}

bool Fila::vazia() {
	return this->tamanho == 0;
}

bool Fila::cheia() {
	return this->tamanho == this->tamanhoMax;
}

int Fila::tamFila(){
    return this->tamanho;
}

/**
 * INSERE UM ELEMENTO NA FILA.

 * Antes de inserir:
 *   - verifica se a fila nao esta lotada.
 *      - se estiver lotada, retorna -1.
 *   - verifica se o elemento ja esta na fila
 *      - se estiver, retorna -2.

 * Depois de inserir:
 *   - retorna a posicao onde o elem foi inserido.
 */

int Fila::inserir(int valor) {
	if (this->cheia()) {
		return -1;
	}
	else if(this->posicaoDoIntem(valor) != -1){
	    return -2;
	}
	else{
    	this->fim = (this->fim + 1) % this->tamanhoMax;
    	if (this->ini == -1) { //primeiro elemento
    		this->ini = 0;
    	}
    	this->fila[fim] = valor;
    	this->tamanho++;
    	return this->fim;
    }
}
/**
 * EXTRAI O PROXIMO ELEMENTO A SER ATENDIDO (PRIMEIRO DA FILA).
 * Retorna o valor do elemento.
 * Obs: se esvaziar a fila (tamanho=0) retorne "ini" e "fim" para -1.
 */
int Fila::extrair() {

	if (this->vazia()) {
        this->ini = -1;
        this->fim = -1;
		return -1;
	}

    int valor;
    valor = this->fila[ini];
    this->fila[ini] = -1;
	this->ini = (this->ini + 1) % this->tamanhoMax;
	this->tamanho--;

	if (vazia()) {
        this->ini = -1;
        this->fim = -1;
	}

	return valor;

}


/**
 * VERIFICA EM QUAL POSICAO DA FILA SE ENCONTRA DETERMINADO ITEM.
 * Retira da Fila original, IMPRIME, insere em uma fila auxiliar. Fa�a isso at� esvaziar a fila.
 * Depois, retorne os elementos para a fila original
 */
string Fila::imprimir() {

    Fila aux(this->tamanho);
    int qde = this->tamanho;
    int elem, ret;
    stringstream ss;
    ss << "[ ";
    while(qde > 0){
            elem = this->extrair();
            ss << elem << " ";
            ret = aux.inserir(elem);
            qde--;
    }
    qde = aux.tamanho;
    while(qde > 0){
            elem = aux.extrair();
            ret = this->inserir(elem);
            qde--;
    }

	ss << "]";

	return ss.str();
}


/**
 * VERIFICA EM QUAL POSICAO DA FILA SE ENCONTRA DETERMINADO ITEM.
 * Retira da Fila original, compara, insere em uma fila auxiliar.
 * Depois, retorne os elementos para a fila original respeitando a ordem original
 * Caso nao encontre, retorna -1 (nao esta' na fila ou a fila esta' vazia).
 */
int Fila::posicaoDoIntem(int valor) {
    Fila aux(tamanho);
    int qde = this->tamanho;
    int posicao = -1, posicao_ele=-1;
    while(qde > 0){
            int elem = this->extrair();
            aux.inserir(elem);
            qde--;
            posicao++;
            if(elem==valor){
                posicao_ele = posicao;
            }
    }
    qde = aux.tamanho;
    while(qde > 0){
        int elem = aux.extrair();
        this->inserir(elem);
        qde--;
    }
	return posicao_ele;
}


//Pode manipular o vetor diretamente.
//Objetivo: treinar ordenacao Use um metodo eficiente!
// 1)fila original -> fila auxiliar 
//                 -> vetor
// 2)fila auxiliar -> fila original
//   vetor -> fila auxiliar 2
void Fila::ordenar(){
    // fila original para vetor "a" e para fila auxiliar
    int n=this->tamanho,qde = this->tamanho;
    int i=0, a[n], elem;
    Fila aux(n);
    while(qde > 0){
            elem = this->extrair();
            aux.inserir(elem);
            a[i]=elem;
            qde--;
            i++;
            }
    // Bubble Sort no vetor "a"
    int temp;
    for (i = 0; i < n; i++) 
    {
        for (int j = 0; j < n-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // fila auxiliar para a Fila original, vetor para fila auxiliar 2
    i=0; 
    Fila aux2(n);
    int elem2;
    while(n > 0){
        elem=a[i];
        aux2.inserir(elem);
        
        elem2 = aux.extrair();
        this->inserir(elem2);
        n--;
        i++;
        }   
    // imprimir a fila
    cout << aux2.imprimir();
}            


//=== IMPLEMENTAR
int Fila::front(){
    if (this->vazia()) {
		return -1;
	}
    
    int valor;
    valor = this->fila[ini];
    return valor;
}


int Fila::back(){
    if (this->vazia()) {
		return -1;
	}
    int valor;
    valor = this->fila[fim];
    return valor;

}

