#include "c_WorkFiles.h"

void c_WorkFiles::setPath(std::string path)
{
	this->file.close();
	this->file.open(path, std::ios::in | std::ios::out);
	this->path = path;
}

int c_WorkFiles::findString(std::string str)
{
	size_t count = 0;
	if (this->file.is_open()) {
		size_t pos = 0;
		std::string tmp;
		while (!this->file.eof())
		{
			std::getline(file, tmp);
			while ((pos = tmp.find(str)) != std::string::npos)
			{
				tmp.erase(0, pos + str.length());
				count++;
			}
		}
	}
	return count;
}

void c_WorkFiles::replaseString(std::string oldStr, std::string newStr)
{
	if (this->file.is_open()) {
		std::string tmp;
		char ch;

		while (this->file.get(ch)) {
			tmp += ch;
		}

		size_t i = tmp.find(oldStr, 0);
		while (i != std::string::npos) {
			tmp.replace(i, newStr.length(), newStr);
			i = tmp.find(oldStr, i);
		}

		this->file.clear();
		this->file.seekg(0, std::ios::beg);

		this->file << tmp;
	}
}

void c_WorkFiles::print()
{
	if (this->file.is_open()) {
		std::string tmp;
		while (!this->file.eof())
		{
			std::getline(file, tmp);
			std::cout << tmp << "\n";
		}
	}
}

void c_WorkFiles::revert()
{
	if (this->file.is_open()) {
		std::string tmp;
		char ch;

		while (this->file.get(ch)) {
			tmp += ch;
		}

		for (size_t i = 0; i < tmp.length() /2; i++) {
			std::swap(tmp[i], tmp[tmp.length() - i - 1]);
		}

		this->file.clear();
		this->file.seekg(0, std::ios::beg);

		this->file << tmp;
	}
}
