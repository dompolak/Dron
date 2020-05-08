#ifndef _BRYLA_HH
#define _BRYLA_HH

#include "Dr3D_gnuplot_api.hh"
#include "macierz_ob.hh"

class bryla
{
    std::vector<Wektor<int, 3>> wierzcholki;

public:
    bryla(): wierzcholki(4) {}

};



#endif