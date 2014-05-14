#ifndef __PRIMENETWORK_H
#define __PRIMENETWORK_H

#include <vector>
#include "neuroBot.h"
#include "RandHomme.h"
#include <iostream>

#define NBINTO 3

struct TableDeVerite{
    bool ff;
    bool vf;
    bool fv;
    bool vv;
};

class PrimeNetwork{
    public:
        PrimeNetwork(double min, double max);
        PrimeNetwork(const PrimeNetwork& prime);
        PrimeNetwork(PrimeNetwork& p1, PrimeNetwork& p2);
        ~PrimeNetwork(void);
        bool evaluate(const TableDeVerite& tab);
        std::ostream& printMe(std::ostream& os);
        NeuroBot& giveMeBrain(unsigned int position);
        double differencielPrime(const TableDeVerite& tab);
        void IlEtaitUneFoisJeMinverse();//

    private:
        bool CalculusPrime(std::list<bool> boulien);
        double CalculusPrimeDouble(std::list<bool> boulien);
        std::vector<NeuroBot> inBot;
        NeuroBot outBot;
};

std::ostream& operator<< (std::ostream& os, PrimeNetwork& prime);

#endif // (__PRIMENETWORK_H)
