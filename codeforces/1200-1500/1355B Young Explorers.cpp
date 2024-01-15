#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：统计各个数出现的次数
//那么每个数值需要的队员数即为本身，所以对应值可以组成的数量为 num[val]/val
//由于前面没有统计的可以归到后面去，所以后面的可以加上前面的余数

const int MAXN = 2e5+5;
int a[MAXN],num[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            num[a[i]]++;//统计数量
        }
        for(int i = 1;i <= n;i++) {
            if(i>1) num[i] += num[i-1]%(i-1);//添加上前面剩余的人数
            ans += num[i]/i;//计算当前值可以组成的数量
            num[i-1] = 0;//清零（memset复杂度过高）！！！
        }
        num[n] = 0;//还剩n位置需要清零
        cout<<ans<<"\n";
    }
    return 0;
}
