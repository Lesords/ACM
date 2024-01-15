#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：从小到大排序，然后对应的数量转为对应下标值即可
//计算过程注意取绝对值

const int MAXN = 3e5+5;
ll a[MAXN],ans;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//从小到大排序
    for(int i = 1;i <= n;i++) {//i即为当前目标数
        ans += llabs(i-a[i]);//取绝对值
    }
    cout<<ans;
    return 0;
}
