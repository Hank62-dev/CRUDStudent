#include <stdio.h>
#include <stdlib.h>

void addStudent();
void listStudent();
void updateStudent( char* name);
void deleteStudent( char* name);

int main(){
	
	//tạo file mới
	FILE *file;
	file = fopen("student.txt","w");
	//đóng file
	fclose(file);
	char name[100], school[100];
	int age;
	int choice;
	do{
		printf("\n#===Student Manament===#\n");
		printf("1.Add new student.\n");
		printf("2.List Student.\n");
		printf("3.Update student.\n");
		printf("4.Delete student.\n");
		printf("5.Exit.\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		getchar();
		
		
		switch(choice) {
			case 1:
				addStudent();
				break;
			case 2:
				listStudent();
				break;
			case 3:
				printf("Enter student name to update: ");
				fgets(name, 100, stdin);
				name[strcspn(name,"\n")] = 0;
				updateStudent(name);	
				break;
			case 4:
				printf("Enter student name to delete: ");
				fgets(name, 100, stdin);
				name[strcspn(name,"\n")] = 0;
				deleteStudent(name);
				break;
			case 5:
				printf("Exiting.......");
				break;
			default: 
				printf("Invalid choice. Try again.\n");	
		}
	}while (choice != 5);

	return 0;
}
void addStudent(){
	FILE* file = fopen("student.txt", "a");
	if(!file){
		printf("Error opening file\n");
		return;
	}
	char name[100], school[100];
	int age;
	printf("Enter student's name: ");
	fgets(name, 100, stdin);
	name[strcspn(name,"\n")] = 0;
	
	printf("Enter age: ");
	scanf("%d", &age);
	getchar();
	
	printf("Enter school: ");
	fgets(school, 100, stdin);
	school[strcspn(school,"\n")] = 0;
	
	fprintf(file,"%s,%d,%s\n",name, age, school);
	fclose(file);
	printf("\nStudent added successfully!\n");
	
}
void listStudent(){
	FILE* file = fopen("student.txt", "r");
	if(!file){
		printf("No student found.\n");
		return;
	}
	char name[100];
	char school[100];
	int age;
	
	printf("\nStudents List: \n");
	while(fscanf(file, "%49[^,],%d,%99[^\n]\n", name, &age, school) != EOF){
		printf("%s,%d,%s\n", name, age, school);
	}
	fclose(file);
}

void updateStudent( char* name){
	FILE* file = fopen("student.txt", "r");
	if(!file){
		printf("Error opening file.\n");
		return;
	}
	FILE* temp = fopen("temp.txt","w");
	
	if(!temp){
		printf("Error opening temp file.\n");
		fclose(file);
		return;
	}
	
	char nameStudent[100];
	char school[100];
	int age;
	int found = 0;
	
	while(fscanf(file,"%49[^,],%d,%99[^\n]\n", nameStudent,&age,school) == 3) {

		
		if(strcmp(nameStudent, name) == 0){
			printf("Enter new age: ");
			if(scanf("%d",&age) != 1){
				printf("Invalid input.\n");
				fclose(file);
				fclose(temp);
				return;
			}
			getchar();
			printf("Enter new school: ");
			fgets(school, 100, stdin);
			school[strcspn(school, "\n")] = 0;
			found = 1;
		}
		fprintf(temp, "%s,%d,%s\n", nameStudent, age, school);
	}
	fclose(file);
	fclose(temp);
	remove("student.txt");
	rename("temp.txt","student.txt");
	
	if(found){
		printf("Student updated successfully!\n");
	}else{
		printf("Student not found.\n");
	}
	
}
void deleteStudent( char* name){
	FILE* file = fopen("student.txt", "r");
	if(!file){
		printf("Error opening file.\n");
		return;
	}
	
	char nameStudent[100], school[100];
	int age;	
	
}

















