#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺���������ַ������Ե�ǰ��Ϊ���Ĵ����ģ���ǰ����չ�ж���Ļ��Ĵ���С
//��Ҫע����ǣ����Ĵ���������ż��������һ�����ĺ���������
//������Ҫ�ж�����

int main() {
    string s;
    getline(cin,s);
    int ans = 0,len = s.size();
    for(int i = 0;i < len;i++) {//���������ַ���
        int num = 1;//�������Ĵ���һ������
        for(int j = 1;j < len;j++) {
            if(i-j<0||i+j>=len) break;//ǰ����һ��Խ���˶�����
            if(s[i-j]!=s[i+j]) break;//ǰ������򣬽���
            num += 2;//������Ĵ��ĳ��� +2��ǰ���һ����
        }
        ans = max(ans,num);//ȡ�ϴ�ֵ
        if(i+1>=len||s[i]!=s[i+1]) continue;//����һ��Խ�磬���߲����
        num = 2;//��������: һ����i��һ����(i+1)
        for(int j = 1;j < len;j++) {
            if(i-j<0||(i+1)+j>=len) break;//Խ��
            if(s[i-j]!=s[(i+1)+j]) break;//i-j������
            num += 2;
        }
        ans = max(ans,num);//ȡ�ϴ�ֵ
    }
    cout<<ans<<endl;
    return 0;
}
