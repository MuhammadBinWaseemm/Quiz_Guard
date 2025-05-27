#include<windows.h>
#include<iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;


// Function to greedily select questions based on marks (values), even if it exceeds capacity (time)
void greedyQuizGuard(vector<int>& weights, vector<int>& values, int capacity , vector<int>& selectedQuestions) 
{
    // Create a vector of tuples (weight, value, index) to track original indices
    vector<pair<pair<int, int>, int>> questions;  // Each question: pair of (weight, value) and its original index
    for (int i = 0; i < values.size(); i++) {
        questions.push_back({{weights[i], values[i]}, i}); // Store weight, value, and original index
    }

    // Sort by value (marks) in descending order (compare based on the second element of the pair)
    sort(questions.begin(), questions.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.first.second > b.first.second; // Compare based on marks (second element in the first pair)
    });

    int totalTime = 0;
    int totalMarks = 0;
    
    // Greedily select questions, prioritizing marks over time (even if the time exceeds the capacity)
    for (int i = 0; i < questions.size(); i++) 
	{
        totalTime += questions[i].first.first; // Add time (weight)
        totalMarks += questions[i].first.second; // Add marks (value)
        selectedQuestions.push_back(questions[i].second); // Add original index of the selected question
    }


    cout << endl;
}

// Function to solve the 0/1 Knapsack problem to determine which questions to prioritize
int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n, vector<int>& selectedQuestions) 
{
    // Create a DP table to store the maximum value for each subproblem
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++) 
	{
        for (int w = 1; w <= capacity; w++) 
		{
            // If the weight of the current item (time for the question) is less than or equal to the current capacity
            if (weights[i - 1] <= w) 
			{
                // Choose the maximum between including the item (question) and excluding it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else 
			{
                // If the weight of the item is more than the current capacity, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find which questions were selected
    int w = capacity;
    for (int i = n; i > 0; i--) 
	{
        if (dp[i][w] != dp[i - 1][w]) 
		{
            selectedQuestions.push_back(i - 1);  // Add the question index to the selected list
            w -= weights[i - 1];  // Reduce the remaining capacity
        }
    }

    // Return the maximum value (score) we can achieve
    return dp[n][capacity];
}
class Colors
{
	public:	
	    int color=10;
	    int color1;
	    void Design()
	    {
	    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,color1);
		    cout<<"  ";
	    	
		}
	    const void Default()
	    {
	    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,color);
		}
	    const void Black()
	    {
	    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,0);
		    cout<<"  ";
		}
		const void White()
		{
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,255);
		    cout<<"  ";
		}
	    const void DarkBlue()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		    SetConsoleTextAttribute(console_color,1);
		    color1=17;
		}
		const void DarkGreen()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,2);
			color1=34;
		}
		const void Red()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
			color1=68;
		}
		const void DarkPurple()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,5);
			color1=85;
		}
		const void Gold()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,6);
			color1=102;
		}
		const void Blue()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,9);
			color1=153;
		}
		const void Green()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
			color1=170;
		}
		const void Turquoise()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,11);
			color1=187;
		}
		const void Coral()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		    SetConsoleTextAttribute(console_color,12);
		    color1=204;
		}
		const void Pink()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,13);
			color1=221;
		}
		const void White1()
		{
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,15);
			color1=255;
		}
};
class Theme
{
	public:
		int color1;
		int color2;
		const void Design()
		{
			HANDLE console_colorr; 
			SetConsoleTextAttribute(console_colorr,color1);
			cout<<" ";
			SetConsoleTextAttribute(console_colorr,color2);
			cout<<" ";
		}
		const void Default()
		{
			HANDLE console_colorr; 
            console_colorr = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_colorr, 15);
			color1=0;
			color2=255;
		}
		const void Zebra()
		{
		    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color,240);
            color1=255;
            color2=0;
		}
		const void Aqua()
		{
		    HANDLE console_colorr; 
            console_colorr = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_colorr,177);
			color1=187;
			color2=17;
		}
		const void Buraikan()
		{
		    HANDLE console_colorr; 
            console_colorr = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_colorr,96);
            color1=102;
            color2=0;
		}
		const void Blueberry()
		{
		      HANDLE console_colorr; 
            console_colorr = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_colorr,180);
            color1=187;
            color2=68;
		}
		const void Jamun()
		{
		    HANDLE console_colorr; 
            console_colorr = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_colorr,219);
            color1=221;
            color2=187;
		}	
};
class Account
{
private:
	                       //complex hash constants (k values)
const unsigned int k[64] =
{
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

    // Actual
    string username;
    string salt="";
    string pepper="";
    string hashedpassword;        // Variables for storing Hashed Values
    string hashedschool;
    string hasheddate;
    // Testing
    string input;
    char Ch;
     struct Questions                       //Queue for Questions
    {
    	string Q;
    	string A;
    	int marks;
    	int markgain=0;
    	Questions *next;
    	Questions *prev;
    	int key;
	};
	struct list
{
	float time;
	int max;
	int marks;
	string name;
	list *next;
};
    struct Quiz                            //LinkedList for Quizzez
	{
	    string Name;
	    int questions;
	    int time;
	    int marks;
	    int theme;
	    Questions *front;
	    Quiz *next;            // Points to the next quiz in the list of this user
	    vector<int> weights;
	    vector<int> values;
		list *Result=nullptr;    
};



struct stack
{
	string Q;
	stack *next;
};

vector<int> selectedQuestionss;
vector<int> selectedQuestions;
    //LinkedList Variables
    struct Node
    {
    	Node *next;
    	string Username;
    	string Salt="";
    	string Pepper="";
    	int key;
    	string password;                    //Variables for List
    	string date;
    	string school;
    	Quiz *quizList;
    	int max=0;
    	int score=0;
    	int Total=0;
    	float timeava=0;
    	float timetaken=0;
    	int num=0;
    	float per=0;
    	bool enable=0;
	};
	
    Node *head=nullptr;
    Node *current=nullptr;
    int currentkey=1;
    int K;
	struct AllQuiz
	{
		string Name;
	    int questions;
	    int time;
	    int marks;
	    int theme;
	    AllQuiz *next;  // Points to the next quiz in the list of this user
	    string User;
	};
	AllQuiz *Front=nullptr;    //For All Quizzez
Colors C;
Theme T;


public:
	void Resultins(list *&Res , string name, float time , int marks,int max)
	{
	list *newNode=new list;
	newNode->name=name;
	newNode->max=max;
	newNode->time=time;
	newNode->marks=marks;
	newNode->next=nullptr;
	if(Res==nullptr)
	{
		Res=newNode;
		
	}
	else
	{
		list *temp=Res;
		while(temp->next!=nullptr)
		{
			temp=temp->next;
		}
		temp->next=newNode;
	}
	}
	void push(stack *&top ,string Q)
{
	stack *temp=new stack;
	temp->Q=Q;
	if(top==nullptr)
	{
		temp->next=nullptr;
		top=temp;
		
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}
bool isempty(stack *top)
{
	return top==nullptr;
	
}
void pop(stack *&top)
{
	if(isempty(top)==1)
	{
		cout<<"\n\t\tSpellBook is empty ";
		
	}
	else
	{
		stack *temp=top;
		top=temp->next;
		delete temp;
	}
}

string peek(stack *&top)
{
	string ans;
	cout<<top->Q;
	cout<<"\n\nprev                                                next";
	cout<<"\n\t\t\t\tEnd";
	cout<<"\n\t\tYour Answer : ";
	getline(cin,ans);
	return ans;

}
    void SignUp()
    {
    	taken:system("cls");
        cout << "\n\t\t\tAccount SignUp\n";                                       //Account SignUp
        cout << "\nUsername : ";
        getline(cin, username); 
        if(userexists())
        {
        	PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"), NULL, SND_FILENAME | SND_SYNC);
        	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        	cout<<"\n\t\tUsername already Taken\n";
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
        	system("pause");
        	goto taken;
		}
        PasswordCheck(input);
        for (int i = 0; i < 32; ++i)                               //generating salt
    		salt += generateSecureRandomCharacter();
    	for (int i = 0; i < 32; ++i)                                    //generating pepper
    		pepper += generateSecureRandomCharacter();
        hashedpassword = complex_hash(input,salt,pepper,currentkey);
        SecureZeroMemory(&input[0], input.size());                 // Securely wipe memory after hashing
        cout << "\nDate of birth(D/M/Y) : ";
        getline(cin, input);  
        hasheddate = complex_hash(input,salt,pepper,currentkey);
        SecureZeroMemory(&input[0], input.size());         // Securely wipe memory after hashing
        cout << "\nInstitution Name(Abbreviation) : ";
        getline(cin,input);
        hashedschool = complex_hash(input,salt,pepper,currentkey);
        SecureZeroMemory(&input[0], input.size());                 // Securely wipe memory after hashing
        cout<<"\n\t\tSignUp Complete";
        PlaySound(TEXT("C:/Users/PC/Downloads/Bubble.wav"), NULL, SND_FILENAME | SND_SYNC);
        system("pause");
        insertNode();
        system("cls");
	}
    int Signin()
    {
    	char ch;
    	int i = 0;
        system("cls");
        cout << "\n\t\t\tSignin";                                  //SignIn
        int count = 0;
        char check;
        while (1)
        {
            cout << "\nUsername : ";
            getline(cin, username);  
            if(username=="Admin")                               //For Admin Purposes
            {  
            	cout<<"\nPassword : ";
            	cin>>input;
            	if(input=="@@@")
            	{
            		printlist();
	            	system("pause");
					return 1;	
				}
			}
            if (!searchuser())                               //Check if user exists
            {
                PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"), NULL, SND_FILENAME | SND_SYNC);
                HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
                cout << "\nUser not found.";
                
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
                continue;
            }
            	
            while (1)
		    {
                cout << "\nPassword : ";               
                getline(cin,input);
                if (complex_hash(input,salt,pepper,K) != hashedpassword)
                {
                    PlaySound(TEXT("C:/Users/PC/Downloads/Denied.wav"), NULL, SND_FILENAME | SND_SYNC);
                    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
                    cout << "\nWrong Password.";
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
                    count++;
                    if (count >= 3)
                    {
                    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
                        cout << "\n\t\t\tForgot Password?(y/n)";
 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
                        cin >> check;
                        cin.ignore();  // To clear the buffer after reading a char input
                    }
                    if (check == 'y' || check == 'Y')
                    {
                        Forgot();
                        return 0;
                    }
                    continue;
                }
                SecureZeroMemory(&input[0], input.size());
                break;
            }
            PlaySound(TEXT("C:/Users/PC/Downloads/Bubble.wav"), NULL, SND_FILENAME | SND_SYNC);
            system("cls");
            return 0;
        }
    }

    void Forgot()                                    //Function for authorization when user forgets password
    {
    	string date;
        system("cls");
        	while (1)
            {
                cout << "\nEnter your Date of birth(D/M/Y) : ";
                getline(cin, date);  
                cout << "\nEnter your Institution Name(Abbreviation) : ";
                getline(cin, input);  
                 
                if (complex_hash(date,salt,pepper,K) == hasheddate && complex_hash(input,salt,pepper,K) == hashedschool)
                {
                	SecureZeroMemory(&date[0], date.size());      // Securely wipe memory after hashing
          		    SecureZeroMemory(&input[0], input.size());   // Securely wipe memory after hashing
                    Change();
                    break;
                }
                else
                {
                    PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"), NULL, SND_FILENAME | SND_SYNC);
                    HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
                    cout << "\n\t\tPrivate information doesn't match. Try Again.";
   
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
                    continue;
                }
            }
            
    }

    void Change()                                           //function for additional account services
    {
        int x;
        while (1)
        {
            PlaySound(TEXT("C:/Users/PC/Downloads/Bubble.wav"), NULL, SND_FILENAME | SND_SYNC);
            cout<<"\n\t\tAuthenticated ! \n\t\t";
            system("pause");
            system("cls");
            cout << "\n\t\t\tAccount Recovery";
            cout << "\n\t\t\t1.Change Username";
            cout << "\n\t\t\t2.Change Password";
            cout << "\n\t\t\t3.Delete Account";
            cout << "\n\t\t\tChoose from (1-3)  ";
            cout << "\nReturn(R)";
            cout << "\n\t\tYou choose:";
            cin >> Ch;
            cin.ignore();  // To clear the buffer after reading a char input
            switch (Ch)
            {
            case '1':
            	system("cls");
            	again:;
            	cout<<"\n\t\tEnter new username : ";
            	input=username;
            	getline(cin,username);
            	if(userexists())
            	{
            		PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"), NULL, SND_FILENAME | SND_SYNC);
            		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
            		cout<<"\n\t\tSorry , username already taken\n";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
            		system("pause");
            		goto again;
				}
            	updateuser();
            	cout << "\n\t\tYour username has been changed !";
            	PlaySound(TEXT("C:/Users/PC/Downloads/Bubble.wav"), NULL, SND_FILENAME | SND_SYNC);
                system("pause");
                break;
            case '2':
                system("cls");
                PasswordCheck(input);
                hashedpassword = complex_hash(input,salt,pepper,K);
                updatepass();
                SecureZeroMemory(&input[0], input.size());              // Securely wipe memory after hashing
                cout << "\n\t\tYour password has been changed !";
                PlaySound(TEXT("C:/Users/PC/Downloads/Bubble.wav"), NULL, SND_FILENAME | SND_SYNC);
                system("pause");
                break;
            case '3':
                system("cls");
                cout << "\n\t\tAre you sure you want to delete your account(y/n)?";
                cin >> Ch;
                cin.ignore();                             // To clear the buffer after reading a char input
                if (Ch == 'y' || Ch == 'Y')
                {
	                delnode();
	                SecureZeroMemory(&hashedpassword[0],hashedpassword.size());              // Securely wipe memory after hashing
	                SecureZeroMemory(&hasheddate[0], hasheddate.size());                    // Securely wipe memory after hashing
	                SecureZeroMemory(&hashedschool[0], hashedschool.size());                 // Securely wipe memory after hashing
	                SecureZeroMemory(&salt[0], salt.size()); 
	                SecureZeroMemory(&pepper[0],pepper.size());
	                K=0;
                    x = 1;
                    cout << "\n\t\tYour Account has been deleted !";
                    PlaySound(TEXT("C:/Users/PC/Downloads/Bubble.wav"), NULL, SND_FILENAME | SND_SYNC);
                    system("pause");
                }
                break;
            case 'R':
            case 'r':
                x = 1;
                break;
            default:
                PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"), NULL, SND_FILENAME | SND_SYNC);
                HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
                cout << "\n\t\t\tInvalid command";
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
                break;
            }
            if (x == 1)
                break;
        }
    }
int enqueue(Questions *&front, int Q) 
{
    // Base Case: if the queue is empty (front is null), create a new node
    static int q = 1;
    static int Marks = 0;
    if (q - 1 == Q) {
        q = 1;
        return Marks;
    }

    Questions *newnode = new Questions;

    cout << "\n\t\tEnter Question " << q << " : ";
    getline(cin, newnode->Q);
	
    cout << "\n\t\tEnter Answer " << q << " : ";
    getline(cin, newnode->A);

    cout << "\n\t\tEnter Marks of question " << q << " : ";
    cin >> newnode->marks;
    cin.ignore();
    Marks += newnode->marks;

    // Initialize new node's pointers
    newnode->next = nullptr;  // New node's next pointer should be nullptr initially
    newnode->prev = nullptr;  // New node's prev pointer should be nullptr initially

    // If the queue is empty, make the new node both front and rear
    if (front == nullptr) {
        front = newnode;  // Set the front to the new node
    } else {
        // Traverse to the end of the list and link the new node
        Questions* temp = front;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newnode;  // Set last node's next to new node
        newnode->prev = temp;  // Set new node's prev to the last node
    }

    q++;  // Increment the question number
    enqueue(front, Q);  // Recursively call the enqueue function for the next question

    return Marks;
}


    void insertNode()                                      //inserting Node to head function
{
	Node *newNode=new Node;
	newNode->Username = username;
	SecureZeroMemory(&username[0],username.size());
	
	newNode->Salt = salt;
	newNode->Pepper = pepper;
	newNode->key = currentkey++;
	SecureZeroMemory(&pepper[0],pepper.size());
    SecureZeroMemory(&salt[0],salt.size());
	newNode->next=nullptr;
	newNode->password=hashedpassword;
	SecureZeroMemory(&hashedpassword[0], hashedpassword.size());
	newNode->date=hasheddate;                                                //assigning values 
	newNode->school=hashedschool;
	newNode->quizList = nullptr;
	SecureZeroMemory(&hasheddate[0], hasheddate.size());                       //securley wiping
	SecureZeroMemory(&hashedschool[0], hashedschool.size());
	if(head==nullptr)
	{
		head=newNode;
		
	}
	else
	{
		Node *temp=head;
		while(temp->next!=nullptr)
		{
			temp=temp->next;
		}
		temp->next=newNode;
	}
	
	
}
void printlist()                                      //function to print List for understanding
{
	system("cls");
	cout<<"\n\t\tList Of Accounts : \n\n";
	if(head==nullptr)
	{
		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
		cout<<"\n\t\tNo Accounts\n";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
	}
	else
	{
		Node *temp=head;
			while(temp!=nullptr)
		{
			cout<<temp->key<<".\tUsername :  "<<temp->Username<<"\n\n\tSalt : "<<temp->Salt<<"\n\n\tPepper : "<<temp->Pepper;
			cout<<"\n\n\tPassword : "<<temp->password<<endl<<endl;
			temp=temp->next;
		}
	}
}
void delnode()
{
	Node *temp=head;
	Node *prev=nullptr;
	if(username==head->Username)
	{
		head=temp->next;
		deleteQuizList(temp->quizList);
		delete temp;
		return;
	}
	while(temp != nullptr)
	{
		if(temp->Username==username)
		{
			deleteQuizList(temp->quizList);
			prev->next=temp->next;
			delete temp;
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
	cout<<"\n\t\tTarget not found";
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
}
int searchuser()                                  //searching for user
{
    Node *temp = head;
    while (temp != nullptr) 
	{
      
        if (username == temp->Username) 
		{
			K=temp->key;
            pepper = temp->Pepper;
            salt = temp->Salt;
            hashedpassword = temp->password;
            hasheddate=temp->date;
            hashedschool=temp->school;
            current=temp;
            return 1;  
        }
        temp = temp->next;  
    }
    return 0;  
}

int userexists()                                  //checking if userexits
{
	Node *temp=head;
	while(temp!=nullptr)
	{
		if(username!=temp->Username)
		{	
			temp=temp->next;
			continue;
		}
		else
			return 1;
	}
	return 0;
}
void updatepass()                   //function to change password
{
	Node *temp=head;
	while(temp!=nullptr)
	{
		if(username==temp->Username)
		{	
			temp->password=hashedpassword;
			return;
		}
		temp=temp->next;
	}
}
void updateuser()             //function to change username
{
	Node *temp=head;
	while(temp!=nullptr)
	{
		if(input==temp->Username)
		{	
			temp->Username=username;
			return;
		}
		temp=temp->next;
	}
}
void createQuiz(string Name,int questions) 
{
	char ch;
	Colors C;
	Theme T;
	AllQuiz* newQ = new AllQuiz;
    Quiz* newQuiz = new Quiz;
    newQuiz->Name = Name;
    newQ->Name = Name;
    newQuiz->next = nullptr;
    newQ->next = nullptr;
    newQuiz->questions = questions;
    newQ->questions = questions;
    newQuiz->front=nullptr;
    newQuiz->marks=enqueue(newQuiz->front,questions);
    newQ->marks=newQuiz->marks;
    cout<<"\n\t\tEnter Time Limit(in minutes) : ";
    cin>>newQuiz->time;
    cin.ignore();
    newQ->time=newQuiz->time;
    Themes:system("cls");
    cout<<"\n\t\tSet a Theme : ";
	cout<<"\n\n\t1.Default        ";
	T.Default();
	T.Design();
	C.Default();
	cout<<"\n\n\t2.Zebra          ";
	T.Zebra();
	T.Design();
	C.Default();
	cout<<"\n\n\t3.Aqua           ";
	T.Aqua();
	T.Design();
	C.Default();
	cout<<"\n\n\t4.Buraikan       ";
	T.Buraikan();
	T.Design();
	C.Default();
	cout<<"\n\n\t5.Blueberry      ";
	T.Blueberry();
	T.Design();
	C.Default();
	cout<<"\n\n\t6.Strawberry     ";
	T.Jamun();
	T.Design();
	C.Default();
	cout<<"\n\nConfirm(C)";
	cout<<"\n\n\t\t"<<Name;
	cout<<"\n\n\tChoose from (1-6) : ";
	choice:;
	cin>>ch;
	cin.ignore();
	switch(ch)
	{
		case '1':
			T.Default();
			C.color=15;
			newQuiz->theme=15;
			break;
		case '2':
			T.Zebra();
			C.color=240;
			newQuiz->theme=240;
			break;
		case '3':
			T.Aqua();
			C.color=177;
			newQuiz->theme=177;
			break;
		case '4':
			T.Buraikan();
			C.color=96;
			newQuiz->theme=96;
			break;
		case '5':
			T.Blueberry();
			C.color=180;
			newQuiz->theme=180;
			break;
		case '6':
			T.Jamun();
			C.color=219;
			newQuiz->theme=219;
			break;
		case 'c':
		case 'C':
			goto settings;
			break;
		default:
			HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
			cout<<"\n\t\tInvalid Choice";
	
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
			goto choice;
			break;
	}
	goto Themes;
	settings:system("cls");
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color,10);
	cout<<"\n\t\tQuiz Complete !";
	PlaySound(TEXT("C:/Users/PC/Downloads/Bubble.wav"), NULL, SND_FILENAME | SND_SYNC);
    system("pause");		
	newQ->theme=newQuiz->theme;		
	newQ->User=current->Username;
	if (current->quizList == nullptr) 
        current->quizList = newQuiz;  // If no quizzes, this quiz becomes the first one
    else 
	{
        Quiz* temp = current->quizList;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newQuiz;  // Add the new quiz at the end of the quiz list
    }
    if (Front == nullptr) 
        Front = newQ;  // If no quizzes, this quiz becomes the first one
    else 
	{
        AllQuiz* temp = Front;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newQ;  // Add the new quiz at the end of the quiz list
    }
}
void displayResults() 
{
	string name;
	int count=0;
	if (current->quizList == nullptr) 
	{
		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "No quizzes so no Results\n";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
        return;
    }
    cout<<"\n\t\tEnter Quiz name you want to view results of : ";
	getline(cin,name);
    Quiz* temp = current->quizList;
    for(int i=1 ;temp != nullptr ; i++ , temp=temp->next) 
	{
		if(name==temp->Name)
		{
			count=1;
			
			break;
		}

    }
    if(count==0)
    {
    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
    	cout<<"\n\t\tNo such quiz";

			SetConsoleTextAttribute(console_color,10);
			
			return;
	}
    
    list *rex=temp->Result;
    if (temp->Result == nullptr) 
	{
		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "No Results yet \n\n";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
        return;
    }
    cout<<"\n\t\tQuiz Results";
    for(int i=1 ;rex != nullptr ; i++ , rex=rex->next) 
	{
		cout<<"\n\t\t"<<i<<".\tUser : "<<rex->name;
		cout<<"\n\t\t"<<"\tMarks : "<<rex->marks<<"/"<<temp->marks;
		cout<<"\n\t\t"<<"\tTime taken : "<<rex->time<<" seconds \n";
    }
    
}
// Function to display quizzes of a user
void displayUserQuizzes() 
{
    if (current->quizList == nullptr) 
	{
		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "No quizzes created by " << current->Username << endl;

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
        return;
    }

    cout << "Quizzes created by " << current->Username << ":\n";
    Quiz* temp = current->quizList;
    for(int i=1 ;temp != nullptr ; i++ , temp=temp->next) 
	{
        cout << i << "." ;
        HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color,temp->theme);
		cout<<temp->Name<< endl;
		SetConsoleTextAttribute(console_color,10);
    }
}
int displayallQuizzes() 
{
    if (Front == nullptr) 
	{
		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "No quizzes "<<endl;
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
        return 0;
    }

    cout << "Quizzes : \n";
    AllQuiz* temp = Front;
    for(int i=1 ;temp != nullptr ; i++ , temp=temp->next) 
	{
        cout << i << "." ;
        HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color,temp->theme);
		cout<<temp->Name<< endl;
		SetConsoleTextAttribute(console_color,10);
    }
    return 1;
}
int searchquiz(string &name)
{
	AllQuiz* temp = Front;
    while(temp != nullptr) 
	{
        if(name==temp->Name)
        	return 1;
        temp=temp->next;
    }
    return 0;
}
void giveQuiz(string name,int type)
{
	
	AllQuiz *temp=Front;
	string User;
	while(temp!=nullptr)
	{
		if(name==temp->Name)
		{
			User=temp->User;                  //saves user name
			break;
		}
		temp=temp->next;
	}
    Node* Current = head;  
    while (Current != nullptr) 
	{ 
        if (Current->Username == User)                        //finds user
             break;
        Current = Current->next;  // Move to the next node
    } 
    Quiz *Temp = Current->quizList;                 //Saves Quiz Node at which user's quizzez are
    while(Temp!=nullptr)
    {
    	if(Temp->Name==name)                  //Quiz name
    		break;
    	Temp=Temp->next;	                                                      
	}
	Questions *Quizzez=Temp->front;        //Node of Questions of Quiz being saved
	
	HANDLE console_color; 
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, Temp->theme);
    
	if(type==1)
	{
		while(Quizzez!=nullptr)
	{
		Temp->values.push_back(Quizzez->marks);
		Temp->weights.push_back(Quizzez->Q.length());
		Quizzez=Quizzez->next;
	}
		string q,a;
		int marks;
		Quizzez=Temp->front;
		int maxScore = knapsack(Temp->time*60, Temp->weights, Temp->values,Temp->questions, selectedQuestionss);  //Calculating Maximum Possible Answer
		greedyQuizGuard(Temp->weights,Temp->values,Temp->time*60 ,selectedQuestions);
		for (int i = 0; i < Temp->questions; ++i) 
		{
	        // If the question was not selected, add it to the selectedQuestions vector
	        if (find(selectedQuestions.begin(), selectedQuestions.end(), i) == selectedQuestions.end()) 
			{
	            selectedQuestions.push_back(i);  // Add the unselected question index at the end
	        }
	    }
	    	Questions *T=nullptr;
	for(int k=0 ; k<Temp->questions ; k++)
    {
    		T=Temp->front;;
		for(int j=0 ; j < selectedQuestions[k]  ; j++ )
			T=T->next;
		T->key=k+1;
	}
    cout << endl;
	for (int i = 0; i < 5 - 1; i++) {
    T = Temp->front;
    int marks;
    while (T && T->next) {
        // Compare adjacent nodes
        if (T->key > T->next->key) {
            // Swap the keys (values) of adjacent nodes
            int temp = T->key;
            T->key = T->next->key;
            T->next->key = temp;
            
            string Q= T->Q;
            T->Q = T->next->Q;
            T->next->Q = Q;
            
            
            string A= T->A;
            T->A = T->next->A;
            T->next->A = A;
            
            
            marks= T->marks;
            T->marks = T->next->marks;
            T->next->marks = marks;
            
            
        }
        
        // Move pointers to the next nodes
        T = T->next;
    }
    
}
marks=0;
	int X=1;
	T=Temp->front;
	Questions *Through=nullptr;
	int Marks = 0;
	qq:;
    
    if (T==nullptr) {
    	T=Temp->front;
        X=0;
    }
if(X==1)
{
	Questions *newnode = new Questions;
	newnode->Q=T->Q;
	newnode->A=T->A;
	newnode->marks=T->marks;

    Marks += newnode->marks;


    // Initialize new node's pointers
    newnode->next = nullptr;  // New node's next pointer should be nullptr initially
    newnode->prev = nullptr;  // New node's prev pointer should be nullptr initially

    // If the queue is empty, make the new node both front and rear
    if (Through == nullptr) {
        Through = newnode;  // Set the front to the new node
    } else {
        // Traverse to the end of the list and link the new node
        Questions* temp = Through;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newnode;  // Set last node's next to new node
        newnode->prev = temp;  // Set new node's prev to the last node
    }
	T=T->next;
  
    goto qq;  // Recursively call the enqueue function for the next question		

}

	
	system("cls");
	cout<<"\n\t\tInstructions : ";
	cout<<"\n\t\t\tQuiz made by "<<User;
	cout<<"\n\t\t1.If you spend more time than alloted time , your answers won't be counted ";
	cout<<"\n\t\t2.Enter prev to move to previous question";
	cout<<"\n\t\t3.Enter next to move to next question";
	cout<<"\n\t\t4.Enter End to end test";
	cout<<"\n\t\t5.You have "<<Temp->time<<" minutes to complete the Quiz\n\n";
	system("pause");
	int marks1=0,count=1;
	stack *top=nullptr;
	auto start = high_resolution_clock::now();
	auto current_time = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(current_time - start);
	// Simulating the user taking the test
	system("cls");
    cout << "Test started! Please answer the questions...\n";
    system("pause");
	while(Through!=nullptr)
	{
	undo:system("cls");
	if (duration.count() < Temp->time*60) {
        cout << "Less than "<<Temp->time*60-duration.count()<<"seconds remain";
    }
	current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
    		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded!";
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
        break;  // End the quiz if time exceeds 10 seconds
    }
	cout<<"\n\t\tQuiz : "<<name;	
	push(top,Through->Q);
	
	cout<<"\n\t\tQuestion "<<count<<" : ";
	string ans=peek(top);
	if(ans=="prev")
	{
			current_time = high_resolution_clock::now();
    duration = duration_cast<seconds>(current_time - start);
    
    if (duration.count() > Temp->time*60) {
    	HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
			break;
    }
		if(count==1)
		{
			pop(top);
			goto undo;
		}
		pop(top);
		
		Through=Through->prev;
		
		marks=marks-Through->markgain;
		count--;

		
	}
	else if(ans=="next")
	{
			
			current_time = high_resolution_clock::now();
    duration = duration_cast<seconds>(current_time - start);
    
    if (duration.count() > Temp->time*60) {
  
        HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
			break;
    
    }
		
		if(Temp->questions==count)
		{
			goto undo;
		}
		Through=Through->next;
		
		count++;
		
		
	}
	else if(ans==Through->A)
	{
			
			current_time = high_resolution_clock::now();
    duration = duration_cast<seconds>(current_time - start);
    
    if (duration.count() > Temp->time*60) {
  
        HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";
 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
    break;
    }
		Through->markgain=Through->marks;
		marks=marks+Through->marks;
		Through=Through->next;
		count++;
	}
	else if(ans=="End")
	{
	
		break;
	}
	else
	{
			
			current_time = high_resolution_clock::now();
    duration = duration_cast<seconds>(current_time - start);
    
    if (duration.count() > Temp->time*60) {
  
       HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
			break;
    }
    
		Through=Through->next;
		count++;
	}
	current_time = high_resolution_clock::now();
    duration = duration_cast<seconds>(current_time - start);
    
    if (duration.count() > Temp->time*60) {
       HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";
      
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
			break;
    }
    
}

HANDLE console_color; 
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 10);
    
cout<<"\n\t\tQuiz ended .";
float time=(float)duration.count()/60;
cout << "Time taken for the test: " << time << " minutes\n";
cout<<"\n\t\tScore : "<<marks<<"/"<<Marks;
system("pause");	
Resultins(Temp->Result , current->Username, time , marks , maxScore);

current->max=current->max+maxScore;
current->score=current->score+marks;
current->Total=current->Total+Marks;
current->timeava=current->timeava+Temp->time*60;
current->timetaken=current->timetaken+time;
current->num=current->num+1;
if((float)(marks*100)/Marks>=current->per)
	current->per=(float)(marks*100)/Marks;
current->enable=1;
	
	

	
	
	
}

	else
	{
		while(Quizzez!=nullptr)
	{
		Temp->values.push_back(Quizzez->marks);
		Temp->weights.push_back(Quizzez->Q.length());
		Quizzez=Quizzez->next;
	}
		string q,a;
		int marks;
		Quizzez=Temp->front;
		int maxScore = knapsack(Temp->time*60, Temp->weights, Temp->values,Temp->questions, selectedQuestions);  //Calculating Maximum Possible Answer
		for (int i = 0; i < Temp->questions; ++i) 
		{
	        // If the question was not selected, add it to the selectedQuestions vector
	        if (find(selectedQuestions.begin(), selectedQuestions.end(), i) == selectedQuestions.end()) 
			{
	            selectedQuestions.push_back(i);  // Add the unselected question index at the end
	        }
	    }
	Questions *T=nullptr;
	for(int k=0 ; k<Temp->questions ; k++)
    {
    	T=Temp->front;
    	cout<<k;
		for(int j=0 ; j < selectedQuestions[k]  ; j++ )
			T=T->next;
		T->key=k+1;
	}
    cout << endl;
	for (int i = 0; i < 5 - 1; i++) {
    T = Temp->front;
    while (T && T->next) {
        // Compare adjacent nodes
        if (T->key > T->next->key) {
            // Swap the keys (values) of adjacent nodes
            int temp = T->key;
            T->key = T->next->key;
            T->next->key = temp;
            
            string Q= T->Q;
            T->Q = T->next->Q;
            T->next->Q = Q;
            
            
            string A= T->A;
            T->A = T->next->A;
            T->next->A = A;
            
            
            marks= T->marks;
            T->marks = T->next->marks;
            T->next->marks = marks;
            
            
        }
        
        // Move pointers to the next nodes
        T = T->next;
    }
    
}	int MARKS=0;
int markss=0;
	int x=1;
	T=Temp->front;
	Questions *Throughh=nullptr;
	int Markss = 0;
	qqq:;
    
    if (T==nullptr) {
    	T=Temp->front;
        x=0;
    }
if(x==1)
{
	Questions *newnode = new Questions;
	newnode->Q=T->Q;
	newnode->A=T->A;
	newnode->marks=T->marks;

    MARKS += newnode->marks;


    // Initialize new node's pointers
    newnode->next = nullptr;  // New node's next pointer should be nullptr initially
    newnode->prev = nullptr;  // New node's prev pointer should be nullptr initially

    // If the queue is empty, make the new node both front and rear
    if (Throughh == nullptr) {
        Throughh = newnode;  // Set the front to the new node
    } else {
        // Traverse to the end of the list and link the new node
        Questions* temp = Throughh;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newnode;  // Set last node's next to new node
        newnode->prev = temp;  // Set new node's prev to the last node
    }
	T=T->next;
  
    goto qqq;  // Recursively call the enqueue function for the next question		

}


	system("cls");
	cout<<"\n\t\tInstructions : ";
	cout<<"\n\t\t\tQuiz made by "<<User;
	cout<<"\n\t\t1.If you spend more time than alloted time , your answers won't be counted ";
	cout<<"\n\t\t2.Enter prev to move to previous question";
	cout<<"\n\t\t3.Enter next to move to next question";
	cout<<"\n\t\t4.Enter End to end test";
	cout<<"\n\t\t5.You have "<<Temp->time<<" minutes to complete the Quiz\n\n";
	system("pause");
	int countt=1;
	stack *topp=nullptr;
		auto start = high_resolution_clock::now();
	auto current_time = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(current_time - start);
	// Simulating the user taking the test
	system("cls");
    cout << "Test started! Please answer the questions...\n";
    system("pause");
	while(Throughh!=nullptr)
	{
		
	undooo:system("cls");
	if (duration.count() < Temp->time*60) {
        cout << "Less than "<<Temp->time*60-duration.count()<<"seconds remain";
    }
	current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
        cout << "Time limit exceeded!";
        break;  // End the quiz if time exceeds 10 seconds
    }
	cout<<"\n\t\tQuiz : "<<name;	
	push(topp,Throughh->Q);
	cout<<"\n\t\tQuestion "<<countt<<" : ";
	string anss=peek(topp);
	if(anss=="prev")
	{
		current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
       HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";
  
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
    
        break;  // End the quiz if time exceeds 10 seconds
    }
		if(countt==1)
		{
			pop(topp);
			goto undooo;
		}
		pop(topp);
		
		Throughh=Throughh->prev;
		
		markss=marks-Throughh->markgain;
		countt--;
		
	}
	else if(anss=="next")
	{
		current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
      HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
    
        break;  // End the quiz if time exceeds 10 seconds
    }
		
		if(Temp->questions==countt)
		{
		
			goto undooo;
		}
		Throughh=Throughh->next;
		
		countt++;
	}
	else if(anss==Throughh->A)
	{
		current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
   HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
    
        break;  // End the quiz if time exceeds 10 seconds
    }
		Throughh->markgain=Throughh->marks;
		markss=markss+Throughh->marks;
		Throughh=Throughh->next;
		countt++;
	}
	else if(anss=="End")
	{
		current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
     HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";
 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
    
        break;  // End the quiz if time exceeds 10 seconds
    }
		break;
	}
	else
	{
		current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
       HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
    
        break;  // End the quiz if time exceeds 10 seconds
    }
		Throughh=Throughh->next;
		countt++;
	}
	current_time = high_resolution_clock::now();
	duration = duration_cast<seconds>(current_time - start);

    if (duration.count() > Temp->time*60) {
     HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
        cout << "Time limit exceeded! ";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
    
        break;  // End the quiz if time exceeds 10 seconds
    }
	
}
HANDLE console_color; 
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 10);
cout<<"\n\t\tQuiz ended .";
float time=(float)duration.count()/60;
cout << "Time taken for the test: " << time << " minutes\n";
cout<<"\n\t\tScore : "<<markss<<"/"<<MARKS;
system("pause");	
Resultins(Temp->Result , current->Username, time , markss , maxScore);

current->max=current->max+maxScore;
current->score=current->score+markss;
current->Total=current->Total+MARKS;
current->timeava=current->timeava+Temp->time*60;
current->timetaken=current->timetaken+time;
current->num=current->num+1;
if((float)(markss*100)/MARKS>=current->per)
	current->per=(float)(markss*100)/MARKS;
current->enable=1;
	
	

}
	
}
void viewstats()
{
	cout<<"\n\t\tStats of "<<current->Username<<endl<<endl;
	cout<<"\n\n\t\tQuizzez Answered : "<<current->num;
	cout<<"\n\t\tHighest Percentage : "<<current->per;
	cout<<"\n\t\tAverage percentage : "<<(float)(current->score*100)/current->Total;
	cout<<"\n\t\tTakt Time : "<<(float)(current->timeava/current->timetaken);
	cout<<"\n\t\tStatus : ";
	if(current->enable==1)
	{
	if(((current->score)*100)/current->Total < 33)
		cout<<"Very Bad";
	else if(((current->score)*100)/current->Total < 50)
		cout<<"Ok";
	else if((current->score*100)/current->Total < 80 )
		cout<<"Good";
	else
		cout<<"Excellent";
	}
	else
		cout<<"Nil";
	cout<<"\n\t\tEfficiency : "<<(float)current->score/current->max<<endl<<endl;

}
void deleteQuizList(Quiz* &quizList) 
{
    Quiz* temp;
    while (quizList != nullptr) 
	{
        temp = quizList;
        quizList = quizList->next;
        delete temp;  // Delete the current quiz
    }
    cout << "All quizzes deleted." << endl;
}

void dequeue(Questions *&front)                         //function for removing nodes from queue
{

		Questions *temp=front;
		front=temp->next;
		delete temp;

	
}
void deleteQuiz()
{
	string name;
	if (current->quizList == nullptr) 
	{
		HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
 
    
        cout << "No quizzes to delete\n";

            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
        return;
    }
    cout<<"\n\t\tEnter Quiz name you want to delete : ";
	getline(cin,name);
    Quiz* temp = current->quizList;
    Quiz* prev = nullptr;
    if( current->quizList->Name ==name)
    {
    	cout<<"\n\t\tQuiz with name "<<temp->Name<<" deleted !";
    	current->quizList=current->quizList->next;
    	delete temp;
	}
    for(int i=1 ;temp != nullptr ; i++ , temp=temp->next) 
	{
		if(name==temp->Name)
		{
			cout<<"\n\t\tQuiz with name "<<temp->Name<<" deleted !";
			prev->next=temp->next;
			delete temp;
			break;
		}
		prev=temp;

    }
    AllQuiz *tempp=Front;
    AllQuiz* prevv = nullptr;
     if( Front->Name ==name)
    {
    	Front=Front->next;
    	delete tempp;
	}
    for(int i=1 ;tempp != nullptr ; i++ , tempp=tempp->next) 
	{
		if(name==tempp->Name)
		{
			prevv->next=tempp->next;
			delete tempp;
			break;
		}
		prevv=tempp;

    }
}





// Right rotate function
unsigned int rightRotate(unsigned int x, unsigned int n) 
{
    return (x >> n) | (x << (32 - n));
}

// Custom character set for final hash output
const string CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=<>?;:,.[]{}|`/\"' ";
                                                                                                
// Function to convert integer to a custom base (using CHARSET)
char intToCustomChar(unsigned int value) 
{
    return CHARSET[value % CHARSET.length()];
}

// Pad message with optional salt
vector<unsigned char> padMessage(const string &input) {
    // Start with the original input
    vector<unsigned char> padded(input.begin(), input.end());
    
    // Append a 0x80 byte (the "1" bit in padding)
    padded.push_back(0x80);

    // Pad with zeros until the message length is 448 mod 512
    while ((padded.size() * 8) % 512 != 448) 
        padded.push_back(0x00);

    // Append the original message length as a 64-bit big-endian integer
    unsigned long long bitLength = input.size() * 8;
    for (int i = 7; i >= 0; --i)
        padded.push_back((bitLength >> (i * 8)) & 0xFF);

    return padded;
}

// The main SHA-256 computation
// Main custom hash function
string complex_hash(const string &input, const string &salt, const string &pepper , int num) 
{
    string modifiedInput="";
	for(int i=0 ;i<=input.length() ; i++)
	{
		modifiedInput+=input[i];                          //Adding pepper to input
		modifiedInput+=pepper;
	}

    vector<unsigned char> padded = padMessage(modifiedInput);

    // Initializing the hash values
    unsigned int h[8] = 
	{
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Process the padded message in 512-bit blocks
    for (size_t i = 0; i < padded.size(); i += 64)
	 {
        vector<unsigned int> w(64);
        for (int t = 0; t < 16; ++t) 
		{
            w[t] = (padded[i + t * 4] << 24) | (padded[i + t * 4 + 1] << 16) |
                   (padded[i + t * 4 + 2] << 8) | padded[i + t * 4 + 3];
        }

        for (int t = 16; t < 64; ++t) 
		{
            unsigned int s0 = rightRotate(w[t - 15], 7) ^ rightRotate(w[t - 15], 18) ^ (w[t - 15] >> 3);
            unsigned int s1 = rightRotate(w[t - 2], 17) ^ rightRotate(w[t - 2], 19) ^ (w[t - 2] >> 10);
            w[t] = w[t - 16] + s0 + w[t - 7] + s1;
        }

        unsigned int a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h_val = h[7];

        for (int t = 0; t < 64; ++t) 
		{
            unsigned int s1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
            unsigned int ch = (e & f) ^ ((~e) & g);
            unsigned int temp1 = h_val + s1 + ch + k[t] + w[t];
            unsigned int s0 = rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22);
            unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
            unsigned int temp2 = s0 + maj;

            h_val = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_val;
    }

    // Combine the final hash value and convert to a string
    string hash_result;
    for (int i = 0; i < 8; ++i) 
	{
        hash_result += intToCustomChar(h[i] >> 24);
        hash_result += intToCustomChar(h[i] >> 16);
        hash_result += intToCustomChar(h[i] >> 8);
        hash_result += intToCustomChar(h[i]);
    }

	num=num%hash_result.length();                          //num % 32

	modifiedInput="";
	for(int i=0 ;i<=hash_result.length() ; i++)               
	{
		if(i==num)
			modifiedInput+=salt;                       //Adding Salt at specific position
		modifiedInput+=hash_result[i];
	}

    return 	modifiedInput;                               //returning result
}

void PasswordCheck(string &password) 
{
    bool upper = false;
    bool lower = false;
    bool symbols = false;
    bool goodLength = false;
    bool hasNumber = false;
    bool s_password = false;

    while (!s_password) 
	{
		cout << "\nPassword requirements:\n";
        cout << "- At least one uppercase letter\n";
        cout << "- At least one lowercase letter\n";
        cout << "- At least one special symbol (e.g., @, #, $, etc.)\n";
        cout << "- At least one numeric digit (0-9)\n";
        cout << "- At least 8 characters long\n\n";
        missed:;
        cout << "Enter a password : ";
       	getline(cin,password);
            
        // Reset the validation flags for each attempt
        upper = lower = symbols = goodLength = hasNumber = false;

        // Check each character of the password
        for (size_t i = 0; i < password.length(); i++) 
		{
            char c = password[i];
            if (isupper(c)) upper = true;
            if (islower(c)) lower = true;
            if (ispunct(c)) symbols = true;          // Checks for punctuation/symbols
            if (isdigit(c)) hasNumber = true;        // Checks for numeric digits
        }

        // Check the length requirement
        goodLength = (password.length() >= 8);

        // If all conditions are met, mark the password as strong
        
        if (upper && lower && symbols && goodLength && hasNumber) 
		{
            s_password = true;

            cout << "Strong password accepted.\n";
        } 
		else 
		{
			system("cls");
			PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"), NULL, SND_FILENAME | SND_SYNC);
				HANDLE console_color; 
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,4);
            cout << "Weak password. Please try again.\n";
          
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,10);
            if (!upper) cout << "- Add at least one uppercase letter.\n";                                  //Conditions to be fulfilled
            if (!lower) cout << "- Add at least one lowercase letter.\n";
            if (!symbols) cout << "- Add at least one special symbol.\n";
            if (!hasNumber) cout << "- Add at least one numeric digit.\n";
            if (!goodLength) cout << "- Make the password at least 8 characters long.\n";
            goto missed;
        }
    }
}

// Function to generate a cryptographically secure random character
char generateSecureRandomCharacter() 
{

    const string allowedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?`/\"' ";
         

    // Use random_device to get a cryptographically secure random number
    
    random_device rd;
    mt19937 gen(rd());              // Mersenne Twister generator
    uniform_int_distribution<> dis(0, allowedChars.size() - 1);

    // Randomly pick a character from the allowed list
    return allowedChars[dis(gen)];
}

};
