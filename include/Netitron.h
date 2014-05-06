#ifndef __NETITRON_H
#define __NETITRON_H

#include "PrimeNetwork.h"
#include "RandHomme.h"
#include <vector>
#include <iostream>

class NetiTron{
    public:
        NetiTron(TableDeVerite tab);
        NetiTron(TableDeVerite tab, unsigned int nbr, double min, double max);
        ~NetiTron();
        bool Fin(PrimeNetwork* prime);
        void evolution(void);
    private:
        TableDeVerite tab;
        void crossover(void);
        void mutation(void);
        void clonnage(void);
        int foo_fighter(unsigned int one, unsigned int two, unsigned int three);
        static int BestOfFive(PrimeNetwork& competitor1, PrimeNetwork& competitor2);
        void crossMeMaybe(unsigned int prems, unsigned int second);
        int fitnessPrime(PrimeNetwork& prime);
        std::vector<PrimeNetwork> networkOfNetwork;
};

#endif // (__NETITRON_H)
