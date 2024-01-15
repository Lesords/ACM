#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于是计算最后可以出现1的位置数量
//所以可以从头到尾计算两个区间是否有交集，有交集则扩域，否则跳过

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x,m;
        cin>>n>>x>>m;
        int l = x,r = x;//初始化范围即为x
        for(int i = 1;i <= m;i++) {
            int a,b;
            cin>>a>>b;
            if(a>r||b<l) continue;//没有交集，则跳过
            l = min(l, a);//l更新为较小的
            r = max(r, b);//r更新为较大的
        }
        cout<<(r-l+1)<<"\n";//计算[l,r]的数量
    }
    return 0;
}
