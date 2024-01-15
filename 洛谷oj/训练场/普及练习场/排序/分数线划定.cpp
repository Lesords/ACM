#include<iostream>//ac
#include<cmath>//包含floor函数（向下取整）
#include<algorithm>
using namespace std;
struct node{
	int num,score;
	friend bool operator < (node a, node b) {
		if(a.score == b.score)
			return a.num<b.num;
		else return a.score > b.score;
	}
}a[5005];
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].num>>a[i].score;
	}
	sort(a+1,a+n+1);//结构体排序
	int cnt = 0,minn = floor(m*1.5),ans = 0;
	for(int i = 1;i <= n;i++) {
		if(cnt>=minn) break;//人数够了即可
		else cnt++;
	}//cnt可确定面试分数线
	for(int i = 1;i <= n;i++) {//求ans人数
		if(a[i].score<a[cnt].score) break;
		else ans++;//计算达到面试分数线的人数
	}
	cout<<a[cnt].score<<' '<<ans<<endl;
	for(int i = 1;i <= n;i++) {
		if(a[i].score<a[cnt].score) break;//没达到直接退出
		cout<<a[i].num<<' '<<a[i].score<<endl;
	}
	return 0;
}
