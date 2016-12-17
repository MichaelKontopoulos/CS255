/* 
 A.M:2788
 KONTOPOULOS MICHAIL
 mystring.h */
size_t ms_length(const char *pcStr);
char *ms_copy(char *destination,const char *source);
char *ms_ncopy(char *destination,const char *source,size_t n);
char *ms_concat(char *dest, const char *src);
char *ms_nconcat(char *destination,const char *source,size_t n);
int ms_compare( const char *str1, const char *str2 );
int ms_ncompare(const char *str1,const char *str2,size_t n);
char *ms_char( char *s,int c);
char *ms_search(char *s1,char *s2);
