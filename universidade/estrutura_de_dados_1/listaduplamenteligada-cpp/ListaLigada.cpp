#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Celula.h"
#include "ListaLigada.h"

using namespace std;


ListaLigada::ListaLigada() {
	head = NULL;
	tail = NULL;
	qtdCelulas = 0;
}

bool ListaLigada::vazia() {
	return head == NULL;
}

int ListaLigada::tamanho() {
	return this->qtdCelulas;
}

int ListaLigada::primeiro() {
    if (head != NULL)
	    return head->getInfo();
	else
	    return -1;
}

int ListaLigada::ultimo() {
    if (tail != NULL)
	    return tail->getInfo();
	else
	    return -1;
}

void ListaLigada::insereInicio(int i) {
	Celula * c = new Celula(i);
	c->setProx(head);
	c->setAnt(NULL);
	if (head != NULL){
        head->setAnt(c);
	}
	head = c;
	if (tail == NULL){
	    tail = c;
	}
	qtdCelulas++;
}


void ListaLigada::insereFinal(int i){
    Celula * c = new Celula(i);
    c->setProx(NULL);
    c->setAnt(tail);
    if (tail != NULL){
        tail->setProx(c);
	}
    tail = c;
    if (head == NULL){
        head = c;
    }
    qtdCelulas++;
}


string ListaLigada::insereEmN(Celula * c, int pos) {

	stringstream ss;

	while (true) {

		if (pos < 1) {
			ss << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas + 1) {
			ss << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		if (pos == 1) {
			insereInicio(c->getInfo());
			ss << "Inserido no inicio";
			break;
		}
		
		if (pos == qtdCelulas + 1) {
			insereFinal(c->getInfo());
			ss << "Inserido no Final";
			break;
		}	
		else{
		    Celula * aux = head; //Cria um ptr aux para chegar na posição desejada-1
		    for(int i=1; i < pos-1; i++){//chegar até a posição - 1
		        aux = aux->getProx();
		    }
		    c->setProx(aux->getProx());//N.next = aux.next
		    aux->setProx(c);//aux.next = N
		    c->setAnt(aux);//N.prev = aux
		    c->getProx()->setAnt(c);//N.next.prev = N
		    ss << "Inserido na posicao " << pos;
		    qtdCelulas++;
		    break;
		}
	}

	return ss.str();
}

string ListaLigada::deletaEmN(int pos) {

	stringstream ss;

	while (true) {

		if (pos < 1) {
			ss << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas) {
			ss << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}
		
		if (qtdCelulas == 1){
		    ss << "Número não deletado, pois há apenas 1 número na lista";
			break;
		}

		if (pos == 1) {//deleta o primeiro número
			Celula * antigoHead = head;
            Celula * novoHead = antigoHead->getProx();
			novoHead->setAnt(NULL);
			head = novoHead;
			int valorAntigoHead = antigoHead->getInfo();
			ss << "Deletou o primeiro número = " << valorAntigoHead;
			qtdCelulas--;
			delete antigoHead, valorAntigoHead;//delterar o antigo head
			break;
		}
		
		if (pos == qtdCelulas) {//deleta o último número
			Celula * antigoTail = tail;
            Celula * novoTail = antigoTail->getAnt();
			novoTail->setProx(NULL);
			tail = novoTail;
			int valorAntigoTail = antigoTail->getInfo();
			ss << "Deletou o último número = " << valorAntigoTail;
			qtdCelulas--;
			delete antigoTail, valorAntigoTail;//delterar o antigo tail
			break;
		}	
		else{//deleta o número da posição pos
		    Celula * n_anterior = head; //Cria um ptr n_anterior para chegar na posição desejada-1
		    for(int i=1; i < pos-1; i++){//chegar até a posição - 1
		        n_anterior = n_anterior->getProx();
		    }
		    Celula * n = n_anterior->getProx();
		    Celula * n_posterior = n->getProx();
		    n_anterior->setProx(n_posterior);
		    n_posterior->setAnt(n_anterior);
		    int valorN = n->getInfo();
		    qtdCelulas--;
		    ss << "Deletou o número " << valorN << " ,posição " << pos;
		    delete n, valorN;//deleta n
		    break;
		}
	}

	return ss.str();
}


void ListaLigada::imprime() {
	Celula * cursor = head;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getInfo() << " ";
		cursor = cursor->getProx();
	}
	cout << "]\n";
}


void ListaLigada::imprimeAoContrario() {
	Celula * cursor = tail;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getInfo() << " ";
		cursor = cursor->getAnt();
	}
	cout << "]\n";
}


