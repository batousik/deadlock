/******************************************************************************
* FILE: hello.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Blaise Barney
* LAST REVISED: 08/09/11
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset */
#include <unistd.h> /* close */

void *PrintHello(void *threadid)
{
   void *m = malloc(1024*1024*20);
   memset (m,0,1024*1024*20);
   long *tid_p;
   tid_p = malloc(1024 * 1024 * 1024 * sizeof(long));
   *tid_p = (long)threadid;  
   while(1){
   	 *tid_p++;
   }
}

int main(int argc, char *argv[])
{
   pthread_t thread;
   long t = 0;
   int rc;
   int aflag = 1;
   while(1){
     if(aflag){
       rc = pthread_create(&thread, NULL, PrintHello, (void *)t);
       aflag = 1;
     }  
   }
}
