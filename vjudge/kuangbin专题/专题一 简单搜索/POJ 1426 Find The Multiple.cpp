#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,flag;//nΪĿ������flag�ж��Ƿ����д�
char s[105];//�ַ����ĸ��Ӷȹ��ߣ�������ȽϿ죡����
//���ô�������˼�룬ÿ��ֻ��Ҫ���������������ɣ�����Ϊ0����������
void dfs(int rem,int pos) {//remΪ������posΪ��һ��������λ��
    if(flag||pos>100) return;//���ҵ����򳬹���Χ�����������100λ��
    if(rem==0) {//��������
        for(int i = 1;i <= pos;i++) cout<<s[i];
        cout<<"\n";
        //flag���
        flag = 1;return ;
    }
    //����������ʱ����pos+1��λֻ���������� 0��1
    if(!flag) s[pos+1] = '0',dfs(rem*10%n,pos+1);//���0
    if(!flag) s[pos+1] = '1',dfs((rem*10+1)%n,pos+1);//���1
}
int main() {
    while(cin>>n&&n) {
        flag = 0;
        memset(s,0,sizeof(s));//��ʼ��
        s[1] = '1';//��һλ�ض���1
        dfs(1%n,1);//�ӵ�һ��λ�ÿ�ʼdfs
    }
    return 0;
}
