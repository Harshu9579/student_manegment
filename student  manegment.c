#include<stdio.h>
#include<stdlib.h>
struct student{
char name[30];
char course[20];
int id;
int birth_date;
int score;
  }s;
  FILE *fp;
  long sz = sizeof(s);
int main(){
int ch;
while(1){
system("cls");
printf("<==SINHAGAD EDUCATIONAL INSTITUTION==>\n");
printf("1.Admission\n");
printf("2.student informetion\n");
printf("3.search\n");
printf("4.update\n");
printf("5.delete\n");
printf("6.sort by id\n");
printf("0.exit\n");
printf("enter your choice:");
scanf("%d",&ch);


switch(ch){
case 0:
    exit(0);
case 1:
    input();
    break;
case 2:
display();
    break;
case 3:
    search();
    break;
case 4:
    update();
    break;
case 5:
    del();
    break;
case 6:
    sort();
    break;

    }
printf("\npress key");
getch();

}
return 0;
}
void input(){
    fp = fopen("stud.txt","ab");
    printf("enter the name\n");
    fflush(stdin);
    gets(s.name);
    printf("enter the course\n");
    fflush(stdin);
    gets(s.course);
    printf("enter student id\n");
    scanf("%d",&s.id);
    printf("enter the score\n");
    scanf("%d",&s.score);
    printf("enter the birth date\n");
    scanf("%d",&s.birth_date);
    fwrite(&s,sz,1,fp);
    printf("record saved\n");
    fclose(fp);
}

void display(){
    system("cls");
    printf("<==student informetion==>");
    printf("%-40s %-30s %-20s %-10s %d\n","name","cours","id","score","birth_date");
    fp = fopen("stud.txt","rb");
    while(fread(&s,sz,1,fp)==1){
            printf("%-40s %-30s %-20s %-10s %d\n",s.name,s.course,s.id,s.score,s.birth_date);
        }
    fclose(fp);
}
void search(){
int ch;
while(1){
    system("cls");
    printf("<==search==>\n");
    printf("1.search by id\n");
    printf("2.search by name\n");
    printf("0.back to main menu\n");
    printf("\n\nenter your choice");

    switch(ch)
    {
    case 0:
    main();
    break;
    case 1:
        searchbyid();
        break;
    case 2:
        searchbyname();
        break;
    default:
        printf("wrong choies");
    }
    getch();
    }
}
void searchbyid(){
int id ,f=0;
printf("enter the id search");
scanf("%d",&id);
printf("%-40s %-30s %-20s %-10s %d\n","name","cours","id","score","birth_date");
fp = fopen("stud.txt","rb");
while(fread(&s,sz,1,fp)==1){
        if(id==s.id){
            f=1;
            printf("%-40s %-30s %-20s %-10s %d\n",s.name,s.course,s.id,s.score,s.birth_date);
            break;
        }


}
fclose(fp);
if(f==0){
    printf("record not found");

}else{

printf("record found successsfully");
}
}
void searchbyname(){
char name[30];
int f=0;
printf("enter the name search");
fflush(stdin);
gets(name);
printf("%-40s %-30s %-20s %-10s %d\n","name","cours","id","score","birth_date");
fp = fopen("stud.txt","rb");
while(fread(&s,sz,1,fp)==1){
        if(strcmpi(name,s.name)==0){
            f=1;
            printf("%-40s %-30s %-20s %-10s %d\n",s.name,s.course,s.id,s.score,s.birth_date);
            break;
        }


}
fclose(fp);
if(f==0){
    printf("record not found");

}else{
printf("record found successsfully");
}
}
void update(){
    int id ,f=0;
printf("enter the id update");
scanf("%d",&id);

fp = fopen("stud.txt","rb+");
while(fread(&s,sz,1,fp)==1){
        if(id==s.id){
            f=1;
             printf("enter the  new name\n");
    fflush(stdin);
    gets(s.name);
    printf("enter the  new course\n");
    fflush(stdin);
    gets(s.course);
    printf("enter new student id\n");
    scanf("%d",&s.id);
    printf("enter the new score\n");
    scanf("%d",&s.score);
    printf("enter the birth date\n");
    scanf("%d",&s.birth_date);
    fseek(fp,-sz,1);
    fwrite(&s,sz,1,fp);
    fclose(fp);
    break;
        }


}

if(f==0){
    printf("record not update");

}else{

printf("record updated successsfully");
}
}
void del(){
    int id ,f=0;
printf("enter the id delete");
scanf("%d",&id);
FILE *ft;

fp = fopen("stud.txt","rb");
ft= fopen("temp.txt","ab");
while(fread(&s,sz,1,fp)==1)
        if(id==s.id){
            f=1;

        }else{

        fwrite(&s,sz,1,ft);
        }


fclose(fp);
fclose(ft);
remove("stud.txt");
rename("temp.txt","stud.txt");
if(f==0){
    printf("record not update");

}else{

printf("record delete successsfully");
}


        }

void sort(){

    int  c=0,i,j;
    struct student s1[50],t;
    system("cls");
    printf("<==sort by id==>");
    printf("%-40s %-30s %-20s %-10s %d\n","name","cours","id","score","birth_date");
    fp = fopen("stud.txt","rb");
    while(fread(&s,sz,1,fp)==1){
            s1[c++] = s;
        }
        for(i=0;i<c-1;i++){
            for(j=i+1;j<c;j++){
                if(s1[i].id>s1[j].id){
                    t = s1[i];
                    s1[i]=s1[j];
                    s1[j]=t;
                }
            }
        }
        for(i=0; i<c;i++)

        printf("%-40s %-30s %-20s %-10s %d\n",s1[i].name,s1[i].course,s1[i].id,s1[i].score,s1[i].birth_date);
    fclose(fp);

}

