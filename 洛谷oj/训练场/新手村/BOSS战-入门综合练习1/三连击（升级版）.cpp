#include<iostream>//ac
#include<cstring>
using namespace std;
int vis[11];
int f(int i) {
	while(i) {//�����Գ��� 0 �� �ѳ��ֹ�������
		if(vis[i%10]||i%10==0) return 0;
		vis[i%10] = 1;
		i /= 10;
	}
	return 1;
}
int main() {
	int a,b,c,flag = 0;
	cin>>a>>b>>c;
	for(int i = 123;i <= 987;i++) {
		for(int j = 123;j <= 987;j++) {
			if(i*b!=j*a) continue;//ǰ����λ���ɱ���
			int k = i/a*c;//�������λ��
			memset(vis,0,sizeof(vis));//��ʼ��
			if(f(i)&&f(j)&&f(k)) {
				cout<<i<<' '<<j<<' '<<k<<endl;
				flag = 1;
			}
		}
	}
	if(!flag) cout<<"No!!!"<<endl;//û�п��ܵ����������
	return 0;
}
