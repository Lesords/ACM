#include<iostream>//ac
#include<cstring>
#include<string>
using namespace std;
char a[55][1005];
int book[30];
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		int sum = 0;//�ܾ����
		cin>>n>>m;
		string ans = "";//����DNA��
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 0;i < m;i++) {
			memset(book,0,sizeof(book));
			int tmp = 0;//��ǰλ�ó�����Ƶ�����ַ��Ĵ���
			char ch;
			for(int j = 1;j <= n;j++) {//����n����
				book[a[j][i]-'A']++;//��¼���ַ����ֵĴ���
				if(book[a[j][i]-'A']>tmp) {
					ch = a[j][i];
					tmp = book[a[j][i]-'A'];
				}
				else if(book[a[j][i]-'A'] == tmp) {
					if(a[j][i]<ch) ch = a[j][i];//�ֵ���
				}
			}
			ans += ch;//����ַ�ch��DNA��ĩβ
			sum += n - tmp;//�ۼӵ�ǰλ�õ�Hamming����
		}
		cout<<ans<<endl<<sum<<endl;
	}
	return 0;
}
