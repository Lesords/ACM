#include<iostream>
#include<cmath> 
using namespace std;
char map[1050][1050]={{},{' ','C','C'},{' ','P','C'}};//最大为1024
void init() {
	for(int i=2;i<=10;i++) {
		int left=pow(2,i-1);//1区的大小 
		int right=pow(2,i);//窗口的总大小 
		for(int j=1;j<=left;j++)
			for(int k=left+1;k<=right;k++)
				map[j+left][k]=map[j][k]=map[j][k-left];//2、4区同时赋值 
		for(int j=left+1;j<=right;j++)
			for(int k=1;k<=left;k++)
				map[j][k]=(map[j-left][k]=='P')?'C':'P';//3区赋值 
	}
}
int main() {
	int T;
	init();
	cin>>T;
	while(T--) {
		int k,len;
		cin>>k;
		len=pow(2,k);//len为k阶的大小范围 
		for(int i=1;i<=len;i++) {
			for(int j=1;j<=len;j++)
				cout<<map[i][j];
			cout<<endl;
		}
	} 
	return 0;
}
