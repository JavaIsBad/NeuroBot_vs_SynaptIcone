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
        result += *boolIt * *poidsIt;
    }
    return result >= 0.5 ? true : false;
}
int NeuroBot::ChangeMyList(std::list<double> list){
    poids = list;
}
