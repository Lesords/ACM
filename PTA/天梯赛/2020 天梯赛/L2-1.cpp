#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e4+5;
stack<int> num;
stack<char> op;
int main() {
    int n;cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;cin>>tmp;
        num.push(tmp);
    }
    getchar();
    for(int i = 1;i < n;i++) {
        char ch;cin>>ch;
        op.push(ch);
    }
    while(!op.empty()) {
        int val1 = num.top();num.pop();
        int val2 = num.top();num.pop();
        int val;
        char ch = op.top();op.pop();
        if(ch=='+') {
            val = val2 + val1;
        }
        else if(ch=='-') val = val2-val1;
        else if(ch=='*') val = val2*val1;
        else if(ch=='/') {
            if(val1==0) {
                cout<<"ERROR: "<<val2<<"/0";
                return 0;
            }
            val = val2/val1;
        }
        if(num.size()) num.push(val);
        else {
            cout<<val<<"\n";
            break;
        }
    }
    return 0;
}
