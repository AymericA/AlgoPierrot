#include "lib_surface.h"
#include "lib_3d.h"
#include "lib_2d.h"
#include "lib_mat.h"
#include <math.h>




t_point3d *definirPoint3d_etu(double x, double y, double z)	// attention malloc
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


t_point3d *definirVecteur3d_etu(double x, double y, double z){
	t_point3d *vecteur = definirPoint3d_etu(x, y, z);
	return vecteur;
};
t_triangle3d *definirTriangle3d_etu(t_point3d * a, t_point3d * b, t_point3d * c){
	t_triangle3d *triangle;
	triangle = (t_triangle3d*) malloc(sizeof(t_triangle3d));

	triangle->abc[0] = a;
	triangle->abc[1] = b;
	triangle->abc[2] = c;

	return triangle;
};
t_triangle3d *copierTriangle3d_etu(t_triangle3d *t){
	// t_triangle3d *copieTriangle; // = definirTriangle3d_etu(
	// // 	t->abc[0],
	// // 	t->abc[1],
	// //  t->abc[2]);
	// 	memcpy(*t->abc, copieTriangle->abc, sizeof(t_triangle3d));
	// return copieTriangle;le));
};
void differenceVecteur3d_etu(t_point3d *v1, t_point3d *v2){
	v1->xyzt[0] = v1->xyzt[0] - v2->xyzt[0];
	v1->xyzt[1] = v1->xyzt[1] - v2->xyzt[1];
	v1->xyzt[2] = v1->xyzt[2] - v2->xyzt[2];
}; //v1 = v1-v2
void sommeVecteur3d_etu(t_point3d *v1, t_point3d *v2){
	v1->xyzt[0] = v1->xyzt[0] + v2->xyzt[0];
	v1->xyzt[1] = v1->xyzt[1] + v2->xyzt[1];
	v1->xyzt[2] = v1->xyzt[2] + v2->xyzt[2];
}; //v1 = v1+v2
void divisionVecteur3d_etu(t_point3d *v1, int n){
	v1->xyzt[0] = v1->xyzt[0] /n;
	v1->xyzt[1] = v1->xyzt[1] /n;
	v1->xyzt[2] = v1->xyzt[2] /n;
}; //v1 = v1/n
t_point3d* centreGraviteTriangle3d_etu(t_triangle3d *t){
	t_point3d *centreGravite = definirPoint3d_etu(
		(t->abc[0]->xyzt[0]+t->abc[1]->xyzt[0]+t->abc[2]->xyzt[0])/3, // (xa+xb+xc)/3
		(t->abc[0]->xyzt[1]+t->abc[1]->xyzt[1]+t->abc[2]->xyzt[1])/3, // (ya+yb+yc)/3
		(t->abc[0]->xyzt[2]+t->abc[1]->xyzt[2]+t->abc[2]->xyzt[2])/3); // (za+zb+zc)/3

	return centreGravite;
};

double zmoyen_etu(t_triangle3d *t){
	return (t->abc[0]->xyzt[2]+t->abc[1]->xyzt[2]+t->abc[2]->xyzt[2])/3;
};
void remplirTriangle3d_etu(t_surface * surface, t_triangle3d * triangle, Uint32 c, double l, double h, double d){
	//On part du centre de gravité du triangle,on fais h
	//Quand les arretes de taille d rejoignent h, on possede une pyramide,
	//on remplis la pyramide avec les surfaces
};

void translationTriangle3d_etu(t_triangle3d *t, t_point3d *vecteur){
	t->abc[0]->xyzt[0] = t->abc[0]->xyzt[0]+vecteur->xyzt[0];
	t->abc[0]->xyzt[1] = t->abc[0]->xyzt[1]+vecteur->xyzt[1];
	t->abc[0]->xyzt[2] = t->abc[0]->xyzt[2]+vecteur->xyzt[2];

	t->abc[1]->xyzt[0] = t->abc[1]->xyzt[0]+vecteur->xyzt[0];
	t->abc[1]->xyzt[1] = t->abc[1]->xyzt[1]+vecteur->xyzt[1];
	t->abc[1]->xyzt[2] = t->abc[1]->xyzt[2]+vecteur->xyzt[2];

	t->abc[2]->xyzt[0] = t->abc[2]->xyzt[0]+vecteur->xyzt[0];
	t->abc[2]->xyzt[1] = t->abc[2]->xyzt[1]+vecteur->xyzt[1];
	t->abc[2]->xyzt[2] = t->abc[2]->xyzt[2]+vecteur->xyzt[2];
};
void rotationTriangle3d_etu(t_triangle3d *t, t_point3d *centre, float degreX, float degreY, float degreZ){};



void __copierPoint3d_etu(t_point3d * src, t_point3d * dest)
{

	memcpy(dest->xyzt, src->xyzt, 4*sizeof(double));
}



void transformationTriangle3d_etu(t_triangle3d *t, double mat[4][4])
{
	t_point3d *p3dtmp;
	int i;

	p3dtmp = (t_point3d*)malloc(sizeof(t_point3d));
	if (p3dtmp!=NULL)
	{
		for(i=0; i<3; i++)
		{
			multiplication_vecteur(p3dtmp, mat, t->abc[i]);
			__copierPoint3d_etu(p3dtmp, t->abc[i]);

		}
	}

	free(p3dtmp);
}
