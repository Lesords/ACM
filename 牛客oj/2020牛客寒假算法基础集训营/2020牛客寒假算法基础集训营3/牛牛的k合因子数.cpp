#include<iostream>//ac
using namespace std;

//��⣺��ʽɸ����ɸ������ʱ���ӵ�ǰ���������������������++
//��Ϊ��������ӵ�ǰ��*2���������ɸѡ����
//����ٱ��ÿ�����ĺ���������

const int MAXN = 1e5 + 5;
int prim[MAXN],cnt[MAXN],ans[MAXN];
int main() {
	int n,m,tmp;
	cin>>n>>m;
	for(int i = 2;i <= n;i++) {
		if(prim[i]) {//1��ʾ������0��ʾ����
			for(int j = i;j <= n;j+=i) cnt[j]++;//cnt����j�ĺ���������
		}//��i��ʼ�ĺ��������Ϊi��������������++
		else for(int j = i+i;j <= n;j += i) prim[j] = 1;
		ans[cnt[i]]++;//���i�ĺ���������
	}//Ͱ����˼��
	for(int i = 1;i <= m;i++) {
		cin>>tmp;
		cout<<ans[tmp]<<endl;
	}
	return 0;
}
