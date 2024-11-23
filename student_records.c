/* 
============================================================================ 
Name        : main.c 
Author      : <<<Shijun Li 041121986 >>>
Version     : Lab 4 
Description : structs in C, Ansi-style 
Status      : 
Builds clean; no warning(s)              : << true>>       
Requirement #1 - struct Student          : << complete  >>      
Requirement #2 - struct Course           : << complete >>       
Requirement #3 - typedef Course struct   : << complete  >>      
Requirement #4 - Prompt for number of students : << complete  >> 
Requirement #5 - Prompt for student information: << complete  >> 
Requirement #6 - Prompt for course information : << complete  >> 
Requirement #7 - Display registration          : << complete  >> 
============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_COURSE_CODE_LENGTH 8
#define MAX_COURSE_NAME_LENGTH 25
#define STUDENT_ID_LENGTH 5
#define LAST_CHAR 1
#define SUCCESS 0
#define FAIL 1
#define NAME_RESTRICTION 19
#define USER_INPUT_ID "0123456789"
#define COURSE_CODE 7
#define VALID_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
#define COURSE_NAME_LENGTH 24

typedef struct {
    char courseCode[MAX_COURSE_CODE_LENGTH];
    char courseName[MAX_COURSE_NAME_LENGTH];
} Course;

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int studentID;
    Course* course;
} Student;

void allocateMemory(Student** students, int numStudents) {
    *students = (Student*)malloc(numStudents * sizeof(Student));
    if (*students == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void allocateCourseMemory(Course** course) {
    *course = (Course*)malloc(sizeof(Course));
    if (*course == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void inputStudentInfo(Student* student, int studentNumber) {
    char inputBuffer[MAX_NAME_LENGTH + LAST_CHAR];
    int valid = SUCCESS;

    do {
        printf("Enter student #%d First Name :", studentNumber);
        if (scanf("%20s", inputBuffer) != FAIL) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }
        if (strlen(inputBuffer) > 0 && strlen(inputBuffer) <= NAME_RESTRICTION) {
            strcpy(student->firstName, inputBuffer);
            valid = FAIL;
        } else {
            printf("Invalid input, IT must be 19 characters or less.\n");
        }
        while (getchar() != '\n'); 
    } while (!valid);

    valid = SUCCESS;
    do {
        printf("Enter student Last Name : ");
        if (scanf("%20s", inputBuffer) != FAIL) {
            printf("Invalid input\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (strlen(inputBuffer) > 0 && strlen(inputBuffer) <= NAME_RESTRICTION) {
            strcpy(student->lastName, inputBuffer);
            valid = FAIL;
        } else {
            printf("Invalid input.\n");
        }
        while (getchar() != '\n'); 
    } while (!valid);

   valid = SUCCESS;
    do {
        char idBuffer[STUDENT_ID_LENGTH + 1];
        printf("Enter student ID  ");
        scanf("%20s", idBuffer);
        if (strlen(idBuffer) == STUDENT_ID_LENGTH && strspn(idBuffer, USER_INPUT_ID) == STUDENT_ID_LENGTH) {
            student->studentID = atoi(idBuffer);
            valid = FAIL;
        } else {
            printf("Invalid input\n");
        }
    } while (!valid);
}


void inputCourseInfo(Course* course) {
    char inputBuffer[MAX_COURSE_NAME_LENGTH + LAST_CHAR];
    int valid = SUCCESS;

    do {
        printf("Enter course code  ");
        if (scanf("%8s", inputBuffer) != FAIL) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        if (strlen(inputBuffer) <= COURSE_CODE && strspn(inputBuffer, VALID_CHARS) == strlen(inputBuffer)) {
            strcpy(course->courseCode, inputBuffer);
            valid = FAIL;
        } else {
            printf("Invalid input.\n");
        }
    } while (!valid);

    valid = SUCCESS;
   do {
    printf("Enter course name : ");
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
        printf("Invalid input.\n");
        continue;
    }
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 
    if (strlen(inputBuffer) > 0 && strlen(inputBuffer) <= COURSE_NAME_LENGTH) {
        strcpy(course->courseName, inputBuffer);
        valid = FAIL;
    } else {
        printf("Invalid input.\n");
    }
} while (!valid);
}

void displayStudents(Student* students, int numStudents) {
    int i;
    for (i = 0; i < numStudents; ++i) {
        printf("\nStudent Name: %s %s\n", students[i].firstName, students[i].lastName);
        printf("Student ID: %d\n", students[i].studentID);
        printf("Course Code: %s\n", students[i].course->courseCode);
        printf("Course Name: %s\n", students[i].course->courseName);
    }
}

void freeMemory(Student* students, int numStudents) {
    int i;
    for (i = 0; i < numStudents; ++i) {
        free(students[i].course);
    }
    free(students);
}

int main() {
    int numStudents;
    int i;
    Student* students;

  printf("How many students do you wish to enter: ");
    while (1) {
        if (scanf("%d", &numStudents) == 1 && numStudents > 0) {
            break;
        } else {
            printf("Invalid input:\nHow many students do you wish to enter:  ");
            while (getchar() != '\n'); 
        }
    }

    allocateMemory(&students, numStudents);

    for (i = 0; i < numStudents; ++i) {
        inputStudentInfo(&students[i], i + 1);
        allocateCourseMemory(&students[i].course);
        inputCourseInfo(students[i].course);
    }

    printf("\nStudent Registration Information:\n");
    displayStudents(students, numStudents);

    freeMemory(students, numStudents);

    return SUCCESS;
}