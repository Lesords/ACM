#include<iostream>//ac
using namespace std;
int ans = 0,n,a[11];
void dfs(int pos, int sum,int flag) {
	if(sum>n) return;
	if(pos==10) {
		if(sum==n) {
			if(!flag) ans++;//ֻ������
			else{//������Ͻ��
				for(int i = 1;i <= 10;i++) cout<<a[i]<<' ';
				cout<<endl;
			}
		}
		return;
	}
	for(int i = 1;i <= 3;i++) {//ֻ��3�����
		a[pos+1] = i;//����������һλ��
		dfs(pos+1,sum+i,flag);
	}
}
int main() {
	cin>>n;
	dfs(0,0,0);//��һ�ε���ֻ����ans����λ��0��ʼ����
	cout<<ans<<endl;
	dfs(0,0,1);//�ڶ��ε�������������
	return 0;
}
