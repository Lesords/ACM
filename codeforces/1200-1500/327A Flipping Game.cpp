#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：统计0和1的个数
//特判：如果都是为1的话，至少需要翻转一个，即需减1
//然后直接扫一遍，判断连续段出现0的次数（0和1可抵消）的最大值
//与1的个数相加即可

int a[105];
int main() {
    int n,one = 0,zero = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        a[i]?one++:zero++;
    }
    if(one==n) {//特判都为1的情况！！！
        cout<<one-1<<"\n";
        return 0;
    }
    int num = 0,ans = 0;//num为局部的0的个数，ans为最大值
    for(int i = 1;i <= n;i++) {
        if(a[i]==0) {
            num++;
            ans = max(ans,num);
        }
        else {
            num--;
            if(num<0) num = 0;//为负数，则重新计数
        }
    }
    ans = max(ans,num);
    cout<<ans+one<<"\n";
    return 0;
}
