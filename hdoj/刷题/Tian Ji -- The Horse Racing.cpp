#include<iostream>//ac
#include<algorithm> 
using namespace std;
int a[1005],b[1005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int n;
	while(cin>>n&&n) {
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 1;i <= n;i++) cin>>b[i];
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		int win = 0,tj,kin,tn,kn;
		tj = kin = 1;
		tn = kn = n;
		while(tj<=tn&&kin<=kn) {
			if(a[tj]>b[kin]) win++,tj++,kin++;
			//田径的马比齐威王的快，两人好马++
			else if(a[tj]<b[kin]) win--,tn--,kin++;
			//田径的马比齐威王的慢，田径的坏马跟好马比
			else {//速度一样快，就判断最慢的马
				if(a[tn]>b[kn]) win++,tn--,kn--;
				//田径的慢马快，两人去掉慢马
				else if(a[tn]<b[kn]) win--,tn--,kin++;
				//田径的慢马慢，就用慢马跟好马比
				else {
				//一样快的话，就用田径的慢马和齐威王的好马比
					if(a[tn]<b[kin]) win--;//田径慢就减
					//田径的慢马不会比齐威王快
					tn--,kin++;//慢马跟好马比
				}
			}
		}
		cout<<win*200<<endl;
	}
	return 0;
}
