#ifndef NOMENCLATOR_H
#define NOMENCLATOR_H
#include <string>
#include "medicament.h"
using namespace std;

class Nomenclator :public Medicament
{
     int nr_medicamente=0;
    Medicament med[50];
public:
    void citire_fisier_medicamente();
    void scriere_in_fisier();

    void meniu_gestiune_farmacie();

    void afisare_nomenclator();

    void cauta_produs_denumire(char* _nume);

    void cauta_produs_cod(int _cod);

    void adauga_produs();

    int get_nr();

    void sterge_produs(char* _nume);

    int obtine_cod_produs(char* _nume);

    char* obtine_denumire_produs(int _cod);

    void set_produs(char* _nume, int _pret);

    bool isEmptyNomenclator();

    bool isFullNomenclator();

};

#endif // NOMENCLATOR_H

