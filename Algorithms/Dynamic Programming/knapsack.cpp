#include <bits/stdc++.h>
using namespace std;

int n,s;
int memo[2020][2020];
int value[2020];
int weight[2020];

int pd(int item, int capacidadeAtual)
{
	if (capacidadeAtual < 0)
		return -INT_MAX;
	if (item == n)
		return 0;	

	int &pdn = memo[item][capacidadeAtual];
	if (pdn != -1)
		return pdn;

	pdn = max(pd(item+1, capacidadeAtual - weight[item]) + value[item],
	 		  pd(item+1, capacidadeAtual));

	return pdn;
}

vector<int> ans;

void recover(int ind, int cap)
{
	if (ind == n)
		return;

	int pega = value[ind] + pd(ind + 1, cap - weight[ind]);
	int passa = pd(ind + 1, cap );

	if (pega >= passa)
	{
		ans.push_back(ind);
		recover(ind + 1, cap - weight[ind]);
	}
	else 
	{
		recover(ind + 1, cap);
	}

}

int main(int argc, char const *argv[])
{
	cin >> s >> n;

	for (int i = 0; i < n; ++i)
		cin >> weight[i] >> value[i];
	
	memset(memo, -1, sizeof(memo));

	// cout << pd(0,s) << endl;

	recover(0,s);

	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
	
	return 0;
}