#include<iostream>
#include<algorithm>
using namespace std;
int a[5];
int main() {
	int tmp;
	for(int i=1;i<=4;i++) {
		cin>>a[i];
	}
	sort(a+1,a+5);
	int cnt=unique(a+1,a+5)-&a[1];//unique����ֵΪ���ظ�������һ��
	cout<<4-cnt<<endl;
	return 0;
}
