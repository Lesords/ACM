#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：先x后y的规则排序，从头开始走，如果y轴出现负方向即无解
//x和y轴对应距离即为R和U出现的次数

const int MAXN = 1e3+5;
struct node{
    int x,y;
    friend bool operator < (node a,node b) {
        //先x后y的顺序排序
        if(a.x!=b.x) return a.x < b.x;
        return a.y < b.y;
    }
}a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,flag = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i].x>>a[i].y;
        }
        sort(a+1,a+1+n);
        string ans = "";
        for(int i = 1;i <= n;i++) {
            int dis_x = a[i].x - a[i-1].x;
            int dis_y = a[i].y - a[i-1].y;
            if(dis_y<0) {//y不能出现负数（向下走），否则无解
                flag = 1;break;
            }
            for(int j = 1;j <= dis_x;j++) ans += 'R';//dis_x个R
            for(int j = 1;j <= dis_y;j++) ans += 'U';//dis_y个U
        }
        if(flag) {//无解
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<ans<<"\n";
    }
    return 0;
}
