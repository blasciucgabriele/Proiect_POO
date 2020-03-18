#include "client.h"
#include "persoana.h"
#include "nomenclator.h"
#include "stdio.h"
#include <cstring>
#include "stdlib.h"
#include <iostream>
using namespace std;
Client::Client()
{
    cod_card=0;
    nume=NULL;
    prenume=NULL;
    stare="NEABONAT";
}
Client::Client(char *_nume,char *_prenume,int _cod)
{
    set_nume(_nume);
    set_prenume(_prenume);
    set_cod(_cod);
    stare="ABONAT";
}
Client::Client(int nr)
{
    cin.ignore();
    cout << "Nume: ";
    char _nume[20];
    cin.getline(_nume,20);
    cout << "Prenume: ";
    char _prenume[20];
    cin.getline(_prenume,20);
    set_nume(_nume);
    set_prenume(_prenume);
    int code=rand();
    if(code==0)
    {
        stare="NEABONAT";
    }
    else
    {
        stare="ABONAT";
        cod_card=code;
    }
}
char* Client::afisare_client()
{
    char buf[50];
    sprintf(buf,"Nume: %s\nPrenume: %s\nCod Client: %d\nStare: %s\n",nume,prenume,cod_card,stare);
    return buf;
}
void Client::set_cod(int _cod)
{
    _cod=rand();
    cod_card=_cod;
}
void Client::set_nume(char *_nume)
{
    int m=strlen(_nume);
    nume=new char[m+1];
    strcpy(nume,_nume);
}
void Client::set_prenume(char *_prenume)
{
    int m=strlen(_prenume);
    prenume=new char[m+1];
    strcpy(prenume,_prenume);
}
char* Client::get_nume()
{
    return nume;
}
char* Client::get_prenume()
{
    return prenume;
}
int Client::get_cod_card()
{
    return cod_card;;
}
void Client::set_stare()
{
    if(cod_card!=0)
    {
        stare="ABONAT";
    }
    else
    {
        stare="NEABONAT";
    }
}
char* Client::get_stare()
{
    return stare;
}

Client::~Client()
{
    //dtor
}
