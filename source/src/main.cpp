#include "dron.hh"
#include "tafla.hh"
#include "podloze.hh"
#include "macierz_obrotu.hh"
#include "Dr3D_gnuplot_api.hh"

using drawNS::APIGnuPlot3D;
using drawNS::Point3D;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using wektor3D = Wektor<double,3>;

void wait4key();
void menu_wyboru();

int main()
{

int max(10);
std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-max,max,-max,max,-max,max,1000));
std::ifstream plik_dron, wirnik;
wektor3D sr_dron;
wektor3D tab[8], tab1[12];
smacierz x_dron;
char wybor;

plik_dron.open("dron.txt");

for(int i(0); i <= 8; i++)
{
    if(i < 8)
    {
      plik_dron >> tab[i];
    }else
    {
      plik_dron >> x_dron;
      plik_dron >> sr_dron;
    }
}
dron tmp();
tmp.rysuj();
tafla T(api);
podloze P(api);
P.rysuj();
T.rysuj();
double kat(0), odleglosc(0);

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
    break;

    case 'o': // zmiana orientacji
    cout << "Podaj kat:" << endl;
    cin >> kat;
    tmp.obroc(kat);
    break;

    case 'k':
    cout << "Koniec dzialania programu!" << endl;
    return 0;

    default:
    std::cerr << "Nie ma takiego wyboru" << endl;
    break;
  }
}

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
