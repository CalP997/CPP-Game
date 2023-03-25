//Filename: StarWarsGame.cpp
//Author: Callum Pope
//Date: 15/02/2017 Version 1
//Program comments
//This game will follow Luke Skywalker throughout the film
//The player will be given obstacles that they will have to overcome in each level
//This can range from calculations to directional choices
//Incorrect choices can mean game over
//the game created to demonstrate to Middleton MUD
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string.h>
using namespace std;

//function declarations(prototypes)

//global variables
int Loading();
void Menu();
void Introduction();
void NewGame();
void Create();
void Level1();
void Level2();
void Level3();
void Cellblocks();
void Level4();
void ReadSavedGame();
void DeleteSavedData();
void Exit();
char filename[100];
ofstream file_ptr;
//Function colour manager
void color(int x)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, x);
}

//Manage coordinates
void gotoxy(short x,short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Main
int main()
{
    gotoxy(20,3);
    color(15);
    cout<<"A Text Based interpretation of the Original film:";
    
    //Creation of animation
    for(int i=0;i<=9;i++)
    {
        color(14);
        gotoxy(25,14-i);
        cout<<"*";
        Sleep(70);
    }
    for(int i=0;i<=19;i++)
    {
        color(14);
        gotoxy(25+i,5);
        cout<<"*";
        Sleep(70);
    }
    for(int i=0;i<=9;i++)
    {
        color(14);
        gotoxy(44,5+i);
        cout<<"*";
        Sleep(70);
    }
    for(int i=0;i<=19;i++)
    {
        color(14);
        gotoxy(44-i,14);
        cout<<"*";
        Sleep(70);
    }
    gotoxy(31,6);
    color(14);
    cout<<"STAR WARS";
    Sleep(80);
    gotoxy(31,8);
    cout<<"Episode IV";
    Sleep(80);
    gotoxy(30,10);
    cout<<"A NEW HOPE";
    Sleep(80);
    gotoxy(27,12);
    cout<<"By Callum Pope";
    
    
    gotoxy(20,20);
    color(15);
    cout<<"Press enter to continue";
    cin.get();
    Menu();
}
void Menu()//main menu function
{
	system("color f3");
char choice, reply;

do
	{
		system("CLS");
		system("color 0f");
		cout<<"********************STAR WARS - A NEW HOPE**************************";
		cout<<"\n\n\tWelcome to the Star Wars - A New Hope Game.";
		cout<<"\n\n\t\t\tA: Introduction";
		cout<<"\n\n\t\t\tB: Start A New Game";
		cout<<"\n\n\t\t\tC: Read Saved Data";
		cout<<"\n\n\t\t\tD: Delete Saved Data";
		cout<<"\n\n\t\t\tE: Exit";
		cout<<"\n\n\tPlease choose one of the options listed above: ";
		cin>>choice;
		cin.ignore();
		switch (choice)
			{
				case 'A':
					Introduction();
					cin.get();
					break;
				case 'B':
					NewGame();
					cin.get();
					break;
				case 'C':
					ReadSavedGame();
					cin.get();
					break;
				case 'D':
					DeleteSavedData();
					cin.get();
					break;
				case 'E':
					cout<<"\n\tEXITING";
					cin.get();
					exit(0);
					break;
				default:
					cout<<"\n\tInput not valid";
					break;
			}
			cout<<"\n\tReturn to Main Menu? (Y/N)";
			cin>>reply;
	}
	while(reply != 'N');
			cin.get();
}

void Introduction()//Introduction to the game
{
	system("CLS");
	system("color 0E");
	cout<<"\n\t\t\t\t\t\tIntroduction\n";
	cout<<"\n\t\t\t\t\t\tA NEW HOPE";
	cout<<"\n\t\t\t\t\tIt is a period of civil war.";
	cout<<"\n\tRebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire.";
	cout<<"\n\tDuring the battle, Rebel spies managed to steal secret plans to the Empires ultimate weapon, the DEATH STAR,";
	cout<<"\n\t\tan armored space station with enough power to destroy an entire planet.";
	cout<<"\n\tPursued by the Empires sinister agents, Princess Leia races home aboard her starship,";
	cout<<"\n\t\t\tcustodian of the stolen plans that can save her people";
	cout<<"\n\t\t\t\tand restore freedom to the galaxy....";
	cout<<"\n\n\n\tIn this game you will be following the journey of Luke Skywalker during the events of the film";
	cout<<"\n\tThe game will have 4 levels. 2 on Tatooine and 2 based around the Death Star";
	cout<<"\n\tThis is a heavily choice based game but not all choices are correct";
	cout<<"\n\tAny incorrect choice could be game over so tread carefully!";
	cin.get();
}
void NewGame()//menu for starting a new game
{
	char choice;
	system("CLS");
		system("color 0f");
		cout<<"********************STAR WARS - A NEW HOPE**************************";
		cout<<"\n\n\tNew Game.";
		cout<<"\n\n\t\t\t0: Create Profile";
		cout<<"\n\n\t\t\tA: Level 1";
		cout<<"\n\n\t\t\tB: Level 2";
		cout<<"\n\n\t\t\tC: Level 3";
		cout<<"\n\n\t\t\tD: Level 4";
		cout<<"\n\n\t\t\tE: Return to main menu";
		cout<<"\n\n\tPlease choose one of the options listed above: ";
		cin>>choice;
		cin.ignore();
		switch (choice)
			{
				case '0':
				Create();
					cin.get();
					break;
				case 'A':
					Level1();
					cin.get();
					break;
				case 'B':
					Level2();
					cin.get();
					break;
				case 'C':
					Level3();
					cin.get();
					break;
				case 'D':
					Level4();
					cin.get();
					break;
				case 'E':
					Menu();
					cin.get();
					break;
				default:
					cout<<"\n\tInput not valid";
					cin.get();
					break;
			}
	cin.get();
}
void ReadSavedGame()//read the saved player data and found items
{
	system("CLS");
	system("color 0B");
	ifstream file_ptr;			
	char filename [100];
	
	cout << "\nEnter the filename to be read:";
	gets (filename);
	
	file_ptr.open(filename,ios::in);
									  
	
	
	char in_char;				 
	
	if(!file_ptr)				 
	   cout<<"Error...File does not exist";
	else
	{
		cout<<"Displaying details and items for "<<filename<<endl;
		while(!file_ptr.eof())   
		{
			file_ptr.get(in_char);	
			cout<<in_char;				
			
		}
		cin.get();
	}
	file_ptr.close();			
}
void DeleteSavedData()//delete all data from a user file
{
	ofstream file_ptr;
	system("CLS");
	system("color 0C");
	cout<<"\n\tEnter name of file you want to delete ";
	cin>>filename;
	file_ptr.open(filename, ios::trunc);
	
	if(!file_ptr){
		cout<<"\n\tError opening the file.";
	}else{
		cout<<"\n\tErasing file.....";
		cout<<"\n\n";
	}
	file_ptr.close();
	cin.get();
}
void Create()//create a new game file
{
	
	system("CLS");
	cout<<"\n\tWelcome to the Star Wars A New Hope text based game";
	cout<<"\n\tTo start the game a file must be created. Please enter a filename to be used.";
	gets (filename);
	
	file_ptr.open(filename, ios::out);
	
	//attributes
	char info[30];
	char choice;
	int count;
	
	if(!file_ptr)				
	  cout<<"\n\tError opening file info.dat";
	else
	{
		for(count=1;count<=3;count++)
		{
			cout<<"\n\t Please enter your firstname, surname and gender. Press enter after each input.: ";
			gets(info);
			file_ptr<<count<<" "<<info<<"\n";
		}
	}
	file_ptr.close();			
	cout<<"\n\tContinue to game [Y/N]?";
	cin>>choice;
	if (choice != 'Y'){
		Menu();
	}else{
		Level1();
	}
}
void Level1()//all coding revolving around level 1 of the game
{
	//attributes
	char info[30];
	char choice;
	int choice1;
	int choice2;
	int count;
	int total;
	
	system("CLS");
	system("color 4a");
	cout<<"\n\tLevel 1 - Lars Homestead";
	cout<<"\n\tObjective - Meet up with Uncle Owen and purchase droids\n";
	cout<<"\n\tOwen: Luke, get out here!";
	cout<<"\n\tNow, you are faced with your first choice of this game. Choices do have consequences, some bringing rewards.";
	cout<<"\n\tMeet up with Uncle Owen now or wait a while longer? (W or N)\n\t";
	cin>>choice;
	cin.ignore();
	switch (choice)
		{
			case 'W':
			file_ptr.open(filename,ios::app);
				if(!file_ptr)
  					cout<<"\n\tError opening file info.dat";
				else
				{
					cout<<"\n\tYou have obtained Han Solos estimated price range for travel.";
					cout<<"\n\tThe estimated price is between 15,000 and 17,000 credits.";
					cout<<"\n\tTo store this item to the file, please enter Credits below.\n\t";
					gets(info);
					file_ptr<<" "<<info<<"\n";
					
				}
			file_ptr.close();	
			cout<<"\n\tGoing to Uncle Owen.....";
			system("pause");
			break;
			case 'N':
			cout<<"\n\tGoing to Uncle Owen.....";
			system("pause");
			break;
			default:
			cout<<"\n\tInput not valid";
			break;
			}
system("CLS");
cout<<"\n\tOn reaching uncle owen, you are greeted and told to choose 2 droids from a line";
cout<<"\n\tThere are 8 droids in total. Only 2 are correct choices.";
cout<<"\n\tThere are 3 attempts until failure. Upon failure, the level will restart.";
cout<<"\n\tDROID LIST";
cout<<"\n\t1.R2-D2\n\t2.R5-D4\n\t3.C230\n\t4.R7-H5\n\t5.C3PO\n\t6.T17B\n\t7.AP5\n\t8.CH1P";
cout<<"\n\tPlease enter the first droid you will choose:\n\t";
cin>>choice1;
cout<<"\n\tPlease enter your second droid choice:\n\t";
cin>>choice2;
	if (choice1 != 1 && choice2 != 5){//1st choice = R2 D2, 2nd choice = C3PO
		cout<<"\n\tOne of the droids has malfuncioned. The Jawas refuse to return them and leave you with them.";
		cout<<"\n\t\t\tBAD END";
		cout<<"\n\tRETURNING TO MENU........";
		system("pause");
		Menu();
		}else{
		cout<<"\n\tDroids are working correctly";
		cout<<"\n\tDroids are discounted by 10% & the regular price offered is 8000 each.";
		cout<<"\n\tWorkout the total for both droids.\n\t";
		cin>>total;
		if (total != (8000*0.9) + (8000*0.9)){//correct total = 14400
			cout<<"\n\tIncorrect total. The Jawas reject your offer and leave you without the droids.";
			cout<<"\n\tFailed to obtain the droids";
			cout<<"\n\tRETURNING TO MENU";
		}else{
			cout<<"\n\tDroids bought successfuly";
		}
		cout<<"\n\tLevel complete.\n\tAdvancing to next level";
		cout<<"\n\t.......................................\n\t";
		system("pause");
		Level2();//Continue on towards level 2 
	}
	}
void Level2()//coding for level 2 of the game
{
	int choice;
	int choice2;
	int credits;
	char info[10];
	char info2[39];
	system("CLS");
	system("color 72");
	cout<<"\n\tLevel 2 - Mos Eisley";
	cout<<"\n\tObjective: Convince Han Solo to pilot you to Alderaan\n";
	cout<<"\n\tHaving met up with Ben Kenobi, you travel to Mos Eisley to find a pilot";
	cout<<"\n\tYou now have to convince Han Solo to pilot you to the Alderaan System";
	cout<<"\n\tSolo:Listen kid, if you wanna fly you gotta pay.";
	cout<<"\n\tSolo: 15,000. Minimum. Dont try and reason with me.";
	cout<<"\n\tEnter the amount of credits that you will give solo:\n\t"; 
	cin>>credits;
	if (credits>=15000){//Credits entered by player can be no less than 15000
		cout<<"\n\tOK kid, its a deal.";
		cout<<"\n\tSolo: Go to docking bay 94. Thats where I'll be.";
		cout<<"\n\tKenobi: 94.";
	}else{
		cout<<"\n\tSolo: You deaf kid, 15000 minimum. No deal";
		cout<<"\n\tFailed to convince Solo to pilot you to Alderaan.";
		cout<<"\n\tRETURNING TO MAIN MENU....................\n\t";
		system("pause");
		Menu();
	}
	cout<<"\n\tSolo: Meet me there. Without Imperial involvement\n\t";
	system("pause");
	system("CLS");
	cout<<"\n\tUpon leaving the cantina, you are greeted with a choice of paths.\n";
	cout<<"\n\tDo you:\n\t\t1.Go left\n\t\t2.Go forward\n\t\t3.Go right\n\t";
	cin>>choice;
	switch (choice){
		case 1://go left
			cout<<"You have found a set of Imperial codes";
			file_ptr.open(filename,ios::app);
				if(!file_ptr)
  					cout<<"\n\tError opening file info.dat";
				else
				{
					cout<<"\n\tTo store this item to the file, please enter Codes below.\n\t";
					cin>>info;
					file_ptr<<" "<<info<<"\n";
					
				}
			file_ptr.close();
			cout<<"\n\tThe path leading left only lead to a closed off area including the codes.";
			cout<<"\n\tContinuing down the first path forward.";
			cout<<"\n\tInformation obtained from merchant on the street.";
			cout<<"\n\tYou hear the merchant exclaim that Princess Leia has been captured by the Empire.";
			cout<<"She is being held on their Death Star.";
			cout<<"Upon reaching the end of the path you find the bay and Millenium Falcon.";
			cout<<"You board the ship and leave the planet";
			cout<<"\n\tLevel complete.\n\tAdvancing to next level";
			cout<<"\n\t.......................................\n\t";
			system("pause");
			Level3();//Continue on towards level 3
			break;
		case 2://go straight
			cout<<"\n\tContinuing down the first path forward.";
			cout<<"\n\tInformation obtained from merchant on the street.";
			cout<<"\n\tYou hear the merchant exclaim that Princess Leia has been captured by the Empire.";
			cout<<"She is being held on their Death Star.";
			cout<<"\n\tUpon reaching the end of the path you find the bay and Millenium Falcon.";
			cout<<"\n\tYou board the ship and leave the planet";
			cout<<"\n\tLevel complete.\n\tAdvancing to next level";
			cout<<"\n\t.......................................\n\t";
			system("pause");
			Level3();//Continue on towards level 3
			break;
		case 3://go right
			cout<<"\n\tContinuing right.......";
			cout<<"\n\tYou are faced with another path choice You can either:";
			cout<<"\n\t1.Go left.";
			cout<<"\n\t2.Go right.";
			cout<<"\n\tEnter your choice below.\n\t";
			cin>>choice2;
			if(choice2 = 1){
				cout<<"Continuing left.....";
				cout<<"Upon reaching the end of the path you find the bay and Millenium Falcon.";
				cout<<"You board the ship and leave the planet";
				cout<<"\n\tLevel complete.\n\tAdvancing to next level";
				cout<<"\n\t.......................................\n\t";
				system("pause");
				Level3();//Continue on towards level 3	
			}else{
				cout<<"\n\tYou run into a group of stormtroopers who are searching for the droids that you have.";
			 	cout<<"\n\tStormtrooper Commander: 'Halt! Stop right there.'";
				cout<<"\n\tYou are arrested for harbouring the droids and taken for questioning.";
				cout<<"\n\tRETURNING TO MAIN MENU....................\n\t";
				system("pause");
				Menu();
			}
			break;
			
	}
}
void Level3()//coding for level 3 of the game
{
	char info[10];
	int choice;
	char choice2;
	system("CLS");
	system("color 84");
	cout<<"\n\tLevel 3 - Death Star";
	cout<<"\n\tObjective: Rescue the Princess\n";
	cout<<"\n\tYou have found an Imperial station known as the Death Star.";
	cout<<"\n\tHaving found out that the Alderaan System was destroyed you are pulled towards the station";
	cout<<"\n\tYou now have to find the Princess and vacate the station.";
	cout<<"\n\tYou reach the hangar control room & Kenobi leaves to turn off the tractor beam.";
	cout<<"\n\tSolo:C'mon kid let's find that Princess so we can get out of here\n\t";
	system("pause");
	system("CLS");
	cout<<"\n\tYou are faced with a choice of routes to take.";
	cout<<"\n\tDo you:\n\t\t1.Go right\n\t\t2.Go forward\n\t\t3.Go left\n\t";
	cin>>choice;
	switch (choice){
		case 1://go right
			cout<<"\n\tYou have found data on the Death Star.";
			cout<<"\n\tOnly within 10m is the gravity field of the reactor effective.";
			file_ptr.open(filename,ios::app);
				if(!file_ptr)
  					cout<<"\n\tError opening file info.dat";
				else
				{
					cout<<"\n\tTo store this item to the file, please enter Data below.\n\t";
					cin>>info;
					file_ptr<<" "<<info<<"\n";
					
				}
			file_ptr.close();
			cout<<"\n\tThe path leading left only lead to a closed off area including the data.";
			cout<<"\n\tContinuing towards cellblocks...";
			system("pause");
			Cellblocks();
			break;
		case 2://go straight
			cout<<"\n\tContinuing forward...";
			system("pause");
			Cellblocks();
			break;
		case 3://go left
			cout<<"\n\tCannot follow Kenobi. You have to find the Princess.";
			cout<<"\n\tAdvancing to cellblocks...";
			system("pause");
			Cellblocks();
			break;
		}
}
void Cellblocks(){
	int cellblock;
	cout<<"\n\tEnter cellblock you wish to go to:\n\t";
	cin>>cellblock;
	while (cellblock != 2){
	cout<<"\n\tIncorrect cellblock";
	if (cellblock > 3 || cellblock < 1){
		cout<<"\n\tCellblock does not exist. Enter an existing cellblock.";
	}
	cout<<"\n\tEnter cellblock you wish to go to:\n\t";
	cin>>cellblock;
	}
	cout<<"\n\tPrincess found!";
	cout<<"\n\tLevel completed.";
	cout<<"\n\tAdvancing to the final level........";
	Level4();
}
void Level4()//coding for level 4 of the game 
{
	int gear;
	int droid;
	int room;
	int choice;
	system("CLS");
	system("color 57");
	cout<<"\n\tLevel 4 - Death Star (Space)";
	cout<<"\n\tObjective: Destroy the Death Star\n";
	cout<<"\n\tFirst you have to collect all gear from the rebel base to advance to your fighter";
	gear = 0;//statement false
	droid = 0;//statement false
	do{
		do{
			cout<<"\n\tEnter the room that you wish to enter [1-3].\n\t";
			cin>>room;
			switch(room){
				case 1:
					cout<<"\n\tEntered room 1. Gear Found";
					gear = 1;
					break;
				case 2:
					cout<<"\n\tEntered room 2. Cannot leave yet. Not all items have been found!";
					break;
				case 3:
					cout<<"\n\tEntered room 3. Droid Found.";
					droid = 1;
					break;
				default:
					cout<<"\n\tRoom not found. Choose one of the 3 rooms.";
					break;
			}
		}while(gear != 1);//loops while condition is not true
	}while(droid != 1);
	cout<<"\n\tAll gear found.";
	cout<<"\n\tAdvancing to Death Star.......";
	system("pause");
	system("CLS");
	system("color 87");
	cout<<"\n\tDeath Star";
	cout<<"\n\tObjective 2 - Destroy the station";
	cout<<"\n\tYou are now on the final trench of the Death Star";
	cout<<"\n\tThe main reactor is in sight\n\tDo you:";
	cout<<"\n\t\t1.Shoot reactor now [25m]\n\t\t2.Shoot at 20m\n\t\t3.Shoot at 15m\n\t\t4.Shoot at 10m\n\t\t5.Shoot at 5m\n\t";
	cin>>choice;
	if(choice != 5){
		cout<<"\n\tYou missed the shot and were subsequently killed by Vader.\n\tGAME OVER\n\t";
		system("pause");
		Menu();
	}else{
		cout<<"\n\tThe shot was successful and the Imperial station was destroyed";
		cout<<"\n\tGreat shot kid that was one in a million!";
		cout<<"\n\n\t\t\tGAME COMPLETED";
	}
}

