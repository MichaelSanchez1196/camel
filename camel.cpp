// Name: Michael Sanchez
// 11/06/15
// Program that plays the camel game.

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

void printIntro(); // prints introduction to the game
void getChar(char& option); // asks for a valid character input
void drink(int& water, int& playerT); // changes the thirst for the camel
void moderateSpeed(int& distance, int& natives, int& playerT, int& camelT); // changes the distance traveled and natives too
void fullSpeed(int& distance, int& natives, int& playerT, int& camelT); // changes the distance traveled and natives too
void stopForNight(int& natives, int& camelT); // changes camels tiredness
void statusCheck(int distance, int thirst, int natives); // grabs traveled distance, thirst drinks, natives distance.
void result(int water, int camelT, int distance, int playerT, int natives, bool& boolChoice); // determines the conditions for the camel and player to see if they are still able to continue
void oasis(int& camelT, int& playerT, int& water); // rare oasis function
void bandit(int& water); // rare bandit steals water
void trapHole(bool& boolChoice); // rare dead camel trap
void scorpion(int& camelT); // rare scorpion bite
void quit(bool& boolChoice); // Quits the program


int main()
{	
	char again;

	printIntro(); // calls the function to print the introduction to the game

	do // beginning of game 
	{

	int canteens = 3, tired = 0; // initializes everything to starting values
	int camelD = 0, thirst = 0;
	int nativeD = -20;
	bool done = false;
	char choice;

	while(!done)
	{
		getChar(choice); // calls function to bring a valid character into my switch
		
		switch(choice)
		{	
			case 'a': drink(canteens,thirst); // calls drink fucntion to determine if theirs water
				result(canteens,tired,camelD,thirst,nativeD,done); // checks conditions
					if(!done)
						break;
				trapHole(done); // rare dead camel
				oasis(tired, thirst, canteens); // rare opportunity to find an oasis
				bandit(canteens); // rare bandit steals canteens
				scorpion(tired); // rare scorpion bite
				break;
			case 'b': moderateSpeed(camelD, nativeD, thirst, tired); // makes parameter changes
				result(canteens,tired,camelD,thirst,nativeD,done); // checks conditions
					if(!done)
						break;
				trapHole(done); // rare dead camel
				oasis(tired, thirst, canteens); // rare opportunity to find an oasis
				bandit(canteens); // rare bandit steals canteens
				scorpion(tired); // rare scorpion bite
				break;
			case 'c': fullSpeed(camelD, nativeD, thirst, tired); // makes parameters changes
				result(canteens,tired,camelD,thirst,nativeD,done); // checks conditions
					if(!done)
						break;				
				trapHole(done); // rare dead camel
				oasis(tired, thirst, canteens); // rare opportunity to find an oasis
				bandit(canteens); // rare bandit steals canteens
				scorpion(tired); // rare scorpion bite		
				break;
			case 'd': stopForNight(nativeD, tired); // calls the rest fucntion for the camel
				result(canteens,tired,camelD,thirst,nativeD,done); // checks conditions
				bandit(canteens); // rare bandit steals canteens
				scorpion(tired); // rare scorpion bite
				break;
			case 'e': statusCheck(camelD, canteens, nativeD); // calls the status on player
				result(canteens,tired,camelD,thirst,nativeD,done); // checks conditions
				break;
			case 'q': quit(done); // exits the program
				break;
			default:	
				break;
		}

	}
	
	cout << "Would You Like To Play Again? (y/n)\n";
	cin >> again;
	again = tolower(again);
	
	while(again != 'y' && again != 'n')
	{
		cout << "You Have Entered A Wrong Input, Try Again.\n";
		cout << "Would You Like To Play Again? (y/n)\n";
		cin >> again;
		again = tolower(again);
	}	

	if(again == 'y')
		done = false;


	}while(again == 'y');	

	return 0;
}
void getChar(char& option) // checks for a valid input characte, while loop to make sure its valid
{
	cout << "\nWhat Is Your Choice.\n";
	cout << "\nA. Drink From Your Canteen.\n";
	cout << "B. Ahead Moderate Speed.\n";
	cout << "C. Ahead Full Speed.\n";
	cout << "D. Stop and Rest.\n";
	cout << "E. Status Check.\n";
	cout << "Q. Quit.\n";

	cin >> option;
	option = tolower(option); // makes the character lower case to get rid of case sensative issues
	
	while(option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e' && option != 'q')
	{
	cout << "\nYou Have Entered A Wrong Input.\n";
	cout << "What Is Your Choice.\n";
	cout << "\nA. Drink From Your Canteen.\n";
	cout << "B. Ahead Moderate Speed.\n";
	cout << "C. Ahead Full Speed.\n";
	cout << "D. Stop and Rest.\n";
	cout << "E. Status Check.\n";
	cout << "Q. Quit.\n";

	cin >> option;
	option = tolower(option); // makes the character lower case to get rid of case sensative issues

	}

	return;
}
void drink(int& water, int& playerT) // player drinks water and deducts 1 from the canteens
{
	if(water > 0)
	{	
		water-=1;
		playerT = 0;	
	}	
	else // if their is no more water canteens, cout an error
		cout << "You Dont Have Enough Drinks" << endl;
	
	cout << "Drinks Left: " << water << endl;
	cout << "Player Thirst: " << playerT << endl;	

	return;
}
void moderateSpeed(int& distance, int& natives, int& playerT, int& camelT) // changes parameters in function
{
	int distanceNum, nativesNum;
	distanceNum = rand() % 7 + 5; // finds a random number between 5-11
	nativesNum = rand() % 5 + 8; // finds a random number between 8-12

	distance+= distanceNum; // adds the first random number above to camel distance
	natives+= nativesNum; // adds the second random number above to native distance

	playerT++; // adds 1 to player thirst
	camelT++; // adds 1 to camel tiredness

	cout << "\nMiles Traveled: " << distance << endl; // outputs the miles traveled by player	
	return;
}
void fullSpeed(int& distance, int& natives, int& playerT, int& camelT) // changes parameter in function
{
	int distanceNum, nativesNum, tiredness; 
	distanceNum = rand() % 9 + 10; // finds a random number between 10-18
	nativesNum = rand() % 6 + 9; // finds a random number between 9-14
	tiredness = rand() % 3 + 1; // finds a randome number between 1-3

	distance+= distanceNum; // adds the first random number between 10-18 to camel distance
	natives+= nativesNum;  // adds the second random number between 9-14 to natives distance

	playerT++;
	camelT += tiredness; // adds the third random number to camel tiredness

	cout << "\nMiles Traveled: " << distance << endl; // outputs the miles traveled by player
	return ;
}
void stopForNight(int& natives, int& camelT) // camel rests while natives keep on catching up
{
	int nativesNum;
	camelT = 0; // initializes camel tiredness back to zero
	cout << "The Camel is Very Happy ! Goodjob!\n"; 
	nativesNum = rand() % 7 + 8; // finds a random number between 8-14 
	
	natives+= nativesNum; // adds the previous number to native distance

	return;
}
void statusCheck(int distance, int thirst, int natives)
{
	cout << "\nMiles Traveled: " << distance << endl; // outputs the natives distance from user
	cout << "Drinks In Canteen: " << thirst << endl; // outputs left over canteens
	cout << "The Natives Are " << distance - natives << " Miles Behind You.\n"; // outputs natives distance

}
void result(int water, int camelT, int distance, int playerT, int natives, bool& boolChoice)
{
	if(distance < 200)
	{
	if(playerT > 4 && playerT < 7) // range to determine the thirst of the player
		cout << "You Are Thirsty.\n";
	if(playerT > 6) // player dies from thirst
	{
		cout << "You Died Of Thirst.\n";
		boolChoice = true;	// end the game
	}
	if(camelT > 5 && camelT < 9) // range to determine the camel tiredness
		cout << "Your Camel Is Getting Tired.\n"; 
	if(camelT > 8) // camel dies from tiredness
	{
		cout << "Your Camel Is Dead.\n";
		boolChoice = true;	
	}	
	if(natives >= distance) // player loses the game, he got caught by the natives
	{
		cout << "Game Over! The Natives Got You.\n"; 
		boolChoice = true;	// end game.
	}
	else if((distance - natives) <= 15) // warning to user that natives are near by
		cout << "The Natives Are Getting Close.\n";
	}
	if(distance >= 200) // winning announcement
	{	
		cout << "You Won! WooHoo!\n";
		boolChoice = true; // exits game
	} 

	return;
}
void quit(bool& boolChoice) // exits the game
{
	boolChoice = true;
	cout << "Thanks For Playing! Goodbye.\n\n";	
	return;
}
void printIntro() // prints the introduction of the game
{
	cout << "\nWelcome To Camel!" << endl;
	cout << "You Have Stolen A Camel To Make Your Way Accross The Great Mobi Desert.\n";
	cout << "The Natives Want Their Camel Back And Are Chasing You Down!\n";
	cout << "Survive Your Desert Trek And Run The Natives.\n";

}
void oasis(int& camelT, int& playerT, int& water) // rare oasis function
{
	int num;
	num = rand() % 25 + 1; // one in 25 chance of finding an oasis	
	
	if(num == 11)
	{
		cout << "Woow! You Have Found A Rare Oasis! Lucky You!\n";
		cout << "You Now Have 10 Canteens, Zero Thirst And Zero tiredness For Your Camel.\n";
		camelT = 0; // initializes camel tiredness to zero
		playerT = 0; // initializes payer thirst to zero
		water = 10; // initializes canteens back to zero
	}
		return;
}
void bandit(int& water)
{
	int num, waterLeft;
	waterLeft = rand() % 3 + 1; // random number of drinks taken away
	num = rand() % 20 + 1; // one in 20 chance of finding an oasis	
	
	if(num == 3)
	{
		cout << "Oh Oh ! A desert Bandit Just Stole Your Water.\n";
		cout << "You Now Have A Lower Amount Of Canteens Left.\n";	
		water = water - waterLeft; // makes the subtraction to drinks
	}

		return;
}
void trapHole(bool& boolChoice)
{
	int num;
	num = rand() % 30 + 1; // one in 30 chance of falling in a hole
	
	if(num == 22)
	{	
		cout << "Ooops, Your Camel Has Died, He Fell In A Hole And Broke His Neck.\n";
		boolChoice = true; // automatic dead for the camel

	}
		return;
}
void scorpion(int& camelT)
{
	int num, tiredness;
	tiredness = rand() % 5 +1; // random number to add to camel tiredness
	num = rand() % 20 + 1; // one in 20 chance of gettin bit by a scorpion
	
	if(num == 7)
	{	
		cout << "Your Camel Has Been Bitten by A Scorpion.\n";
		cout << "Your Camels Tiredness has increased.\n";
		camelT = camelT + tiredness; // tiredness increase for the camel

	}

}
