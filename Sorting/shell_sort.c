#include <stdio.h>
#include <stdlib.h>

void main(void){
    int i, inner, outer, temp, h;
    int a[5] = {4,3,2,1,0};
    size_t len = sizeof(a) / sizeof(int);

    for(i=0;i<len;i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    h = 1;

    while(h <= len/3)
        h=h*3+1;
    
    while(h>0)
    {
        for(outer=h; outer<len; outer++)
        {
            temp =a[outer];
            inner = outer;

            while(inner > h-1 && a[inner-h] >= temp)
            {
                a[inner] =a[inner-h];
                inner -= h;
            }
            a[inner] = temp;
        }
        h=(h-1)/3;
    }

    for(i=0;i<len;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
    exit(0);
}