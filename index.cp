#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<fstream.h>
#include<process.h>
#include<time.h>
#include<dos.h>

class user       //   details and tag of user
{
 public:
 char name[100];
 char password[50];
};

struct string    //   string used for messages
{
 char name[100];
 char memo[500];
};

class message
{
 public:
 char name[50];
 string msg;
 int flag;
};

//    BOX FUNCTION

void box(int x1,int y1,int x2,int y2)
{
	textcolor(WHITE);
	gotoxy(x1,y1);
	cprintf("Ú");
	gotoxy(x2,y1);
	cprintf("¿");
	gotoxy(x1,y2);
	cprintf("À");
	gotoxy(x2,y2);
	cprintf("Ù");
	for(int i=x1+1;i<x2;++i)
	{
		gotoxy(i,y1);
		cprintf("Ä");
		gotoxy(i,y2);
		cprintf("Ä");
	}
	for(i=y1+1;i<y2;++i)
	{
		gotoxy(x1,i);
		cprintf("³");
		gotoxy(x2,i);
		cprintf("³");
	}
}

//         Password Function

void enter_password(char A[])
{
/*int i=1;
while (A[i-1]!='\r')
{
 A[i-1]=getch();
 if(A[i-1]=='\b')
 {
  cout<<'\b'<<' '<<'\b';
  i-=2;
 }
 else
 {
  cout<<'*';
 }
 i++;
};*/
for(int i=0;i<8;i++)
{
  A[i]=getch();
  cout<<"*";
}
A[i]='\0';
}




//      Welcome Screen Function

void welcome_screen()
{
 textbackground(BLUE);
 clrscr();
 gotoxy(35,15);
 cout<<"   Welcome to";
 cout<<endl<<endl<<endl<<"                                    ccccc\n                                  cccc   c\n                                cccc\n                               cccc\n                               cccc\n                               cccc\n                               cccc\n                               cccc       BOOK\n                               cccc\n                               cccc\n                               cccc\n                                cccc\n                                  cccc   c\n                                     cccc";
 box(1,1,79,50);
 box(20,35,60,37);
 gotoxy(21,36);
 textcolor(BLUE);
 for(int i=0;i<39;i++)
 {
  delay(123);
  cout<<"|";
 }
 z:gotoxy(35,40);
 cout<<"Press Enter";
 char x;
 x=getch();
 if(x!='\r')
   goto z;
   clrscr();
}

//            Information

void information()
{
 textbackground(BLUE);
 clrscr();
 textcolor(WHITE);
 box(1,1,79,50);
 box(2,2,78,49);
 gotoxy(25,10);
	cout<<"------ ABOUT PROGRAM ------";
 gotoxy(4,18);
	cout<<" INSTRUCTIONS :";
	gotoxy(7,20);
	  cout<<" In the beginning, the program requires the details of the ";
	gotoxy(7,21);
	  cout<<" user  .  Enter  them  carefully  .  (Please  record  the  ";
	gotoxy(7,22);
	  cout<<" username and password  of  the  user  safely ,  as  it  is";
	gotoxy(7,23);
	  cout<<" vital for the program to operate in proper manner).";
	gotoxy(7,24);
	  cout<<" Only the Programmer has rights to modify the details of";
	gotoxy(7,25);
	  cout<<" other users of the program.";
 gotoxy(4,28);
	cout<<" TROUBLESHOOTING";
	gotoxy(7,30);
	  cout<<"If any problem is encountered, please call the programmer,";
	gotoxy(7,32);
	textbackground(BLACK);
	cout<<" Mohammad Akram Rameez, 050-6920488";
 gotoxy(4,35);
	cout<<" Disclaimer";
	gotoxy(7,37);
	  cout<<" Hacking of program is against the will of the federal ";
	gotoxy(7,38);
	  cout<<" government of United Arab Emirates.";
	gotoxy(7,40);
	  cout<<"   Offenders face DEATH PENALTY.";
 getch();
}


//       sign up (File "user" is created)

void signup()
{
  clrscr();
  user A;
  fstream X;
  if(!X)
   {
    cout<<"Cannot open file";
    getch();
    return;
   }
  box(1,1,79,50);
  gotoxy(36,10);
    cout<<"Sign Up";
  gotoxy(16,17);
    cout<<"Enter Name: ";
  gets(A.name);
  fflush(stdin);
  gotoxy(16,20);
    cout<<"Enter Password: ";
  enter_password(A.password);
  X.write((char*)&A,sizeof(A));
  X.close();
  gotoxy(20,40);
    cout<<"Thank You";
  getch();
  return;
}

void check_mail(user a)
{
 int ctr=0;
 message s;
 fstream X;
 X.open("messages.dat",ios::binary|ios::in|ios::out|ios::ate);
 while(X)
 {
 X.seekg((-1)*(sizeof(s),ios::end));
 while(X.read((char*)&s,sizeof(s)))
   {
    while(strcmp(s.name,a.name))
    {
    if(s.flag==1)
      ctr++;
   };
   };
 if(s.flag!=0)
   {
    clrscr();
    box(1,1,79,50);
    gotoxy(25,20);
    cout<<"You have "<<ctr<<" new mail(s)";
    getch();
    return;
   }
 };
 X.close();
}

void compose_mail(user a)
{
  message r;
  clrscr();
  box(1,1,79,50);
  gotoxy(10,25);
     cout<<"Enter Recipient Name: ";
  gets(r.name);
  gotoxy(10,28);
     cout<<"Enter Message: ";
  gets(r.msg.memo);
  strcpy(r.name,a.name);
  r.flag=1;
  fstream X;
  X.open("messages.dat",ios::in|ios::out|ios::binary);
  X.write((char*)&r,sizeof(r));
  X.close();
  gotoxy(20,45);
    cout<<"The message has been delivered";
  getch();
}

void inbox(user a)
{

 char p;
 message s;
 fstream X;
 X.open("messages.dat",ios::in|ios::out|ios::binary|ios::ate);
 X.seekg((-1)*(sizeof(a)),ios::end);
 while(X.read((char*)&s,sizeof(s)))
   {
    do
    {
    if(strcmp(s.name,a.name))
      {
       z:clrscr();
       box(1,1,79,50);
       gotoxy(10,49);
       cout<<"Press 'P' for previous message, 'N' for next message, '0' to exit";
       gotoxy(14,10);
       cout<<"From :"<<s.name;
       gotoxy(14,13);
       for(int i=0,j=0,k=1;i<strlen(s.msg.memo);i++)
       {
	 if(j<67)
	    cout<<s.msg.memo[i];
	 if(j==67)
	    {
	      gotoxy(14,13+k);
	      cout<<s.msg.memo[i];
	    }
	 if(s.flag==1)
	   {
	    s.flag=0;
	    X.seekg((-1)*(sizeof(a)),ios::cur);
	    X.write((char*)&s,sizeof(s));
	   }
       }
       p=getch();
       switch(p)
	 {
	   case 'P':
	   case 'p':
	      while(X.read((char*)&s,sizeof(s)))
		{
		  if(strcmp(a.name,s.name))
		    goto z;
		}
	      break;
	   case 'n':
	   case 'N':
	      do
	      {
	       X.seekg((-2)*(sizeof(s),ios::cur));
	       X.read((char*)&s,sizeof(s));
	       if(strcmp(a.name,s.name))
		 goto z;
	      }while(X);
	      break;
	   case '0':
	      return;
	   default:
	      goto z;
	 }
      }
    }while(X);
   };
 X.close();
}

void mail(user a)
{
  char x;
  clrscr();
  do
  {
  z:clrscr();
  box(1,1,79,50);
  gotoxy(33,15);
     textcolor(WHITE);
     cout<<"Inbox";
  gotoxy(37,23);
     cout<<"1.Compose Mail";
  gotoxy(37,25);
     cout<<"2.Check Mail";
  gotoxy(37,27);
     cout<<"3.Exit";
  gotoxy(33,40);
     cout<<"Press any key";

  x=getch();

  switch(x)
    {
     case '1':
       compose_mail(a);
       break;
     case '2':
       inbox(a);
       break;
     case '3':
       return;
     default:
       cout<<"  Wrong choice";
       getch();
   }
  }while(x!='3');
  getch();
}

void check_buzz()
{
 char p;
 string s;
 fstream X;
 X.open("buzz.dat",ios::in|ios::out|ios::binary|ios::ate);
 X.seekg((-1)*(sizeof(s)),ios::end);
 while(X.read((char*)&s,sizeof(s)))
   {
    do
    {
       z:clrscr();
       box(1,1,79,50);
       gotoxy(10,49);
       cout<<"Press 'P' for previous message, 'N' for next message, '0' to exit";
       gotoxy(14,10);
       cout<<s.name<<" :";
       gotoxy(14,13);
       for(int i=0,j=0,k=1;i<strlen(s.memo)&&k<30;i++)
       {
	 if(j<30)
	    cout<<s.memo[i];
	 if(j==30)
	    {
	      gotoxy(14,13+k);
	      cout<<s.memo[i];
	      k++;
	    }

       }
       p=getch();
       switch(p)
	 {
	   case 'P':
	   case 'p':
	      while(X.read((char*)&s,sizeof(s)))
		{
		  goto z;
		};
	      break;
	   case 'n':
	   case 'N':
	      X.seekg((-2)*(sizeof(s),ios::cur));
	      X.read((char*)&s,sizeof(s));
	      goto z;
	   case '0':
	      return;
	   default:
	      goto z;
	 }
      }while(X);
    };
 getch();
 X.close();
   }

void status(user a)
{

  string r;
  strcpy(r.name,a.name);
  clrscr();
  box(1,1,79,50);
  gotoxy(10,11);
     cout<<"Enter Status:     ";
  gets(r.memo);
  fstream X;
  X.open("buzz.dat",ios::in|ios::out|ios::binary);
  X.write((char*)&r,sizeof(r));
  X.close();
  gotoxy(20,45);
    cout<<"Your status has been updated";
  getch();
}



void buzz(user a)
{
   char ans;
   do
  {
   j:clrscr();
   box(1,1,79,50);
   gotoxy(28,10);
     cout<<"Welcome "<<a.name;
   gotoxy(17,20);
     cout<<"1. Check Buzz!!";
   gotoxy(17,22);
     cout<<"2. Post What's on your Mind!!";
   gotoxy(17,24);
     cout<<"3. Exit";
   gotoxy(13,35);
     cout<<"Press Any Key ";
   ans=getch();
   switch(ans)
     {
       case '1':
	  check_buzz();
	  break;
       case '2':
	  status(a);
	  break;
       case '3':
	  return;

       default:
	  cout<<"  Wrong Choice";
	  getch();
	  goto j;

     }
   }while(ans!='3');
}

int TTT()
{
  clrscr();
  int j,z=0;
  char ans;
  z:cout<<"\n\t\t\tTHE MAGIC NUMBER GUESSING TRICK.";
  cout<<"\n\t\t\tPick a NUMBER from 0 to 63.";
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	      //1st table
  cout<<"\nIs the number in this table???(Y/N)\n\n\n";
  char ans1;
  cout<<"\t 1\t 3\t 5\t 7\n\n\t 9\t11\t13\t15\n\n\t17\t19\t21\t23\n\n\t25\t27\t29\t31\n\n\t33\t35\t37\t39\n\n\t41\t43\t45\t47\n\n\t49\t51\t53\t55\n\n\t57\t59\t61\t63\n\n\t";
  cout<<"\n\t";
  cin>>ans1;
  if(ans1=='y'||ans1=='Y')
    z=z+1;
  char ans2;
	      //2nd table
  cout<<"\n\n\t\t\tIs the number in this table??(Y/N)\n\n";
  cout<<"\t 2\t 3\t 6\t 7\n\n\t10\t11\t14\t15\n\n\t18\t19\t22\t23\n\n\t26\t27\t30\t31\n\n\t34\t35\t38\t39\n\n\t42\t43\t46\t47\n\n\t50\t51\t54\t55\n\n\t58\t59\t62\t63\n\n\t";
  cin>>ans2;
  if(ans2=='y'||ans2=='Y')
    z+=2;
  char ans3;
	      //3rd table
  cout<<"\n\n\t\t\tIs the number in this table??(Y/N)\n\n";
  cout<<"\t 4\t 5\t 6\t 7\n\n\t12\t13\t14\t15\n\n\t20\t21\t22\t23\n\n\t28\t29\t30\t31\n\n\t36\t37\t38\t39\n\n\t44\t45\t46\t47\n\n\t52\t53\t54\t55\n\n\t60\t61\t62\t63\n\n\t";
  cin>>ans3;
  if(ans3=='y'||ans3=='Y')
    z=z+4;
  char ans4;
	      //4th table
  cout<<"\n\n\t\t\tIs the number in this table??(Y/N)\n\n";
  cout<<"\t 8\t 9\t10\t11\n\n\t12\t13\t14\t15\n\n\t24\t25\t26\t27\n\n\t28\t29\t30\t31\n\n\t40\t41\t42\t43\n\n\t44\t45\t46\t47\n\n\t56\t57\t58\t59\n\n\t60\t61\t62\t63\n\n\t";
  cin>>ans4;
  if(ans4=='y'||ans4=='Y')
    z=z+8;
  char ans5;
	      //5th table
  cout<<"\n\n\t\t\tIs the number in this table??(Y/N)\n\n";
  cout<<"\t16\t17\t18\t19\n\n\t20\t21\t22\t23\n\n\t24\t25\t26\t27\n\n\t28\t29\t30\t31\n\n\t48\t49\t50\t51\n\n\t52\t53\t54\t55\n\n\t56\t57\t58\t59\n\n\t60\t61\t62\t63\n\n\t";
  cin>>ans5;
  if(ans5=='y'||ans5=='Y')
    z=z+16;
  char ans6;
	      //6th table
  cout<<"\n\n\t\t\tIs the number in this table??(Y/N)\n\n";
  cout<<"\t32\t33\t34\t35\n\n\t36\t37\t38\t39\n\n\t40\t41\t42\t43\n\n\t44\t45\t46\t47\n\n\t48\t49\t50\t51\n\n\t52\t53\t54\t55\n\n\t56\t57\t58\t59\n\n\t60\t61\t62\t63\n\n\t";
  cin>>ans6;
  if(ans6=='y'||ans6=='Y')
    z=z+32;
  cout<<"\n\n\t\t\tYour number is\t\a"<<z;
  cout<<"\n\n\tDo you want to move to the next trick or repeat this trick???(M/R)\t";
  cin>>ans;
  if(ans=='R'||ans=='r')
    goto z;
  else return 1
  ;
}


void highlow()
{
  const int totchan = 7;
      int number;
      int guess;
      int chances=0,score=0,chanscor;
      char ans;
      do
       {
	clrscr();
	chances=score=0;
	cout<<"\n\t\t\t\tWelcome to the High/Low game.";
	cout<<"\n\t\t\tI will pick a random number from 0 to 100.";
	cout<<"\n\t\t\t You must try to guess the number.\n";
	randomize();
	number=(int)(rand()%100);
	chanscor=100/totchan;		//score for each successful chance
	do
	 {
	  cout<<"\n\tWhat is your guess? (0 to 100) ";
	  cin>> guess;
	  if((guess<0)||(guess>100))
	     {
	      cout<<" Sorry, but your guess " <<guess<< " must be from 0 to 100. ";
	     }
	  else if(guess<number)
	     {
	       cout<<guess<<" is low. Try a higher number.";
	     }
	  else if (guess>number)
	     {
	       cout<<guess<<" is high. Try a lower number.";
	     }
	  else
	     {
	       cout<<guess<<" is correct. Congratulations!";
	       score=chanscor*(totchan-chances);
	       cout<<"\n\t Your score is "<<score<<endl;
	       break;
	     }
	 chances++;
	 if(guess!=number)
	 cout <<"\n\n Now you have "<<totchan-chances<<" left."<<endl;
	 if(chances==totchan)
	     {
	      cout<<"\n\nOnly "<<totchan <<" chances are allowed. Better luck next time ";
	      cout <<" \n The actual number was "<<number<<endl ;
	      break;
	     }
	}while(guess!=number);
       cout<<"\n\n Thank you for playing High/Low";
       cout <<"Want to play it again?(Y/N). ";
       cin>>ans;
      }while(ans=='y'||ans=='Y');
}


void application(user a)
{
  char ans;
  do
  {
   j:clrscr();
   box(1,1,79,50);
   gotoxy(28,10);
     cout<<"Welcome "<<a.name;
   gotoxy(17,22);
     cout<<"1. High/Low Game";
   gotoxy(17,24);
     cout<<"2. Number Matrix";
   gotoxy(17,26);
     cout<<"3. Exit";
   gotoxy(13,35);
     cout<<"Press Any Key ";
   ans=getch();
   switch(ans)
     {
       case '1':
	  highlow();
	  break;
       case '2':
	  TTT();
	  break;
       case '3':
	  return;
       default:
	  cout<<"  Wrong Choice";
	  getch();
	  goto j;

     }
   }while(ans!='4');
}


void book(user a)
{

  char ans;
  check_mail(a);
  do
  {
   j:clrscr();
   box(1,1,79,50);
   gotoxy(28,10);
     cout<<"Welcome "<<a.name;
   gotoxy(17,20);
     cout<<"1. Mail";
   gotoxy(17,22);
     cout<<"2. Buzz!!";
   gotoxy(17,24);
     cout<<"3. Applications";
   gotoxy(17,28);
     cout<<"4. Exit";
   gotoxy(13,35);
     cout<<"Press Any Key ";
   ans=getch();
   switch(ans)
     {
       case '1':
	  mail(a);
	  break;
       case '2':
	  buzz(a);
	  break;
       case '3':
	  application(a);
	  break;
       case '4':
	  return;

       default:
	  cout<<"  Wrong Choice";
	  getch();
	  goto j;

     }
   }while(ans!='4');
}



//        LOGIN FUNCTION

void login()
{
  int flag=0;
  user z,check;
  clrscr();
  box(1,1,79,50);
  gotoxy(36,10);
    cout<<" LOGIN ";
  gotoxy(16,17);
    cout<<"Enter Name: ";
  gets(z.name);
  fflush(stdin);
  gotoxy(16,20);
    cout<<"Enter Password: ";
  enter_password(z.password);
  fstream X;
  X.open("users.dat",ios::in|ios::nocreate);
  if(!X)
   {
    cout<<" Cannot open file";
    getch();
    return;
   }
  while(X.read((char*)&check,sizeof(check)))
  {
   if(strcmpi(z.name,check.name)==0&&strcmpi(z.password,check.password)==0)
	 {
	   flag=1;
	 }
  }
  if(flag==1)
   {
      box(20,38,60,40);
      gotoxy(21,39);
      textcolor(BLUE);
      for(int i=0;i<39;i++)
       {
	delay(132);
	cout<<"|";
       }
      z:gotoxy(35,42);
      cout<<"Press Enter";
      char x;
      x=getch();
      if(x!='\r')
	 goto z;

      book(z);
   }

  else
  {
   gotoxy(21,36);
   cout<<"Incorrect Username and Password Combination";
   getch();
  }

X.close();
}



//     MAIN FUNCTION

void main()
{
  char x;
  clrscr();
  welcome_screen();
  clrscr();
  information();
  clrscr();
  do
  {
  z:clrscr();
  box(1,1,79,50);
  gotoxy(33,15);
     textcolor(WHITE);
     cout<<"Welcome to C book";
  gotoxy(37,23);
     cout<<"1.Login";
  gotoxy(37,25);
     cout<<"2.Sign up";
  gotoxy(37,27);
     cout<<"3.Information";
  gotoxy(37,33);
     cout<<"4.Exit";
  gotoxy(33,40);
     cout<<"Press any key";

  x=getch();

  switch(x)
    {
     case '1':
       login();
       break;
     case '2':
       signup();
       break;
     case '3':
       information();
       break;
     case '4':
       exit(0);
     default:
       cout<<"  Wrong choice";
       getch();
   }
  }while(x!='4');


getch();
}

