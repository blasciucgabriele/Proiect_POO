#ifndef CLIENT_H
#define CLIENT_H
#include "persoana.h"
#include "Nomenclator.h"
using namespace std;

class Client : public Persoana,public Nomenclator
{
    int cod_card;
    char *stare,*prenume,*nume;
public:
    Client();
    Client(char*,char*,int);
    Client(int nr);
    char* afisare_client();
    void set_cod(int);
    char* get_nume();
    char* get_prenume();
    void set_nume(char*);
    void set_prenume(char*);
    int get_cod_card();
    void set_stare();
    char* get_stare();
    virtual ~Client();
};

#endif // CLIENT_H
