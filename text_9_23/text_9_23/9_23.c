#include<stdio.h>

#pragma warning(disable :4996)

//1. ������A�е����ݺ�����B�е����ݽ��н�����������һ����
int main()
{
	int arr_1[3] = { 1, 2, 3 };
	int arr_2[3] = { 4, 5, 6 };
	int arr[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		arr[i] = arr_1[i];
		arr_1[i] = arr_2[i];
		arr_2[i] = arr[i];
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", arr_1[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", arr_2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//2.����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
int main()
{
	int i;
	double sum;
	double sum_1= 0;
	double sum_2 = 0;
	for ( i = 1; i < 101; i+=2)
	{
		sum_1 = sum_1 + 1.0/i;
	}
	for ( i = 2; i < 101; i+=2)
	{
		sum_2 = sum_2 + 1.0 / i;	//���i�����ͣ�1.0����i��ת��Ϊ�����
	}                               //����Ǹ��㣬1����i������ͳ��������Ϊ���͡�
	sum = sum_1 - sum_2;            //����i����2��1.0 / i����0.5��1 / i����0
	printf("%f\n", sum);
	system("pause");
	return 0;
}

//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
int main()
{   
	int k = 0;
	int j = 20;
	for (int i = 1; i < 101; i++)
	{   
		if (i < 20)
		{
			if (i % 10 == 9)
			{
				k++;
			}
			
		}
		if (i>=20)
		{
			if (i%j == 9)
			{
				k++;
				j = j + 10;
			}
		}
	}
	printf("%d\n", k);
	system("pause");
	return 0;
}