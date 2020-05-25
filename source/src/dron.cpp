#include "dron.hh"

void dron::przesun(const double &odleglosc, const double &kat)
{
        Wektor3D przesuniecie(odleglosc,0,0);
        //macierz_ob obrot(os_y, kat);
        orientacja = macierz_ob(os_y, kat);
        prostopadloscian::przemiesc(przesuniecie);
        lewy_wirnik.przemiesc(przesuniecie);
        prawy_wirnik.przemiesc(przesuniecie);
        lewy_wirnik.obrot(15);
        prawy_wirnik.obrot(15);
        usun_obiekt();
        rysuj();

    
}

void dron::rysuj()
{
    prostopadloscian::rysuj();
    lewy_wirnik.rysuj(srodek_bryly + orientacja * ((wierzcholki[3] + wierzcholki[7]) / 2), orientacja);
    prawy_wirnik.rysuj(srodek_bryly + orientacja * ((wierzcholki[0] + wierzcholki[4]) / 2), orientacja);
}

void dron::usun_obiekt()
{
    prostopadloscian::usun_obiekt();
    lewy_wirnik.usun_obiekt();
    prawy_wirnik.usun_obiekt();
}

void dron::obroc(const double kat)
{
    prostopadloscian::obroc(kat);
    lewy_wirnik.obroc(kat);
    prawy_wirnik.obroc(kat);
    lewy_wirnik.obrot(15);
    prawy_wirnik.obrot(15);
    usun_obiekt();
    rysuj();
}