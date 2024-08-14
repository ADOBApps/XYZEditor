#ifndef CPPGLUE_H
#define CPPGLUE_H

#include "json.hpp"
#include <fstream>
#include <iostream>
#include <exception>
#include <string>
// for convenience
using json = nlohmann::json;
using namespace std;

class GlueMan{
	public:
		json getJSON(string name);
		void printJSON(string name);
		bool putJSON(string name, json data);
		vector<string> getJSON2Vector(string name, string parameter);
		map<string, string> getJSON2BDVector(string name, string parameter);
		int test();
};

#endif // CPPGLUE_H
