#ifndef _DRONE_HH
#define _DRONE_HH

#include "prostopadloscian.hh"
#include "graniastoslup.hh"

using wektor3D = Wektor<double, 3>;

class drone : public prostopadloscian
{
    double id_drone;
public:
    drone(Wektor3D S, drawNS::APIGnuPlot3D *wsk, std::string K,Wektor3D tablica[], macierz_ob M)
    : prostopadloscian(tablica, M, S, wsk, K)
    , id_drone(0) {}
    ~drone();
    void rysuj();
};

#endif