#ifndef _POWIERZCHNIA_HH
#define _POWIERZCHNIA_HH

#include "interfejs_rysowania.hh"
#include "wektor.hh"
#define MAX 10

using std::vector;
using wektor3D = Wektor<double,3>;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class powierzchnia : public interfejs_rysowania
{

public:
    powierzchnia(std::shared_ptr<drawNS::Draw3DAPI> wsk) :
    interfejs_rysowania(wsk){}

    virtual ~powierzchnia() {}

};

#endif