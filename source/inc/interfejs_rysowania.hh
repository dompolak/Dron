#ifndef _INTERFEJS_RYSOWANIA_HH
#define _INTERFEJS_RYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class interfejs_rysowania
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> api;
    int id;
public:
    interfejs_rysowania(std::shared_ptr<drawNS::Draw3DAPI> wsk): 
    api(wsk)
    , id(0){}
    
    virtual ~interfejs_rysowania() {}
    virtual void rysuj() = 0;
    virtual void usun_obiekt() { api->erase_shape(id); }

};
#endif
