#include "Netitron.h"
#include <iostream>

int main (int argc, char **argv){
    RandHomme::nouvelleGraine();
    unsigned long int Rien = 0;
    TableDeVerite tab;
    tab.vv = false;
    tab.vf = true;
    tab.fv = true;
    tab.ff = false;
    NetiTron neti(tab, 100, 0, 1);
    PrimeNetwork pfin(0, 2);
    while(!neti.Fin(&pfin)){
        ++Rien;
        neti.evolution();
        //std::cerr << "Min " << neti.bestOfFitness << std::endl;
        //std::cerr << "Moyenne " << neti.moyenneFitness << std::endl << std::endl;
    }
    std::cout << pfin;
    std::cout << "Le nombre de pas d'évolution a été de " << Rien << std::endl;
    std::cout << "Crossover " << neti.nbcrossover << std::endl;
    std::cout << "Mutation " << neti.nbmutation << std::endl;
    std::cout << "Clonage " << neti.nbclonage << std::endl;
    return 0;
}
