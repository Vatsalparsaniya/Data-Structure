import java.util.Scanner;
public class Main
{
public static int remove_duplicate_elements(int arr[], int n)
{

if (n==0 || n==1)
return n;

int temp[] = new int[n];

int j = 0;
int i;
for (i=0; i<n-1; i++)
if (arr[i] != arr[i+1])
temp[j++] = arr[i];
temp[j++] = arr[n-1];

for (i=0; i<j; i++)
arr[i] = temp[i];

return j;
}

public static void main(String[] args)
{
int n;
Scanner s = new Scanner(System.in);
System.out.print(“Enter no. of elements you want in array:”);
n = s.nextInt();
int a[] = new int[n+1];
System.out.println(“Enter all the elements:”);

for(int i = 0; i < n; i++)
{
a[i] = s.nextInt();
}

n = remove_duplicate_elements(a, n);
System.out.print(“Array after removing : “);
for (int i=0; i<n; i++)
System.out.print(a[i] + ” “);

}
}
