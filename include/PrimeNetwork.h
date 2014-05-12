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
        ~PrimeNetwork(void);
        bool CalculusPrime(std::list<bool> boulien);
        bool evaluate(const TableDeVerite& tab);
        std::ostream& printMe(std::ostream& os);
        NeuroBot& giveMeBrain(unsigned int position);
        int differencielPrime(const TableDeVerite& tab);
		void IlEtaitUneFoisJeMinverse();//

    private:
        std::vector<NeuroBot> inBot;
        NeuroBot outBot;
};

std::ostream& operator<< (std::ostream& os, PrimeNetwork& prime);

#endif // (__PRIMENETWORK_H)
