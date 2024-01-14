#include<cstdio>//ac
#include<map>
#define INF 0x3f3f3f3f
using namespace std;
int main() {
	int n;
	while(scanf("%d",&n)&&n) {
		int tmp;
		map<int,int> m;
		map<int,int>::iterator it;
		while(n--) {
			scanf("%d",&tmp);
			m[tmp]++;
		}
		for(it = m.begin();it!=m.end();it++) {
			if(it->second==1) {
				printf("%d\n",it->first);
				break;
			}
		}
	}
	return 0;
} 
