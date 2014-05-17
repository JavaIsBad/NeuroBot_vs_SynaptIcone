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

#ifndef __NEUROBOT_H
#define __NEUROBOT_H

#include <list>
#include <iostream>
#include "RandHomme.h"

class NeuroBot{
    public:
        NeuroBot();
        NeuroBot(std::list<double> poids);
        virtual ~NeuroBot();
        bool bumblebIn(std::list<bool> in);
        int ChangeMyList(std::list<double> list);
        std::ostream& printMe(std::ostream& os);
        void jeMeChange();
        double recup(int pos);
        double diffDouble(std::list<bool> in);
    private:
        std::list<double> poids;
};

std::ostream& operator<< (std::ostream& os, NeuroBot& bot);
#endif // (__NEUROBOT_H)
