#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int exitstatus = 0;
char usern[5] = "John";
char function[7];
char *diet[100][50][4];

/* function declaration */
void login(char username[]);
char *cp(char username[]);
void add();
void modify();
void view();
void search();
void sort();

int main(int argc, char *argv[]) {
	
	do {
		printf("Login Screen \n");
		login(usern);
		exitstatus = 0;
		
		do {
			printf("\nMeal(s) Screen \n");
			printf("Choose a function: Add, Modify, View, Search, Sort, Exit\n");
			scanf("%s", &function);
			if (strcmp (function, "Add") == 0) {
				add();
				system("pause");
			} else if (strcmp (function, "Modify") == 0) {
				modify();
				system("pause");
			} else if (strcmp (function, "View") == 0) {
				view();
				system("pause");
			} else if (strcmp (function, "Search") == 0) {
				search();
				system("pause");
			} else if (strcmp (function, "Sort") == 0) {
				sort();
				system("pause");
			} else if (strcmp (function, "Exit") == 0){
				exitstatus = 1;
			}
			
		} while (exitstatus == 0);
		
	} while (exitstatus == 1);
	return 0;
}

void login(char username[]) {
	char gusername[5];
	char gpassword[5];
	char password[5];
	
	do {
		printf ("\nEnter username\n");
		scanf ("%s", &gusername);
	} while (strcmp(gusername,username) != 0);
	
	do {
		printf ("\nEnter password\n");
		scanf ("%s", &gpassword);
	} while (strcmp(gpassword, cp(username)) != 0);
}

char *cp(char username[]) {
	int i = 0;
	char password[5];
	for (i=0; i<5; i++){
		if (i%2==0){
			password[i] = toupper(username[i]);
		} else {
			password[i] = username[i];
		}
	}
	return password;
}

void add() {
	int i=-1;
	int j=0;
	char time[5];
	
	char *token;
	char hours[5];
	char minutes[5];
	
	do {
		i++;
	} while (*diet[i][j] != NULL);
	
	printf("Enter food name \n");
	scanf("%s", &*diet[i][j]);
	j++;
	printf("Enter number of calories \n");
	scanf("%d", &*diet[i][j]);
	j++;
	printf("Enter time of consume (XX.YY format) \n");
	scanf("%s", time);
	
	int counter = 0;
	strcpy(&*diet[i][j], time);
	token = strtok(time, ".");
	while(token != NULL)  {
		if(counter == 0) {
			strcpy(hours, token);
		}
		else if(counter == 1) {
			strcpy(minutes, token);
		}
		counter++;
		token = strtok(NULL, ".");
	}
	j++;
	int hourstoInt = atoi(hours);
	
	if(hourstoInt >= 5 && hourstoInt < 12) {
		strcpy(&*diet[i][j], "prwino");
	}
	else if(hourstoInt >= 12 && hourstoInt < 20) {
		strcpy(&*diet[i][j], "mesimeriano");
	}
	else if(hourstoInt >= 20 || hourstoInt < 5) {
		strcpy(&*diet[i][j], "vradino");
	}
}

void modify() {
	
	int i=0;
	int j=0;
	int answer;
	
	do {
		i++;
	} while (*diet[i][j] != NULL);
	
	i--;
	
	printf("%s  |  %d  |  %s  |  %s", &*diet[i][0], *diet[i][1], &*diet[i][2], &*diet[i][3]);
	
	printf("\n");
	
	printf("\nWhich value of the last meal do you want to change?\n");
	printf("Insert the corresponding number (1=Food, 2=Calories, 3=Time, 4=Type of meal\n)");
	scanf("%d", &answer);
	answer--;
	*diet[i][answer] = NULL;
	
	printf("Insert the new data\n");
	if(answer == 1) {
		scanf("%d", &*diet[i][answer]);
	}else{
		scanf("%s", &*diet[i][answer]);
	}
}

void view() {
	
	int i=0;
	int j=0;
	int sumcalories=0;
	
	do {
		printf("%s  |  %d  |  %s  |  %s", &*diet[i][0], *diet[i][1], &*diet[i][2], &*diet[i][3]);
		printf("\n");
		sumcalories = sumcalories + *diet[i][1];
		i++;
	} while (*diet[i][j] != NULL);
	
	printf("Number of meals: %d    Total calories: %d \n", i, sumcalories);
}

void search() {

	int i=0;
	int j=0;
	char type[12];
	
	printf("Insert the type of meal you want to search for (prwino, mesimeriano, vradino)");
	scanf("%s", &type);
	
	if (strcmp (type, "prwino") == 0){
		do {
			if (strcmp (&*diet[i][3], "prwino") == 0) {
				printf("%s  |  %d  |  %s  |  %s", &*diet[i][0], *diet[i][1], &*diet[i][2], &*diet[i][3]);
				printf("\n");
			}
			i++;
		} while (*diet[i][j] != NULL);
	}
	
	else if (strcmp (type, "mesimeriano") == 0){
		do {
			if (strcmp (&*diet[i][3], "mesimeriano") == 0) {
				printf("%s  |  %d  |  %s  |  %s", &*diet[i][0], *diet[i][1], &*diet[i][2], &*diet[i][3]);
				printf("\n");
			}
			i++;
		} while (*diet[i][j] != NULL);
	}
	
	else if (strcmp (type, "vradino") == 0){
		do {
			if (strcmp (&*diet[i][3], "vradino") == 0) {
				printf("%s  |  %d  |  %s  |  %s", &*diet[i][0], *diet[i][1], &*diet[i][2], &*diet[i][3]);
				printf("\n");
			}
			i++;
		} while (*diet[i][j] != NULL);
	}
}

void sort() {
	
	int i=0;
	int j=0;
	char *temp[20] = { NULL };
	
	do {
		i++;
	} while (*diet[i][j] != NULL);
	
	int n = i;
	
	for (i=0; i<n-1; i++){
		for (j=0; j<n-i-1; j++){
			
			if (*diet[j][1] < *diet[j+1][1]){
				
				*temp = *diet[j][1];
				*diet[j][1] = *diet[j+1][1];
				*diet[j+1][1] = *temp;
				
				*temp = *diet[j][0];
				*diet[j][0] = *diet[j+1][0];
				*diet[j+1][0] = *temp;
				
				*temp = *diet[j][2];
				*diet[j][2] = *diet[j+1][2];
				*diet[j+1][2] = *temp;
				
				*temp = *diet[j][3];
				*diet[j][3] = *diet[j+1][3];
				*diet[j+1][3] = *temp;
				
			}
		}
	}
	 i=0;
	 j=0;
	
	
	do {
		printf("%s  |  %d  |  %s  |  %s", &*diet[i][0], *diet[i][1], &*diet[i][2], &*diet[i][3]);
		printf("\n");
		i++;
	} while (*diet[i][j] != NULL);
	
}
