#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题意：共有n个区间，每个区间内取一个点，使得所有点不重复，判断是否可行
//题解：如果我们设置一个当前位置，并且将左边界固定，只存储对应的右边界值
//那么对于当前位置而言，只需要判断是否满足右边界的值即可
//因为取得值都是根据左边界取的，所以当前位置肯定满足左边界的情况！！！
//由于数据范围较大，所以不能直接用vector，但是可以用map和vector嵌套来存储
//然后利用优先队列来存储 已经遍历的左边界 的对应右边界值（当前需要选的区间）
//1. 如果队列中为空，也就说当前位置将前面所有的区间都计算过
//那么可以二分下一个大于等于 当前位置+1 的值，将其设为当前位置（防止TLE）
//2. 否则判断队首值是否满足条件，满足则当前位置后移，否则无解

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        map<int, vector<int>>g;//记录以左边界为下标的所有右边界值
        set<int> st;//记录所有的左边界（方便二分查找下一个位置的左边界）
        int minn = INF, maxx = 0;//minn取最小的左边界，maxx取最大的右边界
        for(int i = 1;i <= n;i++) {
        	int l,r;
        	cin>>l>>r;
        	minn = min(minn, l);
        	maxx = max(maxx, r);
        	g[l].push_back(r);//l起点，存储对应的右边界
        	st.insert(l);//记录对应的起点
        }
        st.insert(INF);//末尾加入最大值（用于最后的左位置）
        priority_queue<int, vector<int>, greater<int> > q;//从小到大排序
        int pos = minn;//pos为当前位置（还未选择）
        bool ok = true;
        while(pos <= maxx) {//必须在maxx范围内（超过了，不满足区间范围）
        	if(g.find(pos)!=g.end()) {//将当前位置的 所有右边界存入队列中
        		for(int i = 0;i < g[pos].size();i++) {
        			q.push(g[pos][i]);
        		}
        	}
        	if(q.empty()) {//如果为空，直接跳到 大于等于 下一个位置 的左边界位置
        		pos = *st.lower_bound(pos+1);
        	}
        	else {
        		//否则判断是否满足条件
        		if(pos<=q.top()) {//q.top()范围内满足条件，否则不满足条件
        			pos++,q.pop();//后移，并且弹出
        		}
        		else break;
        	}
        }
        ok = q.empty();
        puts(ok?"Yes":"No");
    }
	return 0;
}
/*
1
4
1 5
2 5
3 5
4 4
yes

1
5
2 6
2 2
3 3
4 4
5 5
yes
*/