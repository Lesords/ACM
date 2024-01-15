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
int n,m,p,vnum,wnum,page;
int num[10] = {10,11,12,13,14,15};
map<int,int> pos;
string to_bin(string s) {
    string ans = "",tri;
    int tmp;
    for(int i = 0;i < s.size();i++) {
        if(s[i]>='0'&&s[i]<='9') tmp = s[i]-'0';
        else tmp = num[s[i]-'A'];
        tri = "";
        while(tmp) {
            if(tmp&1) tri = '1'+tri;
            else tri = '0'+tri;
            tmp >>= 1;
        }
        while(tri.size()<4) tri = '0'+tri;
        ans += tri;
    }
    return ans;
}
string to_hex(string s) {
    string ans = "",tri;
    for(int i = 0;i < s.size();i+=4) {
        int tmp = 0,tt = 1;
        for(int j = i+3;j >= i;j--) {
            if(s[j]=='1') tmp += tt;
            tt *= 2;
        }
        if(tmp>=0&&tmp<=9) ans += tmp+'0';
        else ans += 'A'+tmp-10;
    }
    return ans;
}
int main() {
    cin>>n>>m>>p;
    vnum = 1<<n;
    wnum = 1<<m;
    page = 1<<p;
    int tmp,q;
    for(int i = 0;i < 1<<(m-p);i++) {
        cin>>tmp;
        pos[tmp] = i;
    }
    cin>>q;
    string s,six,two;
    while(q--) {
        cin>>s;
        two = to_bin(s);
        int ppos = 0,tt = 1;
        for(int i = 31-p;i >= 0;i--) {
            if(two[i]=='1') {
                ppos += tt;
            }
            tt *= 2;
        }
        if(pos.find(ppos)==pos.end()) {//值可能为0，所以用find
            cout<<"interrupt!\n";
        }
        else {
            string ans = "";
            ppos = pos[ppos];
            while(ppos) {
                if(ppos&1) ans = '1'+ans;
                else ans = '0'+ans;
                ppos >>= 1;
            }
            for(int i = 32-p;i < 32;i++) ans += two[i];
            while(ans.size()<32) ans = '0'+ans;
            cout<<to_hex(ans)<<endl;
        }
    }
	return 0;
}
