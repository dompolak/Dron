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
Wektor3D sr_dron, sr1, sr2[4];
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
    plik_dron >> sr2[0];
  for(int i(0); i < 8; i++)
  {
      plik_dron >> tab[2][i];
  }
    plik_dron >> sr2[1];

for(int i(0); i < 8; i++)
{
  cout << *tab[1] << endl;
}

przeszkoda_prost tmp(api, "green", x_dron, sr2[0], tab[1]);
przeszkoda_prost tmp2(api, "green", x_dron, sr2[1], tab[2]);
std::vector<std::shared_ptr<dron>> Dron
{
  std::make_shared<dron>(api, "purple", x_dron, sr_dron, sr1, sr1, tab[0], tab1, tab2),
  std::make_shared<dron>(api, "grey", x_dron, sr_dron, sr1, sr1, tab[0], tab1, tab2),
  std::make_shared<dron>(api, "orange", x_dron, sr_dron, sr1, sr1, tab[0], tab1, tab2)
};
dno Dno(api);
tafla Tafla(api);
Wektor3D tmp1(30,-20,5), tmp3(10, 30, 25);
tmp.przemiesc(tmp1);
tmp2.przemiesc(tmp3);
Dron[1]->obroc(90);
Dron[1]->przesun(30,-10);
Dron[1]->obroc(-90);
Dron[2]->obroc(-90);
Dron[2]->przesun(-30, 20);
Dron[2]->obroc(90);
tmp.rysuj();
tmp2.rysuj();
Tafla.rysuj();
Dno.rysuj();
Dron[0]->rysuj();
Dron[1]->rysuj();
Dron[2]->rysuj();

char wybor;
double odleglosc, kat, dzielnik;
int n(0);
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
    Dron[n]->przesun(odleglosc / dzielnik, kat);
    for(int j(0); j < 3; j++)
    {
      if(j != n)
      {
        if(Dron[n]->czy_kolizja(*Dron[j]))
        {i = dzielnik; }
      }
    }
    if(Dno.czy_kolizja(*Dron[n]) || Tafla.czy_kolizja(*Dron[n]) || tmp.czy_kolizja(*Dron[n]) || tmp2.czy_kolizja(*Dron[n]))
    {
      i = dzielnik;
    }
    Dron[n]->rysuj();
    }
    break;

    case 'o': 
    cout << "Podaj kat:" << endl;
    cin >> kat;
    dzielnik = std::abs(kat * 2);
    for(int i(0); i < dzielnik; i++)
    {
    Dron[n]->obroc(kat/dzielnik);
    Dron[n]->rysuj();
    }
    break;

    case 'w':
    cout << "1. Dron fioletowy" << endl;
    cout << "2. Dron szary" << endl;
    cout << "3. Dron pomaranczowy" << endl;
    cin >> wybor;
      if(wybor == '1')
      n = 0;
      if(wybor == '2')
      n = 1;
      if(wybor == '3')
      n = 2;
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
  cout << "w - wybor drona" << endl;
  cout << "k - Koniec dzialania programu" << endl;
}