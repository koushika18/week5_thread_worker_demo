# Week 5: Thread Worker Demo

## Aim
To write a C program demonstrating multiple threads using `pthread_create()` and `pthread_join()`.

## Program
The file `thread_worker_demo.c` creates three worker threads. Each worker prints a starting message, performs simulated work, and prints a finishing message.

## Concepts Used
- `pthread_create()` creates a new thread.
- `pthread_join()` waits for a thread to finish.
- `sleep()` simulates work by waiting for a specified number of seconds.
- `pthread_t` stores thread identifiers.
- `-pthread` enables POSIX thread support during compilation.

## Compile Command
```bash
gcc -Wall -Wextra -pthread thread_worker_demo.c -o thread_worker_demo
```

## Run Command
```bash
./thread_worker_demo
```

## Expected Output
```text
Main thread: Creating workers.
Worker 1: Started working.
Worker 2: Started working.
Worker 3: Started working.
Worker 1: Finished working.
Worker 2: Finished working.
Worker 3: Finished working.
Main thread: All workers have finished.
```

**Note:** The order of worker messages may vary because the threads execute concurrently.

## Conclusion
The program demonstrates how multiple worker threads can be created and how the main thread waits for all workers to finish using `pthread_join()`.
