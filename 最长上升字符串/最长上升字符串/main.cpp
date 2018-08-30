#include <iostream>
using namespace std;
int f[1001];
int x[1001];
int main(){
    int N;
	int m=0;
	while(cin>>N)
	{
		
		for(int i=1;i<=N;i++)
		{
			cin>>x[i];
		}
		fill(f,f+1001,1);
		for(int i=1;i<=N;i++)
		{
			//f[i]=1;
			for(int j=1;j<i;j++)
			{
				if(x[j]<x[i])
				{
					f[i]=max(f[i],f[j]+1);
					
				}
			
			}
			m=max(m,f[i]);
		}
		cout<<m<<endl;
	}
		


 /*   while(cin >> N){
        int  a[10002], dp[10002] = {0}, m=0;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                m = dp[i] > m ? dp[i] : m;
            }
    cout << m + 1 << endl;
    }*/
    return 0;
}