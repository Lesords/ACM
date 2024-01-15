#include<iostream>//ac
#include<algorithm>
using namespace std;
int num[4];
struct subject{
	int data,time;
	friend bool operator < (subject a,subject b) {
		if(a.data==b.data) return a.time < b.time;
		return a.data < b.data;//从小到大排序
	}
}child[5005];
int main() {
	int t;
	cin>>t;
	for(int i = 1;i <= t;i++) {
		cin>>child[i].data;
		child[i].time = i;//位置数
		num[child[i].data]++;
	}
	sort(child+1,child+t+1);
	sort(num+1,num+4);
	cout<<num[1]<<endl;
	if(num[1]) {
		for(int j = 1;j <= num[1];j++) {
			int cnt = 1;
			for(int i = 1;i <= t;i++) {
				if(child[i].data==cnt) {//满足课程条件
					cout<<child[i].time;
					child[i].data = 0;//清零，避免重复判断
					if(cnt!=3) cout<<' ';
					cnt++;//下一课
				}
				if(cnt==4) break;
			}
			cout<<endl;
		}
	}
	return 0;
} 
