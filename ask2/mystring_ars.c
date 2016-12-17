/* 
 A.M:2788
 KONTOPOULOS MICHAIL
 mystring_ars.c */
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "mystring.h"
/* Return the length of string pcStr.
   It is a checked runtime error for pcStr to be NULL. */
size_t ms_length(const char pcStr[])
{
  size_t uiLength= 0U;
  assert(pcStr != NULL);
  while (pcStr[uiLength] != '\0')
    uiLength++;
  return uiLength;
} 
/* Copies the source string to destination string
 There is a runtime error for source/destination being NULL*/ 
char *ms_copy(char destination[],const char source[])
{
  int y;
  int x;
  y=ms_length(source);
  assert((destination != NULL)||(source != NULL));
  for (x=0;x<y;x++)
  {
    destination[x]=source[x];
  }
  destination[y]='\0';
  return destination;
}
/* Copies the first n chars of source string to destination string
 There is a runtime error for source/destination being NULL and N being more than source chars*/ 
char *ms_ncopy(char destination[],const char source[],size_t n)
{
  int x;
  assert((destination != NULL)||(source != NULL));
  assert(n<=ms_length(source));
  for (x=0;x<n;x++)
  {
    destination[x]=source[x];
  }
  destination[x]='\0';
  return destination;
}
/* Concat..s source string to destination string
 There is a runtime error for source/destination being NULL.*/ 
char *ms_concat(char destination[], const char source[])
{
  int x;
  int l;
  assert((destination != NULL)||(source != NULL)); 
  x=ms_length(destination);
  for(l=0;l<=ms_length(source);l++)
    destination[x++]=source[l];
  ;
  return destination;
}
/* Concat..s the first n chars of source string to destination string
 * There is a runtime error for source/destination being NULL and N being more than source chars*/ 
char *ms_nconcat(char destination[],const char source[],size_t n)
{
  int x;
  int l;
  assert((destination != NULL)||(source != NULL));
  assert(n<=ms_length(source));
  x=ms_length(destination);
  for(l=0;l<n;l++)
    destination[x++]=source[l];
  return destination;
}
/* Compares str2 string to str1 string char by char
 There is a runtime error for source/destination being NULL*/  
int ms_compare(const char str1[], const char str2[])
{
  int x;
  assert((str1 != NULL)||(str2!= NULL));
    if (ms_length(str1)>ms_length(str2))
     return 1;
   else if (ms_length(str1)<ms_length(str2))
     return -1;
  
  for(x=0;x<ms_length(str1);x++){
      if (str1[x]!=str2[x])
	return str1[x]-str2[x];
  }
  return 0;
}
/* Compares the first n chars of str2 and str1 string char by char.
 There is a runtime error for source/destination being NULL and N being more than source/destination chars*/ 
int ms_ncompare(const char str1[],const char str2[],size_t n)
{
  int x;
  assert((str1 != NULL)||(str2!= NULL));
  assert(n<ms_length(str1)+1);
  assert(n<ms_length(str2)+1);
  for(x=0;x<n;x++){
    if (str1[x]!=str2[x])
     return str1[x]-str2[x];
  }
  return 0;
}

  

 
