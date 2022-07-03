#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

int main (){

    
    float**A,*tab;
    int n,m;
    int choix;
    printf("\t\t-------------------RESOLUTION DE SYSTEMES LINEAIRES---------------\n");
    do{
        printf("La resolution des systemes n'est valables que pour des matrices carre\n");
        do{
            printf("Donc entrer un meme  nombre de ligne que de colonnes pour votre matrice \n");
            scanf("%d %d",&n,&m);
        }while(m<0 || n<0); 
    }while(m != n);

    A=allouer(n,m);
    A=lire_clavier(n,m);

    affiche_matrice(n,m,A);
    int nat=Type_matrice(A,n,m);
     

    tab=alloue_espace(n);
    printf("\n\t\t\tCOMMENT VOULEZ VOUS REMPLIR VECTEUR \n\n1-> Par la machine\n2-> manuellement\n");
    do
    {
        printf("Votre choix\n");
        scanf("%d",&choix);
    }while(choix < 1 ||  choix > 2);   

    if(choix == 1){
        tab=genere(tab,n);
        print_tab(n,tab);

    }else{
        tab=fill_tab(n,tab);
        print_tab(n,tab);
    }

   

   
    float** B=allouer(n,m+1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            B[i][j] = A[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        B[i][n] = tab[i];
    }
    Afficher_systeme_lineaire(n,m,tab,A);

    // eliminition_de_gauss(n,m,B);
    printf("les solutions du systemes sont\n");
    solution_inferieure(n,m,B);




    free(tab);
    free_matrice (A,n,m);        
    free_matrice (B,n,m);        

    return 0;
}