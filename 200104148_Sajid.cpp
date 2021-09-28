#include<stdio.h>
#include<string.h>

typedef struct student student;
struct student
{
    int id;
    char name[30];
    float total_gpa;
    float hsc;
    float ssc;
};

//File f1 for student data ==>File f2 for Total GPA ==>File f3 for SSC GPA ==>File f4 for HSC GPA

int main()
{
    FILE *f1 = fopen("student_data.txt", "r");
    student st[5];
    student temp[5];

    int i=0;
    char c[10], c1[10], c2[10], c3[10], c4[10];
    while(!feof(f1))
    {
        fscanf(f1,"%s %d %s %s %s %f %s %f %s %f\n",&c,&st[i].id,&c1,&st[i].name,&c2,&st[i].total_gpa,&c3,&st[i].hsc,&c4,&st[i].ssc);
        i++;
    }
    fclose(f1);
//sorting
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4-i; j++)
        {
            if(st[j].total_gpa<st[j+1].total_gpa)
            {
                temp[j]=st[j];
                st[j]=st[j+1];
                st[j+1]=temp[j];
            }
        }
    }

    FILE *f2 = fopen("total_gpa_analysis.txt", "w");
    fprintf(f2,"\nTotal GPA Analysis\n------------------\n");
    fclose(f2);
    f2 = fopen("total_gpa_analysis.txt", "a");
    for(int i=0; i<4; i++)
    {
        fprintf(f2,"\nTotal GPA :%.2f\n================\n",st[i].total_gpa);
        for(int j=i+1; j<5; j++)
        {
            if(st[i].total_gpa==st[j].total_gpa)
                fprintf(f2,"ID:%d Name:%s\n",st[j].id,st[j].name);
        }
        fprintf(f2,"ID:%d Name:%s\n",st[i].id,st[i].name);
    }
    fclose(f2);

    FILE *f3 = fopen("ssc_gpa_analysis.txt", "w");
    fprintf(f3,"\nSSC GPA Analysis\n----------------\n");
    fclose(f3);
    f3 = fopen("ssc_gpa_analysis.txt", "a");
    for(int i=0; i<5; i++)
    {
        if(st[i].ssc!=0)
        {
            fprintf(f3,"\nSSC GPA :%.2f\n=============\n",st[i].ssc);
            for(int j=i+1; j<5; j++)
            {
                if(st[i].ssc==st[j].ssc)
                {
                    fprintf(f3,"ID:%d Name:%s\n",st[j].id,st[j].name);
                    st[j].ssc=0;
                }
            }
            fprintf(f3,"ID:%d Name:%s\n",st[i].id,st[i].name);
        }
    }
    fclose(f3);

    FILE *f4 = fopen("hsc_gpa_analysis.txt", "w");
    fprintf(f4,"\nHSC GPA Analysis\n----------------\n");
    fclose(f4);
    f4 = fopen("hsc_gpa_analysis.txt", "a");
    for(int i=0; i<4; i++)
    {
        if(st[i].hsc!=0)
        {
            fprintf(f4,"\nHSC GPA :%.2f\n==============\n\n",st[i].hsc);
            for(int j=i+1; j<5; j++)
            {
                if(st[i].hsc==st[j].hsc)
                {
                    fprintf(f4,"ID:%d Name:%s\n",st[j].id,st[j].name);
                    st[j].hsc=0;
                }
            }
            fprintf(f4,"ID:%d Name:%s\n",st[i].id,st[i].name);
        }
    }
    fclose(f4);

    f1 = fopen("student_data.txt", "a");
    f2 = fopen("total_gpa_analysis.txt", "r");
    f3 = fopen("ssc_gpa_analysis.txt", "r");
    f4 = fopen("hsc_gpa_analysis.txt", "r");

    char ch;
    while((ch=fgetc(f2))!=EOF)
        fputc(ch,f1);
    while((ch=fgetc(f3))!=EOF)
        fputc(ch,f1);
    while((ch=fgetc(f4))!=EOF)
        fputc(ch,f1);

    fclose(f4);
    fclose(f3);
    fclose(f2);
    fclose(f1);

    f1 = fopen("student_data.txt", "r");
     while(!feof(f1))
     {
         char x=fgetc(f1);
         printf("%c",x);
     }
     fclose(f1);
    return 0;
}
