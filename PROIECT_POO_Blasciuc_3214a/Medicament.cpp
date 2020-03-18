#include "medicament.h"
#include "stdio.h"
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;


Medicament::Medicament()
{
    denumire = NULL;
    producator = NULL;
    natura = NULL;
    cod = 0;
    pret = 0;
    stoc = 0;
}
Medicament::Medicament(char* _denumire, char* _producator, char* _natura, int _cod, float _pret, int _stoc)
{
    int m = strlen(_denumire);
    denumire = new char[m + 1];
    strcpy(denumire, _denumire);
    int n = strlen(_producator);
    producator = new char[n + 1];
    strcpy(producator, _producator);
    int k = strlen(_natura);
    natura = new char[k + 1];
    strcpy(natura, _natura);
    cod = _cod;
    pret = _pret;
    stoc = _stoc;
}
Medicament::Medicament(int nr)
{
    cin.ignore();
    cout << "Denumire: ";
    char _denumire[20];
    cin.getline(_denumire,20);
    cout << "Producator: ";
    char _producator[20];
    cin.getline(_producator,20);
    cout << "Format: ";
    char _format[20];
    cin.getline(_format,20);
    cout << "Cod: ";
    int _cod;
    cin >> _cod;
    cout << "Pret: ";
    float _pret;
    cin >> _pret;
    cout << "Stoc: ";
    int _stoc;
    cin >> _stoc;
    set_denumire(_denumire);
    set_producator(_producator);
    set_natura(_format);
    set_cod(_cod);
    set_pret(_pret);
    set_stoc(_stoc);
}

void Medicament::afisare_med()
{
     cout<<setw(10)<<get_denumire()<<"\t\t"<<setw(10)<<get_producator()<<"\t\t"<<setw(10)<<get_natura()<<"\t\t"<<setw(10)<<get_cod()<<"\t"<<setw(10)<<get_pret()<<"\t"<<setw(10)<<get_stoc()<<endl;
}
void Medicament::set_denumire(char* _denumire)
{
    int m=strlen(_denumire);
    denumire=new char[m+1];
    strcpy(denumire,_denumire);
}
void Medicament::set_producator(char* _producator)
{
    int m=strlen(_producator);
    producator=new char[m+1];
    strcpy(producator,_producator);
}
void Medicament::set_natura(char* _natura)
{
    int m=strlen(_natura);
    natura=new char[m+1];
    strcpy(natura,_natura);
}
void Medicament::set_cod(int _cod)
{
    cod = _cod;
}
void Medicament::set_pret(float _pret)
{
    pret = _pret;
}
void Medicament::set_stoc(int _stoc)
{
    stoc = _stoc;
}
char* Medicament::get_denumire()
{
    return denumire;
}
char* Medicament::get_producator()
{
    return producator;
}
char* Medicament::get_natura()
{
    return natura;
}
int Medicament::get_cod()
{
    return cod;
}
float Medicament::get_pret()
{
    return pret;
}
int Medicament::get_stoc()
{
    return stoc;
}
Medicament::~Medicament()
{

}
