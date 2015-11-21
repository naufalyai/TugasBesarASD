#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>


#define info(p) (p)->info
#define next(p) (p)->next
#define prev(p) (p)->prev
#define first(l) ((l).first)
#define last(l) ((l).last)
#define infok(p) (p)->infok
#define nextk(p) (p)->nextk
#define prevk(p) (p)->prevk
#define firstchild(p) p->firstchild
#define lastchild(p) p->lastchild


using namespace std;

struct date
{
    int tahun;
    int bulan[12];
    int tanggal[31];
};

struct infostatus
{
    string status;
    string nama;
    string idstatus;
    date tanggal;
};

struct infokomentar
{
    string nama;
    string idkomentator;
    string komentar;
    date tanggal;
};

typedef struct elmstatus *address;
typedef struct elmkomentar *address_k;

struct elmstatus
{
    infostatus info;
    address next;
    address prev;
    address_k firstchild;
    address_k lastchild;
    //address_k firstk;
    //address_k lastk;
};

struct elmkomentar
{
    infokomentar infok;
    address_k nextk;
    address_k prevk;
};

struct list{
    address first;
    address last;
};


void createlist(list &l);
address alokasistatus (infostatus x);
address_k alokasikomentar (infokomentar xanak);
void dealokasistatus(address p);
void dealokasikomentar(address_k p);

void insertFirstStatus (list &l, address p);
void insertLastStatus (list &l, address p);
void insertAfterStatus (list &l, address p,address prec);
void deleteFirstStatus (list &l);
void deleteLastStatus (list &l);
void deleteAfterStatus (list &l);
void insertFirstKomen (address &p, address_k c);
void insertLastKomen (address &p, address_k c);
void insertAfterKomen (address &p, address_k c,address_k prec);
void deleteFirstKomen (address &p);
void deleteLastKomen (address &p);
void deleteAfterKomen (address &p);

void tambahstatus (list &l, infostatus x);
void deletestatusdankomentar (list &l, string idstatus);
void deletekomentar (address &p,string idkomentar );
void tambahkomentar(address &p,infokomentar c);

address caristatusID (list l,string idstatus);
address caristatusnama (list l,string nama);
address_k carikomentarID (list l,string idkomen);
void editstatus (list &l,string idyangdiedit);
void trendingstatus (list l);
void sortingtanggalstatus(list l);
void viewlistkomentar(list l,string x);
void akunterbanyakkomen(list l,string idstatus);

#endif // TUBES_H_INCLUDED
