/*
 * Kernel.cpp
 *
 * Copyright (C) 2013, 2013 Sungh Park
 *
 * ���μ��� ���� ��� �� ���� ����� ������ �� �� ��� Ŀ�� ����� ����
 */
#include <memory.h>

#include "kernel.h"

#define PROC_SIZE  1024


struct proc proc_list[PROC_SIZE + 1];
struct user user_list[PROC_SIZE + 1];

struct proc *p; /* ���� ���μ����� proc */
struct user *u; /* ���� ���μ����� user */


void kernel_init(void)
{
	/* Queue �ʱ�ȭ */
	q_init();

	/* Process List �ʱ�ȭ */
}

struct proc *get_process(int pid)
{
	return &proc_list[pid];
}


/*
 * Create process structure and put it in ready queue array.
 * In this time, application is made by only function. It seems to be a thread.
 * Parameters:
 *    - func: a function pointer to a function for application.
 */
int create_process(void (*func)(void))
{
	int i;

	for ( i = 1; i < PROC_SIZE; i++ )
	{
		if ( proc_list[i].id == 0 )
		{
			break;
		}
	}

	if ( i == PROC_SIZE )
		return -1;

	memset( &proc_list[i], 0, sizeof ( struct proc ) );
	memset( &user_list[i], 0, sizeof ( struct user ) );

	proc_list[i].id = i;
	proc_list[i].u = &user_list[i];
	user_list[i].func = func;

	q_push( proc_list[i].id );
}
