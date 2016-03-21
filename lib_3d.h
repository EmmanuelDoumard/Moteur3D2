#ifndef _LIB_3D_H_
#define _LIB_3D_H_

#include "lib_surface.h"

typedef struct
{
    double xyzt[4]; // vu en TD, coordonnées homogènes
} t_point3d;

typedef struct
{
    t_point3d* abc[3];
} t_triangle3d;

//retourne un point 3D alloue et initialise avec les coordonnees x,y,z,1
t_point3d *definirPoint3d(double x, double y, double z);
//retourne un vecteur 3D alloue et initialise avec les coordonnees x,y,z,0
t_point3d *definirVecteur3d(double x, double y, double z);
//retourne un triangle 3D alloue et initialise avec les points a,b,c
t_triangle3d *definirTriangle3d(t_point3d * a, t_point3d * b, t_point3d * c);
//retourne un triangle 3D alloue initialise avec une copie des points du triangle d'origine
t_triangle3d *copierTriangle3d(t_triangle3d *t);
//libere la memoire occupee par le triangle, il faut aussi liberer les points...
void libererTriangle3d(t_triangle3d *t);

//affiche le triangle sur la surface avec la couleur passee en parametre
void remplirTriangle3d(t_surface * surface, t_triangle3d * triangle, Uint32 c);

// effectue une translation sur les points du triangle selon le vecteur donne en parametre
void translationTriangle3d(t_triangle3d *t, t_point3d *vecteur);
// effectue une rotation sur les points du triangle selon le l'angle en X, en Y et en Z
void rotationTriangle3d(t_triangle3d *t, t_point3d *centre, float degreX, float degreY, float degreZ);

// effectue une transformation arbitraire sur les points du triangle selon le vecteur donne en parametre, vous pourrez ensuite modifier les deux fonctions precedentes pour faire appel a cette fonction
void transformationTriangle3d(t_triangle3d *t, double mat[4][4]);

// affiche une matrice
void affichermatrice(double mat[4][4]);

#endif
