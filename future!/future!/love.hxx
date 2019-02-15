#pragma once


#include <fstream>
#include <iostream>
#include <string>
#include"momoLibrary.hxx"
#include"new.hxx"
const std::string file_name{ "log.log" };
std::string type = "chicken";
int petLevel = 0;
std::string words[8] =
{
	"alpha","beta","jama","jar","jom","get","warnd","look"
};
using engine = m3Library::engine;
using I = m3Library::setInt;

const std::string wordlist2[26] =
{
	"apiary","beetle","cereal","danger","ensign","florid",
	"garage","healthy","insult","jackal","keeper","loaner",
	"manage","nonce","onset","plaid","quilt","remote",
	"stolid","train","useful","valid","whence","xenon",
	"yearn","zippy"
};

int a3;



	std::fstream thu(file_name.c_str(), std::ios::in | std::ios::out);

void check()
{
	int a = thu.get();
	if (a == EOF)
	{
		thu<< petLevel << type << std::endl;
	}
	thu.close();
}
std::ifstream a2(file_name.c_str(), std::ios::in);
void te()
{
	a2 >> petLevel;
	a2 >> type;
}
void playA()
{
	m3Library::engine a(std::time(nullptr));
	m3Library::setInt en(0, 7);
	std::string b = words[en(a)];
	int choose = 4;
	for (auto i : words)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	while (choose)
	{
		std::cout << "guess the word!\n";
		std::string buf;
		std::cin.get();
		std::getline(std::cin, buf);
		if (buf == b)
		{
			std::cout << "you are right! level " << ++petLevel << " completed.";
			break;
		}
		else
		{
			std::cout << "error.you have " <<-- choose << " to guess.";
		}
	}
	
}
void play()
{

	m3Library::engine a(std:: time(nullptr));
	m3Library::setInt e(100, 200);
	int guess = 10;
	//guess
	int what = e(a);
	int whatI;
	while (guess)
	{
		std::cout << "guess my number(at 100-200)";
		std::cin >> whatI;
		if ((whatI > what && whatI - what <= 10) || (whatI < what && what - whatI <= 10)) //Ïà²î²»³¬¹ý10.
		{
			petLevel++;
			std::cout << "you are a bit right\n";
			std::cout << "the number is " << what << std::endl
				<< "level " << petLevel << " completed.\n";
			break;
		}
		else if (whatI == what)
		{
			petLevel += 10;
			std::cout << "you are very right,your number = " << what << " \n"
				<< "level " << petLevel << " comleted." << std::endl;
			break;
		}
		else
		{
			guess--;
			std::cout << "you only have " << guess << " times to guess." << std::endl;
			continue;
		}
	}
}
void pets()
{
	std::cout << "your pet is " << type << ", it is " << petLevel << " level." << std::endl;
}
void remember()
{
	std:: ofstream a(file_name.c_str(), std::ios::out | std::ios::trunc);
	a << petLevel;
	a << type;
	a.close();
}
void buy()
{
	std::system("cls");
	std::cout << "---------------buy the pet.--------------\n";
	std::cout << "1.dog:18 level,2.cat:20 level,3.chicken:default.4.big pet:300 level\n";
	int choose = 0;
	std::cin >> choose;
	std::cin.get();
	switch (choose) {
	case 1:
		if (petLevel <= 18)
		{
			std::cout << "cant buy.\n";
			return;
		}
		else
		{
			type = "dog";
			petLevel -= 18;
		}
	case 2:
		if (petLevel <= 20)
		{
			std::cout << "cant buy.\n";
			return;
		}
		else
		{
			type = "cat";
			petLevel -= 20;
		}
		break;
	case 3:
		std::cout << "you have a chicken now.";
		break;
	case 4:
		if (petLevel <= 300)
		{
			std::cout << "cant buy.\n";
			return;
		}
		else
		{
			type = "big_pet";
			petLevel -= 300;
		}

		std::cout << "<you are very good.go back.delete log.log file,restart.>" << std::endl;

		std::cin.get();
		std::cin.get();
		std::exit(0);

	}


}


void newGame()
{
	engine a = engine(std::time(nullptr));
	I e = I(0, 25);
	std::string target = wordlist2[e(a)];
	int len = target.size();
	std::string att(len, '-');
	std::string badchars;
	int guess = 6;
	std::cout << "guess my secret word.it has " << len << " letters" << ",and you guess\none letters at a time.you get " << guess << " wrong guess.\n";
	std::cout << "your word:" << att << std::endl;
	while (guess > 0 && att != target)
	{
		char letter;
		std::cout << "guess one letter... ";
		std::cin >> letter;
		if (badchars.find(letter) != std::string::npos || att.find(letter) != std::string::npos)
		{
			std::cout << "youve guess this.continue.\n"
				;
			continue;
			/////////
		}
		int loc = target.find(letter);
		if (loc == std::string::npos)
		{
			std::cout << "bad guess.\n";
			--guess;
			badchars += letter;
		}
		else {
			std::cout << "good guess!!!!!!!!!!!!!!!!!" << std::endl;
			att[loc] = letter;
			loc = target.find(letter, loc + 1);
			while (loc != std::string::npos)
			{
				att[loc] = letter;
				loc = target.find(letter, loc + 1);
			}
		}
		std::cout << "your word: " << att << std::endl;
		if (att != target)
		{
			if (badchars.size())
				std::cout << "bad choices:" << badchars << std::endl;
			std::cout << guess << " bad guess left\n";



		}
		
	}
if (guess > 0)
			std::cout << "thats right!!\n" << "level " << ++petLevel << " completed." << std::endl;
		else
			std::cout << "sorry,the word is " <<'\''<< target <<""<<'\''<< ".\n";

} 
void switch_choose()
{
	switch (a3)
	{
	case 1:
		play();
		break;
	case 2:
		pets();
		break;
	case 3:
		remember();
		break;
	case 4:
		buy();
		break;
	case 5:
		playA();
		break;
	case 6:
		newGame();
		break;
	case 0:
		remember();
		exit(0);

	default:
		std::cout << "bad choose,please restart.(press enter key to exit.)" << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
}
void interfaces()
{
	std::cout << "please input number to do something.0 to exit.";
	a3=_getch();
	
	a3-= '0';
	std::cout << '\n';
	switch_choose();
	return;
}
void checkISgood()
{
	if (petLevel <= 100)
		;
	else if (petLevel == 100)
	{
		std::cout << "wow!your pet is level 100!" << std::endl;
	}
	else if (petLevel == 200)
	{
		std::cout << "wow!your pet is level 200!" << std::endl;
	}
	else
	{
		std::cout << "wow!you are good!" << std::endl;
	}
}
void menu()
{
	while (true)
	{

		checkISgood();
		std::cout << ""   << std::endl
			<< "welcome to the game.it is a c++ game by momo." << std::endl
			<< "1.play the game..........................................................1      "<< std::endl
			<< "2.look about your pets.................................................2  "                        << std::endl
			<< "3.save your level.............................................................3  "                              << std::endl
			<< "4.buy good pets..............................................................4  "                             << std::endl
			<< "5.play another game................................................. 5     "                          << std::endl
			<< "6.play new game..........................................................6"               << std::endl;
		interfaces();
	}

}

