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


s_node *list_orderedAppend(s_node **head,int (*compare)(s_node *, void *),
void *param){
    
    s_node *tmp=*head;
    s_node *nouveau=(s_node *)malloc(sizeof(s_node));
    if(nouveau==NULL){
        return *head;
    }
    nouveau->data=param;
    // si la liste est vide on insere le nouveau node et on retourne le nouveau node
    if(*head==NULL){
        nouveau->next=NULL;
        *head=nouveau;
        return nouveau;
    }
    int i=  compare(tmp,param);
    if(i>0 ){ //node->data > data return >0
        nouveau->next=tmp;
        *head=nouveau;
        return nouveau;
    }
    s_node *prec=tmp;
    while (tmp!=NULL && i<0 ){ //node->data < data return <0
        prec=tmp;
        tmp=tmp->next;
        if (tmp != NULL){
            i = compare(tmp, param);
        }              
    }

    if (i==0){
        free(nouveau);
        return tmp;
    }
    if (tmp==NULL){
        prec->next=nouveau;
        nouveau->next=NULL;
        return nouveau;
    }
    
    prec->next=nouveau;
    nouveau->next=tmp;
    return nouveau;
     

}

s_node *list_remove(s_node *head,void *data){

        s_node *tmp=head;
        s_node *prec=NULL;
// si on est pas a la fin de la liste chainé et la valeure de datat est diferencte de celle qu'on veut supprimer 
        while(tmp!= NULL && tmp->data != data){
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