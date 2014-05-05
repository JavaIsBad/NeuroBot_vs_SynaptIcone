#ifndef __NEUROBOT_H
#define __NEUROBOT_H

#include <list>

class NeuroBot{
    public:
        NeuroBot(std::list<double> poids);
        virtual ~NeuroBot();
        bool bumblebIn(std::list<bool> in);
    private:
        std::list<double> poids;
};

#endif // (__NEUROBOT_H)
