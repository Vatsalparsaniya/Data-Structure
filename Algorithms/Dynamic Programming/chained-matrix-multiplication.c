#include <stdio.h>

int infinity=32500;

struct x{
  int used,weight;  
};

int main()
{
    int graph[9][9]={
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };    

    struct x arr[9];//this array traces value is filled or not
    int w[9];//Stores the temporary weight
    
    //lets start from index 0 as default
    w[0]=0;
    arr[0].weight=0;
    // arr[0].used=1;
    for(int i=1;i<9;i++){
        w[i]=infinity;
        arr[i].weight=infinity;
        arr[i].used=0;
    }
    int count=0;
    while(count<9){
        int temp=infinity,//temporary min weight
            ti=-1;//temporary min index
            
        //find the minimum unused index
        for(int i=0;i<9;i++){
            if(w[i]<temp && arr[i].used!=1){
                ti=i;
                temp=w[i];
            }
        }
        
        arr[ti].used=1;
        arr[ti].weight=temp;
        
        for(int i=0;i<9;i++){
            int replacer;
            
            if(graph[ti][i]==0)
                replacer=infinity;
            else
                replacer=graph[ti][i];
                
            if((w[i]>replacer+arr[ti].weight) && arr[i].used!=1)
                w[i]=replacer+arr[ti].weight;
        }
        count++;
    }
    for(int i=0;i<9;i++)
        printf("%d\t",arr[i].weight);
    return 0;
}
