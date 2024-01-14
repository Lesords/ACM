#include<iostream>//ac
#include<algorithm>
using namespace std;
struct cube{
	int x,y;//x为长，y为宽
	friend bool operator < (cube a,cube b) {
		if(a.x==b.x) return a.y>b.y;//从大到小排序
		return a.x>b.x;
	}
}a[10];
int main() {
	int tmp1,tmp2;
	while(cin>>tmp1) {
		if(tmp1==EOF) return 0;//判断输入是否结束
		cin>>tmp2;
		a[1].x=tmp1>tmp2?tmp1:tmp2;//大小处理
		a[1].y=tmp1<tmp2?tmp1:tmp2;
		for(int i = 2;i <= 6;i++) {
			cin>>tmp1>>tmp2;
			a[i].x=tmp1>tmp2?tmp1:tmp2;//大小处理
			a[i].y=tmp1<tmp2?tmp1:tmp2;
		}
		sort(a+1,a+7);
		int flag = 0;
		for(int i = 1;i <= 5;i += 2) {
			if(a[i].x!=a[i+1].x||a[i].y!=a[i+1].y) flag = 1;
			//判断两两是否相等
		}
		if(a[1].x!=a[3].x||a[1].y!=a[5].x||a[3].y!=a[5].y) flag = 1;
		//底面的长和宽是否为其他两面的长以及其他两面的宽是否相等
		if(flag) cout<<"IMPOSSIBLE"<<endl;
		else cout<<"POSSIBLE"<<endl;
	}
	return 0;
}
