#ifndef __PRIMENETWORK_H
#define __PRIMENETWORK_H

#include <vector>
#include "neuroBot.h"
#include "RandHomme.h"

#define NBINTO 3

class PrimeNetwork{
    public:
        PrimeNetwork(double min, double max);
        PrimeNetwork(PrimeNetwork& prime);
        ~PrimeNetwork(void);
        bool CalculusPrime(std::list<bool> boulien);
    private:
        std::vector<NeuroBot> inBot;
        NeuroBot outBot;
};

#endif // (__PRIMENETWORK_H)
