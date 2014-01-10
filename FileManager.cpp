#include "FileManager.h"


FileManager::FileManager(void)
{
	identifierFound = false;
}


FileManager::~FileManager(void)
{
}

void FileManager::LoadContent(const char *filename,
	std::vector<std::vector<std::string> > &attributes,
	std::vector<std::vector<std::string> > &contents)
{
	std::string line;
	std::string newLine;

	std::ifstream openfile(filename);
	if(openfile.is_open())
	{
		while(!openfile.eof())
		{
			std::stringstream str;
			std::getline(openfile, line);

			if(line.find("Load=") != std::string::npos)
			{
				type = LoadType::Attributes;
				line = line.erase(0,line.find("=") + 1);
				tempAttributes.clear();
			}
			else
			{
				type = LoadType::Contents;
				tempContents.clear();
			}

			str << line;

			while(std::getline(str,newLine,']'))
			{
				newLine.erase(std::remove(newLine.begin(),newLine.end(),'['),
					newLine.end());

				std::string erase = " \t\n\r";

				newLine.erase(newLine.find_last_not_of(erase) + 1);

				if(type == LoadType::Attributes)
					tempAttributes.push_back(newLine);
				else
					tempContents.push_back(newLine);

				std::cout << newLine << std::endl;
			}
			if(type == LoadType::Contents && tempContents.size() > 0)
			{
				attributes.push_back(tempAttributes);
				contents.push_back(tempContents);
			}
		}
	}
	else
	{
	}
}

void FileManager::LoadContent(const char *filename,
	std::vector<std::vector<std::string> > &attributes,
	std::vector<std::vector<std::string> > &contents, std::string identifier)
{
	std::string line;
	std::string newLine;

	std::ifstream openfile(filename);
	if(openfile.is_open())
	{
		while(!openfile.eof())
		{
			std::stringstream str;
			std::getline(openfile, line);

			if(line.find("EndLoad=") != std::string::npos &&
				line.find(identifier) != std::string::npos)
			{
				identifierFound = false;
				break;
			}
			else if(line.find("Load=") != std::string::npos &&
				line.find(identifier) != std::string::npos)
			{
				identifierFound = true;
				continue;
			}

			if(identifierFound)
			{
				if(line.find("Load=") != std::string::npos)
				{
					type = LoadType::Attributes;
					line = line.erase(0,line.find("=") + 1);
					tempAttributes.clear();
				}
				else
				{
					type = LoadType::Contents;
					tempContents.clear();
				}

				str << line;

				while(std::getline(str,newLine,']'))
				{
					newLine.erase(std::remove(newLine.begin(),newLine.end(),'['),
						newLine.end());

					std::string erase = " \t\n\r";

					newLine.erase(newLine.find_last_not_of(erase) + 1);

					if(type == LoadType::Attributes)
						tempAttributes.push_back(newLine);
					else
						tempContents.push_back(newLine);

					std::cout << newLine << std::endl;
				}
				if(type == LoadType::Contents && tempContents.size() > 0)
				{
					attributes.push_back(tempAttributes);
					contents.push_back(tempContents);
				}
			}
		}
	}
	else
	{
	}
}