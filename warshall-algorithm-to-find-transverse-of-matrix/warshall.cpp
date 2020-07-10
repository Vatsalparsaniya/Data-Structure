#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{int a,counter=0,m,n;
cout<<"enter the matrix order"<<endl;
cin>>a;
const int b=a;
int x[b][b],y[b][b],s[2][b]={0};
cout<<"enter the values"<<endl;
for (int i=0;i<b;i++)
{ for(int j=0;j<b;j++)
 {cin>>x[i][j];
  y[i][j]=x[i][j];
 }
}
for(int k=0;k<b;k++)
{for(int t=0;t<2;t++)
{for(int u=0;u<b;u++)
{s[t][u]=0;
}
}
for(int i=0;i<b;i++)
{if(y[i][k]==1)
{s[0][i]=1;}
}
for(int j=0;j<b;j++)
{if(y[k][j]==1)
{s[1][j]=1;}
}
for(int p=0;p<b;p++)
{if(s[0][p]==1)
{for(int r=0;r<b;r++)
if(s[1][r]==1)
{y[p][r]=1;}
}
}
}

for (int i=0;i<b;i++)
{ for(int j=0;j<b;j++)
 {if(x[i][j]!=y[i][j])
  {counter++;}
 }
}
if(counter==0)
{cout<<endl<<"the relation is transitive"<<endl<<"the transitive  relation is  -  "<<endl<<endl;
}
else
{cout<<endl<<"the relation is not transitive"<<endl<<"the transitive  relation is  -  "<<endl<<endl;
}
for (int i=0;i<b;i++)
{ for(int j=0;j<b;j++)
 {cout<<y[i][j];
 }
  cout<<endl;
}
}
