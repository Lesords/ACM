#include<iostream>//ac
using namespace std;
int ans,vis[10],a[10],n;
int get_val(int left,int right) {//��Ӧ��Χ��ֵ
	int ans = 0;
	for(int i = left;i <= right;i++) ans = ans*10+a[i];
	return ans;
}
void dfs(int pos) {//����ȫ����
	if(pos==10) {//������9����
		for(int i = 1;i <= 7;i++)  {//��һ����������������
			for(int j = i+1;j <= 8;j++) {//�ڶ�����������һ����
				int A = get_val(1,i);
				int B = get_val(i+1,j);
				int C = get_val(j+1,9);//������������ֵ
				if(n*C==A*C+B) {// n = A + B/C �ı�ʽ����ֹ����ȡ����
					ans++;return;
				}
			}
		}
		return ;
	}
	for(int i = 1;i <= 9;i++) {//�����������
		if(vis[i]) continue;//������ʹ�õ�����
		vis[i] = 1;//���
		a[pos] = i;//��¼posλ�õ�ֵ
		dfs(pos+1);
		vis[i] = 0;//ȡ�����
	}
}
int main() {
	cin>>n;
	dfs(1);//��ʼλ�ô�1��ʼ
	cout<<ans<<endl;
	return 0;
}
