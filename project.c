#include <stdio.h>
#include <stdlib.h>

typedef struct ToDo todo;

struct ToDo{
 char data[100];
 todo *link;
 int count;
};

todo *start=NULL;
todo *temp=NULL;
int main()
{

    int choice;
    welcomeUser();
    login();

    while(1){
        system("color 3F");
        system("cls");
        printf("\n1.See Your ToDo List");
        printf("\n2.Create Your ToDos");
        printf("\n3.Delete Your ToDos");
        printf("\n4.Update Your ToDos");
        printf("\n5.Exit");
        printf("\n\nEnter your choice..");
        scanf("%d",&choice);
        switch(choice){
      case 1:
          seeToDo();
        break;
      case 2:
          createToDo();
        break;
      case 3:
          delToDo();
        break;
      case 4:
         updateToDo();
         break;
      case 5 :
          exit(0);
        break;
        }
    //AT END OF PROGRAM TO DO LIST IS PRINTED INTO A FILE :)

      writeToFile();
    }



}
void login(){
    {
        system("cls");
        system("color A");
        printf("\n\n\n\t\t********************** LOGIN PAGE ********************\n\n");
        printf("\n\tLOGIN :\n\n");
        char id[50];
         User:

        printf("Enter your id:\n");
       scanf("%s", &id);
      if (strcmp(id,"admin")==0)
        {
  printf("correct ID \n");
      }
     else
       {
        printf("\nINVALID User ID:(   \n_________________________________________________");
        printf("Enter your User ID again\n\n");
        goto User;
         }
      char pass[50];
        pass:
      printf("Enter your password: ");
      scanf("%s", &pass);
      if(strcmp(pass,"admin123")==0)
        {
        printf("You have successly loged in into To-do list App !..\n");
        }
    else
     {
     printf("\n INVALID PASSWORD :(   \n_________________________________________________");
     printf("Enter your password again\n\n");
     goto pass;
     }
     return 0;
      system("pause");
       }
      }

void writeToFile()

{
    printf("Printing the details into the file named 'To Do list.txt' ");
    todo* temp=start;
    FILE * fptr;
    fptr = fopen("To Do list .txt", "w+");//Tod lidt



    if(fptr==NULL)
    {
        printf("Error\n");
    }

    else
    {
        printf("file open and printed ");
        fputs("To do list app :\n \n ", fptr) ;
        fprintf(fptr,"%s","printing...\n" );
        while(temp != NULL)
        {


            fprintf(fptr, "%s \n", temp->data);
            temp= temp->link;
        }
    }

    fclose(fptr);
    }



void welcomeUser(){
   system("color 4F");
   printf("\n\n\n\n\n");

   printf("\t------------------------------------------------------------------------------------------------------\n\n");
   printf("\t#################################### YOUR TODO LIST APP ##############################################\n\n");
   printf("\t------------------------------------------------------------------------------------------------------");
   printf("\n\n\n\t\t*******************************WELCOME*******************************\n\n\n\n\n\n\n\n\n\t");
   system("pause");
}

void seeToDo(){
   system("cls");
   system("color 70");
   printf("\t\t Displaying the TO-DO list :\n");

   temp=start;
        if(start==NULL){
           printf("\nEmpty TODO\n\n");
        }

       while(temp!=NULL){
          printf("%d)",temp->count);
          puts(temp->data);
          fflush(stdin);
          temp=temp->link;
       }
       printf("\n\n\n");
       system("pause");
   }

void createToDo(){
    char k;
    todo *t,*temp;
    system("cls");
    while(1){
        printf("\nWant to add?y/n");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       else{
        if(start==NULL){
        t=(todo *)calloc(1,sizeof(todo));
        start=t;
        printf("\nADD it..\n");
        fflush(stdin);
        gets(t->data);
        t->count=1;
        start->link=NULL;
       }
       else{
       temp=(todo *)calloc(1,sizeof(todo));
       printf("\nADD it..\n");
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t->link=temp;
       t=t->link;
     }
     fixcount();
    }
   }
}

void delToDo(){
  system("cls");
  int d;
  todo *temp1,*temp;
  printf("\nEnter the no of the todo you want to remove\n");
  scanf("%d",&d);
  temp1=start;
  temp=start->link;
  while(1){
  if(temp1->count==d){
    start=start->link;
    free(temp1);
    fixcount();
    break;
  }
    if(temp->count==d){
        temp1->link=temp->link;
        free(temp);
        fixcount();
        break;
    }
    else{
        temp1=temp;
        temp=temp->link;
    }
}
system("pause");
}

void fixcount(){
  todo *temp;
  int i=1;
  temp=start;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }
}

void updateToDo(){
  system("cls");
  todo *temp,*t;
  char k;
  while(1){
        printf("\nWant to add?y/n");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       printf("\nADD it..\n");
       temp=(todo *)calloc(1,sizeof(todo));
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t=start;
      while(t->link!=NULL){
        t=t->link;
      }
      t->link=temp;
      fixcount();
}
printf("\n\n");
system("pause");
}
