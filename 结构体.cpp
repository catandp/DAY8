//�ṹ��Ķ�����ʹ��
//�ṹ�嶨��ķ���
//1.struct �ṹ���� ������
//2.struct �ṹ���� ������=����Ա1ֵ����Ա2ֵ...)
//3.����ṹ��ʱ˳�򴴽�����
/*************************************************
#include<iostream>
using namespace std;
#include<string>
//1.����ѧ���������ͣ�ѧ�����������������䣬�ɼ���
struct Student
{
	string name;
	int age;
	float score;
}s3;

int main()
{
	//2.ͨ�����ʹ��������ѧ��
	struct Student s1;
	s1.name = "����";
	s1.age = 23;
	s1.score = 99.8;
	cout << "������" << s1.name << "���䣺" << s1.age << "�ɼ���" << s1.score << endl;
	struct Student s2 = { "����",19,98 };
	cout << "������" << s2.name << "���䣺" << s2.age << "�ɼ���" << s2.score << endl;
	s3.name = "����";
	s3.age = 20;
	s3.score = 88;
	cout << "������" << s3.name << "���䣺" << s3.age << "�ɼ���" << s3.score << endl;
	system("pause");
	return 0;
}
*******************************************/
//�ṹ������
/*****************************************
#include<iostream>
#include<string>
using namespace std;
//����ṹ��
struct Student
{
	string name;
	int age;
	float score;
};
int main()
{
	//�����ṹ������
	struct Student arr[3] = { {"����",18,88},{"����",19,90},{"����",20,99} };
	//���ʽṹ�������е�Ԫ��
	arr[2].name = "����";
	arr[2].age = 22;
	arr[2].score = 100;
	//�����ṹ�������е�Ԫ��
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << arr[i].name << "���䣺" << arr[i].age << "�ɼ���" << arr[i].score << endl;
	}

	system("pause");
	return 0;
}
*************************************************/
//�ṹ��ָ��
//->
/***************************
#include<iostream>
using namespace std;
#include<string>
//����ṹ��
struct Student
{
	string name;
	int age;
	float score;
};
int main()
{
	//�����ṹ�����
	struct Student s = { "����",19,99 };
	//����ָ��ָ��ṹ�����
	struct Student* p = &s;
	//ָ������ṹ�����
	//ͨ���������ʽṹ���е������á�.����ͨ���ṹ��ָ����ʽṹ�������á�->��
	cout << p->name << endl;
	cout << p->age << endl;
	cout << p->score << endl;

	system("pause");
	return 0;
}
********************************************/
//�ṹ��Ƕ�׽ṹ��
/********************************************
#include<iostream>
using namespace std;
#include<string>
//����ѧ���ṹ��
struct Student
{
	string name;
	int age;
	float score;
};
//������ʦ�Ľṹ��
struct Teacher
{
	int id;
	string name;
	int age;
	struct Student s1;
};
int main()
{
	//������ʦ
	struct Teacher t = { 10000,"����",56 };
	t.s1.age = 20;
	t.s1.name = "С��";
	t.s1.score = 80;
	cout << "��ʦ������" << t.name << "��ʦid:" << t.id
		<< "��ʦ���䣺" << t.age << "��ʦ�̵�" << t.s1.name
		<< "����" << t.s1.score << "�ĺóɼ�" << endl;
	system("pause");
	return 0;
}
****************************************/
//�ṹ����Ϊ�����Ĳ���
/************************************
#include<iostream>
using namespace std;
#include<string>
struct Student
{
	string name;
	int age;
	float score;
};
//ֵ����
void printfStudent(struct Student s1)
{
	s1.age = 100;
	cout << "1.������" << s1.name << "���䣺" << s1.age << "�ɼ���" << s1.score << endl;
}
//��ַ���ݣ���ʡ�ռ�
void print(const struct Student* p)
{
	//p->age = 55;//����const�������Ƿ�ֹ��������������ֵ
	cout << "2.������" << p->name << "���䣺" << p->age << "�ɼ���" << p->score << endl;
}
int main()
{
	//�����ṹ�����
	struct Student s1 = { "����",18,99 };
	cout << "0.������" << s1.name << "���䣺" << s1.age << "�ɼ���" << s1.score << endl;
	printfStudent(s1);
	struct Student s2 = { "����",18,99 };
	print(&s2);
	cout << "0.������" << s2.name << "���䣺" << s2.age << "�ɼ���" << s2.score << endl;

	system("pause");
	return 0;
}
*************************************/
//�ṹ�尸��1
/********************************************************
//������ʦ����5��ѧ��������
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
//������ʦ�Ľṹ��
struct student
{
	//ѧ��������
	string name;
	//ѧ���ķ���
	float score;
};
//������ʦ�Ľṹ��
struct teacher
{
	//��ʦ������
	string name;
	//����ѧ��������
	struct student arr[5];
};
//����ʦ��ֵ
void fuZi(struct teacher arr1[], int len)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		arr1[i].name = nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			arr1[i].arr[j].name = nameseed[j];

			int rad = rand() % 60 + 40;
			arr1[i].arr[j].score = rad;
		}
	}
}
void printfInfo(struct teacher arr1[], int len)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "��ʦ������" << arr1[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tѧ��������" << arr1[i].arr[j].name << endl;
			cout << "\t�÷֣�" << arr1[i].arr[j].score << endl;
		}
	}
}
int main()
{
	//���������
	srand((unsigned int)time(NULL));
//������ʦ����
	struct teacher arr1[3];
	//struct student arr2[5];
	int len = sizeof(arr1) / sizeof(arr1[0]);
	fuZi(arr1, len);
	//��ӡ��Ϣ
	printfInfo(arr1, len);
	system("pause");
	return 0;
}
***************************************/
//�ṹ�尸��2
//������˸���������������
#include<iostream>
using namespace std;
#include<string>
//����Ӣ�۵Ľṹ��
struct hero
{
	//����
	string name;
	//����
	int age;
	//�Ա�
	string sex;
};
//�����㷢
void bubblesort(struct hero arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j].age > arr[j + 1].age)
			{
				struct hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//��ӡ����
void printInfo(struct hero arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "������" << arr[i].name << "���䣺" << arr[i].age << "�Ա�" << arr[i].sex << endl;
	}
}
int main()
{
	//����������5��Ӣ��
	struct hero arr[5] = { {"����",23,"��"},{"����",22,"��"},{"�ŷ�",28,"��"},{"����",20,"��"},{"����",19,"Ů"} };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*for (int i = 0; i < len; i++)
	{
		cout <<"������"<< arr[i].name <<"���䣺"<<arr[i].age<<"�Ա�"<<arr[i].sex<<endl;
	}*/
	//����
	bubblesort(arr, len);
	//��ӡ
	printInfo(arr, len);
	system("pause");
	return 0;
}