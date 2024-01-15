#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：先特判是否有INF的情况
//只有所有的R或B都需要花费法术力，那么令对应的R或者B为0，另一个为INF即可
//否则，将咒语按照先r从小到大排序，再按照b从小到大排序
//遍历所有的咒语，对于当前第i个咒语而言
//满足当前的r必定满足前面的r，所以先满足b，即取最小值的b
//因为r满足了，前面小的b肯定也满足，所以每次都需要取最小的b
//那么对于当前的前i个咒语而言，取(b-1)就不会满足前面的咒语
//接着再取下一个r的最大不满足值，即(r-1)，这样也就不会满足下一个咒语
//即更新答案为 ans = max(ans, (min_b-1) + (next_r-1))
//注：如果min_b为0的话，停止更新答案，因为后面的(r-1)会满足前面的情况
//如果不满足，也不会比前一个更新的值大

const int MAXN = 5e3+5;
struct node{
    int a,b;
    friend bool operator < (node x,node y) {
        if(x.a==y.a) return x.b < y.b;
        return x.a < y.a;//先a后b
    }
}val[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,zero_a = 0, zero_b = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int a,b;
            cin>>a>>b;
            if(a==0) zero_a = 1;
            if(b==0) zero_b = 1;
            val[i] = {a,b};
        }
        if(!zero_a||!zero_b) {//如果有一个没有0，表示有INF的情况
            cout<<"INF\n";
        }
        else {
            sort(val+1,val+1+n);
            int ans = 0,tmp = INF;
            for(int i = 1;i <= n;i++) {
                if(val[i].b==0) break;
                tmp = min(tmp, val[i].b);//取最小的b
                //再取下一个的r（即a）
                ans = max(ans, val[i+1].a-1+tmp-1);//都不满足 -2
//                cout<<i<<" "<<tmp<<" "<<ans<<"\n";
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
/*
2
6
0 100
50 50
60 60
100 0
150 50
1000 0
4
0 1
0 100
99 5
100 0
*/
