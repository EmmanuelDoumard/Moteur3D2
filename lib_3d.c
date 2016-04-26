#include "lib_surface.h"
#include "lib_3d.h"
#include "lib_2d.h"
#include "lib_mat.h"
#include <math.h>

typedef struct
{
  double m[4][4];
} t_matrice3d;

t_point3d *definirPoint3d(double x, double y, double z)	// attention malloc
{
  t_point3d *p;

  p  = (t_point3d*) malloc(sizeof(t_point3d));
  if (p!=NULL)
    {
      p->xyzt[0] = x;
      p->xyzt[1] = y;
      p->xyzt[2] = z;
      p->xyzt[3] = 1;
    }

  return p;
}

t_point3d *definirVecteur3d(double x, double y, double z)	// attention malloc
{
  t_point3d *p = NULL;
  p  = (t_point3d*) malloc(sizeof(t_point3d));
    if (p!=NULL)
    {
      p->xyzt[0] = x;
      p->xyzt[1] = y;
      p->xyzt[2] = z;
      p->xyzt[3] = 0;
    }

  // Fini

  return p;
}

t_triangle3d *definirTriangle3d(t_point3d * a, t_point3d * b, t_point3d * c)	// attention malloc
{
  t_triangle3d *t = NULL;
  t = (t_triangle3d*) malloc(sizeof(t_triangle3d));
  
  if (t != NULL) {
    t->abc[0]=a;
    t->abc[1]=b;
    t->abc[2]=c;
  }
  printf("a(%f,%f,%f)\nb(%f,%f,%f)\nc(%f,%f,%f)\n",a->xyzt[0],a->xyzt[1],a->xyzt[2],b->xyzt[0],b->xyzt[1],b->xyzt[2],c->xyzt[0],c->xyzt[1],c->xyzt[2]); // debug

  return t;
}

t_triangle3d *copierTriangle3d(t_triangle3d *t)
{
  t_triangle3d *n = NULL;
  // n = malloc
  // TODO

  return n;

}

void libererTriangle3d(t_triangle3d *t)
{
  // TODO
}

// effectue une conversion de 2D en 3D
t_point2d *__conversion_2d_3d(t_point3d *p3d)
{
  t_point2d *p2d;
  t_point3d *p3dtmp;
  double matrice_projection[4][4]={{1, 0, 0, 0},\
				   {0, 1, 0, 0},\
				   {0, 0, 1, 0},\
				   {0, 0, 0, 1}};


  p2d = NULL;
  p3dtmp = (t_point3d*)malloc(sizeof(t_point3d));
  if (p3dtmp!=NULL)
    {
      multiplicationVecteur3d(p3dtmp, matrice_projection, p3d);

      p2d = definirPoint2d(p3dtmp->xyzt[0]+RX/2, p3dtmp->xyzt[1]+RY/2); // malloc implicite il faut faire un free plus tard... (dans une vingtaine de lignes)
    }

  free(p3dtmp);
  return p2d;
}

void remplirTriangle3d(t_surface * surface, t_triangle3d * triangle, Uint32 c)
{
  t_point2d *p2da, *p2db, *p2dc;
  t_triangle2d *t2d;
  p2da = __conversion_2d_3d(triangle->abc[0]);
  p2db = __conversion_2d_3d(triangle->abc[1]);
  p2dc = __conversion_2d_3d(triangle->abc[2]);

  t2d = definirTriangle2d(p2da, p2db, p2dc);

  remplirTriangle2d(surface, t2d, c);

  free(t2d);
  free(p2da); // le free est fait ici :)
  free(p2db);
  free(p2dc);

}

void translationTriangle3d(t_triangle3d *t, t_point3d *vecteur)
{  
  double matrice_translation[4][4]={{1, 0, 0, vecteur->xyzt[0]},\
				   {0, 1, 0, vecteur->xyzt[1]},\
				   {0, 0, 1, vecteur->xyzt[2]},\
				   {0, 0, 0, 1}};
  
  
  transformationTriangle3d(t,matrice_translation);
}

void rotationTriangle3d(t_triangle3d *t, t_point3d *centre, float degreX, float degreY, float degreZ)
{
  double thetaZ=degreZ*M_PI/180;
  double thetaY=degreY*M_PI/180;
  double thetaX=degreX*M_PI/180;
  double matrice_rotationz[4][4]={{cos(thetaZ),-sin(thetaZ), 0, 0}, \
				  {sin(thetaZ), cos(thetaZ), 0, 0}, \
				  {0          , 0          , 1, 0},			    \
				  {0          , 0          , 0, 1}};

  double matrice_rotationy[4][4]={{cos(thetaY) , 0, sin(thetaY), 0},	\
				  {0           , 1, 0          , 0},	\
				  {-sin(thetaY), 0, cos(thetaY), 0},	\
				  {0           , 0, 0          , 1}};

  double matrice_rotationx[4][4]={{1, 0, 0, 0}, \
				  {0,cos(thetaX), -sin(thetaX), 0}, \
				  {0,sin(thetaX), cos(thetaX), 0}, \
				  {0, 0, 0, 1}};

  double matrice_translation_inverse[4][4]={{1, 0, 0, -centre->xyzt[0]},\
				   {0, 1, 0, -centre->xyzt[1]},\
				   {0, 0, 1, -centre->xyzt[2]},\
				   {0, 0, 0, 1}};

  double matrice_translation[4][4]={{1, 0, 0, centre->xyzt[0]},\
				   {0, 1, 0, centre->xyzt[1]},\
				   {0, 0, 1, centre->xyzt[2]},\
				   {0, 0, 0, 1}};
  
  transformationTriangle3d(t,matrice_translation_inverse);
  transformationTriangle3d(t,matrice_rotationz);
  transformationTriangle3d(t,matrice_rotationy);
  transformationTriangle3d(t,matrice_rotationx);
  transformationTriangle3d(t,matrice_translation);
}


void transformationTriangle3d(t_triangle3d *t, double mat[4][4])
{
  int i;
  for(i=0;i<3;i++){
    multiplicationVecteur3d(t->abc[i],mat,t->abc[i]);
  }   

}

void affichermatrice(double mat[4][4]){
  int i;
  for(i=0;i<4;i++){
    printf("%f %f %f %f\n",mat[i][0],mat[i][1],mat[i][2],mat[i][3]);
  }
}
