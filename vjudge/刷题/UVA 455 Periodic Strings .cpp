#include<iostream>//ac
#include<cstdio>
#include<cstring>
using namespace std;
char a[100];
int len;
int isperiod(int k) {
	int flag = 0;
	for(int i = 0;i < len;i += k) {//���ڱ�����
		for(int j = i;j < i+k;j++) {
			if(j+k>=len) break;//���
			if(a[j]!=a[j+k]) flag = 1;//�������ڱȽ�
		}
	}
	return !flag;//0��ʾ����ƥ��ɹ�
}
int main() {
	int t,flag = 0;
	cin>>t;
	while(t--) {
		getchar();//����������
		int ans = 0;
		cin>>a;
		len = strlen(a);
		for(int i = 1;i <= len;i++) {
			if(isperiod(i)&&!(len%i)) {//��С���Ա�����������
				ans = i;
				break;
			}
		}
		if(flag++) cout<<endl;
		cout<<ans<<endl;//ĩβendl
	}
	return 0;
}
/*wa����
3

aba

abca

abcda*/ 
