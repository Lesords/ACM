#include<iostream>//ac
using namespace std;

//��⣺�����ż���飬˵�����Բ���Ϊȫɫ
//���ֻ��һ����ɫ�����������
//�����Ϊ���������޷�����Ϊȫɫ
//�ɲ������������һ��ż��ɫΪ��ɫ����ÿ��������ɫ�޸��������鲢�����

const int MAXN = 205;
int a[MAXN],ans[MAXN * 3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,white = 0,black = 0,cnt = 0;
	cin>>n;
	char tmp;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;//1�����ɫ�飬0�����ɫ��
		tmp == 'B'?(black++,a[i] = 1):(white++,a[i] = 0);//��������ţ�����
	}
	if(black%2&&white%2) cout<<"-1"<<endl;//��������ɫ�鶼Ϊ���������޷��ɹ�
	else {
		if(!black||!white) cout<<"0"<<endl;//��ֻ��һ����ɫ�����������
		else {
			int flag = (black%2==0)?1:0;//flagΪż������ɫ��
			for(int i = 1;i < n;i++) {
				if(a[i] == flag) {
					ans[++cnt] = i;//�����¼����߿���±꣩
					a[i] ^= 1;//��1�����԰�0��Ϊ1,1��Ϊ0
					a[i+1] ^= 1;
				}
			}
			cout<<cnt<<endl;
			for(int i = 1;i <= cnt;i++) {
				if(i!=1) cout<<' ';
				cout<<ans[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
