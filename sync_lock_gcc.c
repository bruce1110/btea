#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
/**
 * @file sync_lock_gcc.c
 * @brief gcc 提供的锁
 * @author Bruce
 * @version 
 * @date 2017-09-06
 */

int val = 0;
int mu = 0;


#define ngx_atomic_cmp_set(lock, old, set) \
    __sync_bool_compare_and_swap(lock, old, set)

#define ngx_atomic_fetch_add(value, add)  \
    __sync_fetch_and_add(value, add)

#define ngx_trylock(lock)  (*(lock) == 0 && ngx_atomic_cmp_set(lock, 0, 1))
#define ngx_unlock(lock)    *(lock) = 0

void* fun1(void * arg)
{
    while (1) {
        if (!ngx_trylock(&mu)) {
            return NULL;
        }
        val += 1;
        ngx_unlock(&mu);

        printf("fun1: %d\n", val);
        sleep(1);
    }
}

void* fun2(void * arg)
{
    while (1) {
        if (!ngx_trylock(&mu)) {
            return NULL;
        }
        val += 1;
        ngx_unlock(&mu);

        printf("fun2: %d\n", val);
        sleep(1);
    }
}

int main()
{
    pthread_t p1;
    pthread_t p2;

    pthread_create(&p1, NULL, fun1, NULL);
    pthread_create(&p2, NULL, fun2, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}
