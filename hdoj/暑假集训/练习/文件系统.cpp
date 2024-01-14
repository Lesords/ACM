#include<iostream>
#include<string>
using namespace std;
struct fil {
	string name;
	fil * next;//ͬ���ļ� 
};
struct dir {
	string name;
	dir * next;//ͬ���ļ���
	dir * up;//��һ���ļ��� 
	dir * dirhead;//���ļ��� 
	fil * filhead;//���ļ� 
};
dir *head,*nowhead;
dir *searchdir(string name) {
	dir *tmp=nowhead->dirhead->next;
	while(tmp) {
		if(tmp->name==name) return tmp;
		tmp=tmp->next;
	}
	return NULL;
}
fil *searchfil(string name) {
	fil *tmp=nowhead->filhead->next;
	while(tmp) {
		if(tmp->name==name) return tmp;
		tmp=tmp->next;
	}
	return NULL;
}
void init() {//��ʼ��
	head=new dir;//new ����Ҫͷ�ļ� 
	head->dirhead=new dir;
	head->filhead=new fil;
	head->next=NULL;
	head->up=head;
	nowhead=head;
	nowhead->dirhead->next=NULL;
	nowhead->filhead->next=NULL; 
} 
int main() {
	string op,name;
	init();
	while(cin>>op>>name) {
		if(op=="CD") {//����Ŀ¼λ�� 
			if(name=="..") {
				nowhead=nowhead->up;
				cout<<"success"<<endl;
			}
			else if(name=="\\") {
				nowhead=head;
				cout<<"success"<<endl;
			}
			else {
				dir *p=searchdir(name);
				if(!p) {
					cout<<"no such directory"<<endl;
				}
				else {
					nowhead=p;
					cout<<"success"<<endl;
				}
			}
		}
		else if(op=="MD"){//�������ļ��� 
			if(name==".."||name=="\\") {
				cout<<"directory already exist"<<endl;
			}
			else {
				dir *p;
				p=searchdir(name);
				if(!p) {
					dir *q=new dir;
					q->name=name;
					q->filhead=new fil;
					q->dirhead=new dir;
					q->filhead->next=NULL;
					q->dirhead->next=NULL;
					q->up=nowhead;
					q->next=nowhead->dirhead->next;//��next�м�������ļ��� 
					nowhead->dirhead->next=q;
					cout<<"success"<<endl;
				}
				else cout<<"directory already exist"<<endl;
			}
		}
		else if(op=="RD") {//ɾ�����ļ��� 
			dir *p=searchdir(name);
			if(!p||p->dirhead->next) {
				cout<<"can not delete the directory"<<endl;
			} 
			else {
				dir *q=nowhead->dirhead;//dirheadΪ���ļ��� 
				while(q) {
					if(q->next==p) {//q->nextΪͬ�����ļ��� 
						q->next=p->next;
						delete p;//delete����Ҫͷ�ļ� 
						cout<<"success"<<endl;
						break;
					}
					q=q->next;
				}
			}
		}
		else if(op=="CREATE") {//�����ļ� 
			fil *p=searchfil(name);
			if(!p) {
				p=new fil;//���������ڴ� 
				p->name=name;
				p->next=nowhead->filhead->next;//next�м�����ļ� 
				nowhead->filhead->next=p;
				cout<<"success"<<endl;
			}
			else cout<<"file already exist"<<endl;
		}
		else if(op=="DELETE") {//ɾ���ļ� 
			fil *p=searchfil(name);
			if(!p) {
				cout<<"no such file"<<endl;
			}
			else {
				fil *q;
				q=nowhead->filhead;
				while(q) {
					if(q->next==p) {
						q->next=p->next;//p->nextΪ��ɾ�����ļ����ָ�� 
						delete p;
						break;
					}
					q=q->next;
				}
				cout<<"success"<<endl;
			}
		}
	}
	return 0;
} 
