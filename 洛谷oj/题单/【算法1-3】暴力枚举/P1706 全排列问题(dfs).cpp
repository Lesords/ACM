#include<cstdio>//ac
using namespace std;
int n,a[10],vis[10];
void dfs(int step) {
	if(step==n) {//�պ�n����
		for(int i = 1;i <= n;i++) {
			printf("%5d",a[i]);
		}
		printf("\n");
	}
	for(int i = 1;i <= n;i++) {
		if(vis[i]) continue;
		a[step+1] = i;//��¼step+1��ֵ
		vis[i] = 1;
		dfs(step+1);
		vis[i] = 0;
	}
}
int main() {
	scanf("%d",&n);
	dfs(0);//�տ�ʼ0��
	return 0;
}
