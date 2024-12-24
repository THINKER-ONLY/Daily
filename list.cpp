#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
//声明结构体
typedef struct Student {
	char name[50];
	char ID[50];
	char subject[50];
	char dormitoryID[50];
} Student;
//声明函数
void write(Student students[5]);
void take(Student students[5]);
void print(Student students[5]);
int out(Student students[5]);
int show();
int main()
{
	//声明结构体数组
	Student students[5];
	cout << "Please input student`s information:" << endl;
	write(students);
	cout << "Fine, I will sort it." << endl;
	take(students);
	cout << "Finshed the work.Here is the result." << endl;
	print(students);
	cout << "Output the informations." << endl;
	out(students);
	cout << "Here is the result." << endl;
	show();
	cout << "It is fine to show you this." << endl;
	return 0;
}
void write(Student students[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "NAME      ID      SUBJECT      DORMITORY" << endl;
		cin >> students[i].name >> students[i].ID >> students[i].subject >> students[i].dormitoryID;
	}
}
void take(Student students[5])
{
	//使用sort函数，或者使用正常的排序算法也可以
	sort(students, students + 5, [](const Student& a, const Student& b) {
		return strcmp(a.ID, b.ID) < 0;
		});
}
void print(Student students[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Name:" << students[i].name<< "\t" << "ID:" << students[i].ID << "\t" << "Subject:" << students[i].subject << "\t" << "Dormitory:" << students[i].dormitoryID << endl;
	}
}
int out(Student students[5])
{
	//打开文件
	ofstream outfile("D:/student.dat");
	//错误处理
	if (!outfile.is_open())
	{
		cerr << "Failed to open this file." << endl;
		return 1;
	}
	outfile << "NAME\t\t\tID\t\t\tSUBJECT\t\t\tDORMITORY" << endl;
	for (int i = 0; i < 5; i++)
	{
		outfile << students[i].name << "\t\t\t" << students[i].ID << "\t\t\t" << students[i].subject << "\t\t\t" << students[i].dormitoryID << endl;
	}
	//关闭文件
	outfile.close();
	return 0;
}
int show()
{
	//打开文件
	ifstream infile("D:/student.dat");
	//错误处理
	if (!infile.is_open())
	{
		cerr << "Failed to open this file." << endl;
		return 1;
	}
	//读取每一行
	std::string line;
	while (getline(infile, line))
		cout << line << endl;
	//关闭文件
	infile.close();
	return 0;
}