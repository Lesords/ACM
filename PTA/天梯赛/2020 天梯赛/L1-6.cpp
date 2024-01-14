#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e4+5;
bool check(char tmp) {
    if(tmp>='a'&&tmp<='z') return 0;
    if(tmp>='A'&&tmp<='Z') return 0;
    if(tmp>='0'&&tmp<='9') return 0;
    return 1;
}
int main() {
    int cnt = 0,ans = 0,first = 0;
    string chi = "chi1 huo3 guo1";
    int len = chi.size()-1;
    while(1) {
        string tmp;
        getline(cin,tmp);
        //只有一个.字符才结束！！！
        if(tmp[0]=='.'&&tmp.size()==1) break;
        cnt++;
        int pos = 0;
        for(int i = 0;i < (int)tmp.size();i++) {
            if(tmp[i]==chi[pos]) pos++;
            else pos = 0;
            if(pos==len+1) {
                if(first==0) first = cnt;
                ans++;break;
            }
        }
    }
    cout<<cnt<<"\n";
    if(ans) {
        cout<<first<<" "<<ans;
    }
    else cout<<"-_-#";
    return 0;
}
