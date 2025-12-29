#include "LDLCIRCIPCNC.h"
//#include "LSLTNIVSNC.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

LDLCIRCIPCNC::LDLCIRCIPCNC()
{
    p = (struct NodoD*)malloc(sizeof(struct NodoD));
    p->pDer = p->pIzq = p;
    //printf("raíz %x\n",p);
}

LDLCIRCIPCNC::~LDLCIRCIPCNC()
{

}

int LDLCIRCIPCNC::Cardinalidad()
{
    int cuantos = 0;
    for (struct NodoD* pTmp = p->pDer; pTmp != p;
        pTmp = pTmp->pDer)
        cuantos++;
    return cuantos;
}

void LDLCIRCIPCNC::Despliega()
{
    for (struct NodoD* pTmp = p->pDer; pTmp != p;
        pTmp = pTmp->pDer)
        cout << pTmp->dato << "\t";
    cout << endl;
}

bool LDLCIRCIPCNC::Elimina(int* dato, int pos)
{
    //cout << "adentro del elimina" << endl;
    struct NodoD* pTmp = p->pDer;
    int miPos = 1;
    //for(;miPos != pos; pos++)
    for (;miPos != pos; miPos++)
    {
        /*cout << "Izq: " << pTmp->pIzq << endl;
        cout << "pTmp: " << pTmp << endl;
        cout << "Der: " << pTmp->pDer << endl;*/
        if (pTmp == p)
            return false;
        pTmp = pTmp->pDer;
    }
    if (pTmp == p)  // Se ejecutaba si era vacía
        return false;
    *dato = pTmp->dato;
    //cout << endl << "En el elimina" << *dato << endl;
    // Hago que la lista deje de apuntar al nodo
    pTmp->pIzq->pDer = pTmp->pDer;
    pTmp->pDer->pIzq = pTmp->pIzq;
    free(pTmp);
    return true;
}

bool LDLCIRCIPCNC::EsElemento(int dato)
{
    for (struct NodoD* pTmp = p->pDer; pTmp != p;
        pTmp = pTmp->pDer)
        if (pTmp->dato == dato)
            return true;
    return false;
}

bool LDLCIRCIPCNC::EsVacia()
{
    return (p->pDer == p) ? true : false;
}

bool LDLCIRCIPCNC::Inserta(int dato, int pos)
{
    struct NodoD* pNue = (struct NodoD*)malloc(
        sizeof(struct NodoD));
    if (pNue == NULL)
        return false;
    pNue->dato = dato;
    struct NodoD* pTmp = p->pDer;
    int miPos = 1;
    for (; miPos != pos; miPos++)
    {
        if (pTmp == p)
            break;
        pTmp = pTmp->pDer;
    }
    if (miPos != pos)
    {
        free(pNue);
        return false;
    }
    //printf("pTmp %x\n",pTmp);
    // Hago que el nodo nuevo apunte a la lista
    pNue->pIzq = pTmp->pIzq;
    pNue->pDer = pTmp;
    /*printf("pNue->pIzq %x\n",pNue->pIzq);
    printf("pNue->pDer %x\n",pNue->pDer);*/
    // Hago que la lista apunte al nodo nuevo
    pTmp->pIzq->pDer = pNue;
    //printf("pTmp->pIzq->pDer %x\n",pTmp->pIzq->pDer);
    pTmp->pIzq = pNue;
    //printf("pTmp->pIzq %x\n",pTmp->pIzq);
    return true;
}

