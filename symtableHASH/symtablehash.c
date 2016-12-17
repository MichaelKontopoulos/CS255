/*KONTOPOULOS MICHAIL
 * SYMTABLEHASH.C 2788
 */

#include "symtable.h"
#define DEFAULT    509
#define HASH_MULTIPLIER 65599

typedef struct node {
  char *key;
  void *value;
  struct node *next;
} *node;

struct symtable {
  unsigned int count;
  node table[DEFAULT];
};

static unsigned int SymTable_hash(const char *pcKey) {
  int i;
  unsigned int uiHash = 0U;
  for (i = 0; pcKey[i] != '\0'; i++)
    uiHash=uiHash*HASH_MULTIPLIER+pcKey[i];
  return (uiHash%DEFAULT);
}

SymTable_T SymTable_new(void){
  int i;
  SymTable_T smtb;
  node newnode;
  smtb=malloc(sizeof(struct symtable));
  newnode=malloc(sizeof(struct node));
  newnode->key=NULL;
  newnode->next=NULL;
  newnode->value=NULL;
  smtb->count = 0;
  for (i=0;i<DEFAULT;i++)
    smtb->table[i]=newnode;
  return smtb;
}


void SymTable_free(SymTable_T oSymTable){
  node ptr,head;
  int i;
  if (oSymTable==NULL)
    return;
  for (i=0;i<DEFAULT;i++) {
    head=oSymTable->table[i];
    while(head!=NULL) {
      if (head->next==NULL) 
      break;
	else{
      ptr=head->next;
      free(head->key);
      free(head);
      head=ptr;
      }
    }
  }
  free(head); 
  free(oSymTable);
}

unsigned int SymTable_getLength(SymTable_T oSymTable){
  assert(oSymTable!=NULL);
  return (oSymTable->count);
}

int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
  node ptr;
  int hashcode;
  assert(pcKey&&oSymTable);
  hashcode=SymTable_hash(pcKey);
  ptr=oSymTable->table[hashcode];
  while(ptr!=NULL) {
    if(ptr->key!=NULL&&strcmp(ptr->key,pcKey)==0)
      return 1;
    ptr=ptr->next;
  }
  return 0;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey,const void *pvValue){
  node head;
  node newnode;
  int hashcode;
  assert(pcKey&&oSymTable);
  if (SymTable_contains(oSymTable,pcKey))
    return 0;
  newnode=malloc(sizeof(struct node));
  hashcode=SymTable_hash(pcKey);
  head=oSymTable->table[hashcode];
  newnode->key = malloc((strlen(pcKey)+1)*sizeof(char));
  strcpy(newnode->key,pcKey);  
  newnode->value=(void *)pvValue;
  newnode->next=head; 
  head=newnode;
  oSymTable->table[hashcode]=head; 
  oSymTable->count++;
  return 1;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
  int hashcode;
  node ptr;
  node prev;
  assert(pcKey&&oSymTable);
  hashcode=SymTable_hash(pcKey);
  ptr=oSymTable->table[hashcode];
  prev=NULL;
  while(ptr!=NULL) {
    if (ptr->key!=NULL&&strcmp(ptr->key,pcKey) == 0)
      break;
    else{
    prev=ptr;
    ptr=ptr->next;
    }
  }
  if (ptr==NULL)
    return 0;
  if (prev==NULL) 
    oSymTable->table[hashcode]=ptr->next;
  else
    prev->next=ptr->next;
  free(ptr->key);
  free(ptr);
  oSymTable->count--;
  return 1;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
  node ptr;
  int hashcode;
  assert(pcKey&&oSymTable);
  hashcode=SymTable_hash(pcKey);
  ptr=oSymTable->table[hashcode];
  while (ptr!=NULL) {
    if (ptr->key!=NULL&&strcmp(ptr->key,pcKey)==0)
      return ptr->value;
    ptr=ptr->next;
  }
  return NULL;
}

