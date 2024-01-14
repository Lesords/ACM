#include<iostream>
#include<algorithm>
using namespace std;
int val[105],ans[105];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) cin>>val[i];
    for(int i = 1;i <= m;i++) cin>>ans[i];
    for(int i = 1;i <= n;i++) {
        int num = 0;
        for(int j = 1;j <= m;j++) {
            int tmp;
            cin>>tmp;
            num += (tmp==ans[j])?val[j]:0;
        }
        cout<<num<<endl;
    }
    return 0;
}
