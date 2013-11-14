/*
 Desc : 프로세스의 Ready Queue 기능
 */
#include <stdio.h>

#include "kernel.h"

#define QUEUE_SIZE 10


static int ready_queue[QUEUE_SIZE];
static int q_first, q_last;


void q_init()
{
	q_first = 0;
	q_last = 0;
}


int q_pop()
{
	int i;

	/* 데이터가 없을 경우 0을 리턴 */
	if ( q_first == q_last ) 
		return 0;

	i = ready_queue[q_first];

	q_first = ( q_first + 1 ) % QUEUE_SIZE;

	return i;
}


void q_push(int data)
{
	ready_queue[q_last] = data;
	q_last = ( q_last + 1 ) % QUEUE_SIZE;
}
