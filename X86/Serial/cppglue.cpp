/***************************************************************
 * Name:      CppGlue.cpp
 * Purpose:   Code for JSON usign test
 * Author:    Acxel Orozco (acxelorozco@gmail.com)
 * Created:   2023-07-10
 * Copyright: Acxel Orozco ()
 * License:
 **************************************************************/

#include "json.hpp"
#include "cppglue.h"
#include <fstream>
#include <iostream>
#include <exception>
#include <string>

// for convenience
using json = nlohmann::json;
using namespace std;

//#define EXTRACT(x) x = J[#x].get< decltype(x) >()

json GlueMan::getJSON(string name){
	json data;
    try {
    	// read a JSON file
	    //std::ifstream file_input("glue.json");
	    std::ifstream file_input(name);
	    file_input >> data;
    	return data;
    }
    catch(exception& e) {
        cout << e.what() << endl;
        return data;
    }
}

vector<string> GlueMan::getJSON2Vector(string name, string parameter){
	json data;
	std::vector<string> neodatum;
    try {
    	// read a JSON file
	    //std::ifstream file_input("glue.json");
	    std::ifstream file_input(name);
	    file_input >> data;
	    neodatum = data[parameter].get<std::vector<string>>();
        return neodatum;
    }
    catch(exception& e) {
        cout << e.what() << endl;
        return neodatum;
    }
}

map<string, string> GlueMan::getJSON2BDVector(string name, string parameter){
	json data;
	map<string, string> neodatum;
    try {
    	// read a JSON file
	    //std::ifstream file_input("glue.json");
	    std::ifstream file_input(name);
	    file_input >> data;
	    neodatum = data[parameter].get<std::map<string, string>>();
        return neodatum;
    }
    catch(exception& e) {
        cout << e.what() << endl;
        return neodatum;
    }
}

void GlueMan::printJSON(string name){
	json data;
    try {
    	// read a JSON file
	    //std::ifstream file_input("glue.json");
	    std::ifstream file_input(name);
	    file_input >> data;
    	cout <<  data;
    }
    catch(exception& e) {
        cout << e.what() << endl;
        cout <<  data;
    }
}

bool GlueMan::putJSON(string name, json data){
	try{
	    // write prettified JSON to another file
	    std::ofstream output(name);
	    output << std::setw(4) << data << std::endl;
	    return true;
	}
    catch(exception& e) {
        cout << e.what() << endl;
        return false;
    }
}

int GlueMan::test(){
	return 10;
}
