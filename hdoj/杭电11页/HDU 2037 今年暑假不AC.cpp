#include<iostream>//ac
#include<algorithm>
using namespace std;
struct program{
	int s,e;
	friend bool operator < (program a,program b) {
		return a.e<b.e;//按结束时间排序
	}
}a[105];
int main() {
	int t;
	while(cin>>t&&t) {
		for(int i=1;i<=t;i++) {
			cin>>a[i].s>>a[i].e;
		}
		sort(a+1,a+t+1);
		int last_end = 0,cnt = 0;
		for(int i=1;i<=t;i++) {
			if(a[i].s>=last_end) {//开始时间在上次结束时间后面
				cnt++;
				last_end = a[i].e;//更新结束时间
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
