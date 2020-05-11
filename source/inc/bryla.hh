#ifndef _BRYLA_HH
#define _BRYLA_HH

#include "macierz_obrotu.hh"
#include "Dr3D_gnuplot_api.hh"
#include "interfejs_rysowania.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using wektor3D = Wektor<double, 3>;

class bryla : public interfejs_rysowania
{
protected:

    macierz_ob orientacja;
    wektor3D srodek_bryly;
    double id; 


public:
    bryla( drawNS::Draw3DAPI * wsk, std::string K, macierz_ob M, wektor3D S) 
    : interfejs_rysowania(wsk, K) 
    , orientacja(M)
    , srodek_bryly(S)
    , id(0.0) {}

    virtual ~bryla() {};

    /*void set_orientacja(const macierz_ob & M)   { this->orientacja = M; }
    macierz_ob get_orientacja() {return orientacja; }

    void set_srodek(const wektor3D& W)  { this->srodek_bryly = W; }
    wektor3D get_srodek() {return srodek_bryly; }
    */
    double getID() const 
    {return id; }

    virtual void rysuj() = 0;
    virtual void przesun(wektor3D przesuniecie)// narazie przesuniecie o wektor
    {
        api->erase_shape(id);
        srodek_bryly = srodek_bryly + przesuniecie;
        rysuj();
    }

    virtual void rotacja(double kat)
    {
        api->erase_shape(id);
        double kat_rad = M_PI * kat / 180;
        //macierz obrotu wokol osi z 
        macierz_ob tmp(orientacja);
        tmp[0][0] = cos(kat_rad); 
        tmp[0][1] = (-1) * sin(kat_rad);
        tmp[1][0] = sin(kat_rad);
        tmp[1][1] = cos(kat_rad);
        orientacja = macierz_ob(tmp * orientacja);
        rysuj();
    }


};

#endif