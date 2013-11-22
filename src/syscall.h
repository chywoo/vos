#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "kernel.h"


extern int start_p; // scheduler�� ���� �޸� �� �ּ�
extern jmp_buf sche_buf; // scheduler�� jump buffer

int sys_terminate(void *arg);
int sys_print(void *arg);
int sys_swtch(void *arg);

#endif __SYSCALL_H__
