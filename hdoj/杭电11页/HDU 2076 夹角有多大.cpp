#include<iostream>//ac
#include<cmath>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int hour,minute,second; 
		cin>>hour>>minute>>second;
		if(hour>=12) hour -= 12;//小时可能会超过12
		double mi_hand = minute * 6 + second/10.0;
		//分针一格有6度（计算second秒所走的度数，second/60*6） 
		double ho_hand = hour * 30 + (minute + second/60.0)/2.0;
		//时针一格有30度
		//额外的：（minute+second/60.0）/60 * 5 * 6 
		double ans = abs(mi_hand - ho_hand);
		if(ans>180) cout<<floor(360-ans)<<endl;//向下取整
		else cout<<floor(ans)<<endl; 
	}
	return 0;
}
