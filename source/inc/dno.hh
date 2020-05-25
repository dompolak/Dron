#ifndef _DNO_HH
#define _DNO_HH

#include "powierzchnia.hh"

/*!
*  \brief klasa reprezentujaca dno
*/
class dno : public powierzchnia
{

public:
	/*!
	*  \brief konstruktor
	*  \param wsk - lacze do gnuplota
	*/
    dno(shared_ptr<Draw3DAPI> wsk)
    : powierzchnia(wsk, "yellow") {}
	/*!
	*  \brief metoda rysujaca dno 	
	*/
    void rysuj()
    {
    obiekt_id = gnuplot->draw_surface(vector<vector<Point3D>> {{
  	drawNS::Point3D(-100,-100,-100), drawNS::Point3D(-100,-80,-100), drawNS::Point3D(-100,-40,-100), drawNS::Point3D(-100,0,-100), drawNS::Point3D(-100,40,-100), drawNS::Point3D(-100,80,-100), drawNS::Point3D(-100,100,-100)
  	  },{
  	drawNS::Point3D(-80,-100,-100), drawNS::Point3D(-80,-80,-100), drawNS::Point3D(-80,-40,-100),  drawNS::Point3D(-80,0,-100), drawNS::Point3D(-80,40,-100), drawNS::Point3D(-80,80,-100), drawNS::Point3D(-80,100,-100)
      },{
  	drawNS::Point3D(-40,-100,-100), drawNS::Point3D(-40,-80,-100), drawNS::Point3D(-40,-40,-100), drawNS::Point3D(-40,0,-100), drawNS::Point3D(-40,40,-100), drawNS::Point3D(-40,80,-100), drawNS::Point3D(-40,100,-100)
  	  },{
  	drawNS::Point3D(-0,-100,-100), drawNS::Point3D(-0,-80,-100), drawNS::Point3D(-0,-40,-100), drawNS::Point3D(-0,0,-100), drawNS::Point3D(-0,40,-100), drawNS::Point3D(-0,80,-100), drawNS::Point3D(-0,100,-100)
  	  },{
  	drawNS::Point3D(40,-100,-100), drawNS::Point3D(40,-80,-100), drawNS::Point3D(40,-40,-100), drawNS::Point3D(40,0,-100), drawNS::Point3D(40,40,-100), drawNS::Point3D(40,80,-100), drawNS::Point3D(40,100,-100)
  	  },{
  	drawNS::Point3D(80,-100,-100), 	drawNS::Point3D(80,-80,-100), drawNS::Point3D(80,-40,-100), drawNS::Point3D(80,0,-100), drawNS::Point3D(80,40,-100), drawNS::Point3D(80,80,-100), drawNS::Point3D(80,100,-100)
      },{
  	drawNS::Point3D(100,-100,-100), drawNS::Point3D(100,-80,-100), drawNS::Point3D(100,-40,-100), drawNS::Point3D(100,0,-100), drawNS::Point3D(100,40,-100), drawNS::Point3D(100,80,-100), drawNS::Point3D(100,100,-100)
  	  }}, kolor);
    }
};

#endif