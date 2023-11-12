#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * reverse_string(const char * s){
   int i, n = strlen(s);
   char * rev = (char *)malloc(sizeof(char)*n);
   for(i=0; i<n; i++){
      rev[i] = s[n-1-i];
   }
   return rev;// we free s elsewhere
}


int main(void){
   char buf[80]= {'\n', 'w', 'h', 'a', '?', '\0'};
   char *s= (char *)malloc(sizeof(char));
   char *t, *m =(char *)malloc(sizeof(char));
   s[0] = '\0';
   m[0] = '\0';
   fgets(buf, sizeof(buf), stdin);
   t = strchr(buf, '\n');
   *t = '\0';
   //printf("%s", buf);
   while(strcmp(buf, "done") != 0){
   
     s = realloc( s, strlen(s)+1+strlen(buf)+1 );
     t = reverse_string(buf);
     m = realloc( m, strlen(buf)+1);
     strcpy(m, t);
     m[strlen(t)] = '\n';
     m[strlen(t)+1] = '\0';
     strcat( s, m );
     printf("%s\n", s);
     free(t);
     t = NULL;
     fgets(buf, sizeof(buf), stdin);
     t = strchr(buf, '\n');
     *t = '\0';
   }
   
   //printf("%s<-first str", s);
   free(m);
   free(s);
   return 0;
}
