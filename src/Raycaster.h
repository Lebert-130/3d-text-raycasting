#include <iostream>
#include <vector>

class CRaycaster
{
public:
	void Init();
	std::vector<std::vector<int>> vectormap;
	int width;
	int height;
	int x;
	int y;
};