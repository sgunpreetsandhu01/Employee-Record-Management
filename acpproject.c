#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int id;
    char name[20];
    char gender[10];
    char designation[10];
    char address[30];
    int phone_number;
    int salary;
    struct node *next;
};
struct node *head=NULL,*temp,*newnode;
void create_node()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the id: ");
    scanf("%d",&newnode->id);
    fflush(stdin);
    printf("Enter the name of employee: ");
    gets(newnode->name);
    printf("Enter the gender of the employee: ");
    gets(newnode->gender);
    printf("Enter the designation of the employee: ");
    gets(newnode->designation);
    printf("Enter the address of the employee: ");
    gets(newnode->address);
    fflush(stdin);
    printf("Enter the phone number of the employee: ");
    scanf("%d",&newnode->phone_number);
    printf("Enter the salary of the employee: ");
    scanf("%d",&newnode->salary);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void print()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("ID:%d\t",temp->id);
        printf("NAME:%s\t",temp->name);
        printf("GENDER:%s\t",temp->gender);
        printf("Designation:%s\t",temp->designation);
        printf("Address:%s\t",temp->address);
        printf("Contact Number:%d\t",temp->phone_number);
        printf("Salary:%d\n",temp->salary);
        temp=temp->next;
    }
}
void user()
{
   int i,c=0,ch,n;
   do{
    printf("1.Display data\n2.Display a particular employee data\n3.Total number of employees\n4.Switch to administrator account\n5.Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            print();
            break;
        }
    case 2:
        {
            individual_data();
            break;
        }
    case 3:
        {
            n=counter();
            printf("Number of employees:%d\n",n);
            break;
        }
    case 4:
        {
            administrator();
            break;
        }
    case 5:
        {
            exit(0);
            break;
        }
    default:
        print("Enter a valid input.");
    }
   }while(ch!=5);
}
void administrator()
{
    int i,c=0,ch,n;
    do{
    printf("1.Enter data\n2.Delete a data\n3.Display data\n4.Display a particular employee data\n5.Total number of employees\n6.Switch to user account\n7.Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            create_node();
            break;
        }
    case 2:
        {
            delete_data();
            break;
        }
    case 3:
        {
            print();
            break;
        }
    case 4:
        {
            individual_data();
            break;
        }
    case 5:
        {
            n=counter();
            printf("Number of employees:%d",n);
            break;
        }
    case 6:
        {
            user();
            break;
        }
    case 7:
        {
            exit(0);
            break;
        }
    default:
        print("Enter a valid input.");
    }
   }while(ch!=7);
}
int counter()
{
    int count=0;
    temp=head;
    if(head==NULL)
    {
        printf("No records found.");
    }
    else{
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
    }
}
void individual_data()
{
    int n;
    printf("Enter the ID: ");
    scanf("%d",&n);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->id==n)
        {
             printf("ID:%d\t",temp->id);
             printf("NAME:%s\t",temp->name);
             printf("GENDER:%s\t",temp->gender);
             printf("Designation:%s\t",temp->designation);
             printf("Address:%s\t",temp->address);
             printf("Contact Number:%d\t",temp->phone_number);
             printf("Salary:%d\t",temp->salary);
        }
        temp=temp->next;
    }
}
int position(int n)
{
    int pos=0;
    temp=head;
    if(head==NULL)
    {
        printf("The list is empty.");
        return pos=0;
    }
    else
    {
    while(temp!=NULL)
    {
        pos++;
        if(temp->id==n)
        {
            break;
        }
        temp=temp->next;
    }
    return pos;
    }
}
void delete_beg()
{
    temp=head;
    head=head->next;
    free(temp);
}
void delete_end()
{
    struct node *prevnode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    free(temp);
}
void delete_mid(int pos)
{
    struct node *nextnode;
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);

}
void delete_data()
{
    int n,pos,len;
    printf("\nEnter the id number of the data to be deleted: ");
    scanf("%d",&n);
    pos=position(n);
    len=counter();
    if(pos==1)
    {
        delete_beg();
    }
    else if(pos==len)
    {
        delete_end();
    }
    else
    {
        delete_mid(pos);
    }
}
int main()
{
    int ch;
    do
    {
        printf("Welcome to employee record portal.\n");
        printf("1.User account\n2.Administrator account\n3.Exit portal\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        fflush(stdin);
        switch(ch)
        {
        case 1:
            {
                user();
                break;
            }
        case 2:
            {
                administrator();
                break;
            }
        case 3:
            {
                exit(0);
                break;
            }
        default:
            printf("Invalid input.");
        }
    }while(ch!=7);

}
