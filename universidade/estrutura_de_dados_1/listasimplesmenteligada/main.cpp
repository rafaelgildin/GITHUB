/* ******************************************************************
Implementacao do TAD Fila
Giulia Barbieri Quagliano  - TIA : 42013070
Rafael Avraham Gildin Acherboim - TIA : 31940242
****************************************************************** */
#include <cstdlib>
#include <iostream>
#include <locale.h>
#include "ListaLigada.h"

using namespace std;

void ni();
void pausa();

int main() {

	setlocale(LC_ALL, "Portuguese");
	ListaLigada lista;


	while (true) {

// 		system("cls"); /*chamada Windows. Em outro ambiente comente esta linha*/
		cout << "\n *** TESTANDO O TAD LISTA SIMPLESMENTE LIGADA ***\n";
		cout << "\n0 - sair";
		cout << "\n1 - inserir um novo nó no inicio";
		cout << "\n2 - inserir um novo nó no final";
		cout << "\n3 - inserir um novo nó na posicao 'n'";
		cout << "\n4 - inserir um novo nó imediatamente apos a posicao 'n'";
		cout << "\n5 - inserir um novo nó imediatamente antes da posicao 'n'";
		cout << "\n6 - excluir um nó da posicao 'n'";
		cout << "\n7 - excluir um nó imediatamente apos a posicao 'n'";
		cout << "\n8 - excluir um nó imediatamente antes da posicao 'n'";
		cout << "\n9 - informar o total de elementos na lista";
		cout << "\n10 - imprimir a lista";
		cout << "\n\nInforme sua opcao: ";
		int opc;
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			int opc1;
			cout << "Valor do elemento (int): ";
			cin >> opc1;
			lista.insereInicio(opc1);
// 			system("pause"); /*chamada Windows. Em outro ambiente comente esta linha*/
		} else if (opc == 2) {
			int opc2a;
			cout << "\nValor do elemento (int): ";
			cin >> opc2a;
            Celula * c = new Celula(opc2a);
            int pos = lista.qtdCelulas + 1;// usuário começa no 0
            lista.insereEmN(c, pos);
			pausa();
		} else if(opc == 3) {
			int opc3a;
			int opc3b;
			cout << "\nValor do elemento (int): ";
			cin >> opc3a;
			cout << "Posicao a ser inserido: ";
			cin >> opc3b;
			Celula * c = new Celula(opc3a);
			cout << lista.insereEmN(c, opc3b);
			pausa();
		} else if (opc == 4) {
			int opc4a;
			int opc4b;
			cout << "\nValor do elemento (int): ";
			cin >> opc4a;
			cout << "Posicao a ser inserido: ";
			cin >> opc4b;
			opc4b++;
			Celula * c = new Celula(opc4a);
			cout << lista.insereEmN(c, opc4b);
			pausa();
		} else if (opc == 5) {
			int opc5a;
			int opc5b;
			cout << "\nValor do elemento (int): ";
			cin >> opc5a;
			cout << "Posicao a ser inserido: ";
			cin >> opc5b;
			opc5b--;
			Celula * c = new Celula(opc5a);
			cout << lista.insereEmN(c, opc5b);
			pausa();
		} else if (opc == 6) {
		    int opc6;
		    cout << "Posicao a ser removida: ";
			cin >> opc6;
			lista.excluiN(opc6);
			pausa();
		} else if (opc == 7) {
			int opc7;
		    cout << "Posicao a ser removida: ";
			cin >> opc7;
			opc7++;
			lista.excluiN(opc7);
			pausa();
		} else if (opc == 8) {
			int opc8;
		    cout << "Posicao a ser removida: ";
			cin >> opc8;
			opc8--;
			lista.excluiN(opc8);
			pausa();
		} else if (opc == 9) {
			cout << "\n\nTamanho da lista = " << lista.tamanho() << " elemento(s)";
			pausa();
		} else if (opc == 10) {
			cout << "\n\nImpressao dos elemento da lista -> ";
			lista.imprime();
			pausa();
		}

	}

	return 0;
}


void ni() {
// 	system("cls");/*chamada Windows. Em outro ambiente comente esta linha*/
	cout << "\n\n\n\n\n          ***********************";
	cout << "\n\n          AINDA NAO IMPLEMENTADO.\n\n";
	cout << "          ***********************\n\n\n\n\n\n\n\n\n";
// 	system("pause");/*chamada Windows. Em outro ambiente comente esta linha*/
}


void pausa() {
	cout << "\n\n\n\n";
// 	system("pause");/*chamada Windows. Em outro ambiente comente esta linha*/
}



