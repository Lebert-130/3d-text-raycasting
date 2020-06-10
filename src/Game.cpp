#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Raycaster.h"

CRaycaster raycaster;
std::vector<std::vector<int>> vec = {};

void LoadMap(std::string mapName) 
{
	std::vector<int> row = {};
	std::ifstream infile;
	infile.open(mapName + ".txt");

	if (infile.fail()) {
		system("CLS");
		std::cout << "File not found" << std::endl;
		system("PAUSE");
		exit(0);
	}
	else {
		std::string s;

		if (infile.is_open()) {
			while (std::getline(infile, s))
			{
				for (char& c : s) {
					if (!isspace(c)) {
						if (c != '0') {
							row.push_back(std::stoi(s));
						}
						else
						{
							row.push_back(std::stoi(s) - 1);
						}
					}
				}
				vec.push_back(row);
				row.clear();
			}
			infile.close();
		}
	}
}

int main() 
{
	std::string mapfile;
	int width;
	int height;
	int x;
	int y;

	std::cout << "Enter map file: ";
	std::cin >> mapfile;

	system("CLS");

	std::cout << "Enter width (Must type the exact width from the txt file!: ";
	std::cin >> width;

	system("CLS");

	std::cout << "Enter height (Must type the exact width from the txt file!: ";
	std::cin >> height;

	system("CLS");

	std::cout << "Enter X Position to spawn (Must not be outside of boundaries!: ";
	std::cin >> x;

	system("CLS");

	std::cout << "Enter Y Position to spawn (Must not be outside of boundaries!: ";
	std::cin >> y;

	std::cout << "LOADING...";

	LoadMap(mapfile);

	raycaster.vectormap = vec;
	raycaster.width = width;
	raycaster.height = height;
	raycaster.x = x;
	raycaster.y = y;
	raycaster.Init();

	return 0;
}