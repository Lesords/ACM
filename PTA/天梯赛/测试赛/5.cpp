#include<iostream>//ac
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
string ans[1005];
int main() {
    string s;
    getline(cin,s);
    int num = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i]!='6') {
            if(num>9) cout<<"27";
            else if(num>3) cout<<"9";
            else for(int k = 1;k <= num;k++) cout<<'6';
            num = 0;
            cout<<s[i];
        }
        else {
            num++;
            if(i==s.size()-1) {
                if(num>9) cout<<"27";
                else if(num>3) cout<<"9";
                else for(int k = 1;k <= num;k++) cout<<'6';
            }
        }
    }
    return 0;
}
