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
