#ifndef _INTERFEJS_RYSOWANIA_HH
#define _INTERFES_RYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"

class interfejs_rysowania
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> api;
    std::string kolor;
public:
    interfejs_rysowania(drawNS::Draw3DAPI *wsk, const std::string K):
    api(wsk)
    ,kolor(K) {}
    virtual ~interfejs_rysowania() {}
    virtual void rysuj() = 0;

};
#endif
