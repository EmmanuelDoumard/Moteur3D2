#include "lib_3d.h"
#include "lib_mat.h"
#include <math.h>


void multiplicationVecteur3d(t_point3d *v1, double m[4][4], t_point3d *v2) // v1 = m*v2
{
  int i, j;
  double tmp;
  double vtmp[4];
  for(i=0;i<4;i++){
    tmp=0;
    for(j=0;j<4;j++){
      tmp+=m[i][j]*v2->xyzt[j];
    }
    vtmp[i]=tmp; // On passe par un tableau temporaire au cas où on utilise la meme variable pour v1 et v2
  }
  for(i=0;i<4;i++){ // On recopie le tableau temporaire dans v1
    v1->xyzt[i]=vtmp[i];
  }
}

void multiplicationMatrice3d(double m1[4][4], double m2[4][4], double m3[4][4]) // m1 = m2*m3
{
  int i, j, k;
  double tmp;
  double mtmp[4][4];
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      tmp=0;
      for(k=0;k<4;k++){
	tmp+=m2[i][k]*m3[k][j];
      }
      mtmp[i][j]=tmp; // Meme chose que pour vecteur*matrice
    }
  }
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      m1[i][j]=mtmp[i][j];
    }
  }
}

void copierMatrice3d(double m1[4][4], double m2[4][4]) // m1 = m2
{
  int i, j;

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      m1[i][j]=m2[i][j];
    }
  }
}

void translationMatrice(double m[4][4], t_point3d *vecteur)
{
  m[0][0]=1;
  m[0][1]=0;
  m[0][2]=0;
  m[0][3]=vecteur->xyzt[0];
  m[1][0]=0;
  m[1][1]=1;
  m[1][2]=0;
  m[1][3]=vecteur->xyzt[1];
  m[2][0]=0;
  m[2][1]=0;
  m[2][2]=1;
  m[2][3]=vecteur->xyzt[2];
  m[3][0]=0;
  m[3][1]=0;
  m[3][2]=0;
  m[3][3]=1;
}

void translationMatriceInverse(double m[4][4], t_point3d *vecteur)
{
m[0][0]=1;
m[0][1]=0;
  m[0][2]=0;
  m[0][3]=-vecteur->xyzt[0];
  m[1][0]=0;
  m[1][1]=1;
  m[1][2]=0;
  m[1][3]=-vecteur->xyzt[1];
  m[2][0]=0;
  m[2][1]=0;
  m[2][2]=1;
  m[2][3]=-vecteur->xyzt[2];
  m[3][0]=0;
  m[3][1]=0;
  m[3][2]=0;
  m[3][3]=1;
}

void rotationMatrice(double m[4][4],t_point3d *centre, float degreX, float degreY, float degreZ)
{
  double thetaZ=degreZ*M_PI/180;
  double thetaY=degreY*M_PI/180;
  double thetaX=degreX*M_PI/180;

  double tmp[4][4];

  double matrice_rotationz[4][4]={{cos(thetaZ),-sin(thetaZ), 0, 0}, \
				  {sin(thetaZ), cos(thetaZ), 0, 0}, \
				  {0          , 0          , 1, 0}, \
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


  multiplicationMatrice3d(tmp,matrice_translation_inverse,matrice_rotationz);
  multiplicationMatrice3d(tmp,matrice_rotationy,tmp);
  multiplicationMatrice3d(tmp,matrice_rotationz,tmp);
  multiplicationMatrice3d(tmp,matrice_translation_inverse,tmp);
  copierMatrice3d(m,tmp);
}
