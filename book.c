#pragma once
#include <stdio.h>
#include <stdlib.h>


//�����鱾Book�Ľṹ��
typedef struct Node {
	int id;				//���
	char name[50];		//����
	char author[20];	//����
	int inventory;		//�����
	float price;		//�۸�
	struct Node* next;	//ָ����
} Book;	//�ṹ�嶨��ΪBook

//ѡ����
void choose();
//��ӡ�˵�
void printMainMenu();
//��������ģ��
Book *create(Book *);
//ɾ���ڵ�ģ��
void del(Book*);
//����ڵ�ģ�飨�ɶ�����룩
void insert(Book*);
//�޸Ľڵ�ģ��
void mod(Book *);
//���������
void printBook(Book *);
//��ӡ�����˵�
void printSearchnMenu();
//�������߲�ѯ
void searchByAuthor(Book*);
//���ݱ�Ų���ͼ����Ϣ
void searchById(Book*);
//������������ͼ����Ϣ
void searchByName(Book*);
//������ݱ������ð������
void sortById(Book*);

int main() {
	//ѡ����
	choose();

	return 0;
}

//ѡ����
void choose() {
	Book* head = NULL;
	int flag;	//�������˵�����
	int i = 1;		//����ѭ��,��-1��ֹ

	while (i > 0) {
		printMainMenu();	//��ӡ�˵�
		scanf_s("%d", &flag);//ѡ����

		switch (flag) { //���������ֶ�Ӧ�˵����֣�ͨ��nȷ����������
		case 1://����
			head = create(head);
			sortById(head);	//����
			break;
		case 2://����
			insert(head);
			break;
		case 3://ɾ��
			del(head);
			break;
		case 4://�޸�
			mod(head);
			break;
		case 5://����
			printSearchMenu();	//��ӡ��ѯ�˵�
			int flagSerch = 0;	//���Ʋ�ѯ�˵�����
			scanf_s("%d", &flagSerch);
			switch (flagSerch) {
			case 1:	//��ѯ����ͼ����Ϣ
				printBook(head);
				break;
			case 2:	//���ݱ�Ų�ѯ
				searchById(head);
				break;
			case 3:	//����������ѯ
				searchByName(head);
				break;
			case 4:	//�������߲�ѯ
				searchByAuthor(head);
				break;
			defalt:	//�������˵�
				break;
			}
			break;
		default:
			i = -1;	//����ѭ�����˳�����ϵͳ
			printf("\n�ɹ��˳�����ϵͳ��\n\n");
			printf("�������ַ��رմ���");
			getch();
			break;
		}	
	}
}

//��ӡ�˵�
void printMainMenu() {
	system("cls");		// ����
	system("color 71");	//��������ͱ�����ɫ
	putchar('\n');
	printf("\t\tͼ����Ϣ����ϵͳ\t\n");	
	printf("\t ============================\n");
	printf("\t ��\t���ߣ�author       ��\n");
	printf("\t ��\tѧ�ţ�number       ��\n");
	printf("\t ============================\n");
	printf("\t ��\t1.ͼ��������     ��\n");
	printf("\t ��\t2.ͼ����Ϣ����     ��\n");
	printf("\t ��\t3.ͼ����Ϣɾ��     ��\n");
	printf("\t ��\t4.ͼ����Ϣ�޸�     ��\n");
	printf("\t ��\t5.ͼ����Ϣ��ѯ     ��\n");
	printf("\t ��\t6.�˳�����ϵͳ     ��\n");
	printf("\t ============================\n");
	printf("\t��ѡ����ģ��(1��6,�������ַ��˳�):");

}

//��������ģ��
Book* create(Book *head) {
	system("cls");			//�����Ļ
	if (!head) {	//���������������������
		Book* p, * q;	//����ָ��
		head = (Book*)malloc(sizeof(Book));	//��ͷ�ڵ㿪�ٿռ�
		head->next = NULL;	//�ÿ�ͷ�ڵ��ָ����
		q = head;			//qָ���¼ͷ�ڵ�ĵ�ַ
		p = head->next;	//pָ���¼ͷ�ڵ��ָ����ĵ�ַ

		printf("�������鱾����Ϣ,��-1��������ʽ����� ���� ���� ����� �۸�\n");
		int id;	//����ı��
		scanf_s("%d", &id);

		while (id != -1) {
			p = (Book*)malloc(sizeof(Book));	//pָ�뿪�ٿռ�
			//�������Ա
			p->id = id;
			scanf("%s %s %d %f", p->name, p->author, &p->inventory, &p->price);
			p->next = NULL;	//�ÿ�p�ڵ��ָ����
			q->next = p;	//p��q�ڵ�����
			q = p;			//qָ�����
			printf("�������鱾����Ϣ����-1��������ʽ����� ���� ���� ����� �۸�\n");
			scanf_s("%d", &id);
		}
	}
	else {	//��������������ش�����Ϣ
		printf("�Ѵ���ͼ�����������ظ�����!\n");
		//ʹҳ��ͣ���ڵ�ǰҳ
		printf("�������������......");
		getch();
	}

	return head;	//�����������ʼλ��
}

//ɾ���ڵ�ģ��
void del(Book* head) {
	system("cls");
	//�������Ϊ�գ���ʼɾ��
	if (head) {
		Book* p, * q;//����ָ��
		int id;//���������Ų���ɾ��
		p = head;//p��¼ͷ�ڵ�ĵ�ַ
		q = head->next;//q��¼ͷ�ڵ��ָ����ĵ�ַ
		printf("������Ҫɾ����ͼ���ţ�");
		//������
		scanf_s("%d", &id);
		while (q != NULL) { //q��Ϊ��ʱִ��ѭ��
			if (q->id == id)//�ж��Ƿ��ҵ�����ı��
				//Ϊ��ʱ
			{
				p->next = q->next;//�Ͽ�q�ڵ�
				free(q);//�ͷ�q�ڵ�neicun
				q = NULL; //�ÿ�qָ���ֹ����Ұָ��
			}
			else {
				//�ж�Ϊ��ʱ
				p = p->next;//pָ�����
				q = q->next;//qָ�����
			}
		}
		//�����ҵ����һ���ڵ㻹δ�鵽Ҫɾ���ı��ʱ�����������Ϣ
		if (p == NULL) {
			printf("û�д˱��\n");
			//ʹҳ��ͣ���ڵ�ǰҳ
			printf("�������������......");
			getch();
		}
	}
	//�������Ϊ��
	else {
		printf("��δ����ͼ�������봴���������ɾ��\n");
		//ʹҳ��ͣ���ڵ�ǰҳ
		printf("�������������......");
		getch();
	}
	
}

//����ڵ�ģ�飨�ɶ�����룩
void insert(Book *head) {
	system("cls");

	//�������Ϊ�գ���ʼ����
	if (head) {
		int flag = 1;	//flagʵ���ж�ָ���Ƿ񵽴����һ���ڵ�

		Book* p, * q, * r;	//����ָ����ڲ������
		printf("�������鱾����Ϣ,��-1��������ʽ����� ���� ���� ����� �۸�\n");

		int id;	//����ı��
		scanf_s("%d", &id);

		while (id != -1) {	//����-1����
			r = (Book*)malloc(sizeof(Book));	//rָ�뿪�ٿռ�
			r->next = NULL;	//�ÿ�r��ָ����
			r->id = id;
			scanf("%s %s %d %f", r->name, r->author, &r->inventory, &r->price);

			q = head;//qָ���¼ͷ�ڵ�ĵ�ַ
			p = head->next;//pָ���¼ͷ�ڵ��ָ����ĵ�ַ
			while (q->next != NULL && p->id < r->id) { //ѭ����������q->next��Ϊ��,�Լ���ͼ�����������
				p = p->next;//pָ�����
				q = q->next;//qָ�����
				if (q->next == NULL) { //����жϷ�ֹq->nextΪ��ʱ����ִ��ѭ���ǳ���Ұָ��ʹ�������
					p = NULL;//��ֹ����Ұָ��p
					q->next = r;//���ӽڵ�
					r->next = NULL;//�ÿ�rָ����
					flag = 0;//�������һ���ڵ����flag
					break;
				}
			}
			if (flag) { //�ж��Ƿ񵽴����һ���ڵ㣬Ϊ��ִ�иò���
				r->next = p;
				q->next = r;
				//ʵ�ֽ�r�ڵ��������
			}
			printf("�������鱾����Ϣ,��-1��������ʽ����� ���� ���� ����� �۸�\n");
			scanf_s("%d", &id);
		}
	}
	//�������Ϊ��
	else {
		printf("��δ����ͼ�������봴��������ٲ���!\n");
		//ʹҳ��ͣ���ڵ�ǰҳ
		printf("�������������......");
		getch();
	}
	

}


//�޸Ľڵ�ģ��
void mod(Book* head) {
	system("cls");
	//�������Ϊ�գ���ʼ�޸�
	if (head) {
		Book* p;	//����ָ��
		int id1, id2, inventory1;	//����num1������������鼮�޸���Ϣ,num2�����޸�
		char name1[50], author1[20];
		float price1;
		printf("������Ҫ�޸ĵ�ͼ���ţ�");
		//����Ҫ�޸ĵ�ͼ����
		scanf_s("%d", &id1);
		p = head->next;
		while (p != NULL) {
			if (p->id == id1) {		//�ж��Ƿ��ҵ��鼮
				printf("�������鱾����Ϣ����ʽ����� ���� ���� ����� �۸�\n");
				//Ϊ��ʱ������ͼ����Ϣ
				scanf("%d %s %s %d %f", &id2, name1, author1, &inventory1, &price1);
				p->id = id2;
				strcpy(p->name, name1);
				strcpy(p->author, author1);
				p->inventory = inventory1;
				p->price = price1;
				break;
			}
			else {
				//Ϊ��ʱ
				p = p->next;//ָ�����
			}
		}
		if (p == NULL) {//���ҵ����һ���ڵ㻹δ�鵽Ҫ�ı��ʱ�����������Ϣ
			printf("δ���ҵ���ͼ����\n");
			//ʹҳ��ͣ���ڵ�ǰҳ
			printf("�������������......");
			getch();
		}
	}
	else {
		printf("��δ����ͼ�������봴����������޸�!\n");
		//ʹҳ��ͣ���ڵ�ǰҳ
		printf("�������������......");
		getch();
	}

}

//���������
void printBook(Book *head) {
	system("cls");		// ����
	//�������Ϊ�գ���ʾ��Ϣ
	if (head) {
		Book* p = head->next;
		printf("���\t����\t����\t����\t�۸�\n");
		while (p) { //��p��Ϊ�յ�ʱ��ִ��
			printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
			printf("\n");
			p = p->next;//ָ�����
		}
	}
	//���Ϊ��
	else {
		printf("��δ����ͼ������������鱾���ٲ�ѯ!\n");
	}

	//ʹҳ��ͣ���ڵ�ǰҳ
	printf("�������������......");
	getch();
}

//��ӡ�����˵�
void printSearchMenu() {
	system("cls");		// ����
	system("color 71");	//��������ͱ�����ɫ

	putchar('\n');
	printf("\t\tͼ����Ϣ����ϵͳ\t\n");
	printf("\t ============================\n");
	printf("\t\t  ͼ����Ϣ��ѯ\t\n");
	printf("\t ============================\n");
	printf("\t ��\t1.��ѯ����ͼ����Ϣ ��\n");
	printf("\t ��\t2.���ݱ�Ų�ѯ     ��\n");
	printf("\t ��\t3.����������ѯ     ��\n");
	printf("\t ��\t4.�������߲�ѯ     ��\n");
	printf("\t ��\t5.�������˵�       ��\n");
	printf("\t ============================\n");
	printf("\t��ѡ����(1��5,�������ַ��˳�):");

}

//�������߲�ѯ
void searchByAuthor(Book* head) {
	system("cls");		// ����

	//�������Ϊ�գ���ʼ��ѯ
	if (head) {
		Book* p;//����ָ��
		char author[20];//����author������������鼮
		printf("��������Ҫ����ͼ�������:");
		//�����������
		scanf("%s", author);
		p = head->next;
		while (p != NULL) {
			if (strcmp(p->author, author) == 0) { //�ж��Ƿ��ҵ��鼮
				//Ϊ��ʱ�������Ϣ
				printf("�鼮��Ϣ\n");
				printf("���\t����\t����\t����\t�۸�\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
				break;
			}
			else
				//Ϊ��ʱ
				p = p->next;//ָ�����
		}
		if (p == NULL) {	//���ҵ����һ���ڵ㻹δ�鵽Ҫ�ı��ʱ�����������Ϣ
			printf("δ��ѯ����ͼ�飡\n");
		}
	}
	//���Ϊ��
	else {
		printf("��δ����ͼ������������鱾���ٲ�ѯ!\n");
	}

	//ʹҳ��ͣ���ڵ�ǰҳ
	printf("�������������......");
	getch();
}

//���ݱ�Ų���ͼ����Ϣ
void searchById(Book* head) {
	system("cls");		// ����
	//�������Ϊ�գ���ʼ��ѯ
	if (head) {
		Book* p;//����ָ��
		int id1;//����id1������������鼮
		printf("��������Ҫ���ҵ�ͼ����:");
		//������ұ��
		scanf_s("%d", &id1);
		p = head->next;
		while (p != NULL) {
			if (p->id == id1) { //�ж��Ƿ��ҵ��鼮
				//Ϊ��ʱ�������Ϣ
				printf("���\t����\t����\t����\t�۸�\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
				break;
			}
			else
				//Ϊ��ʱ
				p = p->next;//ָ�����
		}
		if (p == NULL)//���ҵ����һ���ڵ㻹δ�鵽Ҫ�ı��ʱ�����������Ϣ
			printf("δ��ѯ����ͼ�飡\n");
	}
	//���Ϊ��
	else {
		printf("��δ����ͼ������������鱾���ٲ�ѯ!\n");
	}

	//ʹҳ��ͣ���ڵ�ǰҳ
	printf("�������������......");
	getch();
}

//������������ͼ����Ϣ
void searchByName(Book* head) {
	system("cls");		// ����
	
	//�������Ϊ�գ���ʼ��ѯ
	if (head) {
		Book* p;//����ָ��
		char name1[50];//����name1���������������
		printf("��������Ҫ���ҵ�����:");
		//�����������
		scanf("%s", name1);
		p = head->next;
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) { //�ж��Ƿ��ҵ��鼮
				//Ϊ��ʱ�������Ϣ
				printf("���\t����\t����\t����\t�۸�\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->author, p->inventory, p->price);
				break;
			}
			else {
				//Ϊ��ʱ
				p = p->next;//ָ�����
			}
		}
		if (p == NULL) {	//���ҵ����һ���ڵ㻹δ�鵽Ҫ�ı��ʱ�����������Ϣ
			printf("δ��ѯ����ͼ�飡\n");
		}
	}
	//���Ϊ��
	else {
		printf("��δ����ͼ������������鱾���ٲ�ѯ!\n");
	}

	//ʹҳ��ͣ���ڵ�ǰҳ
	printf("�������������......");
	getch();
}

//������ݱ������ð������
void sortById(Book* head) {
	//������û���޸�ͷ�ڵ�ָ��ֵ��ֻ���޸�ָ������head->next��ֵ
	Book* pre, * p, * tail, * temp;
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail) { //(head->next)!=tailͬ������ ����ִ�����һ�����Ƚ�
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if ((p->id) > (p->next->id)) {
				pre->next = p->next; //�����ڵ㷽��
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = pre->next;  //p����һ���ڵ�
			}
			p = p->next;  //p��ǰ��һ���ڵ�
			pre = pre->next;
		}
		tail = p;
	}
}
