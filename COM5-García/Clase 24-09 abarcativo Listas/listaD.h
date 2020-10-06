#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

typedef struct nodoD
{
    float nota;
    struct nodoD* ant;
    struct nodoD* sig;
}nodoD;

#endif // LISTAD_H_INCLUDED
