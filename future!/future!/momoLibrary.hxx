#pragma once




#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<utility>
#include<ctime>
#include<locale>
#include<chrono>
#include<thread>
#include<conio.h>

#include<cstdio>
#include<random>
#include<array>
#include<valarray>
#include<memory>
#include<new>

#include<windows.h>

namespace GlobalVariable
{
	HANDLE handle;
}
namespace m3Library
{
	using _random_engine_ = std::default_random_engine;
	using engine = _random_engine_;
	using setInt = std::uniform_int_distribution<int>
		;
	using _rti_ =
		setInt;
	using setDouble = std::uniform_real_distribution<double>;
	using _rtd_ = setDouble;
	inline void get() { _getch(); }
	inline void setTitle(const std::string &a)
	{
		SetConsoleTitleA(a.c_str());
	}
	inline void setTitle(std::string& a)
	{
		SetConsoleTitleA(a.c_str());
	}
	inline void pauseConsoleText()
	{
		system("pause");
		
	}
	void initLibrary()
	{
		GlobalVariable::handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	inline void setColor(const int &colorIndex)
	{
		SetConsoleTextAttribute(GlobalVariable::handle, colorIndex);
	}
	inline void clearAllText()
	{
		std::system("cls");
	}
	void setConsoleSize(const int &width, const int &height)
	{
		char command[40];
		sprintf_s(command, "mode con cols=%d lines=%d", width, height);
		std::system(command);
	}


}

