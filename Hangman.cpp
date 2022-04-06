#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdio.h>
#include<ctype.h>

char A[40],B[100],C[40],D[40];
int i,n=3,a2,plyr1[50]={0},plyr2[50]={0},cnt=0;
using namespace std;
int main()
{
	void player1();
	void selectlett();
	void chooseword();
	void scorecard();
	void exitgame();
	int i,po=0,ans=0,count,loop=0;
	cout<<setw(62)<<"GUESS THE WORD GAME:- HANGMAN USING C++:\n";
	cout<<setw(64)<<"----- --- ---- ----   ------- ----- ---\n\n\n\n";
			  cout<<"->1. Player1 gives the word to guess, Player2 guesses the word using a hint that     Player1 gives.\n\n\n"
				  <<"->2. Player2 gets 3 chances to either guess the whole word or guess any of the       letters in the word.\n\n\n"
				  <<"->3. If Player2 choose to guess the whole word at once, he/she will have to do       it in one chance only.\n\n\n"
				  <<"->4. If Player2 choose to guess any letter in the word, if he/she does it            correctly, the number of chances remains same.\n\n\n"
				  <<"->5. The number of chances reduce if Player2 fails in the above written step.\n\n\n"
				  <<"->6. If ready, press '1' to play____: ";
	cin>>a2;
	x:
	while(a2==1)
	{
		if(po==0)
		{
			player1();
			system("cls");
		}
	po++;

	cout<<"\n\n\n\n\t***Player1 has given you the following word, with the following                    hint:\n\n\n";
	count=strlen(A);
	cout<<"\tThis is a "<<count<<" letter word.\n\n\tGIVEN HINT: ";
	puts(B);
	cout<<"\n\n\tNumber of available chances: "<<n;
	cout<<"\n\n\n\t\t\tTHE WORD: ";
	int a=strlen(A),c;
	for(i=0;i<a;i++)
		cout<<C[i]<<" ";	
	cout<<"\n\nPress 1 to guess a letter in the word or Press 2 to guess the word: ";
	cin>>c;
	if(c==1)
		selectlett();
	else if(c==2)
		chooseword();
	if(n==0&&loop==0)
	{
		system("cls");
		cout<<"\n\n\n\n\tAlas!! No more chances available :( " 
			<<"\n\n\n\tYou have the only option to guess the whole word now.";
			loop++;
	}		
	}
	y:
	cout<<"\n\n\n-> For seeing the scorecard, Press 1. Press 2 to play again. Press any key         to exit: ";
	cin>>ans;
	if(ans==1)
	{
		scorecard();
		cout<<"\n\n\n\n";
		system("pause");
		system("cls");
		cout<<"\n\n\n";
		goto y;
	}
	else if(ans==2)
	{
		a2=1;
		n=3;
		cnt++;
		po=0;
		goto x;
	}
	else
		exitgame();
return 0;
}

void player1()
{
		system("cls");
		cout<<setw(45)<<"NEW GAME:\n";
		cout<<setw(43)<<"--- ----";
		fflush(stdin);
		cout<<"\n\n\nFor player1 -> "
			<<"\n\n\nEnter the word to challange: ";
			gets(A);
			strupr(A);
		cout<<"\n\nEnter the hint: ";
		gets(B);
		int a=strlen(A);
		for(i=0;i<a;i++)
			C[i]='_';
		C[i]='\0';	
}

void selectlett()
{
	char a1;
	int a=strlen(A),p=0,d=0;
	for(i=0;i<a;i++)
	{
		if(C[i]=='_')
			d++;
	}
	if(n>0&&d>a/2)
	{
		cout<<"\n\n\t Enter your guessed letter: ";
		cin>>a1;
		a1=toupper(a1);
		for(i=0;i<a;i++)
		{
			if(A[i]==a1)
			{
				C[i]=A[i];
				p++;
			}
		}
		if(p!=0)
		{
			system("cls");
			cout<<"\n\n\t\tBingo! You've guessed a correct letter.";
		}
		else
		{
			system("cls");
			cout<<"\n\n\t\tAlas! You've guessed the incorrect letter.";
			n--;
		}
	}
	else
	{
		system("cls");
		cout<<"\n\n You've either guessed more than half of the word or you've ran out of options.."
			<<"\n    Now you can only guess the full word at once by pressing 2 in the option.";
	}
}

void chooseword()
{
	fflush(stdin);
	cout<<"\n\n\tEnter your guess: ";
	gets(D);
	strupr(D);
	if(strcmp(A,D)==0)
	{
		system("cls");
		cout<<"\n\n\n\n\t\t\tBINGO!! Player2 has won the game!!"
			<<"\n\n\t\t\tThe correct word was: "<<A;
		a2=2;
		plyr2[cnt]=1;
		plyr1[cnt]=0;
	}
	else
	{
		system("cls");
		cout<<"\n\n\n\n\t\t\tAlas!! Player1 has won the game!!"
			<<"\n\n\t\t\tThe correct word was: "<<A;
		a2=2;
		plyr2[cnt]=0;
		plyr1[cnt]=1;
	}
}

void scorecard()
{
	system("cls");
	cout<<setw(378)<<"Player1                    Player2"<<"\n\n";
	for(i=0;i<=cnt;i++)
	{
		cout<<endl<<setw(27)<<plyr1[i]<<"            |            "<<plyr2[i]<<endl;
	}
}

void exitgame()
{
	system("cls");
	cout<<setw(530)<<"Thanks For Playing. :-)"<<"\n\n\n";
}
