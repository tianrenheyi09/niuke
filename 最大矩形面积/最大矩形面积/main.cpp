#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] <= height[i]) s.push(i);
            else {
                int tmp = s.top();
                s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }

int two_largestRectangleArea(vector<int> &height) {

        int res = 0;
		for(int i=0;i<height.size();i++)
		{
			if(i+1<height.size()&&height[i]<=height[i+1])
				continue;
		int minh=height[i];
		for(int j=i;j>=0;j--)
		{
			minh=min(minh,height[j]);
			res=max(res,minh*(i-j+1));
		}
		}

		return res;

        //stack<int> s;
        //height.push_back(0);
        //for (int i = 0; i < height.size(); ++i) {
        //    if (s.empty() || height[s.top()] <= height[i]) s.push(i);
        //    else {
        //        int tmp = s.top();
        //        s.pop();
        //        res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
        //        --i;
        //    }
        //}
        //return res;
    }

int maximalRectangle(int matrix[][5],int m,int n) {
        int res = 0;
        vector<int> height(n,0);
        for (int i = 0; i < m; ++i) {
           // height.resize(matrix[i].size());
            for (int j = 0; j < n; ++j) {
                height[j] = matrix[i][j] == 0 ? 0 : (1 + height[j]);
            }
            res = max(res, two_largestRectangleArea(height));
        }
        return res;
    }

int matrix[5][5]={{1,1,0,0,1},
	{0,1,0,0,1},
	{0,0,1,1,1},
	{0,0,1,1,1},
	{0,0,0,0,1}};
int main()
{
	cout<<maximalRectangle(matrix,5,5)<<endl;

	return 0;
}