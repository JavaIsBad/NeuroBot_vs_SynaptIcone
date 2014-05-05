#include "PrimeNetwork.h"

PrimeNetwork::PrimeNetwork(double min, double max){
    std::list<double> l;
    for(unsigned int i=0; i < NBINTO; i++){
        l.push_back( RandHomme::randDouble(min, max) );
        l.push_back( RandHomme::randDouble(min, max) );
        inBot.push_back(NeuroBot::NeuroBot( l ));
        l.clear();
    }
    l.push_back( RandHomme::randDouble(min, max) );
    l.push_back( RandHomme::randDouble(min, max) );
    l.push_back( RandHomme::randDouble(min, max) );
    outBot.ChangeMyList(l);
}

PrimeNetwork::PrimeNetwork(PrimeNetwork& prime){
    inBot = prime.inBot;
    outBot = prime.outBot;
}

PrimeNetwork::~PrimeNetwork(){
}

bool PrimeNetwork::CalculusPrime(std::list<bool> boulien){
    if( boulien.size() != 2 )
        return false;
    std::list<bool> l;
    for(unsigned int i = 0; i < NBINTO; i++){
        l.push_back( inBot.at( i ).bumblebIn( boulien ) );
    }
    return outBot.bumblebIn( l );
}