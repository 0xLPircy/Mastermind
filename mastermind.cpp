#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void display(int guess[], int black, int white) /*main game display*/
{

	int i;
	cout<<"\n                                 =========\n                                 ";
	cout<<"|"<<guess[0]<<"|"<<guess[1]<<"|"<<guess[2]<<"|"<<guess[3]<<"| ";
	for(i=0;i<black;i++)
	{
		cout<<"@";
	}
	for(i=0;i<white;i++)
	{
		cout<<"o";
	}
	cout<<"\n                                 =========\n";
}
void intro() /*intorduction*/
{
	clrscr();
	cout<<"\n\n\n\n\n\n                            Computer ";
	delay(300);
	cout<<"Science ";
	delay(300);
	cout<<"Project";
	delay(600);
	cout<<"\n\n\n                                   MASTERMIND";
	delay(600);
	cout<<"\n\n\n                            Made By:-";
	delay(300);
	cout<<"Taveesha Agarwal";
}
void rulesm()
{
	clrscr();
	cout<<"\n\n\n                     ______________________________________";
	cout<<"\n                     |    WELCOME TO SIMPLE MENTAL MATHS    |";
	cout<<"\n                     |                                      |";
	cout<<"\n                     | 1. You will be asked simple addition |";
	cout<<"\n                     |    and subtraction.                  |";
	cout<<"\n                     | 2. You will be asked 12 questions.   |";
	cout<<"\n                     | 3. You get 2 points for every right  |";
	cout<<"\n                     |    answer.                           |";
	cout<<"\n                     | 4. Your time will start as soon as   |";
	cout<<"\n                     |    the first question turns up.      |";
	cout<<"\n                     | 5. MAX SCORE:24                      |";
	cout<<"\n                     |       BEST OF LUCK!!!!!              |";
	cout<<"\n                      ______________________________________";
}
void rulesc()
{
	clrscr();
	cout<<"\n\n\n                      _____________________________________";
	cout<<"\n                     |            HOW TO PLAY              |";
	cout<<"\n                     |                                     |";
	cout<<"\n                     | 1. Guess the code by choosing four  |";
	cout<<"\n                     | out of given six numbers.           |";
	cout<<"\n                     |         1  2  3  4  5  6            |";
	cout<<"\n                     | 2. 'o' Signifies that the number is |";
	cout<<"\n                     |        correct but position is not. |";
	cout<<"\n                     |    '@' Signifies that the number &  |";
	cout<<"\n                     |        the position is corect.      |";
	cout<<"\n                     | 3. You have six tries.              |";
	cout<<"\n                     |                                     |";
	cout<<"\n                      _____________________________________";
}
void main()
{
    intro();
    delay(900);
    clrscr();
    {
	cout<<"\n\n\n                      _____________________________________";
	cout<<"\n                     |              MAIN MENU              |";
	cout<<"\n                     |                                     |";
	cout<<"\n                     | CHOOSE ONE OF THE FOLLOWING CHOICES |";
	cout<<"\n                     |   1. MASTER MIND                    |";
	cout<<"\n                     |      Break the code given by your   |";
	cout<<"\n                     |      opponent in less than 6 tries. |";
	cout<<"\n                     |   2. MENTAL MATHEMATICS             |";
	cout<<"\n                     |      Simple time based addition and |";
	cout<<"\n                     |      subtraction.                   |";
	cout<<"\n                     |   3. EXIT                           |";
	cout<<"\n                      _____________________________________";
	cout<<"\n                          ENTER YOUR DESIRED CHOICE:";
	}
    int choice;
    cin>>choice;
    if(choice==1)
    {
	rulesc();
	getch();
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n                 PLEASE ENTER CODE THAT IS TO BE GUESSED\n";
	int i, j, r, r1, r2, code[4], guess2[4], guess[4], guess1[4], guess3[4], guess4[4], black3, black4, white3, white4, black, white, black1, black2, white1, white2, win, tries;
	win=0;
	tries=0;
	for(i=0;i<4;i++)
	{
		cin>>code[i];
		if((code[i]!=1)&&(code[i]!=2)&&(code[i]!=3)&&(code[i]!=4)&&(code[i]!=5)&&(code[i]!=6))
		{
			i=i-1;
			cout<<" PLEASE ENTER 1 2 3 4 5 OR 6 \n";
		}
	}
	clrscr();
	while(win==0)
	{
		time_t t;
		t = time(NULL);
		r1=("%ld",t);
		cout<<"ENTER YOUR GUESS\n";
		for(int i=0;i<4;i++)
		{
			cin>>guess[i];
			if((guess[i]!=1)&&(guess[i]!=2)&&(guess[i]!=3)&&(guess[i]!=4)&&(guess[i]!=5)&&(guess[i]!=6))
			{
				i=i-1;
				cout<<"PLEASE ENTER 1 2 3 4 5 OR 6 \n";
			}
		}
		clrscr();
		if(tries==1)
		{
			display(guess1, black1, white1);
		}
		else if(tries==2)
		{
			display(guess2, black2, white2);
			display(guess1, black1, white1);
		}
		else if(tries==3)
		{
			display(guess3, black3, white3);
			display(guess2, black2, white2);
			display(guess1, black1, white1);
		}
		else if(tries==4)
		{
			display(guess4, black4, white4);
			display(guess3, black3, white3);
			display(guess2, black2, white2);
			display(guess1, black1, white1);
		}
		black=0;
		white=0;
		tries= tries+1;
		for(i=0;i<4;i++) /**checking with orignal*/
		{
			if(code[i]==guess[i])
			{
				black++;
			}
			else
			{
				for(j=0;j<4;j++)
				{
					if(code[i]==guess[j])
					{
						white++;
					}
				}
			}
		}
		display(guess, black, white);
		if(black==4)
		{
			win=1;
		}
		else if(tries==1)
		{
			for(i=0;i<4;i++)
				guess1[i]=guess[i];
			black1=black;
			white1=white;
		}
		else if(tries==2)
		{
			for(i=0;i<4;i++)
				guess2[i]=guess1[i];
			black2=black1;
			white2=white1;
			for(i=0;i<4;i++)
				guess1[i]=guess[i];
			black1=black;
			white1=white;
		}
		else if(tries==3)
		{
			for(i=0;i<4;i++)
				guess3[i]=guess2[i];
			black3=black2;
			white3=white2;
			for(i=0;i<4;i++)
				guess2[i]=guess1[i];
			black2=black1;
			white2=white1;
			for(i=0;i<4;i++)
				guess1[i]=guess[i];
			black1=black;
			white1=white;
		}
		else if(tries==4)
		{
			for(i=0;i<4;i++)
				guess4[i]=guess3[i];
			black4=black3;
			white4=white3;
			for(i=0;i<4;i++)
				guess3[i]=guess2[i];
			black3=black2;
			white3=white2;
			for(i=0;i<4;i++)
			guess2[i]=guess1[i];
			black2=black1;
			white2=white1;
			for(i=0;i<4;i++)
				guess1[i]=guess[i];
			black1=black;
			white1=white;
		}
		else if(tries==6)
		break;
	}
	if(win==1)
	{
		time_t t1;
		t1 = time(NULL);
		r=("%ld",t1);
		r2=r-r1;
		cout<<"\n\n\n                  CONGRATULATIONS!! YOU HAVE WON IN JUST "<<tries<<" TRIES. \n"<<"\t\t\t TIME TAKEN "<<r2<<" seconds";
	}
	else if(win==0)
	{
		cout<<"Sorry you lost.\n";
	}
	cout<<"\n                  Enter any key to exit.\n";
	getch();
}
	else if(choice==2)
	{
		clrscr();
		rulesm();
		getch();
		clrscr();
		int f, x, y, z, score, n1, n2, n;
		time_t t, t2, t1;
		srand((unsigned) time(&t));
		score=0;
		cout<<"\n\n\n\n\n\n";
		for(int i=0;i<12;i++)
		{
			t1 = time(NULL);
			n1=("%ld",t);
			f=0;
			x=0;
			y=0;
			z=0;
			f=("%d\n", rand() % 3000);
			cout<<"\t\t\t\t"<<f;
			y=("%d\n", rand() % 1000);
			cout<<"="<<y;
			if(y>f)
			{
				cout<<"-";
				cin>>x;
				z=y-x;
				if(z==f)
				{
					cout<<"\t\t\t\t\tCORRECT \n";
					score= score+2;
				}
				else
					cout<<"\t\t\t\t\tWRONG \n";
			}
			else
			{
				cout<<"+";
				cin>>x;
				z=y+x;
				if(z==f)
				{
					cout<<"\t\t\t\t\tCORRECT \n";
					score= score+2;
				}
				else
					cout<<"\t\t\t\t\tWRONG \n";
			}
			t1 = time(NULL);
			n=("%ld",t1);
			n2=n-n1;
		}
		cout<<"\n\n\t\t\t  ________________________";
		cout<<"\n\t\t\t | SCORE:  "<<score<<"              |";
		cout<<"\n\t\t\t | TIME TAKEN: "<<n2<<" seconds |";
		cout<<"\n\t\t\t  ________________________";
		getch();
	}
	else if(choice==3)
	{
		cout<<"BBBBYYYEEEEE";
		delay(3000);
	}
}