/*Onoma:Mixahl
Epi8eto:Kontopoulos
AM:2788
Askhsh 1h. ask1.c */
#include <stdio.h>
#include <stdlib.h>
#define tonos 39
 
 
 
 int stateMorN(int current,int arrGreekCapital[24],int arrGreekSmall[24],int arrLatinCapital[24],int arrLatinSmall[24]){		/*State Machine gia Mp,MP,mP,mp,Nt,NT,nt,NT.*/
  int tmp;
  if (current==204){ 			/*an M*/
    tmp=getchar();
	if((tmp==208)||(tmp==240)){ 
	      printf("B");
	      return 1;
	}
	else{
	    ungetc(tmp,stdin);
	    putchar(arrLatinCapital[current-arrGreekCapital[0]]);
	    return 1;
	}
  }
  else if(current==236){		/*an m*/
    tmp=getchar();
	if((tmp==208)||(tmp==240)){
	  printf("b");
	  return 1;
	}
	else
	{
	    ungetc(tmp,stdin);
	    putchar(arrLatinSmall[current-arrGreekSmall[0]]);
	  return 1;
	}
  }
    
  if (current==205){		
    tmp=getchar();
	if((tmp==244)||(tmp==212)){	/*an N*/
	  printf("D");             	
	  return 1;
	}
	else{
	  ungetc(tmp,stdin);
	  putchar(arrLatinCapital[current-arrGreekCapital[0]]);
	  return 1;
	}
  }
  else if (current==237){		/*an n*/	
    tmp=getchar();
	if((tmp==244)||(tmp==212)){
	  printf("d");
	  return 1;
	}
	else{
	  ungetc(tmp,stdin);
	  putchar(arrLatinSmall[current-arrGreekSmall[0]]);
	  return 1;
	}
      }
 return 0;   
}


int stateIdentify(int character,int arrGreekCapital[24],int arrGreekSmall[24],int arrLatinCapital[24],int arrLatinSmall[24],int GreekSmallTonoi[7],
		  int GreekCapTonoi[7],int LatinSmallTonoi[7],int LatinCapitalTonoi[7]){										/*Sunarthsh gia prosdiorismo tou xarakthra.*/
 int i;
 int j;
	
	for (i=0;i<24;i++){
	  if (character==arrGreekCapital[i]){		/*Elegxos gia to an einai Kefalaio*/
	    if((character==204)||(character==205))	/*an M or N gia FSM  */
	      stateMorN(character,arrGreekCapital,arrGreekSmall,arrLatinCapital,arrLatinSmall);
	    else if (character==206)			/*KS kefalaio*/
	      printf("KS");
	    else if (character==216)			/*PS kefalaio*/
	      printf("PS");
	    else
	      putchar(arrLatinCapital[i]);		/*printarei kanonika to anagnwrismeno gramma*/
 	    return 1;
	  }
	  else if (character==arrGreekSmall[i]){	/*Elegxos gia to an einai Mikro*/
	    if((character==236)||(character==237))	/*an m or n*/
	      stateMorN(character,arrGreekCapital,arrGreekSmall,arrLatinCapital,arrLatinSmall);  
	    else if (character==238)			/*ks mikro*/
	      printf("ks");
	    else if (character==248)			/*ps mikro*/
	      printf("ps");
	    else
	      putchar(arrLatinSmall[i]);		/*printarei kanonika to anagnwrismeno gramma*/
	      return 1;
	  }
	}
	for(j=0;j<7;j++){				/*Elegxoume tonismena Kefalaia*/
	  if (character==GreekCapTonoi[j]){
	    putchar(tonos); 				/*Pros8etoume tono kai ektupwnoume*/
	    putchar(LatinCapitalTonoi[j]);
	    return 1;
	  }
	  else if(character==GreekSmallTonoi[j]){	/*Elegxoume tonismena mikra*/
	    putchar(LatinSmallTonoi[j]);		/*Pros8etoume tono kai ektupwnoume.*/
	    putchar(tonos);
	    return 1;
	  }
	}
	if (character==192){
	  printf("i");
	  putchar(tonos);
	  putchar(34);
	  return 1;
	}
	else if(character==224){
	  printf("y");
	  putchar(tonos);
	  putchar(34);
	  return 1;
	}
	else if(character==250){
	  printf("i");
	  putchar(tonos);
	  putchar(tonos);
	  return 1;
	}
	else if(character==251){
	  printf("y");
	  putchar(tonos);
	  putchar(tonos);
	  return 1;
	  }
	 if(character==EOF)				/*An einai EOF,vgainoume apo sunarthsh kai epeita apo main.*/
	  return 0;
	  printf("%c",character);			/*An einai mh anagnwrisimo opws shmeio sti3hs,sumvola klp,to ektupwnoume*/
	  return 1;
  
}




int main()				/*diavazei ews otou anagnwristei o xarakthras EOF,epeita apo klhsh ths sugkekrimenhs sunarthshs prosdiorismou.*/
{  
    int arrGreekCapital[24]={193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,211,212,213,214,215,216,217};
    int arrGreekSmall[24]={225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,243,244,245,246,247,248,249};
    int arrLatinCapital[24]={65,86,71,68,69,90,72,56,73,75,76,77,78,75,79,80,82,83,84,89,70,88,80,87};
    int arrLatinSmall[24]={97,118,103,100,101,122,104,56,105,107,108,109,110,107,111,112,114,115,116,121,102,120,112,119};
    int GreekSmallTonoi[7]={220,221,222,223,252,253,254};
    int GreekCapTonoi[7]={182,184,185,186,188,190,191};
    int LatinSmallTonoi[7]={97,101,104,105,111,121,119};
    int LatinCapitalTonoi[7]={65,69,72,73,79,89,87};
    int character;
    int y=0;
    while(character!=EOF){
	character=getchar();
	 
	y=stateIdentify(character,arrGreekCapital,arrGreekSmall,arrLatinCapital,arrLatinSmall,GreekSmallTonoi,GreekCapTonoi,LatinSmallTonoi,LatinCapitalTonoi);
	if (y==0)
	  return 0;
	        
    }
    return 1;
}

 

