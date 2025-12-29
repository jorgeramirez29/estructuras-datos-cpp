#ifndef LDLCIRCIPCNC_H
#define LDLCIRCIPCNC_H

struct NodoD
{
    int dato;
    struct NodoD* pIzq;
    struct NodoD* pDer;
};

class LDLCIRCIPCNC
{
protected:
    struct NodoD* p;
public:
    LDLCIRCIPCNC();
    virtual ~LDLCIRCIPCNC();
    int  Cardinalidad();
    void Despliega();
    bool Elimina(int* dato, int pos);
    bool EsElemento(int dato);
    bool EsVacia();
    bool Inserta(int dato, int pos);
};

#endif /* LDLCIRCIPCNC_H */

