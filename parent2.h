#ifndef PARENT2_H_INCLUDED
#define PARENT2_H_INCLUDED
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

typedef struct project {
    string nama_project;
    string bahasa;
    string dateline;
};

typedef struct elmL2 *addresspointer2;
typedef project infotype2;
struct elmL2{
    infotype2 info;
    addresspointer2 next;
    addresspointer2 prev;
};

struct DLL2 {
    addresspointer2 first;
    addresspointer2 last;
};

void createL2(DLL2 &L);

addresspointer2 allocate2(infotype2 x);
void deallocate2 (addresspointer2 P);


void delAfter2 (addresspointer2 Q, addresspointer2 &P);
void delFirst2 (DLL2 &L, addresspointer2 &P);
void delLast2 (DLL2 &L, addresspointer2 &P);

void update2 (DLL2 &L, string x);

void insAfter2 (addresspointer2 &Q, addresspointer2 &P);
void insFirst2 (DLL2 &L, addresspointer2 P);
void insLast2 (DLL2 &L, addresspointer2 P);


void show2 (DLL2 L);
addresspointer2 search2 (string x, DLL2 L);
void insertProject (DLL2 &L, addresspointer2 P);


#endif // PARENT2_H_INCLUDED
