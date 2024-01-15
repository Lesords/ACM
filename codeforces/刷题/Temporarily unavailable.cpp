#include<iostream>//ac
#include<algorithm>
using namespace std;

//题意：起始点a和终点b还有个网点c，网点覆盖的范围为r，求没网的大小
//题解：总共有五种情况，分类讨论即可
//全包括，在起末点内，左包括，右包括，不包括

int main() {
	int t,a,b,s,r;
	cin>>t;
	while(t--) {
		cin>>a>>b>>s>>r;
		int minn = min(a,b);
		int maxx = max(a,b);
		int s_l = s - r;
		int s_r = s + r;
		if(s_r>=maxx&&s_l<=minn) cout<<"0"<<endl;//全包括
		else if(minn<=s_l&&s_r<=maxx) //在起末点内
			cout<<maxx-s_r+s_l-minn<<endl;
		else if(minn<=s_l&&s_l<=maxx) //左包括
			cout<<s_l-minn<<endl;
		else if(minn<=s_r&&s_r<=maxx) //右包括
			cout<<maxx-s_r<<endl;
		else cout<<maxx-minn<<endl;
	}
	return 0;
}
