#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream.h>
char usr, cpu;
int uscore=0, cscore=0, gamelen, ichoice;
void intro();
void introchoice(int);
char cpumove(int);
int decide(char, char);
void play();
void verdict();
void main()
{
	intro();
	introchoice(ichoice);
	clrscr();
	cout<<"Please enter the gamelength\n";
	cin>>gamelen;
	while(!(uscore==gamelen || cscore==gamelen))// terminates when any
	{                                           // of the players reach
		randomize();                        // the gamelength limit
		clrscr();
		play();
	}
	clrscr();
	verdict();
	getch();
}
void intro()
{
	for(int i=0;i<10;i++)
	{
		cout<<"*";
	}
	cout<<"|| ROCK-PAPER-SCISSORS ||\n\n";
	cout<<"\t1) Create Profile\n\n";
	cout<<"\t2) Load Profile\n\n";
	cout<<"\t3) Rules\n\n";
	cout<<"\t4) Quit\n\n";
	cout<<"\tPress the corresponding key...\n";
	cin>>ichoice;
}
void introchoice(x)
{
	switch(x)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:cout<<"Please select a valid choice\n";
			goto start;
	}
}
void play()
/*this function shows the scores of both cpu and user and takes inputs of
  the moves of both */
{
	cout<<"Your Score:"<<uscore;
	cout<<"CPU's Score:"<<cscore<<endl;
	cout<<"Your move:";
	cin>>usr;
	cpu=cpumove(random(3));
	cout<<"CPU's move:"<<cpu;
	getch();
	if(decide(usr, cpu)==1)
	{
		uscore++;
	}
	if(!decide(usr, cpu))
	{
		cscore++;
		cout<<"\a";
	}
}
char cpumove(int x)
/* this function converts the randomly generated integer value in terms of
   charecters 'r' (Rock), 'p' (Paper) or 's' (Scissors) */
{
	char ch;
	switch(x)
	{
		case 0:	ch='r';
			break;
		case 1: ch='p';
			break;
		case 2: ch='s';
			break;
	}
	return ch;
}
int decide(char u, char c)
/* this function decides who takes away the point by the conventional
   priority of the game ( r>s ; s>p ; p>r ) */
{
	int x=2;
	/*default value for x is kept at 2 (some value except 0 & 1) for in
	case the decision is a tie*/
	if(u=='s' && c=='r')
	{
		x=0;
	}
	if(u=='p' && c=='s')
	{
		x=0;
	}
	if(u=='r' && c=='p')
	{
		x=0;
	}
	if(u=='r' && c=='s')
	{
		x=1;
	}
	if(u=='s' && c=='p')
	{
		x=1;
	}
	if(u=='p' && c=='r')
	{
		x=1;
	}
	return x;
}
void verdict()
/* this function makes the final decision of the winner by comparing the
   scores */
{
	if(cscore>uscore)
	{
		cout<<"YOU LOSE!!!\n";
	}
	else if(uscore>cscore)
	{
		cout<<"YOU WON!!!\n";
	}
	else
	{
		cout<<"IT'S A TIE!!!\n";
	}
}