#ifndef __NEUROBOT_H
#define __NEUROBOT_H

#include <list>

class NeuroBot{
    public:
        NeuroBot();
        NeuroBot(std::list<double> poids);
        virtual ~NeuroBot();
        bool bumblebIn(std::list<bool> in);
        int ChangeMyList(std::list<double> list);
    private:
        std::list<double> poids;
};

#endif // (__NEUROBOT_H)
