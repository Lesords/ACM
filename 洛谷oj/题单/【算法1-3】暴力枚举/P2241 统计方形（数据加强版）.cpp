#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：矩形数 = 长方形数 + 正方形数
//所以遍历所有规格的矩形即可
//方格放入矩形数为: 方格长 - 矩形长 + 1

int main() {
    int n,m;
    ll square = 0,rec = 0;//结果爆int
    cin>>n>>m;//n行m列
    for(int i = 1;i <= n;i++) {//行方向的矩形长度
        for(int j = 1;j <= m;j++) {//列方向的矩形长度
            if(i==j) square += (n-i+1)*1ll*(m-j+1);//正方形
            else rec += (n-i+1)*1ll*(m-j+1);//长方形
        }
    }
    cout<<square<<' '<<rec<<endl;
    return 0;
}
