#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：暴力选择区间+差分
//利用差分来修改区间，然后根据前缀和来判断当前牛是否面向前方

const int MAXN = 5e3+5;
int a[MAXN],d[MAXN],n;//d数组保存差分的值
int solve(int len) {
    memset(d,0,sizeof(d));//初始化为0，即无操作
    int now = 0,num = 0;//now为前缀和的值，num为操作数
    for(int i = 1;i <= n;i++) {
        now += d[i];
        if(i+len-1<=n) {//长度满足修改的区间
            if((a[i]+now)%2==0) {//当前面向后方，则修改
                d[i]++;//差分
                now++;//当前前缀和的值需要修改！！！
                d[i+len]--;//区间为len
                num++;//操作数++
            }
        }
        else {
            if((a[i]+now)%2==0) {//当前面向后方，并且剩余长度不够修改
                return -1;//则无解
            }
        }
    }
    return num;
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        char ch;
        cin>>ch;
        a[i] = ch=='F';//1为面向前方
    }
    int ans_cnt = INF,ans_len = 0;
    for(int i = 1;i <= n;i++) {//暴力枚举所有区间
        int cnt = solve(i);
        if(cnt!=-1&&cnt<ans_cnt) {//有解，则取较小操作数
            ans_cnt = cnt;
            ans_len = i;
        }
    }
    cout<<ans_len<<" "<<ans_cnt<<"\n";
    return 0;
}
