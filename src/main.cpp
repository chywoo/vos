#include <stdio.h>

#include "kernel.h"
#include "syscall.h"


void ex_ps1(void)
{
	int i;
	char msg[100];

	for ( i = 0; i < 10; i++ )
	{
		sprintf(msg, "PS1's message: %d\n", i);
		sys_print(msg);
		sys_swtch(NULL);
	}

	sys_terminate(NULL);
}


void ex_ps2(void)
{
	int i;
	char msg[100];

	for ( i = 0; i < 10; i++ )
	{
		sprintf(msg, "PS2's message: %d\n", i);
		sys_print(msg);
		sys_swtch(NULL);
	}

	sys_terminate(NULL);
}



void ex_ps3(void)
{
	int i;
	char msg[100];

	for ( i = 0; i < 10; i++ )
	{
		sprintf(msg, "PS3's message: %d\n", i);
		sys_print(msg);
		sys_swtch(NULL);
	}

	sys_terminate(NULL);
}

void main(void)
{
	kernel_init();

	create_process(ex_ps1);
	create_process(ex_ps2);
	create_process(ex_ps3);

	scheduler();
}
