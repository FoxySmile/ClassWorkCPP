#pragma once
#include <iostream>
#include "Lines.h"

using namespace std;

class FileReader
{
public:
	static Lines read(string path);
};

