#include<stdio.h>

#include "liste.h"
#include "testListHelpers.h"

void displayInt(s_node *node){
    int *ptrInt=(int *) list_get_data(node);
    printf("%d \n",*ptrInt);

}


   // si a ==b alors node->data = data return 0
   // si a < b alors node->data < data return <0
   // si a > b alors node->data > data return >0
int compareInt(s_node *node, void *data){

    int a = *(int *)node->data;
    int b = *(int *)data;

    return a-b;
}


int main(void){
    int i=3,j=1,k=8,ok;
    s_node *l=liste_create();

    l=list_insert(l,&i);
    displayInt(l); // retoune la valeur du 1 ere node

    l=list_insert(l,&j);
    displayInt(l);

    ok=check_list_state(l, &node_int_to_string , "1 -> 3 -> null");
    if(ok){
         printf("c bon\n");
        }
   else{
    printf("c'est pas  bon\n");
   }
    // tester la fonction get_data
    void * data=list_get_data(l);
    printf("la valeur du data est : %d\n",*(int*)data); // toujour casteer le data car c'est un void pointer car le compilateur ne sait pas le type de data

    // teste de la fonction list_append
    s_node *l1=liste_create();

    l1=list_insert(l1,&j);
    l1=list_insert(l1,&j);
    l1=list_append(l1 , &k);

    l=list_append(l , &k);  // c'est a l qu'on ajoute ici 

    printf("\nteste de la fonction set data \n");
    list_set_data(l1, &k);
    ok=check_list_state(l1, &node_int_to_string , "8 -> 1 -> 8 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    
    // tester la fonction set data mofifie la tete de la liste chainé
    printf("\nteste de la fonction set data \n");
    list_set_data(l1, &k);
    ok=check_list_state(l1, &node_int_to_string , "8 -> 1 -> 8 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    
    printf("\nteste de la fonction list_next \n");
    void * data1=list_get_data(list_next(l1));

    // normalment le data1=1       8 -> 1 -> 8 -> null
    printf("la valeur du data est : %d\n",*(int*)data1); // toujour casteer le data car c'est un void pointer car le compilateur ne sait pas le type de data   
    /*test de compareInt*/

    int a = 2;
    int b = 5;
    int c = 1;

    printf("\nComparaison avec 2 : %d\n", compareInt(l, &a));
    printf("Comparaison avec 5 : %d\n", compareInt(l, &b));
    printf("Comparaison avec 1 : %d\n", compareInt(l, &c));


    // tester la fonction list_orderedAppend
    printf("\nteste de la fonction list_orderedAppend \n");
    ok=check_list_state(l1, &node_int_to_string , "8 -> 1 -> 8 -> null");
    
    int m=0;
    s_node *sn0=list_orderedAppend(&l,  compareInt ,&m);
    printf("\ntest insertion au debut avec m = : %d\n", m);
    ok=check_list_state(l, &node_int_to_string , "0 -> 1 -> 3 -> 8 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    displayInt(sn0);

    
    int m1=1;
    printf("\nteste insertion d'un nombre qui existe deja avec m1 = : %d\n", m1);
    s_node *sn1=list_orderedAppend(&l,  compareInt ,&m1);
    ok=check_list_state(l, &node_int_to_string , "0 -> 1 -> 3 -> 8 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    displayInt(sn1);
   
    int m2=10; // ça doit inserer a la fin de la liste 
    printf("\nteste insertion a la fin avec m2 = : %d\n", m2);
    s_node *sn2=list_orderedAppend(&l,  compareInt ,&m2);
    ok=check_list_state(l, &node_int_to_string , "0 -> 1 -> 3 -> 8 -> 10 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    displayInt(sn2);
    int m3=3; // insert au milieu de la liste 
    printf("\nteste insertion au milieu avec m3 = : %d\n", m3);
    l=list_orderedAppend(&l,  compareInt ,&m3);
    ok=check_list_state(l, &node_int_to_string , "0 -> 1 -> 3 -> 8 -> 10 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    displayInt(sn3);
    int m5=5;
    printf("\nteste insertion au milieu avec m5 = : %d\n", m5);
    s_node *sn5=list_orderedAppend(&l,  compareInt ,&m5);
    ok=check_list_state(l, &node_int_to_string , "0 -> 1 -> 3 -> 5 -> 8 -> 10 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    displayInt(sn5);
    int m6=-1;
    printf("\nteste insertion au debut avec m6 = : %d\n", m6);
    s_node *sn6=list_orderedAppend(&l,  compareInt ,&m6);
    ok=check_list_state(l, &node_int_to_string , "-1 -> 0 -> 1 -> 3 -> 5 -> 8 -> 10 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    displayInt(sn6);
    s_node *l3=liste_create();
    int m7=9;
    printf("\nteste insertion dans une liste vide : %d\n", m7);
    l3=list_orderedAppend(&l3,compareInt,&m7);
    ok=check_list_state(l3, &node_int_to_string ,"9 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
   

    //teste sur la fonction remove
    int f=2,g=3,h=6,p=7;
        s_node *l2=liste_create();

        l2=list_insert(l2,&f);
        l2=list_insert(l2,&g);
        l2=list_insert(l2,&h);
        l2=list_insert(l2,&p);
        displayInt(l2);
        ok=check_list_state(l2, &node_int_to_string , "7 -> 6 -> 3 -> 2 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }



    printf("\nteste de la fonction list_remove avec g = 3 \n");
    l2= list_remove(l2,&g);

        ok=check_list_state(l2, &node_int_to_string , "7 -> 6 -> 2 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }

    printf("\nteste de la fonction list_remove avec p = 7 suppression de la tete de la liste \n");

    l2= list_remove(l2,&p);

        ok=check_list_state(l2, &node_int_to_string , "6 -> 2 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    printf("\nteste de la fonction list_remove avec p = 7 encore une fois pour verifier que la fonction ne supprime pas si la valeur n'existe pas dans la liste \n");
    l2= list_remove(l2,&p);

        ok=check_list_state(l2, &node_int_to_string , "6 -> 2 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }

    printf("\nteste de la fonction list_remove avec f = 2 suppression de la queue de la liste \n");
    l2= list_remove(l2,&f);
        ok=check_list_state(l2, &node_int_to_string , "6 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    printf("\nteste de la fonction list_remove avec h = 6 suppression de la fin de la liste \n");
    l2= list_remove(l2,&h);
        ok=check_list_state(l2, &node_int_to_string , "null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");
    }
    printf("\nteste de la fonction list_headRemove avec l  \n");
    ok=check_list_state(l, &node_int_to_string , "-1 -> 0 -> 1 -> 3 -> 5 -> 8 -> 10 -> null");

    l= list_headRemove(l);
        ok=check_list_state(l, &node_int_to_string , "0 -> 1 -> 3 -> 5 -> 8 -> 10 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");    
    }

    l2=list_insert(l2,&f);
    printf("\nteste de la fonction list_headRemove suite à l'insertion on a une liste non vide 2 -> null car on vient d'insérer un élément\n");
    l2=list_headRemove(l2);
        ok=check_list_state(l2, &node_int_to_string , "null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");    
    }

    printf("\nteste de la fonction list_destroy \n");
    list_destroy(l2);
        ok=check_list_state(l2, &node_int_to_string , "null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");    
    }
    printf("\nteste de la fonction list_insert dans l2 \n");
    l2=list_insert(l2,&f);
    ok=check_list_state(l2, &node_int_to_string , "2 -> null");
        if(ok){
            printf("c bon\n");
            }
    else{
        printf("c'est pas  bon\n");    
    }
    return 0;
    }