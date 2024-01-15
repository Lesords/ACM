#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：a[1] < a[n]时有解，因为 1-n之间可以找到一个最小的r
//使a[1] < a[r]，那么1-r中间所有的元素都可以与r匹配，被r删掉，然后再把r删掉
//如果反复可使最终只剩一个元素
//如果a[1] > a[n] 的话，那么接下来的操作必须a[2] > a[1]，才能删掉a[1]
//但是由于a[1] > a[n]，所以构成的a[2] > a[n]，导致不匹配

//该题也可用栈来解决，思想与上面类似

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,a,b;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            if(i==1) a = tmp;//记录第一个数
            if(i==n) b = tmp;//记录最后一个数
        }
        if(a<b) cout<<"YES\n";//第一个小于最后一个既有解
        else cout<<"NO\n";
    }
    return 0;
}
