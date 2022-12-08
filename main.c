#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int,int);
void bscs_ya1();
void bscs_ya2();
void bsit_ya1();
void bsit_ya2();


int viewStudentListCondition = 1;
char usernameG[20];
char teacherUsername[20] = {
    "Sheinn Reyes"
};
char teacherPassword[20] = {
    "PseudosRebelz"
};


struct bscs_ya1_list{

    char lastname[50];
    char firstname[50];
    char studentNumber[30];
    char prelim[30];
    char midterm[30];
    char finals[30];
};

//---------------------Struct for storing student deatils for Recording of Attendance
struct student{

    char studentNumber[50];
    char firstname[50];
    char lastname[50];
    char vaccinationStatus[50];
    char contactNumber[15];
    char arrivalTime[50];
    char course[20];
    char section[20];

};

void bscsList(){

    struct bscs_ya1_list student;

        FILE *fpointer;

        fpointer = fopen("BSCS_1-YA-1_Student_List.txt", "ab+");

        strcpy(student.lastname, "Dotingco");
        strcpy(student.firstname, "Frank Lynuel");
        strcpy(student.studentNumber, "02220003438");
        strcpy(student.prelim, "0");
        strcpy(student.midterm, "0");
        strcpy(student.finals, "0");

            fflush(stdin);
            fwrite(&student,sizeof(student),1,fpointer);

        strcpy(student.lastname, "Ilaida");
        strcpy(student.firstname, "Romille");
        strcpy(student.studentNumber, "02220003439");
        strcpy(student.prelim, "0");
        strcpy(student.midterm, "0");
        strcpy(student.finals, "0");

            fflush(stdin);
            fwrite(&student,sizeof(student),1,fpointer);

        strcpy(student.lastname, "Lim");
        strcpy(student.firstname, "Jald");
        strcpy(student.studentNumber, "02220003440");
        strcpy(student.prelim, "0");
        strcpy(student.midterm, "0");
        strcpy(student.finals, "0");

            fflush(stdin);
            fwrite(&student,sizeof(student),1,fpointer);

        strcpy(student.lastname, "Ong");
        strcpy(student.firstname, "Noriel Edwards");
        strcpy(student.studentNumber, "0220-1892-888");
        strcpy(student.prelim, "0");
        strcpy(student.midterm, "0");
        strcpy(student.finals, "0");

            fflush(stdin);
            fwrite(&student,sizeof(student),1,fpointer);

        strcpy(student.lastname, "Torre");
        strcpy(student.firstname, "Jayel");
        strcpy(student.studentNumber, "02220003442");
        strcpy(student.prelim, "0");
        strcpy(student.midterm, "0");
        strcpy(student.finals, "0");

            fflush(stdin);
            fwrite(&student,sizeof(student),1,fpointer);

        strcpy(student.lastname, "Zara");
        strcpy(student.firstname, "Je Ace");
        strcpy(student.studentNumber, "02220003443");
        strcpy(student.prelim, "0");
        strcpy(student.midterm, "0");
        strcpy(student.finals, "0");

            fflush(stdin);
            fwrite(&student,sizeof(student),1,fpointer);

        fclose(fpointer);

}

void viewStudentList(){

    system("cls");

    struct bscs_ya1_list student;

    FILE *fp;
    int i=1,j;

    gotoxy(15,5);
    printf("---View Student List---");
    gotoxy(15,7);
    printf("Student No.        Name of Student             Prelim       Midterm     Finals");
    gotoxy(15,8);
    printf("---------------------------------------------------------------------------------");

    fp = fopen("BSCS_1-YA-1_Student_List.txt","rb+");
    if(fp == NULL){
        gotoxy(15,10);
        printf("Error opening file.");
        getch();
        teacherMenu();
    }
    j=10;
    int a = 20;
    sleep(1);
    while(fread(&student,sizeof(student),1,fp) == 1){
        gotoxy(15,j);
        printf("%s", student.studentNumber);
        gotoxy(15+a-1,j);
        printf("%s, %s", student.lastname, student.firstname);
        gotoxy(15+(a+27),j);
        printf("%s", student.prelim);
        gotoxy(15+(a+40),j);
        printf("%s", student.midterm);
        gotoxy(15+(a+52),j);
        printf("%s", student.finals);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(15,j+3);

    printf("Press any key to continue...");
    getch();
    system("cls");
    teacherMenu();

}

void recordStudentGrade(){

    system("cls");

    char student_number[20], response;
    int status = 1, subStatus = 1;

    FILE *fp;
    struct bscs_ya1_list std;

    while(status != 0){
        subStatus = 1;
        gotoxy(15,5);
        printf("---Record Student Grade---");
        gotoxy(15,7);
        printf("Enter Student Number: ");
        fflush(stdin);
        gets(student_number);
        fp = fopen("BSCS_1-YA-1_Student_List.txt","rb+");
        if(fp == NULL){
            gotoxy(15,9);
            printf("Error opening file");
            exit(1);
        }
        rewind(fp);
        fflush(stdin);
        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            if(strcmp(student_number,std.studentNumber) == 0){
                gotoxy(15,9);
                printf("Enter Prelim Grade: ");
                gets(std.prelim);
                gotoxy(15,10);
                printf("Enter Midterm Grade: ");
                gets(std.midterm);
                gotoxy(15,11);
                printf("Enter Finals Grade: ");
                gets(std.finals);
                fseek(fp ,-sizeof(std),SEEK_CUR);
                fwrite(&std,sizeof(std),1,fp);
                break;
            }
        }
    fclose(fp);

        while(subStatus != 0){
            gotoxy(15,13);
            printf("Grades have been recorded. Would you like to record again?[Y/N] - ");
            scanf(" %c", &response);

            switch(toupper(response)){
                case 'Y':
                    system("cls");
                    subStatus = 0;
                    break;
                case 'N':
                    teacherMenu();
                    subStatus = 0;
                    break;
                default:
                    system("cls");
                    continue;
            }
        }
    }
}

void change(){

    system("cls");

    char currentPassword[50];
    char newPassword[50], newUsername[50];
    char buffer;

    gotoxy(15,5);
    printf("---Change Username and/or Password---");

    gotoxy(15,7);
    printf("------------------------------------------------");

    gotoxy(15,9);
    printf("Enter Current Password: ");
    scanf(" %[^\n]", &currentPassword);

    if(strcmp(currentPassword, teacherPassword) == 0){
        gotoxy(15,11);
        printf("Enter New Username: ");
        scanf(" %[^\n]", &newUsername);
        gotoxy(15,12);
        printf("Enter New Password: ");
        scanf(" %[^\n]", &newPassword);

        strcpy(teacherUsername, newUsername);
        strcpy(teacherPassword, newPassword);

        gotoxy(15,14);
        printf("------------------------------------------------");

        gotoxy(15,16);
        printf("Username and/or Password Successfully Changed.");
        getch();
        teacherSecurity();
    }else{
        gotoxy(15,11);
        printf("Incorrect Password");
        getch();
        teacherMenu();
    }
}
//---------------------Teacher's Menu Function
void teacherMenu(){

    system("cls");

    int choice;

    FILE *fp;

    fp = fopen("BSCS_1-YA-1_Student_List.txt", "r");

        if(fp == NULL){
            bscsList();
        }

    gotoxy(15,5);
    printf("---Teacher Menu---");

    gotoxy(15,7);
    printf("1. View Attendance Sheet");
    gotoxy(15,8);
    printf("2. View Student List");
    gotoxy(15,9);
    printf("3. Record Student Grade");
    gotoxy(15,10);
    printf("4. Change Username and/or Password");
    gotoxy(15,11);
    printf("5. Back to Home Screen");

    gotoxy(15,13);
    scanf("%d", &choice);

    switch(choice){
        case 1:
            viewAttendanceSheetT();
            break;
        case 2:
            viewStudentList();
            break;
        case 3:
            recordStudentGrade();
            break;
        case 4:
            change();
            break;
        case 5:
            main();
            break;
    }
}
//---------------------Loading Screen Function redirecting to Teacher's Menu Function
void loadingScreen(){
    system("cls");

    gotoxy(53,12);
    printf("Loading");
    gotoxy(60,12);
    for(int i = 0; i <=2; i++){
        printf(".");
        sleep(1);
    }
    system("cls");
    gotoxy(53,12);
    printf("Loading");
    gotoxy(60,12);
    for(int i = 0; i <=2; i++){
        printf(".");
        sleep(1);
    }
    system("cls");
    gotoxy(53,12);
    printf("Loading");
    gotoxy(60,12);
    for(int i = 0; i <=2; i++){
        printf(".");
        sleep(1);
    }
    system("cls");

    teacherMenu();
}
//---------------------Copy of Log-In System for Teachers for buffer issues
void teacherSecurity1(){

  system("cls");
  int s = 0;
  char username[20], password[20], p, buffer[5];

  gotoxy(15,5);
  printf("---Log-In System---");

  gotoxy(15,7);
  printf("Username: ");

  gets(username);

  gotoxy(15,8);
  printf("Password: ");

  while (p != 13) {
    p = getch();
    if (p != 13) {
      putch('*');
      password[s] = p;
      s++;
    }
  }
  password[s] = '\0';

    if(strcmp(teacherUsername, username) == 0){
      if(strcmp(teacherPassword, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreen();
      }else{
        gotoxy(15, 9);
        printf("Incorrect Password. Try Again.");
        getch();
        teacherSecurity1();
      }
    }else if(strcmp(teacherUsername, username) != 0){
        if(strcmp(teacherPassword, password) == 0){
          gotoxy(15, 9);
          printf("Invalid Username. Try Again.");
          getch();
          teacherSecurity1();
        }else{
          gotoxy(15, 9);
          printf("Invalid Account. Try Again.");
          getch();
          teacherSecurity1();
        }
    }

}
//---------------------Log-In System Function for Teachers
void teacherSecurity(){

  system("cls");
  int s = 0;
  char username[20], password[20], p, buffer[5];

  gotoxy(15,5);
  printf("---Log-In System---");

  gotoxy(15,7);
  printf("Username: ");

  gets(buffer);
  gets(username);

  gotoxy(15,8);
  printf("Password: ");

  while (p != 13) {
    p = getch();
    if (p != 13) {
      putch('*');
      password[s] = p;
      s++;
    }
  }
  password[s] = '\0';

    if(strcmp(teacherUsername, username) == 0){
      if(strcmp(teacherPassword, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreen();
      }else{
        gotoxy(15, 9);
        printf("Incorrect Password. Try Again.");
        getch();
        teacherSecurity1();
      }
    }else if(strcmp(teacherUsername, username) != 0){
        if(strcmp(teacherPassword, password) == 0){
          gotoxy(15, 9);
          printf("Invalid Username. Try Again.");
          getch();
          teacherSecurity1();
        }else{
          gotoxy(15, 9);
          printf("Invalid Account. Try Again.");
          getch();
          teacherSecurity1();
        }
    }

}
//---------------------Record Attendance Function
void recordAttendance(){
    system("cls");

    int status = 1, subStatus = 0;
    char course[50], section[50], name[100], studentNumber[20], vaccinationStatus[30], contactNumber[20];
    char response;
    char buffer;

    struct student std;

    while(status != 0){
        gotoxy(15,5);
        printf("---Record Attendance---");

        gets(buffer);
        gotoxy(15,7);
        printf("Enter Course: ");
        scanf(" %[^\n]", &course);
        gotoxy(15,8);
        printf("Enter Section: ");
        scanf(" %[^\n]", &section);
        gotoxy(15,10);
        printf("--------------------------------------------------------------");

        if(strcmp(strupr(course), "BSCS") == 0){
            if(strcmp(strupr(section), "YA-1") == 0 || strcmp(strupr(section), "1-YA-1") == 0 || strcmp(strupr(section), "1YA-1") == 0 || strcmp(strupr(section), "1-YA1") == 0 || strcmp(strupr(section), "YA1") == 0 || strcmp(strupr(section), "1YA1") == 0){
                FILE *fp;

                fp = fopen("BSCS_1YA1_Attendance_Sheet.txt", "ab+");
                fflush(stdin);
                        gotoxy(15,12);
                        printf("Enter Student Number: ");
                        gets(std.studentNumber);
                        gotoxy(15,13);
                        printf("Enter First Name: ");
                        gets(std.firstname);
                        gotoxy(15,14);
                        printf("Enter Last Name: ");
                        gets(std.lastname);
                        gotoxy(15,15);
                        printf("Enter Vaccination Status: ");
                        gets(std.vaccinationStatus);
                        gotoxy(15,16);
                        printf("Enter Contact Number: ");
                        gets(std.contactNumber);

                        strcpy(std.course, "BSCS");
                        strcpy(std.section, "1-YA-1");

                        sleep(1);

                        time_t arrivaltime = time(NULL);
                        char *arrival = ctime(&arrivaltime);

                        strcpy(std.arrivalTime, arrival);

                fwrite(&std,sizeof(std),1,fp);
                fclose(fp);

                FILE *fpointer;

                time_t date = time(NULL);
                char *filename = ctime(&date);

                fpointer = fopen("Attendance Sheet.txt", "ab+");
                    fwrite(&std,sizeof(std),1,fpointer);
                fclose(fpointer);

            }else if(strcmp(strupr(section), "YA-2") == 0 || strcmp(strupr(section), "1-YA-2") == 0 || strcmp(strupr(section), "1YA-2") == 0 || strcmp(strupr(section), "1-YA2") == 0 || strcmp(strupr(section), "YA2") == 0 || strcmp(strupr(section), "1YA2") == 0){
                FILE *fp;

                fp = fopen("BSCS_1YA2_Attendance_Sheet.txt", "ab+");
                fflush(stdin);
                        gotoxy(15,12);
                        printf("Enter Student Number: ");
                        gets(std.studentNumber);
                        gotoxy(15,13);
                        printf("Enter First Name: ");
                        gets(std.firstname);
                        gotoxy(15,14);
                        printf("Enter Last Name: ");
                        gets(std.lastname);
                        gotoxy(15,15);
                        printf("Enter Vaccination Status: ");
                        gets(std.vaccinationStatus);
                        gotoxy(15,16);
                        printf("Enter Contact Number: ");
                        gets(std.contactNumber);

                        strcpy(std.course, "BSCS");
                        strcpy(std.section, "1-YA-2");

                        sleep(1);

                        time_t arrivaltime = time(NULL);
                        char *arrival = ctime(&arrivaltime);

                        strcpy(std.arrivalTime, arrival);

                fwrite(&std,sizeof(std),1,fp);
                fclose(fp);

                FILE *fpointer;

                time_t date = time(NULL);
                char *filename = ctime(&date);

                fpointer = fopen("Attendance Sheet.txt", "ab+");
                    fwrite(&std,sizeof(std),1,fpointer);
                fclose(fpointer);

            }else{
                gotoxy(15,18);
                printf("Error! Invalid Section");
                sleep(3);
                system("cls");
            }
        }else if(strcmp(strupr(course), "BSIT") == 0){
            if(strcmp(strupr(section), "YA-1") == 0 || strcmp(strupr(section), "1-YA-1") == 0 || strcmp(strupr(section), "1YA-1") == 0 || strcmp(strupr(section), "1-YA1") == 0 || strcmp(strupr(section), "YA1") == 0 || strcmp(strupr(section), "1YA1") == 0){
                FILE *fp;

                fp = fopen("BSIT_1YA1_Attendance_Sheet.txt", "ab+");
                fflush(stdin);
                        gotoxy(15,12);
                        printf("Enter Student Number: ");
                        gets(std.studentNumber);
                        gotoxy(15,13);
                        printf("Enter First Name: ");
                        gets(std.firstname);
                        gotoxy(15,14);
                        printf("Enter Last Name: ");
                        gets(std.lastname);
                        gotoxy(15,15);
                        printf("Enter Vaccination Status: ");
                        gets(std.vaccinationStatus);
                        gotoxy(15,16);
                        printf("Enter Contact Number: ");
                        gets(std.contactNumber);

                        strcpy(std.course, "BSIT");
                        strcpy(std.section, "1-YA-1");

                        sleep(1);

                        time_t arrivaltime = time(NULL);
                        char *arrival = ctime(&arrivaltime);

                        strcpy(std.arrivalTime, arrival);

                fwrite(&std,sizeof(std),1,fp);
                fclose(fp);

                FILE *fpointer;

                time_t date = time(NULL);
                char *filename = ctime(&date);

                fpointer = fopen("Attendance Sheet.txt", "ab+");
                    fwrite(&std,sizeof(std),1,fpointer);
                fclose(fpointer);

            }else if(strcmp(strupr(section), "YA-2") == 0 || strcmp(strupr(section), "1-YA-2") == 0 || strcmp(strupr(section), "1YA-2") == 0 || strcmp(strupr(section), "1-YA2") == 0 || strcmp(strupr(section), "YA2") == 0 || strcmp(strupr(section), "1YA2") == 0){
                FILE *fp;

                fp = fopen("BSIT_1YA2_Attendance_Sheet.txt", "ab+");
                fflush(stdin);
                        gotoxy(15,12);
                        printf("Enter Student Number: ");
                        gets(std.studentNumber);
                        gotoxy(15,13);
                        printf("Enter First Name: ");
                        gets(std.firstname);
                        gotoxy(15,14);
                        printf("Enter Last Name: ");
                        gets(std.lastname);
                        gotoxy(15,15);
                        printf("Enter Vaccination Status: ");
                        gets(std.vaccinationStatus);
                        gotoxy(15,16);
                        printf("Enter Contact Number: ");
                        gets(std.contactNumber);

                        strcpy(std.course, "BSIT");
                        strcpy(std.section, "1-YA-2");

                        sleep(1);

                        time_t arrivaltime = time(NULL);
                        char *arrival = ctime(&arrivaltime);

                        strcpy(std.arrivalTime, arrival);

                fwrite(&std,sizeof(std),1,fp);
                fclose(fp);

                FILE *fpointer;

                time_t date = time(NULL);
                char *filename = ctime(&date);

                fpointer = fopen("Attendance Sheet.txt", "ab+");
                    fwrite(&std,sizeof(std),1,fpointer);
                fclose(fpointer);

            }else{
                gotoxy(15,18);
                printf("Error! Invalid Section");
                sleep(3);
                system("cls");
            }
        }else{
            gotoxy(15,18);
            printf("Error! Invalid Course!");
            sleep(3);
            system("cls");
        }

        gotoxy(15,18);
        printf("--------------------------------------------------------------");

        subStatus = 1;

        while(subStatus != 0){
            gotoxy(15,19);
            printf("Your response has been recorded. Would you like to record again?[Y/N] - ");
            scanf(" %c", &response);

            switch(toupper(response)){
                case 'Y':
                    system("cls");
                    subStatus = 0;
                    break;
                case 'N':
                    studentMenu();
                    subStatus = 0;
                    break;
                default:
                    system("cls");
                    continue;
            }
        }


    }
}

void viewAttendanceSheetS(){
    system("cls");

    FILE *fp;
    int i=1,j;
    struct student std;

    gotoxy(15,5);
    printf("---View Attendance Sheet---");
    gotoxy(15,7);
    printf("Name of Student        Course and Section        Vaccination Status       Time of Arrival");
    gotoxy(15,8);
    printf("------------------------------------------------------------------------------------------------------");

    fp = fopen("Attendance Sheet.txt","rb+");
    if(fp == NULL){
        gotoxy(15,10);
        printf("Error opening file.");
        getch();
        studentMenu();
    }
    j=10;
    int a = 20;
    sleep(1);
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(15,j);
        printf("%s, %s", std.lastname, std.firstname);
        gotoxy(15+(a+4),j);
        printf("%s %s", std.course, std.section);
        gotoxy(15+(a+30),j);
        printf("%s", std.vaccinationStatus);
        gotoxy(15+(a+55),j);
        printf("%s", std.arrivalTime);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(15,j+3);

    printf("Press any key to continue...");
    getch();
    studentMenu();
}

void viewAttendanceSheetT(){

    system("cls");

    FILE *fp;
    int i=1,j;
    struct student std;

    char course[50], section[50];

    gotoxy(15,5);
    printf("Enter Course: ");
    scanf(" %[^\n]", &course);
    gotoxy(15,6);
    printf("Enter Section: ");
    scanf(" %[^\n]", &section);

        if(strcmp(strupr(course), "BSCS") == 0){
            if(strcmp(strupr(section), "YA-1") == 0 || strcmp(strupr(section), "1-YA-1") == 0 || strcmp(strupr(section), "1YA-1") == 0 || strcmp(strupr(section), "1-YA1") == 0 || strcmp(strupr(section), "YA1") == 0 || strcmp(strupr(section), "1YA1") == 0){

                system("cls");

                gotoxy(15,5);
                printf("---View BSCS 1-YA-1 Attendance Sheet---");
                gotoxy(15,7);
                printf("Student No.        Name of Student        Vaccination Status       Time of Arrival");
                gotoxy(15,8);
                printf("------------------------------------------------------------------------------------------------------");
                fp = fopen("BSCS_1YA1_Attendance_Sheet.txt","rb+");
                if(fp == NULL){
                    gotoxy(15,10);
                    printf("Error opening file.");
                    getch();
                    teacherMenu();
                }
                j=10;
                int a = 20;
                sleep(1);
                while(fread(&std,sizeof(std),1,fp) == 1){
                    gotoxy(15,j);
                    printf("%s", std.studentNumber);
                    gotoxy(15+a-1,j);
                    printf("%s, %s", std.lastname, std.firstname);
                    gotoxy(15+(a+23),j);
                    printf("%s", std.vaccinationStatus);
                    gotoxy(15+(a+48),j);
                    printf("%s", std.arrivalTime);
                    i++;
                    j++;
                }
                fclose(fp);
                gotoxy(15,j+3);

                printf("Press any key to continue...");
                getch();
                teacherMenu();

            }else if(strcmp(strupr(section), "YA-2") == 0 || strcmp(strupr(section), "1-YA-2") == 0 || strcmp(strupr(section), "1YA-2") == 0 || strcmp(strupr(section), "1-YA2") == 0 || strcmp(strupr(section), "YA2") == 0 || strcmp(strupr(section), "1YA2") == 0){

                system("cls");

                gotoxy(15,5);
                printf("---View BSCS 1-YA-2 Attendance Sheet---");
                gotoxy(15,7);
                printf("Student No.        Name of Student        Vaccination Status       Time of Arrival");
                gotoxy(15,8);
                printf("------------------------------------------------------------------------------------------------------");
                fp = fopen("BSCS_1YA2_Attendance_Sheet.txt","rb+");
                if(fp == NULL){
                    gotoxy(15,10);
                    printf("Error opening file.");
                    getch();
                    teacherMenu();
                }
                j=10;
                int a = 20;
                while(fread(&std,sizeof(std),1,fp) == 1){
                    gotoxy(15,j);
                    printf("%s", std.studentNumber);
                    gotoxy(15+a-1,j);
                    printf("%s, %s", std.lastname, std.firstname);
                    gotoxy(15+(a+23),j);
                    printf("%s", std.vaccinationStatus);
                    gotoxy(15+(a+48),j);
                    printf("%s", std.arrivalTime);
                    i++;
                    j++;
                }
                fclose(fp);
                gotoxy(15,j+3);

                printf("Press any key to continue...");
                getch();
                teacherMenu();

            }else{
                gotoxy(15,18);
                printf("Error! Invalid Section");
                sleep(3);
                system("cls");
                viewAttendanceSheetT();
            }
        }else if(strcmp(strupr(course), "BSIT") == 0){
            if(strcmp(strupr(section), "YA-1") == 0 || strcmp(strupr(section), "1-YA-1") == 0 || strcmp(strupr(section), "1YA-1") == 0 || strcmp(strupr(section), "1-YA1") == 0 || strcmp(strupr(section), "YA1") == 0 || strcmp(strupr(section), "1YA1") == 0){

                system("cls");

                gotoxy(15,5);
                printf("---View BSIT 1-YA-1 Attendance Sheet---");
                gotoxy(15,7);
                printf("Student No.        Name of Student        Vaccination Status       Time of Arrival");
                gotoxy(15,8);
                printf("------------------------------------------------------------------------------------------------------");
                fp = fopen("BSIT_1YA1_Attendance_Sheet.txt","rb+");
                if(fp == NULL){
                    gotoxy(15,10);
                    printf("Error opening file.");
                    getch();
                    teacherMenu();
                }
                j=10;
                int a = 20;
                while(fread(&std,sizeof(std),1,fp) == 1){
                    gotoxy(15,j);
                    printf("%s", std.studentNumber);
                    gotoxy(15+a-1,j);
                    printf("%s, %s", std.lastname, std.firstname);
                    gotoxy(15+(a+23),j);
                    printf("%s", std.vaccinationStatus);
                    gotoxy(15+(a+48),j);
                    printf("%s", std.arrivalTime);
                    i++;
                    j++;
                }
                fclose(fp);
                gotoxy(15,j+3);

                printf("Press any key to continue...");
                getch();
                teacherMenu();

            }else if(strcmp(strupr(section), "YA-2") == 0 || strcmp(strupr(section), "1-YA-2") == 0 || strcmp(strupr(section), "1YA-2") == 0 || strcmp(strupr(section), "1-YA2") == 0 || strcmp(strupr(section), "YA2") == 0 || strcmp(strupr(section), "1YA2") == 0){

                system("cls");

                gotoxy(15,5);
                printf("---View BSIT 1-YA-2 Attendance Sheet---");
                gotoxy(15,7);
                printf("Student No.        Name of Student        Vaccination Status       Time of Arrival");
                gotoxy(15,8);
                printf("------------------------------------------------------------------------------------------------------");
                fp = fopen("BSIT_1YA2_Attendance_Sheet.txt","rb+");
                if(fp == NULL){
                    gotoxy(15,10);
                    printf("Error opening file.");
                    getch();
                    teacherMenu();
                }
                j=10;
                int a = 20;
                while(fread(&std,sizeof(std),1,fp) == 1){
                    gotoxy(15,j);
                    printf("%s", std.studentNumber);
                    gotoxy(15+a-1,j);
                    printf("%s, %s", std.lastname, std.firstname);
                    gotoxy(15+(a+23),j);
                    printf("%s", std.vaccinationStatus);
                    gotoxy(15+(a+48),j);
                    printf("%s", std.arrivalTime);
                    i++;
                    j++;
                }
                fclose(fp);
                gotoxy(15,j+3);

                printf("Press any key to continue...");
                getch();
                teacherMenu();

            }else{
                gotoxy(15,18);
                printf("Error! Invalid Section");
                sleep(3);
                system("cls");
                viewAttendanceSheetT();
            }
        }else{
            gotoxy(15,18);
            printf("Error! Invalid Course!");
            sleep(3);
            system("cls");
            viewAttendanceSheetT();
        }


}


void loadingScreenStudent(){
    system("cls");

    gotoxy(53,12);
    printf("Loading");
    gotoxy(60,12);
    for(int i = 0; i <=2; i++){
        printf(".");
        sleep(1);
    }
    system("cls");
    gotoxy(53,12);
    printf("Loading");
    gotoxy(60,12);
    for(int i = 0; i <=2; i++){
        printf(".");
        sleep(1);
    }
    system("cls");
    gotoxy(53,12);
    printf("Loading");
    gotoxy(60,12);
    for(int i = 0; i <=2; i++){
        printf(".");
        sleep(1);
    }
    system("cls");

    viewGrades();
}

void studentSecurity(){

  system("cls");
  int s = 0;
  char username[20], password[20], p, buffer[5];
  char tUsername1[20] = {
    "02220003438",
  };
  char tUsername2[20] = {
    "02220003439",
  };
    char tUsername3[20] = {
    "02220003440",
  };
  char tUsername4[20] = {
    "0220-1892-888",
  };
  char tUsername5[20] = {
    "02220003442",
  };
  char tUsername6[20] = {
    "02220003443",
  };
  char tPassword1[20] = {
    "PseudosRebelz1",
  };
  char tPassword2[20] = {
    "PseudosRebelz2",
  };
  char tPassword3[20] = {
    "PseudosRebelz3",
  };
  char tPassword4[20] = {
    "PseudosRebelz4",
  };
  char tPassword5[20] = {
    "PseudosRebelz5",
  };
  char tPassword6[20] = {
    "PseudosRebelz6",
  };

  gotoxy(15,5);
  printf("---Log-In System---");

  gotoxy(15,7);
  printf("Student Number: ");

  gets(buffer);
  gets(usernameG);

  gotoxy(15,8);
  printf("Password: ");

  while (p != 13) {
    p = getch();
    if (p != 13) {
      putch('*');
      password[s] = p;
      s++;
    }
  }
  password[s] = '\0';

    if(strcmp(tUsername1, usernameG) == 0){
      if(strcmp(tPassword1, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername2, usernameG) == 0){
      if(strcmp(tPassword2, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername3, usernameG) == 0){
      if(strcmp(tPassword3, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername4, usernameG) == 0){
      if(strcmp(tPassword4, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername5, usernameG) == 0){
      if(strcmp(tPassword5, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername6, usernameG) == 0){
      if(strcmp(tPassword6, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }

}

void studentSecurity1(){

  system("cls");
  int s = 0;
  char username[20], password[20], p, buffer[5];
  char tUsername1[20] = {
    "02220003438",
  };
  char tUsername2[20] = {
    "02220003439",
  };
    char tUsername3[20] = {
    "02220003440",
  };
  char tUsername4[20] = {
    "0220-1892-888",
  };
  char tUsername5[20] = {
    "02220003442",
  };
  char tUsername6[20] = {
    "02220003443",
  };
  char tPassword1[20] = {
    "PseudosRebelz1",
  };
  char tPassword2[20] = {
    "PseudosRebelz2",
  };
  char tPassword3[20] = {
    "PseudosRebelz3",
  };
  char tPassword4[20] = {
    "PseudosRebelz4",
  };
  char tPassword5[20] = {
    "PseudosRebelz5",
  };
  char tPassword6[20] = {
    "PseudosRebelz6",
  };

  gotoxy(15,5);
  printf("---Log-In System---");

  gotoxy(15,7);
  printf("Student Number: ");

  gets(username);

  gotoxy(15,8);
  printf("Password: ");

  while (p != 13) {
    p = getch();
    if (p != 13) {
      putch('*');
      password[s] = p;
      s++;
    }
  }
  password[s] = '\0';

    if(strcmp(tUsername1, usernameG) == 0){
      if(strcmp(tPassword1, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername2, usernameG) == 0){
      if(strcmp(tPassword2, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername3, usernameG) == 0){
      if(strcmp(tPassword3, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername4, usernameG) == 0){
      if(strcmp(tPassword4, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername5, usernameG) == 0){
      if(strcmp(tPassword5, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }else if(strcmp(tUsername6, usernameG) == 0){
      if(strcmp(tPassword6, password) == 0){
        gotoxy(15, 9);
        printf("Log-In Succesful.");
        sleep(2);
        loadingScreenStudent();
      }else{
        gotoxy(15, 9);
        printf("Invalid Account. Try Again.");
        getch();
        studentSecurity1();
      }
    }

}

void viewGrades(){
    system("cls");

    char student_number[20], response;
    int status = 1, subStatus = 1;

    FILE *fp;
    struct bscs_ya1_list std;

    while(status != 0){
        subStatus = 1;
        gotoxy(15,5);
        printf("---View Student Grades---");
        fp = fopen("BSCS_1-YA-1_Student_List.txt","rb+");
        if(fp == NULL){
            gotoxy(15,9);
            printf("Error opening file");
            exit(1);
        }
        rewind(fp);
        fflush(stdin);
        while(fread(&std,sizeof(std),1,fp) == 1)
        {
            if(strcmp(usernameG,std.studentNumber) == 0){
                gotoxy(15,7);
                printf("-------------------------------------------");
                gotoxy(15,9);
                printf("Name: %s, %s", std.lastname, std.firstname);
                gotoxy(15,11);
                printf("Prelim Grade: %s", std.prelim);
                gotoxy(15,12);
                printf("Midterm Grade: %s", std.midterm);
                gotoxy(15,13);
                printf("Finals Grade: %s", std.finals);
                fseek(fp ,-sizeof(std),SEEK_CUR);
                fwrite(&std,sizeof(std),1,fp);
                break;
            }
        }
        fclose(fp);

        gotoxy(15,15);
        printf("Press any key to continue...");
        getch();
        studentMenu();
    }
}

void viewAcademicCalendar(){
    system("cls");
    printf("This is View Academic Calendar");
}

void studentMenu(){
    system("cls");

    int choice, status = 1;

    while(status != 0){
        gotoxy(15,5);
        printf("---Student Menu---");

        gotoxy(15,7);
        printf("1. Record Attendance");
        gotoxy(15,8);
        printf("2. View Attendance Sheet");
        gotoxy(15,9);
        printf("3. View Grades");
        gotoxy(15,11);
        printf("4. Back to Home Screen");

        gotoxy(15,13);
        scanf("%d", &choice);

        switch(choice){
            case 1:
                recordAttendance();
                break;
            case 2:
                system("cls");
                viewAttendanceSheetS();
                break;
            case 3:
                studentSecurity();
                break;
            case 4:
                main();
                break;
            default:
                gotoxy(15,14);
                printf("Invalid Input. Try Again");
                getch();
                system("cls");
                continue;
        }
    }
}


int main()
{
    system("cls");

    int choice, status = 1;
    char buffer;

    gotoxy(20,5);
    printf("---Student Management System---");
    gotoxy(23,7);
    printf("Press any key to continue ");
    getch();

    while(status != 0){

        system("cls");
        gotoxy(15,5);
        printf("Proceed as:");
        gotoxy(15,7);
        printf("1. Teacher");
        gotoxy(15,8);
        printf("2. Student");
        gotoxy(15,9);
        printf("3. Exit the program");

        gotoxy(15,11);
        scanf("%d", &choice);

        switch(choice){
            case 1:
                gets(buffer);
                teacherSecurity();
                status = 0;
                break;
            case 2:
                studentMenu();
                status = 0;
                break;
            case 3:
                system("cls");
                exit(1);
                break;
            default:
                printf("\n\n\nUnknown Command. Try Again.");
                system("cls");
                sleep(2);
                break;
        }
    }

    return 0;
}

void bscs_ya1(){
    FILE *fp;
    struct student std;

    fp = fopen("BSCS_1-YA-1_Attendance_Form.txt", "ab+");
        fflush(stdin);
        fwrite(&std,sizeof(std),1,fp);
        fflush(stdin);
}

void bscs_ya2(){
    FILE *fp;
    struct student std;

    fp = fopen("BSCS_1-YA-2_Attendance_Form.txt", "ab+");
        fflush(stdin);
        fwrite(&std,sizeof(std),1,fp);
        fflush(stdin);
}

void gotoxy(int x,int y){
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
