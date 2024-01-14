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
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：multiset+vector组合
//利用vector来存储还没排序的元素，multiset存储已经排序的元素

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
multiset<int> st;
vector<int> vec;
int main() {
	int n;
	scanf("%d", &n);
	int op, x;
	int cnt = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%d", &op);
		if(op==1) {
			scanf("%d", &x);
			vec.push_back(x);
		}
		else if(op==2) {
			if(st.empty()) {
				printf("%d\n", vec[cnt]);
				cnt++;
			}
			else {
				printf("%d\n", *st.begin());
				st.erase(st.begin());
				//只能根据地址删除元素，否则会将所有相同值都删除！！！
			}
		}
		else {
			while(cnt>=0&&cnt<vec.size()) {
				st.insert(vec[cnt++]);
			}
		}
	}
    return 0;
}