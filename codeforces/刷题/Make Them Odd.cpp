#include<iostream>//ac
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

//题意：将所有偶数都转换为奇数，操作是 对所有相同数 除2
//题解：利用set保存所有操作的数（偶数）,set的大小即为结果

//数据值过大用数组和map都不行（unordered_map效率会高点）!!!

int main() {
	int t,n;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		int tmp,maxx = 0,ans = 0;
		set<int> s;
		while(n--) {
			cin>>tmp;
			while(tmp%2 == 0) {//偶数
				if(s.count(tmp))  break;//已存在此数，跳过
				s.insert(tmp);//保存所有操作的数(包括2)
				tmp /= 2;
			}
		}
		cout<<s.size()<<endl;
	}
	return 0;
}
