#include<iostream>//ac
using namespace std;
int main() {
	int n,m,cnt = 0;
	cin>>n>>m;
	while(n--) {//��������--
		cnt++;
		if(!(cnt%m)) n++;//����ָ��ʱ�䣬����++
	}
	cout<<cnt<<endl;
	return 0;
} 
