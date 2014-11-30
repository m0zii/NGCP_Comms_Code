/* 

Lightweight cross platform thread wrapper for
Windows and POSIX.

*/
#ifndef _THREAD_H
#define _THREAD_H

#ifdef _WIN32
#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"ws2_32.lib")
typedef HANDLE thread_t;
#endif


#ifdef __unix__
#include <pthread.h>
typedef pthread_t thread_t;
#endif

extern "C"
{

void thread_create(thread_t* thread, void *(*start_routine) (void *), void* arg);
void thread_set_priority(thread_t* thread, int32_t priority);
thread_t thread_get_self_id();
}


#endif
