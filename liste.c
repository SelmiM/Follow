#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "testListHelpers.h"

s_node *liste_create(void){
    return NULL;
}

void *list_get_data(s_node *node){
    if(node ==NULL){
        return NULL;
    }
    return node->data;
}

void list_set_data(s_node *node, void *data){
    node->data=data;
}

s_node *list_next(s_node *node){
    if(node->next!=NULL){
        return node->next ;
    }
    return NULL;
}

s_node *list_insert(s_node *head , void *data){
     s_node  *first = (s_node * ) malloc(sizeof(s_node));
     if(first ==NULL){
        //free(first); 
        return NULL;
    }
    else{
        first->data=data;
        first->next=head;
    return first;
    }

}
 
s_node *list_append(s_node *head , void *data){
    s_node  *last = (s_node * ) malloc(sizeof(s_node));
    if(last ==NULL){
        return head;  // si la malloc echoue on retourn pas null ici on retourne le head snn on va perdre la liste chainé qui est deja creee
    }

    s_node  *tmp = head;
    
    while(tmp->next!=NULL){
        tmp=tmp->next; //on avence jusqu'a la fin de la liste chainé
    }
    tmp->next=last;
    last->data=data;
    last->next=NULL;

    return head;
}


s_node *list_orderedAppend(s_node **head,int (*compareInt)(s_node *, void *),
void *param){

    s_node **tmp = head;
    if (*tmp == NULL){  //liste chainer qui est vide 
        *head = list_insert(NULL, param);
        return *head;
    }
    int i = compareInt(*tmp, param);

    if (i == -1 ){ // param est egale a tmp->data on  doit pas inseer on retourne le debut 
        return *head;
    }

    if (*(int *)(*tmp)->data  >  *(int *)param){ // si on met verifie pas au debut ça va pas insere en 1 ere car comppartint elle verfie au mileu seulment elle ne verifi pas au debut 
        *head = list_insert(*head, param);
        return *head;
    }
    while ((*tmp)->next != NULL && i ==!1 ){ // on verifie si on est pas a la fin et si i est diferent de 1  on passe au moeud suivant on a pas trouver encore la place de param 
        tmp = &(*tmp)->next;
        i = compareInt(*tmp, param);
    }
    if (i == -1){
        return *head;
    }
    s_node *nou = list_insert((*tmp)->next, param);

    if (nou == NULL){
        return *head;
    }
    (*tmp)->next = nou;
    return *head;
}



s_node *list_remove(s_node *head,void *data){

        s_node *tmp=head;
        s_node *prec=NULL;
// si on est pas a la fin de la liste chainé et la valeure de datat est diferencte de celle qu'on veut supprimer 
        while(tmp!= NULL && *(int*)tmp->data != *(int*)data){
            prec = tmp;
            tmp = tmp->next;
        }
        if(tmp ==NULL){
            return head; // on a rien supprimer
        }
        if(prec==NULL){
            head=tmp->next;
        }else{
            prec->next= tmp->next;
        }
        
        free(tmp);
        return head;
}



s_node *list_headRemove(s_node *head){

    if(head==NULL){
        return NULL;
    }
    s_node *tmp=head;
    head= head->next;
    free(tmp);
    return head;
}


void list_destroy(s_node *head){

    while (head!=NULL){
             s_node *tmp=head;
            head= head->next;
            free(tmp);
    }

}







void displaylist(s_node *head, void (*display)(s_node *)){
    s_node *ptr=head;
    while (ptr !=NULL){
        (*display)(ptr);
        ptr=ptr->next; /*ptr=list_next(ptr)*/
        printf("->");
    }
    printf("NULL\n");
}