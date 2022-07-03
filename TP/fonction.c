#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

float** allouer(int n,int m)
{
    float **A;
   
    int i;
    A=(float**)malloc(sizeof(float*)*n);
    for(i=0;i<n;i++){  
        A[i]=(float*)malloc(sizeof(float)*m);
    }  
    return A;
}


void free_matrice (float **a, int n,int m)
{
    if (a!=NULL)
    {
        for (int i=0; i<n; i++)
        if (a[i]!=NULL)
        free((void *)a[i]);
        free((void *)a);
    }
}


float** lire_clavier(int n,int m)
{
    float **tab; 
    int i,j;
    tab=allouer(n,m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){ 
        printf("entrer la valeur de la composante %d %d de votre tableau\n",(i+1),(j+1));
        scanf("%f",&tab[i][j]);
        }
        printf("\n"); 
    }
	return tab;
}


void affiche_matrice(int n,int m,float **A){
	int i,j;
	printf("la matrice est\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%f\t",A[i][j]);
		}
		printf("\n");
	}
}

void print_tab(int n,float *tab)
{
	int i;
	printf("le tableau est\n");
	for(i=0;i<n;i++)
	{
		printf("%f\t",tab[i]);
	}
	printf("\n");
}

float* genere(float* tab,int n)
{
	int i;
	srand(time(NULL));
	for (i=0 ; i<n ; i++)
	{
		tab[i]=rand()%20;
	}
	return tab;
}

float* alloue_espace( int n)
{
	float* tab;
	tab=(float*)malloc(sizeof(float)*n);
	return tab;
} 


int Type_matrice(float** tab,int n,int m){

    int  compi = 0, comps = 0, compd = 0, i, j;
    float **inf= allouer(n,m);
    float **sup = allouer(n,m);

    for (i=0; i<n; i++){
        for(j = 0; j<m; j++){
            if(i>j)
                inf[i][j] = 0;
            else
                inf[i][j] = tab[i][j];
        }
        for(j = 0; j<m; j++){
            if(i<j)
                sup[i][j] = 0;
            else
                sup[i][j] = tab[i][j];
        }
    }

    for (i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(inf[i][j] == tab[i][j]){
                compi += 1;
            }

            if(sup[i][j] == tab[i][j]){
                comps += 1;
            }
        }
        
    }

    if(compi == n*m && comps != n*m && n == m){
        printf("\nil sagit d une matrice triangulaire superieure.\n");
        return 1;
    }
    if(compi != n*m && comps == n*m && n == m){
        printf("\nil sagit d une matrice triangulaire  inferieure. \n");
        return 2;
    }
    if(compi == n*m && comps == n*m && n == m){
        printf("\nil sagit d une matrice diagonale. \n");
        return 3;
    }
    if(compi != n*m && comps != n*m || n != m){
        printf("\nil sagit d une matrice quelconque. \n");
        return 4;
    }
    return 0;
}    


void Afficher_systeme_lineaire(int n,int m,float *b,float **a)
{
    int i,j;

    printf("\nle systeme est :\n");
    for(i=0;i<n;i++)
    {
        printf("(");
        
        for(j=0;j<m;j++)
        {
            printf("%f   ",a[i][j]);
        }
        printf(" )(x%d) = %f\n",i,b[i]);
    }
}



float* fill_tab(int n, float* tab)
{ int i;
	for(i=0;i<n;i++){
	printf("element %d:",i+1);
	scanf("%f", &tab[i]);
	}

	return tab;
}



void eliminition_de_gauss(int n,int m,float**a)
{
  int i,j,k;
  float c;
  float **d = allouer(n,m);

    

  for(j=0;j<n;j++)
  {
      for(i=0;i<n;i++)
      {
          if(i!=j)
          {
              c=a[i][j]/a[j][i];

              for( k=0;k<n;k++)
              {
                  d[i][k]=a[i][k]-(c*a[j][k]);
              }
          }
      }
   }
    printf("\n elimination \n");
    // free_matrice(d,m,n);

}



void solution_superieur(int n,int m,float** A)
{
		float *x = (float*)malloc(sizeof(float)*n);

        x[n-1] = A[n-1][n]/ A[n-1][n-1];

		for(int i = n-2; i >= 0; i--){
			x[i] = A[i][n];

			for(int j = i+1; j < n; j++){
				x[i] -= A[i][j] * x[j];
			}
			x[i] /= A[i][i];
		}

		for (int i = 0; i < n; i++){
			printf("x%d=%f",i,x[i]);
			if (i != n-1){
                printf("\n");
			}
		}
	}

	// matrice triangulaire inférieure
	void solution_inferieure(int n,int m,float** A)
    {

		float *x = alloue_espace(n);

        x[0] = A[0][n]/ A[0][0];

		for(int i = 0; i <= n-1; i++){
			x[i] = A[i][n];

			for(int j = 0 ; j <= i-1; j++){
				x[i] -= A[i][j] * x[j];
			}
			x[i] /= A[i][i];
		}

		for (int i = 0; i < n; i++){
        printf("x%d=%f",i,x[i]);			
        if (i != n-1){
                printf("\n ");
			}
		}
	}

	//matrice diagonale
	void solution_diagonale(int n,int m,float** A) 
    {
		float *x;

		for(int i = 0; i < n; i++){
			if(A[i][i] != 0){
				x[i] = A[i][n] / A[i][i];
			}else{
				x[i] = 0;
			}
		}

		for (int i = 0; i < n ; i++){
			printf("%f", x[i]);
			if (i != n-1){
                printf(", ");
			}
		}
	}


