#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[10];
int main() {
	for(int i = 1;i <= 8;i++) a[i] = i;//��ʼ��
	do {
		for(int i = 1;i <= 8;i++) {
			if(i!=1) cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
	}while(next_permutation(a+1,a+9));//ȫ���к���
	return 0;
}
