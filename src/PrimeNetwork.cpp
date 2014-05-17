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
    (*this) = prime;
}

PrimeNetwork::PrimeNetwork(PrimeNetwork& p1, PrimeNetwork& p2){
    NeuroBot nb;
    int rand;
    for (unsigned int i=0; i < NBINTO; i++){
        rand = RandHomme::randInt(0,2);
        if(rand >= 1){
            nb = p1.giveMeBrain(i);
        }
        else{
            nb = p2.giveMeBrain(i);
        }
        inBot.push_back(nb);
    }
    rand = RandHomme::randInt(0,2);
    if (rand>=1){
        nb = p1.giveMeBrain(NBINTO);
    }
    else{
        nb = p2.giveMeBrain(NBINTO);
    }
    outBot = nb;
}


PrimeNetwork::~PrimeNetwork(){
}

bool PrimeNetwork::CalculusPrime(std::list<bool> boulien){
    if( boulien.size() != 2 )
        return false;
    std::list<bool> li;
    for(std::vector<NeuroBot>::iterator it = inBot.begin(); it != inBot.end(); ++it){
        li.push_back( (*it).bumblebIn( boulien ) );
    }
    return outBot.bumblebIn( li );
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
    os << outBot << std::endl;
    return os;
}

std::ostream& operator<< (std::ostream& os, PrimeNetwork& prime){
    return prime.printMe(os);
}

NeuroBot& PrimeNetwork::giveMeBrain(unsigned int position){
    if( position== NBINTO )
        return outBot;
    return inBot.at(position);
}

double PrimeNetwork::CalculusPrimeDouble(std::list<bool> boulien){
    if( boulien.size() != 2 )
        return false;
    std::list<bool> l;
    for(std::vector<NeuroBot>::iterator it = inBot.begin(); it != inBot.end(); ++it){
        l.push_back( (*it).bumblebIn( boulien ) );
    }
    return outBot.diffDouble( l );
}

double PrimeNetwork::differencielPrime(const TableDeVerite& tab){
    std::list<bool> l;
    double diff = 0.;
    l.push_back(true);
    l.push_back(true);
    if(CalculusPrime( l ) != tab.vv)
        diff += CalculusPrimeDouble( l );
    l.clear();
    l.push_back(true);
    l.push_back(false);
    if(CalculusPrime( l ) != tab.vf)
        diff += CalculusPrimeDouble( l );
    l.clear();
    l.push_back(false);
    l.push_back(true);
    if(CalculusPrime( l ) != tab.fv)
        diff += CalculusPrimeDouble( l );
    l.clear();
    l.push_back(false);
    l.push_back(false);
    if(CalculusPrime( l ) != tab.ff)
        diff += CalculusPrimeDouble( l );
    return diff;
}

void PrimeNetwork::IlEtaitUneFoisJeMinverse(){
    for (unsigned int i=0; i<inBot.size(); i++){
        inBot.at(i).jeMeChange();
    }
    outBot.jeMeChange();
}

