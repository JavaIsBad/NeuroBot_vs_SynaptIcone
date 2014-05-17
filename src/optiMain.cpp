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
    // Table de vérité, nombre d'individus, minIndividu, maxIndividu
    NetiTron neti(tab, 100, 0, 1);
    PrimeNetwork pfin(0, 2); // sert a récuperer les bons neurones
    while( !neti.Fin(&pfin) ){ // Tant qu'aucun individu ne conviens évoluer
        ++Rien;
        neti.evolution();
        std::cerr << "Min " << neti.bestOfFitness << std::endl;
        std::cerr << "Moyenne " << neti.moyenneFitness << std::endl << std::endl;
    }
    std::cout << pfin;
    std::cout << "Le nombre de pas d'évolution a été de " << Rien << std::endl;
    std::cout << "Crossover " << neti.nbcrossover << std::endl;
    std::cout << "Mutation " << neti.nbmutation << std::endl;
    std::cout << "Clonage " << neti.nbclonage << std::endl;
    return 0;
}
