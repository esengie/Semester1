#pragma once

#include "string"
#include "iostream"


namespace hashes
{
	const int ARRAYLENGTH = 503;
	const int PRIME = 13;


	bool find(std::string, int hashfunction);
	void insertHash (std::string, int hashfunction);
	void createHash ();
	void deleteHash ();
	int func (std::string, char ghr =0);
	void printHash ();
}