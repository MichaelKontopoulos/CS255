#include "symtable.h"

int main(){
SymTable_T oSymTable=SymTable_new();
SymTable_put(oSymTable,"root","1");
SymTable_put(oSymTable,"law","2");
SymTable_put(oSymTable,"moon","3");
SymTable_put(oSymTable,"dog","4");
SymTable_put(oSymTable,"cat","5");
SymTable_put(oSymTable,"worth","6");
SymTable_put(oSymTable,"greetings","7");
SymTable_remove(oSymTable,"greetings");
SymTable_remove(oSymTable,"cat");
printf("%s\n",(char*)SymTable_get(oSymTable,"worth"));
 
if (SymTable_contains(oSymTable,"root"))
		fprintf(stdout,"FOUND!!!\n");
  else 
		fprintf(stdout,"NOT FOUND !!!\n");
if (SymTable_contains(oSymTable,"cat"))
		fprintf(stdout,"FOUND!!!\n");
  else 
		fprintf(stdout,"NOT FOUND!!!\n");
		
printf("%d\n",SymTable_getLength(oSymTable));
        
        
  printf("root=%s\n",(char*)SymTable_get(oSymTable,"root"));
  SymTable_free(oSymTable);
 
  return 0;
}
