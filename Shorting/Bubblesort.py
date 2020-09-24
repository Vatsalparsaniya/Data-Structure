list1=[10000,4000,0,900,10]
passes=len(list1)-1  // len() func to find size of list
while(passes!=0):
        for i in range(0,len(list1)-1):
              if(list1[i]>list1[i+1]):
                   temp=list1[i]
                   list1[i]=list1[i+1]
                   list1[i+1]=temp
        passes=passes-1
print(list1)
