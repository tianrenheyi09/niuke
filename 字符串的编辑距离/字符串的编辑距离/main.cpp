#include<iostream>
#include<string>
#include<vector>
using namespace std;

int min_dis(string word1,string word2)
{
	int n=word1.size();
	int m=word2.size();
	vector<vector<int>>f(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++)
		f[i][0]=i;
	for(int j=0;j<=m;j++)
		f[0][j]=j;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(word1[i-1]==word2[j-1])
				f[i][j]=f[i-1][j-1];
			else
			{
				int mn=min(f[i-1][j],f[i][j-1]);
				f[i][j]=1+min(f[i-1][j-1],mn);
			}
		}
	}

	return f[n][m];
}
int main()
{
	string s1="if";
	string s2="iff";

	cout<<min_dis(s1,s2)<<endl;

	return 0;
}

