//
// This is the solution to CPSC 213 Assignment 9.
// Do not distribute this code or any portion of it to anyone in any way.
// Do not remove this comment.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/errno.h>
#include <assert.h>
#include "queue.h"
#include "disk.h"
#include "uthread.h"

queue_t      pending_read_queue;
unsigned int sum = 0;




void interrupt_service_routine () {
  // TODO

  void* t = uthread_self();
  queue_dequeue(pending_read_queue, &t, NULL, NULL);
  uthread_t* th = t;
  uthread_unblock(*th);
}

void* read_block (void* blocknov) {
  // TODO enqueue result, schedule read, and the update (correctly)
  void* t = uthread_self();
  int* n = (int*)blocknov;
  int num = *n;
  int r;

  disk_schedule_read(&r, num);
  queue_enqueue(pending_read_queue, &t, NULL, NULL);
  uthread_block();
  sum += r;
  return NULL;
}





int main (int argc, char** argv) {

  // Command Line Arguments
  static char* usage = "usage: tRead num_blocks";
  int num_blocks;
  char *endptr;
  if (argc == 2)
    num_blocks = strtol (argv [1], &endptr, 10);
  if (argc != 2 || *endptr != 0) {
    printf ("argument error - %s \n", usage);
    return EXIT_FAILURE;
  }

  // Initialize
  uthread_init (1);
  disk_start (interrupt_service_routine);
  pending_read_queue = queue_create();


  // Sum Blocks
  // TODO
  uthread_t thread[num_blocks];
  int b[num_blocks];
  for (int blockNo = 0; blockNo < num_blocks; blockNo++) {
     b[blockNo] = blockNo;
     thread[blockNo] = uthread_create(&read_block, &b[blockNo]);
  }
  for (int blockNo = 0; blockNo < num_blocks; blockNo++) {
      void* re;
      uthread_join(thread[blockNo], &re);
\
  }

  printf("%d\n", sum);
  exit (EXIT_SUCCESS);
}
