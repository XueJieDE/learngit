#ifndef ANG
#define AND
#include "��ͷ.h"
#include<process.h>
string str(10, ' ');
void table(graph &a) {
	system("cls");
	cout <<str<< "1����ӽڵ�" << endl;
	cout <<str<< "2��ɾ���ڵ�" << endl;
	cout <<str<< "3����ӱ�" << endl;
	cout <<str<< "4��ɾ����" << endl;
	cout <<str<< "5���˳�" << endl;
	int choice = 0;
	cin >> choice;
	while (!(choice > 0 && choice < 5)) {
		cout << "��������" << endl;
		cin >> choice;
	}
	switch (choice) {
	case 1:a.add_point(); break;
	case 2:a.delete_point(); break;
	case 3:a.add_line(); break;
	case 4:a.delete_line(); break;
	case 5:return; break;
	}
}
void show(graph &a) {
	system("cls");
	cout << "����ڵ���" << endl;
	int point = 0;
	cin >> point;
	a.dijkstra(point);//�ҵ����·��
	cout <<str<< "�ڵ���  Ȩֵ  ��һ�����" << endl;
	for (int i = 0; i < a.vexnum; i++) {
		if (a.dis[i].value < INT_MAX&&i != point-1)cout <<str<< i+1 <<"           "<< a.dis[i].value <<"           "<< a.dis[i].next+1 << endl;
	}
	char q;
	cout << "���������ַ����˳�" << endl;
	cin>>q;
	return;
}
void menu(graph &a) {
	while (1) {
		system("cls");
		cout <<str<< "   �γ̱���" << endl;
		cout <<str<< "1���鿴·�ɱ�" << endl;
		cout <<str<< "2���޸�" << endl;
		cout <<str<< "3���˳�" << endl;
		int choice = 0;
		cin >> choice;
		while (!(choice > 0 && choice < 5)) {
			cout << "��������" << endl;
			cin >> choice;
		}
		switch (choice) {
		case 1:show(a); break;
		case 2:table(a); break;
		case 3:return; break;
		}
	}
}
#endif