#include<iostream>//ac
#include<cmath>
using namespace std;
int main() {
	int n,tmp,sign;
	cin>>n;
	for(int i = n;i >= 0;i--) {//�ܹ�n+1������
		cin>>tmp;
		if(!tmp) continue;//0���� 
		sign = (tmp>=0)?1:0;//1Ϊ+��0Ϊ-
		tmp = abs(tmp);
		if(!sign) cout<<'-';//����������
		else if(i!=n) cout<<'+';//��һ����������
		if(tmp>1) cout<<tmp;
		else if(!i) cout<<tmp;//����������1
		if(i) {//�ǳ�����
			if(i>1) cout<<"x^"<<i;
			else cout<<'x';//��С��
		}
	}
	cout<<endl;
	return 0;
}
