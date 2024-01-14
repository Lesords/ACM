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
            a += to_string(i);//转换成字符串
		memset(book,0,sizeof(book));//初始化
        for(int i = 0;i < a.size(); i++)
            book[a[i]-'0']++;// - '0' 很重要
        for(int i = 0;i < 10; i++) {
            if(i) cout<<' ';
            cout<<book[i];
        }
        cout<<endl;
	}
	return 0;
}
