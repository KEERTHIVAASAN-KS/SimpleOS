bits 32


section    .text 
 	align 4 
	dd 0x1badb002
	dd 0x00
	dd - (0x1badb002 + 0x00)

extern main

global start
start:
	cli
	call main
  	hlt
