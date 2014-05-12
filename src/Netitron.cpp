#include "Netitron.h"

NetiTron::NetiTron(TableDeVerite tab){
    NetiTron(tab, RandHomme::randInt(100, 1000), RandHomme::randDouble(-100., 0.), RandHomme::randDouble(1., 100.));
}

NetiTron::NetiTron(TableDeVerite tab, unsigned int nbr, double min, double max){
    for(unsigned int i=0; i < nbr; i++){
        networkOfNetwork.push_back( PrimeNetwork(min, max) );
    }
    this->tab = tab;
}

NetiTron::~NetiTron(){
}

bool NetiTron::Fin(PrimeNetwork* prime){
    for(unsigned int i=0; i < networkOfNetwork.size(); i++){
        if( networkOfNetwork.at(i).evaluate( tab ) ){
            prime=new PrimeNetwork( networkOfNetwork.at( i ) );
            return true;
        }
    }
    return false;
}

void NetiTron::evolution(void){//a faire
	//Prendre un primenetwork au hasard, et modifier les valeurs des neurones a l'interieur, en prenant !neuronne par exemple
	unsigned int chosen_one = RandHomme::randInt(0, networkOfNetwork.size());
	PrimeNetwork* p = networkOfNetwork.at(chosen_one);
	p->IlEtaitUneFoisJeMinverse();
}

void Netitron::crossMeMaybe(unsigned int prems, unsigned int second){//a faire
	PrimeNetwork* p1 = networkOfNetwork.at(prems);
	PrimeNetwork* p2 = networkOfNetwork.at(second);
	accouplonsNous(p1,p2);
}

void Netitron::accouplonsNous(PrimeNetwork* p1, PrimeNetwork* p2){// a faire
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

bool NetiTron::infPrime(PrimeNetwork& p1, PrimeNetwork& p2){
    return p1.differencielPrime(tab) < p2.differencielPrime(tab);
}

int NetiTron::BestOfFive(PrimeNetwork& competitor1, PrimeNetwork& competitor2){ //1 si comp1 > comp2
    int fit1 = this->fitnessPrime(competitor1);
    int fit2 = this->fitnessPrime(competitor2);
    return (fit1 > fit2)? 1 : -1;
}

int NetiTron::fitnessPrime(PrimeNetwork& prime){
    return prime.differencielPrime(tab);
}

void NetiTron::selection(void){
    std::sort(networkOfNetwork.begin(), networkOfNetwork.end(), infPrime);
}
