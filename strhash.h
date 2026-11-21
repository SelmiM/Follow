#ifndef _STRHASH_H_
#define _STRHASH_H_
#include "liste.h"

typedef struct {
    s_node *l_mots;    
     int nb_mots;
     
} s_entree;


typedef struct {
    s_entree *tableau;    //il sotoque la liste de node et les information
    unsigned int size;  
    int nb_tot;
    int nb_min;
    int nb_max;
    double ecart_type;

} s_strhash;


//creation d’une table de hashage,
s_strhash *strhash_create(unsigned int size);
void strhash_print(s_strhash *h);
void strhash_ckek(s_strhash *h, const char *word) ;
void strhash_destroy(s_strhash *h);   
const char  *strhash_add(s_strhash *h , const char *word);
void strhash_clear(s_strhash *h);
void strhash_remove(s_strhash *h, const char *word);
void strhash_stats( s_strhash *h);
int comparechar(s_node *node, void *data);



#endif