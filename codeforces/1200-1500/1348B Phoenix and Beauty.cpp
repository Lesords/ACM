#include<iostream>//ac
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

//题解：由于每个k子段都需要相等，那么就需要k段周期循环（k个数循环
//所以超过k个数不可以构成循环，小于k个数可以用1补齐

const int MAXN = 105;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        set<int> st;//统计不同数的个数
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            st.insert(a[i]);
        }
        if(st.size()>k) {//超过k个则无解，跳过！！！
            cout<<"-1\n";
            continue;
        }
        cout<<n*k<<"\n";//每个数都构造相同的顺序（其中一个必在里面）
        for(int i = 1;i <= n;i++) {
            for(int val:st) {//遍历出现的所有数
                cout<<val<<" ";
            }
            //不足k个的用1补齐
            for(int j = 1;j <= k-st.size();j++) cout<<"1 ";
        }
        cout<<"\n";
    }
}
