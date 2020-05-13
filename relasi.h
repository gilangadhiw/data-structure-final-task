#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "parent1.h"
#include "parent2.h"
#include <iostream>
#define nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#include <windows.h>

using namespace std;
typedef struct elmrel* addressrelasi;
typedef struct infoR{
    addresspointer1 p1;
    addresspointer2 p2;
};
struct elmrel{
    addressrelasi next;
    infoR info;
};

struct CSL {
    addressrelasi first;
};

 void createLR(CSL &L);

addressrelasi allocateR(infoR x);
void deallocateR (addressrelasi P);

void delAfterR (CSL &L, addressrelasi prec, addressrelasi &P);
void delFirstR (CSL &L, addressrelasi &P);
void delLastR (CSL &L, addressrelasi &P);

void updateR (CSL &L, addressrelasi P);

void insAfterR (CSL &L, addressrelasi P);
void insFirstR (CSL &L, addressrelasi P);
void insLastR (CSL &L, addressrelasi P);

void showR_Programmer(CSL L);
addressrelasi searchR (infoR x, CSL L);
void showR_Project(CSL L);

/////////MENU////////
void loginadmin(bool &out);
void loginmanajer (bool &out);
void loginProgrammer (DLL L1, CSL L2, bool &out);
void submenu1 (DLL &L1, DLL2 &L2, CSL &L3);
void submenu2 (DLL &L1, DLL2 &L2, CSL &L3);
void submenu3 (DLL &L1, DLL2 &L2, CSL &L3);


bool cekrelasi(CSL L,infoR x);

void top5(DLL L1);
#endif // RELASI_H_INCLUDED
