#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：将a数组排序，然后遍历数组b的所有元素，利用二分来查找<=b[i]的数量

const int MAXN = 2e5+5;
int a[MAXN], b[MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//数组a排序
    for(int i = 1;i <= m;i++) cin>>b[i];
    for(int i = 1;i <= m;i++) {
        int l = 1, r = n,ans = 0;
        while(l<=r) {//二分
            int mid = (l+r)/2;
            //满足 <= 的，扩大l的位置，并更新答案
            if(a[mid]<=b[i]) ans = mid,l = mid+1;
            else r = mid-1;//不满足，则缩小区间
        }
        cout<<ans<<" ";
    }
    return 0;
}
