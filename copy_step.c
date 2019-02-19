#include <stdio.h>
#include<time.h>
#include <stdlib.h>

void print_rs(int arr[], int len){
    for (int i = 0; i < len; ++i) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}

/**
 * 间隔 step 距离，对两数组进行复制
 * @param src 源数组
 * @param dst 目标数组
 * @param len 数组长度
 * @param step 访问间隔
 */
void copy_by_step(int *src, int *dst,
        int len, int step){
    for(int i = 0; i < step; i++){
        for(int j = i; j < len; j= j + step){
            dst[j] = src[j];
        }
    }
}


void test(int arrLen, int step){
    int *src, *dst;

    src = (int*)malloc( arrLen*sizeof(int) );
    dst = (int*)malloc( arrLen*sizeof(int) );
    if(!src && !dst){
        printf("创建数组失败！\n");
        exit(1);
    }


    for(int i=0; i<arrLen; i++){
        src[i] = 1;
        dst[i] = 0;
    }

    int begintime = clock();
    for (int j = 0; j < 10; ++j) {
        copy_by_step(src, dst, arrLen, step);
    }
    int endtime = clock();

    double duration = (double) (endtime - begintime) / CLOCKS_PER_SEC;

    FILE *fp = NULL;

    fp = fopen("/Users/Rui/workspace/works/com.ruipages/learning_csapp/test2.txt", "a");
    fprintf(fp, "%d,%d,%f\n", arrLen,step, duration);
    fclose(fp);

}

int main() {
    FILE *fp = NULL;

    fp = fopen("/Users/Rui/workspace/works/com.ruipages/learning_csapp/test2.txt", "w+");
    fclose(fp);

    int len_base = 2000;
    int step_base = 1;
    int times = 2;

    int len_time = 10;
    int step_time = 10;

    fp = fopen("/Users/Rui/workspace/works/com.ruipages/learning_csapp/info.txt", "w+");
    fprintf(fp, "%d,%d,%d,%d,%d\n", len_base,step_base, times,len_time,step_time);
    fclose(fp);

    int len = len_base;
    for (int lt = 0; lt < len_time; ++ lt) {
        int step = step_base;
        for (int st = 0; st < step_time && step < len; ++ st) {
            test(len,step);
            step = step * times;
        }
        len = len * times;
    }

    printf("finished");

}


