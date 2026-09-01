#include<stdio.h>
struct Student{
    int roll;
    char name[50];
    float marks;
};
int main(){
    int choice;
    int searchroll;
    struct Student students[100];
    int count=0;
    while(1){
    printf("===== Student Management System =====\n");
    printf("\n1. Add Student\n");
    printf("2. Display Student\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
switch(choice)
{
    case 1:{ 
            int duplicate=0;
            printf("Enter Roll number: ");
            scanf("%d",&students[count].roll);
            for(int i=0;i<count;i++){
                if(students[i].roll==students[count].roll){
                    duplicate=1;
                    break;
                }
            }
            if(duplicate==1){
                printf("\nroll number already exists!\n");
                break;
            }
            printf("Enter name: ");
            scanf("%s",students[count].name);
            do {
            printf("Enter marks(0-100): ");
            scanf("%f",&students[count].marks);
            if(students[count].marks<0||students[count].marks>100){
                printf("invalid marks! please enter marks between 0to 100");
            }
        }while (students[count].marks<0||students[count].marks>100);
            count++;
            printf("\nStudent Added Successfully!\n");
            break;
        }
    case 2: if(count==0)
            {
                printf("no student found\n");
            }
            else{
                printf("\n=====Student List=====\n");
                for(int i=0;i<count;i++)
                {
                    printf("\nroll number: %d\n",students[i].roll);
                    printf("\nname: %s\n",students[i].name);
                    printf("\nmarks: %f\n",students[i].marks);
                }
            }
            break;
    case 3: printf("Enter roll number to search: ");
            scanf("%d",&searchroll);
            int found=0;
            for(int i=0;i<count;i++){
                if(students[i].roll==searchroll){
                    printf("\nStudent found!\n");
                    printf("\nroll number: %d\n",students[i].roll);
                    printf("\nname: %s\n",students[i].name);
                    printf("\nmarks: %f\n",students[i].marks);
                found=1;
                break;    
                }
            }
            if(found==0){
                printf("\nStudent not found\n");
            }
            break;
    case 4: printf("Enter roll number to update: ");
            scanf("%d",&searchroll);
            int updated=0;
            for(int i=0;i<count;i++){
                if(students[i].roll==searchroll){
                    printf("\ncurrent details: \n");
                    printf("roll number: %d\n",students[i].roll);
                    printf("name: %s\n",students[i].name);
                    printf("marks: %f\n",students[i].marks);
                    printf("enter new name: ");
                    scanf("%s",students[i].name);
                    printf("enter new marks: ");
                    scanf("%f",&students[i].marks);
                    updated=1;
                    printf("\nStudent updated successfully!\n");
                    break;
                }
            }
            if(updated==0){
                printf("\nstudent not found!\n");
            }
            break;
    case 5: printf("Enter roll number to delete: ");
            scanf("%d",&searchroll);
            int founddelete=0;
            for(int i=0;i<count;i++){
                if(students[i].roll==searchroll){
                    for(int j=i;j<count-1;j++){
                        students[j]=students[j+1];
                    }
                    count=count-1;
                    founddelete=1;
                    printf("\nStudent deleted successfully!\n");
                    break;
                }
            }
            if(founddelete==0){
                printf("\nstudent not found!\n");
            }
            break;
    case 6: printf(" Thank You\n");
            return 0;
    default: printf("invalid choice\n");
}
    }
    return 0;
}