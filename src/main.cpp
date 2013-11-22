#include <stdio.h>

#include "kernel.h"
#include "syscall.h"


void ex_ps1(void)
{
	sys_print("EX_PS1's first message.");
	sys_swtch(NULL);
	
	sys_print("EX_PS1's second message.");
	sys_swtch(NULL);
	sys_print("EX_PS1's third message.");

	sys_terminate(NULL);
}


void ex_ps2(void)
{
	sys_print("EX_PS2's first message.");
	sys_swtch(NULL);
	sys_print("EX_PS2's second message.");

	sys_terminate(NULL);
}



void main(void)
{
	kernel_init();

	create_process(ex_ps1);
	create_process(ex_ps2);

	scheduler();
}
