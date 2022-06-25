
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>



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

void jouer() {
   
    unsigned int k =2 ;
    unsigned int n =12 ;
    int compteur =1 ;
    
    unsigned int * userTab = NULL ;
    
    unsigned int * computerTab = NULL ;
    
    while ( true) {
        userTab = getRandomArray(k ,n) ;
        computerTab = getRandomArray(k ,n) ;
        if (areTheSame(userTab , computerTab ,k)){
            
            printf("Gagné !!!\ncompteur = %d == " , compteur) ;
            printf ("user tab est : ") ;
            afficherTableau(userTab , k) ;
            
            printf ("computer tab est : ") ;
            afficherTableau(computerTab , k) ;
            printf("\n") ;
            break ;
        }
        
        
        printf("oups !... %d\n" , compteur) ;
        printf ("user tab est : ") ;
        afficherTableau(userTab , k) ;
        printf(" == ") ;
        printf ("computer tab est : ") ;
        afficherTableau(computerTab , k) ;
        printf("\n") ;
        compteur ++ ;
        
    }

}





int main(int argc, char const *argv[])
{
    srand(time(0));
    
    
    jouer() ;
   
   
    return 0;
}
