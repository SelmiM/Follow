#include<stdio.h>
#include<string.h>
#include "liste.h"
#include "strhash.h"
#include "testListHelpers.h"





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

    printf("\nTEST fonction uppression d’un mot dans une table vide mot=vide  ---\n");
    const char *m0="vide";
    strhash_remove(t_hash,m0);
    strhash_ckek(t_hash,m0);
    
    
    printf("\nTEST ajout sur table vide  ---\n");
    const char *m1 = strhash_add(t_hash, "salut");
    printf("Mot ajoute : %s\n", m1);
    strhash_ckek(t_hash,m1);

    printf("\nsuprimer le premier mot ajout sur table vide  ---\n");
    strhash_remove(t_hash,m1);
    strhash_ckek(t_hash,"'vide'");

    

    
    printf("\nTEST ajout d’un mot dans la table si le mot concerne ne s’y trouve pas deja sur table non vide  ---\n");
    const char *m2 = strhash_add(t_hash, "manar");
    strhash_ckek(t_hash, m2);
    const char *m3 = strhash_add(t_hash, "lysa");
    strhash_ckek(t_hash, m3);
    const char *m5 = strhash_add(t_hash, "L3_IFA");
    strhash_ckek(t_hash, m5);
    const char *m6 = strhash_add(t_hash, "L3_IFA_TP2");
    strhash_ckek(t_hash, m6);
    const char *m7 = strhash_add(t_hash, "almskvcjlfx");
    strhash_ckek(t_hash, m7);


    printf("\n");
    strhash_print(t_hash);

    printf("\nTEST d'un doublon \n");
    const char *m4 = strhash_add(t_hash, "lysa");
    strhash_ckek(t_hash, m6);

    printf("\n");
    strhash_print(t_hash);

    printf("\nteste de la fonction statistque sur liste non vide  ");
    strhash_stats(t_hash);

    printf("\nteste de la fonction statistque sur liste  vide  ");
    s_strhash *t_hash2=strhash_create(size);

    strhash_stats(t_hash2);



    printf("\n--- TEST de la fonction suppression d’un mot dans la table  ---\n");
    strhash_remove(t_hash,m4);
    strhash_ckek(t_hash, m4);
    strhash_print(t_hash);

    printf("\n--- TEST de la fonction suppression du dernier mot dans la table  ---\n");
    strhash_remove(t_hash,m6);
    strhash_print(t_hash);
    strhash_ckek(t_hash, m6);
    




    printf("\n--- TEST de la fonction de libération des données enregistrées dans une table de hashage,  ---\n");
    strhash_clear(t_hash);




    strhash_print(t_hash);
    printf("\n--- TEST de la fonction destruction de la table si elle est vide \n");
    strhash_destroy(t_hash);
    

return 0;
}