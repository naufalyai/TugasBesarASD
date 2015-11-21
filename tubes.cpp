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


void insertFirstKomen(address &p,address_k c){
    if (firstchild(p)!=NULL)
    {
        nextk(c)=firstchild(p);
        prevk(firstchild(p))=c;
        firstchild(p)=c;
    }
    else
{
        firstchild(p)=c;
        lastchild(p)=c;
}
}

void insertLastKomen(address &p,address_k c){
  if (firstchild(p) != NULL)
    {
        prevk(c)=lastchild(p);
        nextk(lastchild(p))=c;
        lastchild(p)=c;
    }
    else
    {
        firstchild(p)=c;
        lastchild(p)=c;
    }
}

void insertAfterKomen(address &p,address_k c,string idkomenprec){
    address_k z;
    if(firstchild(p) != NULL)
    {
        z=firstchild(p);
        while((infok(z).idkomentator)!=(idkomenprec) || (z!=lastchild(p))){
            z=nextk(z);
        }
        if((infok(z).idkomentator)==idkomenprec && z!=lastchild(p)){
            prevk(c)=z;
            nextk(c)=nextk(z);
            prevk(nextk(z))=c;
            nextk(z)=c;}
        else if (z==lastchild(p))
        {
            insertLastKomen(p,c);
        }
        else{
            cout<<"Id komentar tidak ditemukan ";
        }
        }
    else
    {
        insertFirstKomen(p,c);
    }
}

//dzaky
void deleteFirstStatus(list &l) {
    address P=first(l);
    if (first(l)!=NULL) {
        if (next(P)==NULL) {
            first(l)=NULL;
            last(l)=NULL;
        }
        else {
            first(l)=next(first(l));
            next(P)=NULL;
            prev(P)=NULL;
            prev(first(l))=NULL;
        }
    }
}
void deleteLastStatus(list &l) {

    if (first(l)!=NULL) {
        address P=first(l);
        if (next(P)==NULL) {
            deleteFirstStatus(l);
        }
        else {
            address P=last(l);
            last(l)=prev(last(l));
            prev(P)=NULL;
            next(last(l))=NULL;
        }
    }
}

void deleteAfterStatus(list &l, address prec) {
    if(first(l)!=NULL) {
        address P = first(l);
        if(next(P) == NULL) {
            deleteFirstStatus(l);
        } else {
            while(P != NULL) {
                if(P == prec) {
                    if(next(next(P)) == NULL) {
                        deleteLastStatus(l);
                    } else {
                        address Q = next(P);
                        next(P) = next(next(P));
                        prev(next(P)) = P;
                        next(Q) = NULL;
                        prev(Q) = NULL;
                    }
                    break;
                }
                P = next(P);
            }
        }
    }
}

//uya

//komang

