#include<iostream>//ac
#include<string>
#include<cstring>
#define maxn 10005
using namespace std;
int book[10];
int main() {
	int T,n;
	cin>>T;
	while(T--) {
		cin>>n;
		string a;
        for(int i = 1;i<=n;i++)
            a += to_string(i);//ת�����ַ���
		memset(book,0,sizeof(book));//��ʼ��
        for(int i = 0;i < a.size(); i++)
            book[a[i]-'0']++;// - '0' ����Ҫ
        for(int i = 0;i < 10; i++) {
            if(i) cout<<' ';
            cout<<book[i];
        }
        cout<<endl;
	}
	return 0;
}
