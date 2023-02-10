#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Grade {A,Am,B,Bm,C,Cm} Grade;

typedef struct Student {
  char email[100];
  int assigment1;
  int assigment2;
  int midsem;
  int endsem;
  Grade grade;
} Student;

typedef struct Database {
  Student students[300];
  int count_students;
} Database;

float compute_total_marks(Student s) {
/* Problem 2.1: write code here, for computing the 
total marks for a student and returning it. 
Assume that
assignment marks were out of 100, midsem marks 
were out of 50 and endsem marks were out of 80. 
The best 1 score amoung the 2 assignments will 
only be taken. The weightage for the total marks 
is 30% from assignment, 30% from midsem and 40% 
from endsem. (2 marks)
*/
  int assignment_mark = s.assigment1 > s.assigment2? s.assigment1 : s.assigment2;
  float total_marks = 30.0*((float)assignment_mark)/100.0 
                      + 30.0*((float)s.midsem)/50.0
                      + 40.0*((float)s.endsem)/80.0;
  return total_marks;
}

void compute_grades(Database* db) {
/* Problem 2.2: Assume that grades are given as 
follows: >= 90: A, between 90 and 80: Am,
between 70 and 80: B, between 60 and 70: Bm,
between 50 and 60: C, between 40 and 50: Cm.
Write code here to assign grades to each 
student, and save it in the `grade` field of the
`Student`. (2 marks)
*/
  for (int i = 0; i < db->count_students; i++) {
    float total_marks = compute_total_marks(db->students[i]);
    if (total_marks >= 90.0) {
      db->students[i].grade = A;
    } else if (total_marks >= 80.0) {
            db->students[i].grade = Am;
    } else if (total_marks >= 70.0) {
            db->students[i].grade = B;
    } else if (total_marks >= 60.0) {
            db->students[i].grade = Bm;
    } else if (total_marks >= 50.0) {
            db->students[i].grade = C;
    } else if (total_marks >= 40.0) {
            db->students[i].grade = Cm;
    }
  }
}

int main(int argc, char* argv[]) {
  Database db;
  /* Problem 2.3: Suppose the a.out is run with the 
  first argument as the name of the `.csv` file. 
  For example `./a.out marks.csv`. Write code here, 
  that will read all the data from the `.csv` file 
  and populate the Database `db`.  (3 marks)
  */
  FILE* marks = fopen(argv[1], "r");
  if (marks == NULL) {
    printf("Marks file provided \"%s\" is invalid.", argv[1]);
    return 0;
  } 
  char line[200];
  fgets(line, 200, marks);
  int i = 0;
  for (; i < 300; i++) {
    // printf("%d",i);
    int a = fscanf(marks, "%s ,%d,%d,%d,%d\n", db.students[i].email, &(db.students[i].assigment1),&(db.students[i].assigment2),&(db.students[i].midsem),&(db.students[i].endsem));
    if (a != 5) break;
  }
  db.count_students = i;
  fclose(marks);
  // printf("%d",i);
  

  compute_grades(&db);
/* Problem 2.4: Suppose the a.out is run with the 
second argument as the name of the `.csv` file for 
grades. 
For example `./a.out marks.csv grades.csv`. 
Write code here, open the file with name given by
second argument, and write the grades.  (3 marks)
*/
  FILE* grades = fopen(argv[2], "w"); 
  if (grades == NULL) {
    printf("Grades file provided \"%s\" is invalid.", argv[2]);
    return 0;
  }
  char grades_line[200] = "email,total_marks,grade\n";
  fputs(grades_line, grades);
  i = 0;
  for (; i < db.count_students; i++) {
    char grade_string[3];
    switch (db.students[i].grade)
    {
    case A:
      strcpy(grade_string, "A");
      break;
    case Am:
      strcpy(grade_string, "A-");
      break;
    case B:
      strcpy(grade_string, "B");
      break;
    case Bm:
      strcpy(grade_string, "B-");
      break;
    case C:
      strcpy(grade_string, "C");
      break;
    case Cm:
      strcpy(grade_string, "C-");
      break;
    default:
      break;
    }
    fprintf(grades, "%s ,%f,%s\n", db.students[i].email, compute_total_marks(db.students[i]), grade_string);
  }
  db.count_students = i;
  fclose(grades);


}