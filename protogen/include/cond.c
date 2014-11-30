/* 

Lightweight cross platform condition variable
wrapper for Windows and POSIX.

*/

#ifndef _COND_H
#define _COND_H
#include <mutex.h>

#ifdef __unix__
#include <pthread.h>
typedef pthread_cond_t cond_t;
#endif

#ifdef _WIN32

#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"ws2_32.lib")

typedef struct cond_s
{
  int waiters_count_;
  // Number of waiting threads.

  CRITICAL_SECTION waiters_count_lock_;
  // Serialize access to <waiters_count_>.

  HANDLE sema_;
  // Semaphore used to queue up threads waiting for the condition to
  // become signaled. 

  HANDLE waiters_done_;
  // An auto-reset event used by the broadcast/signal thread to wait
  // for all the waiting thread(s) to wake up and be released from the
  // semaphore. 

  size_t was_broadcast_;
  // Keeps track of whether we were broadcasting or signaling.  This
  // allows us to optimize the code if we're just signaling.
} cond_t;
#endif

void cond_init(cond_t* cv);
void cond_signal (cond_t *cv);
void cond_wait(cond_t *cv, mutex_t *external_mutex);
void cond_broadcast (cond_t *cv);

#endif	
