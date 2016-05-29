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

  t_objet3d *soleil=sphere(80,12,12,ROUGEC,ROUGEF);

  t_objet3d *saturne=sphere(30,10,10,MARRON1,MARRON2);
  t_point3d *centreSaturne=definirPoint3d(0,0,0);
  //translationObjet3d(saturne,centreSaturne);

  t_objet3d *uranus=sphere(30,10,10,BLEUC,BLEUC);
  t_point3d *centreUranus=definirPoint3d(0,0,0);
  //translationObjet3d(uranus,centreUranus);

  t_objet3d *terre=sphere(15,8,8,BLEUC,BLEUF);
  t_point3d *centreTerre=definirPoint3d(0,0,0);
  //translationObjet3d(terre,centreTerre);

  t_objet3d *lune=sphere(6,6,6,GRISC,GRISF);
  t_point3d *centreLune=definirPoint3d(0,0,0);
  //translationObjet3d(lune,centreLune);

  t_objet3d *anneauS=tore(40,3,3,16);

  //translationObjet3d(anneauS,centreSaturne);

  t_objet3d *anneauU=tore(40,2,3,16);

  //translationObjet3d(anneauU,centreUranus);


  t_scene3d *scene = definirScene3d(camorigine);

  t_point3d* centreSoleil=origine;

  t_scene3d *scsol = ajouter_relation(scene,soleil);
  t_scene3d *scsat = ajouter_relation(scsol,saturne);
  t_scene3d *scanneau1 = ajouter_relation(scsat, anneauS);
  t_scene3d *scura = ajouter_relation(scsol,uranus);
  t_scene3d *scanneauU=ajouter_relation(scura,anneauU);
  t_scene3d *scterre=ajouter_relation(scsol,terre);
  t_scene3d *sclune=ajouter_relation(scterre,lune);


  vecteur=definirPoint3d(150,0,0);
  translationScene3d(scterre,vecteur);
  free(vecteur);

  vecteur=definirPoint3d(250,0,0);
  translationScene3d(scsat,vecteur);
  free(vecteur);

  vecteur=definirPoint3d(320,0,0);
  translationScene3d(scura,vecteur);
  free(vecteur);

  vecteur=definirPoint3d(40,0,0);
  translationScene3d(sclune,vecteur);
  free(vecteur);


  rotationScene3d(scanneauU,centreUranus,0,0,90);
  





  t_bool quit=false;
  SDL_Event event; //variable event
  float dx=0;
  float dy=0;
  float dz=0;
  float drx=0;
  float dry=0;
  float drz=0;

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


      // Outil SDL Benoit !

      //rotationObjet3d(soleil,origine,0,1,0);
      //dessinerObjet3d(surface,soleil);
      //printf("coucou\n");
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
      
      multiplicationVecteur3d(centreSaturne,origine,scsat->descendant);
      multiplicationVecteur3d(centreUranus,origine,scura->descendant);
      multiplicationVecteur3d(centreTerre,origine,scterre->descendant);
      multiplicationVecteur3d(centreLune,origine,sclune->descendant);
      
      
      rotationScene3d(scsol,origine,0,0.2,0);
      rotationScene3d(scsat,origine,0,0.5,0);
      rotationScene3d(scterre,origine,0,1,0);
      rotationScene3d(sclune,centreLune,0,-3,0);
      rotationScene3d(scanneauU,origine,5,0,0);
      rotationScene3d(scura,origine,0,0.3,0);
      
      /*
      rotationScene3d(sclune,origine,0,-3,0);      
      rotationScene3d(scterre,centreTerre,0,1,0);
      rotationScene3d(scsat,centreSaturne,0,0.5,0);
      rotationScene3d(scura,centreUranus,0,0.3,0);
      */
      
      

      
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
