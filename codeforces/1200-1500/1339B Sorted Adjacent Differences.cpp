#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：先排序，然后以中间值为起点，依次向左右分别取值即可

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        //取较高的中位数，确保可以取到多余的一个高位置值！！！
        int mid = (n+1)/2, pos = 0;//pos表示与中间位置的距离
        cout<<a[mid];//中间值为起点
        while(++pos) {
            if(mid+pos<=n) cout<<" "<<a[mid+pos];//右边
            else break;//超过则结束
            if(mid-pos>=1) cout<<" "<<a[mid-pos];//左边
            else break;//超过则结束
        }
        cout<<"\n";
    }
    return 0;
}
