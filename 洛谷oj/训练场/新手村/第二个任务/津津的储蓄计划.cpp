#include<iostream>//ac
using namespace std;
int a[15];
int main() {
	int flag = 0,mine = 0,mother = 0;
	for(int i = 1;i <= 12;i++) {
		cin>>a[i];
		if(flag) continue;
		if(mine+300<a[i]) flag = i;//������
		else {
			int rest = mine+300 - a[i];//ʣ�µ�Ǯ
			if(rest>=100) mother += rest/100 * 100;//��ĸ�׵�
			mine = rest % 100;//�Լ�ʣ�µ�
		}
	}
	if(flag) cout<<"-"<<flag<<endl;//������
	else cout<<mine + mother*1.2<<endl;
	return 0;
}
