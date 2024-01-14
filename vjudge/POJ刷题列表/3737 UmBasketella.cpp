#include<iostream>//ac
#include<cstring>
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
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;

//题解：三分
//由于圆锥公式：
//S总 = S底 + S侧 = pi * r * r + pi * r * L
//L = sqrt(h*h + r*r)
//V总 = S底 * 高 / 3= pi*r*r * h /3

//由于 V总 对于r来说是二次函数，所以令r为变量
//三分r的值，左边界为0，右边界为 sqrt(S/pi)
//根据S总的公式，可以得出 L = S/pi/r - r
//接着可得 高h = sqrt(L*L - r*r)
//最后由于h和L都已知，所以可以直接求圆锥体积

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
double s;
double cal(double r) {//计算以r为底面积半径时的容器体积
	double L = s/pi/r - r;
	double h = sqrt(L*L - r*r);
	return pi*r*r * h /3;
}
int main() {
	while(cin>>s) {
		//对应左右边界
		double l = 0, r = sqrt(s/pi);
		while(r-l > eps) {
			double m1 = l+(r-l)/3;//三分
			double m2 = r-(r-l)/3;
			if(cal(m1)<cal(m2)) l = m1;//左边小，则舍去
			else r = m2;//否则舍去右边
		}
		//最后得需要知道 底面半径 和倾斜高度 以及 体积
		double L = s/pi/r - r;
		double h = sqrt(L*L - r*r);
		double ans = pi*r*r *h /3;
		printf("%.2f\n%.2f\n%.2f\n", ans, h, r);
	}
    return 0;
}
