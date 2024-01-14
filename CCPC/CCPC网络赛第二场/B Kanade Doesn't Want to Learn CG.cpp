#include<iostream>//ac
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-8
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题解：计算几何
//由于进球只有两种情况，直接进和打板进
//那么直接考虑进球的两种情况
//1. 直接进，那么对于抛物线而言，在篮筐左端点的函数值肯定要高于篮筐位置
//在篮筐右端点的函数肯定要小于篮筐位置，那么中间才会进球
//1. 打板进，由于为完全弹性碰撞，那么打板后的路径与原来的路径实际上是对称的
//那么可以先计算篮筐左端点对应的对称点
//则有在篮筐左端点的函数值肯定要高于篮框位置
//对应的对称点的函数值肯定要小于篮筐位置，篮筐右端点的函数值肯定要小于等于篮板上沿高度
//需要特判的是：当球刚好砸中篮筐右端点时，球会弹开

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
double a, b, c;
double cal(double val) {//x为val的函数值
	return (a*val*val)+b*val+c;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	cin >> a >> b >> c;
    	double x0, x1, y0, y1, y2;
    	cin >> x0 >> x1 >> y0 >> y1 >> y2;
    	double rr = x1+(x1-x0);
    	if(cal(x1)==y0) {//砸到边框会弹出，所以为No
    		cout<<"No\n";
    		continue;
    	}
    	if(cal(x0) > y0 && cal(x1) < y0) {//直接进
    		cout<<"Yes\n";
    		continue;
    	}
    	if(cal(x1) <= y2 && cal(x0) > y0 && cal(rr) < y0) {//打板进
    		cout<<"Yes\n";
    		continue;
    	}
    	//剩余的都是不进的情况
    	cout<<"No\n";
    }
    return 0;
}
