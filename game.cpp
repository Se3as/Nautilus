
#include "ship.h"
class Game {
	public:
	Game(){
		srand(time(0));
	}
	void register_insert(int& iterations, string& name){}
	void register_remove(int& iterations, string& name){}
	void register_search(int& iterations, string& name){}
	void load_ship(Ship* ship){
		unordered_set<int> initial_elements;
		int iterations = 0;
		for(int i = 1; i < 101; i++){
			initial_elements.insert(i);
		}
		for(int i = 1; i < 101; i++){
			int num = *initial_elements.begin();
			initial_elements.erase(initial_elements.begin());
			ship->insert_iterations(num,iterations);
			register_insert(iterations,ship->name);
		}
	}
	int select_random (Ship* ship){
		int num = 0;
		bool in_set = false;
		while(!in_set){
			num = rand() % 100 + 1;
			if(ship->search_element(num)){
				in_set = true;
			}
		}
		return num;
	}
	double attack(Ship* ship){
		int iterations = 0;
		int num = select_random(ship);
		ship->search_iterations(num, iterations);
		register_search(iterations, ship->name);
		double damage = 100/(double)iterations;
		return damage;
	}
	
	bool upgrade(Ship* ship, int up_points){
		int iterations = 0;
		bool sucess = false;
		int num = select_random(ship);
		sucess = ship->remove_iterations(num, up_points, iterations);
		register_remove(iterations, ship->name);
		return sucess;
	}
	void send_spy(Ship* ship){
		int iterations = 0;
		int num = rand() % 100 + 101;
		ship->insert_iterations(num, iterations);
		register_insert(iterations, ship->name);
	}
	void shoot(Ship* attacker, Ship* objective){
		double damage = attack(attacker);
		objective->life -= (int) damage;
	}
};


int main() {

    Ship1 ship1("Embarcacion Lista", 100, 500);
    Ship2 ship2("Embarcacion Array", 100, 600);
    Ship3 ship3("Embarcacion Set", 100, 700);
    Ship6 ship6("Embarcacion Splay", 100, 800);
    
    cout << "Creación de Barcos:" << endl << endl;
    cout << ship1.name << " con vida: " << ship1.life << endl;
    cout << ship2.name << " con vida: " << ship2.life <<endl;
    cout << ship3.name << " con vida: " << ship3.life << endl;
    cout << ship6.name << " con vida: " << ship6.life << endl;
    cout << endl;
	
    
    Game game;
    game.load_ship(&ship1);
    game.load_ship(&ship2);
    game.load_ship(&ship3);
    game.load_ship(&ship6);
	
    cout << "Ataques entre Embarcaciones:" << endl << endl ;
    
    game.shoot(&ship1, &ship2);
    cout <<"Barco "<<ship1.name << " ataca " << ship2.name << endl;
    cout << ship2.name << " ahora tiene vida: " << ship2.life << endl<<endl;
    
    game.shoot(&ship3, &ship1);
    cout <<"Barco "<<ship3.name << " ataca " << ship1.name << endl;
    cout << ship1.name << " ahora tiene vida: " << ship1.life << endl<<endl;
    
    game.shoot(&ship6, &ship3);
    cout <<"Barco "<<ship6.name << " ataca " << ship3.name << endl;
    cout << ship3.name << " ahora tiene vida: " << ship3.life << endl<<endl;
    
    game.shoot(&ship2, &ship6);
    cout <<"Barco "<<ship2.name << "ataca " << ship6.name<< endl;
    cout << ship6.name << " ahora tiene vida: " << ship6.life << endl;
    return 0;
}