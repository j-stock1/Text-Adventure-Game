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

void display_items(vector<Item> items, string title){
	string s = "";
	s += "----" + title + "----\n";
	for(int i = 0; i < items.size(); i++){
		s+= to_string(i) + ": ";
		s+= items[i].get_display();
		s+= "\n";
	}
	print_text(s);
}

void print_text(string text){
	for(int i = 1; i < text.length(); i++){
		sleep(30);
		cout << text[i];
	}
}

void sleep(int milli){
	this_thread::sleep_for(chrono::milliseconds(milli));
}

void cutscene(string file) {
	fstream newfile;
	newfile.open(file, ios::in);
	string tp;
	vector<string> frames;
	while (!newfile.eof()) {
		getline(newfile, tp);
		frames.push_back(tp + "\n");
	}
	string frame;
	for (int i = 0; i < int(frames.size()); i++) {
		if (i % 30 == 0) {
			cout << frame;
			frame = "";
			sleep_for(40ms);
		}
		frame += frames[i];
	}
	newfile.close();
}
