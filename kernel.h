#ifndef __KERNEL_H__
#define __KERNEL_H__

#include <setjmp.h>

#ifdef __cplusplus
extern "C" {
#endif


struct proc
{
	int id;
	int state;
	struct user *u;
};

#define STAT_NORMAL	0
#define STAT_TERM	1
#define STAT_IO		2
#define STAT_SLEEP	3 /* Context Switching 발생시 설정 */

struct user
{
	void (*func)();

	/* Stack Data Backup */
	void *stack_pointer;
	int  stack_size;
	void *stack;
	jmp_buf ctx_state;

	/* CPU state vector */
	unsigned long esp;
	unsigned long ebp;
};

extern struct proc *p; /* 현재 프로세스의 proc */
extern struct user *u; /* 현재 프로세스의 user */

/* Kernel */
void kernel_init(void);


/* Process */
struct proc *get_process(int pid);
void create_process(void (*func)(void));


/* Queue */
void q_init();
int q_pop();
void q_push(int data);

/* Scheduler */
void scheduler();

#ifdef __cplusplus
}
#endif

#endif __KERNEL_H__
