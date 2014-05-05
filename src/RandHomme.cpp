#include "RandHomme.h"

int RandHomme::randInt(int minimum, int maximum){
    return static_cast<int> (randDouble(minimum, maximum));
}
double RandHomme::randDouble(double minimum, double maximum){
    return minimum + std::rand() / ( static_cast <double> (RAND_MAX) / (maximum - minimum));
}
void RandHomme::nouvelleGraine(void){
    std::srand(std::time(NULL));
}
void RandHomme::nouvelleGraine(unsigned int graine){
    std::srand(graine);
}
