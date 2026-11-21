#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "strhash.h"
#include "liste.h"
#include "testListHelpers.h"


//clef de hachage (privée) 
static int hash(const char *word, unsigned int size){
     int clef = 0;
    while (*word != '\0'){
        clef = clef * 2;
        clef = clef + ( char)*word;
        word=word+1;

    }
    clef= clef % (int) size ;
    return clef;
}

s_strhash *strhash_create(unsigned int size){
    if (size == 0) {
    return NULL;
    }   
    s_strhash *t_hash=(s_strhash*)malloc(sizeof(s_strhash));
    if(t_hash==NULL){
        return NULL;
    }
    t_hash->tableau =(s_entree*)malloc(size*sizeof(s_entree));
    if (t_hash->tableau == NULL){
        free(t_hash);
        return NULL;
    }
    unsigned  int i=0;
    while (i<size){
        t_hash->tableau[i].l_mots= liste_create();
        t_hash->tableau[i].nb_mots=0;
        i++;
    }
    {
        /* code */
    }
    
    t_hash->size = size;
    t_hash->nb_tot=0;
    t_hash->nb_min=0;
    t_hash->nb_max=0;
    t_hash->ecart_type=0.0;
    return t_hash;

}

// faire un parcour de liste et faire un free sur chaqyun ed'une donner qu'il ya dasn les node 


void strhash_clear(s_strhash *h){
    if (h != NULL){
        unsigned int i=0;
        while(i < h->size){
            while(h->tableau[i].l_mots!=NULL){
                free(h->tableau[i].l_mots->data);
                h->tableau[i].l_mots=list_headRemove(h->tableau[i].l_mots);
                h->tableau[i].nb_mots--;
                h->nb_tot--;
            }
            i++;
  
        }


        h->nb_tot = 0;
        h->nb_min = 0;
        h->nb_max = 0;
        h->ecart_type = 0.0;
        

    }
}

void strhash_destroy(s_strhash *h){
    
        strhash_clear(h);
        free(h->tableau);
        
        free(h);

    
    
}
int comparechar(s_node *node, void *data){
    return strcmp((char *)node->data,(char *)data);
}

const char  *strhash_add(s_strhash *h,const char *word){
    if (h == NULL || h->tableau == NULL || word == NULL){
        return NULL;
    }
    char *copie=strdup(word);
    if(copie == NULL){
        return NULL;
    }
    int clef=hash(word, h->size);
    s_node *m=list_orderedAppend(&h->tableau[clef].l_mots,comparechar,copie);
    if(m==NULL){
        free(copie);
        return NULL;
    }
    if(m->data != copie ){
        free(copie);
        return m->data;
    }
    h->tableau[clef].nb_mots++;
    h->nb_tot++;
    return m->data;
    
}


void strhash_remove(s_strhash *h, const char *word){

    int b=0; 
    if(h!= NULL && h->tableau != NULL && word!=NULL && b==0){ 
        int clef= hash(word,h->size);
        s_node *courant = h->tableau[clef].l_mots;
        while(courant!=NULL && b ==0){
            if(strcmp((char*)courant->data,(char*)word)==0){
                char *mot=courant->data;
                h->tableau[clef].l_mots=list_remove(h->tableau[clef].l_mots,mot);
                free(mot);
                h->tableau[clef].nb_mots--;
                h->nb_tot--;
                b=1;
            }else{
                courant=courant->next;
            }
            
        }    
    }
            
}



void  strhash_stats( s_strhash *h ){
    if(h!=NULL && h->tableau != NULL ){
        h->nb_min = h->tableau[0].nb_mots;
        h->nb_max = h->tableau[0].nb_mots;

        unsigned int i = 1;
       
        while ( i<h->size){
            if(h->nb_max < h->tableau[i].nb_mots){
                h->nb_max= h->tableau[i].nb_mots;
            }
            if(h->nb_min > h->tableau[i].nb_mots){
                h->nb_min = h->tableau[i].nb_mots;
            }

            i++;
        }
        double moyenne= (double)h->nb_tot/(double)h->size;
        double diff=0.0;
        unsigned int k=0;
        while ( k<h->size){
            diff=diff+((double)h->tableau[k].nb_mots - moyenne)*((double)h->tableau[k].nb_mots - moyenne);
            k++;
        }
        double variance = diff/ h->size;
        h->ecart_type = sqrt(variance);

        printf("nombre total d'elements = %d \n",h->nb_tot);
        printf("nombre minimum d'elements par entrée = %d\n", h->nb_min);
        printf("nombre maximum d'elements par entrée = %d\n", h->nb_max);
        printf("écart type = %f\n", h->ecart_type);

    }
}




void strhash_print(s_strhash *h) {
    if (h == NULL) {    
        printf("table de hashage null");
    }else{
    unsigned int i = 0;
    while (i < h->size) {
        printf("Case %u : ", i);
        s_node *courant = h->tableau[i].l_mots;

        while (courant != NULL) {
            printf("%s -> ", (char *)courant->data);

            courant = courant->next;
        }

        printf("NULL\n");
        printf("Nombre total de mots daans la liste de node n°=%u = %d\n",i, h->tableau[i].nb_mots);
        i++;
    }

    printf("\nNombre total de mots dans la table de hashage : %d\n", h->nb_tot);
    }
}


void strhash_ckek(s_strhash *h, const char *word) {
    if (h == NULL) {    
        printf("table de hashage null");
        printf("le mot n'existe pas");
    }
    else{
    int clef=hash(word, h->size);

    s_node *courant = h->tableau[clef].l_mots;
    int i=0;

        while (courant != NULL && i==0) {

            if ((char *)courant->data == word){
                i=1;
            }

            courant = courant->next;
        }
        if(i==0){
            printf (" le mot %s n'existe pas  dans la table de hashage\n",word);
        }else{
            printf (" le mot %s existe dans la table de hashage\n",word);
        }
        

        
    }  
}