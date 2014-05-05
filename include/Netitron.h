#ifndef __NETITRON_H
#define __NETITRON_H

#include "PrimeNetwork.h"
#include <vector>

class NetiTron{
    public:
        NetiTron();
        NetiTron(unsigned int nbr, double min, double max);
        ~NetiTron();
        bool Fin(const TableDeVerite tab, PrimeNetwork* prime);
        void evolution(void);
    private:
        std::vector<PrimeNetwork> networkOfNetwork;
};

#endif // (__NETITRON_H)
