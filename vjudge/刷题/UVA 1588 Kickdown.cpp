#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 999999
using namespace std;
int is_right(string a,string b,int len,bool dir) {
	for(int i = 1;i <= len;i++)//�ƶ���ǰ������
		dir?b = '0' + b:a = '0' + a;
	while(b.size()<a.size()) b += '0';//��С�Ŀ�󷽲���
	while(a.size()<b.size()) a += '0';
	int l_a = 0,l_b = 0;
	while(l_a<a.size()) {
		int tmp1 = a[l_a] - '0';
		int tmp2 = b[l_b] - '0';
		if(tmp1+tmp2>3) return INF;//����������
		l_a++,l_b++;
	}
	return a.size();//�̶��鳤�ȼ�Ϊ��������
}
int main() {
	string a,b;
	while(cin>>a>>b) {//aΪ�ײ��̶���,bΪ�Ϸ��ƶ��� 
		int len = 0,ans = INF;
		while(len<=a.size()||len<=b.size()) {//lenС�����⴮
			ans = min(is_right(a,b,len,1),ans);//������
			ans = min(is_right(a,b,len,0),ans);//�����ƣ�����
			len++;//�ƶ�λ��++
		}
		cout<<ans<<endl;
	}
	return 0;
} 
