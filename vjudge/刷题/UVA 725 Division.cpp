#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
int vis[10];
bool check(int n) {//判断是否重复
    bool flag = false;
    while(n) {
        int tmp = n%10;
        if(vis[tmp]) flag = true;
        vis[tmp] = 1;
        n /= 10;
    }
    return flag;
}
int main() {
    int n,cas=1;
    while(cin>>n&&n) {
        int flag = 0;
        if(cas!=1) cout<<"\n";
        cas++;
        for(int i = 12345;i <= 98765;i++) {
            memset(vis,0,sizeof(vis));
            if(check(i)||i%n) continue;
            int tmp = i/n;
            if(check(tmp)||tmp<999) continue;//不能只有三位
            if(tmp<9876&&vis[0]) continue;//四位范围最大为9876！！！
            cout<<i<<" / "<<(tmp<9876?"0":"")<<tmp<<" = "<<n<<"\n";
            flag = 1;
        }
        if(!flag) cout<<"There are no solutions for "<<n<<".\n";//无结果
    }
    return 0;
}
