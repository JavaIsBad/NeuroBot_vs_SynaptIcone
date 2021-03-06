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

NetiTron::NetiTron(TableDeVerite tabv, unsigned int nbr, double min, double max){
    for(unsigned int i=0; i < nbr; i++){
        networkOfNetwork.push_back( PrimeNetwork(min, max) );
    }
    tab = tabv;
    nbclonage = 0;
    nbmutation = 0;
    nbcrossover = 0;
}

NetiTron::~NetiTron(){
}

bool NetiTron::Fin(PrimeNetwork* prime){
    for(std::vector<PrimeNetwork>::iterator it = networkOfNetwork.begin(); it != networkOfNetwork.end(); ++it){
        if( (*it).evaluate( tab ) ){
            *prime = *it;
            return true;
        }
    }
    return false;
}

void NetiTron::evolution(void){
    int rand = RandHomme::randInt(0,100);
    if(rand < 80)
        crossover();
    else
        if(rand > 95)
            clonnage();
        else
            mutation();
    selection();
    calculDeMoyenneMax();
}

void NetiTron::calculDeMoyenneMax(){
    moyenneFitness=0;
    unsigned int nbr=0;
    bestOfFitness = std::numeric_limits<double>::max();
    std::vector<PrimeNetwork>::iterator it = networkOfNetwork.begin();
    for(; it != networkOfNetwork.end(); ++it){
        double fitness = this->fitnessPrime(*it);
        if(fitness < bestOfFitness)
            bestOfFitness=fitness;
        moyenneFitness+=fitness;
        nbr++;
    }
    moyenneFitness/=nbr;
}

void NetiTron::crossMeMaybe(unsigned int prems, unsigned int second){//a faire
    PrimeNetwork p1 = networkOfNetwork.at(prems);
    PrimeNetwork p2 = networkOfNetwork.at(second);
    this->accouplonsNous(p1,p2);
}

void NetiTron::accouplonsNous(PrimeNetwork& p1, PrimeNetwork& p2){// a faire
    PrimeNetwork p3(p1, p2);
    networkOfNetwork.push_back(p3);
}

void NetiTron::crossover(void){
    unsigned int chosen_one = RandHomme::randInt(0, networkOfNetwork.size());
    unsigned int chosen_two;
    unsigned int chosen_three;
    do{
        chosen_two = RandHomme::randInt(0, networkOfNetwork.size());
        chosen_three = RandHomme::randInt(0, networkOfNetwork.size());
    }while(chosen_two == chosen_one || chosen_one == chosen_three || chosen_two == chosen_three);
    int choice = foo_fighter(chosen_one, chosen_two, chosen_three);
    switch(choice){
        case 3: // one and two won
            crossMeMaybe(chosen_one, chosen_two);
            break;
        case 5: // one and three won
            crossMeMaybe(chosen_one, chosen_three);
            break;
        case 6: // two and three won
            crossMeMaybe(chosen_three, chosen_two);
            break;
    }
    nbcrossover++;
}

int NetiTron::foo_fighter(unsigned int one, unsigned int two, unsigned int three){
    int fight = BestOfFive(networkOfNetwork.at(one), networkOfNetwork.at(two));
    if(fight == 1){
        fight = BestOfFive(networkOfNetwork.at(two), networkOfNetwork.at(three));
        if(fight==1)
            return 3; // one and two win
        else
            return 5; // one and three win
    }
    fight = BestOfFive(networkOfNetwork.at(one), networkOfNetwork.at(three));
    if(fight == 1)
        return 3; // one and two win
    else
        return 6; // two and three win
}

int NetiTron::BestOfFive(PrimeNetwork& competitor1, PrimeNetwork& competitor2){ //1 si comp1 > comp2
    double fit1 = this->fitnessPrime(competitor1);
    double fit2 = this->fitnessPrime(competitor2);
    return (fit1 > fit2) ? 1 : -1;
}

double NetiTron::fitnessPrime(PrimeNetwork& prime){
    return prime.differencielPrime(tab);
}

void NetiTron::selection(void){ // Jete au hasard
    while (networkOfNetwork.size()>100){
        int rand = RandHomme::randInt(0, networkOfNetwork.size());
        networkOfNetwork.erase(networkOfNetwork.begin()+rand);
    }
}

void NetiTron::mutation(void){
    //Prendre un primenetwork au hasard, et modifier les valeurs des neurones a l'interieur, en prenant !neuronne par exemple
    unsigned int chosen_one = RandHomme::randInt(0, networkOfNetwork.size());
    networkOfNetwork.at(chosen_one).IlEtaitUneFoisJeMinverse();
    nbmutation++;
}

void NetiTron::clonnage(void){
    int rand=RandHomme::randInt(0,networkOfNetwork.size());
    PrimeNetwork p2(networkOfNetwork.at(rand));
    networkOfNetwork.push_back(p2);
    nbclonage++;
}

