#ifndef __NEUROBOT_H
#define __NEUROBOT_H

#include <list>
#include <iostream>
#include "RandHomme.h"

class NeuroBot{
    public:
        NeuroBot();
        NeuroBot(std::list<double> poids);
        virtual ~NeuroBot();
        bool bumblebIn(std::list<bool> in);
        int ChangeMyList(std::list<double> list);
        std::ostream& printMe(std::ostream& os);
        void jeMeChange(); //
        double recup(int pos);
    private:
        std::list<double> poids;
};

std::ostream& operator<< (std::ostream& os, NeuroBot& bot);
#endif // (__NEUROBOT_H)
