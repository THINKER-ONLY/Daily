/*
3．编写程序实现下列问题的求解。
	<1> 在某系的成绩登记册中，每个班最多有40个学生，每份成绩表中的成绩信息包括：学号（9位字符），姓名（8位字符），成绩（百分制），备注（20位字符）。设计程序以处理一个班级的成绩信息，包括输入、输出、查询（给定分数以上或以下的学生信息）、按分数排序等。
	<2> 建立一个链表，存储上题所需数据，并实现相同功能。
*/
#include<stdio.h>
#include<stdlib.h>
//定义结构体
typedef struct StudentNode
{
    char id[10];
    char name[9];
    float score;
    char remarks[21];
    //我的理解是声明一个接口，用于链接下一个节点
    struct StudentNode *next;
} StudentNode;
// 声明函数
StudentNode *createList();
void printList(const StudentNode *head);
void query(StudentNode *head, float score);
void sort(StudentNode **head);
int main()
{
    StudentNode *head = NULL;
    float score;
    head = createList();
    printf("所有学生成绩：\n");
    printList(head);
    printf("请输入要查询的分数：");
    scanf("%f", &score);
    query(head, score);
    sort(&head);
    printf("按分数排序后的学生成绩：\n");
    printList(head);
    //为链表赋值为NULL，释放链表
    StudentNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
StudentNode *createList()
{
    int count;
    printf("请输入学生人数：");
    scanf("%d", &count);
    //定义链表为空
    StudentNode *head = NULL, *newNode, *tail;
    for (int i=0; i<count; i++)
    {
        //为节点在堆上分配内存
        newNode = (StudentNode *)malloc(sizeof(StudentNode));
        printf("输入第%d个学生的学号 姓名 成绩 备注：\n", i + 1);
        scanf("%s %s %f %s", newNode->id, newNode->name, &newNode->score, newNode->remarks);
        //定义链表的下一个节点为NULL
        newNode->next = NULL;
        //如果链表为空，则其既为头结点也是尾结点
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        //不为空
        else
        {
            //更新尾节点为下一个节点
            tail->next = newNode;
            tail = newNode;
        }
    }
    //返回整个列表的头节点
    return head;
}
void printList(const StudentNode *head)
{
    //定位指针指向头节点
    const StudentNode *current = head;
    while (current != NULL)
    {
        printf("学号：%s 姓名：%s 成绩：%.2f 备注：%s\n", current->id, current->name, current->score, current->remarks);
        current = current->next;
    }
}
void query(StudentNode *head, float score)
{
    int above = 0, below = 0;
    //同上个函数
    StudentNode *current = head;
    while (current != NULL)
    {
        if (current->score > score)
        {
            above++;
            printf("学号：%s 姓名：%s 成绩：%.2f 备注：%s\n", current->id, current->name, current->score, current->remarks);
        }
        else if (current->score < score)
        {
            below++;
            printf("学号：%s 姓名：%s 成绩：%.2f 备注：%s\n", current->id, current->name, current->score, current->remarks);
        }
        current = current->next;
    }
    printf("共有%d个学生成绩高于%.2f，%d个学生成绩低于%.2f。\n", above, score, below, score);
}
void sort(StudentNode **head)
{
    //定义一个用于排序的外部节点
    StudentNode *sorted = NULL;
    //定义一个二级指针，指向头节点所指向的内容
    StudentNode *current = *head;
    while (current != NULL)
    {
        //保存下一个节点的地址
        StudentNode *next = current->next;
        StudentNode **trav = &sorted;
        while (*trav != NULL && (*trav)->score <= current->score)
            //我的理解是跳过被取走的节点，直接链接下一个节点
            trav = &(*trav)->next;
        //更新节点
        current->next = *trav;
        *trav = current;
        current = next;
    }
    *head = sorted;
}