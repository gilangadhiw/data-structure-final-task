#include "parent2.h"

void createL2(DLL2 &L){
    first(L) = NULL;
    last(L) = NULL;
}

addresspointer2 allocate2(infotype2 x) {
    addresspointer2 P = new elmL2;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate2 (addresspointer2 P){
    delete P;
    P = NULL;
}

void delAfter2 (addresspointer2 Q, addresspointer2 &P){
    P = next(Q);
    next(Q) = next(P);
    prev(next(P)) = Q;
    next(P) = NULL;
    prev(P) = NULL;
}

void delFirst2 (DLL2 &L, addresspointer2 &P){
    P = first(L);
    if (first(L) != NULL){
        if(next(P)!=NULL){
            first(L) = next(P);
            prev(next(P)) = NULL;
            next(P)=NULL;
        }
        else{
            first(L)=NULL;
            last(L)=NULL;
    }
}
}
void delLast2 (DLL2 &L, addresspointer2 &P){
    P = last(L);
    last(L) = prev(P);
    prev(P) = NULL;
    next(last(L)) = NULL;
}

void update2 (DLL2 &L, string x){
    addresspointer2 P = search2(x, L);
    if (P==NULL){
        cout<<"data not found"<<endl;
    }
    else {
        cout<<"masukan project : ";cin>>info(P).nama_project;
        cout<<"masukan bahasa  : "; cin>>info(P).bahasa;
        cout<<"masukan dateline : "; cin>>info(P).dateline;
        cout<<""<<endl;
        cout<<"\t Updated Successfully!"<<endl;
        system("pause");
    }
    }

void insAfter2 (addresspointer2 &Q, addresspointer2 &P){
    next(P) = next(Q);
    prev(next(Q)) = P;
    next(Q) = P;
    prev(P) = Q;
}


void insFirst2 (DLL2 &L, addresspointer2 P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;           //DOUBLE BRO

    }
   else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insLast2 (DLL2 &L, addresspointer2 P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L)=P;
    }
}

addresspointer2 search2 (string x, DLL2 L){
    addresspointer2 P = first(L);
    if (first(L) != NULL ){
        while ((next (P) != NULL) && (info(P).nama_project != x)){
            P = next(P);
        }
        if (info(P).nama_project==x) return P;
        else{
            return NULL;
        }
    }
    return NULL;
}

void show2 (DLL2 L){
    addresspointer2 P = first(L);
    if(P != NULL){
        while (P != NULL){
            cout<<"Nama projek : "<<info(P).nama_project<<endl;
            cout<<"Bahasa yang digunakan : "<<info(P).bahasa<<endl;
            cout<<"Dateline : "<<info(P).dateline<<endl;
            cout<<""<<endl;
            P = next(P);
        }
    }
    else{
        cout<<"LIST IS EMPTY"<<endl;
}
}



void insertProject (DLL2 &L, addresspointer2 P){
    if (first(L)==NULL) insFirst2(L, P);
    else{
        if (info(P).nama_project < info(first(L)).nama_project) insFirst2(L,P);
        else if (info(P).nama_project>info(last(L)).nama_project) insLast2(L,P);
        else{
            addresspointer2 Q = first(L);
            while (next(Q)!=first(L)&&(info(P).nama_project>info(next(Q)).nama_project)) Q=next(Q);
            insAfter2(Q, P);
        }
    }
    }

