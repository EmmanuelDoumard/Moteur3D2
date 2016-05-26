#ifndef LIB_SCENE3D_H_
#define LIB_SCENE3D_H_

#include "lib_surface.h"
#include "lib_3d.h"
#include "lib_objet3d.h"

typedef struct __scene3d t_scene3d;

struct __scene3d
{
    t_objet3d *objet;
    double descendant[4][4];
  double montant[4][4]; // Ne pas se préoccuper, sert pour le chgt de caméra
    t_scene3d *pt_pere; // liste chainee de noeud
    t_scene3d *pt_fils; // descendants
    t_scene3d *pt_suiv; // liste chainee de noeud
};

t_scene3d* definirScene3d(t_objet3d *pt_objet);
t_scene3d* ajouter_relation(t_scene3d* pt_noeud, t_objet3d *pt_objet); // ajout de l'objet en tete des fils
void translationScene3d(t_scene3d *pt_scene, t_point3d *vecteur);
void rotationScene3d(t_scene3d *pt_scene, t_point3d *centre, float degreX, float degreY, float degreZ);
void dessinerScene3d(t_surface *surface, t_scene3d* pt_scene);
//void changerCamera(t_scene3d *pt_objet); // modifie l'arbre de la scene pour que pt_objet en soit la racine, pt_racine ne veut plus rien dire
void dessinerScene3drec(t_surface *surface,t_scene3d* pt_racine,double mat[4][4],double matinv[4][4]);

#endif /* LIB_SCENE3D_H_ */
