#include<stdio.h>
#include<string.h>		// Use for strcmp(),strcpy(),strlen(),etc.
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>		// Use for getch()

struct patient_details{			// List of global variables
	int id;
	int discharge;
	char disease[10],doctor[20],gen;
	struct
	{
		char first_name[20];
		char middle_name[20];
		char surname[20];
	}patient_name;
	int age;
	struct
	{
		int month_no;
		int day;
		int year;
	}date_of_entry;
	int room_no;
	struct
	{
		int date;
		int month_no;
		int year;
	}date_of_birth;
};
struct node
{
	struct patient_details patient;
	struct node *next;
};
int ID=237,room[9];
int num;	
int e=0	;
char Username[15];
char Password[15];
char original_Username[25]="HMS";
char original_Password[15]="shan_1506";
struct node *start=NULL;
struct node *insert_details(struct node *start);
struct node *change_details(struct node *start);
struct node *display_details(struct node *start);
struct node *List_of_medicine(struct node *start);
struct node *Facilities_charges(struct node *start);
struct node *Information_About_the_Hospital(struct node *start);
void display_list(struct node *start);
void display(struct node *start);				// Function declaration
int sort_by_month(struct node *start);
void sort_by_name(struct node *start);
void sort_by_id(struct node *start);
void swap_data(struct node *ptr1, struct node *ptr2);
void LoginScreen (void);
void MainMenu(void);
void WelcomeScreen(void);
int main(void)
{
	WelcomeScreen(); 	// To call WelcomeScreen function
	LoginScreen();		// To call Login screen function
}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void)	//Function for welcome screen
{
	system("Color 02");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t\t\t@@ ______________________________________________________________________________@@\n");
	printf("\t\t\t@@|                                           		                        |@@\n");
	printf("\t\t\t@@|                                           		                        |@@\n");
	printf("\t\t\t@@|                                           		                        |@@\n");
	printf("\t\t\t@@|                                WELCOME TO                                   |@@\n");
	printf("\t\t\t@@|                                                                             |@@\n");
	printf("\t\t\t@@|                   C.V.RAMAN MULTICARE HOSPITAL MANAGEMENT                   |@@\n");
	printf("\t\t\t@@|                                                                             |@@\n");
	printf("\t\t\t@@|                                                                             |@@\n");
	printf("\t\t\t@@|_____________________________________________________________________________|@@\n");
	printf("\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t");
	printf("\n\tPress any key to continue..........");
	getch();
	system("cls");		// use to clear screen
}
/* ************************************************* Login Screen ********************************************* */
void LoginScreen(void)		//function for login screen
{
	do
	{
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\tEnter your Username and Password :)                          \n");
	printf("\t\t\t\t\t\t_________________________________________________________________\n\n");
	printf("\t\t\t\t\t\tUSERNAME: ");
	scanf("%s",&Username);
	printf("\n\t\t\t\t\t\tPASSWORD: ");
	scanf("%s",&Password);
		
	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
	{
		printf("\n\n\n\t\t\t\t\t\t............Login Successfull............");
		printf("\n\n\t\t\t\t\t\tPress any key to continue..........");
		getch();
		system("cls");
		MainMenu();		// main menu function called
	}
	else
	{
		printf("\n\t\t\t\t\t\tPassword is incorrect!( Try Again :)");
		e++;
		getch();
	}
	}while(e<=2);
	if(e>2)
	{
		printf("\n\nYou have cross the limit. You cannot login! :( :(");
		printf("\n\nTHANK YOU FOR VISITING :)\n\n");	
	}	
	exit(0);
}
/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)		//function declaration
{	int choice,i;
	for(i=0;i<10;i++)	// for printing avilable rooms
		room[i]=-1;
	do
	{
		system("Color 02");
		printf("\n\n");
		printf("\t\t\t\t\t\t_________________________________________________________________\n");
		printf("\t\t\t\t\t\t                                           		                 \n");
		printf("\t\t\t\t\t\t                          PATIENT FIRST                          \n");
		printf("\t\t\t\t\t\t                  Assuring.Advanced.Accessible.                  \n");
		printf("\t\t\t\t\t\t_________________________________________________________________\n\n");
		printf("\t\t\t\t\t\t            1  >> Make a new entry of a patient                  \n");
		printf("\t\t\t\t\t\t            2  >> Display details of a patient                   \n");
		printf("\t\t\t\t\t\t            3  >> Change details of a patient                    \n");
		printf("\t\t\t\t\t\t            4  >> List of medicine                               \n");
		printf("\t\t\t\t\t\t            5  >> Facilities charges                             \n");
		printf("\t\t\t\t\t\t            6  >> Information About the Hospital                 \n");
		printf("\t\t\t\t\t\t            7  >> Exit the Program                               \n\n");
		printf("\t\t\t\t\t\t_________________________________________________________________\n\n");
		printf("\n\nChoose Number from (1-7): ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				start=insert_details(start);		// add patient function is called
				break;
			case 2:
				start=display_details(start);		// search patient function is called
				break;
			case 3:
				start=change_details(start);		// change patient's information function is called
				break;
			case 4:
				start=List_of_medicine(start);		// function to print list of medicine
				break;
			case 5:
				start=Facilities_charges(start);		// function to print charges
				break;
			case 6:
				start=Information_About_the_Hospital(start);	// function to print about
				break;
    		case 7:
				system("Color 02");
				printf("\n\tClosing application......\n");
				printf("\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   				printf("\t\t\t\t\t@@_________________________________________________________________________________________@@\n");
    			printf("\t\t\t\t\t@@|                                           		                                  |@@\n");
    			printf("\t\t\t\t\t@@|                                           		                                  |@@\n");
    			printf("\t\t\t\t\t@@|                               THANK YOU FOR VISITING :)                               |@@\n");
    			printf("\t\t\t\t\t@@|                                                                                       |@@\n");
    			printf("\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n");
    			printf("\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t");
    			exit(0);	// to exit from the program
			default:
				printf("\nPlease enter valid option! ");
		}
	}
	while(choice!=7);
}
/* **************************************ADD RECORD*******************************************/
struct node *insert_details(struct node *start)
{
	struct node *new_node,*ptr;
	int d,m,yr,ag,db,mb,yrb,flag=0,i=0,roomno=0;
	char gend,f_name[20],m_name[20],l_name[20],dis[20],doct[20];
	new_node=(struct node *)malloc(sizeof(struct node));

	while(i<10){
		if(room[i]==-1)
		{
			printf("\t\t\t\t\tRoom number %d is empty.\n",i+1);
			flag=1;
		}
		i++;
	}
	if(flag!=1)
		printf("\n\t\t\t\t\tSorry,there are no Rooms available at this time.\n");
	else
	{
		printf("======================================================================\n");
		printf("                        Entry Patient's Details                       \n");
		printf("======================================================================\n");
		printf("\nEnter day of entry(dd): ");
		scanf("%d",&d);
		printf("\nEnter month of entry(mm): ");
		scanf("%d",&m);
		printf("\nEnter year of entry(yyyy): ");
		scanf("%d",&yr);
		printf("\nEnter Patient's First name: ");
		scanf("%s",f_name);
		printf("\nEnter Patient's Middle name: ");
		scanf("%s",m_name);
		printf("\nEnter Patient's Last name: ");
		scanf("%s",l_name);
		printf("\nEnter Patient's age(in yrs): ");
		scanf("%d",&ag);
		printf("\nEnter Patient's Gender(M-male, F-female, O-others): ");
		scanf(" %c",&gend);
		printf("\nEnter Patient's date of birth(dd/mm/yyyy): ");
		scanf("%d/%d/%d",&db,&mb,&yrb);
		printf("\nEnter Disease name: ");
		scanf("%s",&dis);
		printf("\nEnter Prescribed Doctor name: ");
		scanf("%s",doct);
		printf("\nPatient's Generated ID: %d\n",ID);

		do{
			printf("\nEnter the Room Number for the patient: ");
			scanf("%d",&roomno);
			if(roomno>0 && roomno<11)
			{
                if(room[roomno-1]!=-1)
                {
                    printf("\nThis Room is occupied. Please select from the given Room Number(s) only\n");
                    i=1;
                }
                else
                {
                    new_node->patient.room_no=roomno;
                    room[roomno-1]=new_node->patient.id;
                    i=0;
					printf("\n******* Patients's Information Recorded Successfully *******\n");
					printf("\nPress any key to Continue.......");
					getch();
                }
			}
			else
			{
                printf("\n**** Invalid Room Number. Please select again. ****\n");
                i=1;
			}
		}while(i);
		new_node->patient.id=ID;
		strcpy(new_node->patient.patient_name.first_name,f_name);
		strcpy(new_node->patient.patient_name.middle_name,m_name);
		strcpy(new_node->patient.patient_name.surname,l_name);
		new_node->patient.date_of_entry.month_no=m;
		new_node->patient.date_of_entry.day=d;
		new_node->patient.date_of_entry.year=yr;
		new_node->patient.age=ag;
        new_node->patient.gen=gend;
        new_node->patient.discharge=0;
		new_node->patient.date_of_birth.date=db;
		new_node->patient.date_of_birth.month_no=mb;
		new_node->patient.date_of_birth.year=yrb;
		strcpy(new_node->patient.disease,dis);
		strcpy(new_node->patient.doctor,doct);
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
			ID++;
		}
		else
		{
			new_node->next=NULL;
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			ID++;
		}
	}
	return start;
}
/* ************************************* Change details ***********************************************************/
struct node *change_details(struct node *start)
{
	struct node *ptr;
	int change_id,option,status,roomno,i=0,flag=0;
	char f_name[20],m_name[20],l_name[20],dis[20],doct[20];
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(ptr==NULL)
	{
		printf("\n***** No details available!! Please make an entry. *****\n");
		return NULL;
	}
	else
	{
		printf("\nWhich patient's detail is to be changed?\n\nPlease enter the patient's Id: ");
		scanf("%d",&change_id);
		while(ptr!=NULL && ptr->patient.id!=change_id)
		{
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("There is no patient with such id.\n");
			free(ptr);
			return start;
		}
		else
		{
			do
			{   
			    a:
				printf("============================================================\n");
				printf("           Which detail is to be changed ?     	            \n");
				printf("============================================================\n");
				printf("           1  >> Status of the patient                      \n");
				printf("           2  >> Name of the patient                        \n");
				printf("           3  >> Room Number of the patient                 \n");
				printf("           4  >> Doctor Prescribed to the patient           \n");
				printf("           5  >> New Disease acquired by the patient        \n");
				printf("           6  >> Exit    				                    \n");				
				printf("\nEnter your option: ");				
				scanf("%d",&option);
				switch(option)
				{
					case 1:
						printf("\nIs the patient\n1.Admitted\tOR\t2.Discharged ? :-- ");
						scanf("%d",&status);
						if(status==1)
						{
						    ptr->patient.discharge=0;
							printf("\n\n****** Patient is admitted successfully ******\n\n");
						}
						else
						{
							ptr->patient.discharge=1;
							roomno=ptr->patient.room_no;
							room[roomno-1]=-1;
							printf("\n\n****** Patient is dischraged successfully ******\n\n");
						}
					    goto a;
					case 2:
						printf("\nEnter Patient's First name: ");
						scanf("%s",f_name);
						printf("\nEnter Patient's Middle name: ");
						scanf("%s",m_name);
						printf("\nEnter Patient's Last name: ");
						scanf("%s",l_name);
						strcpy(ptr->patient.patient_name.first_name,f_name);
						strcpy(ptr->patient.patient_name.middle_name,m_name);
						strcpy(ptr->patient.patient_name.surname,l_name);
						printf("\n****** Patient's information is edited successfully ******\n");
						goto a;
					case 3:
						while(i<10)
						{
							if(room[i]==-1)
							{
								printf("Room number %d is empty.\n",i+1);
								flag=1;
							}
							i++;
						}
						if(flag!=1)
							printf("\nThere are no rooms empty at this time. Please try again later.\n");
						else
						{
							do
							{
								printf("\nEnter new Room Number for the patient: ");
								scanf("%d",&roomno);
								if(room[roomno-1]!=-1)
								{
									printf("\nThis room is occupied. Please select from the given room no(s)\n");
									i=1;
								}
								else
								{
									room[ptr->patient.room_no-1]=-1;
									ptr->patient.room_no=roomno;
									room[roomno-1]=ptr->patient.id;
									printf("\n\n****** New room is alloted to the patient ******\n");									
									i=0;
								}
							}while(i);
						}
						goto a;
					case 4:
						printf("\nEnter Prescribed Doctor name: ");
						scanf("%s",doct);
						strcpy(ptr->patient.doctor,doct);
						printf("\n****** Prescribed Doctor is successfully changed ******\n");
						goto a;
					case 5:
						printf("\nEnter Disease name: ");
						scanf("%s",dis);
						strcpy(ptr->patient.disease,dis);
						printf("\n****** Patient's new Disease added successfully ******\n");
						goto a;
					case 6:
						printf("\nReturning to Main Menu............ \n");
						break;
					default:
						printf("Wrong choice!\n");
				}
				return start;
			}while(option!=6);
		}
	}
}
/* ************************************* View Patient *************************************************************/
struct node *display_details(struct node *start)
{
	int choice,i=0,m;
	char n[15];
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\n***** Patient database is empty! *****\n");
		return NULL;
	}
	else
	{
		while(choice!=5)
		{
			ptr=start;
			printf("\n\n");
		printf("============================================================\n");
		printf("            		DISPLAY MENU       		                \n");
		printf("============================================================\n");
		printf("           1  >> Display all patients List                  \n");
		printf("           2  >> Display by ID                              \n");
		printf("           3  >> Display for a specific month               \n");
		printf("           4  >> Search patient by first name               \n");
		printf("           5  >> Exit back to MainMenu                      \n");
		printf("\n\nEnter a choice: ");
		scanf("%d",&choice);
			switch(choice){
				case 1:
					sort_by_name(start);
					printf("ID\t\tName\t\t\t\tDisease\t\t\t\tDoctor\t\t\t\tRoom No.\t\tStatus\n");
					while(ptr!=NULL)
					{
						display_list(ptr);
						ptr=ptr->next;
					}
					printf("\nPress any key to continue...........");
					getch();
					system("cls");
					break;
				case 2:
					sort_by_id(start);
					printf("\nEnter patient's ID: ");
					scanf("%s",n);
					printf("ID\t\tName\t\t\t\tDisease\t\t\t\tDoctor\t\t\t\tRoom No.\t\tStatus\n");
					
					while(ptr!=NULL)
					{
						display_list(ptr);
						i++;
						ptr=ptr->next;
					}
					if(i==0)
						{
						printf("\nPatients not found!\n");
						}
					printf("\nPress any key to continue...........");
					getch();
					system("cls");
					break;
				case 3:
					m=sort_by_month(start);
					if(m==0)
						printf("\nNo Entry available for this month\n ");
					else
						printf("ID\t\tName\t\t\t\tDisease\t\t\t\tDoctor\t\t\t\tRoom No.\t\tStatus\n");
					while(ptr!=NULL)
						{
							if(ptr->patient.date_of_entry.month_no==m)display_list(ptr);
							ptr=ptr->next;
						}
					break;
				case 4:
					printf("\nEnter patient's first name: ");
					scanf("%s",n);
					while(ptr!=NULL)
					{
						if(!(strcmpi(n,ptr->patient.patient_name.first_name)))
						{
							display(ptr);
							i++;
						}
						ptr=ptr->next;
					}
					if(i==0)
						{
						printf("\nName not found!\n");
						}
					printf("\nPress any key to continue...........");
					getch();
					system("cls");
					break;
				case 5:
					printf("\nReturning to Main Menu............ ");
					break;
				default:
					printf("\nInvalid choice. Please enter again.");
			}
		}
	}
	sort_by_id(start);
	return start;
}
void display(struct node *start)
{
	char Discharge[15];
	if(start->patient.discharge==0)
		strcpy(Discharge,"Hospitalised");
	else
		strcpy(Discharge,"Discharged");
		
	printf("\nID: %d\n",start->patient.id);
	printf("Patient Name [FIRST MIDDLE LAST] : %s  %s  %s\n",start->patient.patient_name.first_name,start->patient.patient_name.middle_name,start->patient.patient_name.surname);
	printf("Gender: %c\n",start->patient.gen);
	printf("Date of Birth: %d/%d/%d\n",start->patient.date_of_birth.date,start->patient.date_of_birth.month_no,start->patient.date_of_birth.year);
	printf("Age: %d years\n",start->patient.age);
	printf("Date of entry: %d/%d/%d\n",start->patient.date_of_entry.day,start->patient.date_of_entry.month_no,start->patient.date_of_entry.year);
	printf("Room Number: %d\n",start->patient.room_no);
	printf("Disease: %s\nDoctor: Dr. %s\n",start->patient.disease,start->patient.doctor );
	printf("Status: %s\n",Discharge);
}
void display_list(struct node *start)
{
		char Discharged[15];
		if(start->patient.discharge==0)
			strcpy(Discharged,"Hospitalised");
		else
			strcpy(Discharged,"Discharged");
		printf("%d\t%s %s %s\t\t\t%s\t\t\t%s\t\t\t%d\t%s\n",start->patient.id,start->patient.patient_name.first_name,start->patient.patient_name.middle_name,start->patient.patient_name.surname,start->patient.disease,start->patient.doctor,start->patient.room_no,Discharged);
}
int sort_by_month(struct node *start)
{
	struct node *pt1,*pt2;
	int m,flag=1;
	long int d1,d2;
	printf("\nEnter Month number for which you want all patient details: ");
	scanf("%d",&m);
	pt1=start;
	while(pt1!=NULL)
	{
		if(pt1->patient.date_of_entry.month_no==m)
			{
			    flag=0;
			    break;
			}
		pt1=pt1->next;
	}
	pt2=pt1;
	if(flag)
		return 0;
	while(pt1->next!=NULL)
	{
		while(pt1->patient.date_of_entry.month_no!=m)
			pt1=pt1->next;

		d1=pt1->patient.date_of_entry.month_no*50+pt1->patient.date_of_entry.day+pt1->patient.date_of_entry.year*1000;
		while(pt2!=NULL)
		{
		    if(pt2->patient.date_of_entry.month_no==m && pt1!=pt2){
                d2=pt2->patient.date_of_entry.month_no*50+pt2->patient.date_of_entry.day+pt2->patient.date_of_entry.year*1000;
                if((d1>d2) && (pt2->patient.date_of_entry.month_no==m))
                    swap_data(pt1,pt2);
		    }
			pt2=pt2->next;
		}
		pt1=pt1->next;
	}
    return m;
}
void sort_by_id(struct node *start)
{
	struct node *pt1,*pt2;
	pt1=start;
	while(pt1->next!=NULL)
	{
		pt2=pt1->next;
		while(pt2!=NULL)
		{
			if(pt1->patient.id>pt2->patient.id)
				swap_data(pt1,pt2);
			pt2=pt2->next;
		}
		pt1=pt1->next;
	}
}
void sort_by_name(struct node *start)
{
	struct node *pt1,*pt2;
	pt1=start;
	while(pt1->next!=NULL)
	{

		pt2=pt1->next;
		while(pt2!=NULL)
		{
			if(strcmpi(pt1->patient.patient_name.first_name,pt2->patient.patient_name.first_name)>0)
				swap_data(pt1,pt2);
			pt2=pt2->next;
		}
		pt1=pt1->next;
	}
}
void swap_data(struct node *ptr1, struct node *ptr2){
	struct patient_details temp;
	temp=ptr1->patient;
	ptr1->patient=ptr2->patient;
	ptr2->patient=temp;
}
struct node *List_of_medicine(struct node *start)
{	
	FILE* ptr;
    char ch;
    // Opening file in reading mode
    ptr = fopen("Medicine.prn", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        printf("%c", ch);
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
    // Closing the file
    printf("\n\nPress any key to close this file................");
    getch();
    system("cls");
return start;	
}
struct node *Facilities_charges(struct node *start)
{
	FILE* ptr;
    char ch;
    // Opening file in reading mode
    ptr = fopen("FACILITIES CHARGES.prn", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        printf("%c", ch);
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
    // Closing the file
    printf("\n\nPress any key to close this file................");
    getch();
    system("cls");
return start;	
}
struct node *Information_About_the_Hospital(struct node *start)
{
	FILE* ptr;
    char ch;
    // Opening file in reading mode
    ptr = fopen("About_the_Hospital.txt", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        printf("%c", ch);
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
    // Closing the file
    printf("\n\nPress any key to close this file................");
    getch();
	system("cls");
    MainMenu();	
}