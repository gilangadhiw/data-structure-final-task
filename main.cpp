#include <iostream>
#include "parent1.h"
#include "parent2.h"
#include "relasi.h"
#include <stdio.h>
#include <cstdlib>
#include <conio.h>


using namespace std;
int main()
{
    DLL L1; //manggil dan bikin
    DLL2 L2;
    CSL LR;
    createL1(L1);
    createL2(L2);
    createLR(LR);

    char choice;
    bool Quit=false;
    while(!Quit) {
        system ("color 0B");
        system("CLS");
        cout<<"\t\t ================SELAMAT DATANG================"<<endl;
        cout<<" "<<endl;
        cout<<"\t 1. LOGIN ADMIN\n";
        cout<<"\t 2. LOGIN MANAGER\n";
        cout<<"\t 3. LOGIN PROGRAMMER\n";
        cout<<"\t 4. KELUAR\n";

        choice=getch();
        switch (choice) {
            case '1':{
                system("CLS");
                bool out=false;
                while(!out){
                    loginadmin(out);
                    system("CLS");
                }
                submenu1(L1,L2,LR);
                break;}
            case '2':{
                system("CLS");
                bool out=false;
                while(out==false){
                    loginmanajer(out);
                    system("CLS");
                }
                submenu2(L1,L2,LR);
                break;}
            case '3':{
                system("CLS");
                bool out=false;
                while(out==false){
                    loginProgrammer(L1,LR,out);
                    out=true;
                }
                break;}
            case '4': //Quit
                Quit = true;
                break;
            default:
                cout << "Input Tidak Valid " <<endl;system("pause");
                break;
        }
    }




}
