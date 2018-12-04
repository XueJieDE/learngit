#ifndef ANG
#define AND
#include "标头.h"
#include<process.h>
string str(10, ' ');
void table(graph &a) {
	system("cls");
	cout <<str<< "1、添加节点" << endl;
	cout <<str<< "2、删除节点" << endl;
	cout <<str<< "3、添加边" << endl;
	cout <<str<< "4、删除边" << endl;
	cout <<str<< "5、退出" << endl;
	int choice = 0;
	cin >> choice;
	while (!(choice > 0 && choice < 5)) {
		cout << "错误输入" << endl;
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
	cout << "输入节点编号" << endl;
	int point = 0;
	cin >> point;
	a.dijkstra(point);//找到最短路径
	cout <<str<< "节点编号  权值  下一跳编号" << endl;
	for (int i = 0; i < a.vexnum; i++) {
		if (a.dis[i].value < INT_MAX&&i != point-1)cout <<str<< i+1 <<"           "<< a.dis[i].value <<"           "<< a.dis[i].next+1 << endl;
	}
	char q;
	cout << "输入任意字符以退出" << endl;
	cin>>q;
	return;
}
void menu(graph &a) {
	while (1) {
		system("cls");
		cout <<str<< "   课程报告" << endl;
		cout <<str<< "1、查看路由表" << endl;
		cout <<str<< "2、修改" << endl;
		cout <<str<< "3、退出" << endl;
		int choice = 0;
		cin >> choice;
		while (!(choice > 0 && choice < 5)) {
			cout << "错误输入" << endl;
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