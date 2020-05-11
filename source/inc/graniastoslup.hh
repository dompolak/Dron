#ifndef _GRANIASTOSLUP_HH
#define _GRANIASTOSLUP_HH

#include "bryla.hh"
using Wektor3D = Wektor<double,3>;

class graniastoslup : public bryla
{
   Wektor3D wierzcholki[12];
public:
    graniastoslup(Wektor3D S, drawNS::APIGnuPlot3D *wsk, std::string K,Wektor3D tablica[], macierz_ob M)
    : bryla(wsk, K, M, S)
    {
        for(int i(0); i < 12; i++)
        { wierzcholki[i] = tablica[i]; }  
    }

    void rysuj()
    {
    using std::vector;

    Wektor<double,3 > tmp[8];
    for(int i(0); i < 8; i++)
    { tmp[i] = srodek_bryly + orientacja * wierzcholki[i]; }

    id = api->draw_polyhedron(vector<vector<drawNS::Point3D>>{{tmp[0].punkt(),tmp[1].punkt(),tmp[2].punkt(),tmp[3].punkt(), tmp[4].punkt(), tmp[5].punkt()},
    {tmp[6].punkt(),tmp[7].punkt(),tmp[8].punkt(),tmp[9].punkt(), tmp[10].punkt(), tmp[11].punkt()}},kolor);
    api->redraw();

    }
};

#endif