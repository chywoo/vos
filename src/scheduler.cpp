/*
 Desc : 스케줄러 기능
 */
#include <stdio.h>
#include <setjmp.h>
#include <memory.h>

#include "kernel.h"


int start_p;
jmp_buf sche_buf;

void scheduler()
{
	int pid;
	unsigned long r_sp, r_bp;
	

	char stackstart;

	start_p = (int)&stackstart;

	setjmp(sche_buf);

#ifdef DEBUG
	_asm
	{
		mov r_sp, esp;
		mov r_bp, ebp;
	}

	printf ("SP: %x, BP: %x\n", r_sp, r_bp );
#endif

	while(1)
	{
		
		pid = q_pop();
		
		if ( pid == 0 )
		{
			break;
		}

		/* 현재 프로세스를 전역 변수 p, u에 저장 */
		p = get_process(pid);
		u = p->u;

		if ( p->state == STAT_SLEEP )
		{
			r_sp = u->esp;
			r_bp = u->ebp;

			_asm
			{
				mov esp, r_sp;
				mov ebp, r_bp;
			}

			memcpy( (void *)u->stack_pointer, u->stack, u->stack_size );


#ifdef DEBUG
			_asm
			{
				mov r_sp, esp;
				mov r_bp, ebp;
			}

			printf (" new SP: %x, BP: %x\n", r_sp, r_bp );
#endif

			longjmp( u->ctx_state, -1 );
		}
		else
		{
			u->func();

			if ( p->state != STAT_TERM )
			{
				q_push(p->id);
			}
		}
	}
}
