#ifndef __RANDHOMME_H
#define __RANDHOMME_H

#include <cstdlib>
#include <ctime>

class RandHomme{
    public:
        static int randInt(int minimum, int maximum);
        static double randDouble(double minimum, double maximum);
        static void nouvelleGraine(void);
        static void nouvelleGraine(unsigned int graine);
};

#endif // (__RANDHOMME_H)
