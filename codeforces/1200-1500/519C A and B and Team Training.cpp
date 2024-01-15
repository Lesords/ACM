#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：数据只有5e5，所以直接暴力即可，每次选小的-1，大的-2
//直到不满足条件

int main() {
    int n,m,ans = 0;
    cin>>n>>m;
    while(n&&m) {//n小，m大
        if(n>m) swap(n,m);//交换顺序使n小
        if(n>=1&&m>=2) ans++,n--,m-=2;//小的-1，大的-2
        else break;//不满足条件，则结束
    }
    cout<<ans;
    return 0;
}
