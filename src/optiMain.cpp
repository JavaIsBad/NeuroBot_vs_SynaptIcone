#include "Netitron.h"
#include <iostream>

int main (int argc, char **argv){
    RandHomme::nouvelleGraine();
    unsigned long int Rien = 0;
    TableDeVerite tab;
    tab.vv=0;
    tab.vf=1;
    tab.fv=1;
    tab.ff=0;
    NetiTron neti(tab, 100, -5, 5);
    PrimeNetwork* pfin = NULL;
    while(!neti.Fin(pfin)){
        ++Rien;
        neti.evolution();
        std::cerr << "Max " << neti.bestOfFitness << std::endl;
        std::cerr << "Moyenne " << neti.moyenneFitness << std::endl << std::endl;
    }
    std::cout << Rien << std::endl;
    std::cout << "Crossover " << neti.nbcrossover << std::endl;
    std::cout << "Mutation " << neti.nbmutation << std::endl;
    std::cout << "Clonage " << neti.nbclonage << std::endl;
    return 0;
}
