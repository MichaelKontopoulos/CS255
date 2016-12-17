/* 
 A.M:2788
 KONTOPOULOS MICHAIL
 mystring_ptrs.c */
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "mystring.h"

/* Return the length of string pcStr.
   It is a checked runtime error for pcStr to be NULL. */
size_t ms_length(const char *pcStr)
{
  const char *pcStrEnd;
  pcStrEnd = pcStr;
  assert(pcStr != NULL);
  while (*pcStrEnd != '\0')
    pcStrEnd++;
  return pcStrEnd - pcStr;
} 

/* Copies the source string to destination string
 There is a runtime error for source/destination being NULL*/ 
char *ms_copy( char * destination, const char * source ) {
  char *tmp;
  tmp=destination;
  assert((destination != NULL)||(source != NULL));
  while(*source!='\0'){
    *destination=*source;
     destination++;
     source++;
    
  }
  *destination='\0';
   return tmp; 
}
/* Copies the first n chars of source string to destination string
 There is a runtime error for source/destination being NULL and N being more than source chars*/ 
char *ms_ncopy(char *destination, const char *source, size_t n){
  int i;
  char *tmp;
  assert((destination != NULL)||(source != NULL));
  assert(n<=ms_length(source));
  tmp=destination;
  for (i = 0; i<n; i++){
    *destination++ = *source++;
  }
  *destination='\0';
  return tmp;

}

/* Concat..s source string to destination string
 There is a runtime error for source/destination being NULL.*/ 
char *ms_concat(char *destination, const char *source)
{
  char *tmp;
  tmp=destination;
  assert((destination != NULL)||(source != NULL)); 
  while(*destination!='\0')
    destination++;
   ;
  while(*source!='\0')
    *destination++=*source++;
  ;
  *destination='\0';
  return tmp;
}
/* Concat..s the first n chars of source string to destination string
 * There is a runtime error for source/destination being NULL and N being more than source chars*/ 
char *ms_nconcat(char *destination,const char *source,size_t n)
{
  
  int i=0;
  char *tmp;
  tmp=destination;
  assert((destination != NULL)||(source != NULL));
  assert(n<=ms_length(source));
  while(*destination!='\0')
    destination++;
  ;
  for (;i<n;i++)
    *destination++=*source++;
  *destination='\0';
  return tmp;
}
/* Compares str2 string to str1 string char by char
 There is a runtime error for source/destination being NULL*/   
int ms_compare(const char *str1, const char *str2)
{
  assert((str1 != NULL)||(str2!= NULL)); 
  if (ms_length(str1)>ms_length(str2))
     return 1;
   else if (ms_length(str1)<ms_length(str2))
     return -1;
     else
   {
     while(*str1!='\0'){
       if ((*str1)!=(*str2))
	 return *str1-*str2;
     *str1++;
     *str2++;
     }
   }
   return 0;
}
/* Compares the first n chars of str2 and str1 string char by char.
 There is a runtime error for source/destination being NULL and N being more than source/destination chars*/ 
int ms_ncompare(const char *str1,const char *str2,size_t n)
{
  int y;
  assert((str1 != NULL)||(str2!= NULL));
  assert(n<ms_length(str1)+1);
  assert(n<ms_length(str2)+1);
  for(y=0;y<n;y++,str1++,str2++){
       if ((*str1)!=(*str2))
       { 
	 return *str1-*str2;
       }
     }
  return 0;
}

/*Searches for the place of character c to string s*/
char *ms_char( char *s,int c)
{
    char ch; 
    ch=c;
  for ( ; *s != ch; s++)
        if (*s == '\0')
            return 0;
    return s;
}
/*Searches for the string 2 to string1 and prints the next chars*/
char *ms_search(char *s1,char *s2)
{
  const size_t len = ms_length(s2);

  for (; (s1 = ms_char(s1,*s2))!= 0; s1++)
    {
      if (ms_ncompare(s1,s2,len) == 0)
    return s1;
    }
  return (0);
}




  
  
  
