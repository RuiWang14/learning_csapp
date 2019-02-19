#include <stdio.h>
#include<time.h>

const int ARR_SIZE = 990;
int src[ARR_SIZE][ARR_SIZE], dst[ARR_SIZE][ARR_SIZE];

void copyij(int src[ARR_SIZE][ARR_SIZE],
        int dst[ARR_SIZE][ARR_SIZE]) {
    int i, j;
    for (i = 0; i < ARR_SIZE; i++)
        for (j = 0; j < ARR_SIZE; j++)
            dst[i][j] = src[i][j];
}

void copyji(int src[ARR_SIZE][ARR_SIZE],
        int dst[ARR_SIZE][ARR_SIZE]) {
    int i, j;
    for (j = 0; j < ARR_SIZE; j++)
        for (i = 0; i < ARR_SIZE; i++)
            dst[i][j] = src[i][j];
}



int main() {

    int i, j;

    printf("size of int: %ld \n", sizeof(int));
    printf("size of src: %ld \n", sizeof(src));

    for (i = 0; i < ARR_SIZE; i++) {
        for (j = 0; j < ARR_SIZE; j++) {
            src[i][j] = 1;
            dst[i][j] = 0;
        }
    }
    int begintime_ij = clock();
    copyij(src, dst);
    int endtime_ij = clock();

    for (i = 0; i < ARR_SIZE; i++) {
        for (j = 0; j < ARR_SIZE; j++) {
            src[i][j] = 1;
            dst[i][j] = 0;
        }
    }
    int begintime_ji = clock();
    copyji(src, dst);
    int endtime_ji = clock();


    double duration_ij = (double) (endtime_ij - begintime_ij) / CLOCKS_PER_SEC;
    double duration_ji = (double) (endtime_ji - begintime_ji) / CLOCKS_PER_SEC;


    FILE *fp = NULL;

    fp = fopen("/Users/Rui/workspace/works/com.ruipages/learning_csapp/test.txt", "a");
    fprintf(fp, "ij,%d,%f\n", ARR_SIZE, duration_ij);
    fprintf(fp, "ji,%d,%f\n", ARR_SIZE, duration_ji);
    fclose(fp);

    printf("finished");

    return 0;
}
