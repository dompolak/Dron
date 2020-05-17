#ifndef _BRYLA_HH
#define _BRYLA_HH

#include "macierz_obrotu.hh"
#include "Dr3D_gnuplot_api.hh"
#include "interfejs_rysowania.hh"
#define DZIELNIK 100

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using wektor3D = Wektor<double, 3>;

class bryla : public interfejs_rysowania
{
protected:

    macierz_ob orientacja;
    wektor3D srodek_bryly;
    std::string kolor;

public:
    bryla(std::shared_ptr<drawNS::Draw3DAPI> wsk, std::string K, macierz_ob M, wektor3D S) 
    : interfejs_rysowania(wsk)
    , orientacja(M)
    , srodek_bryly(S)
    , kolor(K) {}

    virtual ~bryla() {};

    /*void set_orientacja(const macierz_ob & M)   { this->orientacja = M; }
    macierz_ob get_orientacja() {return orientacja; }
    */
    void set_srodek(const wektor3D& W)  { this->srodek_bryly = W; }
    wektor3D get_srodek() {return srodek_bryly; }
    
    double getID() const 
    {return id; }

    virtual void rysuj() = 0;

    virtual void przesun(const wektor3D &we)
    {
        srodek_bryly = srodek_bryly + we;
        usun_obiekt();
        rysuj();
    }

    virtual void obroc(const double &kat)
    {
        
        macierz_ob tmp(os_z, kat);
        orientacja = macierz_ob(tmp * orientacja);
        usun_obiekt();
        rysuj();
    }


};

#endif