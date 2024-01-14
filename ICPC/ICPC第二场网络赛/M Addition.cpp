#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN], b[MAXN], c[MAXN], pre[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>pre[i];
	}
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++) {
		cin>>b[i];
	}
	
	int jin = 0, mark = 0;
	for(int i = 1;i <= n;i++) {
		int num = a[i]+b[i];
		
		if(jin) {//有进位的情况
			if(mark!=pre[i]) {//符号不同，扣除一个
				num--;
			}
			else num++;//否则累加一个
		}
		
		if(num<0) {//如果为负数，说明前后两个都需要进位
			c[i] = 1;
			jin = 1;
			continue;
		}
		
		int tmp = num;
		jin = 0;
		
		if(tmp==1) {
			c[i] = 1;
		}
		else if(tmp==2) {
			jin = 1;
			if(pre[i]<0) mark = -1;
			else mark = 1;
		}
		else if(tmp==3) {
			c[i] = 1;
			jin = 1;
			if(pre[i]<0) mark = -1;
			else mark = 1;
		}
	}
	for(int i = 1;i <= n;i++) {
		if(i!=1) cout<<" ";
		cout<<c[i];
	}
	return 0;
}


/*
7
1 1 1 -1 -1 -1 1
1 0 1 1 0 0 0 
1 0 1 0 0 0 0
*/