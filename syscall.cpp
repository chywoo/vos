#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <memory.h>

#include "syscall.h"


int sys_terminate(void *arg)
{
	p->state = STAT_TERM;

	return 0;
}

int sys_print(void *arg)
{
	char *str;

	str = (char *)arg;

	puts(str);

	return 0;
}

int sys_swtch(void *arg)
{
	unsigned long r_esp;
	unsigned long r_ebp;

	char swtch_stack;

	
	p->state = STAT_SLEEP;

	u->stack_pointer = (void *)&swtch_stack;
	u->stack_size = start_p - (int)&swtch_stack;
	u->stack = malloc( u->stack_size );

	_asm
	{
		mov r_esp, esp;
		mov r_ebp, ebp;
	}

#ifdef DEBUG
	printf (" > SP: %x, BP: %x\n", r_esp, r_ebp );
#endif

	u->esp = r_esp;
	u->ebp = r_ebp;
	
	memcpy( u->stack, (void *)&swtch_stack, u->stack_size );

	if ( setjmp(u->ctx_state) == 0 )
	{
		q_push( p->id );
		longjmp( sche_buf, 1 );
	}
	else
	{
		// Context Switch되어서 돌아온 경우
	}

	return 0;
}
