#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <Psapi.h>
#pragma warning(disable:4996)

typedef struct Lotto
{
	int drawNumber;
	char date[100];
	struct Lotto* next;
	struct Lotto* prev;
}lotto;


void Q1();
void Q2();
int Add222(int num);
void Q4();
void addToList(char date[], int number);
lotto* head = NULL;
lotto* tail = NULL;

int main() {
	Q4();
	return 0;
}

void Q1()
{
	char stringSize;
	char userString[100];

	printf("Enter string: ");
	gets(userString);
	printf("\n");

	stringSize = strlen(userString);
	for (int i = 0; i < stringSize; i++)
	{
		if (i == stringSize/2)
		{
			printf("\n");
		}
		printf("%c", userString[i]);
	}
	
}

void Q2() 
{
	char stringSize;
	char userString[100];
	printf("Enter string: ");
	gets(userString);
	printf("\n");
	stringSize = strlen(userString);
	
	while (stringSize != 0)
	{
		stringSize = stringSize / 2;
		printf("\n");
	for (int i = 0; i < stringSize; i++)
	{
		printf("%c", userString[i]);
	}
	}
}

int Add222(int num)
{
	printf("%d\n", num);
	return num != 100 ? Add222(num + 1) : 0;
}

void addToList(char date[],int number)
{

	lotto* newStruct = (lotto*)malloc(sizeof(lotto));
	if (!newStruct)
	{
		//log write
		exit(1);
	}

	newStruct->next = NULL;
	newStruct->drawNumber = number;
	strcpy(newStruct->date, date);

	if (head == NULL)
	{
		newStruct->prev = NULL;
		head = newStruct;
		tail = newStruct;
	}
	else
	{
		tail->next = newStruct;
		newStruct->prev = tail;
		tail = newStruct;
	}

}


void Q4()
{
	lotto* ptr;
	char* token;
	char dater[100],c=1;
	int number;
	
	FILE* f = fopen("Lotto.txt", "r");
	if(!f){
		//log write
		return 1;
	}

	while (fgets(dater,50,f))
	{
		token = strtok(dater, ",");
		number = atoi(token);
		token = strtok(NULL, ",");
		strcpy(dater, token);
		addToList(dater, number);
	}

	printf("press N to search\npress Q to quit: ");
	while (c != 'E')
	{
		c = getch();
		switch (c)
		{
		case 'N':
		case 'n':
			printf("\nEnter draw number to get its date: ");
			scanf("%d", &number);
			ptr = head;
			while (ptr != NULL )
			{
				if (ptr->drawNumber == number)
				{
					printf("the date is: %s", ptr->date);
				}
				ptr = ptr->next;
			}
			if(ptr ==NULL)
			{
				printf("\npress N to search\npress Q to quit:");
			}
			break;
		case 'Q':
		case 'q': return 0;
			break;
		default:printf("\nPlease enter a valid char\n");
			break;
		}
	}
}