#include "PrimeNetwork.h"

PrimeNetwork::PrimeNetwork(double min, double max){
    std::list<double> l;
    for(unsigned int i=0; i < NBINTO; i++){
        l.push_back( RandHomme::randDouble(min, max) );
        l.push_back( RandHomme::randDouble(min, max) );
        NeuroBot nb( l );
        inBot.push_back(nb);
        l.clear();
    }
    for(unsigned int i=0; i < NBINTO; i++)
        l.push_back( RandHomme::randDouble(min, max) );
    outBot.ChangeMyList( l );
}

PrimeNetwork::PrimeNetwork(const PrimeNetwork& prime){
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

bool PrimeNetwork::evaluate(const TableDeVerite& tab){
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

std::ostream& PrimeNetwork::printMe(std::ostream& os){
    os << "PrimeNetwork" << std::endl;
    for(unsigned int i=0; i < inBot.size(); i++){
        os << inBot.at(i) << std::endl;
    }
    return os;
}

std::ostream& operator<< (std::ostream& os, PrimeNetwork& prime){
    return prime.printMe(os);
}

NeuroBot& PrimeNetwork::giveMeBrain(unsigned int position){
    return inBot.at(position);
}

int PrimeNetwork::differencielPrime(const TableDeVerite& tab){
    int shala = 0;
    std::list<bool> l;
    l.push_back(true);
    l.push_back(true);
    if(CalculusPrime( l ) != tab.vv)
        shala++;
    l.clear();
    l.push_back(true);
    l.push_back(false);
    if(CalculusPrime( l ) != tab.vf)
        shala++;
    l.clear();
    l.push_back(false);
    l.push_back(true);
    if(CalculusPrime( l ) != tab.fv)
        shala++;
    l.clear();
    l.push_back(false);
    l.push_back(false);
    if(CalculusPrime( l ) != tab.ff)
        shala++;
    return shala;
}
