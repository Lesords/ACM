#include<iostream>//ac
#include<string>
using namespace std;
int f(char tmp) {//�жϷ���
	if(tmp=='-') return 0;//����
	return 1;//����
}
int val(char tmp) {//ת��ʮ����
	if(tmp >= '0'&&tmp <= '9') return tmp - '0';
	return tmp - 'A' + 10;
}
char to_hex(int tmp) {//ת��ʮ������
	if(tmp <= 9) return tmp + '0';
	return tmp + 'A' - 10;
}
int a_bigger(string a,string b) {//�Ƚ�a��b��ֵ
	if(a.size()>b.size()) return 1;//aֵ��
	if(a.size()<b.size()) return 0;
	for(int i = 0;i < b.size();i++) {
		if(val(a[i])>val(b[i])) return 1;//aֵ��
		if(val(a[i])<val(b[i])) return 0;
	}
	return 2;//��ֵ���
}
string sub(string a,string b) {//a - b��ֵ
	int len = a.size() - 1;
	while(b.size() < a.size()) b = '0' + b;
	for(int i = len;i >= 0;i--) {
		if(val(a[i])<val(b[i])) {//����������λ
			a[i-1] = to_hex(val(a[i-1]) - 1);
			a[i] = to_hex(16 + val(a[i]) - val(b[i]));
		}
		else a[i] = to_hex(val(a[i]) - val(b[i]));
	}
	return a;
}
string cal(string a,string b) {
	int mark_a = f(a[0]);
	int mark_b = f(b[0]);
	if(a[0]=='-'||a[0]=='+') a.erase(0,1);
	if(b[0]=='-'||b[0]=='+') b.erase(0,1);
	if(mark_a==mark_b) {//�ӷ�(��ͬ����)
		while(a.size()<b.size()) a = '0' + a;
		while(b.size()<a.size()) b = '0' + b;
		a = '0' + a;
		b = '0' + b;
		for(int i = a.size() - 1;i >= 0;i--) {
			int sum = val(a[i]) + val(b[i]);
			if(sum>=16) {
				a[i-1] = to_hex(val(a[i-1])+1);//��λ
				a[i] = to_hex(sum-16);
			}
			else a[i] = to_hex(sum);
		}
	}
	else {//���
		if(a_bigger(a,b)==2) return "0";
		if(a_bigger(a,b)) {//a��ֵ��
			a = sub(a,b);
			while(a[0] == '0') a.erase(0,1);
			if(mark_a==0) a = '-' + a;
		}
		else {
			a = sub(b,a);
			while(a[0] == '0') a.erase(0,1);
			if(mark_b==0) a = '-' + a;
		}
	}
	while(a[0]=='0'&&a.size()!=1) a.erase(0,1);//!!!
	if(mark_a==mark_b&&mark_a==0) a = '-' + a;
	return a;
}
int main() {
	string a,b;
	while(cin>>a>>b) {
		cout<<cal(a,b)<<endl;
	}
	return 0;
}
