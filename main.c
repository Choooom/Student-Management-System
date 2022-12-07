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

struct student{

    char studentNumber[50];
    char firstname[50];
    char lastname[50];
    char vaccinationStatus[50];
    char contactNumber[15];
    char arrivalTime[50];

};

void teacherMenu(){

    int choice;

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
    printf("5. Exit");

    gotoxy(15,13);
    scanf("%d", &choice);

    switch(choice){
        case 1:
            viewAttendanceSheetT();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            exit(1);
            break;
    }
}

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

void teacherSecurity1(){

  system("cls");
  int s = 0;
  char username[20], password[20], p, buffer[5];
  char tUsername[20] = {
    "Sheinn Reyes"
  };
  char tPassword[20] = {
    "PseudosRebelz"
  };

  gotoxy(15,5);
  printf("Log-In System");

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

    if(strcmp(tUsername, username) == 0){
      if(strcmp(tPassword, password) == 0){
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
    }else if(strcmp(tUsername, username) != 0){
        if(strcmp(tPassword, password) == 0){
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

void teacherSecurity(){

  system("cls");
  int s = 0;
  char username[20], password[20], p, buffer[5];
  char tUsername[20] = {
    "Sheinn Reyes"
  };
  char tPassword[20] = {
    "PseudosRebelz"
  };

  gotoxy(15,5);
  printf("Log-In System");

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

    if(strcmp(tUsername, username) == 0){
      if(strcmp(tPassword, password) == 0){
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
    }else if(strcmp(tUsername, username) != 0){
        if(strcmp(tPassword, password) == 0){
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
    printf("Student No.        Name of Student        Vaccination Status       Time of Arrival");
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
                    studentMenu();
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
                studentMenu();

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
                    studentMenu();
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
                studentMenu();

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
                    studentMenu();
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
                studentMenu();

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
                    studentMenu();
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
                studentMenu();

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

void viewGrades(){
    system("cls");
    printf("This is View Grades");
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
        gotoxy(15,10);
        printf("4. View Academic Calendar");
        gotoxy(15,11);
        printf("5. Exit");

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
                viewGrades();
                break;
            case 4:
                viewAcademicCalendar();
                break;
            case 5:
                exit(1);
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


        gotoxy(15,10);
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
