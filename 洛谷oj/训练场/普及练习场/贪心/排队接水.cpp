#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int num,water;
	friend bool operator < (node a, node b) {
		return a.water < b.water;//��С��������
	}
}a[1005];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i].water,a[i].num = i;
	sort(a+1,a+n+1);//��һ�˵��Ŷ�ʱ��Ϊ0
	double ans = 0,tmp = 0;//ansΪ��ʱ�䣬tmpΪÿ���˵��Ŷ�ʱ��
	for(int i = 1;i <= n;i++) {//ÿ���˵�ʱ���൱��ǰ׺��
		if(i!=1) cout<<' ',tmp += a[i-1].water,ans += tmp;
		cout<<a[i].num;
	}
	printf("\n%.2f",ans/n);
	return 0;
}
