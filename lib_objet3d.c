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
  pt_objet->tete=NULL;
  pt_objet->est_trie=false;
  pt_objet->est_camera=false;

  return pt_objet;
}

t_objet3d *camera()
{
  t_objet3d *camera=objet_vide();
  camera->est_camera=true;

  return camera;
}

t_objet3d* parallelepipede(double lx, double ly, double lz, Uint32 couleur)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  double x = lx/2;
  double y = ly/2;
  double z = lz/2;


  t_point3d *p1_1 = definirPoint3d(x,-y,-z);
  t_point3d *p1_2 = definirPoint3d(x,y,-z);
  t_point3d *p1_3 = definirPoint3d(-x,-y,-z);
  t_triangle3d *t1 = definirTriangle3d(p1_1,p1_2,p1_3);
  __insere_tete(pt_objet,__cree_maillon(t1,ROUGEC));
  
  t_point3d *p2_1 = definirPoint3d(-x,y,-z);
  t_point3d *p2_2 = definirPoint3d(-x,-y,-z);
  t_point3d *p2_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t2 = definirTriangle3d(p2_1,p2_2,p2_3);
  __insere_tete(pt_objet,__cree_maillon(t2,ROUGEF));

 
  t_point3d *p3_1 = definirPoint3d(x,-y,-z);
  t_point3d *p3_2 = definirPoint3d(x,-y,z);
  t_point3d *p3_3 = definirPoint3d(x,y,z);
  t_triangle3d *t3 = definirTriangle3d(p3_1,p3_2,p3_3);
  __insere_tete(pt_objet,__cree_maillon(t3,BLEUC));

  
  t_point3d *p4_1 = definirPoint3d(x,y,z);
  t_point3d *p4_2 = definirPoint3d(x,-y,-z);
  t_point3d *p4_3 = definirPoint3d(x,y,-z);
  t_triangle3d *t4 = definirTriangle3d(p4_1,p4_2,p4_3);
  __insere_tete(pt_objet,__cree_maillon(t4,BLEUF));

 
  t_point3d *p5_1 = definirPoint3d(-x,-y,z);
  t_point3d *p5_2 = definirPoint3d(x,y,z);
  t_point3d *p5_3 = definirPoint3d(x,-y,z);
  t_triangle3d *t5 = definirTriangle3d(p5_1,p5_2,p5_3);
  __insere_tete(pt_objet,__cree_maillon(t5,JAUNEC));


  t_point3d *p6_1 = definirPoint3d(-x,-y,z);
  t_point3d *p6_2 = definirPoint3d(-x,y,z);
  t_point3d *p6_3 = definirPoint3d(x,y,z);
  t_triangle3d *t6 = definirTriangle3d(p6_1,p6_2,p6_3);
  __insere_tete(pt_objet,__cree_maillon(t6,JAUNEF));


  t_point3d *p7_1 = definirPoint3d(-x,-y,-z);
  t_point3d *p7_2 = definirPoint3d(-x,-y,z);
  t_point3d *p7_3 = definirPoint3d(-x,y,z);
  t_triangle3d *t7 = definirTriangle3d(p7_1,p7_2,p7_3);
  __insere_tete(pt_objet,__cree_maillon(t7,VERTC));


  t_point3d *p8_1 = definirPoint3d(-x,y,-z);
  t_point3d *p8_2 = definirPoint3d(-x,-y,-z);
  t_point3d *p8_3 = definirPoint3d(-x,y,z);
  t_triangle3d *t8 = definirTriangle3d(p8_1,p8_2,p8_3);
  __insere_tete(pt_objet,__cree_maillon(t8,VERTF));


  t_point3d *p9_1 = definirPoint3d(-x,y,-z);
  t_point3d *p9_2 = definirPoint3d(x,y,-z);
  t_point3d *p9_3 = definirPoint3d(x,y,z);
  t_triangle3d *t9 = definirTriangle3d(p9_1,p9_2,p9_3);
  __insere_tete(pt_objet,__cree_maillon(t9,GRISC));
  

  t_point3d *p10_1 = definirPoint3d(-x,y,-z);
  t_point3d *p10_2 = definirPoint3d(-x,y,z);
  t_point3d *p10_3 = definirPoint3d(x,y,z);
  t_triangle3d *t10 = definirTriangle3d(p10_1,p10_2,p10_3);
  __insere_tete(pt_objet,__cree_maillon(t10,GRISF));

 
  t_point3d *p11_1 = definirPoint3d(-x,-y,-z);
  t_point3d *p11_2 = definirPoint3d(x,-y,z);
  t_point3d *p11_3 = definirPoint3d(x,-y,-z);
  t_triangle3d *t11 = definirTriangle3d(p11_1,p11_2,p11_3);
  __insere_tete(pt_objet,__cree_maillon(t11,MARRON1));

  t_point3d *p12_1 = definirPoint3d(-x,-y,-z);
  t_point3d *p12_2 = definirPoint3d(-x,-y,z);
  t_point3d *p12_3 = definirPoint3d(x,-y,z);
  t_triangle3d *t12 = definirTriangle3d(p12_1,p12_2,p12_3);
  __insere_tete(pt_objet,__cree_maillon(t12,MARRON2));

  return pt_objet;
}

t_objet3d* sphere(double r, double nlat, double nlong,Uint32 couleur1,Uint32 couleur2)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  int i,j;
  double h1,h2;

  t_point3d *p1 = malloc(sizeof(t_point3d));
  t_point3d *p2 = malloc(sizeof(t_point3d));
  t_point3d *p3 = malloc(sizeof(t_point3d));
  t_triangle3d *t1 = malloc(sizeof(t_triangle3d));

  h1=r*(1-2/nlat);
  for(i=0;i<nlong;i++){

    p1=definirPoint3d(0,r,0);
    p2=definirPoint3d(r*cos(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
    p3=definirPoint3d(r*cos((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));

    t1 = definirTriangle3d(p1,p2,p3);
    __insere_tete(pt_objet,__cree_maillon(t1,couleur1));
  }

  for(i=1;i<nlat-1;i++){
    h1=r*(1-2*i/nlat);
    h2=r*(1-2*(i+1)/nlat);
    for(j=0;j<nlong;j++){
      p1=definirPoint3d(r*cos(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
      p2=definirPoint3d(r*cos(j*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)),h2,r*sin(j*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)));
      p3=definirPoint3d(r*cos((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)),h2,r*sin((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)));
      t1 = definirTriangle3d(p1,p2,p3);
      __insere_tete(pt_objet,__cree_maillon(t1,couleur1));

      p1=definirPoint3d(r*cos(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
      p2=definirPoint3d(r*cos((j+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin((j+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
      p3=definirPoint3d(r*cos((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)),h2,r*sin((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)));
      t1 = definirTriangle3d(p1,p2,p3);
      __insere_tete(pt_objet,__cree_maillon(t1,couleur2));
    }
  } 

  h1=r*(1-2/nlat);
  for(i=0;i<nlong;i++){

    p1=definirPoint3d(0,-r,0);
    p2=definirPoint3d(r*cos(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),-h1,r*sin(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
    p3=definirPoint3d(r*cos((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),-h1,r*sin((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
    t1 = definirTriangle3d(p1,p2,p3);
    __insere_tete(pt_objet,__cree_maillon(t1,couleur1));
  }

  return pt_objet;
}

t_objet3d* sphere_amiga(double r, double nlat, double nlong)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();


  int i,j;
  double h1,h2;

  t_point3d *p1 = malloc(sizeof(t_point3d));
  t_point3d *p2 = malloc(sizeof(t_point3d));
  t_point3d *p3 = malloc(sizeof(t_point3d));
  t_triangle3d *t1 = malloc(sizeof(t_triangle3d));

  h1=r*(1-2/nlat);
  for(i=0;i<nlong;i++){

    p1=definirPoint3d(0,r,0);
    p2=definirPoint3d(r*cos(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
    p3=definirPoint3d(r*cos((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));

    t1 = definirTriangle3d(p1,p2,p3);

    if((i+j)%2==0){
      __insere_tete(pt_objet,__cree_maillon(t1,BLANC));
    }
    else{
      __insere_tete(pt_objet,__cree_maillon(t1,ROUGEF));
    }

  }

  for(i=1;i<nlat-1;i++){
    h1=r*(1-2*i/nlat);
    h2=r*(1-2*(i+1)/nlat);
    for(j=0;j<nlong;j++){
      p1=definirPoint3d(r*cos(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
      p2=definirPoint3d(r*cos(j*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)),h2,r*sin(j*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)));
      p3=definirPoint3d(r*cos((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)),h2,r*sin((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)));
      t1 = definirTriangle3d(p1,p2,p3);

      if((i+j)%2==0){
	__insere_tete(pt_objet,__cree_maillon(t1,BLANC));
      }
      else{
	__insere_tete(pt_objet,__cree_maillon(t1,ROUGEF));
      }

      p1=definirPoint3d(r*cos(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin(j*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
      p2=definirPoint3d(r*cos((j+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),h1,r*sin((j+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
      p3=definirPoint3d(r*cos((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)),h2,r*sin((j+1)*2*M_PI/nlong)*sqrt(1-(h2*h2)/(r*r)));
      t1 = definirTriangle3d(p1,p2,p3);

      if((i+j)%2==0){
	__insere_tete(pt_objet,__cree_maillon(t1,BLANC));
      }
      else{
	__insere_tete(pt_objet,__cree_maillon(t1,ROUGEF));
      }

    }
  } 

  h1=r*(1-2/nlat);
  for(i=0;i<nlong;i++){

    p1=definirPoint3d(0,-r,0);
    p2=definirPoint3d(r*cos(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),-h1,r*sin(i*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
    p3=definirPoint3d(r*cos((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)),-h1,r*sin((i+1)*2*M_PI/nlong)*sqrt(1-(h1*h1)/(r*r)));
    t1 = definirTriangle3d(p1,p2,p3);

    if((i+j+1)%2==0){
      __insere_tete(pt_objet,__cree_maillon(t1,BLANC));
    }
    else{
      __insere_tete(pt_objet,__cree_maillon(t1,ROUGEF));
    }
  }

  return pt_objet;
}

t_objet3d* tore(double r1,double r2, double nlat, double nlong)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  int i,j;

  t_point3d *p1 = malloc(sizeof(t_point3d));
  t_point3d *p2 = malloc(sizeof(t_point3d));
  t_point3d *p3 = malloc(sizeof(t_point3d));
  t_triangle3d *t1 = malloc(sizeof(t_triangle3d));

  for(i=0;i<nlat;i++){
    for(j=0;j<nlong;j++){

      // (i,j),(i,j+1),(i+1,j+1)
      p1=definirPoint3d((r1+r2*cos(i*2*M_PI/nlat))*sin(j*2*M_PI/nlong),
			r2*sin(i*2*M_PI/nlat),
			(r1+r2*cos(i*2*M_PI/nlat))*cos(j*2*M_PI/nlong));

      p2=definirPoint3d((r1+r2*cos(i*2*M_PI/nlat))*sin((j+1)*2*M_PI/nlong),
			r2*sin(i*2*M_PI/nlat),
			(r1+r2*cos(i*2*M_PI/nlat))*cos((j+1)*2*M_PI/nlong));

      p3=definirPoint3d((r1+r2*cos((i+1)*2*M_PI/nlat))*sin((j+1)*2*M_PI/nlong),
			r2*sin((i+1)*2*M_PI/nlat),
			(r1+r2*cos((i+1)*2*M_PI/nlat))*cos((j+1)*2*M_PI/nlong));

      t1 = definirTriangle3d(p1,p2,p3);

      __insere_tete(pt_objet,__cree_maillon(t1,BLANC));

      // (i,j),(i+1,j),(i+1,j+1)
      p1=definirPoint3d((r1+r2*cos(i*2*M_PI/nlat))*sin(j*2*M_PI/nlong),
			r2*sin(i*2*M_PI/nlat),
			(r1+r2*cos(i*2*M_PI/nlat))*cos(j*2*M_PI/nlong));

      p2=definirPoint3d((r1+r2*cos((i+1)*2*M_PI/nlat))*sin(j*2*M_PI/nlong),
			r2*sin((i+1)*2*M_PI/nlat),
			(r1+r2*cos((i+1)*2*M_PI/nlat))*cos(j*2*M_PI/nlong));

      p3=definirPoint3d((r1+r2*cos((i+1)*2*M_PI/nlat))*sin((j+1)*2*M_PI/nlong),
			r2*sin((i+1)*2*M_PI/nlat),
			(r1+r2*cos((i+1)*2*M_PI/nlat))*cos((j+1)*2*M_PI/nlong));
      t1 = definirTriangle3d(p1,p2,p3);

      __insere_tete(pt_objet,__cree_maillon(t1,ROUGEF));
    }
  } 
  return pt_objet;
}


t_objet3d* pyramide(double lx, double ly, double lz, Uint32 couleur) //pyramide avec comme base un rectangle de taille (lx,lz) et de hauteur ly centré sur (0,0,0);
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();

  double x = lx/2;
  double y = ly/2;
  double z = lz/2;


  t_point3d *p1= definirPoint3d(-x,-y,-z);
  t_point3d *p2 = definirPoint3d(x,-y,-z);
  t_point3d *p3 = definirPoint3d(x,-y,z);
  t_triangle3d *t = definirTriangle3d(p1,p2,p3);
  __insere_tete(pt_objet,__cree_maillon(t,couleur));
  

  p1 = definirPoint3d(-x,-y,-z);
  p2 = definirPoint3d(-x,-y,z);
  p3 = definirPoint3d(x,-y,z);
  t = definirTriangle3d(p1,p2,p3);
  __insere_tete(pt_objet,__cree_maillon(t,couleur+20));


  p1 = definirPoint3d(-x,-y,-z);
  p2 = definirPoint3d(-x,-y,z);
  p3 = definirPoint3d(0,y,0);
  t = definirTriangle3d(p1,p2,p3);
  __insere_tete(pt_objet,__cree_maillon(t,couleur+40));
 
  p1 = definirPoint3d(-x,-y,-z);
  p2 = definirPoint3d(x,-y,-z);
  p3 = definirPoint3d(0,y,0);
  t = definirTriangle3d(p1,p2,p3);
  __insere_tete(pt_objet,__cree_maillon(t,couleur+60));
  
  p1 = definirPoint3d(-x,-y,z);
  p2 = definirPoint3d(x,-y,z);
  p3 = definirPoint3d(0,y,0);
  t = definirTriangle3d(p1,p2,p3);
  __insere_tete(pt_objet,__cree_maillon(t,couleur+80));
 
   
  p1 = definirPoint3d(x,-y,-z);
  p2 = definirPoint3d(x,-y,z);
  p3 = definirPoint3d(0,y,0);
  t = definirTriangle3d(p1,p2,p3);
  __insere_tete(pt_objet,__cree_maillon(t,couleur+100));
 

  return pt_objet;

}

t_objet3d* arbre(double lx, double ly, double lz)
{

  t_objet3d *tronc=parallelepipede(lx,ly/2,lz,MARRON1);
  translationObjet3d(tronc,definirPoint3d(0,ly/4,0));
  
  t_objet3d *feuillage=pyramide(2*lx,ly/2,2*lz,VERTC);
  rotationObjet3d(feuillage,definirPoint3d(0,0,0),180,0,0);
  translationObjet3d(feuillage,definirPoint3d(0,-ly/4,0));

  composerObjet3d(tronc,feuillage);

  return tronc;

}

t_objet3d* damier(double lx, double lz, double nx, double nz)
{
  t_objet3d *pt_objet = NULL;

  pt_objet = objet_vide();
  
  int i,j;

  t_point3d *p1 = malloc(sizeof(t_point3d));
  t_point3d *p2 = malloc(sizeof(t_point3d));
  t_point3d *p3 = malloc(sizeof(t_point3d));

  for (i=-nx/2;i<nx/2+((int)nx/2)%2-1;i++) {
    for (j=-nz/2;j<nz/2+((int)nz/2)%2-1;j++) {
      p1=definirPoint3d(j*lx/nx,0,i*lz/nz);
      p2=definirPoint3d((j+1)*lx/nx,0,i*lz/nz);
      p3=definirPoint3d((j+1)*lx/nx,0,(i+1)*lz/nz);

      if ((i+j)%2==0) {
      __insere_tete(pt_objet,__cree_maillon(definirTriangle3d(p1,p2,p3),BLANC));
      }
      else {
	__insere_tete(pt_objet,__cree_maillon(definirTriangle3d(p1,p2,p3),NOIR));
      }

      p1=definirPoint3d(j*lx/nx,0,i*lz/nz);
      p2=definirPoint3d(j*lx/nx,0,(i+1)*lz/nz);
      p3=definirPoint3d((j+1)*lx/nx,0,(i+1)*lz/nz);

      if ((i+j)%2==0) {
      __insere_tete(pt_objet,__cree_maillon(definirTriangle3d(p1,p2,p3),BLANC));
      }
      else {
	__insere_tete(pt_objet,__cree_maillon(definirTriangle3d(p1,p2,p3),NOIR));
      }
    }
  }


  return pt_objet;

}

t_objet3d *copierObjet3d(t_objet3d *o) // attention, effectue une copie mirroir
{
  t_objet3d *n = objet_vide();
  
  t_maillon *m = o->tete;
  
  t_maillon *pt_maillon=NULL;
  while(m != NULL){

    pt_maillon=copierMaillon(m);

    __insere_tete(n,pt_maillon);

    m=m->pt_suiv;
  }
  return n;
}


t_maillon *copierMaillon(t_maillon *maillon){
  t_maillon *res=malloc(sizeof(t_maillon));
  
  res->face=copierTriangle3d(maillon->face);
  res->couleur=maillon->couleur;

  return res;

}


void composerObjet3d(t_objet3d* o, t_objet3d* o2) /* o = o+o2, o2 ne signifiera plus rien */
{
  if(!(o==NULL | o2==NULL)){
    t_maillon *tmp;
    t_maillon *suiv = o2->tete;
    while(suiv != NULL){
      tmp=suiv->pt_suiv;
      __insere_tete(o,suiv);
      suiv=tmp;
    }
  }
}

void libererMaillon(t_maillon *m)
{
  if(m!=NULL){
    libererMaillon(m->pt_suiv);
    libererTriangle3d(m->face);
    free(m);
  }
}
void libererObjet3d(t_objet3d *o)
{
  if(o!=NULL){
    libererMaillon(o->tete);
    free(o);
  }
}

//effectue un tri des faces de l'objet dans l'ordre des z decroissants => cf algorithme du peintre
/*void __trier_objet(t_objet3d *pt_objet)
{
  t_maillon *suiv = pt_objet->tete;
  t_triangle3d *tmp_t=malloc(sizeof(t_triangle3d));
  Uint32 tmp_c;
  int nb_faces=0;
  int i,j;
  while (suiv != NULL) {
    suiv = suiv->pt_suiv;
    nb_faces++;
  }


  for (i=0;i<nb_faces;i++){
    suiv=pt_objet->tete;
    for (j=0;j<nb_faces-i-1;j++){
      //printf("avgz(suiv->face)=%f ; avgz(suiv->pt_suiv->face)=%f\n",avgz(suiv->face),avgz(suiv->pt_suiv->face));
      if (avgz(suiv->face)<avgz(suiv->pt_suiv->face)){
	//printf("Reagencement...\n");
	tmp_t=suiv->face;
	tmp_c=suiv->couleur;
	suiv->face=suiv->pt_suiv->face;
	suiv->couleur=suiv->pt_suiv->couleur;
	suiv->pt_suiv->face=tmp_t;
	suiv->pt_suiv->couleur=tmp_c;
		
      }

      suiv=suiv->pt_suiv;
    }
  }
  suiv=pt_objet->tete;
  }*/

//version bugée à corriger
void __trier_objet(t_objet3d *pt_objet)
{
  t_bool chg=true;
  while(chg){
    chg=false;
    //affichaine(pt_objet->tete);
    //printf("\n");
    pt_objet->tete=trichaine(pt_objet->tete,&chg);
  }
} 

t_maillon* trichaine(t_maillon *m, t_bool *chg)
{
  t_maillon *tmp;
  if(m->pt_suiv!=NULL){
    //printf("coucou\n");
    m->pt_suiv=trichaine(m->pt_suiv,chg);
    if(avgz(m->face)>avgz(m->pt_suiv->face)){
      *chg=true;

      //echange
      tmp=m->pt_suiv;
      m->pt_suiv=m->pt_suiv->pt_suiv;
      tmp->pt_suiv=m;
      m=tmp;

    }
  } 
  return m;
}
 
void affichaine(t_maillon *m){
  printf("%f     ",avgz(m->face));
  if(m->pt_suiv !=NULL){
    affichaine(m->pt_suiv);
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

