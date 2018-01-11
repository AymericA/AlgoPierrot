#include "lib_surface.h"
#include "lib_objet3d.h"
#include "lib_3d.h"
#include "lib_2d.h"
#include "lib_mat.h"

t_objet3d* objet_vide_etu(){return NULL;};
t_objet3d *camera_etu(double l, double h, double n, double f, double d){return NULL;}; // zone l*h dans le champ n->f
t_objet3d* parallelepipede_etu(double lx, double ly, double lz){return NULL;};
t_objet3d* sphere_etu(double r, double nlat, double nlong){return NULL;};
t_objet3d* sphere_amiga_etu(double r, double nlat, double nlong){return NULL;};
t_objet3d* arbre_etu(double lx, double ly, double lz){return NULL;};
t_objet3d* damier_etu(double lx, double lz, double nx, double nz){return NULL;};
t_objet3d *copierObjet3d_etu(t_objet3d *o){return NULL;}; // attention, effectue une copie mirroir
void composerObjet3d_etu(t_objet3d* o, t_objet3d* o2){};
void composerObjet3d_limite_en_z_etu(t_objet3d* o, t_objet3d* o2, t_objet3d *camera){};
void libererObjet3d_etu(t_objet3d *o){};
t_point3d *centreGraviteObjet3d_etu(t_objet3d *o){return NULL;};
void dessinerObjet3d_etu(t_surface *surface, t_objet3d* pt_objet, t_objet3d *camera){};

void translationObjet3d_etu(t_objet3d* pt_objet, t_point3d *vecteur){};
void translationObjet3d_fast_etu(t_objet3d* pt_objet, t_point3d *vecteur){};
void rotationObjet3d_etu(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ){};
void rotationObjet3d_fast_etu(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ){};
void transformationObjet3d_etu(t_objet3d* pt_objet, double mat[4][4])
{
	t_maillon* o = NULL;

	o = pt_objet->tete;
	while (o!=NULL)
	{
		transformationTriangle3d(o->face, mat);
		o = o->pt_suiv;
	}
	pt_objet->est_trie = false;
}