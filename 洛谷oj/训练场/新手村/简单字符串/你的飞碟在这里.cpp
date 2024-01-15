#include<iostream>//ac
#include<cstring>
using namespace std;
char a[10],b[10];
int judge(char a[]) {
	int ans = 1;
	for(int i = 0;i < strlen(a);i++) {//长度不固定
		ans *= (a[i]-'A'+1);//记得 + 1！！！
	} 
	return ans%47;
}
int main(){
	cin>>a>>b;
	if(judge(a)==judge(b)) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}
