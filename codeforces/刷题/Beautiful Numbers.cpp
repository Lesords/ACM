#include<iostream>//ac
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 2e5 + 5;
int pos[MAXN],len[MAXN];
int main() {
	int t,n,tmp;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			pos[tmp] = i;//����λ��
		}
		string ans = "1";//��һ������Ϊ������
		len[1] = 0;
		int minn,maxx;
		minn = maxx = pos[1];//��ʼλ��Ϊ1
		for(int i = 2;i <= n;i++) {//����2~n���е��������  
			minn = min(pos[i],minn);//������С��λ��
			maxx = max(pos[i],maxx);//��������λ��
			len[i] = maxx - minn;//������Сλ�õĿ�ȼ�Ϊ����
			if(len[i]<i) ans += '1';//������С����������
			else ans += '0';
		}
		cout<<ans<<endl;
	}
	return 0;
}
