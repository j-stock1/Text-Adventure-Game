#include "Map.h";

Map::Map(){
	w = 0; h = 0;
	empty.set_solid(true);
}
Map::Map(int w_, int h_){
	for(int i = 0; i < w_ * h_; i++){
		tiles.push_back(&empty);
	}
	w = w_;
	h = h_;
	empty.set_solid(true);
}
Tile* Map::get_tile_r(int x, int y){
	if(x < 0 || x >= w){ return &empty; }
	if(y < 0 || y >= h){ return &empty; }
	Tile* p = tiles[y * w + x];
	return p;
}
void Map::set_tile(int x, int y, Tile* t){
	if(x < 0 || x >= w){ return; }
	if(y < 0 || y >= h){ return; }
	Tile* old = get_tile_r(x, y);
	tiles[y * w + x] = t;
	//delete old;
}
void Map::add_entity(Entity* e){
	entities.push_back(e);
	e->set_map(this);
}
int Map::get_entity(int x, int y){
	for(int i = 0; i < entities.size(); i++){
		Entity* e = entities[i];
		if(e->get_x() == x && e->get_y() == y){
			return i;
		}
	}
	return -1;
}
int Map::get_w(){
	return w;
}
int Map::get_h(){
	return h;
}
void Map::update(){
	for(int i = 0; i < entities.size(); i++){
		entities[i]->update();
	}
}
void Map::render(){
	for(int i = 0; i < w * h; i++){
		tiles[i]->render();
		if((i + 1) % w == 0){
			cout << endl;
		}
	}
}
void Map::render(int x, int y, int w_, int h_){
	int x_, y_, e;
	Tile* t;
	for(int i = 0; i < h_; i++){
		for(int j = 0; j < w_; j++){
			x_ = x + j;
			y_ = y + i;
			e = get_entity(x_, y_);
			t = tiles[x_ + y_ * (w)];
			if(e == -1){
				t->render();
			} else{
				entities[e]->render(t);
			}
		}
		cout << endl;
	}
}