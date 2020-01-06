#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define MAXPROCESS 50                        //��������
#define MAXRESOURCE 100                      //�����Դ��
int AVAILABLE[MAXRESOURCE];                  //������Դ����
int MAX[MAXPROCESS][MAXRESOURCE];            //����������
int ALLOCATION[MAXPROCESS][MAXRESOURCE];     //�������
int NEED[MAXPROCESS][MAXRESOURCE];           //�������
int REQUEST[MAXPROCESS][MAXRESOURCE];        //������Ҫ��Դ��
bool FINISH[MAXPROCESS];                     //ϵͳ�Ƿ����㹻����Դ���������
int p[MAXPROCESS];                           //��¼����
int m, n;                                    //m������,n����Դ
void Init();
void Menu();
bool Safe();
void Bank();
void showdata(int, int);

int main()
{
	int input;
	Init();
	do
	{
		Menu();
		cout << "������Ҫִ�еĲ�����\n" << endl;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Safe();
			break;
		case 2:
			Bank();
			break;
		case 0:
			cout << "�˳�����" << endl;
			break;
		default:
			cout << "��������ȷѡ�\n" << endl;
			break;
		}
	} while (input);
	return 0;
}
void Menu()
{
	cout << "/***********************************/\n" << endl;
	cout << "/******     1.��ȫ�Լ��   *********/\n" << endl;
	cout << "/******     2.���м��㷨   *********/\n" << endl;
	cout << "/******     0.�˳�         *********/\n" << endl;
	cout << "/***********************************/\n" << endl;
}

void Init()                //��ʼ���㷨
{
	int i, j;
	cout << "��������̵���Ŀ:";
	cin >> m;
	cout << "��������Դ������:";
	cin >> n;
	cout << "������ÿ�������������ĸ���Դ��,����" << m << "*" << n << "��������" << endl;
	for (i = 0; i<m; i++)
	for (j = 0; j<n; j++)
		cin >> MAX[i][j];
	cout << "������ÿ�������ѷ���ĸ���Դ��,Ҳ����" << m << "*" << n << "��������" << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> ALLOCATION[i][j];
			NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
			if (NEED[i][j]<0)
			{
				cout << "������ĵ�" << i + 1 << "��������ӵ�еĵ�" << j + 1 << "����Դ������,����������:" << endl;
				j--;
				continue;
			}
		}
	}
	cout << "�����������Դ���е���Ŀ:" << endl;
	for (i = 0; i<n; i++)
	{
		cin >> AVAILABLE[i];
	}
}

void Bank()                //���м��㷨
{
	int i, cusneed, flag = 0;
	char again;
	while (1)
	{
		showdata(n, m);
		cout << endl;
	input:
		cout << "������Ҫ������Դ�Ľ��̺�(ע:��1�����̺�Ϊ0,��������)" << endl;
		cin >> cusneed;
		if (cusneed > m)
		{
			cout << "û�иý��̣�����������" << endl;
			goto input;
		}
		cout << "���������������ĸ���Դ������" << endl;
		for (i = 0; i<n; i++)
		{
			cin >> REQUEST[cusneed][i];
		}
		for (i = 0; i<n; i++)
		{
			if (REQUEST[cusneed][i]>NEED[cusneed][i])//����û�ѡ��Ľ��̵ĵ�i����Դ���������ý��̸���Դ���������
			{
				cout << "��������������������̵�������!����������!" << endl;
				goto input;
			}
			if (REQUEST[cusneed][i]>AVAILABLE[i])//����û�ѡ��Ľ��̵ĵ�i����Դ��������ϵͳ���еĵ�i����Դ������
			{
				cout << "�����������������ϵͳ�е���Դ��!����������!" << endl;
				goto input;
			}
		}
		for (i = 0; i<n; i++)//������������ô����
		{
			AVAILABLE[i] -= REQUEST[cusneed][i];//ϵͳ������Դ��ȥ�����˵�
			ALLOCATION[cusneed][i] += REQUEST[cusneed][i];//���̱��������Դ�����������˵�
			NEED[cusneed][i] -= REQUEST[cusneed][i];//���̻���Ҫ����Դ��ȥ������õ���
		}
		if (Safe())//AVAILABLE  ALLOCATION  NEED�䶯֮���Ƿ�ᵼ�²���ȫ
		{
			cout << "ͬ���������!" << endl;
		}
		else//����ȫ��ԭ
		{
			cout << "�������󱻾ܾ�!" << endl;
			for (i = 0; i<n; i++)
			{
				AVAILABLE[i] += REQUEST[cusneed][i];
				ALLOCATION[cusneed][i] -= REQUEST[cusneed][i];
				NEED[cusneed][i] += REQUEST[cusneed][i];
			}
		}
		for (i = 0; i<n; i++)
		{
			if (NEED[cusneed][i] == 0)//����=����
			{
				flag++;
			}
		}

		if (flag == n)//����ý��̸���Դ�����������������ͷ���Դ
		{
			for (i = 0; i<n; i++)
			{
				AVAILABLE[i] += ALLOCATION[cusneed][i];
				ALLOCATION[cusneed][i] = 0;
				NEED[cusneed][i] = 0;
			}
			cout << "����" << cusneed << " ռ�е���Դ���ͷţ�" << endl;
			flag = 0;
		}
		for (i = 0; i<m; i++)//��������Ժ󽫽��̵ı�ʶFINISH�ĳ�false
		{
			FINISH[i] = false;
		}
		showdata(n, m);
		cout << "�������ٴ����������?���밴y/Y,���밴������" << endl;
		cin >> again;
		if (again == 'y' || again == 'Y')
		{
			continue;
		}
		break;
	}
}

bool Safe() //��ȫ���㷨
{
	int i, j, k, l = 0;
	int Work[MAXRESOURCE]; //��������
	for (i = 0; i < n; i++)
		Work[i] = AVAILABLE[i];
	for (i = 0; i < m; i++)
	{
		FINISH[i] = false;//FINISH��¼ÿ�������Ƿ�ȫ
	}
	while (l<m)//�����Ļ�����ִ��m��
	{
		int init_index = l;//��¼��ǰ��ȫ���д�С
		for (i = 0; i < m; i++)
		{
			if (FINISH[i] == true)//�жϵ�ǰ�����Ƿ�ִ��
			{
				continue;
			}
			for (j = 0; j < n; j++)//ѭ�����ҵ�i��������Ҫ�ĸ�����Դ�� �Ƿ񳬹�ϵͳ���еĶ�Ӧ��Դ��
			{
				if (NEED[i][j] > Work[j])//��i����Դ��Ҫ�ĵ�j����Դ��>ϵͳ���еĵ�j����Դ��
				{
					break;
				}
			}
			if (j == n)//�����i����������ĸ�����Դ����û�г���ϵͳ���еĶ�Ӧ��Դ��  
			{
				FINISH[i] = true;//���ý��̵�FINISH���Ϊtrue  
				for (k = 0; k < n; k++)
				{
					Work[k] += ALLOCATION[i][k];/*��Work��ֵΪ��i�����̸����ѷ�����
												Դ����ϵͳ���еĶ�Ӧ��Դ��(��Ϊ���Ľ���ȫ����Դ��������ʱ���̽���������Դ������ϵͳ) */
				}
				p[l++] = i;//��¼���̺�	
			}
			else//�����������ѭ����һ������
			{
				continue;
			}
		}
		if (l == init_index)//�Ƚϰ�ȫ�����Ƿ����仯
		{
			cout << "ϵͳ�ǲ���ȫ��" << endl;
			return false;
		}
	}//forѭ��
	cout << "ϵͳ�ǰ�ȫ��" << endl;
	cout << "��ȫ����:" << endl;
	for (i = 0; i < l; i++)
	{
		cout << p[i];
		if (i != l - 1)
		{
			cout << "-->";
		}
	}
	cout << "" << endl;
	return true;
}

void showdata(int n, int m)   //��ʾ
{
	int i, j;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "ϵͳ���õ���Դ��Ϊ:    ";
	for (j = 0; j<n; j++)
		cout << "    " << AVAILABLE[j];
	cout << endl;
	cout << "�����̻���Ҫ����Դ��:" << endl;
	for (i = 0; i<m; i++)
	{
		cout << "    ����" << i << ":";

		for (j = 0; j<n; j++)
			cout << "     " << NEED[i][j];
		cout << endl;
	}
	cout << endl;
	cout << "�������Ѿ��õ�����Դ��:    " << endl << endl;
	for (i = 0; i<m; i++)
	{
		cout << "    ����" << i << ":";
		for (j = 0; j<n; j++)
			cout << "     " << ALLOCATION[i][j];
		cout << endl;
	}
	cout << endl;
}
