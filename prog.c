#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "lib_surface.h"
#include "lib_2d.h"
#include "lib_3d.h"
#include "lib_objet3d.h"

//#define T2D
//#define T3D
#define O3D

int main(int argc,char** argv)
{
    t_surface *surface=NULL;
    int cpt = 0;
    int timestart;
    char buf[50];

#ifdef T2D
    t_point2d *p1 = definirPoint2d(10,50), *p2 = definirPoint2d(100,240), *p3 = definirPoint2d(50,300);
    t_triangle2d *t1 = definirTriangle2d(p1, p2, p3);
#endif
#ifdef T3D
    t_point3d *p10 = definirPoint3d(100,50,80), *p20 = definirPoint3d(100,240,100), *p30 = definirPoint3d(50,300,100);
    t_triangle3d *t10 = definirTriangle3d(p10, p20, p30);
    t_point3d *v10 = definirVecteur3d(1,1,1);
#endif
#ifdef O3D
    t_point3d *origine = definirPoint3d(0,0,0), *vecteur;
    t_objet3d *o10 = parallelepipede(100, 250, 500);
    rotationObjet3d(o10, origine, 90, 0,0);
#endif

    int i=0;

    surface=creerFenetre(RX,RY);
    timestart = SDL_GetTicks();


    while(i<75*10)
    {
        effacerFenetre(surface, 0);

#ifdef T2D
/*
 * etape 1 : ce n'est qu'un exemple... il faut desactiver le define T2D pour la suite
 */
        remplirTriangle2d(surface, t1, echelle_de_couleur(30*i));
        SDL_Delay(500);

#endif
#ifdef T3D
/*
 * etape 2 : ecrire le corps des fonctions de lib_mat.c et lib_3d.c
 * - commencer par definirTriangle3d et rotationTriangle3d
 * - tester en activant le define T3D
 * - terminer avec les autres fonctions
 */

	translationTriangle3d(t10,v10);

        rotationTriangle3d(t10, p10, 0, 10, 0); // rotation d'axe Y
	

        remplirTriangle3d(surface, t10, echelle_de_couleur(30*i));
	SDL_Delay(25);
	
#endif
#ifdef O3D
/*
 * etape 3 : ecrire le corps des fonctions de lib_objet3d.c
 * - commencer par la definition d'un objet simple (parallelepipede) et l'affichage,
 * - continuer par les transformations
 * - finir par le tri des faces d'un objet et la composition des objets
 */
        vecteur = definirPoint3d(sin(i*M_PI/180),cos(i*M_PI/180),0);
	printf("coucou\n");
        translationObjet3d(o10, vecteur);
	rotationObjet3d(o10,origine,1,1,1);
	__trier_objet(o10);
        //dessinerObjet3d(surface, o10);
	printf("coucou\n");
        free(vecteur);
	SDL_Delay(25);
#endif

        majEcran(surface);

        i += 1;

        cpt++;
        sprintf(buf,"%d FPS",(int)(cpt*1000.0/(SDL_GetTicks()-timestart)));
        SDL_WM_SetCaption(buf,NULL);
    }
    SDL_Quit();
    return 0;
}
