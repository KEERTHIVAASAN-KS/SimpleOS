#include "include/screen.c"
#include "include/keyboard.c"

void main(){
  
  int v=0xb8000;
  char * vm=(char *)v;
  v=clearscreen();
  
  init_kbd();
  while(1){
  
   char chr=readfromkeyboard();
   v=printchar(v,chr);
  }
     
}
