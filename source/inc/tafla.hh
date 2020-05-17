#ifndef _TAFLA_HH
#define _TAFLA_HH

#include "powierzchnia.hh"

class tafla :public powierzchnia
{
    std::string kolor = "blue";
public:
    tafla(std::shared_ptr<drawNS::Draw3DAPI> wsk) : 
    powierzchnia(wsk) {}

    void rysuj()
    {
        id = api->draw_surface(vector<vector<Point3D>> {{
        
	    drawNS::Point3D(-MAX,-MAX, MAX), drawNS::Point3D(MAX,-MAX,MAX), drawNS::Point3D(MAX,MAX,MAX)
	    },{
	    drawNS::Point3D(-MAX,-MAX,MAX), drawNS::Point3D(-MAX,MAX,MAX), drawNS::Point3D(MAX,MAX,MAX)       
        }}
        , "blue");
        api->redraw();
    }
};

#endif