#ifndef FARMACIST_H
#define FARMACIST_H
#include "persoana.h"
#include "client.h"
#include "Medicament.h"
#include "Nomenclator.h"
using namespace std;

class Farmacist : public Persoana,public Medicament,public Nomenclator
{
    char *username,*parola;
    int nr_clienti=0;
    Nomenclator nom;
    Client clt[50];
public:
    Farmacist();
    Farmacist(char*,char*);
    char* get_user();
    void set_user(char*);
    void set_pass(char*);
    char* get_pass();
    void cumparaturi();
    void meniu_gestiune_client(char*);
    void adauga_client();
    void cumparaturi_da();
    void cumparaturi_nu();
    void cumparaturi_doresc();
    bool isFullClienti();
    bool isEmptyClienti();
    virtual ~Farmacist();
};

#endif // FARMACIST_H
