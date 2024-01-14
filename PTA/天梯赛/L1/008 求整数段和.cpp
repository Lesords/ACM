#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int a,b,sum = 0,cnt = 1;
    cin>>a>>b;
    for(int i = a;i <= b;i++) {//每到达5的倍数就一个回车
        sum += i;
        printf("%5d",i);//每个数字占五位6
        if(i!=b&&cnt%5==0) cout<<'\n';//处理回车（忽略最后一位！！！）
        cnt++;
    }//最后一位无需回车，否则会与下方重复输出
    cout<<"\nSum = "<<sum;
    return 0;
}
