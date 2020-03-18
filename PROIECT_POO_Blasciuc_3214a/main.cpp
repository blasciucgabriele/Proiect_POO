#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include "medicament.h"
#include "farmacist.h"
#include "client.h"
#include "persoana.h"
#include "nomenclator.h"
using namespace std;

int main()
{
    Nomenclator nom;
    Farmacist fm;
    char opt;
    char us[20],pssw[20];
    while(true)
    {
        system("cls");
        char us[20],pssw[20],linie[100],z[5],usa[20],pas[20];
        int nr,i=0,ok=1;
        cout<<"Introduceti username: ";
        cin.getline(us,20);
        cout<<"Introduceti parola: ";
        cin.getline(pssw,20);
        ifstream f("user_parola.txt");
        if(f.fail())
            cout<<"Fisierul nu s-a putut deschide"<<endl;
        f.getline(linie,sizeof(linie));
        strcpy(z,linie);
        nr=atoi(z);
        while(i<nr)
        {
            f.getline(linie,sizeof(linie));
            strcpy(usa,strtok(linie,","));
            strcpy(pas,strtok(NULL,","));
            if(strcmp(usa,us)!=0&& strcmp(pas,pssw)!=0)
            {
                i++;
                ok=0;
                continue;
            }
            else
            {
                ok=1;
            }
            if(ok==1)
            {
                fm.meniu_gestiune_client(usa);
            }
        }
    }
    return 0;
}
