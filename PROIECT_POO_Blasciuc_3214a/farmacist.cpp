#include "farmacist.h"
#include "client.h"
#include "persoana.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "Medicament.h"
#include "Nomenclator.h"
using namespace std;
Farmacist::Farmacist()
{
    username="blasciuc.gabriele";
    parola="FarmaciaUSV";
}
char* Farmacist::get_user()
{
    return username;
}
char* Farmacist::get_pass()
{
    return parola;
}
bool Farmacist::isFullClienti()
{
    return nr_clienti==50?true:false;
}
bool Farmacist::isEmptyClienti()
{
    return nr_clienti==0?true:false;
}
void Farmacist::adauga_client()
{
    int nr=0;
    if(!isFullClienti())
    {
        clt[nr_clienti]=Client(nr);
        nr_clienti++;
    }
}
void Farmacist::meniu_gestiune_client(char *us)
{
    char opt;
    do
    {
        system("cls");
        cout<<"Bine ai venit! || Welcome! - "<<us<<endl;
        cout << "1. Gestiune Farmacie\n"
             "2. Client\n"
             "3. Info farmacie\n"
             "4. Iesire" << endl;
        cout<<"Introduceti o optiune: ";
        cin>>opt;
        switch(opt)
        {
        case '1':
            nom.meniu_gestiune_farmacie();
            break;
        case '2':
            cumparaturi();
            cout<<"La revedere!"<<endl;
            cout<<"Press any key.."<<endl;
            getch();
            break;
        case '3':
            cout<<"Farmacia Stefan Cel Mare Suceava-(SV)"<<endl;
            cout<<"Press any key.."<<endl;
            getch();
            break;
        case '4':
            cout<<"LA REVEDERE!"<<endl;
            exit(0);
        }
    }
    while(true);
}
void Farmacist::cumparaturi()
{
    char ss,opt[3],_nume[20],_prenume[20];
    char opte[3];
    int code;
    Nomenclator nom;
    do
    {
        system("cls");
        cout<<"Bunaziua!Aveti cardul nostru?\n"
            "1. DA\n"
            "2. NU\n"
            "3. Doresc sa-l fac?\n"
            "4. Exit"<<endl;
        cout<<"Introduceti optiunea: ";
        cin>>ss;
        switch(ss)
        {
        case '1':
            cumparaturi_da();
            getch();
            break;
        case '2':
            cumparaturi_nu();
            getch();
            break;
        case '3':
            cumparaturi_doresc();
            getch();
            break;
        default:
            break;
        }

    }
    while(ss!='4');
}
void Farmacist::cumparaturi_nu()
{
    char med[20];
    cout<<"Introduceti denumirea: ";
    cin>>med;
    nom.cauta_produs_denumire(med);
}
void Farmacist::cumparaturi_da()
{
    char opt[5],_nume[20],_prenume[20];
    int code,nr;
    ifstream f;
    f.open("clienti_abonati.txt");
    if(f.fail())
    {
        cout<<"Eroare la deschiderea fisierului!"<<endl;
    }
    for(int i=0; i<nr; i++)
    {
        f>>code;
        f.getline(_nume,',');
        f.getline(_prenume,',');
        clt[nr_clienti]=Client(_nume,_prenume,code);
        nr_clienti++;
    }
    f.close();
    while(true)
    {
        cout<<"Introduceti codul cardului: ";
        cin>>code;
        for(int i=0; i<nr_clienti; i++)
        {
            if(code!=clt[i].get_cod())
            {
                cout<<"Codul este gresit sau nu rezulta ca aveti card la farmacia noastra!"<<endl;
                continue;
            }
            else
            {
                cout<<"Doriti sa achizionati un produs?";
                cin.getline(opt,10);
                while(opt=="da" || opt=="DA")
                {
                    nom.adauga_produs();
                    ofstream f;
                    f.open("bon.txt");
                    if(f.fail())
                        cout<<"Eroare la deschiderea fisierului!"<<endl;
                    char nume[20],prenume[20];
                    strcpy(nume,clt[i].get_nume());
                    strcpy(prenume,clt[i].get_prenume());
                    f<<nume<<" "<<prenume<<endl;
                    f.close();
                }
            }
        }
    }
}
void Farmacist::cumparaturi_doresc()
{
    char opte[3];
    adauga_client();
    cout<<"Doriti sa achizionati un produs?";
    cin>>opte;
    int i=nr_clienti;
    if(opte=="DA" || opte=="da")
    {
        nom.adauga_produs();
        ofstream f;
        f.open("bon.txt",ios::in);
        if(f.fail())
            cout<<"Eroare la deschiderea fisierului!"<<endl;
        char nume[20],prenume[20];
        strcpy(nume,clt[i].get_nume());
        strcpy(prenume,clt[i].get_prenume());
        f<<nume<<" "<<prenume<<endl;
        f.close();
    }
}
void Farmacist::set_user(char *us)
{
    int m=strlen(us);
    username=new char[m+1];
    strcpy(username,us);
}
void Farmacist::set_pass(char *ps)
{
    int m=strlen(ps);
    parola=new char[m+1];
    strcpy(parola,ps);
}
Farmacist::~Farmacist()
{
    //dtor
}
