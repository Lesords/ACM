#include<iostream>//ac
#include<string>
using namespace std;
char tree[1<<11];//n最大为10
int n;
void build_tree(string a,int root) {//建二叉树
	int B = 0, I = 0;
	for(int i = 0;i < a.size();i++) {
		if(a[i]=='0') B = 1;
		else if(a[i]=='1') I = 1;
		if(B&&I) break;
	}
	if(B&I) tree[root] = 'F';//01都有为F 
	else tree[root] = (B?'B':'I');
	if(a.size()==1) return;//不可分时不进行递归
	int mid = a.size()/2;
	//a.substr(0,mid) ： 从0开始截取mid个字符
	build_tree(a.substr(0,mid),root<<1);//左递归 
	build_tree(a.substr(mid,mid),root<<1|1);//右递归
}
void postorder(int root) {//后序遍历
	if(root>=(1<<(n+1))) return;//越界
	postorder(root<<1);//先左
	postorder(root<<1|1);//后右
	cout<<tree[root];//再输出根值
}
int main() {
	string a;
	cin>>n>>a;
	//2^n 可生成 （n+1）层树，则范围为 1 ~ ( (1<<(n+1)) - 1 )
	build_tree(a,1);
	postorder(1);
	return 0;
} 
