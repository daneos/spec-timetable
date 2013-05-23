#ifndef genotypeH
#define genotypeH
#include "gene.h"
#include "data.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocen�, kar�, ilosc gen�w(grup) oraz tablic� wska�nik�w na wszystkie geny.
*/
class Genotype
{
public:
    Genotype(const Data &data);
    ~Genotype();
    void Evaluation(); //Funkcja oceniaj�ca
    bool Mark(double &mark);
    double termsCollision();//kolizja terminosal
protected:
    Gene **genes; //Tablica wszystkich przedmiot�w(po kolei wed�ug grup[klas])
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    double mark;
    bool penalty;
};
#endif
