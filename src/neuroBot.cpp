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
    if( poids.size() != in.size() )
        return false;
    std::list<double>::const_iterator poidsIt = poids.begin();
    std::list<bool>::const_iterator boolIt = in.begin();
    for(; boolIt != in.end(); boolIt++, poidsIt++){
        if( *boolIt )
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
    std::list<double>::iterator poidsIt = poids.begin();
    for(; poidsIt != poids.end(); poidsIt++){
        if(RandHomme::randInt(0,2) == 0)
            *poidsIt =-(*poidsIt);
    }
}

double NeuroBot::recup(int pos){
    std::list<double>::const_iterator poidsIt = poids.begin();
    for (int i=0; i<pos; i++)
        poidsIt++;
    return *poidsIt;
}
