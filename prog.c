#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "lib_surface.h"
#include "lib_2d.h"
#include "lib_3d.h"
#include "lib_objet3d.h"
#include "lib_scene3d.h"


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
    
  t_objet3d *camorigine=camera();

  t_objet3d *dam = damier(200, 200 , 5,5);
  t_point3d *v1=definirPoint3d(200,200,0);
  //translationObjet3d(dam,v1);
  t_objet3d *testsphere = sphere(50,12,12);
  t_objet3d *dam2= damier(100, 100, 10,10);
  //translationObjet3d(dam2,definirPoint3d(-200,-200,0));
  //rotationObjet3d(dam2,definirPoint3d(-200,-200,0),90,0,0);

  t_objet3d *sphamiga= sphere_amiga(50,12,12);
  //translationObjet3d(sphamiga,definirPoint3d(-200,0,0));

  t_objet3d *test_tore = tore(100,10,10,20);
  //translationObjet3d(test_tore,definirPoint3d(-200,200,0));

  t_objet3d *a=arbre(30,200,30);
  //translationObjet3d(a,definirPoint3d(200,0,0));

  t_scene3d *scene = definirScene3d(camorigine);
  t_scene3d *scdam = ajouter_relation(scene,dam);
  t_scene3d *scsphere = ajouter_relation(scene->pt_fils, testsphere);
  t_scene3d *sctore = ajouter_relation(scene->pt_fils, test_tore);







  t_bool quit=false;
  SDL_Event event; //variable event
  int dx=0;
  int dy=0;
  int dz=0;
  int drx=0;
  int dry=0;
  int drz=0;

#endif

  int i=0;

  surface=creerFenetre(RX,RY);
  timestart = SDL_GetTicks();


  while(i<50*10000 && !quit)
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

      /*
	if(i<250){
	dessinerObjet3d(surface,dam2);
	}
	if(i==250){
	composerObjet3d(dam,dam2);
	}

        //translationObjet3d(testsphere, vecteur);
	


	rotationObjet3d(dam,origine,1,1,0);		   
	rotationObjet3d(testsphere,origine,1,1,1);
	rotationObjet3d(sphamiga,definirPoint3d(-200,0,0),1,1,1);
	rotationObjet3d(test_tore,definirPoint3d(-200,200,0),0.5,0.5,0.5);
	rotationObjet3d(a,definirPoint3d(200,0,0),1,1,1);
	//__trier_objet(o10);                    //déjà utilisé au début de dessinerObjet3d
	
	dessinerObjet3d(surface, dam);
        dessinerObjet3d(surface, testsphere);
	dessinerObjet3d(surface, sphamiga);
	dessinerObjet3d(surface, test_tore);
	dessinerObjet3d(surface, a);

        free(vecteur);
	SDL_Delay(25);
      */
      //rotationScene3d(scdam,origine,1,1,1);
      //rotationScene3d(sctore,origine,1,1,1);
      //rotationScene3d(scsphere,origine,-1,-1,-1);


      // Outil SDL Benoit !

      
      dessinerScene3d(surface,scene);

      SDL_PollEvent(&event); //récupère la dernière entré système(souris, clavier etc...

      
      switch(event.type){
      case SDL_KEYDOWN:
	switch(event.key.keysym.sym){    
	case SDLK_KP9:
	  dy++;
	  break;
	case SDLK_KP3:
	  dy--;
	  break;
	case SDLK_KP6:
	  dx--;
	  break;
	case SDLK_KP4:
	  dx++;
	  break;
	case SDLK_KP8:
	  dz++;
	  break;
	case SDLK_KP2:
	  dz--;
	  break;
	case SDLK_a:
	  drz++;
	  break;
	case SDLK_e:
	  drz--;
	  break;
	case SDLK_q:
	  dry--;
	  break;
	case SDLK_d:
	  dry++;
	  break;
	case SDLK_z:
	  drx++;
	  break;
	case SDLK_s:
	  drx--;
	  break;      
	case SDLK_SPACE:
	  dx=0;
	  dy=0;
	  dz=0;
	  drx=0;
	  dry=0;
	  drz=0;
	  break;
	case SDLK_ESCAPE:
	  quit=true;
	}
	break;
      }    
      
      t_point3d *translation=definirPoint3d(dx,dy,dz);
      translationScene3d(scene->pt_fils,translation);      
      free(translation);

      if(drx<0)
	{    
	  rotationScene3d(scene,origine,-1,0,0);
	}
      if(dry<0)
	{
	  rotationScene3d(scene,origine,0,-1,0);
	}
      if(drz<0)
	{
	  rotationScene3d(scene,origine,0,0,-1);
	}
      if(drx>0)
	{
	  rotationScene3d(scene,origine,1,0,0);
	}
      if(dry>0)
	{
	  rotationScene3d(scene,origine,0,1,0);
	}
      if(drz>0)
	{
	  rotationScene3d(scene,origine,0,0,1);
	  }

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
