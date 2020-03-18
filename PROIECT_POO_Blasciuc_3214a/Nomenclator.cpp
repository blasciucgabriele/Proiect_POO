#include "nomenclator.h"
#include "medicament.h"
#include <fstream>
#include "stdlib.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;
static int ID=0;
void Nomenclator::meniu_gestiune_farmacie()
{
    char opt;
                        do
                        {
                            system("cls");
                            cout << "\t\t\t\t\tGESTIUNE - FARMACIE\t\t" << endl;
                            cout << "1. Adaugare medicamente(tastatura)\n"
                                 "2. Adaugare medicament(fisier)\n"
                                 "3. Afisare medicamente\n"
                                 "4. Obtine info medicament(necesar cod produs)\n"
                                 "5. Obtine info medicament(necesar denumire produs)\n"
                                 "6. Eliminare medicament\n"
                                 "7. Salvare medicamente(fisier)\n"
                                 "8. Info Farmacie\n"
                                 "9. Exit"<<endl;
                            cout << "Introduceti o optiune: ";
                            cin >> opt;
                            switch (opt)
                            {
                            case '1':
                                adauga_produs();
                                cout<<"Press any key.."<<endl;
                                getch();
                                break;
                            case '2':
                                citire_fisier_medicamente();
                                cout<<"Press any key.."<<endl;
                                getch();
                                break;
                            case '3':
                                afisare_nomenclator();
                                cout<<"Press any key.."<<endl;
                                getch();
                                break;
                            case '4':
                                int cod;
                                cout << "Introduceti codul medicamentului: ";
                                cin>>cod;
                                cauta_produs_cod(cod);
                                cout<<"Press any key.."<<endl;
                                getch();
                                break;
                            case '5':
                                char _nume[20];
                                cout << "Introduceti numele medicamentului: ";
                                cin>>_nume;
                                cauta_produs_denumire(_nume);
                                getch();
                                break;
                            case '6':
                                cout << "Introduceti denumirea prodosului ce doriti sa eliminati: ";
                                char med[20];
                                cin >> med;
                                sterge_produs(med);
                                cout<<"Press any key.."<<endl;
                                getch();
                                break;
                            case '7':
                                scriere_in_fisier();
                                cout<<"Date salvate cu succes!"<<endl;
                                cout<<"Press any key.."<<endl;
                                getch();
                                break;
                            case '8':
                                cout << "Farmacia Stefan Cel Mare - Suceava(SV)" << endl;
                                cout<<"Press any key.."<<endl;
                                getch();
                                break;
                            default:
                                break;
                            }
                        }while(opt!='9');
}

void Nomenclator::citire_fisier_medicamente()//CITIRE CLIENTI + PROGRAM FUNCTIONAL COMPLET +
{
    char _denumire[20],_producator[20],_natura[20],codec[10],prete[10],stoche[10],z[5];
    char linie[100];
    int code,_stoc,i=0,nr;
    float _pret;
    ifstream f("Medic_in.txt");
    f.getline(linie,sizeof(linie));
    strcpy(z,linie);
    nr=atoi(z);
    while(i<nr)
    {
        if(!isFullNomenclator())
        {
            f.getline(linie,sizeof(linie));
            strcpy(_denumire, strtok(linie, ","));
            strcpy(_producator, strtok(NULL, ","));
            strcpy(_natura, strtok(NULL, ","));
            strcpy(codec, strtok(NULL, ","));
            code=atoi(codec);
            strcpy(prete, strtok(NULL, ","));
            _pret=atof(prete);
            strcpy(stoche, strtok(NULL, ","));
            _stoc=atoi(stoche);

            med[nr_medicamente]=Medicament(_denumire,_producator,_natura,code,_pret,_stoc);
            nr_medicamente++;
            i++;
        }
    }

    cout<<"Fisier citit cu succes!"<<endl;
    f.close();
}
void Nomenclator::scriere_in_fisier()
{
    ofstream f("Medic_out.txt",ios::app);
    if(f.fail()) cout<<"Eroare la deschiderea fisierului!"<<endl;
    for(int i=0;i<nr_medicamente;i++)
    {
        f<<setw(10)<<med[i].get_denumire()<<"\t\t"<<setw(10)<<med[i].get_producator()<<"\t\t"<<setw(10)<<med[i].get_natura()<<"\t\t"<<setw(10)<<med[i].get_cod()<<"\t"<<setw(10)<<med[i].get_pret()<<"\t"<<setw(10)<<med[i].get_stoc()<<endl;
    }
    f.close();
}

void Nomenclator::afisare_nomenclator()
{
    if(!isEmptyNomenclator())
    {    cout<<setw(10)<<"DENUMIRE"<<"\t\t"<<setw(10)<<"PRODUCATOR"<<"\t\t"<<setw(10)<<"FORMAT"<<"\t\t"<<setw(10)<<"COD"<<"\t"<<setw(10)<<"PRET"<<"\t"<<setw(10)<<"STOC"<<endl;
        for(int i=0; i<nr_medicamente; i++)
        {
            med[i].afisare_med();
        }
    }
    else
        cout<<"Nu exista produse"<<endl;
}

void Nomenclator::cauta_produs_denumire(char *_nume)
{
    for (int i = 0; i < nr_medicamente; i++)
    {
        if (strcmp(_nume, med[i].get_denumire()) == 0)
        {
            med[i].afisare_med();
        }
    }
}
void Nomenclator::cauta_produs_cod(int _cod)
{
    for (int i = 0; i < nr_medicamente; i++)
    {
        if (_cod == med[i].get_cod())
        {
            med[i].afisare_med();
        }
    }
}
void Nomenclator::adauga_produs()
{
    int nr = 0;
    if (!isFullNomenclator())
    {
        med[nr_medicamente] = Medicament(nr);
        nr_medicamente++;
        cout<<"Produs adaugat cu succes!"<<endl;
    }
    else
        cout<<"Baza de date este plina!"<<endl;
}

void Nomenclator::sterge_produs(char *_nume)
{
    int k = -1, i;
    if (!isEmptyNomenclator())
    {
        for (i = 0; i < nr_medicamente; i++)
        {
            if (strcmp(_nume, med[i].get_denumire()) == 0)
            {
                k = i;
            }
            if (k != -1)
            {
                for (i = k; i < nr_medicamente; i++)
                {
                    med[i] = med[i + 1];
                }
                nr_medicamente--;
            }
        }
        cout<<"Produs eliminat!"<<endl;
    }
    else
        cout<<"Nu exista produse!"<<endl;
}
int Nomenclator::obtine_cod_produs(char *_nume)
{
    for (int i = 0; i < nr_medicamente; i++)
    {
        if (strcmp(_nume, med[i].get_denumire()) == 0)
        {
            return med[i].get_cod();
        }
    }
    return -1;
}
char* Nomenclator::obtine_denumire_produs(int _cod)
{
    for (int i = 0; i < nr_medicamente; i++)
    {
        if (_cod == med[i].get_cod())
        {
            return med[i].get_denumire();
        }
    }
    char error[]="Produsul nu exista!";
    return error;
}

void Nomenclator::set_produs(char *_nume,int _pret)
{
    for (int i = 0; i < nr_medicamente; i++)
    {
        if (strcmp(_nume, med[i].get_denumire()) == 0)
        {
            med[i].set_pret(_pret);
        }
    }
}
bool Nomenclator::isEmptyNomenclator()
{
    return nr_medicamente==0?true:false;
}

bool Nomenclator::isFullNomenclator()
{
    return nr_medicamente==50?true:false;
}





