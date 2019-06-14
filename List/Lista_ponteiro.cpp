#include <iostream>

using namespace std;


struct No {
    int Info;
    No * Lig;
};

typedef struct No *NoPtr;


void InsereLista (NoPtr& L, int Novo) {
    if (L == NULL) {  // INSERÇÃO DO PRIMEIRO NÓ
        L = new No;
        L->Info = Novo;
        L->Lig = NULL;
    } else {                // AJUSTA PONTEIROS ANT E AUX
        NoPtr Ant = NULL;
        NoPtr Aux = L;
        while((Aux != NULL)&&(Aux->Info < Novo)) { //ENCONTRA POSIÇÃO
            Ant = Aux;
            Aux = Aux->Lig;
        }
        Aux = new No;
        Aux->Info = Novo;
        if (Ant == NULL) {
            Aux->Lig = L;
            L = Aux;
        } else {
            Aux->Lig = Ant->Lig;
            Ant->Lig = Aux;
        }
    }
}

NoPtr ConcatenaListas (NoPtr &L1, NoPtr &L2) { // CONCATENA DUAS LISTAS APRESENTADO EM SALA - ELE ALTERA A LISTA L1
    if((L1 != NULL)&&(L2==NULL))
        return L1;
    if((L1 == NULL)&&(L2!=NULL))
        return L2;
    if((L1 == NULL)&&(L2==NULL))
        return NULL;
    NoPtr Aux = L1;
    NoPtr Ant = NULL;
    while(Aux != NULL) {
        Ant = Aux;
        Aux = Aux->Lig;
    }
    Ant->Lig = L2;
    return L1;
}

bool RetiraLista (NoPtr& L, int Novo) {
    NoPtr Ant = NULL;
    NoPtr Aux = L;
    while ((Aux != NULL) && (Aux->Info != Novo)) {
        Ant = Aux;
        Aux = Aux->Lig;
    }
    if (Aux == NULL)
        return false;
    if (Aux == L)
        L = L->Lig;
    else
        Ant->Lig = Aux->Lig;
    delete Aux;
    return true;
}


void ImprimeLista (NoPtr L) {
    NoPtr Ant = NULL;
    NoPtr Aux = L;
    cout << "L -> ";
    while ((Aux != NULL)) {
        Ant = Aux;
        Aux = Aux->Lig;
        cout << Ant->Info << " -> ";
    }
    if (Aux == NULL)
        cout << "NULL" << endl;
}

void ImprimeListaRec (NoPtr L) {
    if (!(L == NULL)) {
        cout << L->Info << " -> ";
        ImprimeListaRec(L->Lig);
    } else
        cout << "NULL" << endl;
}

void removeRepetido(NoPtr& L) {
    if(L!= NULL) {
        NoPtr Laux = NULL, Aux = NULL;
        InsereLista(Laux, L->Info);
        Aux = Laux;
        while(L!= NULL) {
            if(L->Info != Aux->Info) {
                InsereLista(Laux, L->Info);
                Aux = Aux->Lig;
            }
            RetiraLista(L, Aux->Info);
        }
        while(Laux!= NULL) {
            InsereLista(L, Laux->Info);
            RetiraLista(Laux, Laux->Info);
        }
    }
}

NoPtr mesclaListas(NoPtr& L1, NoPtr& L2){
    if(L1 == NULL || L2==NULL)
        return NULL;

    NoPtr L3 = NULL;
    NoPtr Aux1 = L1, Aux2 = L2;
    while(Aux1->Lig != NULL || Aux2->Lig != NULL){
        if(Aux1->Lig == NULL){
            InsereLista(L3, Aux2->Info);
            Aux2 = Aux2->Lig;
        }else if(Aux2->Lig == NULL){
            InsereLista(L3, Aux1->Info);
            Aux1 = Aux1->Lig;
        }else{
            InsereLista(L3, Aux1->Info);
            InsereLista(L3, Aux2->Info);
            Aux1 = Aux1->Lig;
            Aux2 = Aux2->Lig;
        }
        if(Aux1->Lig == NULL && Aux2->Lig == NULL){
            InsereLista(L3, Aux1->Info);
            InsereLista(L3, Aux2->Info);
        }

    }
    return L3;
}

int main () {
    NoPtr L  = NULL;
    NoPtr L1 = NULL;
    NoPtr L2 = NULL;

    InsereLista(L, 3);
    InsereLista(L, 2);
    InsereLista(L, 1);
    InsereLista(L, 4);
    InsereLista(L, 1);
    InsereLista(L, 2);
    InsereLista(L, 5);
    InsereLista(L, 4);
    InsereLista(L, 2);
    InsereLista(L, 2);

    ImprimeListaRec(L);

    removeRepetido(L);

    ImprimeListaRec(L);


    return 0;
}
