#include<iostream>//ac
using namespace std;
int head;

//��⣺ÿ��λ�������9��Ư����������һ������ɣ� 
//���� n ��Ư���� =��λ�� - 1�� * 9 + ��λ��Ư����
//��Ҫ�жϸ�λ�Ƿ��� ��λ���� ��ɵ�Ư���� 

int f(int n) {
	int pos = 0;
	while(n) {
		if(n<10) head = n;//����λ����
		n /= 10;
		pos++;
	}
	return pos;
}
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int pos = f(n);//��λ��
		int cnt = head;
		for(int i = 1;i < pos;i++) {
			cnt = cnt*10 + head;
		}//���õ� cnt Ϊ��λ������ɵ�Ư����
		if(n>=cnt) cout<<(pos - 1) * 9 + head<<endl;
		else cout<<(pos - 1) * 9 + head - 1<<endl;
	}
	return 0;
} 
