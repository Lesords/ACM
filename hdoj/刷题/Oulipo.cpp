#include<iostream>//ac
#include<cstring>
using namespace std;
const int MAXN = 1e6 + 5;
char a[10005],b[MAXN];
int nextt[10005],len_a,len_b,ans;
void get_next() {//����nextt����
	int i = 0,j = -1;
	nextt[i] = j;
	while(i < len_a) {
		if(a[i] == a[j]||j==-1) nextt[++i] = ++j;
		else j = nextt[j];
	}
}
void kmp() {
	get_next();
	int i = 0,j = 0;
	while(i < len_a && j < len_b) {
		if(a[i] == b[j]||i == -1) i++,j++;
		else i = nextt[i];
		if(i == len_a) {//ƥ��ɹ�
			ans++;
			i = nextt[i];//ģʽ���������
		}
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		len_a = strlen(a),len_b = strlen(b);
		ans = 0;
		kmp();
		cout<<ans<<endl;
	}
	return 0;
}
