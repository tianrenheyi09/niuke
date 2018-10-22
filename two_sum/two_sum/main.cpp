#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<vector<int>> find_res(vector<int>arr,int n)
{
	int left=0;
	int right=arr.size()-1;
	vector<vector<int>>res;
    while(left<right)
	{
		vector<int>path;
		if(arr[left]+arr[right]==n)
		{
			path.push_back(left);
			path.push_back(right);
			res.push_back(path);
			while(left<right&&arr[left]==arr[path[0]])
			{
				left++;
			}
			while(left<right&&arr[right]==arr[path[1]])
			{
				right--;
			}
		}
		else if(arr[left]+arr[right]>n)
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	return res;
}

vector<vector<int>> find_two_res(vector<int>arr,int n)
{
	vector<vector<int>>res;
	map<int,int>mp;
	for(int i=0;i<arr.size();i++)
	{
		mp[arr[i]]=i;
	}
	for(int i=0;i<arr.size()/2;i++)
	{
		if(i>0&&arr[i]==arr[i-1])
		{
			continue;
		}
		int gap=n-arr[i];
		if(mp.find(gap)!=mp.end()&&mp[gap]!=i)
		{
			vector<int>path;
			path.push_back(i);
			path.push_back(mp[gap]);
			res.push_back(path);
		
			
		}
	}

	return res;
}

void printof(vector<vector<int>>a)
{
	for(auto it=a.begin();it!=a.end();it++)
	{
		for(auto it1=(*it).begin();it1!=(*it).end();it1++)
		{
			cout<<*it1<<" ";
		}
		cout<<endl;
	}
}

int main()
{

	//int a[]={1,3,4,6,8,9};
	int a[]={1,1,3,4,6,6,8,9};
	vector<int>x(a,a+8);
	//vector<vector<int>>res=find_res(x,10);

	vector<vector<int>>res=find_two_res(x,10);


	printof(res);

	return 0;
}