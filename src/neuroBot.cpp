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

#include "neuroBot.h"

NeuroBot::NeuroBot(std::list<double> poids){
    this->poids = poids;
}

NeuroBot::~NeuroBot(){
}

NeuroBot::NeuroBot(){
}

bool NeuroBot::bumblebIn(std::list<bool> in){
    double result;
    if( poids.size() != in.size() || in.size() == 0)
        return false;
    std::list<double>::const_iterator poidsIt = poids.begin();
    for(std::list<bool>::const_iterator boolIt = in.begin(); boolIt != in.end(); boolIt++, poidsIt++){
        if( (*boolIt) )
            result += *poidsIt;
    }
    return result >= 0.5 ? true : false;
}

int NeuroBot::ChangeMyList(std::list<double> list){
    poids = list;
    return 0;
}

std::ostream& NeuroBot::printMe(std::ostream& os){
    os << "Neurobot" << std::endl;
    std::list<double>::const_iterator poidsIt = poids.begin();
    for(; poidsIt != poids.end(); poidsIt++){
        os << (*poidsIt) << "\t";
    }
    os << std::endl;
    return os;
}

std::ostream& operator<< (std::ostream& os, NeuroBot& bot){
    return bot.printMe(os);
}

void NeuroBot::jeMeChange(){
    for(std::list<double>::iterator poidsIt = poids.begin(); poidsIt != poids.end(); poidsIt++){
        if(RandHomme::randInt(0,2) == 0)
            (*poidsIt) = -(*poidsIt);
    }
}

double NeuroBot::recup(int pos){
    std::list<double>::const_iterator poidsIt = poids.begin();
    for (int i=0; i<pos; i++)
        poidsIt++;
    return *poidsIt;
}

double NeuroBot::diffDouble(std::list<bool> in){
    double result;
    if( poids.size() != in.size() )
        return false;
    std::list<double>::const_iterator poidsIt = poids.begin();
    std::list<bool>::const_iterator boolIt = in.begin();
    for(; boolIt != in.end(); boolIt++, poidsIt++){
        if( *boolIt )
            result += *poidsIt;
    }
    double res;
    if(result > 0 && result < 0.5)
        res = 0.5 - result;
    else
        res = result - 0.5;
    return res > 0 ? res : -res;
}
