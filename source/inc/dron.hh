#ifndef _DRON_HH
#define _DRON_HH

#include "inter_drona.hh"
#include "wirnik.hh"

/*!
*  \brief klasa reprezentujaca drona
*/
class dron : public interfejs_drona
{   
    /*!
    *  \brief zmienne reprezentujaca wirniki drona
    */
    wirnik lewy_wirnik, prawy_wirnik;

public:
        /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    *  \param M - masierz stanowiaca orientacje bryly
    *  \param S - punkt sroka bryly
    *  \param S1 - punkt srodka bryle wirnika
    *  \param S2 - punkt srodka bryly wirnika
    *  \param tablica - tablica 8 wektorow reprezentujaca wierzcholki
    *  \param tab1 - tablica 12 wektorow reprezentujaca wierzcholki
    *  \param tab2 - tablica 12 wektorow reprezentujaca wierzcholki
    */
    dron(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S, Wektor3D S1, Wektor3D S2, Wektor3D tablica[], Wektor3D tab1[], Wektor3D tab2[])
    : interfejs_drona(wsk, K, M, S, tablica) 
    , lewy_wirnik(wsk, "red", M, S1, tab1)
    , prawy_wirnik(wsk, "red", M, S1, tab1) {}
    /*!
    *  \brief destruktor
    */
    virtual ~dron() {}
    /*!
    *  \brief metoda odpowiedzialna za przesuwanie calego obiektu
    *  \param odleglosc - o ile ma sie przesunac obiekt
    *  \param kat - kat o jaki ma sie obrocic obiekt
    */  
    void przesun(const double &, const double &);
    /*!
    *  \brief metoda sluza do zmiany orientacji bryly
    *  \param kat - kat o jaki ma sie obrocic obiekt
    */
    void obroc(const double );
    /*!
    *  \brief metoda rysujaca obiekt
    */
    void rysuj();
    /*!
    *  \brief metoda wymazujaca caly obiekt
    */
    void usun_obiekt();
    


};

#endif