#ifndef _PROSTOPADLOSCIAN_HH
#define _PROSTOPADLOSCIAN_HH

#include "bryla.hh"

using std::vector;
using Wektor3D = Wektor<double,3>;

class prostopadloscian : public bryla
{
    Wektor3D wierzcholki[8];

public:
    prostopadloscian(Wektor3D tablica[], macierz_ob M, Wektor3D S, drawNS::APIGnuPlot3D *wsk, std::string K)
    : bryla(wsk, K, M ,S) 
    {
        for(int i(0); i < 8; i++)
        { wierzcholki[i] = tablica[i]; }
    }

    void rysuj();
};
#endif