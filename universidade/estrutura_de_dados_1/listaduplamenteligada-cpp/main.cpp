/* ******************************************************************
Implementacao do TAD Lista Duplamente Ligada
Giulia Barbieri Quagliano  - TIA : 42013070
Rafael Avraham Gildin Acherboim - TIA : 31940242
****************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ListaLigada.h"

using namespace std;

void ni();
void pausa();

int main() {

	ListaLigada lista;

	while (true) {

		system("cls"); /*chamada Windows. Em outro ambiente comente esta linha*/
		cout << "\n ********* TESTANDO O TAD LISTA DUPLAMENTE LIGADA ******\n";
		cout << "\n0 - sair";
		cout << "\n1 - inserir um novo no no inicio";
		cout << "\n2 - inserir um novo no no final";
		cout << "\n3 - inserir um novo no na posicao 'n'"; /////////////
		cout << "\n4 - excluir um no do inicio";
		cout << "\n5 - excluir um no do final";
		cout << "\n6 - excluir um no da posicao 'n'";
		cout << "\n7 - informar o total de elementos na lista";
		cout << "\n8 - imprimir a lista do inicio para o final";
		cout << "\n9 - imprimir a lista do final para o inicio";
		cout << "\n10 - primeiro da lista";
		cout << "\n11 - ultimo da lista";
		cout << "\n\nInforme sua opcao: ";
		int opc;
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			int item;
			cout << "Valor do elemento (int): ";
			cin >> item;
			lista.insereInicio(item);
			system("pause"); /*chamada Windows. Em outro ambiente comente esta linha*/
		} else if (opc == 2) {
		    int item;
			cout << "Valor do elemento (int): ";
			cin >> item;
			lista.insereFinal(item);
			system("pause"); /*chamada Windows. Em outro ambiente comente esta linha*/

		} else if(opc == 3) { //////////////////////ok
			int item;
			int pos;
			cout << "\nValor do elemento (int): ";
			cin >> item;
			cout << "Posicao a ser inserido: ";
			cin >> pos;
			Celula * c = new Celula(item);
			cout << lista.insereEmN(c, pos);
			pausa();
		} else if (opc == 4) { //////////////////////ok
            int pos = 1;
            cout << lista.deletaEmN(pos);
			pausa();
        } else if (opc == 5) {
			int pos = lista.tamanho(); //última posição ok
            cout << lista.deletaEmN(pos);
			pausa();
        } else if (opc == 6) { //////////////////////ok
			int pos;
			cout << "Posicao a ser deletada: ";
			cin >> pos;
            cout << lista.deletaEmN(pos);
			pausa();
		} else if (opc == 7) {
			cout << "\n\nTamanho da lista = " << lista.tamanho() << " elemento(s)";
			pausa();
		} else if (opc == 8) {
			cout << "\n\nImpressao dos elemento da lista -> ";
			lista.imprime();
			pausa();
		} else if (opc == 9) { ////////////////////// ok
			lista.imprimeAoContrario();
			pausa();
		} else if (opc == 10){
		    int ret = lista.primeiro();
		    if (ret != -1){
		        cout << "Primeiro da Lista: ";
		        cout << ret;
		    }else
		        cout << "Lista Vazia";
		    pausa();
        } else if (opc == 11){

		    int ul = lista.ultimo();
		    if (ul != -1){
		        cout << "Ultimo da Lista: ";
		        cout << ul;
		    }else
		        cout << "Lista Vazia";
		    pausa();
		}

	}

	return 0;
}


void ni() {
	system("cls");/*chamada Windows. Em outro ambiente comente esta linha*/
	cout << "\n\n\n\n\n          ***********************";
	cout << "\n\n          AINDA NAO IMPLEMENTADO.\n\n";
	cout << "          ***********************\n\n\n\n\n\n\n\n\n";
	system("pause");/*chamada Windows. Em outro ambiente comente esta linha*/
}


void pausa() {
	cout << "\n\n\n\n";
	system("pause");/*chamada Windows. Em outro ambiente comente esta linha*/
}



