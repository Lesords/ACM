#include<iostream>//ac
//�ƶ��Ĵ���������ÿ�ζ���2�㣬������ÿ�ζ���1��(n��)
//��Ҫע��ľ��ǲ���Ϊ�����Ļ���������һ�ε���һ��
using namespace std;
int n,m;
int solve() {
	if(n%2==0) {//����Ϊż��
		int num = n/2;
		for(int i = num;i <= n;i++) {
			if(i%m==0) return i;
		}
	}
	else {//����Ϊ����
		int num = (n-1)/2 + 1;//n-1��Ϊ2���ģ�����һ�ε���һ��
		for(int i = num;i <= n;i++) {
			if(i%m==0) return i;
		}
	}
	return -1;
}
int main() {
	cin>>n>>m;
	if(n<m) {//����С���ƶ������
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<solve()<<endl;
	return 0;
}
