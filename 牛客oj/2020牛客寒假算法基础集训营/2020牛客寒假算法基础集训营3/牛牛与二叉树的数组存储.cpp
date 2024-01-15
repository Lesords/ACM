#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 5;
int tree[MAXN],pos[MAXN];
int main() {
	int n,size = 0,cnt = 1;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tree[i];
		if(tree[i]!=-1) {
			size++;
			pos[tree[i]] = i;
		}
	}
	printf("The size of the tree is %d\n",size);
	printf("Node %d is the root node of the tree\n",tree[1]);
	for(int i = 1;i <= size;i++) {
		int l_child,r_child,father;
		father = (pos[i]/2>n||pos[i]/2<1)?-1:tree[pos[i]/2];
		l_child = (2*pos[i]<=n)?tree[2*pos[i]]:-1;
		r_child = (2*pos[i]+1<=n)?tree[2*pos[i]+1]:-1;
		printf("The father of node %d is %d",cnt++,father);
		printf(", the left child is %d,",l_child);
		printf(" and the right child is %d",r_child);
		if(i!=size) printf("\n");
	}
	return 0;
}
