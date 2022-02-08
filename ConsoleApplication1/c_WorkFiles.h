#pragma once
#include <iostream>
#include <fstream>
#include <string>
class c_WorkFiles
{
private:
	std::fstream file;
	std::string path;
public:
	void setPath(std::string path);

	int findString(std::string str);
	void replaseString(std::string oldStr, std::string newStr);
	void print();
	void revert();
	

	~c_WorkFiles()
	{
		file.close();
	}
	
};

