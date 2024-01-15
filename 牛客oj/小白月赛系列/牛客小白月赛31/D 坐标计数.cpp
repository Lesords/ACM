#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：所有的整数点都可以变为(0,0)，所以就是求对应矩阵面积

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;//x2和y2值大
        cout<<(x2-x1+1)*(y2-y1+1)<<"\n";
    }
    return 0;
}
