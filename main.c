#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int,int);

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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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
    printf("This is Record Attendance");
}

void viewAttendanceSheet(){
    system("cls");
    printf("This is View Attendance Sheet");
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

    int choice;

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
            viewAttendanceSheet();
            break;
        case 3:
            viewGrades();
            break;
        case 4:
            viewAcademicCalendar();
            break;
        case 5:
            break;
        default:
            gotoxy(15,14);
            printf("Invalid Input. Try Again");
            getch();
            studentMenu();
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
        printf("");
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
                gotoxy(15, 10);
                printf("Unknown Command. Try Again.");
                sleep(3);
                system("cls");
                break;
        }

    return 0;
    }
}

void gotoxy(int x,int y){
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


