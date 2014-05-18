NeuroBot_vs_SynaptIcone
=======================

Que fait ce programme ?
-----------------------

Ce programme est un programme d'évolution artificielle pour créer une porte XOR (ou exclusif)
grâce à trois neurones. Les neurones ont en entrée une liste de booléens qui représentent
le nombre d'axones qui arrivent à lui. La sortie du neurone est calculée avec un test simple.
Un compteur réel est initialisé à 0 et si l'entrée est active on ajoute la valuation
(positive ou négative) de cet entrée au compteur. Si le compteur est supérieur à 0.5 le neurone
est actif (vrai) et sinon il est non actif(faux).
La fonction de fitness est calculée par la valeur absolue de l'écart à 0.5 si les neurones ne conviennent
pas pour la table de vérité recherchée. La fitness est donc égale à 0 si le neurone répond au besoin.
Les neurones sont initialisées avec des valeurs entre 0 et 1 et il y a 100 individus.

Build & run
-----------

    make
    ./bin/optiMain

License
-------

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
