#include<iostream>//tle 02¹ýµÄ
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
struct node{
	int num,score,val;
	friend bool operator < (node a, node b) {
		if(a.score==b.score) return a.num < b.num;
		return a.score > b.score;
	}
}a[MAXN*2];
int main() {
	int N,R,Q;
	scanf("%d%d%d",&N,&R,&Q);
	for(int i = 1;i <= 2*N;i++) {
		scanf("%d",&a[i].score);
		a[i].num = i;
	}
	for(int i = 1;i <= 2*N;i++) scanf("%d",&a[i].val);
	stable_sort(a+1,a+(2*N+1));
	while(R--) {
		for(int i = 1;i <= 2*N;i+=2) {
			a[i].val>a[i+1].val?a[i].score++:a[i+1].score++;
		}
		stable_sort(a+1,a+(2*N+1));
	}
	cout<<a[Q].num<<endl;
	return 0;
}
