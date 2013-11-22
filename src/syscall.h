#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "kernel.h"


extern int start_p; // scheduler의 스택 메모리 끝 주소
extern jmp_buf sche_buf; // scheduler의 jump buffer

int sys_terminate(void *arg);
int sys_print(void *arg);
int sys_swtch(void *arg);

#endif __SYSCALL_H__
