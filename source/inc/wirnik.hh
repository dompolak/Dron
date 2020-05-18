#ifndef _WIRNIK_HH
#define _WIRNIK_HH

#include "graniastoslup.hh"

class wirnik : public graniastoslup
{   
    macierz_ob ob_wirnik;
    wektor3D point;
public:
    wirnik(Wektor3D S, std::shared_ptr<drawNS::Draw3DAPI> wsk, std::string K,Wektor3D tablica[], macierz_ob M):
    graniastoslup(S, wsk, K, tablica, M)
    , ob_wirnik(os_x, 0)
    , point(1,1,1) {}

    void rysuj()
    {  
        wektor3D pom[12];
        macierz_ob tmp(os_y, 90);
        for(int i(0); i < 12; i++)
        {
            pom[i] = point + orientacja * (ob_wirnik * (tmp * wierzcholki[i]));
        }
        id = api->draw_polyhedron(vector<vector<drawNS::Point3D>> {
        {pom[0].punkt(),pom[1].punkt(),pom[2].punkt(),pom[3].punkt(),pom[4].punkt(),pom[5].punkt()
        },{
        pom[6].punkt(),pom[7].punkt(),pom[8].punkt(),pom[9].punkt(),pom[10].punkt(),pom[11].punkt()}
        }, kolor);

    }
    
    void obroc(const double kat)
    {
        usun_obiekt();
        ob_wirnik = macierz_ob(os_x, kat);
    }

    void przesun(const wektor3D &we)
    {
        point = point + we;
        srodek_bryly = srodek_bryly + we;
        for(int i(0); i < 12; i++)
        {
            wierzcholki[i] = wierzcholki[i] + we;
        }
        usun_obiekt();
        rysuj();
    }
    void setPoint(const wektor3D &we) { point = we; }
    wektor3D getPoint() const { return point; }

};

#endif