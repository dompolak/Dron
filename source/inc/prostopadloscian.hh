#ifndef _PROSTOPADLOSCIAN_HH
#define _PROSTOPADLOSCIAN_HH

#include "bryla.hh"

using std::vector;
using Wektor3D = Wektor<double,3>;

class prostopadloscian : public bryla
{
    Wektor3D wierzcholki[8];

public:
    prostopadloscian(Wektor3D tablica[], macierz_ob M, Wektor3D S, std::shared_ptr<drawNS::Draw3DAPI> wsk, std::string K)
    : bryla(wsk, K, M ,S) 
    {
        for(int i(0); i < 8; i++)
        { wierzcholki[i] = tablica[i]; }
    }

    virtual ~prostopadloscian() {}
    void rysuj()
    {
    Wektor<double,3 > tmp[8];
    for(int i(0); i < 8; i++)
    { tmp[i] = srodek_bryly + orientacja * wierzcholki[i]; }

    id = api->draw_polyhedron(vector<vector<drawNS::Point3D>>
    {{tmp[0].punkt(),tmp[1].punkt(),tmp[2].punkt(),tmp[3].punkt()
    },{
    tmp[4].punkt(),tmp[5].punkt(),tmp[6].punkt(),tmp[7].punkt()}
    },kolor);

    api->redraw();
    }

    void przesun(const Wektor3D &we)
    {
        srodek_bryly = srodek_bryly + we;
        for(int i(0); i < 8; i++)
        {
            wierzcholki[i] = wierzcholki[i] + we;
            usun_obiekt();
            rysuj();
        }
    }
};

#endif