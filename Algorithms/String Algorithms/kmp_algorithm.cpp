#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    string txt,pat;
    cout<<"\nEnter the string in which search is to be done\n";
    cin>>txt;
    cout<<"\nEnter the pattern\n";
    cin>>pat;
    int M = pat.length(); 
    int N = txt.length();
    //Compute the LPS array(longest prefix which is also a suffix)
    int lps[M]; 
    int len = 0; 
  
    lps[0] = 0; 
    int i = 1,j; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
    //Using lps array search the string in O(n)
    i=j = 0; 
    int flag=0;
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            printf("Found pattern at index %d \n", i - j); 
            j = lps[j - 1]; 
            flag=1;
        } 
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    }
    if(!flag)
            cout<<"Pattern not found\n";
    return 0; 
} 