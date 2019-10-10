#Selection sort in Python

a = []
size = int(input("Enter the size of list\n"))
for i in range(size):
    a.append(int(input()))

for i in range(len(a)):
    min = a[i]
    index = i


    for j in range(i+1,len(a)):
        if min>a[j]:
            min = a[j]
            index = j




    temp = a[i]
    a[i] = min
    a[index] = temp

print("The sorted list is :")
print(a)
