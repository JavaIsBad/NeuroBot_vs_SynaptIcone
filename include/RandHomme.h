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

#ifndef __RANDHOMME_H
#define __RANDHOMME_H

#include <cstdlib>
#include <ctime>

class RandHomme{
    public:
        static int randInt(int minimum, int maximum);
        static double randDouble(double minimum, double maximum);
        static void nouvelleGraine(void);
        static void nouvelleGraine(unsigned int graine);
};

#endif // (__RANDHOMME_H)
