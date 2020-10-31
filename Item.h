#pragma once
using namespace std;
#include <string>
#include <map>
#include <iostream>
#include "Functions.h"

class Item{
public:
	Item();
	void set_name(string name_);
	string get_name();
	void set_desc(string desc_);
	string get_desc();
	void display();
	string get_display();
	void add_attribute(string key, string value);
	string get_attribute(string key_);
private:
	string name;
	string desc;
	string type;
	map<string, string> attributes;
};