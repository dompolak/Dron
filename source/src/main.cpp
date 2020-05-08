#include <iostream>
#include "bryla.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000));
    
}