#include <stdio.h>
#include<time.h>
#include <stdlib.h>

int times = 10;
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
    for (int j = 0; j < times; ++j) {
        copy_by_step(src, dst, arrLen, step);
    }
    int endtime = clock();

    double duration = (double) (endtime - begintime) / CLOCKS_PER_SEC / times;

    FILE *fp = NULL;

    fp = fopen("/Users/Rui/workspace/works/com.ruipages/learning_csapp/test3.txt", "a");
    fprintf(fp, "%d,%d,%f\n", arrLen,step, duration);
    fclose(fp);

}

int main() {
    FILE *fp = NULL;

    fp = fopen("/Users/Rui/workspace/works/com.ruipages/learning_csapp/test3.txt", "w+");
    fclose(fp);

    int len_base = 10;
    int max_len = 1000;

    for (int len = len_base; len < max_len; len = len + 10) {
        test(len * len, 1);
        test(len * len, len);
    }


    printf("finished");

    return 0;
}


