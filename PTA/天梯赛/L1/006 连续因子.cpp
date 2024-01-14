#include<iostream>//ac
#include<algorithm>
using namespace std;
bool is_prime(int n) {//判断n是否为质数
    for(int i = 2;i*1ll*i <= n;i++) {
        if(n%i==0) return 0;
    }
    return 1;//1表示是质数
}
int main() {
    int n,ans = 0,index = 0;
    cin>>n;
    if(is_prime(n)) {//先特判是否为质数！！！
        cout<<"1\n"<<n;//若为质数则只有一个结果，即本身
        return 0;
    }
    for(int i = 2;i*1LL*i <= n;i++) {//否则直接遍历所有因子，找最大连续即可
        if(n%i) continue;//跳过不是因子的数
        int tmp = n,num = 0;//tmp为当前操作数，num为当前起点的因子数量
        for(int j = i;j <= n;j++) {//直接遍历
            if(tmp%j==0) tmp /= j,num++;//可被整除
            else break;//不可整除则结束
        }
        if(num>ans) {//更新较大值
            ans = num;
            index = i;//index保存第一个因子的大小
        }
    }
    cout<<ans<<"\n";
    for(int i = 0;i < ans;i++) {//共ans个因子
        if(i!=0) cout<<"*";
        cout<<index+i;
    }
    return 0;
}
