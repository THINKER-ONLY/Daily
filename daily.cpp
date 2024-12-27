/*���ṹ��ʵ�ֶ�̬���������ɾ���ġ��鹦�ܡ�Ҫ�������������ޡ�*/
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
	// ��ӡ����
	PrintList(head);
	// �޸Ľڵ�
	cout << "The id of the node you want to change: " << endl;
	cin >> ID;
	cout << "The new number you want to give this node: " << endl;
	cin >> num;
	ChangeNode(head, ID, num);
	// ��ӡ����
	PrintList(head);
	// ���ҽڵ�
	cout << "The id of the node you want to find: " << endl;
	cin >> ID;
	FindNode(head, ID);
	// ɾ���ڵ�
	cout << "The id of the node you want to delete: " << endl;
	cin >> ID;
	DeleteNode(head, ID);
	// ��ӡ����
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
	//Ϊ�½ڵ�����ڴ�
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
	//�����ڵ㲢ɾ��
	if (!head) return;
	if (head->id == ID)
	{
		Test* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	//�����м�ڵ�
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
			//�ı�ڵ��ֵ
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
	//ѭ��������������
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
	//�����б���ӡ
	Test* temp = head;
	while (temp) 
	{
		cout << "ID: " << temp->id << ", Number: " << temp->number << endl;
		temp = temp->next;
	}
}