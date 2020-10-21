#include "Entity.h";


Entity::Entity(){}
void Entity::render(Tile* tile){
	cout << fg(f_color) << bg(tile->get_bg()) << c;
}
void Entity::set_char(char c_){
	c = c_;
}
void Entity::set_fg(Color color_){
	f_color = color_;
}
void Entity::set_bg(Color color_){
	b_color = color_;
}
char Entity::get_char(){
	return c;
}
Color Entity::get_fg(){
	return f_color;
}
Color Entity::get_bg(){
	return b_color;
}
void Entity::set_x(int x_){
	x = x_;
}
void Entity::set_y(int y_){
	y = y_;
}
int Entity::get_x(){
	return x;
}
int Entity::get_y(){
	return y;
}
void Entity::set_map(Map* m){
	map = m;
}
Map* Entity::get_map(){
	return map;
}
void Entity::move_up(){
	int x = get_x();
	int y = get_y();
	Tile* t = get_map()->get_tile_r(x, y - 1);
	if(!t->get_solid()){
		set_y(y - 1);
	}
}
void Entity::move_down(){
	int x = get_x();
	int y = get_y();
	Tile* t = get_map()->get_tile_r(x, y + 1);
	if(!t->get_solid()){
		set_y(y + 1);
	}
}
void Entity::move_left(){
	int x = get_x();
	int y = get_y();
	Tile* t = get_map()->get_tile_r(x - 1, y);
	if(!t->get_solid()){
		set_x(x - 1);
	}
}
void Entity::move_right(){
	int x = get_x();
	int y = get_y();
	Tile* t = get_map()->get_tile_r(x + 1, y);
	if(!t->get_solid()){
		set_x(x + 1);
	}
}
void Entity::update(){}