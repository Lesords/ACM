#include<iostream>//ac
#include<algorithm>
#include<cmath>//ceil����ȡ����ceil��Ϊ��������
using namespace std;
const int MAXN = 2e5 + 5;
int num[MAXN];//��Ҫ�����Ĵ���
int main() {
	int n,a,b,k,tmp,ans = 0;
	cin>>n>>a>>b>>k;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		tmp %= a+b;//ȥ��������ɱ��Ѫ��
		//�պñ�b��ɱʱ����Ҫ��ԭ��b��ɱ��Ѫ������ʱ�����֣�
		if(tmp==0) num[i] = ceil(b*1.0/a*1.0);//ֻʣ��b��Ѫ��
		else num[i] = ceil(tmp*1.0/a*1.0)-1;//ȥ������һ��
	}
	sort(num+1,num+1+n);
	for(int i = 1;i <= n;i++) {
		if(k>=num[i]) {
			ans++;//���++
			k -= num[i];//���¿������Ĵ���
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
