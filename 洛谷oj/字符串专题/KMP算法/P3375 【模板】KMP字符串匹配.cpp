#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;

//��⣺kmp
//��¼���г��ֵ�λ�ã�ƥ��ɹ���ʱ������ͷƥ��һ�Σ�ֱ������λ�ö�ƥ�����
//����border��ֵ����ʵ����nextt�����ֵ
//ֻ��������ƥ��ɹ�����ƣ����Զ�Ӧλ��Ҳ��Ҫ���ƣ�����

int len_n,len_m,nextt[MAXN];
char n[MAXN],m[MAXN];//nΪ������mΪ�̴�
void get_nextt() {
	int i = 0,j = -1;
	nextt[i] = j;
	while(i<len_m) {//Ŀ�괮����
		if(m[i] == m[j]||j == -1) nextt[++i] = ++j;
		else j = nextt[j];//�������
	}
}
bool kmp() {
	int i = 0, j = 0;
	get_nextt();
	while(i<len_n&&j<len_m) {
		if(n[i]==m[j]||j==-1) i++,j++;
		else j = nextt[j];//����
		if(j == len_m) {
            //i����һλ������ֱ�� -len_m��Ϊ��߽�
            //�������ڽ����1��ʼ����+1
            cout<<i-len_m+1<<"\n";
            j = nextt[j];//������ƥ��
		}
	}
	if(j == len_m) return true;
	return false;
}

int main() {
    cin>>n>>m;
    len_n = strlen(n);//�ȼ�¼�ַ����ĳ��ȣ�����
    len_m = strlen(m);
    get_nextt();
    kmp();
    //ԭ����0��ʼ������nextt��¼����ƣ����Դ�1��ʼ
    for(int i = 1;i <= len_m;i++) cout<<nextt[i]<<" ";
    return 0;
}
