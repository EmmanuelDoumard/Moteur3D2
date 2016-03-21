#include "lib_surface.h"
#include "lib_2d.h"


t_point2d *definirPoint2d(int x, int y)	// attention malloc il faut penser au free pour les retours
{
	t_point2d *p;

	p = (t_point2d *) malloc(sizeof(t_point2d));

	p->x = x;
	p->y = y;

	return p;
}

void __copierPoint2d(t_point2d * src, t_point2d * dest) // pas d'allocation de memoire il faut un dest deja alloue, fonction en dehors du .h cependant
{
	dest->x = src->x;
	dest->y = src->y;
}

t_triangle2d *definirTriangle2d(t_point2d * a, t_point2d * b, t_point2d * c)	// attention malloc
{
	t_triangle2d *t;

	t = (t_triangle2d *) malloc(sizeof(t_triangle2d));

	__copierPoint2d(a, &(t->t[0]));
	__copierPoint2d(b, &(t->t[1]));
	__copierPoint2d(c, &(t->t[2]));

	return t;
}

void __echangerPointsTriangle(t_triangle2d * triangle, int a, int b)
{
	t_point2d p;

	__copierPoint2d(&(triangle->t[a]), &p);
	__copierPoint2d(&(triangle->t[b]), &(triangle->t[a]));
	__copierPoint2d(&p, &(triangle->t[b]));
}

void __ordonnerPointsTriangle(t_triangle2d * triangle) /* ordonne dans le sens croissant des y */
{
	if (triangle->t[0].y > triangle->t[1].y)    /* on passe le plus grand des
                                                   deux premier au milieu */
	{
		__echangerPointsTriangle(triangle, 0, 1);
	}
	if (triangle->t[1].y > triangle->t[2].y)    /* on passe le plus grand des
                                                   deux dernier au fin */
	{
		__echangerPointsTriangle(triangle, 1, 2);
	}
	if (triangle->t[0].y > triangle->t[1].y)    /* on passe le plus grand des
                                                   deux premier au milieu */
	{
		__echangerPointsTriangle(triangle, 0, 1);
	}
}

void __majMinMax(int x,int y,int *xmin,int *xmax)
{
	if (x<0) x=0;
	if (x>=RX) x=RX-1;

	if (y>0 &&  y<RY)
	{
		if ( x < xmin[y] )
			xmin[y] = x;
		if ( x > xmax[y] )
			xmax[y] = x;
	}
}

/*
 * Algo de Bresenham
 */
void __calculerBornes(int xi,int yi,int xf,int yf,
		int *xmin,int *xmax,int ymin)
{
	int cumul;
	int i;
	int x = xi,y = yi;
	int dx = xf - xi;
	int dy = yf - yi;
	int xinc = ( dx > 0 ) ? 1 : -1;
	int yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);

	if(dx>dy)
	{
		cumul = dx/2;
		for(i=0;i<dx;i++)
		{
			x += xinc;
			cumul += dy;
			if(cumul>dx)
			{
				cumul -= dx;
				y += yinc;
			}

			__majMinMax(x,y,xmin,xmax);
		}
	}
	else
	{
		cumul = dy/2;
		for(i=0;i<dy;i++)
		{
			y += yinc;
			cumul += dx;
			if(cumul>dy)
			{
				cumul -= dy;
				x += xinc;
			}
			__majMinMax(x,y,xmin,xmax);
		}
	}

}

void __imprimerTriangle2d(t_triangle2d * triangle)
{
	printf("%d %d - %d %d - %d %d\n", triangle->t[0].x, triangle->t[0].y, triangle->t[1].x, triangle->t[1].y, triangle->t[2].x, triangle->t[2].y); fflush(stdout);
}

/*
 * Algo "scanline"
 */
void remplirTriangle2d(t_surface * surface, t_triangle2d * triangle, Uint32 c)
{
	int ymin, ymax;
	int *xmin = surface->xmin, *xmax = surface->xmax;
	int x, y;

	__ordonnerPointsTriangle(triangle);
	/*__imprimerTriangle2d(triangle);*/

	ymin = triangle->t[0].y;
	ymax = triangle->t[2].y;

	for ( y = 0 ; y < RY ; y++ )
	{
		xmax[y] = 0;
		xmin[y] = RX-1;
	}

	__calculerBornes(triangle->t[0].x, triangle->t[0].y,
			triangle->t[1].x, triangle->t[1].y,
			xmin,xmax,ymin);
	__calculerBornes(triangle->t[0].x, triangle->t[0].y,
			triangle->t[2].x, triangle->t[2].y,
			xmin,xmax,ymin);
	__calculerBornes(triangle->t[2].x, triangle->t[2].y,
			triangle->t[1].x, triangle->t[1].y,
			xmin,xmax,ymin);
	for (y = MAX(0,ymin) ; y <= MIN(RY-1,ymax) ; y++ )
	{
		for (x = xmin[y] ; x <= xmax[y] ; x++ )
		{
			definirPixel(surface, x, y, c);
		}
	}
}
