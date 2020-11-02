#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "../task4/string.c"
#define STDIN   0
#define BOOL char 
#define TRUE 1
#define FALSE 0


struct word {
char* string ;
int8_t thenumberoftrials ;
int8_t thenumberofcharacters ;

} ;

BOOL occurance (char c , char* string){
int length = string_length (string);
for (int i=0 ; i<length ; i++) {
   if ((*(string+i))==c) {
   
     return TRUE ;
}
} 
return FALSE ;
}
void read_line(char*input){
while(getchar()!='\n');
for(int i =0 ; i<3;i++){
input[i]=getchar();
}
input[3]='\0';
while(getchar()!='\n');


}
void replace_all_occurence(char* string1 ,char* string2, char c){
int length = string_length(string1);
for (int i =0; i<length;i++){
   if (*(string1+i)==c)
    *(string2+i)=c;   
}
}
void play_game(struct word * arrayofwords){
  
 // initlalize the random generator
  srand(clock());
  int i = rand()%10 ;
   struct word* theword = (arrayofwords+i);
  
  printf("vous avez %d coups pour deviner le mot :\n " , (*theword).thenumberoftrials);
  char*lemotdevine = malloc (sizeof((*theword).string));
  int lenombrededevination = (*theword).thenumberoftrials ;
  //printf("%s\n",((*theword).string));              // pout tester le code
  for (int j =0 ; j<(*theword).thenumberofcharacters;j++)
  lemotdevine[j]='-';
  printf("%s\n",lemotdevine);
  
  
  while (lenombrededevination>0){
  printf("?");
  char destination ;
  do {
  destination=getchar();
  }while(destination =='\n') ;
  
  
    
     if (occurance(destination,(*theword).string)== TRUE){
     
      replace_all_occurence((*theword).string,lemotdevine,destination);
     }
    
    printf("%s\n", lemotdevine);
    lenombrededevination--; 
    int c =0  ;
   for(int j = 0; j<(*theword).thenumberofcharacters;j++){
     if (*(lemotdevine+j)==*(((*theword).string)+j))
     c++;
   
   }
   if (c==(*(arrayofwords+i)).thenumberofcharacters){
   
   free(lemotdevine);
   printf("Vous avez gagner !!\nvoulez vous jouez une autre fois?\n");
   char*input=malloc(4*sizeof(char));
   read_line(input);
   
   
   if (string_cmp(input,"oui")==0){
   for (int i =0 ; i<string_length(input);i++)
     *(input+i)='\0';
   
   free(input);
   play_game(arrayofwords);
   lenombrededevination=0;
   }
   
   else 
   return;
   
   }
   
 
  
   }
   
   return ;  
}
int main(int nargs, char** args) {
  int numberofwords = 10 ;
 
  int sizeofword = sizeof(struct word );
  struct word *arrayofwords =malloc (numberofwords*sizeofword);
  (*(arrayofwords+0)).string="Mirette"; (*(arrayofwords+0)).thenumberofcharacters=7;
  (*(arrayofwords+1)).string="hello";  (*(arrayofwords+1)).thenumberofcharacters=5;
  (*(arrayofwords+2)).string="world";   (*(arrayofwords+2)).thenumberofcharacters=5;
  (*(arrayofwords+3)).string="my";       (*(arrayofwords+3)).thenumberofcharacters=2;
  (*(arrayofwords+4)).string="name";    (*(arrayofwords+4)).thenumberofcharacters=4;
  (*(arrayofwords+5)).string="spring";  (*(arrayofwords+5)).thenumberofcharacters=6;
  (*(arrayofwords+6)).string="square";   (*(arrayofwords+6)).thenumberofcharacters=6;
  (*(arrayofwords+7)).string="hiver";   (*(arrayofwords+7)).thenumberofcharacters=5;
  (*(arrayofwords+8)).string="sphere";  (*(arrayofwords+8)).thenumberofcharacters=6;
  (*(arrayofwords+9)).string="circle";   (*(arrayofwords+9)).thenumberofcharacters=6;
  for (int i =0 ; i<10 ; i++)
  (*(arrayofwords+i)).thenumberoftrials =10 ;
  play_game(arrayofwords);
  free(arrayofwords);
 
   
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  printf("Bye.\n");
}
