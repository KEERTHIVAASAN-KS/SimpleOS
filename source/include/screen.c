int clearscreen(){
   char * video=(char *)0xb8000;
   for(int i=0;i<80*80;i++){
     video[i]=0x00;
   }
   return 0xb8000; 
}
int space(int vaddr){
 return vaddr+2;

}


int newline(int vaddr){
   int disp=(vaddr-0xb8000)%160;
   vaddr=vaddr-disp;
   vaddr+=160;
   return vaddr;
  
}


int printchar(int currentaddr,char ch){
   char * vm=(char *)currentaddr;
   if(ch=='\b'){
     vm-=2;
     vm[0]=' ';
     vm[1]=0x07;
     return currentaddr-2;
   }
   else if(ch=='\0'){
     return currentaddr;
   }
   else if(ch=='\n'){
    currentaddr=newline(currentaddr);
    return currentaddr;
   }
   
   vm[0]=ch;
   vm[1]=0x07;
   return currentaddr+2;
}

int printstr(int vaddr,char *str){
 char * vm=(char *)vaddr;
 int i=0;
 while(1){
     if(str[i]!='\0'){
     vm=(char*)printchar((int)vm,str[i]);
     i++;
     }
    else{
    break;
    }
 
 }
 return (int)vm;
}




