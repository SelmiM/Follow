#ifndef _LIST_H_
#define _LIST_H_

struct _list_node{
    void *data;
    struct _list_node *next;

}; 
typedef struct _list_node s_node; 

s_node *liste_create(void);

void *list_get_data(s_node *node);

void list_set_data(s_node *node, void *data);

s_node *list_next(s_node *node); /*retourner le noeud suivant*/

s_node *list_insert(s_node *head , void *data); /* crée un nouveau noued(faire un malloc)
                                                /le mettre en tete dde la liste / 
                                                retourne le nouveau noeud en tete */

s_node *list_append(s_node *head , void *data);

s_node *list_orderedAppend(s_node **head , int (*compare) (s_node *,void *),void *param);
                           /* (** : entrée/sortie)*/
                           //un pionteur vers le neoud ou la valeur (mise) ou se trouve 
s_node *list_remove(s_node *head,void *data);

s_node *list_headRemove(s_node *head);

void list_destroy(s_node *head);


void displaylist(s_node *head, void (*display)(s_node *)); /*prend en param en plus un pointeur de fonction/
                                il y a un cast à faire */           
                                
                                



#endif                              