/*
 Desc : 프로세스 관련 기능 등 현재 제대로 구현이 안 된 모든 커널 기능을 포함
 */
#include <memory.h>

#include "kernel.h"

#define PROC_SIZE  2


struct proc proc_list[PROC_SIZE + 1];
struct user user_list[PROC_SIZE + 1];

struct proc *p; /* 현재 프로세스의 proc */
struct user *u; /* 현재 프로세스의 user */


void kernel_init(void)
{
	/* Queue 초기화 */
	q_init();

	/* Process List 초기화 */
}

struct proc *get_process(int pid)
{
	return &proc_list[pid];
}


void create_process(void (*func)(void))
{
	int i;

	for ( i = 1; i < PROC_SIZE; i++ )
	{
		if ( proc_list[i].id == 0 )
		{
			break;
		}
	}

	memset( &proc_list[i], 0, sizeof ( struct proc ) );
	memset( &user_list[i], 0, sizeof ( struct user ) );

	proc_list[i].id = i;
	proc_list[i].u = &user_list[i];
	user_list[i].func = func;

	q_push( proc_list[i].id );
}
