#include <iostream>
// #include "..\bibliotecas\ABB.h"
// #include "..\bibliotecas\Fila.h" 
#include <queue>

using namespace std;

struct noABB {
	int info;
	noABB *Llink;
	noABB *Rlink;
};

noABB *ini_AB(noABB *T) {
	return NULL;
}

noABB *novoNo_AB(noABB *T, int x) {
	T = new noABB;
	if (T != NULL) {
		T->info = x;
		T->Llink = NULL;
		T->Rlink = NULL;
	}
	return T;
}

noABB *insere_AB(noABB *T, int x) {
	if (T == NULL){
		T = novoNo_AB(T,x);
		return T;
	}
	else {
		if (x < T->info){ 
			T->Llink = insere_AB(T->Llink, x);
		}
		else {	 
				T->Rlink = insere_AB(T->Rlink, x);
		}
		return T;
	}
}

void emOrdem_AB(noABB *T) {
	if(T != NULL) {
		emOrdem_AB(T->Llink);
		cout << T->info << " ";
		emOrdem_AB(T->Rlink);
	}
}

void imprimeDecrescente(noABB *T) { // (Ex 3) imprime árvore em ordem decrescente.
    if (T != NULL) {
        imprimeDecrescente(T->Rlink);
        cout << T->info << " ";
        imprimeDecrescente(T->Llink);
    }
}

void percursoLargura(noABB *T) { // (Ex 1) imprime o percurso em largura e quebra a linha a cada nível
    
	if (T == NULL){
		return;
	}
		
    queue<noABB*> P;  
    P.push(T);   // aficiona a raiz

    while(!P.empty()){ // enquanto tem coisa na fila
        int quantNos = P.size(); 

        for (int i = 0; i < quantNos; i++) {
            noABB* atual = P.front(); // retorna o primeiro elemento
            P.pop(); // remove

            cout << atual->info << " "; // printa

            if (atual->Llink) { // verifica se é filho da direita ou esquerda
				P.push(atual->Llink); // da push
			}
            if (atual->Rlink){
				P.push(atual->Rlink);
			}
			
        }
		cout << endl; // quebra a linha p representar os niveis
    }
	
}

int main() {
    noABB *T; // não noABB*
    int x;
    T = ini_AB(T);

    cout << "Insira 10 valores para inserir na arvore:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> x;
        T = insere_AB(T, x);
    }

    cout << "Arvore crescente (em ordem): " << endl;
    emOrdem_AB(T);
    cout << endl;

    cout << "Arvore decrescente: " << endl;
    imprimeDecrescente(T);
    cout << endl;

    cout << "Percurso em largura: " << endl;
    percursoLargura(T);

    return 0;
}
