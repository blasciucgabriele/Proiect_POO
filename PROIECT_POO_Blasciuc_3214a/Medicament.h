#ifndef MEDICAMENT_H
#define MEDICAMENT_H

class Medicament
{
private:
    char* denumire, * producator, * natura;
    int cod, stoc;
    float pret;
public:
    Medicament();
    Medicament(int);
    Medicament(char*, char*, char*, int, float, int);
    void afisare_med();
    void set_denumire(char*);
    void set_producator(char*);
    void set_cod(int);
    void set_pret(float);
    void set_natura(char*);
    void set_stoc(int);
    int get_cod();
    int get_stoc();
    float get_pret();
    char* get_denumire();
    char* get_natura();
    char* get_producator();
    ~Medicament();
};

#endif // MEDICAMENT_H

