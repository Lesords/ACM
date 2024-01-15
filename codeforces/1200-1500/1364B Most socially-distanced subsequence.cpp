#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：以三个为一段，若这三个为升序或降序，则中间的点可省略（起点和终点不省略）

const int MAXN = 1e5+5;
int p[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> ans;
        for(int i = 1;i <= n;i++) cin>>p[i];
        for(int i = 1;i <= n;i++) {
            //三段不为有序，或为起点和终点，则添加到ans中
            if(i==1||i==n||p[i-1]<p[i]!=p[i]<p[i+1]) ans.push_back(p[i]);
        }
        cout<<ans.size()<<"\n";
        for(int i = 0;i < ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
