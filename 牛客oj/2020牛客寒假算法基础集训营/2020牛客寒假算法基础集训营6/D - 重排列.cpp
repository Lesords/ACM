#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//��⣺����ֻҪ����a����һ��һС��b���鼴��
//����Խ�a��b���鶼��������
//Ȼ����˫ָ���жϣ�ÿ��λ�ÿ����м������ֿ�ѡ���۳˼���

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int a[MAXN], b[MAXN];
int main() {
	int n,ans = 1;//ans��ʼ��Ϊ1���˷���
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",a+i);
	for(int i = 1;i <= n;i++) scanf("%d",b+i);
	sort(a+1,a+n+1);//����
	sort(b+1,b+n+1);
	for(int i = 1,j = 0;i <= n;i++) {//������������b����Ϊ׼��
		while(j<n&&a[j+1]<=b[i]) j++;//a����һλ������b�ĵ�ǰλ
		//��ѡ���ָ���Ϊ ������j�� - ����������i-1��
		ans = (ans*max(0LL,j-i+1LL))%MOD;//ȡģ
	}
	cout<<ans<<endl;
	return 0;
}
