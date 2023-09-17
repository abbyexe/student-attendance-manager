/*
18. Student attendance management
To maintain attendance information of students, data structure Created: 
Student Structure 
a. Enrollment no. 
b. Name 
c. Mobile no.
d. 3 courses and corresponding student attendance of each course (total, Present, 
%age).{Hint 2D array} 5. Average attendance % 
Write a menu driven program for above data structure with separate and features: 
Menu: 
a. Insert Student
b. Update attendance of given Enrollment no. 
c. Update attendance of all student 
e. attendance() of all student: user select subject and then mark attendance 
Features: 
a. Maintain each student information in single node of doubly linked list. 
b. Start pointer always point to smallest % of attendance. 
c. Insert student in already sorted list with proper location 
d. After updating attendance of students all node will be in Sort on basis of Average 
attendance (increasing order)
e. Insert min 5 student information using menu option 1.
*/

#include <stdio.h>
#include <stdlib.h>

struct student 
{
    int enrollment;
    char name[30];
    char mobile[20];
    int attendance[3][3];
    float avg;
    struct student *next;
    struct student *prev;
}*temp, *p, *q, *r, *start; //global declaration

void insert() 
{
    temp = (struct student *)malloc(sizeof(struct student));
    printf("Enter Enrollment No.: ");
    scanf("%d", &temp->enrollment);
    printf("Enter Name: ");
    scanf("%s", temp->name);
    printf("Enter Mobile No.: ");
    scanf("%s", temp->mobile);
    printf("Enter Attendance of 3 courses: \n");

    for (int i = 0; i < 3; i++)
    {
        switch(i)
        {
            case 0: printf("For Physics: \n");
                    break;
            case 1: printf("For Chemistry: \n");
                    break;
            case 2: printf("For Maths: \n");
                    break;
        }
        printf("\tEnter Total Classes : ");
        scanf("%d", &temp->attendance[i][0]);
        printf("\tEnter Present Classes : ");
        scanf("%d", &temp->attendance[i][1]);
        temp->attendance[i][2] = temp->attendance[i][0] - temp->attendance[i][1];
        printf("\tAbsent Classes: %d\n", temp->attendance[i][2]);
    }
    temp->avg = 100 * (temp->attendance[0][1] + temp->attendance[1][1] + temp->attendance[2][1]) / (temp->attendance[0][0] + temp->attendance[1][0] + temp->attendance[2][0]);
    printf("Average Attendance: %0.2f\n", temp->avg);
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        p = start;
        q = p->next;
        while(q != NULL && temp->enrollment > q->enrollment)
        {
            p = q;
            q = q->next;
        }
        if (temp->enrollment < p->enrollment)
        {
            temp->next = p;
            p->prev = temp;
            start = temp;
        }
        else if (temp->enrollment > p->enrollment && q == NULL)
        {
            p->next = temp;
            temp->prev = p;
        }
        else
        {
            p->next = temp;
            temp->prev = p;
            temp->next = q;
            q->prev = temp;
        }
    }
}

void update()
{
    int enrollment;
    printf("Enter Enrollment No. to update: ");
    scanf("%d", &enrollment);
    p = start;
    while (p != NULL)
    {
        if (p->enrollment == enrollment)
        {
            printf("Enter Attendance of 3 courses: \n");

            for (int i = 0; i < 3; i++)
            {
                switch(i)
                {
                    case 0: printf("For Physics: \n");
                            break;
                    case 1: printf("For Chemistry: \n");
                            break;
                    case 2: printf("For Maths: \n");
                            break;
                }
                printf("\tEnter Total Classes : ");
                scanf("%d", &p->attendance[i][0]);
                printf("\tEnter Present Classes : ");
                scanf("%d", &p->attendance[i][1]);
                p->attendance[i][2] = p->attendance[i][0] - p->attendance[i][1];
                printf("\tAbsent Classes: %d\n", p->attendance[i][2]);
            }
            p->avg = 100 * (p->attendance[0][1] + p->attendance[1][1] + p->attendance[2][1]) / (p->attendance[0][0] + p->attendance[1][0] + p->attendance[2][0]);
            printf("Average Attendance: %0.2f\n", p->avg);
            break;
        }
        p = p->next;
    }
}

void updateAll()
{
    p = start;
    while (p != NULL)
    {
        printf("Student Enrollment No.: %d\n", p->enrollment);
        printf("Student Name: %s\n", p->name);
        printf("Enter Attendance of 3 courses: \n");

        for (int i = 0; i < 3; i++)
        {
            switch(i)
            {
                case 0: printf("For Physics: \n");
                        break;
                case 1: printf("For Chemistry: \n");
                        break;
                case 2: printf("For Maths: \n");
                        break;
            }
            printf("\tEnter Total Classes : ");
            scanf("%d", &p->attendance[i][0]);
            printf("\tEnter Present Classes : ");
            scanf("%d", &p->attendance[i][1]);
            p->attendance[i][2] = p->attendance[i][0] - p->attendance[i][1];
                printf("\tAbsent Classes: %d\n", p->attendance[i][2]);
        }
        p->avg = 100 * (p->attendance[0][1] + p->attendance[1][1] + p->attendance[2][1]) / (p->attendance[0][0] + p->attendance[1][0] + p->attendance[2][0]);
        printf("Average Attendance: %0.2f\n", p->avg);
        p = p->next;
    }
}

void attendance()
{
    printf("Select Subject: \n");
    printf("1. Physics\n");
    printf("2. Chemistry\n");
    printf("3. Maths\n");
    int choice;
    scanf("%d", &choice);
    p = start;
    while (p != NULL)
    {
        printf("\nStudent Name: %s\n", p->name);
        printf("Student Enrollment No.: %d\n", p->enrollment);
        printf("Enter P if present and A if absent: ");
        char ch;
        scanf(" %c", &ch);
        p->attendance[choice - 1][0]++;
        if (ch == 'P' || ch == 'p')
        {
            p->attendance[choice - 1][1]++;
        }
        else
        {
            p->attendance[choice - 1][2]++;
        }
        p->avg = 100 * (p->attendance[0][1] + p->attendance[1][1] + p->attendance[2][1]) / (p->attendance[0][0] + p->attendance[1][0] + p->attendance[2][0]);
        p = p->next;
    }
}



void display()
{
    p = start;
    while (p != NULL)
    {
        printf("Enrollment No.: %d\n", p->enrollment);
        printf("Name: %s\n", p->name);
        printf("Mobile No.: %s\n", p->mobile);
        printf("Attendance of 3 courses: \n");
        for (int i = 0; i < 3; i++)
        {
            switch(i)
            {
                case 0: printf("\tFor Physics: \n");
                        break;
                case 1: printf("\tFor Chemistry: \n");
                        break;
                case 2: printf("\tFor Maths: \n");
                        break;
            }
            printf("\t\tTotal Classes: %d", p->attendance[i][0]);
            printf("\t\tPresent Classes: %d", p->attendance[i][1]);
            printf("\t\tAbsent Classes: %d\n", p->attendance[i][2]);
        }
        printf("Average Attendance: %0.2f\n\n", p->avg);
        p = p->next;
    }
}

void search()
{
    int enrollment;
    printf("Enter Enrollment No. to search: ");
    scanf("%d", &enrollment);
    p = start;
    while (p != NULL)
    {
        if (p->enrollment == enrollment)
        {
            printf("Enrollment No.: %d\n", p->enrollment);
        printf("Name: %s\n", p->name);
        printf("Mobile No.: %s\n", p->mobile);
        printf("Attendance of 3 courses: \n");
        for (int i = 0; i < 3; i++)
        {
            switch(i)
            {
                case 0: printf("\tFor Physics: \n");
                        break;
                case 1: printf("\tFor Chemistry: \n");
                        break;
                case 2: printf("\tFor Maths: \n");
                        break;
            }
            printf("\t\tTotal Classes: %d", p->attendance[i][0]);
            printf("\t\tPresent Classes: %d", p->attendance[i][1]);
            printf("\t\tAbsent Classes: %d\n", p->attendance[i][2]);
        }
        printf("Average Attendance: %0.2f\n\n", p->avg);
            break;
        }
        p = p->next;
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n\nEnter your choice: \n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Update All\n");
        printf("6. Attendance\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: display();
                    break;
            case 3: search();
                    break;
            case 4: update();
                    break;
            case 5: updateAll();
                    break;
            case 6: attendance();
                    break;
            case 7: exit(0);
            default: printf("Invalid Choice");
        }
    }
}