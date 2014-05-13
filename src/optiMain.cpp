#include "Netitron.h"
#include <iostream>

int main (int argc, char **argv){
    //RandHomme::nouvelleGraine();
    unsigned long int Rien = 0;
    TableDeVerite tab;
    tab.vv=0;
    tab.vf=1;
    tab.fv=1;
    tab.ff=0;
    NetiTron neti(tab, 100, -100, 100);
    PrimeNetwork* pfin = NULL;
    while(neti.Fin(pfin)){
        ++Rien;
        neti.evolution();
    }
    std::cout << pfin << Rien << std::endl;
    return 0;
}
