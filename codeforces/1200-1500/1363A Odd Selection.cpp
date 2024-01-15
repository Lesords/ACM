#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：统计所有奇数和偶数的数量，由于结果为奇数，则奇数的数量必须为奇数
//然后枚举奇数的数量（奇数枚举1,3,5···）
//判断剩余的数是否不为负数，并且小于偶数的数量
//不满足则不成立

const int MAXN = 1005;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        int odd = 0,even = 0,flag = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            a[i]%2==0?even++:odd++;//统计奇偶数量
        }
        for(int i = 1;i <= odd;i+=2) {//枚举奇数的数量（奇数个）
            int rest = x-i;//剩余的数量，不能为负数！！！
            if(even>=rest&&rest>=0) {//剩余的偶数大于差值才满足条件
                flag = 1;break;
            }
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
