#pragma once
using namespace std;
#include "Functions.h"
#include "Tile.h"
#include "Map.h"
#include "Structures.h"

class Map;

class Entity{
public:
	Entity();
	void render(Tile* tile);
	string r_render(Tile* tile);
	void set_char(char c_);
	void set_fg(Color color_);
	void set_bg(Color color_);
	char get_char();
	Color get_fg();
	Color get_bg();
	void set_x(int x_);
	void set_y(int y_);
	int get_x();
	int get_y();
	void set_map(Map* m);
	Map* get_map();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	virtual void update();
private:
	char c;
	int x;
	int y;
	Color f_color;
	Color b_color;
	Map* map = NULL;
};