#include<iostream>//ac
#include<algorithm>
using namespace std;
int num[4];
struct subject{
	int data,time;
	friend bool operator < (subject a,subject b) {
		if(a.data==b.data) return a.time < b.time;
		return a.data < b.data;//��С��������
	}
}child[5005];
int main() {
	int t;
	cin>>t;
	for(int i = 1;i <= t;i++) {
		cin>>child[i].data;
		child[i].time = i;//λ����
		num[child[i].data]++;
	}
	sort(child+1,child+t+1);
	sort(num+1,num+4);
	cout<<num[1]<<endl;
	if(num[1]) {
		for(int j = 1;j <= num[1];j++) {
			int cnt = 1;
			for(int i = 1;i <= t;i++) {
				if(child[i].data==cnt) {//����γ�����
					cout<<child[i].time;
					child[i].data = 0;//���㣬�����ظ��ж�
					if(cnt!=3) cout<<' ';
					cnt++;//��һ��
				}
				if(cnt==4) break;
			}
			cout<<endl;
		}
	}
	return 0;
} 
