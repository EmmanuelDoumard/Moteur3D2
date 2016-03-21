#ifndef LIB_MAT_H_
#define LIB_MAT_H_

// effectue la multiplication vectorielle : v1 = m*v2
void multiplicationVecteur3d(t_point3d *v1, double m[4][4], t_point3d *v2);
// effectue la multiplication matricielle : m1 = m2*m3
void multiplicationMatrice3d(double m1[4][4], double m2[4][4], double m3[4][4]);
// effectue une copie de matrices : m1 = m2
void copierMatrice3d(double m1[4][4], double m2[4][4]);

#endif
