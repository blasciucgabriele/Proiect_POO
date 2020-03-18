#include "persoana.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

Persoana::Persoana()
{
    nume=NULL;
    prenume=NULL;
    data=NULL;
}
Persoana::Persoana(int nr)
{
    cin.ignore();
    cout << "Nume: ";
    char _nume[20];
    cin.getline(_nume,20);
    cout << "Prenume: ";
    char _prenume[20];
    cin.getline(_prenume,20);
    cout << "Data nastere: ";
    char _data[20];
    cin.getline(_data,20);
    set_nume(_nume);
    set_prenume(_prenume);
    set_data(_data);

}
Persoana::Persoana(char *_nume,char *_prenume,char *_data)
{
    set_nume(_nume);
    set_prenume(_prenume);
    set_data(_data);
}
char* Persoana::afisare_persoana()
{
    char buf[50];
    sprintf(buf,"Nume: %s\nPrenume: %s\nData: %s\n",nume,prenume,data);
    return buf;
}
void Persoana::set_nume(char *_nume)
{
    int m=strlen(_nume);
    nume=new char[m+1];
    strcpy(nume,_nume);
}
void Persoana::set_prenume(char *_prenume)
{
    int m=strlen(_prenume);
    prenume=new char[m+1];
    strcpy(prenume,_prenume);
}
void Persoana::set_data(char *_data)
{
    int m=strlen(_data);
    data=new char[m+1];
    strcpy(data,_data);
}
char* Persoana::get_nume()
{
    return nume;
}
char* Persoana::get_prenume()
{
    return prenume;
}
char* Persoana::get_data()
{
    return data;
}
Persoana::~Persoana()
{

}
