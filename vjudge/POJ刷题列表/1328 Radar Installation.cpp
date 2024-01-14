#include<iostream>//ac
#include<cmath>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;

//题解：计算每个点在x轴中能够被雷达覆盖的范围[l,r]
//那么对于原题目，可以转换为在若干个区间中，选择最少的点，使得所有区间至少都有一个点
//将区间按照l的大小，从小到大排序，用变量pos记录上一个雷达的位置
//判断过程：如果pos>=l[i]，说明满足当前点的要求，pos需要更新(pos = min(pos,r[i])
//例如：[1,7] [2,5] 这两个区间，对于后一个来说，雷达需要在满足上一个的条件下，尽量靠后，即为5
//否则需要多添加一个雷达，放置位置为r[i]（尽量靠后

struct node{
    double l,r;
    friend bool operator < (node a,node b) {
        return a.l < b.l;//从小到大排序
    }
};
vector<node> v;//存区间
double get_dis(double d,double y) {
    return sqrt(d*d-y*y);//计算投影到x轴的长度
}
int main() {
    int n,cas = 0;
    double m;
    while(cin>>n>>m&&n&&m) {
        v.clear();                      //清空！！！
        int flag = 0;                   //标记是否有解
        for(int i = 1;i <= n;i++) {
            double x,y;
            cin>>x>>y;
            if(flag||y>m) {             //离x轴的距离大于雷达的范围，则无解！！！
                flag = 1;continue;
            }
            double dis = get_dis(m,y);  //投影到x轴的长度
            node tmp = {x-dis,x+dis};   //区间即为x为中点，左右扩大dis
            v.push_back(tmp);
        }
        if(flag) {                      //特判无解的情况！！！
            cout<<"Case "<<++cas<<": -1\n";
            continue;
        }
        sort(v.begin(),v.end());        //排序
        double pos = -INF;              //初始化起点为负无穷
        int ans = 0;
        for(int i = 0;i < v.size();i++) {
            if(pos>=v[i].l) {           //满足条件
                pos = min(pos,v[i].r);  //更新为较小的位置
            }
            else ans++, pos = v[i].r;   //添加数量++，更新位置
        }
        cout<<"Case "<<++cas<<": "<<ans<<"\n";
    }
    return 0;
}
