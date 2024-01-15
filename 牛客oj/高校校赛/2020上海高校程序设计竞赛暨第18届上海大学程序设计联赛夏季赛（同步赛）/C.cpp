#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        string s;
        int num = 0;
        cin>>n;
        getchar();//´¦ÀíÄ©Î²×Ö·û
        for(int i = 1;i <= n;i++) {
            getline(cin,s);
            for(int j = 0;j < s.size();j++) {
                if(s[j]=='2') {
                    num++;break;
                }
            }
        }
        printf("%.10f\n",num*1.0/n*1.0);
    }
	return 0;
}

