#include "prostopadloscian.hh"
#include "wektor.hh"

void prostopadloscian::rysuj()
{
    using std::vector;

    Wektor<double,3 > tmp[8];
    for(int i(0); i < 8; i++)
    { tmp[i] = srodek_bryly + orientacja * wierzcholki[i]; }

    id = api->draw_polyhedron(vector<vector<drawNS::Point3D>>{{tmp[0].punkt(),tmp[1].punkt(),tmp[2].punkt(),tmp[3].punkt()},
    {tmp[4].punkt(),tmp[5].punkt(),tmp[6].punkt(),tmp[7].punkt()}},kolor);
    api->redraw();

}



