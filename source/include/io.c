char inb(unsigned int port){
    char c;
   asm("inb %1,%0":"=a" (c) :"Nd"(port));
   return c;
}

void outb(int port,char value){
 asm("outb %0,%1":"=a"(value):"dN"(port));

}
