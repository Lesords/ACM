#include<iostream>//ac
using namespace std;
int ans[105],n,m,book[105];
int main() {
	ans[0] = 1;//���ó�ʼ���
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {//�ܹ�n��
		for(int j = ans[i-1],cnt = 0;;j = j%n + 1) {//%n����n
			if(book[j]) continue;//������ѡ����
			cnt++;//����ing
			if(cnt==m) {//����mʱ
				ans[i] = j,book[j] = 1;//��¼�𰸲������ѡ����
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		if(i!=1) cout<<' ';
		cout<<ans[i];
	}
	return 0;
} 
