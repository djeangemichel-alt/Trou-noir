#include <iostream>
#include "2D_lensing.hpp"

int main()
{
    position2D centre = {0.0, 0.0};
    position2D particule = {100.0, 0.0};

    vitesse2D vitesse = {0.0, 0.0};

    double masseTrouNoir = 1.0e20;

    mettreAJour(
        particule,
        vitesse,
        centre,
        masseTrouNoir,
        0.1
    );

    std::cout << "Position X : " << particule.x << std::endl;
    std::cout << "Position Y : " << particule.y << std::endl;

    return 0;
}