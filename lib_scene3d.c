#include <assert.h>
#include <math.h>
#include "lib_3d.h"
#include "lib_objet3d.h"
#include "lib_mat.h"
#include "lib_surface.h"
#include "lib_scene3d.h"

#define MATRICE_IDENTITE (double[4][4]){{1., 0., 0., 0.},{0., 1., 0., 0.},{0., 0., 1., 0.},{0., 0., 0., 1.}}

t_scene3d* definirScene3d(t_objet3d *pt_objet)
{
	t_scene3d* pt_maillon;

        pt_maillon = (t_scene3d*) malloc(sizeof(t_scene3d));

	pt_maillon->objet=pt_objet;
	pt_maillon->pt_pere=NULL;
	pt_maillon->pt_fils=NULL;
	pt_maillon->pt_suiv=NULL;
        copierMatrice3d(pt_maillon->descendant,MATRICE_IDENTITE);
	copierMatrice3d(pt_maillon->montant,MATRICE_IDENTITE);

	return pt_maillon;
}

t_scene3d* ajouter_relation(t_scene3d* pt_noeud, t_objet3d *pt_objet) // ajout de l'objet en tete des fils
{
	t_scene3d* pt_maillon = definirScene3d(pt_objet);

	if (pt_maillon!=NULL)
	{
		pt_maillon->pt_pere = pt_noeud;
		pt_maillon->pt_suiv = pt_noeud->pt_fils;
		pt_noeud->pt_fils = pt_maillon;
	}

	return pt_maillon; // on retourne le lien vers la nouvelle sous scene
}

void translationScene3d(t_scene3d *pt_scene, t_point3d *vecteur)
{
  double mat[4][4];
  double matinv[4][4];
  translationMatrice(mat,vecteur);
  translationMatriceInverse(matinv,vecteur);
  multiplicationMatrice3d(pt_scene->descendant,mat,pt_scene->descendant);
  multiplicationMatrice3d(pt_scene->montant,pt_scene->montant,matinv);
}
  

void rotationScene3d(t_scene3d *pt_scene, t_point3d *centre, float degreX, float degreY, float degreZ)
{
  double mat[4][4];
  double matinv[4][4];

  rotationMatrice(mat,centre,degreX,degreY,degreZ);
  rotationMatrice(matinv,centre,-degreX,-degreY,-degreZ);

  multiplicationMatrice3d(pt_scene->descendant,mat,pt_scene->descendant);
  multiplicationMatrice3d(pt_scene->montant,pt_scene->montant,matinv);
}


void dessinerScene3d(t_surface *surface, t_scene3d* pt_racine)
{
  t_objet3d* scene=objet_vide();
  dessinerScene3drec(surface,pt_racine,MATRICE_IDENTITE,MATRICE_IDENTITE,scene);
  dessinerObjet3d(surface,scene);
  libererObjet3d(scene);
  //printf("bula\n");
}

void dessinerScene3drec(t_surface *surface, t_scene3d* pt_racine,double mat[4][4],double matinv[4][4], t_objet3d *objtmp)
{
  if (pt_racine!=NULL){
    double mattmp[4][4];
    double mattmpinv[4][4];

    t_objet3d* tmp;

    multiplicationMatrice3d(mattmp,mat,pt_racine->descendant);
    multiplicationMatrice3d(mattmpinv,pt_racine->montant,matinv);

    /*printf("matrice descendante :\n");
    affichermatrice(pt_racine->descendant);
    printf("matrice montante : \n");
    affichermatrice(pt_racine->montant);*/

    transformationObjet3d(pt_racine->objet,mattmp);
    tmp=copierObjet3d(pt_racine->objet);
    composerObjet3d(objtmp,tmp);
    transformationObjet3d(pt_racine->objet,mattmpinv);
  
    dessinerScene3drec(surface,pt_racine->pt_suiv,mat,matinv,objtmp);
    dessinerScene3drec(surface,pt_racine->pt_fils,mattmp,mattmpinv,objtmp);
  }
}



/*
 * // il faut multiplier mes matrices \E0 celles du p\E8re pour inverser la relation
  copier_matrice(m, pt_pere->descendant);
  multiplication_matrice(pt_pere->descendant, pt_objet->montant, m);
  copier_matrice(m, pt_pere->montant);
  multiplication_matrice(pt_pere->montant, pt_objet->descendant, m);
*/

void changerCamera(t_scene3d *pt_objet) // modifie l'arbre de la scene pour que pt_objet en soit la racine, pt_racine ne veut plus rien dire
{

  //TODO
}
