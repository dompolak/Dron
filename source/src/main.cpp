#include "dron.hh"
#include "dno.hh"
#include "tafla.hh"
#include "przeszkoda_prostopadloscian.hh"

using std::cin;
using std::cout;
using std::endl;

void wait4key();
void menu_wyboru();


int main()
{

int max(100);
std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-max,max,-max,max,-max,max,-1));
std::ifstream plik_dron;
Wektor3D sr_dron, sr1, sr2;
Wektor3D tab[5][8], tab1[12], tab2[12];
macierz3D x_dron;

plik_dron.open("test.txt");

  plik_dron >> x_dron;
for(int i(0); i < 8; i++)
{
      plik_dron >> tab[0][i];
}
    plik_dron >> sr_dron;

for(int i(0); i < 12; i++)
{
      plik_dron >> tab1[i];
}
  plik_dron >> sr1;

for(int i(0); i < 8; i++)
{
      plik_dron >> tab[1][i];
}
    plik_dron >> sr2;

przeszkoda_prost tmp(api, "green", x_dron, sr2, tab[1]);
dron Dron(api, "purple", x_dron, sr_dron, sr1, sr2, tab[0], tab1, tab2);
dno Dno(api);
tafla Tafla(api);
Wektor3D tmp1(20,0,0);
tmp.przemiesc(tmp1);
tmp.rysuj();
Tafla.rysuj();
Dno.rysuj();
Dron.rysuj();

char wybor;
double odleglosc, kat, dzielnik;
while(wybor != 'k')
{
  menu_wyboru();
  cout << "Twoj wybor: " << endl;
  cin >> wybor;

  switch(wybor)
  {
    case 'r': 
    cout << "Podaj odleglosc, kat:" << endl;
    cin >> odleglosc >> kat;
    dzielnik = std::abs(odleglosc * 5);
    for(int i(0); i < dzielnik; i++)
    {
    Dron.przesun(odleglosc / dzielnik, kat);
    usleep(1000);
    if(Dno.czy_kolizja(Dron) || Tafla.czy_kolizja(Dron))
    {
      i = dzielnik;
    }
    Dron.rysuj();
    }
    break;

    case 'o': 
    cout << "Podaj kat:" << endl;
    cin >> kat;
    dzielnik = std::abs(kat * 2);
    for(int i(0); i < dzielnik; i++)
    {
    Dron.obroc(kat/dzielnik);
    usleep(1000);
    Dron.rysuj();
    }
    break;

    case 'k':
    cout << "Koniec dzialania programu!" << endl;
    return 0;

    default:
    std::cerr << "Nie ma takiego wyboru" << endl;
    break;
  }
}
return 0;

}

void wait4key() 
{
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

void menu_wyboru()
{
  cout << "----Wybor opcji drona----" << endl;
  cout << "r - Zadaj ruch na wprost" << endl;
  cout << "o - Zadaj zmiane orientacji" << endl;
  cout << "k - Koniec dzialania programu" << endl;
}