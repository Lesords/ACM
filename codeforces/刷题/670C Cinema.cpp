#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：记录所有科学家会的语言，并统计数量
//由于语言的值过大，所以可先离散化
//然后遍历所有电影，取最满足条件的电影

const int MAXN = 2e5+5;
int a[MAXN],b[MAXN],au[MAXN],su[MAXN],num[MAXN];
int cnt;
int query(int val) {//查询val值的位置
    int pos = lower_bound(b+1,b+1+cnt,val)-b;
    if(b[pos]!=val) return 0;//如果pos位置不为val，则表示不存在该值
    //所以返回0，因为位置0的值为0
    return pos;
}
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b+1,b+1+n);//排序
    cnt = unique(b+1,b+1+n)-b-1;//去重
    for(int i = 1;i <= n;i++) {
        num[query(a[i])]++;//统计每个科学家会的语言
    }
    //初始化index为1，在都没有满意的人的时候，选择第一个电影即可
    int index = 1,numa = 0,nums = 0;
    cin>>m;
    for(int i = 1;i <= m;i++) {
        cin>>au[i];
    }
    for(int i = 1;i <= m;i++) {
        cin>>su[i];
        int tmpa = num[query(au[i])];//听懂的人
        int tmps = num[query(su[i])];//看懂字幕的人
        //要么听懂的人多，要么听懂的人一样多但是看字幕的人多
        if(tmpa>numa||(tmpa==numa&&tmps>nums)) {
            numa = tmpa;
            nums = tmps;
            index = i;
        }//相同情况下，nums更新做了（wa点）！！！
    }
    cout<<index;
    return 0;
}
