/*KONTOPOULOS MICHAIL
 SYMTABLE.H
 ASK3 2788 */

#include "symtable.h"

typedef struct node{
  char *key;
  void *value;
  struct node *next;
}*node;

struct symtable {
  unsigned int count;
  node head;
};

/*new empty Symtable*/
SymTable_T SymTable_new(void){
  SymTable_T smtb;
  node NewNode=malloc(sizeof(struct node));
  smtb=malloc(sizeof(struct symtable));
  NewNode->key=NULL;
  NewNode->value=NULL;
  NewNode->next=NULL;
  smtb->count=0;
  smtb->head=NewNode;
  return smtb;
}

/*Frees the symtable except if it's already NULL then do nothing*/
void SymTable_free(SymTable_T oSymTable){
  node head,ptr;
  if (oSymTable==NULL)
    return;
  head=oSymTable->head;
  while(head!=NULL){
    ptr=head->next;
    free(head->key);
    free(head);
    head=ptr;
  }
  free(oSymTable);
}

/*returns the count number (bindings) of the symtable */
unsigned int SymTable_getLength(SymTable_T oSymTable){
  assert(oSymTable!=NULL);
  return (oSymTable->count);
}

/*1 if unique pcKey is found,0 if not (Assert for null pcKey or Symtable free*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
  node ptr;
 assert(pcKey && oSymTable);
  ptr=oSymTable->head;
  while (ptr!=NULL){
    if (ptr->key!=NULL&&strcmp(ptr->key,pcKey)==0)
      return 1;
    ptr=ptr->next;
  }
  return 0;
}

/*Check if newnode=null,newnode->key=null and if symtable contains the key or not,if not adds the key and increment +1 the count of bindings*/
int SymTable_put(SymTable_T oSymTable, const char *pcKey,
                 const void *pvValue){
  node NewNode,head;
  assert(pcKey && oSymTable);
  if(SymTable_contains(oSymTable,pcKey))
    return 0;
  NewNode=malloc(sizeof(struct node));
  if (NewNode==NULL){
    printf("ALLOCATION FAILED\n");
    exit(0);
  }
  head = oSymTable->head;
  NewNode->key=malloc((strlen(pcKey)+1)*sizeof(char));/*Allocates length of char +1 * size of char (1 byte) */
  if(NewNode->key==NULL){
    printf("ALLOCATION FAILED\n");
    exit(0);
  }
  strcpy(NewNode->key, pcKey);
  NewNode->value=(void*)pvValue;
  NewNode->next=head;
  head = NewNode;
  oSymTable->head=head;
  oSymTable->count++;
  return 1;
}

/* if pcKey is found then remove it if not return 0*/
int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
  node ptr, prev;
  assert(pcKey && oSymTable);
  prev=NULL;
  ptr=oSymTable->head;
  while(ptr!=NULL){
    if(ptr->key!=NULL&&strcmp(ptr->key,pcKey)==0)
      break;
    else{
    prev=ptr;
    ptr=ptr->next;
    }
  }
  if (ptr==NULL)
    return 0;
  if (prev==NULL)
    oSymTable->head=ptr->next;
  else
    prev->next=ptr->next;
  free(ptr->key);
  free(ptr);
  oSymTable->count--;
  return 1;
}


/*returns value of the exact pcKey,if found else return 0*/
void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
  node ptr;
  assert(pcKey && oSymTable);
  ptr=oSymTable->head;
  while(ptr!=NULL) {
    if (ptr->key!=NULL&&strcmp(ptr->key,pcKey)==0)
      return ptr->value;
    ptr = ptr->next;
  }
  return 0;
}

