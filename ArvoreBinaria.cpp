/*+--------------------------------------------------------+
  | Árvore Binária - 2018                                  |
  |--------------------------------------------------------|
  | NOME                           |                   	   |
  |--------------------------------------------------------|
  | Johnata Davi Teixeira Silva    | 		           |        
  +--------------------------------------------------------+*/

#include <iostream>

#define espaco  5

using namespace std;

struct No {
    char info;
    struct No *esq;
    struct No *dir;
};

typedef struct No *Arvore;


void insere (Arvore& a, char c) {

    if (a == NULL) {  // INSERÇÃO DO NÓ
        a = new No;
        a->info = c;
        a->dir = NULL;
        a->esq = NULL;
    } else if (c > a->info)
        insere (a->dir, c); // INSERINDO NO RAMO DIREITO
    else
        insere (a->esq, c); // INSERINDO NO RAMO ESQUERDO
}

void ordem (Arvore& a) { // CAMINHAMENTO EM ORDEM
    if (a!=NULL) {
        ordem (a->esq);
        cout << a->info << "   " ;
        ordem (a->dir);
    }
}

void pre_ordem (Arvore& a) { // CAMINHAMENTO EM ORDEM
    if (a!=NULL) {
        cout << a->info << "   " ;
        pre_ordem (a->esq);
        pre_ordem (a->dir);
    }
}

void pos_ordem (Arvore& a) { // CAMINHAMENTO EM ORDEM
    if (a!=NULL) {
        pos_ordem (a->esq);
        pos_ordem (a->dir);
        cout << a->info << "   " ;
    }
}

void mostra (Arvore& a, int n) {
    if (a) {
        int i;
        mostra (a->dir, n+1);
        for (i = 0; i < n; i++)
            cout << "    ";
        cout << a->info << endl;
        mostra (a->esq, n+1);
    }
}


Arvore maxMin(Arvore no) {
    if(no->dir != NULL)
        return maxMin(no->dir);
    else {
        Arvore aux = no;
        if(no->esq != NULL)
            no = no->esq;
        else
            no = NULL;
        return aux;
    }
}


Arvore deletaNo(Arvore& a, char elemento) {
    if (a!=NULL) {
        if(elemento > a->info)
            a->dir = deletaNo(a->dir, elemento);
        else if(elemento < a->info)
            a->esq = deletaNo(a->esq, elemento);
        else {
            if(a->esq==NULL && a->dir==NULL) {
                delete a;
                a = NULL;
            } else if(a->dir==NULL) {
                Arvore aux = a;
                a = a->esq;
                delete aux;
                aux = NULL;
            } else if(a->esq==NULL) {
                Arvore aux = a;
                a = a->dir;
                delete aux;
                aux = NULL;
            } else {
                Arvore aux = maxMin(a->esq);
                a->info = aux->info;
                aux = NULL;
                a->esq = deletaNo(a->esq, a->info);
            }
        }
        return a;
    } else
        return a;
}


int grauNo(Arvore a, char data) {
    if(a != NULL) {
        if (data < a->info)
            grauNo(a->esq, data);
        else if (data > a->info)
            grauNo(a->dir, data);
        else {
            int cont = 0;
            if(a->dir!= NULL)
                cont++;
            if(a->esq!= NULL)
                cont++;
            return cont;
        }
    } else
        return -1;
}

int nivelNo(Arvore a, char data) {
    if(a != NULL) {
        int nivel=0;
        if (data < a->info) {
            nivel = nivelNo(a->esq, data) + 1;
        } else if (data > a->info) {
            nivel = nivelNo(a->dir, data) + 1;
        } else
            return nivel + 1;
    } else
        return 0;
}

int qtdElementos(Arvore& a) {
    if(a == NULL)
        return 0;
    else {
        int conte = qtdElementos(a->esq);
        int contd = qtdElementos(a->dir);
        return conte+contd+1;
    }
}

//void trocaNegativo(Arvore& a) {
//    if(a != NULL){
//        if(a->info == 'a') {
//            a->info = 'b';
//        } else {
//            trocaNegativo(a->esq);
//            trocaNegativo(a->dir);
//        }
//    }
//}

int qtdElemento(Arvore& a, char data) {
    if(a == NULL)
        return 0;
    else {
        if(a->info == data) {
            int cont = qtdElemento(a->esq, data);
            return cont+1;
        } else {
            qtdElemento(a->dir, data);
            qtdElemento(a->esq, data);
        }
    }
}


// Segunda forma de imprimir
//secondary function
void desenha_arvore_horiz(Arvore arvore, int depth, char *path, int dir)
{
    // stopping condition
    if (arvore== NULL)
        return;

    // increase spacing
    depth++;

    // start with direita no
    desenha_arvore_horiz(arvore->dir, depth, path, 1);

    // set | draw map
    path[depth-2] = 0;

    if(dir)
        path[depth-2] = 1;

    if(arvore->esq)
        path[depth-1] = 1;

    // print root after spacing
    cout << "\n";

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          cout << ("+");
      else if(path[i])
          cout << ("|");
      else
          cout << (" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          cout << (" ");
      else
          cout << ("-");
    }
    cout << arvore->info << endl;
    //printf("%d\n", arvore->valor);

    // vertical espacors below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          cout << ("|");
      else
          cout << (" ");

      for(int j=1; j<espaco; j++)
          cout << (" ");
    }

    // go to esquerda no
    desenha_arvore_horiz(arvore->esq, depth, path, 0);
}

//primary fuction
void draw_arvore_hor(Arvore arvore)
{
    // should check if we don't exceed this somehow..
    char path[255] = {};

    //initial depth is 0
    desenha_arvore_horiz(arvore, 0, path, 0);
}

int main () {
    char no = 'd';
    Arvore t = NULL;
    insere (t, 'd');
    insere (t, 'b');
    insere (t, 'b');
    insere (t, 'b');
    insere (t, 'c');
    insere (t, 'f');
    insere (t, 'a');
    insere (t, 'e');
    insere (t, 'h');
    insere (t, 'i');
    insere (t, 'e');
    insere (t, 'e');
    insere (t, 'e');
    insere (t, 'h');
    insere (t, 'i');

    cout << "Pre ordem     : " ;
    pre_ordem(t);

    cout << "\nOrdem         : " ;
    ordem(t);

    cout << "\nPos ordem     : " ;
    pos_ordem(t);

    cout << "\nGrau do No  " << no << " : " << grauNo(t, no) ;

    cout << "\nNivel do No " << no << " : " << nivelNo(t, no) ;

    cout << "\nQuantidade de elementos: " << qtdElementos(t);

    cout << "\nQuantidade de elemento: " << qtdElemento(t, 'e');

    cout << endl;
    cout << "\nArvore: \n";
    cout << endl;
    mostra (t, 0);
    cout << endl;

    deletaNo(t, no);
    cout << endl;

    cout << "\nArvore com No " << no <<" deletado: \n\n";
    mostra(t, 0);

    // Segunda forma de imprimir
    //cout << endl << endl;
    //draw_arvore_hor(t );a

    return 0;
}
