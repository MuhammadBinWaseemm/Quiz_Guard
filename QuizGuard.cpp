#include<iostream>
#include <windows.h>  
#include <random>
using namespace std;
#include"AccountHash.cpp"
#include <chrono>
#include <thread>
int main()
{
	HANDLE console_color; 
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color,10);
	auto start = high_resolution_clock::now();
	Account A;
	char ch;
	int Ch,Q;
	int a;
	string name;
	while(1)
	{
		Sign:system("cls");
		cout<<"\n\t\tQuizGuard";
		cout<<"\n\t\t1.SignUp";
		cout<<"\n\t\t2.SignIn";
		cout<<"\n\nExit(E)";
		cout<<"\n\t\tChoose between (1-2) : ";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case '1':
				A.SignUp();
				break;
			case '2':
				a=A.Signin();
				if(a==1)
					break;
				while(1)
				{
					wr1:system("cls");
					wr:;
					
					cout<<"\n\t\tQuiz Portal";
					cout<<"\n\t\t1.Create a Quiz";
					cout<<"\n\t\t2.View Quizzez";
					cout<<"\n\t\t3.Answer Quiz";
					cout<<"\n\t\t4.View Quiz Results";
					cout<<"\n\t\t5.Delete a Quiz";
					cout<<"\n\t\t6.View Stats";
					cout<<"\n\t\t7.Time Complexity";
					cout<<"\n\t\t8.SignOut";
					cout<<"\n\t\tChoose from (1-8) : ";
					cin>>Ch;
					cin.ignore();
					switch(Ch)
					{
						case 1:
							system("cls");
							cout<<"\n\t\tName of Quiz : ";
							getline(cin,name);
							zero:;
							cout<<"\n\t\tNumber of Questions : ";
							cin>>Q;
							cin.ignore();
							if(Q==0)
							{
								cout<<"\n\t\tNo. of Questions can't be 0";
								goto zero;
							}
							A.createQuiz(name,Q);
					
							break;
						case 2:
							A.displayUserQuizzes();
							system("pause");
							break;
						case 3:
							wr3:;
							Q=A.displayallQuizzes();
							if(Q==0)
							{
								cout<<"\n\t\tNo Quizzez ";
								system("pause");
								goto wr1;
								
							}
							cout<<"\n\t\tEnter Quiz Name you want to answer : ";
							getline(cin,name);
							Q=A.searchquiz(name);
							if(Q==0)
							{
								cout<<"\n\t\tNo such quiz";
								system("pause");
								goto wr3;
							}
							WR:system("cls");
							cout<<"\n\t\tBefore answering the quiz , we would like to ask you.";
							cout<<"\n\t\tFor this quiz , do you want us to ";
							cout<<"\n\t\t1.Prioritize Marks over Time(Greedy Algorithm)";
							cout<<"\n\t\t2.Prioritize Time over Marks(Dynamic Programming(KnapSack))";
							cout<<"\n\t\tChoose between (1-2) : ";
							cin>>Q;
							cin.ignore();
							if(Q!=1 && Q!=2)
							{
								cout<<"\n\t\tInvalid input";
								goto WR;
							}
							A.giveQuiz(name,Q);
							break;
						case 4:
							system("cls");
							A.displayUserQuizzes();
							
							A.displayResults();
							
							system("pause");
							
							
							break;
						case 5:
							A.displayUserQuizzes();
							A.deleteQuiz();
							system("pause");
							
							break;
						
						case 6:
							system("cls");
							A.viewstats();
							
							system("pause");
							break;
						case 7:
								{
							
							auto end = high_resolution_clock::now();
							auto duration = duration_cast<microseconds>(end - start);
							cout << "Execution time: " << (float)(duration.count()/(1000000))/60 << " minutes" << endl;
							 system("pause");
							break;
						}
						case 8:
							goto Sign;
						default:
							{
								SetConsoleTextAttribute(console_color,4);
							cout<<"\n\t\tInvalid Input'n'";
							SetConsoleTextAttribute(console_color,10);
							system("pause");
							system("cls");
							goto wr;
							break;
						}
					}
				}
				break;
			case 'e':
			case 'E':
			
				return 0;
				break;
			default:
				cout<<"Invalid Input";
				break;
		}
	}
}
	
	
