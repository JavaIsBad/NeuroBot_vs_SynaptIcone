/*
   Copyright (C) 2014  Raphaël Schimchowitsch, Maxime Schmitt

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */

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
