#include "tubes.h"

using namespace std;

void createlist(list &l){
    first(l)=NULL;
    last(l)=NULL;
};

address alokasistatus (infostatus x){
    address p = new elmstatus;
    info(p)=x;
    next(p)=NULL;
    prev(p)=NULL;
    firstchild(p)=NULL;
    lastchild(p)=NULL;
    return p;
};

address_k alokasikomentar (infokomentar xanak){
    address_k c = new elmkomentar;
    infok(c)=xanak;
    nextk(c)=NULL;
    prevk(c)=NULL;
    return c;
};

void dealokasistatus (address p)
{
    free(p);
};

void dealokasikomentar (address_k p)
{
    free(p);
}
