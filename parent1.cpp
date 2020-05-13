#include "parent1.h"

void createL1(DLL &L){
    first(L) = NULL;
    last(L) = NULL;
}

addresspointer1 allocate1(infotype x) {
    addresspointer1 P = new elmL1;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate1 (addresspointer1 P){
    delete P;
    P = NULL;
}

void delAfter1 (addresspointer1 Q, addresspointer1 &P){
    P = next(Q);
    next(Q) = next(P);
    prev(next(P)) = Q;    //KURANG BENER ALGORITMA NYA
    next(P) = NULL;
    prev(P) = NULL;
}

void delFirst1 (DLL &L, addresspointer1 &P){
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

void delLast1 (DLL &L, addresspointer1 &P){
    P = last(L);
    last(L) = prev(P);
    prev(P) = NULL;
    next(last(L)) = NULL;
//    if (P != NULL){
//        if (prev(P) != NULL){
//            last(L) = prev(P);
//            prev(P) = NULL;
//            next(P) = NULL;
//        }
//        else{
//            first(L)=NULL;
//            last(L)=NULL;
//}
//}
}

void update1 (DLL &L, string x){
    addresspointer1 P = search1(x, L);
    if (P==NULL){
        cout<<"data not found"<<endl;
    }
    else {
        cout<<"Username baru : ";cin>>info(P).username;
        cout<<"password baru : "; cin>>info(P).password;
        cout<<"usia baru : "; cin>>info(P).usia;
        cout<<""<<endl;
        cout<<"\t Updated Successfully!"<<endl;
        system("pause");
    }
}
void insAfter1 (addresspointer1 &Q, addresspointer1 &P){

    next(P) = next(Q);
    prev(P) = Q;

    prev(next(Q)) = P;
    next(Q) = P;

}

void insFirst1 (DLL &L, addresspointer1 P){
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

void insLast1 (DLL &L, addresspointer1 P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        prev(P) = last( L);
        next(last(L)) = P;
        last(L)=P;
    }
}

addresspointer1 search1 (string x, DLL L){
    addresspointer1 P = first(L);
    if (first(L) != NULL ){
        while ((next (P) != NULL) && (info(P).username != x)){
            P = next(P);
        }
        if (info(P).username==x)
            return P;
        else
            return NULL;
    }
    return NULL;
}

void show1 (DLL L){
    addresspointer1 P = first(L);
    if(P != NULL){
        while ((P) != NULL){
            cout<<"Username : "<<info(P).username<<endl;
            cout<<"Password : "<<info(P).password<<endl;
            cout<<"Usia : "<<info(P).usia<<endl<<endl;
            P = next(P);
        }
    }
    else{
        cout<<"LIST IS EMPTY"<<endl;
}
}


void insertProgrammer (DLL &L, addresspointer1 P){
    if (first(L)==NULL) insFirst1(L, P);
    else{
        if (info(P).username < info(first(L)).username) insFirst1(L,P);
        else if (info(P).username>info(last(L)).username) insLast1(L,P);
        else{
            addresspointer1 Q = first(L);
            while (next(Q)!=first(L)&&(info(P).username>info(next(Q)).username)) Q=next(Q);
            insAfter1(Q,P);
        }
    }
    }


