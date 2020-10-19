using namespace std;
#include <iostream>;
#include <string>;
#include <vector>;
#include <time.h>;

struct Color{
	Color(){}
	Color(int r_, int g_, int b_){
		r = r_;
		g = g_;
		b = b_;
	}
	int r = 0;
	int g = 0;
	int b = 0;
};

void set_color(Color c,  bool fg){
	string s = "";

	s.push_back(0x1b);

	s += '[';

	if(fg){
		s += "38;2;";
	}else{
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





class Tile{
public:
	Tile();
	Tile(char c_, Color f_color_, Color b_color_);
	void set_char(char c_);
	void set_fg(Color color_);
	void set_bg(Color color_);
	void render();
private:
	char c;
	Color f_color;
	Color b_color;
};
Tile::Tile(){ 
	c = ' '; 
}
Tile::Tile(char c_, Color f_color_, Color b_color_){
	c = c_;
	f_color = f_color_;
	b_color = b_color_;
}
void Tile::set_char(char c_){ 
	c = c_;
}
void Tile::set_bg(Color color_){ 
	b_color = color_; 
}
void Tile::set_fg(Color color_){ 
	f_color = color_; 
}
void Tile::render(){
	cout << fg(f_color) + bg(b_color) + c;
}

class Grass : Tile{
public:
	Grass();
};
Grass::Grass(){
	set_char('*');
	set_bg(Color(0, 255, 0));
	set_fg(Color(50, 255, 50));
}

class map{
public:
	map();
	map(int w_, int h_);
	Tile * get_tile(int w, int h);
	void set_tile(int w, int h, Tile t);
	void render();
private:
	int w;
	int h;
	vector<Tile> tiles;
};
map::map(){ 
	w = 0; h = 0; 
}
map::map(int w_, int h_){
	for(int i = 0; i < w_ * h_; i++){
		tiles.push_back(Tile());
	}
	w = w_;
	h = h_;
}
Tile * map::get_tile(int w_, int h_){
	Tile* p = &tiles[h_ * w + w_];
	return p;
}
void map::set_tile(int w_, int h_, Tile t){
	tiles[h_ * w + w_] = t;
}
void map::render(){
	for(int i = 0; i < w * h; i++){
		tiles[i].render();
		if((i+1) % w == 0){
			cout << endl;
		}
	}
}

int main(){
	map m = map(5, 5);
	for(int i = 0; i < 5; i++){
		Tile* t = m.get_tile(i, i);
		t->set_char('*');
		t->set_fg(Color(0, 255, 0));
		t->set_bg(Color(0, 0, 255));
	}

	Grass g = Grass();
	//m.set_tile(0, 0, g);

	m.render();
	reset_colors();
}
