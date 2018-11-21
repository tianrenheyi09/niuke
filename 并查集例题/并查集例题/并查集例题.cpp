#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int pre[1000];
bool t[1000];
int find(int x)
{
	int r = x;
	while (pre[r] != r)
		r = pre[r];;

	int i = x; int j;
	while (i != r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}

	return r;
}

void mix(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
	{
		pre[fy] = fx;
	}
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = i;
	}
}
int main()
{
	int n, m, p1, p2, i, total, f1, f2;
	cin >> n >> m;

	////c��ʼ��
	init(n);
	///ѹ�����ڵ�
	for (int i = 1; i <= m; i++)
	{
		cin >> p1 >> p2;
		mix(p1, p2);
	}
	////�����ڵ㸳ֵΪ1
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= n; i++)
	{
		t[find(i)] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (t[i])
			ans++;
	}
	cout << "����Ҫ������·" << endl;
	cout << ans - 1 << endl;
	cout << "������ͨ��" << endl;
	cout << ans << endl;


	return 0;
}