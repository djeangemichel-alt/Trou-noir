
#include <cmath>
#include <iostream>
#include "2D_lensing.hpp"
using namespace std;

void deplacement(
    position2D& pos,
    vitesse2D& vitesse, 
    double temps
){
    
    pos.x += vitesse.vx * temps;
    pos.y += vitesse.vy * temps;

};

position2D soustraire(position2D a, position2D b) {
    position2D resultat;

    resultat.x = b.x - a.x;
    resultat.y = b.y - a.y;

    return resultat;
}

double norme_distance(position2D d){
    return sqrt(d.x*d.x + d.y*d.y);   
}
double norme_vitesse(vitesse2D v){
    return sqrt(v.vx*v.vx + v.vy*v.vy);
}
double norme_acceleration(acceleration2D a){
    return sqrt(a.ax*a.ax + a.ay*a.ay);   // sqrt pour square root
}

double force_gravitationnelle(
    double masseT,
    double masse,
    position2D position,
    position2D centre
){
    
    double G = 6.67430e-11; 

    position2D distance_vect = soustraire(centre, position);
    double r = norme_distance(distance_vect);
   
    if(r==0){
        return 0;
    }
    double force=G*masseT*masse/(r*r);

    return force;
}

double acceleration_gravitationnelle(
    double masseT,
    position2D position,
    position2D centre
){
    
    double G = 6.67430e-11; 

    position2D distance_vect = soustraire(centre, position);
    double r = norme_distance(distance_vect);
   
    if(r==0){
        cout << "Erreur : division par zéro dans la fonction acceleration_gravitationnelle." << endl;
        return 0;
    }

     double Facteur = -G * masseT/(r * r * r);
     
    double ax = Facteur * distance_vect.x;
    double ay = Facteur * distance_vect.y;

    double norme_acceleration = sqrt(ax*ax +ay*ay);

    return norme_acceleration;
}

acceleration2D acceleration_gravitationnelleComposants(
    double masseT,
    position2D position,
    position2D centre
){
    
    double G = 6.67430e-11; 

    position2D distance_vect = soustraire(centre, position);
    double r = norme_distance(distance_vect);
   
    if(r==0){
        acceleration2D result = {0, 0};
        return result;
    }
    double Facteur = -G * masseT/(r * r * r);
     
    double ax = Facteur * distance_vect.x;
    double ay = Facteur * distance_vect.y;

    acceleration2D result = {ax, ay};
    return result;
}

void mettreAJour(
    position2D& position,
    vitesse2D& vitesse,
    position2D centre,
    double masseTrouNoir,
    double dt
) {
    
    acceleration2D a = acceleration_gravitationnelleComposants(
        masseTrouNoir, position, centre
    );

    
    vitesse.vx = vitesse.vx + a.ax * dt;
    vitesse.vy = vitesse.vy + a.ay * dt;

    
    position.x = position.x + vitesse.vx * dt;
    position.y = position.y + vitesse.vy * dt;
}


void test(){
    // referenciel , Sagittarius A ,masse = 4.3*10e6 Masse solaire = 8.55 * 10e36 kg 
    // masse soleil = 1.989 * 10e30 kg
    // masse terre = 5.972 * 10e24 kg
    //distance terre - sagittarius A  = 26 000 année lumiere = 9.4608e15 m * 26000 m = 2.459808e20 m
    //sagittarius - soleil = 2.459808*10e20 - 150*10e9 = 2.459808*10e20 m
    // unité de distance = année lumiere = 9.4608e15 m
    // nous supposons un alignement parfait entre le trou noir, le soleil et la terre pour simplifier les calculs.
   // distance reelle
    double dt = 1.0e9; 
    double masseTrouNoir = 8.55e36;
    vitesse2D vitesseSoleil = {0.0, 0.0};
    position2D trouNoir = {0.000, 0.000};
    position2D soleil = {2.459808e20, 0.000};
    position2D terre = {2.459808e20, 0.000};

    position2D trouNoir_soleil = soustraire(soleil, trouNoir);
    position2D trouNoir_terre = soustraire(terre, trouNoir);

    double force_soleil = force_gravitationnelle(8.55e36, 1.989e30, soleil, trouNoir);
    double force_terre = force_gravitationnelle(8.55e36, 5.972e24, terre, trouNoir);

    double acceleration_soleil = acceleration_gravitationnelle(8.55e36, soleil, trouNoir);
    double acceleration_terre = acceleration_gravitationnelle(8.55e36, terre, trouNoir);

    cout << "Force sur le soleil: " << force_soleil << "N"<< endl;
    cout << "Force sur la terre: " << force_terre << "N"<< endl;
    cout << "Acceleration sur le soleil: " << acceleration_soleil  << "m/s^2"<< endl;
    cout << "Acceleration sur la terre: " << acceleration_terre  << "m/s^2"<< endl;

    for (int i = 0; i < 100000; i++) {
    mettreAJour(
        soleil,
        vitesseSoleil,
        trouNoir,
        masseTrouNoir,
        dt
    );

    cout << "Etape " << i + 1
         << " : x = " << soleil.x
         << ", y = " << soleil.y
         << ", vitesse = " << vitesseSoleil.vx
         << ", " << vitesseSoleil.vy << endl;
}
    
}



