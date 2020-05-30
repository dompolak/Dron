#ifndef _PRZESZKODA_HH
#define _PRZESZKODA_HH

#include "inter_drona.hh"
#include "inter_rysowania.hh"

class przeszkoda : public interfejs_rysowania
{
    virtual bool czy_kolizcja(const interfejs_drona &) const = 0;
};

#endif