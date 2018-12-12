


/********************************************************************
*********************************************************************
 * 																	*
 *                Student Attendance Management system				*
 * 				       Made by: Kumar Navin Barnwal					*
 * 							Linkdin:- knbarnwal1					*
 * 																	*
 * 				Languages:-     C,C++;								*
 * 				Platform:-      Linux, Windows						*
 * 				Dependenncies:- Read out the comment line.			*
 * 								and replace all "cls" with			*
 * 								"clear" to make it work on 			*
 * 								linux.								*
 * 				Username:-		knbarnwal							*
 * 				Password:- 		8971835071							*
 * 																	*
 * ******************************************************************
 * ******************************************************************/









/**Comment out this following macro to make it work on Linux **/


 #define PERR(bSuccess, api){if(!(bSuccess)) printf("Error");}


/*********           Till Here     ****************************/






#include <stdio.h>
#include <stdbool.h>
#include "struct_header.h"
#include <string.h>
#include <stdlib.h>

/* -----------Comment it Out to Make it Run on Linux ---------------- */
#include <windows.h>
#include <conio.h>
#include <unistd.h>

/*-----------Till Here/ More below --------------*/

#define NAMES "student_names.txt"
#define REG_NO "register_number.txt"
#define PERCENTAGE "percentage.txt"
#define WEEK_PROGRESS "weekly_progress.txt"

stu candidate[63];


int first_switch();
int find_by_reg_no();
void first_switch_validation();
void back_exit();
void add_attendance();
void perticular_s_attendance();
void display_all_attendance();
void display_weekly_progress();
void read_name();
void read_data();
void read_percent();
void read_reg_no();
void read_week_progress();
void gotoxy();
void box();


/* -----------Comment it Out to Make it Run on Linux ---------------- */


void cls();



void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}




 void cls( HANDLE hConsole )
 {
    COORD coordScreen = { 0, 0 };    /* here's where we'll home the
                                        cursor */ 
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
    DWORD dwConSize;                 /* number of character cells in
                                        the current buffer */ 

    /* get the number of character cells in the current buffer */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "GetConsoleScreenBufferInfo" );
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    /* fill the entire screen with blanks */ 

    bSuccess = FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputCharacter" );

    /* get the current text attribute */ 

    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "ConsoleScreenBufferInfo" );

    /* now set the buffer's attributes accordingly */ 

    bSuccess = FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputAttribute" );

    /* put the cursor at (0, 0) */ 

    bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
    PERR( bSuccess, "SetConsoleCursorPosition" );
    return;
 }



/*---------------------------------     Till Here/ More below         --------------*/




/*--------------- Remove this Comment tag to run in linux ------- */
/*
void gotoxy(int x,int y){
	
	printf("%c[%d;%df",0x1B,y,x);
	
}
*/


/*--------------- Till Here ..... ------- */



void box(){
	
	int hor_row, ver_col;
	
	
	
	for(hor_row=10; hor_row<70; hor_row++){
		gotoxy(hor_row, 3);
			printf("*");
		gotoxy(hor_row, 4);
			printf("*");
		
		
	}
	
	for(hor_row=10; hor_row<70; hor_row++){
		gotoxy(hor_row, 22);
			printf("*");
		gotoxy(hor_row, 21);
			printf("*");
		
	}
	
	for(ver_col=4; ver_col<21; ver_col++){
		gotoxy(10, ver_col);
			printf("*");
		gotoxy(11, ver_col);
			printf("*");
		gotoxy(12, ver_col);
			printf("*");
		
		
	}
	
	for(ver_col=3; ver_col<23; ver_col++){
		gotoxy(70, ver_col);
			printf("*");
		gotoxy(69, ver_col);
			printf("*");
		gotoxy(68, ver_col);
			printf("*");
		
	}
	
	
}




int find_by_reg_no(long unsigned number){
	
	int i=1;
	while(i<63){
		if(candidate[i].reg_no== number)
			return i;
		else i++;	
	}
	return 0;
}
int find_by_name(char name[30]){
	
	int i=1;
	while(i<63){
		if((strcmp(candidate[i].names, name)== 0))
			return i;
			else i++;
	}
	return 0;
}
		

void back_exit(){
	int c;
	printf("\n\n\n\n\n\t\t\t\t 1. back \n\t\t\t\t 2. exit ");
	printf("\n\nSelect(1/2):- ");
	scanf("%d", &c);
	if(c==1){
		
		first_switch();
		
	}
	
	else if(c==2){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t\t\tThank You,  Visit again !!");
		exit(0);
		
	}
	
}

void edit_attendance(){
	long int number;
	system("cls");
	float add;
	int choice;
	box();
	gotoxy(25,5);
	printf("\n\n\t\t\t***Edit Attendance***");
	printf("\n\n\t\tyou want to:- ");
	printf("\n\n\n\t\t\t 1. Increase Attendance");
	printf("\n\n\t\t\t 2. Decrease Attendance");
	printf("\n\n\t\tSelect(1-2):-  ");
	scanf("%d", &choice);
	if(choice ==1){
		system("cls");
		box();
		gotoxy(20,6);
		printf("\n\n\t\tEnter the registration number of student:- ");
		scanf("%ld", &number);
		int code = find_by_reg_no(number);
		printf("\n\n\t\tHow many percent you want to add:- ");
		scanf("%f", &add);
		system("cls");
		box();
		gotoxy(20,6);
		candidate[code].attendance_percent+=add;
		printf("\n\n\t\t\t*** %s ***\n\n\t\t\t\t*** %lu ***\n\n\t\t\t attendance increamented by \n\n\t\t\t\t*** %0.2f ***", candidate[code].names,candidate[code].reg_no, add);
		printf("\n\t\tEarlier attendance:- %0.2f%%", candidate[code].attendance_percent-add);
		printf("\n\t\tPresent attendance:- %0.2f%%", candidate[code].attendance_percent);
	}
	else if( choice ==2){
		system("cls");
		box();
		gotoxy(20,6);
		printf("\n\n\t\tEnter the registration number of student:- ");
		scanf("%ld", &number);
		int code = find_by_reg_no(number);
		printf("\n\n\t\tHow many percent you want to decrease:- ");
		scanf("%f", &add);
		system("cls");
		box();
		gotoxy(20,6);
		candidate[code].attendance_percent-=add;
		printf("\n\n\t\t\t*** %s ***\n\n\t\t\t\t*** %lu ***\n\n\t\t\t attendance decremented by \n\n\t\t\t\t*** %0.2f ***", candidate[code].names,candidate[code].reg_no, add);
		printf("\n\t\tEarlier attendance:- %0.2f%%", candidate[code].attendance_percent+add);
		printf("\n\t\tPresent attendance:- %0.2f%%", candidate[code].attendance_percent);
	}
	else{
		char y_n;
		printf("\n\t\tInvalid input !!");
		printf("\n\n\t\tDo you want to try again (y/n):- ");
		scanf(" %c", &y_n);
		if(y_n=='y'){
			edit_attendance();
		}
		else exit(0);
	}
	
	back_exit();
}


	
void perticular_s_attendance(){
	
	long int number;
	int choice, code;
	char name[40];
	system("cls");
	box();
	gotoxy(20,5);
	printf("\n\t\t\tsearch by what ?");
	printf("\n\n\t\t\t\t1. Name\n\n\t\t\t\t 2. Registration number");
	printf("\n\n\t\tSelect(1-2):- ");
	scanf("%d", &choice);
	if(choice ==2){
		printf("\n\t\tEnter the registration number of student:- ");
		scanf("%ld", &number);
		code = find_by_reg_no(number);
		system("cls");
		box();
		gotoxy(20,7);
		printf("\n\n\t\t\t The Attendance percentage of \n\n\t\t\t***  %s  *** \n\n\t\t\t\t*** %lu *** \n\n\t\t\t\t   is \n\n\t\t\t\t   %0.2f %% ", candidate[code].names,candidate[code].reg_no, candidate[code].attendance_percent);
	
	}
	else if(choice== 1){
		printf("\n\t\tEnter the name of student:- ");
		scanf(" %[^\n]s", name);
		code = find_by_name(name);
		system("cls");
		box();
		gotoxy(20,7);
		printf("\n\n\t\t\t  The Attendance percentage of \n\n\t\t\t***  %s  *** \n\n\t\t\t\t*** %lu *** \n\n\t\t\t\t   is \n\n\t\t\t\t   %0.2f %% ", candidate[code].names,candidate[code].reg_no, candidate[code].attendance_percent);
	
	}
	else{
		char y_n;
		printf("\nInvalid input !!");
		printf("\n\nDo you want to try again (y/n):- ");
		scanf(" %c", &y_n);
		if(y_n=='y'){
			perticular_s_attendance();
		}
		else exit(0);
	}
	
	back_exit();
}

void display_all_attendance(){
	system("cls");
	printf("\n\n\t\t*** MCA I Attendance Record ***\n");
	printf("\n\t\tAttendance\t\tNames\n\n");
	for(int i=1; i<63; i++){
		printf("\n\t\t%0.2f%%\t\t%s", candidate[i].attendance_percent,  candidate[i].names);
	}
	back_exit();
}

void display_name_reg_no(){
	
	system("cls");
	printf("\n\n\t\t\t*** MCA I Students Record ***\n");
	printf("\n\t\tRegister  \t Names\n");
	for(int i=1; i<63; i++){
		printf("\n\t\t%lu\t\t%s", candidate[i].reg_no, candidate[i].names );
	}
	back_exit();
	
}

void display_weekly_progress(){
	system("cls");
	printf("\n\n\t\t*** Weekly Progress of MCA I - by Register ***");
	printf("\n\n\n\t\tRegister\tWeekly Progress\n\n");
	for(int i=1; i<63; i++){
		printf("\n\t\t%lu\t\t%0.2f%%", candidate[i].reg_no, candidate[i].weekly_progress);
	}
	back_exit();
}

void first_switch_validation(){
	char y;
	printf("Invalid Option choosen !\n");
	printf("Do you want to run again(y/n):- ");
	scanf("%c", &y);
	if(y=='y'){
		first_switch();
	}
	else {
		exit(0);
	}
}



int first_switch(){
	system("cls");
	box();
	char options;
	bool valid=true;
	gotoxy(19,6);
	printf("***MCA I - Student Attendance Database***");
	printf("\n\t\t  =========================================");
	
	//printf("\n\nI want to :- \n");
	//printf("\n\n\n\n\t\t\t1. Add Attendance ");
	printf("\n\n\t\t\t1. Edit Attendance");
	printf("\n\t\t\t2. See perticular student Attendance");
	printf("\n\t\t\t3. All Attendance Record");
	printf("\n\t\t\t4. Weekly progress ");
	printf("\n\t\t\t5. Name with Registration number");
	
	do{
		printf("\n\n\n\t\tChoose an option(1-5):- ");
		scanf(" %[^\n]s", &options);
		if( (options=='1') || (options=='2') || (options=='3') || (options=='4') || (options=='5')){
			valid=false;
			
		}
		else first_switch_validation();
		
	}
	while(valid);
	int op = options- 48;
	
	switch(op){
		
		case 1: edit_attendance();
				break;
		case 2: perticular_s_attendance();
				break;
		case 3: display_all_attendance();
				break;
		case 4: display_weekly_progress();
				break;
		case 5: display_name_reg_no();
				break;
		default: first_switch_validation();
				break;
	}
		return 0;
}

void read_name(char filename[30]){
	
	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);
	
	fptr = fopen(file1, "r");
	
	
	int row=0, col=0;
	 if(fptr == NULL){
      perror("Error in opening file names");
      exit(0);
   }else{
	char ch = fgetc(fptr);
	while(ch != EOF){
		if(ch=='\n'){
			
			candidate[row+1].names[col]='\0';
			ch=fgetc(fptr);
			row++;
			col=0;
		}
		
		else if(ch==32){
			 candidate[row+1].names[col]=ch;
			col++;
			ch=fgetc(fptr);
		}
		else if((ch>=65 && ch<=90)){
			 candidate[row+1].names[col]=ch;
			col++;
			ch=fgetc(fptr);
		}	
		
	}
	}
	fclose(fptr);
	
}


void read_reg_no(char filename[20]){
	
	
	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);
	
	fptr = fopen(file1, "r");
	
	if(fptr == NULL){
      perror("Error in opening file reg_no ");
      exit(0);
   }else{
	   	for(int i=0; i<62; i++){
			fscanf(fptr, "%lu\n", &candidate[i+1].reg_no);
		}
	}
    fclose(fptr);
}

void read_percent(char filename[20]){
	
	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);
	
	fptr = fopen(file1, "r");
	if(fptr == NULL){
      perror("Error in opening file percent");
      exit(0);
   }else{
	   	for(int i=0; i<62; i++){
			fscanf(fptr, "%f\n", &candidate[i+1].attendance_percent );
		}
	}
    fclose(fptr);
}

void read_week_progress(char filename[20]){
	
	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);
	
	fptr = fopen(file1, "r");
	
	
	if(fptr == NULL){
      perror("Error in opening file weekly_progress");
      exit(0);
   }else{
	   	for(int i=0; i<63; i++){
			fscanf(fptr, "%f\n", &candidate[i+1].weekly_progress );
		}
	}
    fclose(fptr);
}



void read_data(char name_file[20], char reg_no_file[20], char percentage[20], char week_progress[20]){
		
	read_name(name_file);
	read_reg_no(reg_no_file);
	read_percent(percentage);
	read_week_progress(week_progress);
}

int thankyou(){
	system("cls");
	box();
	gotoxy(20,12);
	printf("Sorry, Invalid Username/Password !");
	printf("\n\n\t\t\tThank you, Visit again !!");
	gotoxy(20,22);
	exit(0);
	return 0;
}
int main(){
	
	char username[]="knbarnwal";
	char pass[]="8971835071";
	
	char usercheck[20];
	char passcheck[20];
	read_data(NAMES, REG_NO, PERCENTAGE, WEEK_PROGRESS);
	box();
	gotoxy(26,5);
	printf("Christ (Deemed to be University)");
	gotoxy(24,7);
	printf("\tMCA I Batch(2017-20) Database login");
	gotoxy(20,10);
	printf("Username:- ");
	scanf(" %[^\n]", usercheck);
	gotoxy(20,14);
	printf("Password:- ");
	scanf(" %[^\n]", passcheck);
	if(strcmp(usercheck, username)==0){
		if((strcmp(passcheck, pass)==0)){
		first_switch();
		}
		else thankyou();
	}
	
	else{ thankyou();
	}
	
		
	
	return 0;
}
