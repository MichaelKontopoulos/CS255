/*KONTOPOULOS MICHAIL SYMTABLE.H 
  AM 2788*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>



typedef struct symtable *SymTable_T;
SymTable_T SymTable_new(void);
void SymTable_free(SymTable_T oSymTable);
unsigned int SymTable_getLength(SymTable_T oSymTable);
int SymTable_put(SymTable_T oSymTable, const char *pcKey,const void *pvValue);
int SymTable_remove(SymTable_T oSymTable, const char *pcKey);
int SymTable_contains(SymTable_T oSymTable, const char *pcKey);
void *SymTable_get(SymTable_T oSymTable, const char *pcKey);

