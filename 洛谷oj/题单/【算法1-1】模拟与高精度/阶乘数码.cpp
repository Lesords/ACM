#include<iostream>//ac
#include<cstring>
using namespace std;
const int MAXN = 3e3 + 5;
int a[MAXN];
void multi(int n) {//�����˷���nΪ����
	int rest = 0;//�����λ��Ҳ�ɿ�����������ans
	for(int i = 1;i < MAXN;i++) {
		a[i] = a[i]*n+rest;//��λ����ӵ�
		rest = a[i]/10;//����һ��Ļ����ظ��ˣ�����
		a[i] %= 10;
	}
}
int main() {
	int t,x,pos;
	cin>>t;
	while(t--) {
		int num = 0,s;
		memset(a,0,sizeof(a));//��Ҫ��a��ʼ��
		a[1] = 1;//��λΪ1
		cin>>s>>x;
		for(int i = 1;i <= s;i++) multi(i);//��׳�s��
		for(int i = MAXN - 1;i >= 1;i--) if(a[i]) {//�ҵ�pos
			pos = i;break;
		}//ͳ��x������
		for(int i = pos;i >= 1;i--) if(a[i]==x) num++;
		cout<<num<<endl;
	}
	return 0;
}
