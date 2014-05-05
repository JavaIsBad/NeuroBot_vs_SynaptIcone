#include "Netitron.h"

NetiTron::NetiTron(void){
    NetiTron(RandHomme::randInt(100, 1000), RandHomme::randDouble(-100., 0.), RandHomme::randDouble(1., 100.));
}

NetiTron::NetiTron(unsigned int nbr, double min, double max){
    for(unsigned int i=0; i < nbr; i++){
        networkOfNetwork.push_back( PrimeNetwork(min, max) );
    }
}

NetiTron::~NetiTron(){
}

bool NetiTron::Fin(const TableDeVerite tab, PrimeNetwork* prime){
    for(unsigned int i=0; i < networkOfNetwork.size(); i++){
        if( networkOfNetwork.at(i).evaluate( tab ) ){
            prime=new PrimeNetwork( networkOfNetwork.at( i ) );
            return true;
        }
    }
    return false;
}

void NetiTron::evolution(void){
}
