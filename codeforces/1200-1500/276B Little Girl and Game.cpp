#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺�����ַ���˳��������⣬���Ծ����ַ����Ƿ��ǻ��Ĵ��������ǣ�
//Ϊ �������ַ� ������
//�������ַ� ������Ϊ0����Ϊ�������ǵ�һ����Ӯ������Ϊ�ڶ�����Ӯ
//��Ϊÿ���˵�����ѡ����ɾ�� һ�����������ַ�
//��Ϊ��Ӧ�� ż�����ַ� ˫��������ɾ����ɾ������ɾ��ǰ����Ӱ��

int cnt[30];
int main() {
    string s;
    cin>>s;
    //ͳ�������ַ����ֵĴ���
    for(int i = 0;i < s.size();i++) cnt[s[i]-'a']++;
    int num = 0;
    for(int i = 0;i <= 25;i++) {
        if(cnt[i]&1) num++;//��¼���������ε�����
    }
    if(num==0||num&1) cout<<"First";//Ϊ0����Ϊ���������ǵ�һ����Ӯ
    else cout<<"Second";
    return 0;
}
