#pragma once
#include <iostream>
#include <exception>

using namespace std;

class MojIzuzetak : public exception
{
public:

	const char* what() const throw ()
	{
		return "Nije moguce uneti negativan broj(Exception).";
	}

};


