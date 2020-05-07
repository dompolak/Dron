#include "macierz.hh"

int main()
{
    macierz<double, 3> tmp;

    for(;;)
    {
        std::cin >> tmp;
        std::cout << tmp.wyznacznik() << std::endl;
        std::cout << tmp.wyznacznik1() << std::endl;

    }

}