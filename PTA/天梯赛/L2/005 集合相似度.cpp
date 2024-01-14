#include<iostream>//ac
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

//题解：用set存储所有的集合
//每次查询的时候，遍历第一个集合，计算有多少个在第二个集合也出现
//都出现的即为Nc（两个集合都有的不相等整数的个数）
//两个集合的数量和-Nc = Nt（两个集合一共有的不相等整数的个数）

set<int> st[55];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int m;cin>>m;
        for(int j = 1;j <= m;j++) {
            int tmp;cin>>tmp;
            st[i].insert(tmp);
        }
    }
    int k;cin>>k;
    for(int i = 1;i <= k;i++) {
        int a,b,num = 0;
        cin>>a>>b;
        //遍历第一个集合
        for(set<int>::iterator it = st[a].begin();it!=st[a].end();it++) {
            if(st[b].find(*it)!=st[b].end()) num++;//判断是否在第二个集合中也出现
        }
        double aa = num;//aa为共同出现的不相等整数的个数
        double bb = st[a].size()+st[b].size()-num;
        printf("%.2f%%\n",aa/bb*100);
    }
    return 0;
}
