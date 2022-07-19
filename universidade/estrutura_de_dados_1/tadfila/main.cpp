/* ******************************************************************
Implementacao do TAD Fila
Giulia Barbieri Quagliano  - TIA : 42013070
Rafael Avraham Gildin Acherboim - TIA : 31940242
 
****************************************************************** */


#include <iostream>
#include "tad_fila.h"

using namespace std;


//Testando o TAD FILA
int main() {

    cout << "\n-------------------------------------------------------";
    cout << "\n    PROGRAMA PARA APRENDIZADO DO TAD FILA CIRCULAR";
    cout << "\n-------------------------------------------------------";

    int tamVet;
    cout << "\n\nPrimeiramente, informe o tamanho do vetor para criarmos a fila: ";
    cin >> tamVet;

    //Criando a fila
	Fila fila(tamVet);
    while(true) {
        cout << "\n0 - sair ";
        cout << "\n1 - inserir na fila (enqueue) ";
        cout << "\n2 - remover da fila (dequeue)";
        cout << "\n3 - imprimir a fila ";
        cout << "\n4 - verificar se um item/dado esta na fila" ;
        cout << "\n5 - tamanho da fila ";
        cout << "\n6 - ordenar a fila ";
        cout << "\n7 - pegar o primeiro valor";
        cout << "\n8 - pegar o ultimo valor";
        

        int opc = 0;
        cout << "\n\nDigite sua opcao: ";
        cin >> opc;

        if (opc == 0) {
            break;
        } else if (opc == 1) {
            int dado = -1;
            cout << "\nInforme o valor do dado: ";
            cin >> dado;
            int x = fila.inserir(dado);
            if (x == -1) {
                cout << "\nERRO: A fila esta lotada.";
            } else if (x == -2) {
                cout << "\nERRO: Este elemento ja esta na fila."; ////////////////////////
            } else {
                cout << "\nDado adicionado com sucesso na posicao " << x << " da fila";
            }
        } else if (opc == 2) {
        	int x = fila.extrair();
        	if (x == -1) {
                cout << "\nERRO: A fila esta vazia.";
        	}
			else{
				cout << "Elemento removido da fila" << endl;
				cout << fila.imprimir();
			}
        } else if (opc == 3) {
            cout << fila.imprimir();
        } else if (opc == 4) {
        	int elem;
        	cout << "Qual elemento deseja procurar na fila? ";
        	cin >> elem;
        	int res = fila.posicaoDoIntem(elem);
        	if (res == -1)
        		cout << "Elemento nao esta na fila";
        	else
        		cout << "Elemento esta na fila na posicao " << res << endl;

        }else if (opc == 5) {
            cout << "\nTamanho da fila: " << fila.tamFila() << endl;;

        }else if (opc == 6) {
            cout << "Ordenando a fila" << endl;
            fila.ordenar();
        }else if (opc == 7) {
            int res = fila.front();
            if (res == -1)
            	cout << "Fila vazia";
            else
            	cout << "o primeiro valor é " << res << endl;
        } else if (opc == 8) {
             int res = fila.back();
            if (res == -1)
            	cout << "Fila vazia";
            else
            	cout << "o ultimo valor é " << res << endl;
        }    

        cout << "\n\n";
        cout << "\n-------------------------------------------------------";
        cout << "\n    PROGRAMA PARA APRENDIZADO DO TAD FILA CIRCULAR";
        cout << "\n-------------------------------------------------------";
    }
    

    return 0;
}

