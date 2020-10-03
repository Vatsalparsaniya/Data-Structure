#include <bits/stdc++.h>
using namespace std;
 
void fill(vector<string> &ans, string &curr, int index, int n, int open, int close){
    if(index>= n && open==close){
        ans.push_back(curr);
        return;
    }
    else if(index>=n)
        return;
    if(close> open)
        return;
    if(open-close > n/2)
        return;
    curr.push_back('(');
    fill(ans, curr, index+1, n, open+1, close);
    curr.pop_back();
 
    curr.push_back(')');
    fill(ans, curr, index+1, n, open, close+1);
    curr.pop_back();
}
 
vector<string> generateParenthesis(int n) {
    int open= 0, closed= 0;
    string curr;
    vector<string> ans;
 
    fill(ans, curr, 0, 2*n, open, closed);
 
    return ans;
}
 
 
int main() {
	vector<string> eightLenthParenthesis = generateParenthesis(4);
	for (int i = 0; i < eightLenthParenthesis.size(); i++) {
		cout << eightLenthParenthesis[i] << endl;
	}
	return 0;
}