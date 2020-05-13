#ifndef PARENT1_H_INCLUDED
#define PARENT1_H_INCLUDED
#include <iostream>
#define nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
typedef struct programmer {
    string username;
    string password;
    int usia;
    int jum;
};

typedef struct elmL1 *addresspointer1;
typedef programmer infotype;

struct elmL1 {
    infotype info;
    addresspointer1 next;
    addresspointer1 prev;
};

struct DLL {
    addresspointer1 first;
    addresspointer1 last;
};


void createL1(DLL &L);

addresspointer1 allocate1(infotype x);
void deallocate1 (addresspointer1 P);


void delAfter1 (addresspointer1 Q, addresspointer1 &P);
void delFirst1 (DLL &L, addresspointer1 &P);
void delLast1 (DLL &L, addresspointer1 &P);

void update1 (DLL &L, string x);

void insAfter1 (addresspointer1 &Q, addresspointer1 &P);
void insFirst1 (DLL &L, addresspointer1 P);
void insLast1 (DLL &L, addresspointer1   P);

void show1 (DLL L);
addresspointer1 search1 (string x, DLL L);
void insertProgrammer (DLL &L, addresspointer1 P);
//void insertProgrammer(DLL &L, addresspointer1 &P);


#endif // PARENT1_H_INCLUDED
