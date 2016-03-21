#include "lib_3d.h"
#include "lib_mat.h"

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
  //int i, j;

  // TODO
}
