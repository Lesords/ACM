#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
int book[205],s[205],e[205];

//��⣺����ÿ�����Ӷ���Ҫ�ƶ�����ôֻ��Ҫ�ж����з����ƶ���
//�����·���ж��ٴμ��ɣ���Ϊ����ĵط����붼Ҫ�ƶ��ض�����

 
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int ans = 0;
		memset(book,0,sizeof(book));//��ʼ���������
		for(int i = 1;i <= n;i++) {
			cin>>s[i]>>e[i];
			if(s[i]%2) s[i]++;//ת���·�����ţ�ż����
			if(e[i]%2) e[i]++;
			s[i] /= 2, e[i] /= 2;//��2��Ϊ�к�
			if(s[i]>e[i]) swap(s[i],e[i]);//��ȷ����С
			for(int j = s[i];j <= e[i];j++) book[j]++;//���·��
		}
		for(int i = 1;i <= 200;i++) {
			ans = max(ans,book[i]);//Ѱ�ҽ���·������һ��
		}
		cout<<ans*10<<endl;
	}
	return 0;
}
