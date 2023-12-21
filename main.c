#include <stdio.h>
#include <stdlib.h>
int main() {
   /*#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);        
      freopen("output.txt", "w", stdout);
   #endif*/
   FILE *file;
   file = fopen("MENU.txt", "r");
   char buffer[2]; 
   while(fgets(buffer, sizeof(buffer), file) != NULL) {
      printf("%s", buffer);
   }
   fclose(file);
   int x;
   scanf("%d",&x);
   if(x == 1){
      system("cls"); 
   }
   scanf("%d",&x);
   return 0;
}
