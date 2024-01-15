#include<iostream>//ac
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

//题解：先计算总结果是否在0到3的范围内，如果结果不在范围内，则肯定无解
//然后判断两个极端 -3 和 3是否可以合理计算为0，因为其他值可以在3的范围内进行计算
//先判断-3的情况，有 3 和 (1+2) 和 (1*3) 和 (2*2-1)
//然后在判断是否有多余的-3，如有则无解
//再判断3的情况，有 (-1-2) 和 ((-1)*3) 和 (1+(-2)*2)
//然后判断3的数量是否超过1，超过则无解

const int MAXN = 505;
int num[10];//移3位计数
bool check() {
    int tmp,ans = 0;
    for(int i = -3;i <= 3;i++) {//计算总和
        ans += num[i+3]*i;
    }
    if(ans>3||ans<0) return false;//结果超范围了
    if(num[-3+3]) {
        tmp = min(num[-3+3],num[3+3]);
        num[-3+3] -= tmp;
        num[3+3] -= tmp;
        tmp = min(num[-3+3], min(num[1+3],num[2+3]));
        num[-3+3] -= tmp;
        num[1+3] -= tmp;
        num[2+3] -= tmp;
        tmp = min(num[-3+3],num[1+3]/3);
        num[-3+3] -= tmp;
        num[1+3] -= tmp*3;
        tmp = min(num[-3+3], min(num[-1+3],num[2+3]/2));
        num[-3+3] -= tmp;
        num[-1+3] -= tmp;
        num[2+3] -= tmp*2;
    }
    if(num[-3+3]) return false;//-3的数量需为0
    if(num[3+3]) {
        tmp = min(num[3+3],min(num[-1+3],num[-2+3]));
        num[3+3] -= tmp;
        num[-1+3] -= tmp;
        num[-2+3] -= tmp;
        tmp = min(num[3+3],min(num[1+3], num[-2+3]/2));
        num[3+3] -= tmp;
        num[1+3] -= tmp;
        num[-2+3] -= tmp*2;
        tmp = min(num[3+3], num[-1+3]/3);
        num[3+3] -= tmp;
        num[-1+3] -= tmp*3;
    }
    if(num[3+3]>1) return false;//3的数量不能超过1！！！
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,tmp;
        cin>>n;
        memset(num,0,sizeof(num));//初始化
        for(int i = 1;i <= n;i++) cin>>tmp,num[tmp+3]++;
        cout<<(check()?"Yes\n":"No\n");
    }
    return 0;
}
