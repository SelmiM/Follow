#include<stdio.h>
#include<string.h>
#include "liste.h"
#include "strhash.h"
#include "testListHelpers.h"


int comparechar(s_node *node, void *data){
    return strcmp((char *)node->data,(char *)data);
}


int main(void){
    
    unsigned int size=4;

    printf("TEST 1 : création de la table :\n");
    s_strhash *t_hash=strhash_create(size);
    if (t_hash==NULL){
        printf("création de la table echoue \n");
    }
    else{
        printf("création de la table reussit \n");
    }

    strhash_print(t_hash);
    printf("\n--- TEST fonction uppression d’un mot dans une table vide mot=vide  ---\n");
    strhash_remove(t_hash,"vide");
    strhash_print(t_hash);
    
    
    printf("\n--- TEST ajout sur table vide  ---\n");
    const char *m1 = strhash_add(t_hash, "salut", comparechar);
    printf("Mot ajoute : %s\n", m1);
    strhash_print(t_hash);

    
    printf("\n--- TEST ajout d’un mot dans la table si le mot concerne ne s’y trouve pas deja sur table non vide  ---\n");

    const char *m2 = strhash_add(t_hash, "manar", comparechar);
    const char *m3 = strhash_add(t_hash, "lysa", comparechar);
    const char *m5 = strhash_add(t_hash, "L3_IFA", comparechar);
    const char *m6 = strhash_add(t_hash, "L3_IFA_TP2", comparechar);

    
    printf("Mot ajoute : %s\n", m2);
    printf("Mot ajoute : %s\n", m3);
    printf("Mot ajoute : %s\n", m5);
    printf("Mot ajoute : %s\n", m6);
    strhash_print(t_hash);

    printf("\n--- TEST d'un doublon ---\n");

    const char *m4 = strhash_add(t_hash, "lysa", comparechar);
    printf("Mot ajoute : %s\n", m4);
    strhash_print(t_hash);

    printf("\nteste de la fonction statistque sur liste non vide  ");
    strhash_stats(t_hash);
    printf("\nteste de la fonction statistque sur liste  vide  ");
    s_strhash *t_hash2=strhash_create(size);
    strhash_stats(t_hash2);



    printf("\n--- TEST de la fonction suppression d’un mot dans la table  ---\n");
    strhash_remove(t_hash,m4);
    strhash_print(t_hash);


    printf("\n--- TEST de la fonction de libération des données enregistrées dans une table de hashage,  ---\n");
    strhash_clear(t_hash);
    strhash_print(t_hash);
    printf("\n--- TEST de la fonction destruction de la table si elle est vide \n");
    strhash_destroy(t_hash);
    

return 0;
}