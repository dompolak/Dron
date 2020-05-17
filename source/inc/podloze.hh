#ifndef _PODLOZE_HH
#define _PODLOZE_HH
#include "powierzchnia.hh"

class podloze : public powierzchnia
{
    std::string kolor = "grey";
public:
    podloze(std::shared_ptr<drawNS::Draw3DAPI> wsk) :
    powierzchnia(wsk) {}

    void rysuj()
    {
    id = api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-MAX,-MAX,-MAX), drawNS::Point3D(MAX,-MAX,-MAX), drawNS::Point3D(MAX,MAX,-MAX)
	  },{
	drawNS::Point3D(-MAX,-MAX,-MAX), drawNS::Point3D(-MAX,MAX,-MAX), drawNS::Point3D(MAX,MAX,-MAX)       
	  }	      
	  },"grey");

        api->redraw();
    }
};

#endif