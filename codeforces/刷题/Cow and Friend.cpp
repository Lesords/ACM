#include<iostream>//ac
#include<cmath>
using namespace std;
int main() {
	int t,n,x;
	cin>>t;
	while(t--) {
		int ans = 0,tmp,maxx = 0;
		cin>>n>>x;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			maxx = max(maxx,tmp);//��¼���ֵ
			if(tmp==x) ans = 1;//�պ���һ�������յ��
		}
		if(ans) {//һ����
			cout<<ans<<endl;
			continue;
		}//����һ����������������Ҫ���������ܴ���С��
		//�����һ����������ж���Ҫ����maxx��������ȡ����
		//Ӧ�ÿ����ߵľ���Ϊ maxx - 2*maxx ������ֵ ������
		//����پ��붼Ҫ����һ��
		ans = max(2.0,ceil(x*1.0/maxx*1.0));
		cout<<ans<<endl;
	}
	return 0;
}
