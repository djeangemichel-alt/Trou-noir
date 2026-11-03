#pragma once

struct position2D {
    double x;
    double y;
};

struct vitesse2D {
    double vx;
    double vy;
};

struct acceleration2D {
    double ax;
    double ay;
};

// Fonctions mathématiques
void deplacement(position2D& pos, vitesse2D& vitesse, double temps);

position2D soustraire(position2D a, position2D b);

double norme_distance(position2D d);
double norme_vitesse(vitesse2D v);
double norme_acceleration(acceleration2D a);

// Fonctions physiques
double force_gravitationnelle(
    double masseT,
    double masse,
    position2D position,
    position2D centre
);

double acceleration_gravitationnelle(
    double masseT,
    position2D position,
    position2D centre
);

acceleration2D acceleration_gravitationnelleComposants(
    double masseT,
    position2D position,
    position2D centre
);

void mettreAJour(
    position2D& position,
    vitesse2D& vitesse,
    position2D centre,
    double masseTrouNoir,
    double dt
);