#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct profile
{
	int registration_no;
	//int password;
	char name[30];
	double attend_1;
	//double attend_2;
	//double attend_3;
	double marks_1;
	//double marks_2;
	//double marks_3;
	struct profile* next;	
}node;

//node *head= NULL;
void rtn_intgrs(double x, int *w, int *f)
{
	*w=(int)x;
	double frac;
	frac = x-(double)*w;
	*f=(int)ceil(frac*100);
}
node* create()
{
	node *head=NULL;
	node *new=NULL;
	node *p=NULL;
	int ch;
	int reg;
	char name[30];
	double attend,marks;
	do
	{
		new=(node*)malloc(sizeof(node));
		//node *new=(node*)malloc(sizeof(node));
		printf("\n%30cEnter the registration no. of the student=>",' ');
		scanf("%d",&(new->registration_no));
		getchar();
		printf("\n%30cEnter the name=>",' ');
		scanf("%s",&(new->name));
		printf("\n%30cEnter the attendance in subject 1 as(attended.total)=>",' ');
		scanf("%lf",&(new->attend_1));
		printf("\n%30cEnter the marks in subject 1 as(marks secured.full marks)=>",' ');
		scanf("%lf",&(new->marks_1));
		
		printf("\nWhether you want to add any more data (1/0)=>");
		scanf("%d",&ch);
		if(head==NULL)
		{
			head=new;
			
		}
		else
		{
			p=head;
			while(p->next!=NULL)
			{
			p=p->next;
			}
			p->next=new;
						
		}
	}while(ch==1);
	printf("\nExiting create\n");
	return head;
		
}
void addnew(node *head, int check)
{
	node *temp=head;
	node *new=(node*)malloc(sizeof(node));
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	printf("\n%30cEnter the registration no. of the student=>",' ');
	scanf("%d",&(new->registration_no));
	getchar();
	printf("\n%30cEnter the name=>",' ');
	scanf("%s",&(new->name));
	printf("\n%30cEnter the attendance in subject 1 as(attended.total)=>",' ');
	scanf("%lf",&(new->attend_1));
	printf("\n%30cEnter the marks in subject 1 as(marks secured.full marks)=>",' ');
	scanf("%lf",&(new->marks_1));
	temp->next=new;
	
	
}
node* search(node *head,int reg,int check)
{
	int flag=0;
	node *search_node=head;
	
	while(search_node!=NULL)
	{
		if(search_node->registration_no==reg)
		{
			flag++;
			break;
		}
		search_node=search_node->next;
	
	}
	if(flag==1)
	{
	printf("\n%30cRegistration Number=>%d",' ',search_node->registration_no);
	//printf("\n%30cName=>%s",' ',temp->name[30]);
	printf("\n%30cName=>",' ');puts(search_node->name);
	int attend,total;
	rtn_intgrs(search_node->attend_1,&attend,&total);
	printf("\n%30cAttendance in subject 1=%d/%d",' ',attend,total);
	int got,full;
	rtn_intgrs(search_node->marks_1,&got,&full);
	printf("\n%30cMarks in subject 1=%d/%d",' ',got,full);
	return(search_node);
	}
	else
	{
	printf("\n%30cNO SUCH RECORD IN OUR DATABASE........!",' ');
	}
}
void edit_node(node* edit)
{
	printf("\nDO YOU WANT TO EDIT ANY DATA?(1/0)");
	int edit_ch;
	scanf("%d",&edit_ch);
	int up_attend_ch;
	int up_marks_ch;
	while(edit_ch==1)
	{
		//printf("\n%30c1:Registration Number",' ');
		//printf("\n%30c1:Password",' ');
		printf("\n%30c1:Name",' ');
		printf("\n%30c2:Attendance",' ');
		printf("\n%30c3:Marks",' ');
		printf("\n%30cEnter what you want to edit(1/2/3)=>",' ');
		fflush(stdin);
		int curr_edit;
		scanf("%d",&curr_edit);
		//int new_pass;
		char new_nam[30];
		//int up_attend_ch;
		double up_attend;
		//int up_marks_ch;
		double up_marks;
		getchar();
		switch(curr_edit)
		{
			/*case 1: 
				printf("\n%30cEnter new password=>",' ');
				scanf("%d",&new_pass);
				temp->registration_no=new_pass;
				break;*/
			case 1: 
				fflush(stdin);
				printf("\n%30cEnter new name=>",' ');
				//sacnf("%s ",&new_nam[30]);
				//scanf("%s",&temp->name);
				//temp->name=new_nam;
				fgets(edit->name,30,stdin);
				break;
			case 2: printf("\n%30cEnter the attendance for which subject you want to edit(1/2/3)=>",' ');
				
				scanf("%d",&up_attend_ch);
				if(up_attend_ch==1)
				{
					printf("\n%30cEnter the new attendance(attended.total)=>",' ');
					scanf("%lf",&up_attend);
					edit->attend_1=up_attend;	
				}
				/*if(up_attend_ch==2)
				{
					printf("\n%30cEnter the new attendance(attended.total)=>",' ');
					scanf("%lf",&up_attend);
					temp->attend_2=up_attend;	
				}
				if(up_attend_ch==3)
				{
					printf("\n%30cEnter the new attendance(attended.total)=>",' ');
					scanf("%lf",&up_attend);
					temp->attend_3=up_attend;	
				}*/
				break;
			case 3: printf("\n%30cEnter the subject of which you want to edit the marks(1/2/3)=>",' ');
				
				scanf("%d",&up_marks_ch);
				if(up_marks_ch==1)
				{
					printf("\n%30cEnter the new marks=>",' ');
					scanf("%lf",&up_marks);
					edit->marks_1=up_marks;
				}
				/*if(up_marks_ch==2)
				{
					printf("\n%30cEnter the new marks=>",' ');
					scanf("%lf",&up_marks);
					temp->marks_2=up_marks;
				}
				if(up_marks_ch==3)
				{
					printf("\n%30cEnter the new marks=>",' ');
					scanf("%lf",&up_marks);
					temp->marks_3=up_marks;
				}*/
				break;
				
				
		}
		printf("\n%30cWhether you want to edit any other data of this student(1/0)?=>",' ');
		fflush(stdin);
		scanf("%d",&edit_ch);
	}
	printf("\n%30cRegistration Number=>%d",' ',edit->registration_no);
	//printf("\n%30cName=>%s",' ',temp->name[30]);
	printf("\n%30cName=>",' ');puts(edit->name);
	int attend,total;
	rtn_intgrs(edit->attend_1,&attend,&total);
	printf("\n%30cAttendance in subject 1=%d/%d",' ',attend,total);
	int got,full;
	rtn_intgrs(edit->marks_1,&got,&full);
	printf("\n%30cMarks in subject 1=%d/%d",' ',got,full);
	
}

void teachermenu(node* head)
{
	printf("\n%30cWhether you want to edit data or read data ?",' ');
	printf("\n%30c1:Edit Data.",' ');
	printf("\n%30c2:Read Data.",' ');
	int t_ch;
	scanf("%d",&t_ch);
	if(t_ch==1)
	{
		node* search_head=head;
		int ch;
		printf("\n%30cDo you want to add any new student(1/0)=>",' ');
		scanf("%d",&ch);
		if(ch==1)
		{
			addnew(search_head,2);
			printf("\n%30cStudent Added...!",' ');	
		}
		//Edit data
		
		
		//edit existing lists with a key
		int reg_no;
		printf("\n%30cEnter the registration number of the student you want to edit=>",' ');
		scanf("%d",&reg_no);
		node* get=search(head,reg_no,2);
		edit_node(get);
		
		
		
	}
	if(t_ch==2)
	{
		getchar();
		printf("\n%30cWhether you want to read the data of a single student or not?(1/0)",' ');
		int r_ch;
		fflush(stdin);
		scanf("%d",&r_ch);
		if(r_ch==1)
		{
			printf("\n%30cEnter the registration number of the student you want to read the data of=>",' ');
			int read_reg_no;
			fflush(stdin);
			scanf("%d",&read_reg_no);
			//search the reg_no and print the data.
			node *read_search=search(head,read_reg_no,2);
		}
		else if(r_ch==0)
		{
			node* temp=head;
			while(temp!=NULL)
			{
				printf("\n%30cRegistration Number=>%d",' ',temp->registration_no);
				//printf("\n%30cPassword=>%d",' ',temp->password);
				//printf("\n%30cName=>%s",' ',temp->name[30]);
				printf("\n%30cName=>",' ');puts(temp->name);
				//write a fuction for returning attendance as two integers
				int attend,total;
				rtn_intgrs(temp->attend_1,&attend,&total);
				printf("\n%30cAttendance in subject 1=%d/%d",' ',attend,total);
				//rtn_intgrs(temp->attend_2,&attend,&total);
				//printf("\n%30cAttendance in subject 2=%d/%d",' ',attend,total);
				//rtn_intgrs(temp->attend_3,&attend,&total);	
				//printf("\n%30cAttendance in subject 3=%d/%d",' ',attend,total);
				//write a function to return marks as two integers
				int got,full;
				rtn_intgrs(temp->marks_1,&got,&full);
				printf("\n%30cMarks in subject 1=%d/%d",' ',got,full);
				//rtn_intgrs(temp->marks_2,&got,&full);
				//printf("\n%30cMarks in subject 2=%d/%d",' ',got,full);
				//rtn_intgrs(temp->marks_3,&got,&full);
				//printf("\n%30cMarks in subject 3=%d/%d",' ',got,full);
				printf("\n\n\n");
				temp=temp->next;
			}
			//print all the data of all the students present in the database.
		}

	}
}
void studentmenu(node *head, int regn_no, int passcode, int pvt_key)
{
	node *temp=head;
	int flag=0;
	while(temp!=NULL && pvt_key==1)
	{
		if(temp->registration_no == regn_no)
		{
			flag++;
			break;
		}
		temp=temp->next;	
	}
	if(flag==1)
	{
		printf("\n%30cRegistration Number=>%d",' ',temp->registration_no);
		//printf("\n%30cPassword=>%d",' ',temp->password);
		//printf("\n%30cName=>%s",' ',temp->name[30]);
		printf("\n%30cName=>",' ');puts(temp->name);
		//write a fuction for returning attendance as two integers
		int attend,total;
		rtn_intgrs(temp->attend_1,&attend,&total);
		printf("\n%30cAttendance in subject 1=%d/%d",' ',attend,total);
		//rtn_intgrs(temp->attend_2,&attend,&total);
		//printf("\n%30cAttendance in subject 2=%d/%d",' ',attend,total);
		//rtn_intgrs(temp->attend_3,&attend,&total);	
		//printf("\n%30cAttendance in subject 3=%d/%d",' ',attend,total);
		//write a function to return marks as two integers
		int got,full;
		rtn_intgrs(temp->marks_1,&got,&full);
		printf("\n%30cMarks in subject 1=%d/%d",' ',got,full);
		//rtn_intgrs(temp->marks_2,&got,&full);
		//printf("\n%30cMarks in subject 2=%d/%d",' ',got,full);
		//rtn_intgrs(temp->marks_3,&got,&full);
		//printf("\n%30cMarks in subject 3=%d/%d",' ',got,full);
		printf("\n\n\n");
			
	}
	else
	{
		printf("\n%30cWRONG CREDENTIALS ENTERED.................!!!!!!!!!!",' ');
	}
}

void main()
{
int flag=0;
node *head=NULL;
int sdb;
do
{
	printf("\n%40cWELCOME TO MY STUDENT DATABASE MANAGEMENT\n",' ');
	printf("%40c----------------------------------------------",' ');
	printf("\n%30cEnter whether you are a student or teacher:",' ');
	printf("\n%30c1:For Student",' ');
	printf("\n%30c2:For Teacher",' ');
	int ch;
	scanf("%d",&ch);
	if(ch==1)
	{
	int student_registn,pass;
	printf("\n%30cNote:You can only read the data.\n",' ');
	printf("\n%30cEnter your registration number=>",' ');
	scanf("%d",&student_registn);
	printf("\n%30cEnter you password=>",' ');
	scanf("%d",&pass);
	studentmenu(head,student_registn,pass,1);
	
		
	}
	else if(ch==2)
	{
		if(flag==0)
		{
		head=create();
		flag++;
		}
		else
		{
		printf("\n%30cNote:You can read as well as access the data.\n",' ');
		teachermenu(head);
		}
	}
	
	printf("\n1: for again going to the main menu \n0:for exit");
	scanf("%d",&sdb);
}while(sdb==1);
//head=create();
printf("\nReturned to main\n");
node *temp=head;
while(temp!=NULL)
{
	printf("\nname=>%s",temp->name);
	printf("\nreg=>%d",temp->registration_no);
	int w,f;
	rtn_intgrs(temp->attend_1, &w, &f);
	printf("\nattendence is %d / %d.",w,f);
	rtn_intgrs(temp->marks_1, &w, &f);
	printf("\nmarks is %d / %d.",w,f);
	temp=temp->next;
}

} 




















