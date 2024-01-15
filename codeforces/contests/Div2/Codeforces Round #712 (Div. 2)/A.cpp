#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
bool judge(string tmp) {//判断是否不为回文串
    string tri = tmp;
    reverse(tri.begin(),tri.end());
    return tri!=tmp;//不是回文串，则返回true
}
int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--) {
        string tmp;
        cin>>tmp;
        int flag = 0;
        for(int i = 0;i < tmp.size();i++) {
            if(tmp[i]!='a') {//判断是否全为字符a
                flag = 1;break;
            }
        }
        if(!flag) {//如果全为字符a，则无解
            cout<<"NO\n";
            continue;
        }
        if(!judge(tmp)) {//如果当前已经是回文串，那么直接添加即可
            cout<<"YES\n";
            cout<<'a'<<tmp<<"\n";
            continue;
        }
        int len = tmp.size();
        for(int i = 0;i <= len;i++) {//判断在当前位置添加字符的对应位置是否为a
            if(tmp[len-1-i]!='a') {//len-1-i与i位置相互对应
                tmp.insert(i, "a");//不同即可添加，即为结果
                cout<<"YES\n";
                cout<<tmp<<"\n";
                break;
            }
        }
    }
	return 0;
}
