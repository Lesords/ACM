#include<iostream>//ac
#include<set>
#include<algorithm>
using namespace std;

//题解：先取n的最小因子a，然后再取n/a的最小因子，最后判断剩余值是否为n或者1
//用set保存因子

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        set<int> st;
        for(int i = 2;i*i <= n;i++) {//计算n的最小因子
            if(n%i==0) {
                st.insert(i);
                n /= i;//去除因子
                break;
            }
        }
        for(int i = 2;i*i <= n;i++) {//n/a中的最小因子
            if(n%i==0&&!st.count(i)) {
                st.insert(i);
                n /= i;
                break;
            }
        }
        //判断是否找到两个因子，并且最后一个因子未出现且不为1
        if(st.size()<2||st.count(n)||n==1) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
            st.insert(n);//添加最后一个因子
            for(int x:st) cout<<x<<" ";//输出3个因子（快捷遍历）
            cout<<"\n";
        }
    }
    return 0;
}
