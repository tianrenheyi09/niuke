#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<int>G[1000];
bool visited[1000] = { 0 };

void dfs(int v)
{
	visited[v] = 1;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (visited[G[v][i]] == 0)
		{
			dfs(G[v][i]);
		}
	}
}

int main()
{
	int n, a, b;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int block = 0;
	///枚举顶点
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			block++;
		}
	}

	cout << "联通块" << endl;
	cout << block << endl;

	return 0;

}