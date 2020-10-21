#include "Tile.h";
using namespace std;


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
void Tile::set_fg(Color color_){
	f_color = color_;
}
void Tile::set_bg(Color color_){
	b_color = color_;
}
Color Tile::get_fg(){
	return f_color;
}
Color Tile::get_bg(){
	return b_color;
}
void Tile::set_solid(bool b){
	solid = b;
}
bool Tile::get_solid(){
	return solid;
}
void Tile::render(){
	cout << fg(f_color) + bg(b_color) + c;
}