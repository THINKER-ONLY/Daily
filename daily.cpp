/*（结构）实现动态链表的增、删、改、查功能。要求链表容量无限。*/
#include <iostream>
using namespace std;
typedef struct Test {
	int id;
	int number;
	Test* next;
}Test;
void AddNode(Test*& head, int ID, int num);
void DeleteNode(Test*& head, int ID);
void ChangeNode(Test*& head, int ID, int num);
void FindNode(Test*& head, int ID);
void PrintList(Test*& head);
int main()
{
	Test* head = nullptr;
	int ID, num;
	cout << "The id you want to name this node(quit with -1): " << endl;
	while (cin >> ID && ID != -1)
	{
		cout << "The number you want to give this node: " << endl;
		cin >> num;
		cout << "Fine, go on." << endl;
		AddNode(head, ID, num);
	}
	// 打印链表
	PrintList(head);
	// 修改节点
	cout << "The id of the node you want to change: " << endl;
	cin >> ID;
	cout << "The new number you want to give this node: " << endl;
	cin >> num;
	ChangeNode(head, ID, num);
	// 打印链表
	PrintList(head);
	// 查找节点
	cout << "The id of the node you want to find: " << endl;
	cin >> ID;
	FindNode(head, ID);
	// 删除节点
	cout << "The id of the node you want to delete: " << endl;
	cin >> ID;
	DeleteNode(head, ID);
	// 打印链表
	PrintList(head);

	while (head != nullptr)
	{
		Test* temp = head;
		head = head->next;
		delete temp;
	}
	return 0;
}

void AddNode(Test*& head, int ID, int num)
{
	//为新节点分配内存
	Test* NewNode = new Test{ ID, num, nullptr };
	if (!head)
	{
		head = NewNode;
	}
	else
	{
		Test* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = NewNode;
	}
}

void DeleteNode(Test*& head, int ID)
{
	//搜索节点并删除
	if (!head) return;
	if (head->id == ID)
	{
		Test* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	//定义中间节点
	Test* temp = head;
	while (temp->next && temp->next->id != ID)
	{
		temp = temp->next;
	}
	if (temp->next)
	{
		Test* toDelete = temp->next;
		temp->next = temp->next->next;
		delete toDelete;
	}
}

void ChangeNode(Test*& head, int ID, int num)
{
	Test* CurNode = head;
	while (CurNode)
	{
		if (CurNode->id == ID)
		{
			//改变节点的值
			CurNode->number = num;
			return;
		}
		CurNode = CurNode->next;
	}
	std::cout << "Node with ID " << ID << " not found." << std::endl;
}

void FindNode(Test*& head, int ID)
{
	Test* toFind = head;
	//循环遍历链表，查找
	while (toFind)
	{
		if (toFind->id == ID)
		{
			cout << "The number of this node is: " << toFind->number << endl;
			return ;
		}
		toFind = toFind->next;
	}
	cout << "Node with ID " << ID << " not found." << endl;
}

void PrintList(Test*& head)
{
	//遍历列表并打印
	Test* temp = head;
	while (temp) 
	{
		cout << "ID: " << temp->id << ", Number: " << temp->number << endl;
		temp = temp->next;
	}
}