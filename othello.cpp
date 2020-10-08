#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>

using namespace std;

void Display(char [8][8]);
void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Display(char Board[8][8])
{
	system("cls");
 
 int i;
 for(i=0;i<8;i++)
 {
  printf("\t  +---+---+---+---+---+---+---+---+\n");
  cout<<"\t"<<i+1<<" | "<<Board[i][0]<<" | "<<Board[i][1]<<" | "<<Board[i][2]<<" | "<<Board[i][3]<<" | "<<Board[i][4]<<" | "<<Board[i][5]<<" | "<<Board[i][6]<<" | "<<Board[i][7]<<" |"<<endl;
 }
 printf("\t  +---+---+---+---+---+---+---+---+\n");
 printf("\t    A   B   C   D   E   F   G   H  ");
}
int main()
{
Intro:
srand(time(0));
system("cls");
int i,j,W,Done,Melon=0;
char A,B,pos[2],X,Y,Board[8][8];
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 Board[i][j]=' ';
}
printf("\t\t  ####****************************####\n"); 
printf("\t\t  ##\t      OTHELLO GAME    \t    ##\n"); 
printf("\t\t  ####****************************####\n");
printf("The Rules are as usual:\n\n");
printf("In the End, Player which will have more tokens than its Opponent Wins the Game\n\n");
printf(" !    @    #    $    %    ^    &    *    (    )    /    -    +    = \n\n");
Sleep(3000);
printf("Enter Your Token Symbol: "); 
cin>>A;
printf("Enter Opponent's Token Symbol: ");
cin>>B;
if(A==B)
{
 printf("\n\t\tLOL !!! Both the Tokens are Same........");
 Sleep(1000);
 goto Intro;
}
char tICK = A;
char Tick = B;
char *Quote[5]={"AND","THE","GAME","STARTS","NOW !!!"};
for(i=0;i<5;i++)
{
 cout<<"\n\n"<<"\t\t\t"<<Quote[i]<<"  ";
 Sleep(500);
}
Sleep(1000);
Board[3][3]=A; Board[3][4]=B;
Board[4][3]=B; Board[4][4]=A;
start:
Display(Board);
A = tICK;
cout<<endl<<"Your ("<<A<<") Turn........";
Sleep(1000);
printf("\nEnter Position: ( Like A1, G6, C3 etc. ) "); 
gets(pos);
cout<<endl;
pos[0]=toupper(pos[0]);
if(pos[0]=='A')
X = 0;
else if(pos[0]=='B')
X = 1;
else if(pos[0]=='C')
X = 2;
else if(pos[0]=='D')
X = 3;
else if(pos[0]=='E')
X = 4;
else if(pos[0]=='F')
X = 5;
else if(pos[0]=='G')
X = 6;
else if(pos[0]=='H')
X = 7;
else
{
 printf("Enter Again...");
 Sleep(500);
 goto start;
}
if(pos[1]=='1')
Y = 0;
else if(pos[1]=='2')
Y = 1;
else if(pos[1]=='3')
Y = 2;
else if(pos[1]=='4')
Y = 3;
else if(pos[1]=='5')
Y = 4;
else if(pos[1]=='6')
Y = 5;
else if(pos[1]=='7')
Y = 6;
else if(pos[1]=='8')
Y = 7;
else
{
 printf("Enter Again...");
 Sleep(500);
 goto start;
}
if(Board[Y][X]!=' ')
{
 printf("Enter Again...");
 Sleep(500);
 goto start;
}
Board[Y][X]=A;
B = Tick;
// Left Check
for(j=X-1;j>=0;j--)
{
 if(Board[Y][j]==B)
 Board[Y][j]=A;
 else
 break;
}
if(Board[Y][j]!=A)
{
 for(j=X-1;j>=0;j--)
 {
  if(Board[Y][j]==A)
  Board[Y][j]=B;
  else
  break;
 }
}
// Right Check
for(j=X+1;j<8;j++)
{
 if(Board[Y][j]==B)
 Board[Y][j]=A;
 else
 break;
}
if(Board[Y][j]!=A)
{
 for(j=X+1;j<8;j++)
 {
  if(Board[Y][j]==A)
  Board[Y][j]=B;
  else
  break;
 }
}
// Up Check
for(i=Y-1;i>=0;i--)
{
 if(Board[i][X]==B)
 Board[i][X]=A;
 else
 break;
}
if(Board[i][X]!=A)
{
 for(i=Y-1;i>=0;i--)
 {
  if(Board[i][X]==A)
  Board[i][X]=B;
  else
  break;
 }
}
// Down Check
for(i=Y+1;i<8;i++)
{
 if(Board[i][X]==B)
 Board[i][X]=A;
 else
 break;
}
if(Board[i][X]!=A)
{
 for(i=Y+1;i<8;i++)
 {
  if(Board[i][X]==A)
  Board[i][X]=B;
  else
  break;
 }
}
// UL Diagonal Check
i = Y-1; j = X-1;
while(i>=0 && j>=0)
{
 if(Board[i][j]==B)
 Board[i][j]=A;
 else
 break;
 i--; j--;
}
if(Board[i][j]!=A)
{
 i = Y-1; j = X-1;
 while(i>=0 && j>=0)
 {
  if(Board[i][j]==A)
  Board[i][j]=B;
  else
  break;
  i--; j--;
 }
}
// UR Diagonal Check
i = Y-1; j = X+1;
while(i>=0 && j<8)
{
 if(Board[i][j]==B)
 Board[i][j]=A;
 else
 break;
 i--; j++;
}
if(Board[i][j]!=A)
{
 i = Y-1; j = X+1;
 while(i>=0 && j<8)
 {
  if(Board[i][j]==A)
  Board[i][j]=B;
  else
  break;
  i--; j++;
 }
}
// DL Diagonal Check
i = Y+1; j = X-1;
while(i<8 && j>=0)
{
 if(Board[i][j]==B)
 Board[i][j]=A;
 else
 break;
 i++; j--;
}
if(Board[i][j]!=A)
{
 i = Y+1; j = X-1;
 while(i<8 && j>=0)
 {
  if(Board[i][j]==A)
  Board[i][j]=B;
  else
  break;
  i++; j--;
 }
}
// DR Diagonal Check
i = Y+1; j = X+1;
while(i<8 && j<8)
{
 if(Board[i][j]==B)
 Board[i][j]=A;
 else
 break;
 i++; j++;
}
if(Board[i][j]!=A)
{
 i = Y+1; j = X+1;
 while(i<8 && j<8)
 {
  if(Board[i][j]==A)
  Board[i][j]=B;
  else
  break;
  i++; j++;
 }
}
Display(Board);
Sleep(500);
Done = 1;
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 {
  if(Board[i][j]==' ')
  Done = 0;
 }
}
if(Done==1)
goto end;
/*                                */
cout<<endl<<"Opponent's ("<<B<<") Turn........";
Sleep(1000);
again:
X = rand()%8;
Y = rand()%8;
W = 0;
if(Board[Y][X]!=' ')
goto again;
 if(Board[Y+1][X]==A)
 W++;
 if(Board[Y][X+1]==A)
 W++;
 if(Board[Y+1][X+1]==A)
 W++;
 if(Board[Y-1][X]==A)
 W++;
 if(Board[Y][X-1]==A)
 W++;
 if(Board[Y-1][X-1]==A)
 W++;
 if(Board[Y+1][X-1]==A)
 W++;
 if(Board[Y-1][X+1]==A)
 W++;
if(W==0 && Melon<15)
goto again;
Board[Y][X] = B;
Melon++;
// Left Check
for(j=X-1;j>=0;j--)
{
 if(Board[Y][j]==A)
 Board[Y][j]=B;
 else
 break;
}
if(Board[Y][j]!=B)
{
 for(j=X-1;j>=0;j--)
 {
  if(Board[Y][j]==B)
  Board[Y][j]=A;
  else
  break;
 }
}
// Right Check
for(j=X+1;j<8;j++)
{
 if(Board[Y][j]==A)
 Board[Y][j]=B;
 else
 break;
}
if(Board[Y][j]!=B)
{
 for(j=X+1;j<8;j++)
 {
  if(Board[Y][j]==B)
  Board[Y][j]=A;
  else
  break;
 }
}
// Up Check
for(i=Y-1;i>=0;i--)
{
 if(Board[i][X]==A)
 Board[i][X]=B;
 else
 break;
}
if(Board[i][X]!=B)
{
 for(i=Y-1;i>=0;i--)
 {
  if(Board[i][X]==B)
  Board[i][X]=A;
  else
  break;
 }
}
// Down Check
for(i=Y+1;i<8;i++)
{
 if(Board[i][X]==A)
 Board[i][X]=B;
 else
 break;
}
if(Board[i][X]!=B)
{
 for(i=Y+1;i<8;i++)
 {
  if(Board[i][X]==B)
  Board[i][X]=A;
  else
  break;
 }
}
// UL Diagonal Check
i = Y-1; j = X-1;
while(i>=0 && j>=0)
{
 if(Board[i][j]==A)
 Board[i][j]=B;
 else
 break;
 i--; j--;
}
if(Board[i][j]!=B)
{
 i = Y-1; j = X-1;
 while(i>=0 && j>=0)
 {
  if(Board[i][j]==B)
  Board[i][j]=A;
  else
  break;
  i--; j--;
 }
}
// UR Diagonal Check
i = Y-1; j = X+1;
while(i>=0 && j<8)
{
 if(Board[i][j]==A)
 Board[i][j]=B;
 else
 break;
 i--; j++;
}
if(Board[i][j]!=B)
{
 i = Y-1; j = X+1;
 while(i>=0 && j<8)
 {
  if(Board[i][j]==B)
  Board[i][j]=A;
  else
  break;
  i--; j++;
 }
}
// DL Diagonal Check
i = Y+1; j = X-1;
while(i<8 && j>=0)
{
 if(Board[i][j]==A)
 Board[i][j]=B;
 else
 break;
 i++; j--;
}
if(Board[i][j]!=B)
{
 i = Y+1; j = X-1;
 while(i<8 && j>=0)
 {
  if(Board[i][j]==B)
  Board[i][j]=A;
  else
  break;
  i++; j--;
 }
}
// DR Diagonal Check
i = Y; j = X;
while(i<8 && j<8)
{
 if(Board[i][j]==A)
 Board[i][j]=B;
 else
 break;
 i++; j++;
}
if(Board[i][j]!=B)
{
 i = Y; j = X;
 while(i<8 && j<8)
 {
  if(Board[i][j]==B)
  Board[i][j]=A;
  else
  break;
  i++; j++;
 }
}
Display(Board);
Sleep(500);
Done = 1;
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 {
  if(Board[i][j]==' ')
  Done = 0;
 }
}
if(Done==1)
goto end;
goto start;
end:
cout<<endl;
Sleep(1000);
int Pla=0,Opp=0;
for(i=0;i<8;i++)
{
 for(j=0;j<8;j++)
 {
  if(Board[i][j]==A)
  Pla++;
  if(Board[i][j]==B)
  Opp++;
 }
}
system("cls");
if(Pla>Opp)
{
 gotoxy(30,10);
 printf("YOU WON THE GAME !!!!!!");
}
if(Pla<Opp)
{
 gotoxy(30,10);
 printf("OPPONENT WON THE GAME !!!!!!");
}
if(Pla==Opp)
{
 gotoxy(30,10);
 printf("IT IS A DRAW !!!!!!");
}
getch();
}
