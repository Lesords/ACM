#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * 返回最后要输出的答案
     * @param n int整型 表示牛牛的数字
     * @param m int整型 表示牛妹的数字
     * @return int整型
     */
	struct node{
		int val,step;
		friend bool operator < (node a,node b) {
			if(a.step!=b.step) return a.step > b.step;
			return a.val < b.val;
		}
	};
	const int MAXN = 0x3f3f3f3f;
	int vis[2020];//70分wa点是数据范围过小！！！
    int solve(int n, int m) {
        // write code here
        if(m<=n) return n-m;
        memset(vis,0x3f,sizeof(vis));
        vis[n] = 0;
		priority_queue<node> q;
		q.push(node{n,0});
		node tmp;
		while(!q.empty()) {
			tmp = q.top();
			if(tmp.val==m) return tmp.step;
			q.pop();
			//直接判断vis也可，重点是数组大小
			if(tmp.val+1<2020&&vis[tmp.val+1]>tmp.step+1) {
				vis[tmp.val+1] = tmp.step+1;
				q.push(node{tmp.val+1,tmp.step+1});
			}
			if(tmp.val-1>=0&&vis[tmp.val-1]>tmp.step+1) {
				vis[tmp.val-1] = tmp.step+1;
				q.push(node{tmp.val-1,tmp.step+1});
			}
			if(tmp.val*tmp.val<2020&&vis[tmp.val*tmp.val]>tmp.step+1) {
				vis[tmp.val*tmp.val] = tmp.step+1;
				q.push(node{tmp.val*tmp.val,tmp.step+1});
			}
		}
    }
}tmp;
int main() {
	int n,m;
	cin>>n>>m;
	cout<<tmp.solve(n,m)<<endl;
	return 0;
}
