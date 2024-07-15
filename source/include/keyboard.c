#include "io.c"

char chr(int c){

 if(c==0x1e){
 return 'a';
 }
 else if(c==0x30){
 return 'b';
 }
 else if(c==0x2e){
 return 'c';
 }
 else if(c==0x20){
 return 'd';
 }
 else if(c==0x12){
 return 'e';
 }
 else if(c==0x21){
 return 'f';
 }
 else if(c==0x22){
 return 'g';
 }
 else if(c==0x23){
 return 'h';
 }
 else if(c==0x17){
 return 'i';
 }
 else if(c==0x24){
 return 'j';
 }
 else if(c==0x25){
 return 'k';
 }
 else if(c==0x26){
 return 'l';
 }
 else if(c==0x32){
 return 'm';
 }
 else if(c==0x31){
 return 'n';
 }
 else if(c==0x18){
 return 'o';
 }
 else if(c==0x19){
 return 'p';
 }
 else if(c==0x10){
 return 'q';
 }
 else if(c==0x13){
 return 'r';
 }
 else if(c==0x1f){
 return 's';
 }
 else if(c==0x14){
 return 't';
 }
 else if(c==0x16){
 return 'u';
 }
 else if(c==0x2f){
 return 'v';
 }
 else if(c==0x11){
 return 'w';
 }
 else if(c==0x2d){
 return 'x';
 }
 else if(c==0x15){
 return 'y';
 }
 else if(c==0x2c){
 return 'z';
 }
 else if(c==0x39){
 return ' ';
 }
 else if(c==0x1c){
 return '\n';
 }
 else if(c==0xe){
 return '\b';
 }
 else if(c==0x02){
 return '1';
 }
 else if(c==0x03){
 return '2';
 }
 else if(c==0x04){
 return '3';
 }
 else if(c==0x05){
 return '4';
 }
 else if(c==0x06){
 return '5';
 }
 else if(c==0x07){
 return '6';
 }
 else if(c==0x08){
 return '7';
 }
 else if(c==0x09){
 return '8';
 }
 else if(c==0xa){
 return '9';
 }
 else if(c==0xb){
 return '0';
 }
 else if(c==0x49){
 return '+';
 }
 else if(c==0xc){
 return '-';
 }
 else if(c==0x37){
 return '*';
 }
 
 else{
 return '\0';
 
 }
 
}



int keyboardstatus(){
    int status=(int)inb(0x64);
    if(status & 0x01){
      return 1;
    }
    else{
      return 0;
    }
}

char readfromkeyboard(){
   while(!keyboardstatus()){
   }
   return chr(inb(0x60));
  
}
void init_kbd(){
  outb(0x64,0xAD);//disabing mouse 
  outb(0x64,0xA7);//disabling keyboardd
  outb(0x64,0xAE);//enabling keyboard
}

void clearbuffer(){
  while(((int)inb(0x64)>>1)&0x01!=0){
  }
  outb(0x64,0xF4);
}


