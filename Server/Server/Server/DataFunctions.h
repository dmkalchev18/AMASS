#pragma once
#include "Libraries.h"

void saveStr(std::fstream& file, std::string str);
void readStr(std::fstream& file, std::string& str);
void saveBool(std::fstream& file, bool a);
void saveInt(std::fstream& file, int a);
void saveVec(std::fstream& file, std::vector<int> vec);
void saveVec(std::fstream& file, std::vector<std::string> vec);
void readInt(std::fstream& file, int& num);
void readBool(std::fstream& file, bool& a);
void readVec(std::fstream& file, std::vector<std::string>& vec);
void readVec(std::fstream& file, std::vector<int>& vec);