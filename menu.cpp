#include "parent1.h"
#include "parent2.h"
#include "relasi.h"
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
const string user1="gilang";
const string pass1="gilang";
const string user2 ="rafid";
const string pass2="rafid";


void submenu1 (DLL &L1, DLL2 &L2, CSL &L3){
    char choice;
    bool out=false;
    infotype data;
    infotype2 data2;
    while(!out) {
        system("CLS");
        cout<<"\t\t =========SELAMAT DATANG========="<<endl;
        cout<<"\t\t     =========ADMIN========="<<endl;
        cout<<" "<<endl;
        cout<<"\t 1. INPUT DATA PROGRAMMER\n";
        cout<<"\t 2. UPDATE DATA PROGRAMMER\n";
        cout<<"\t 3. DELETE DATA PROGRAMMER\n";
        cout<<"\t 4. VIEW DATA PROGRAMMER\n";
        cout<<"\t 5. INPUT DATA PROJECT\n";
        cout<<"\t 6. UPDATE DATA PROJECT\n";
        cout<<"\t 7. DELETE DATA PROJECT\n";
        cout<<"\t 8. VIEW DATA PROJECT\n";
        cout<<"\t 9. KELUAR\n";
        choice=getch();
        switch (choice) {
            case '1':
                system("CLS");
                cout<<"\t\t =========INPUT DATA PROGRAMMER========="<<endl;
                cout<<" "<<endl;
                cout<<"Masukan username programmer : ";
                cin>>data.username;
                cout<<" "<<endl;
                cout<<"Masukan password programmer : ";
                cin>>data.password;
                cout<<" "<<endl;
                cout<<"Masukan usia programmer : ";
                cin>>data.usia;
                data.jum=0;
                cout<<" "<<endl;
                insertProgrammer(L1,allocate1(data));
                break;
            case '2':{
                system("CLS");
                cout<<"\t\t =========UPDATE DATA PROGRAMMER========="<<endl;
                string masukan;
                show1(L1);
                cout<<"\t Masukan username yang ingin di update : ";cin>>masukan;
                update1(L1,masukan);
                break;}
            case '3':{
                system("CLS");
                string masukan;
                cout<<"\t\t =========HAPUS DATA PROGRAMMER========="<<endl;
                cout<<" "<<endl;
                show1(L1);
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"\t\t Masukan username yang ingin dihapus : ";cin>>masukan;
                addresspointer1 P = search1(masukan,L1);
                if (P==NULL) cout<<"USERNAME NOT FOUND\n";
                else {
                    if (info(P).username==info(first(L1)).username) delFirst1(L1,P);
                    else if (info(P).username==info(last(L1)).username) delLast1(L1,P);
                    else delAfter1(prev(P),P);
                    deallocate1(P);
                    cout<<"\t Deleted Successfully!"<<endl;
                    cout<<" "<<endl;
                }
                system("pause");
                break;}
            case '4':
                system("CLS");
                cout<<"\t\t ========TAMPIL DATA PROGRAMMER========="<<endl;
                cout<<" "<<endl;
                show1(L1);
                system("pause");
                break;
             case '5':
                system("CLS");
                cout<<"\t\t =========INPUT DATA PROJECT========="<<endl;
                cout<<" "<<endl;
                cout<<"\t Masukan nama project : "; cin>>data2.nama_project;
                cout<<" "<<endl;
                cout<<"\t Masukan bahasa pemrograman : "; cin>>data2.bahasa;
                cout<<" "<<endl;
                cout<<"\t Masukan dateline :  "; cin>>data2.dateline;
                cout<<" "<<endl;
                insertProject(L2,allocate2(data2));
                system("pause");
                break;
             case '6':{
                system("CLS");
                string masukan;
                cout<<"\t\t =========INPUT DATA PROJECT========="<<endl;
                cout<<" "<<endl;
                cout<<"\t Masukan project yang ingin di update : ";cin>>masukan;
                update2(L2,masukan);
                system("pause");
                break;}
             case '7':{
                system("CLS");
                string masukan;
                cout<<"\t\t ========HAPUS DATA PROJECT========="<<endl;
                cout<<" "<<endl;
                show2(L2);
                cout<<"\t Masukan nama projek yang ingin dihapus : ";cin>>masukan;
                addresspointer2 P = search2(masukan,L2);
                if (P==NULL){
                    cout<<"PROJECT NOT FOUND\n";
                    cout<<" "<<endl;
                    system("pause");
                }
                else {
                    if (P==first(L2)) delFirst2(L2,P);
                    else if (P==last(L2)) delLast2(L2,P);
                    else delAfter2(prev(P),P);
                    deallocate2(P);
                }
                system("pause");
                break;}
             case '8':
                system("CLS");
                cout<<"\t\t ========TAMPIL DATA PROJECT========="<<endl;
                cout<<" "<<endl;
                show2(L2);
                system("pause");
                break;
            case '9':
                 out = true;
                 system("pause");
                break;
            default:
                cout << "Input Tidak Valid " <<endl;system("pause");
                break;
}
}
}

void submenu2 (DLL &L1, DLL2 &L2, CSL &L3){
    char choice;
    bool out=false;
    infotype data;
    infotype2 data2;
    while(!out) {
        system("CLS");
        cout<<"\t\t =========SELAMAT DATANG========="<<endl;
        cout<<"\t\t    =========MANAGER========="<<endl;
        cout<<" "<<endl;
        cout<<"1. BERI PROJECT KE PROGRAMMER\n";
        cout<<"2. HAPUS PROJECT DARI PROGRAMMER\n";
        cout<<"3. VIEW ASSIGNMENT PROGRAMMER\n";
        cout<<"4. VIEW ASSIGNMENT PROJECT\n";
        cout<<"5. VIEW TOP 5 ASSIGMENT TERBANYAK\n";
        cout<<"6. KELUAR\n";
        choice=getch();
        switch (choice) {
            case '1':{
                system("CLS");
                string masukanProgrammer;
                string masukanProject;
                string jawab;
                infoR assign1;
                show2(L2);
                cout<<"\t\t =========BERIKAN PROJECT========="<<endl;
                cout<<" "<<endl;
                bool out = false;
                while (!out){
                    cout<<"\t Masukan username programmer : ";
                    cin>>masukanProgrammer;
                    cout<<"\t Masukan nama project : ";
                    cin>>masukanProject;
                    addresspointer1 P = search1(masukanProgrammer,L1);
                    addresspointer2 Q = search2(masukanProject,L2);
                    if(P==NULL){
                        cout<<"NOT FOUND\n";
                    }
                    else{
                        if(Q==NULL) cout<<"NOT FOUND\n";
                        else if(P!=NULL&&Q!=NULL){
                            assign1.p1 = P;
                            assign1.p2 = Q;
                            bool cek=cekrelasi(L3,assign1);
                            if (!cek){
                                info(P).jum=info(P).jum + 1;
                                insLastR(L3,allocateR(assign1));
                                out=true;
                            }else{
                                cout<<"Sudah dikerjakan"<<endl;
                            }

                        }
                    }
//                    if (P==NULL){
//                            cout<<"\t Username not found\n";
//                            system("PAUSE");
//                            system("CLS");
//                    }
//
//                    else if (Q==NULL) cout<<"\t Project not found\n";
//                    else{
//                            assign1.p1 = P;
//                            assign1.p2 = Q;
//                            info(P).jum=info(P).jum + 1;
//                            insLastR(L3,allocateR(assign1));
//                            out=true;
//                        }
                    }
                break;}
            case '2':{
                system("CLS");
                string masukanProgrammer;
                string masukanProject;
                string jawab;
                infoR assign1;
                cout<<"\t\t =========HAPUS PROJECT========="<<endl;
                cout<<" "<<endl;
                    cout<<"\t Masukan username programmer : ";
                    cin>>masukanProgrammer;
                    cout<<"\t Masukan nama project : ";
                    cin>>masukanProject;
                    addresspointer1 P = search1(masukanProgrammer,L1);
                    addresspointer2 Q = search2(masukanProject,L2);
                    if(P==NULL){
                        cout<<"NOT FOUND\n";
                    }
                    else{
                        if(Q==NULL) cout<<"NOT FOUND\n";
                        else if(P!=NULL&&Q!=NULL){
                            assign1.p1 = P;
                            assign1.p2 = Q;
                            bool cek=cekrelasi(L3,assign1);
                            if (cek){
                                //HAPUS RELASI
                                addressrelasi B = searchR(assign1,L3);
                                addressrelasi temp;
                                if (B==NULL) cout<<"relasi tidak ditemukan"<<endl;
                                else {
                                    if (B==first(L3)) delFirstR(L3,temp);
                                    else {
                                        addressrelasi C=first(L3);
                                        while (next(C) != first(L3)&&((info(C).p1!=assign1.p1) || (info(C).p2 !=assign1.p2))) C=next(C);
                                        delAfterR(L3,C,temp);
                                    }
                                }
                            }
                            else cout<<"relasi tidak ditemukan bro"<<endl;
                            }
                    }
                system("pause");
                break;}
            case '3':{
                system("CLS");
                addresspointer1 P = first(L1);
                while(P!=NULL){
                    cout<<info(P).username<<endl;
                    addressrelasi Q = first(L3);
                    if(Q!=NULL){
                        while (next(Q)!=first(L3)){
                            if(info(Q).p1==P) cout<<"\t\t"<<info(info(Q).p2).nama_project<<endl;
                            Q=next(Q);
                        }
                        if(info(Q).p1==P) cout<<"\t\t"<<info(info(Q).p2).nama_project<<endl;
                    }
                    P=next(P);
                }
//                while (P!= NULL){
//                    cout<<info(P).username<<endl;
//                    Q = first(L3);
//                    while (next(Q)!= first(L3)){
//                        if (P == info(Q).p1){
//                            cout<<"\t\t"<<info(info(Q).p2).nama_project<<endl;
//                        }
//                        Q = next(Q);
//                    }
//                    if (P ==info(Q).p1){
//                        cout<<"\t\t"<<info(info(Q).p2).nama_project<<endl;
//                    }
//                    P = next(P);
//                }
                system("pause");
                break;}
            case '4':{
                system("CLS");
                addresspointer2 P = first(L2);
                while(P!=NULL){
                    cout<<info(P).nama_project<<endl;
                    addressrelasi Q = first(L3);
                    if (Q!=NULL){
                        while (next(Q)!=first(L3)){
                            if(info(Q).p2==P) cout<<"\t\t"<<info(info(Q).p1).username<<endl;
                            Q=next(Q);
                        }
                        if(info(Q).p2==P) cout<<"\t\t"<<info(info(Q).p1).username<<endl;
                    }
                    P=next(P);
                }
//                system("CLS");
//                addresspointer2 P = first(L2);
//                addressrelasi Q =first(L3);
//                while (P!=NULL){
//                    cout<<info(P).nama_project<<endl;
//                    Q=first(L3);
//                    while (next(Q)!=first(L3)){
//                        if (P = info(Q).p2){
//                            cout<<"\t"<<info(info(Q).p1).username<<endl;
//                        }
//                        Q = next(Q);
//                    }
//                    if (P = info(Q).p2){
//                        cout<<"\t"<<info(info(Q).p1).username<<endl;
//                    }
//                    P = next(P);
//                }
            system("pause");
            break;
            }
             case '5':{
                system("CLS");
                top5(L1);
                system("pause");
                break;
                }

            case '6':
                 out = true;
                 system("pause");
                break;
            default:
                cout << "Input Tidak Valid " <<endl;system("pause");
                break;
}
    }
}


void loginadmin(bool &out){
    string username;
    string password;
    cout<<"\t\t =========SELAMAT DATANG========="<<endl;
    cout<<"\t\t     =========ADMIN========="<<endl;
    cout<<" "<<endl;
    cout<<"\t Masukan username : ";
    cin>>username;
    cout<<" "<<endl;
    cout<<"\t Masukam password : ";
    cin>>password;
    if ((username==user1) && (password==pass1)) out=true;
    else out=false;

}



void loginmanajer (bool &out){
    string userManager;
    string passwordManager;
    cout<<"\t\t =========SELAMAT DATANG========="<<endl;
    cout<<"\t\t     =========MANAJER========="<<endl;
    cout<<" "<<endl;
    cout<<"\t masukan username : ";
    cin>>userManager;
    cout<<" "<<endl;
    cout<<"\t masukam password : ";
    cin>>passwordManager;
    if ((userManager==user2) && (passwordManager==pass2)) out=true;
    else out=false;

}

void loginProgrammer (DLL L1, CSL L3, bool &out){
    string user3;
    string password3;


    cout<<"\t\t =========SELAMAT DATANG========="<<endl;
    cout<<"\t\t   =========DI MENU========= "<<endl;
    cout<<"\t\t ==========PROGRAMMER============"<<endl;
    cout<<" "<<endl;
    cout<<"\t Masukan username anda : ";
    cin>>user3;
    addresspointer1 P = search1(user3,L1);
    cout<<" "<<endl;
    cout<<"\t Masukam password anda : ";
    cin>>password3;
    system("CLS");


    if (P==NULL){
        system("CLS");
        cout<<"\t Username tidak ditemukan!\n";
        out=true;
        system("pause");
        system("CLS");
    }
    else {
        if (info(P).password!=password3) cout<<"password salah!\n";
        else if (info(P).password==password3){
            system("CLS");
            cout<<"\t SELAMAT DATANG "<<info(P).username<<endl;
            cout<<"\t PROJECT YANG ANDA KERJAKAN "<<endl;

            addressrelasi Q=first(L3);
            if (Q==NULL){
                cout<<"\t\t TIDAK ADA "<<endl;
                cout<<""<<endl;
                system("pause");
            }
            else{
                while(next(Q)!=first(L3)){//berdasarkan pointer
                    if(info(Q).p1==P){
                        cout<<info(info(Q).p2).nama_project<<endl;
                    }
                    Q=next(Q);
                }
                if(info(Q).p1==P){
                    cout<<info(info(Q).p2).nama_project<<endl;
                    system("pause");
                    out=true;
                }
                else {
                    cout<<" TIDAK ADA ";
                    system("pause");
                }
            }

        }
    }


}
