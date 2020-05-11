#ifndef _MACIERZ_OBROTU_HH
#define _MACIERZ_OBROTU_HH

#include "macierz.hh"
using smacierz = macierz<double, 3>;

//wokol jakiej osi ma sie obrocic obiekt
//enum wymiar{x, y, z};

class macierz_ob :public macierz<double, 3>
{
public:
    macierz_ob() 
    {
        tab[0][0] = 1;
        tab[1][1] = 1;
        tab[2][2] = 1;
    }
    macierz_ob(const smacierz & M) : smacierz(M) 
    {
        if(abs((*this).wyznacznik() - 1) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }

        if(abs(M[0]*M[1]) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }

        if(abs(M[1]*M[2]) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }

        if(abs(M[1]*M[2]) > FLT_EPSILON)
        {std::cerr << "To nie jest macierz obrotu" << std::endl; exit(1); }
    }
    ~macierz_ob() {}
};
#endif