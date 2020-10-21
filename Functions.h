#pragma once
#include <string>;
#include <iostream>;
#include "Structures.h";
using namespace std;


void set_color(Color c, bool fg);
void reset_colors();
string reset();
string bg(Color c);
string fg(Color c);