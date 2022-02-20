#include<stdio.h>
#include<string.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>

int myadd(int a, int b) {
    return a+b;
}

int cmpfunc( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

int fib(int a) {
    if (a == 0 || a == 1)
        return a;
    else
        return fib(a-1) + fib(a-2);
}

int main(){
    int i,j,count;
    double sum = 0;
    double add = 1;
    long seconds = 0;
    long microseconds = 0;
    double elapsed = 0;
    struct timeval begin, end;

    gettimeofday(&begin, 0);
    for (i=0; i< 10000000; i++) {        
    }
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;    
    printf("10m loop: %.3f seconds.\n", elapsed);

    gettimeofday(&begin, 0);
    for (i=0; i< 1000000; i++) {        
       j = 1/pow(i+1,0.5);
    }
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;    
    printf("1m pow loop: %.3f seconds.\n", elapsed);

    char * buffer = 0;
    long length;
    gettimeofday(&begin, 0);
    FILE * f = fopen ("tale-of-two-cities64x.txt", "rb");
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer)
    {
        fread (buffer, 1, length, f);
    }
    gettimeofday(&end, 0);
    fclose (f);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;    
    printf("read 11m word file: %.3f seconds.\n", elapsed);

    buffer = 0;
    f = fopen ("tale-of-two-cities.txt", "rb");
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer)
    {
        fread (buffer, 1, length, f);
    }
    gettimeofday(&begin, 0);
    qsort(buffer, (size_t) strlen(buffer), (size_t) sizeof(char), cmpfunc);
    gettimeofday(&end, 0);
    fclose (f);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;    
    printf("sort 792k words: %.3f seconds.\n", elapsed);

    gettimeofday(&begin, 0);
    fib(40);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;    
    printf("fib 40: %.3f seconds.\n", elapsed);

    gettimeofday(&begin, 0);
    for (i=0; i< 10000000; i++) {       
        myadd(i,myadd(i,1)); 
    }
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;    
    printf("10m add-func loop: %.3f seconds.\n", elapsed);

    gettimeofday(&begin, 0);
    for (i=0; i< 10000000; i++) {       
        i+i+1; 
    }
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;    
    printf("10m add-inline loop: %.3f seconds.\n", elapsed);

    return 0;
}