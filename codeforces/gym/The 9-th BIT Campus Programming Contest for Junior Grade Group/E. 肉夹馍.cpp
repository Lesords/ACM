#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//��⣺ֱ��ģ�⼴��
//����ͼ������Ҫ�Ŀռ��С��Ȼ����м�㿪ʼ����
//�ȳ�ʼ������λ��Ϊ |���ɷ������

const int MAXN = 1e3+5;
char meat[MAXN<<1][MAXN];
void change(int mid, int val, char ch) {
    //��Ӧ����Ϊ mid+val, mid-val;���һ��Ϊ2+val
    for(int i = 1;i <= 2+val;i++) {//���������
        meat[mid-val][i] = meat[mid+val][i] = ch;
    }
    if(ch=='-') return;//Ĥ��ֱ����������Ϊ��ʼ������
    for(int i = 0;i <= val;i++) {//���һ��
        meat[mid-i][2+val] = meat[mid+i][2+val] = ch;
    }
}
int main() {
    string s;
    cin>>s;
    int len = s.size();
    int col = len+1;
    int raw = len*2-1;
    for(int i = 1;i <= raw;i++) {//��ʼ������λ��Ϊ|
        for(int j = 1;j <= col;j++) meat[i][j] = '|';
    }
    for(int i = 0;i < len;i++) {
        char now = (s[i]-'0')?'-':'*';
        change(len, i,now);//�м��len����������ɢi��С��������Ӧ�ַ�Ϊnow
    }
    for(int i = 1;i <= raw;i++) {
        for(int j = 1;j <= col;j++) {
            cout<<meat[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
/*
0000001
0101001
*/
