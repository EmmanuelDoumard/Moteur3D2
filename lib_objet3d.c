#include <assert.h>
#include <math.h>
#include "lib_3d.h"
#include "lib_objet3d.h"
#include "lib_mat.h"
#include "lib_surface.h"


// cree un nouveau maillon, cf cours algo
t_maillon* __cree_maillon(t_triangle3d *face, Uint32 couleur)
{
  t_maillon* pt_maillon = NULL;
  pt_maillon = malloc(sizeof(t_maillon));

  pt_maillon->face = face;
  pt_maillon->couleur = couleur;
  pt_maillon->pt_suiv = NULL;

  return pt_maillon;
}

// insere en tete le maillon, cf cours algo
void __insere_tete(t_objet3d *pt_objet, t_maillon *pt_maillon)
{
  pt_maillon->pt_suiv=pt_objet->tete;
  pt_objet->tete=pt_maillon;

}

t_objet3d *objet_vide()
{
  t_objet3d *pt_objet = NULL;
  pt_objet = malloc(sizeof(t_objet3d));

  return pt_objet;
}

t_objet3d *camera()
{
  t_objet3d camera=objet_vide();
  camera->est_camera=true;

  return camera;
}

t_objet3d* parallelepipede(double lx, double ly, double lz)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();
  // TODO


  return pt_objet;
}

t_objet3d* sphere(double r, double nlat, double nlong)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  // TODO

  return pt_objet;
}

t_objet3d* sphere_amiga(double r, double nlat, double nlong)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  // TODO


  return pt_objet;
}

t_objet3d* arbre(double lx, double ly, double lz)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();
  // TODO

  return pt_objet;

}

t_objet3d* damier(double lx, double lz, double nx, double nz)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  // TODO

  return pt_objet;

}

t_objet3d *copierObjet3d(t_objet3d *o) // attention, effectue une copie mirroir
{
  t_objet3d *n = objet_vide();

  // TODO

  return n;
}

void composerObjet3d(t_objet3d* o, t_objet3d* o2) /* o = o+o2, o2 ne signifiera plus rien */
{

  // TODO

}

void libererObjet3d(t_objet3d *o)
{
  // TODO

}

//effectue un tri des faces de l'objet dans l'ordre des z decroissants => cf algorithme du peintre
void __trier_objet(t_objet3d *pt_objet)
{
  // TODO

}

void dessinerObjet3d(t_surface *surface, t_objet3d* pt_objet)
{
  // TODO

}

void translationObjet3d(t_objet3d* pt_objet, t_point3d *vecteur)
{
  // TODO

}

void rotationObjet3d(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ)
{
  // TODO

}

void transformationObjet3d(t_objet3d* pt_objet, double mat[4][4])
{
  // TODO

}

