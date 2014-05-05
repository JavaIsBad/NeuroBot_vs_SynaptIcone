#include "PrimeNetwork.h"

PrimeNetwork::PrimeNetwork(double min, double max){
    std::list<double> l;
    for(unsigned int i=0; i < NBINTO; i++){
        l.push_back( RandHomme::randDouble(min, max) );
        l.push_back( RandHomme::randDouble(min, max) );
        inBot.push_back(NeuroBot::NeuroBot( l ));
        l.clear();
    }
    for(unsigned int i=0; i < NBINTO; i++)
        l.push_back( RandHomme::randDouble(min, max) );
    outBot.ChangeMyList( l );
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
bool PrimeNetwork::evaluate(TableDeVerite tab){
    std::list<bool> l;
    l.push_back(true);
    l.push_back(true);
    if(CalculusPrime( l ) != tab.vv)
        return false;
    l.clear();
    l.push_back(true);
    l.push_back(false);
    if(CalculusPrime( l ) != tab.vf)
        return false;
    l.clear();
    l.push_back(false);
    l.push_back(true);
    if(CalculusPrime( l ) != tab.fv)
        return false;
    l.clear();
    l.push_back(false);
    l.push_back(false);
    if(CalculusPrime( l ) != tab.ff)
        return false;
    return true;
}
