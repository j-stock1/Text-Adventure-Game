using namespace std;
#include "MP4.h";

class Grass : public Tile{
public:
	Grass(){
		set_char('*');
		set_bg(Color(0, 200, 0));
		set_fg(Color(191, 147, 13));
		set_solid(false);
	}
};


class Dirt : public Tile{
public:
	Dirt(){
		set_char('*');
		set_fg(Color(138, 75, 28));
		set_bg(Color(219, 148, 94));
		set_solid(false);
	}
};

class StoneBrick : public Tile{
public:
	StoneBrick(){
		set_char(206);
		set_fg(Color(50, 50, 50));
		set_bg(Color(150, 150, 150));
		set_solid(true);
	}
};

class Player : public Entity{
public:
	Player(){
		set_char('@');
		set_fg(Color(0, 0, 255));
	}
	void update(){
		//move_up();
	}
private:
};

int main(){
	Grass g = Grass();
	Dirt d = Dirt();
	StoneBrick s = StoneBrick();
	Map m = Map(10, 10);
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			m.set_tile(x, y, &d);
		}
	}
	for(int y = 0; y < 5; y++){
		for(int x = 0; x < 5; x++){
			m.set_tile(x+3, y+3, &g);
		}
	}

	m.set_tile(0, 0, &s);
	m.set_tile(0, 1, &s);
	m.set_tile(0, 2, &s);
	m.set_tile(0, 3, &s);
	m.set_tile(1, 3, &s);
	m.set_tile(2, 3, &s);
	m.set_tile(4, 3, &s);
	m.set_tile(4, 2, &s);
	m.set_tile(4, 1, &s);
	m.set_tile(4, 0, &s);

	Player p = Player();

	p.set_x(2);
	p.set_y(1);

	m.add_entity(&p);

	char inp;

	while(true){
		m.update();
		system("CLS");
		m.render(0, 0, 10, 10);
		reset_colors();
		cout << ":";
		cin >> inp;
		if(inp=='u'){
			p.move_up();
		}else if(inp=='d'){
			p.move_down();
		}else if(inp=='l'){
			p.move_left();
		}else if(inp=='r'){
			p.move_right();
		}
	}
}