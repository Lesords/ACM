#include<iostream>//ac
#include<map>
#include<string>
#include<utility>//存放pair容器
using namespace std;
int main() {
	int t,n;
	string s;
	cin>>t;
	while(t--) {
		cin>>n>>s;
		int flag = 1,L = -1,R = n;//初始化为左右两个极端
		map<pair<int,int>, int> vis;
		pair<int,int> p(0,0);//初始坐标需标记
		vis[p] = 0;//下标可为 {0,0}，即 vis[{0,0}] = 0;
		//vis保存的是当前状态的下一位
		for(int i = 0;i < n;i++) {
			if(s[i]=='L') p.first--;
			if(s[i]=='R') p.first++;
			if(s[i]=='U') p.second++;
			if(s[i]=='D') p.second--;
			if(vis.count(p)) {//若此坐标已存在过
				if(i-vis[p]+1<R-L+1) {//区间更小
					L = vis[p];//左区间不能包括原状态！！！
					R = i;//右区间为当前状态
				}
				flag = 0;
			}
			vis[p] = i+1;//下一位（才是去除的子串开头）
		}
		if(flag) cout<<"-1"<<endl;
		else cout<<L+1<<' '<<R+1<<endl;
	}
	return 0;
}
