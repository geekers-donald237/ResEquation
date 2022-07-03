#ifndef  __FONCTION_H__
#define  __FONCTION_H__

#include "fonction.h"

float** allouer(int n,int m);

void free_matrice (float **a, int n,int m);

float** lire_clavier(int n,int m);

void affiche_matrice(int n,int m,float **A);

void print_tab(int n,float *tab);

float* genere(float* tab,int n);

float* alloue_espace( int n);

int Type_matrice(float** tab,int n,int m);

void Afficher_systeme_lineaire(int n,int m,float *b,float **a);

float* fill_tab(int n, float* tab);

void eliminition_de_gauss(int n,int m,float**a);

void solution_superieur(int n,int m,float** A);

void solution_inferieure(int n,int m,float** A);

void solution_diagonale(int n,int m,float** A) ;



#endif
