#include "relasi.h"


void createLR(CSL &L){
    first(L) = NULL;
}

addressrelasi allocateR(infoR x) {
    addressrelasi R = new elmrel; //tiap mau manggil alocateR
    info(R)=x;
    next(R) = NULL;                 // project data ; data.bahasa
    return R;
}

void deallocateR (addressrelasi P){
    delete P;
    P = NULL;
}

void delAfterR (CSL &L, addressrelasi prec, addressrelasi &P){
    if (next(prec)==first(L)) delFirstR(L,P);
    else{
        P=next(prec);
        next(prec)=next(P);
        next(P)=NULL;
    }
}

void delFirstR(CSL &L, addressrelasi &P){
   if (first(L)==next(first(L))){
        P=first(L);
        next(P)=NULL;
        first(L)=NULL;
   }
   else {
    addressrelasi Q = first(L);
    while (first(L)!=next(Q)) Q=next(Q);
    P = first(L);
    next(Q)=next(P);
    first(L)=next(P);
    next(P)=NULL;
   }
}
void delLastR (CSL &L, addressrelasi &P){
    if (next(first(L))==first(L)) delFirstR(L,P);
    else{
        addressrelasi Q = first(L);
        while (next(next(Q))!=first(L)){
            Q=next(Q);
        }
        P=next(Q);
        next(Q)=first(L);
        next(P)=NULL;
        }
    }

void updateR (CSL &L, addressrelasi P){

}
void insFirstR(CSL &L, addressrelasi P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else {
        addressrelasi Q = first(L);
        while(next(Q) != first(L)) Q = next(Q);
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insAfterR(addressrelasi &Prec, addressrelasi &P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void insLastR(CSL &L, addressrelasi P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else {
        addressrelasi Q = first(L);
        while(next(Q) != first (L)) Q = next(Q);
        next(P) = first(L);
        next(Q) = P;
    }
}
// infoR data;
// data.p1 = search1(x,L);
//searchR(data,LR)
addressrelasi searchR (infoR x, CSL L){
    addressrelasi P = first(L);
    while ((next(P)!=first(L)) && ((info(P).p1!=x.p1) || (info(P).p2 !=x.p2))){
        P=next(P);
    }
   if ((info(P).p1==x.p1) && (info(P).p2 ==x.p2)){
    return P;
   }
   else {
    return NULL;
   }

}

void showR_Programmer (CSL L){
    addressrelasi P = first(L);
    addressrelasi Q = first(L);
    if(first(L) != NULL){
        while (next(P) != first(L) ){
            cout<<info(info(P).p1).username<<endl;
            cout<<info(info(P).p1).password<<endl;
            cout<<info(info(P).p1).usia<<endl;
            P = next(P);
        }
        cout<<info(info(P).p1).username<<endl;
        cout<<info(info(P).p1).password<<endl;
        cout<<info(info(P).p1).usia<<endl;
    }

    else{
        cout<<"LIST IS EMPTY"<<endl;

}
}

void showR_Project(CSL L){
    addressrelasi Q=first(L);
     if(first(L) != NULL){
        while (next(Q) != first(L) ){
            cout<<info(info(Q).p2).nama_project<<endl;
            cout<<info(info(Q).p2).bahasa<<endl;
            cout<<info(info(Q).p2).dateline<<endl;
            Q = next(Q);
        }
        cout<<info(info(Q).p2).nama_project<<endl;
        cout<<info(info(Q).p2).bahasa<<endl;
        cout<<info(info(Q).p2).dateline<<endl;
    }

    else{
        cout<<"LIST IS EMPTY"<<endl;

}
}
bool cekrelasi(CSL L,infoR x){
    addressrelasi P=first(L);
    if(P==NULL) return false;
    else{
        while(next(P)!=first(L)&&(info(P).p1!=x.p1||info(P).p2 !=x.p2)) P=next(P);
        if(info(P).p1==x.p1&&info(P).p2 ==x.p2) return true;
        else return false;
    }
}
void top5(DLL L1){
        DLL Ltemp;
        createL1(Ltemp);
        addresspointer1 P=first(L1);
            while (P!=NULL) {
                if (first(Ltemp)==NULL) insFirst1(Ltemp,allocate1(info(P)));
                else if (info(P).jum<info(first(Ltemp)).jum) insFirst1(Ltemp,allocate1(info(P)));
                else if (info(P).jum>info(last(Ltemp)).jum) insLast1(Ltemp,allocate1(info(P)));
                    else{
                    addresspointer1 x=first(Ltemp);
                    while ((x!=NULL)&&(info(next(x)).jum<info(P).jum)) x=next(x);
                    addresspointer1 B=allocate1(info(P));
                    insAfter1(x,B);
                    }
                P=next(P);
            }
            P=last(Ltemp);
            int i = 1;
            cout<<"cekkk"<<endl;
//                while ((P!= NULL) && (i<=5)){
//                    cout<<info(P).username<<endl;
//                    cout<<info(P).jum<<endl;
//                    i++;
//                    P = next(P);
//                }
            while ((P!= NULL) && (i<=5)){
                cout<<info(P).username<<endl;
                cout<<info(P).jum<<endl;
                i++;
                P = prev(P);
            }
                //first(Ltemp) = NULL;
}
