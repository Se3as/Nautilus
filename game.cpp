
#include "ship.h"
#include <fstream>  

using namespace std;
class Game {
	public:
	std::ofstream csv;
	Game(){
		csv.open("resultado.csv");
		csv << "Barco,operacion,iteraciones,daño\n";
		srand(time(0));
	}

	void register_insert(int& iterations, string& name){
		csv << name <<","<<"insert,"<<iterations<<",0\n";
	}
	void register_remove(int& iterations, string& name){
		csv << name <<","<<"deletion,"<<iterations<<",0\n";
	}
	void register_search(int& iterations, string& name, double& damage){
		csv << name <<","<<"search,"<<iterations<<","<<damage<<"\n";
	}
	void close(){
		csv.close();
	}
	void load_ship(Ship* ship){
		unordered_set<int> initial_elements;
		int iterations = 0;
		for(int i = 1; i < 101; i++){ 
			initial_elements.insert(i);  
			                             
		}
		for(int i = 1; i < 101; i++){
			//int num = *initial_elements.begin();
			int num = rand() % 100 + 1;
			while (initial_elements.find(num) == initial_elements.end()) {
				num = rand() % 100 + 1; 
			}
			cout<<num<<"/n";
			//initial_elements.erase(initial_elements.begin());
			ship->insert_iterations(num,iterations);
			register_insert(iterations,ship->name);
			iterations = 0;
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
		double damage = 100/(double)iterations;
		register_search(iterations, ship->name, damage);
		return damage;
	}
	void searches(Ship* ship){
		int iterations = 0;
		for(int i=0; i < 100; i++){
		int num = select_random(ship);
		ship->search_iterations(num, iterations);
		double damage = 100/(double)iterations;
		register_search(iterations, ship->name, damage);
		iterations = 0;
		}
	}
	void deletions(Ship* ship){
		int iterations = 0;
		for(int i=0; i < 50; i++){
		int num = select_random(ship);
		ship->remove_iterations(num,iterations,iterations);
		register_remove(iterations, ship->name);
		iterations = 0;
		}
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

    Ship1 ship1("Lista", 100, 500);
    Ship2 ship2("Array", 100, 600);
    Ship3 ship3("Set", 100, 700);
	Ship4 ship4("RedBlack", 100, 700);
	Ship5 ship5("Btree", 100, 700);
    Ship6 ship6("Splay", 100, 800);
    
    cout << "Creación de Barcos:" << endl << endl;
    cout << ship1.name << " con vida: " << ship1.life << endl;
    cout << ship2.name << " con vida: " << ship2.life <<endl;
    cout << ship3.name << " con vida: " << ship3.life << endl;
	cout << ship4.name << " con vida: " << ship4.life << endl;
	cout << ship5.name << " con vida: " << ship4.life << endl;
    cout << ship6.name << " con vida: " << ship6.life << endl;
    cout << endl;
	
    
    Game game;
    game.load_ship(&ship1);
    game.load_ship(&ship2);
    game.load_ship(&ship3);
	game.load_ship(&ship4);
	game.load_ship(&ship5);
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
    cout <<"Barco "<<ship2.name << " ataca " << ship6.name<< endl;
    cout << ship6.name << " ahora tiene vida: " << ship6.life << endl<<endl;

	game.shoot(&ship4, &ship5);
    cout <<"Barco "<<ship4.name << " ataca " << ship5.name<< endl;
    cout << ship5.name << " ahora tiene vida: " << ship5.life << endl<<endl;

	game.shoot(&ship5, &ship4);
    cout <<"Barco "<<ship5.name << " ataca " << ship4.name<< endl;
    cout << ship4.name << " ahora tiene vida: " << ship4.life << endl<<endl;
	game.searches(&ship1);
	game.searches(&ship2);
	game.searches(&ship3);
	game.searches(&ship4);
	game.searches(&ship5);
	game.searches(&ship6);
	
	game.deletions(&ship1);
	game.deletions(&ship2);
	game.deletions(&ship3);
	game.deletions(&ship4);
	game.deletions(&ship5);
	game.deletions(&ship6);

	game.close();
    return 0;
}