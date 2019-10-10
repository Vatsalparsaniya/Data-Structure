import time
import os

l=list(map(int,input().split()))
n=len(l)

def swap(l,hole):
    temp=l[hole]
    l[hole]=l[hole-1]
    l[hole-1]=temp
def Insertion_sort(l):
    for i in range(0,n):
        hole=i
        while(hole>0 and l[hole]<l[hole-1]):
            swap(l,hole)
            hole-=1
Insertion_sort(l)
for i in l:
    print(i,end=" ")
