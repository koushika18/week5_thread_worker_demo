
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function executed by each worker thread
void *worker(void *arg)
{
    int worker_id = *(int *)arg;

    printf("Worker %d: Started working.\n", worker_id);

    // Simulate some work
    sleep(worker_id);

    printf("Worker %d: Finished working.\n", worker_id);

    return NULL;
}

int main(void)
{
    pthread_t threads[3];
    int worker_ids[3] = {1, 2, 3};

    printf("Main thread: Creating workers.\n");

    // Create three worker threads
    for (int i = 0; i < 3; i++)
    {
        int result = pthread_create(
            &threads[i], NULL, worker, &worker_ids[i]
        );

        if (result != 0)
        {
            fprintf(stderr, "Error creating worker %d.\n",
                    worker_ids[i]);
            return EXIT_FAILURE;
        }
    }

    // Wait for all worker threads to finish
    for (int i = 0; i < 3; i++)
    {
        int result = pthread_join(threads[i], NULL);

        if (result != 0)
        {
            fprintf(stderr, "Error joining worker %d.\n",
                    worker_ids[i]);
            return EXIT_FAILURE;
        }
    }

    printf("Main thread: All workers have finished.\n");

    return EXIT_SUCCESS;
}
