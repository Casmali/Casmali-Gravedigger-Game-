#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class FileManager
{
private:
	enum LoadType { Attributes, Contents };
	int type;
	bool identifierFound;

	std::vector<std::string> tempAttributes;
	std::vector<std::string> tempContents;
public:
	FileManager();
	~FileManager();

	void LoadContent(const char *filename,std::vector<std::vector<std::string> > &attributes,
		std::vector<std::vector<std::string> > &contents);

	void LoadContent(const char *filename,std::vector<std::vector<std::string> > &attributes,
		std::vector<std::vector<std::string> > &contents, std::string identifier);
};

