#include "dron.hh"

void wait4key() {
  do {
    cout << "\n Press a key to continue..." << endl;
  } while(cin.get() != 'a');
}

int main()
{
     drawNS::APIGnuPlot3D *wsk=new drawNS::APIGnuPlot3D(-5,5,-5,5,-5,5,1000);
}