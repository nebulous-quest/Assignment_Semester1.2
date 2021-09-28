#include<stdio.h>
#include<string.h>

typedef struct users users;
struct users
{
    int id;
    char name[50];
    char email[30];
    char pass[30];
};

typedef struct students students;
struct students
{
    users students;
    float cg;
};


typedef struct teachers teachers;
struct teachers
{
    users teachers;
    char designation[30];
};

//Find user
int findUser(users u1,users u2)  //u1=s_arr[],u2=user input for login
{
    int t1,t2;
    t1=strcmp(u1.email,u2.email);
    t2=strcmp(u1.pass,u2.pass);
    if(t1==0 && t2==0)
    {
        return 1;
    }
    else
        return 0;
}

//Function for students and teachers output
void print_s(students s,int a)
{
    printf("ID: %d\n",a+1);
    printf("Name: %s\n",s.students.name);
    printf("Email: %s\n",s.students.email);
    printf("Pass: %s\n",s.students.pass);
    printf("CGPA: %f\n",s.cg);
}

void print_t(teachers t,int b)
{
    printf("ID: %d",b+1);
    printf("Name: %s",t.teachers.name);
    printf("Email: %s",t.teachers.email);
    printf("Designation: %S",t.designation);
}
int display()
{
    int p;
    printf("Login as: 1.Student  2.Teacher\n");
    scanf("%d",&p);
    return p;
}
int option()
{
    int v;
    printf("1.See all Students\n2.See All Teachers\n3.Edit Student\n4.Logout\n5.Exit\n");
    scanf("%d",&v);
    return v;
}

int main()
{
    int s,t;

    printf("How many students: ");
    scanf("%d",&s);
    printf("How many teachers: ");
    scanf("%d",&t);
    students s_arr[s];
    teachers t_arr[t];
//Take student input
    if(s!=0)
    {
        printf("\nEnter student information:\n");
        for(int i=0; i<s; i++)
        {
            printf("\nName: ");
            fflush(stdin);
            scanf("%s",&s_arr[i].students.name);
            printf("Email:");
            scanf("%s",&s_arr[i].students.email);
            printf("Pass:");
            scanf("%s",&s_arr[i].students.pass);
            printf("CGPA:");
            scanf("%f",&s_arr[i].cg);
            printf("\n");
        }
    }
//Take teachers input
    if(t!=0)
    {
        printf("\nEnter teachers information:\n");
        for(int i=0; i<t; i++)
        {
            printf("\nName: ");
            fflush(stdin);
            scanf("%s",&t_arr[i].teachers.name);
            printf("Email:");
            scanf("%s",&t_arr[i].teachers.email);
            printf("Pass:");
            scanf("%s",&t_arr[i].teachers.pass);
            printf("Designation:");
            scanf("%s",&t_arr[i].designation);
            printf("\n");
        }
    }

jump:
    int x=display();//call display function for login option
    fflush(stdin);
    users user;
    int vary;
    switch(x)
    {
    case 1:
    {
        printf("\nEmail:");
        gets(user.email);
        fflush(stdin);
        printf("Pass:");
        gets(user.pass);
        fflush(stdin);
        for(int i=0; i<s; i++)
        {
            if(findUser(s_arr[i].students,user)==1) //call finduser fucntion for check right person
            {
                printf("Login Successful!\n");
                vary=i;
                if(findUser(s_arr[i].students,user)==0)
                    goto jump;
            }
        }

        int y;//y for option no
        printf("\nOptions:\n1.See details\n2.Logout\n3.Exit\n");
        scanf("%d",&y);
        if(y==1)
        {
            printf("\nStudent Details:\n");
            for(int i=vary; i<s; i++)
            {
                printf("ID: %d\n",i+1);
                printf("Name: %s\n",s_arr[vary].students.name);
                printf("Email: %s\n",s_arr[vary].students.email);
                printf("Pass: %s\n",s_arr[vary].students.pass);
                printf("CGPA: %.4f\n",s_arr[vary].cg);
            }
            goto jump;
        }
        else if(y==2)
            goto jump;
        else
            return 0;
        break;
    }
    case 2:
    {
        printf("\nEmail:");
        gets(user.email);
        fflush(stdin);
        printf("Pass:");
        gets(user.pass);
        fflush(stdin);

        for(int i=0; i<t; i++)
        {
            if(findUser(t_arr[i].teachers,user)==1)  //call finduser fucntion for check right person
            {
                printf("Login Successful!\n");
                vary=i;
                if(findUser(t_arr[i].teachers,user)==0)
                    goto jump;
            }
        }

jump1:
        int y=option();//y for option no
        if(y==1)
        {
            printf("\nAll Students:\n");
            for(int i=0; i<s; i++)
            {
                print_s(s_arr[i],i);
                printf("\n");
            }
            goto jump1;
        }
        else if(y==2)
        {
            printf("\nAll Teachers info:\n");
            for(int i=0; i<t; i++)
            {
                print_t(t_arr[i],i);
                printf("\n");
            }
            goto jump1;
        }
        else if(y==3)
        {
            int id;
            printf("\nEnter student ID: ");
            scanf("%d",&id);
            fflush(stdin);
            printf("Enter new name: ");
            gets(s_arr[id-1].students.name);
            fflush(stdin);
            goto jump1;
        }
        else if(y==4)
            goto jump1;
        else
            return 0;
        break;
    }

    }
}
