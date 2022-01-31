#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define USERNAME 100
#define STUDENT_NUMBER 100
#define MAJOR 100
#define MATH 100
#define INTRODUCTION_TO_COMPUTER 100
char Username[USERNAME][20] = {};
char major[MAJOR][20] = {};
long long int student[STUDENT_NUMBER] = {};
int math[MATH] = {};
int introduction[INTRODUCTION_TO_COMPUTER] = {};
int num;
void menu();//ϵͳ����
void lookuser(int num);//�鿴�û�
void exportuser(int c);//�����û�
void adduser(int temp);//ѧ����Ϣ�Ķ�����
void deleteuser(int b);//ɾ���û�
void modifyuser(int c);//�޸��û���Ϣ
void lookupuser(int a);//�����û���Ϣ
int inexport();//������Ϣ
void studentdate();
void menu()
{
	printf("-------------------ѧ������ϵͳ------------------\n");
	printf("                1.ѧ����Ϣ������\n");
	printf("                2.ѧ����Ϣ�ĵ��롣\n");
	printf("                3.ѧ����Ϣ�Ĳ鿴��\n");
	printf("                4.ѧ����Ϣ��ɾ����\n");
	printf("                5.ѧ����Ϣ���޸ġ�\n");
	printf("                6.ѧ����Ϣ�Ĳ��ҡ�\n");
	printf("                7.�˳������밴'q'��\n");
	printf("-------------------------------------------------\n");
}
void studentdate()
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\source\\repos\\ѧ������ϵͳ\\ѧ������ϵͳ\\�ı�.txt", "r")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, -1L, SEEK_END);
	fscanf(fp, "%d", &num);
	rewind(fp);
	for(i=0;i<num;i++)
	{
		fscanf(fp, "%s %s %lld %d %d", &Username[i], &major[i], &student[i], &math[i], &introduction[i]);
		if (student[i] == num)
		{
			break;
		}
	}
	num = i;
	fclose(fp);
}
int inexport()
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\source\\repos\\ѧ������ϵͳ\\ѧ������ϵͳ\\�ı�.txt", "w+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<num;i++)
	{
		fprintf(fp, "%s %s %lld %d %d \n", Username[i], major[i], student[i], math[i], introduction[i]);
	}
	fprintf(fp, "%d", num);
	fclose(fp);
}
void lookuser( int num)
{
	int a_username, b_major,d_math,e_introduction;
	long long int  c_studentnumber;
	printf(" ����\t\t\tרҵ\t\t\tѧ��\t\t\t��ѧ\t\t\t�Ƶ�\n");
	for (a_username = 0, b_major = 0, c_studentnumber = 0, d_math=0, e_introduction=0; a_username < num; a_username++, b_major++, c_studentnumber++, d_math++,e_introduction++)
	{
		printf("%d:", a_username+1);
		printf("%-4s%28s\t\t%lld\t\t%d\t\t\t%d\n", Username[a_username], major[b_major], student[c_studentnumber], math[d_math], introduction[e_introduction]);
	}
	printf("ѧ�������ܼ�Ϊ:%d��\n", num);
}
void exportuser(int c)
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\Desktop\\ѧ����Ϣ", "w+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(fp, " ����\t\tרҵ\t\t\tѧ��\t\t\t��ѧ\t\t\t�Ƶ�\n");
	for(i = 0; i < num; i++)
	{
		fprintf(fp,"%d:", i + 1);
		fprintf(fp,"%-4s%28s\t\t%lld\t\t%d\t\t\t%d\n", Username[i], major[i], student[i], math[i], introduction[i]);
	}
	fprintf(fp, "�ܼ�����Ϊ��%d", c);
	fclose(fp);
}
void adduser(int temp)
{
	int ch=1;
	printf("��������Ҫ¼��ѧ������Ϣ��\n");
	while(ch)
	{
		printf("%d.", temp+1);
		printf("��������ѧ����������\n");
		scanf("%s", &Username[temp]);
		printf("���������רҵ��\n");
		scanf("%s", &major[temp]);
		printf("���������ѧ�ţ�\n");
		scanf("%lld", &student[temp]);
		printf("�����������ѧ�ɼ���\n");
		scanf("%d", &math[temp]);
		printf("��������ļ�������۳ɼ���\n");
		scanf("%d", &introduction[temp]);
		temp += 1;
		printf("��0�Ž���¼�루�������������¼�룩:\n");
		if (scanf("%d", &ch) == 0)
		{
			break;
		}
	}
	printf("¼��ɹ�������\n");
	num = temp;
}
void deleteuser(int b)
{
	
	long long int studentnumber;
	int i;
	printf("����������ɾ����ѧ����ѧ��:");
	scanf("%lld", &studentnumber);
	for (i = 0; i <b; i++)
	{
		if (student[i] == studentnumber)
		{
			break;
		}
	}
	while (i <=num)
	{
		strcpy(Username[i], Username[i + 1]);
		strcpy(major[i], major[i + 1]);
		student[i] = student[i + 1];
		math[i] = math[i + 1];
		introduction[i] = introduction[i + 1];
		i += 1;
	}
	num = b - 1;
	printf("ɾ���ɹ�������\n");
	exportuser(num);
}
void modifyuser(int c)
{
	long long int studentnumber;
	int i, a, k;
	k = 0;
	printf("��������Ҫ�޸��˵�ѧ�ţ�");
	scanf("%lld", &studentnumber);
	for (i = 0; i < c; i++)
	{
		if (student[i] == studentnumber)
		{
			printf(" ����\t\t\tרҵ\t\t\tѧ��\t\t\t��ѧ\t\t\t�Ƶ�\n");
			printf("%d:", i + 1);
			printf("%s%30s\t\t%lld\t\t%d\t\t\t%d\n", Username[i], major[i], student[i], math[i], introduction[i]);
			k = 1;
		}
	}
	if (k != 1)
	{
		printf("ϵͳ��û�и�ѧ�ţ�����\n");
	}
	printf("-------------------------------------\n");
	printf("               1.��ѧ\n");
	printf("               2.�Ƶ�\n");
	printf("             3.����ȫ��\n");
	printf("-------------------------------------\n");
	printf("��ѡ����Ҫ�޸ĵ�ѡ�\n");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("���������޸ĺ����ѧ�ɼ���\n");
		scanf("%d", &math[i]);
		break;
		
	case 2:
		printf("���������޸ĺ�ļ�������۳ɼ���\n");
		scanf("%d", &introduction[i]);
		break;
	case 3:
		printf("���������޸ĺ����ѧ�ɼ��ͼ�������۳ɼ���\n");
		scanf("%d %d", &math[i],&introduction[i]);
		break;
	default:
		break;
	}
	printf("�޸ĳɹ�������\n");
	
}
void lookupuser(int a)
{
	long long int studentnumber;
	int i,k;
	k = 0;
	printf("��������Ҫ�����˵�ѧ�ţ�");
	scanf("%lld", &studentnumber);
	for (i = 0; i < a; i++)
	{
		if (student[i] == studentnumber)
		{
			printf("��ѯ�ɹ�������\n");
			printf(" ����\t\t\tרҵ\t\t\tѧ��\t\t\t��ѧ\t\t\t�Ƶ�\n");
			printf("%d:", i + 1);
			printf("%s%30s\t\t%lld\t\t%d\t\t\t%d\n", Username[i], major[i], student[i], math[i], introduction[i]);
			k = 1;
		}
	}
	if (k != 1)
	{
		printf("ϵͳ��û�и�ѧ�ţ�����\n");
	}
	
}
int main()
{
	int number;
	num = 0;
	menu();
	studentdate();
	printf("��ѡ��һ��\n");
	while (scanf("%d", &number))
	{
		switch (number)
		{
		case 1:
			printf("---------------------��Ϣ����--------------------\n");
			adduser(num);//ѧ����Ϣ�Ķ�����
			menu();
			printf("��ѡ��һ��\n");
			break;
		case 2:
			printf("---------------------��Ϣ����--------------------\n");
		    inexport();//������Ϣ
			printf("��Ϣ����ɹ�! ! ! \n");
			menu();
			printf("��ѡ��һ��\n");
			break;
		case 3:
			printf("---------------------�鿴��Ϣ--------------------\n");
			lookuser(num);//�����û�
			menu();
			printf("��ѡ��һ��\n");
			break;
		case 4:
			printf("---------------------��Ϣɾ��--------------------\n");
			deleteuser(num);//ɾ���û�
			menu();
			printf("��ѡ��һ��\n");
			break;
		case 5:
			printf("---------------------��Ϣ�޸�--------------------\n");
			modifyuser(num);//�޸��û���Ϣ
			menu();
			printf("��ѡ��һ��\n");
			break;
		case 6:
			printf("---------------------��Ϣ����--------------------\n");
			lookupuser(num);//�����û���Ϣ
			menu();
			printf("��ѡ��һ��\n");
		case 7:
			break;
		}
	} 
	exportuser(num);
	inexport();
	return 0;
}