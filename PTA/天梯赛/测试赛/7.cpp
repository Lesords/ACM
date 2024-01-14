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
string s;
int main() {
    int n;
    cin>>n;
    int val = 1,cnt = 1;
    while(val<n) {
        val = val*10+1;
        cnt++;
    }
    while(val) {
        int tmp = val%n;
        int ss = val/n;
        s += (char) ss+'0';
        if(tmp==0) {
            break;
        }
        val = tmp*10+1;
        cnt++;
    }
    cout<<s<<" "<<cnt<<"\n";
    return 0;
}
