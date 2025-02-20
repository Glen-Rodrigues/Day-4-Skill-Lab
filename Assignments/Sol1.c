#include <stdio.h>

struct student
{
    int roll_no, marks;
    char name[50], course[100];
};
typedef struct student st;

void readStudents(st s[], int n)
{
    printf ("Enter details (Roll No, Name, Course, Marks):\n");
    for (int i=0; i<n; i++)
    {
        printf ("Student %d: ", i+1);
        scanf ("%d %s %s %d", &s[i].roll_no, s[i].name, s[i].course, &s[i].marks);
    }
}

void saveStudents(st s[], int n)
{
    FILE* file = fopen ("Students.txt", "w");
    if (file == NULL)
    {
        printf ("Error in creating file.\n");
        return;
    }
    for (int i=0; i<n; i++)
        fprintf (file, "%d %s %s %d\n", s[i].roll_no, s[i].name, s[i].course, s[i].marks);
    fclose (file);
    printf ("Record saved in Students.txt\n");
}

void searchStudent (st s[], int n)
{
    int rollno, flag=1;
    printf ("Enter Roll No to search: ");
    scanf ("%d", &rollno);
    for (int i=0; i<n; i++)
    {
        if (rollno == s[i].roll_no)
        {
            printf ("Student Found: %s, %s, Marks: %d\n", s[i].name, s[i].course, s[i].marks);
            flag = 0;
        }
    }
    if (flag)
        printf ("Student not found\n");
}

int main()
{
    int no_student;
    printf ("Enter number of students: ");
    scanf ("%d", &no_student);
    st students[100];
    readStudents (students, no_student);
    searchStudent (students, no_student);
    saveStudents (students, no_student);
    return 0;
}
