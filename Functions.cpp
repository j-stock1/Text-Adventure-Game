using namespace std;
#include "Functions.h";

void set_color(Color c, bool fg){
	string s = "";

	s.push_back(0x1b);

	s += '[';

	if(fg){
		s += "38;2;";
	} else{
		s += "48;2;";
	}
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	cout << s;
}

void reset_colors(){
	string s = "";
	s.push_back(0x1b);
	s += "[0;39;49m";

	cout << s;
}

string reset(){
	string s = "";
	s.push_back(0x1b);
	s += "[0;39;49m";

	return s;
}

string bg(Color c){
	string s = "";

	s.push_back(0x1b);

	s += "[48;2;";
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	return s;
}

string fg(Color c){
	string s = "";

	s.push_back(0x1b);

	s += "[38;2;";
	s += to_string(c.r) + ';' + to_string(c.g) + ';' + to_string(c.b) + 'm';

	return s;
}