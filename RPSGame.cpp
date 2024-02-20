#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<time.h>
char usr, cpu;
int uscore=0, cscore=0, gamelen, ichoice;
void clrscr();
char cpumove(int);
int decide(char, char);
void play();
void verdict();
int main()
{
	srand(time(0)); // rand() seeding using current time
	clrscr();
	std::cout<<"Please enter the gamelength\n";
	std::cin>>gamelen;
	while(!(uscore==gamelen || cscore==gamelen))// terminates when any
	{                                           // of the players reach
		clrscr();							// the gamelength limit
		play();
	}
	clrscr();
	verdict();
	getch();
	return 0;
}
void clrscr() {
	printf("\e[1;1H\e[2J");
}
void play()
/*this function shows the scores of both cpu and user and takes inputs of
  the moves of both */
{
	std::cout<<"Your Score:"<<uscore;
	std::cout<<"CPU's Score:"<<cscore<<std::endl;
	std::cout<<"Your move:";
	std::cin>>usr;
	cpu=cpumove(rand() % 3);
	std::cout<<"CPU's move:"<<cpu;
	getch();
	if(decide(usr, cpu)==1)
	{
		uscore++;
	}
	if(!decide(usr, cpu))
	{
		cscore++;
		std::cout<<"\a";
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
		std::cout<<"YOU LOSE!!!\n";
	}
	else if(uscore>cscore)
	{
		std::cout<<"YOU WON!!!\n";
	}
	else
	{
		std::cout<<"IT'S A TIE!!!\n";
	}
}