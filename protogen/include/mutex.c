/* 
Lightweight cross platform mutex wrapper for
Windows and POSIX.
*/
#ifndef _MUTEX_H
#define _MUTEX_H

#ifdef __unix__
#include <pthread.h>
typedef pthread_mutex_t mutex_t;
#endif

#ifdef _WIN32
#include <Windows.h>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"ws2_32.lib")
typedef HANDLE mutex_t;
#endif

void mutex_init(mutex_t* mutex);
void mutex_unlock(mutex_t* mutex);
void mutex_lock(mutex_t* mutex);
void mutex_destroy(mutex_t* mutex);	


#endif