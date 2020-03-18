#ifndef PERSOANA_H
#define PERSOANA_H

using namespace std;
class Persoana
{
    char *nume,*prenume,*data;
    public:
        Persoana();
        Persoana(int nr);
        Persoana(char*,char*,char*);
        char* afisare_persoana();
        void set_nume(char*);
        void set_prenume(char*);
        void set_data(char*);
        char* get_nume();
        char* get_prenume();
        char* get_data();
        virtual ~Persoana();
};

#endif // PERSOANA_H
