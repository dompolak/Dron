#ifndef _WIRNIK_HH
#define _WIRNIK_HH

#include "graniastoslup6.hh"

/*!
*  \brief klasa reprezentujaca wirnik
*/
class wirnik : public graniastoslup
{

public:
    /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    *  \param M - macierz stanowiaca orientacje bryly
    *  \param S - punkt srodka bryly
    *  \param tablica - tablica 12 wektorow reprezentujaca wierzcholki 
    */
    wirnik(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S, Wektor3D tablica[])
    : graniastoslup(wsk, K, M, S, tablica) {}
    /*!
    *  \brief destruktor
    */
    virtual ~wirnik() {}

    /*!
    *  \brief metoda rysujaca obiekt
    *  \param we - wektor przyjmujacy srodek obiektu bazowego
    *  \param ob - macierz obrotu przyjmujaca orientacje obiektu bazowego
    */
    void rysuj(const Wektor3D & we, const macierz_ob & ob)
    {
        macierz_ob m_pom(os_y, 90);
        Wektor3D tmp[12];
        for(int i(0); i < 12; i++)
        { 
            //tmp[i] = we + ob * (orientacja * (m_pom * wierzcholki[i]));
            tmp[i] = we + orientacja * (srodek_bryly + m_pom * wierzcholki[i]);
        }

        obiekt_id = gnuplot->draw_polyhedron(vector<vector<Point3D>>
        {{
            tmp[0].punkt(), tmp[1].punkt(), tmp[2].punkt(), tmp[3].punkt(), tmp[4].punkt(), tmp[5].punkt()
        },{ 
            tmp[6].punkt(),tmp[7].punkt(),tmp[8].punkt(),tmp[9].punkt(), tmp[10].punkt(), tmp[11].punkt()
        }}, kolor);
    }
    
    /*!
    *  \brief metoda obracajaca wirnik wzgledem osi x 
    *  \param kat - kat o jaki ma sie obrocic
    */
    void obrot(const double kat) 
    {
       orientacja = macierz_ob(os_x, kat);
       usun_obiekt();
    }
    
    
};

#endif