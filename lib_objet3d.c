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
  t_objet3d *camera=objet_vide();
  camera->est_camera=true;

  return camera;
}

t_objet3d* parallelepipede(double lx, double ly, double lz)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  double x = lx/2;
  double y = ly/2;
  double z = lz/2;


  t_point3d *p1_1 = definirPoint3d(-x,-y,z);
  t_point3d *p1_2 = definirPoint3d(x,y,z);
  t_point3d *p1_3 = definirPoint3d(x,-y,z);
  t_triangle3d *t1 = definirTriangle3d(p1_1,p1_2,p1_3);
  __insere_tete(pt_objet,__cree_maillon(t1,GRISC));
  
  t_point3d *p2_1 = definirPoint3d(-x,-y,z);
  t_point3d *p2_2 = definirPoint3d(x,-y,z);
  t_point3d *p2_3 = definirPoint3d(x,y,z);
  t_triangle3d *t2 = definirTriangle3d(p2_1,p2_2,p2_3);
  __insere_tete(pt_objet,__cree_maillon(t2,GRISF));

 
  t_point3d *p3_1 = definirPoint3d(x,-y,z);
  t_point3d *p3_2 = definirPoint3d(x,y,z);
  t_point3d *p3_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t3 = definirTriangle3d(p3_1,p3_2,p3_3);
  __insere_tete(pt_objet,__cree_maillon(t3,ROUGEC));

  
  t_point3d *p4_1 = definirPoint3d(x,-y,z);
  t_point3d *p4_2 = definirPoint3d(x,-y,-z);
  t_point3d *p4_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t4 = definirTriangle3d(p4_1,p4_2,p4_3);
  __insere_tete(pt_objet,__cree_maillon(t4,ROUGEF));

 
  t_point3d *p5_1 = definirPoint3d(-x,y,-z);
  t_point3d *p5_2 = definirPoint3d(-x,-y,-z);
  t_point3d *p5_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t5 = definirTriangle3d(p5_1,p5_2,p5_3);
  __insere_tete(pt_objet,__cree_maillon(t5,VERTC));


  t_point3d *p6_1 = definirPoint3d(-x,-y,-z);
  t_point3d *p6_2 = definirPoint3d(x,-y,-z);
  t_point3d *p6_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t6 = definirTriangle3d(p6_1,p6_2,p6_3);
  __insere_tete(pt_objet,__cree_maillon(t6,VERTF));


  t_point3d *p7_1 = definirPoint3d(-x,-y,z);
  t_point3d *p7_2 = definirPoint3d(-x,y,z);
  t_point3d *p7_3 = definirPoint3d(-x,y,-z);
  t_triangle3d *t7 = definirTriangle3d(p7_1,p7_2,p7_3);
  __insere_tete(pt_objet,__cree_maillon(t7,BLEUC));


  t_point3d *p8_1 = definirPoint3d(-x,y,-z);
  t_point3d *p8_2 = definirPoint3d(-x,-y,z);
  t_point3d *p8_3 = definirPoint3d(-x,-y,-z);
  t_triangle3d *t8 = definirTriangle3d(p8_1,p8_2,p8_3);
  __insere_tete(pt_objet,__cree_maillon(t8,BLEUF));


  t_point3d *p9_1 = definirPoint3d(-x,y,z);
  t_point3d *p9_2 = definirPoint3d(-x,y,-z);
  t_point3d *p9_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t9 = definirTriangle3d(p9_1,p9_2,p9_3);
  __insere_tete(pt_objet,__cree_maillon(t9,JAUNEC));
  

  t_point3d *p10_1 = definirPoint3d(-x,y,z);
  t_point3d *p10_2 = definirPoint3d(x,y,z);
  t_point3d *p10_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t10 = definirTriangle3d(p10_1,p10_2,p10_3);
  __insere_tete(pt_objet,__cree_maillon(t10,JAUNEF));

 
  t_point3d *p11_1 = definirPoint3d(-x,-y,z);
  t_point3d *p11_2 = definirPoint3d(x,-y,-z);
  t_point3d *p11_3 = definirPoint3d(-x,-y,-z);
  t_triangle3d *t11 = definirTriangle3d(p11_1,p11_2,p11_3);
  __insere_tete(pt_objet,__cree_maillon(t11,MARRON1));

  t_point3d *p12_1 = definirPoint3d(-x,-y,z);
  t_point3d *p12_2 = definirPoint3d(x,-y,z);
  t_point3d *p12_3 = definirPoint3d(x,-y,-z);
  t_triangle3d *t12 = definirTriangle3d(p12_1,p12_2,p12_3);
  __insere_tete(pt_objet,__cree_maillon(t12,MARRON2));


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
  t_maillon *suiv = pt_objet->tete;
  t_triangle3d *tmp_t=malloc(sizeof(t_triangle3d));
  Uint32 tmp_c;
  int nb_faces=0;
  int i,j;
  printf("coucou\n");
  while (suiv->pt_suiv != NULL) {
    printf("coucou");
    suiv = suiv->pt_suiv;
    nb_faces++;
    printf("coucou");
  }

  for (i=0;i<nb_faces;i++){
    suiv=pt_objet->tete;
    for (j=0;i<nb_faces-i;j++){
      if (avgz(suiv->face)<avgz(suiv->pt_suiv->face)){
	tmp_t=suiv->face;
	tmp_c=suiv->couleur;
	suiv->face=suiv->pt_suiv->face;
	suiv->couleur=suiv->pt_suiv->couleur;
	suiv->pt_suiv->face=tmp_t;
	suiv->pt_suiv->couleur=tmp_c;
	
	suiv=suiv->pt_suiv;	
      }
    }
  }

}

double avgz(t_triangle3d *face){
  return (face->abc[0]->xyzt[2]+face->abc[1]->xyzt[2]+face->abc[2]->xyzt[2])/3;
}

void dessinerObjet3d(t_surface *surface, t_objet3d* pt_objet)
{
  __trier_objet(pt_objet);
  t_maillon *suiv=pt_objet->tete;
  while(suiv!=NULL){
    remplirTriangle3d(surface,suiv->face,suiv->couleur);
    suiv=suiv->pt_suiv;
  }
}

void translationObjet3d(t_objet3d* pt_objet, t_point3d *vecteur)
{
  t_maillon *suiv=pt_objet->tete;
  while(suiv!=NULL){
    translationTriangle3d(suiv->face,vecteur);
    suiv=suiv->pt_suiv;
  }

}

void rotationObjet3d(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ)
{
  t_maillon *suiv=pt_objet->tete;
  while(suiv!=NULL){
    rotationTriangle3d(suiv->face,centre,degreX,degreY,degreZ);
    suiv=suiv->pt_suiv;
  }
}

void transformationObjet3d(t_objet3d* pt_objet, double mat[4][4])
{
  t_maillon *suiv=pt_objet->tete;
  while(suiv!=NULL){
    transformationTriangle3d(suiv->face,mat);
    suiv=suiv->pt_suiv;
  }
}

