#include<iostream>//ac
#include<cstdio>
using namespace std;
int a[25],vis[25],n,r;
void dfs(int step) {//step��ʾ��ǰ��λ��
	if(step==r) {//r��ʱ
		for(int i = 1;i <= r;i++) {//��r������3���ֿ�
			printf("%3d",a[i]);
		}
		printf("\n");
	}
	//��������ֶ���Ҫ��ǰ��Ĵ�
	for(int i = a[step]+1;i <= n;i++) {
		if(vis[i]) continue;//�ѷ���
		a[step+1] = i;
		vis[i] = 1;//���
		dfs(step+1);
		vis[i] = 0;//ȡ�����
	}
}
int main() {
	cin>>n>>r;
	dfs(0);//��0��ʼ
	return 0;
}
