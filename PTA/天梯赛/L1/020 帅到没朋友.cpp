#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
using namespace std;
string s[1005];
int main() {
    int n;
    cin>>n;
    set<string> hav,mark;//hav�洢�����ѵ��ˣ�mark�洢���������
    for(int i = 1;i <= n;i++) {
        int m;cin>>m;
        for(int j = 1;j <= m;j++) cin>>s[j];
        sort(s+1,s+m+1);
        int pos = unique(s+1,s+m+1)-s;//�����ȥ��
        if(pos==2) continue;//���ֻ��һ����������
        for(int j = 1;j < pos;j++) hav.insert(s[j]);//�����ѵ���
    }
    cin>>n;
    int flag = 0;
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        if(mark.count(tmp)) continue;//�����Ѿ������
        if(!hav.count(tmp)) {
            if(flag) cout<<" ";//�����ʽ
            mark.insert(tmp),cout<<tmp;
            flag = 1;
        }
    }
    if(mark.size()==0) cout<<"No one is handsome";//�����˶�������
    return 0;
}
