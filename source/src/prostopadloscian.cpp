#include "prostopadloscian.hh"
#include "wektor.hh"

/*void prostopadloscian::rysuj()
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
*/
/*void prostopadloscian::przesun(const wektor3D &przesuniecie)
{
    Wektor3D tmp(przesuniecie/DZIELNIK);

    for(int i(0); i < DZIELNIK; i++)
    {
        srodek_bryly = srodek_bryly + tmp;
        for(int j(0); i < 8; i++)
        { wierzcholki[j] = wierzcholki[i] + tmp; }
        usun_obiekt();
        rysuj();
    }
}

void prostopadloscian::przesun_przod(const double odleglosc, const double kat)
{
    macierz_ob tmp(os_z, kat);
    double tab[3] = {odleglosc/DZIELNIK,0,0};
    Wektor3D tmp1(tab);
    tmp = tmp * orientacja;
    for(int i(0); i < DZIELNIK; i++)
    {
        srodek_bryly = srodek_bryly + tmp * tmp1;

        api->erase_shape(id);
        rysuj();
    }
}


/*void prostopadloscian::obroc(const double &kat)
{
    macierz_ob tmp(os_z, kat/DZIELNIK);
    for(int i(0); i < DZIELNIK; i++)
    {
        orientacja = orientacja * tmp;
        api->erase_shape(id);
        rysuj();
    }
}*/
