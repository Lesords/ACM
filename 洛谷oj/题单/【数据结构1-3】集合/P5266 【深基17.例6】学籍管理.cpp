#include<iostream>//ac
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

//��⣺����map�洢��Ӧ���ֵķ���
//ɾ��һ���˵ķ�����ֱ�Ӹ�ֵΪ-1����
//��ѯѧ�������Ļ���Ҫ��num��¼��ֱ�Ӳ�ѯ�ᳬʱ

map<string,int> score;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,num = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int op,sco;
        string name;
        cin>>op;
        if(op==1) {                                 //����͸��·���
            cin>>name>>sco;
            //��������name����num++
            if(score.find(name)==score.end()||score[name]==-1) num++;
            score[name] = sco;
            cout<<"OK\n";
        }
        else if(op==2) {                            //��ѯ�ɼ�
            cin>>name;
            if(score.find(name)!=score.end()) {     //�ҵ�name
                if(score[name]==-1) {               //ֵΪ-1����ʾ��ɾ����
                    cout<<"Not found\n";
                }
                else cout<<score[name]<<"\n";
            }
            else cout<<"Not found\n";
        }
        else if(op==3) {                            //ɾ���ɼ�
            cin>>name;
            if(score.find(name)==score.end()) {
                cout<<"Not found\n";
            }
            else {
                if(score[name]==-1) cout<<"Not found\n";//ֵΪ-1����ʾ��ɾ����
                else {
                    num--;                          //ɾ���ɹ�������--
                    score[name] = -1;
                    cout<<"Deleted successfully\n";
                }
            }
        }
        else {
            cout<<num<<"\n";
        }
    }
    return 0;
}
