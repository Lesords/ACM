#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	int T,n;
	char name[35];
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		double c,s;//double ∑Ò‘Ú tle
		int flag = 0;
		double up = 0,down = 0;
		while(n--) {
			scanf("%s%lf%lf",name,&c,&s);
			if(s<60) {
				flag = 1;
				continue;
			}
			if(flag) continue;
			up += c * s;
			down += c;
		}
		if(flag) printf("Sorry!\n");
		else printf("%.2f\n",up/down);
		if(T) printf("\n");
	}
	return 0;
}
