
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include <limits.h>
#include <signal.h>

bool areTheSame (unsigned int * tab1, unsigned int *tab2 , unsigned int  N){
    for (unsigned int i=0 ; i<N ; i++){
        if (*(tab1+i) != *(tab2+i)) return false ;
    }
    return true ;
}

bool itExists(unsigned int *tab , unsigned int val,int N){
    for (unsigned int i=0 ; i<N ; i++){
        if (*(tab+i) == val) return true ;
    }
    return false ;
}

bool areAllHere(unsigned int *tab , unsigned int * tab1,int N){
    for (unsigned int i=0 ; i<N ; i++) {
        if (! itExists(tab1 , *(tab+i) , N) ){
            return false ;
        }

    }
    return true ;
}
unsigned int * getRandomArray(unsigned int k, unsigned int n ) {
    unsigned int *tab = (unsigned int *) malloc (sizeof(unsigned int) *k) ;
    unsigned int index =0 ;
    int r =0 ;
    for (unsigned int i= 0 ; i<k ; i++) *(tab+i) =-1 ;

    while(index <k) {
        r=(rand()%n)+1 ;
        if (! itExists(tab ,r ,k)){
            *(tab+index) = r ;
            index ++ ;
        }
    }
     return tab ;
}


void afficherTableau(unsigned int * tab , unsigned int  N){
    for (unsigned int i=0 ; i<N ; i++) printf ("%d " , *(tab+i)) ;
    
}

void jouer(unsigned int k , unsigned int n) {
   
    unsigned  long int compteur =1 ;
    
    unsigned int * userTab = NULL ;
    
    unsigned int * computerTab = NULL ;
    
    while ( true) {
        userTab = getRandomArray(k ,n) ;
        computerTab = getRandomArray(k ,n) ;
        if (areAllHere(userTab , computerTab ,k)){
            
            printf("Gagné !!!\nNombre d'essais = %ld == " , compteur) ;
            printf ("Quentin  : ") ;
            afficherTableau(userTab , k) ;
            
            printf ("Euromillion : ") ;
            afficherTableau(computerTab , k) ;
            printf("\n") ;
            break ;
        }
        compteur ++ ;
        free(userTab);
        free(computerTab);
        
    }
    
}





int main(int argc, char const *argv[])
{
    srand(time(0));
    
    
    jouer(2,12) ;    
    jouer(5,50) ;
    
 
    
    return 0;
}
