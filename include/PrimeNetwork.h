#ifndef __PRIMENETWORK_H
#define __PRIMENETWORK_H

#include <vector>
#include "neuroBot.h"
#include "RandHomme.h"

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
        bool evaluate(TableDeVerite tab);
    private:
        std::vector<NeuroBot> inBot;
        NeuroBot outBot;
};

#endif // (__PRIMENETWORK_H)
