#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺ȡ��󻯵�k��ĺͣ���ô���Խ��������鶼��������
//Ȼ�����������е�ǰk���������
//���������������Ӱ�죬��Ӧ��ӣ�������
//������󻯵�k��Ļ������ǽ�a����ǰk������b����ǰk������
//Ȼ���Ӧ��ӣ���Сֵ��Ϊ��k��

const int MAXN = 1e5 + 5;
int a[MAXN],b[MAXN];
bool cmp(int a,int b) {//����
	return a>b;
}
int main() {
	int n,k,ans;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1,cmp);//��������
	sort(b+1,b+n+1,cmp);
	ans = a[1]+b[1];//��ʼ��Ϊ�������ֵ�ĺ�
	//O(N)�����������������
	for(int i = 1;i <= k;i++) {//aΪ����bΪ����
		ans = min(ans,a[i]+b[k-i+1]);//��Ӧȡ��Сֵ
	}//����ans��Ϊ��k��ֵ
	printf("%d",ans);
	return 0;
}
