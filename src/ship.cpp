#define NUM_OF_ELEMENTS 100
#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class Splay_tree {
	public:
    Node* root;
    Splay_tree() : root(NULL) {}
    Node* rightRotate(Node* x, int& iterations) {
		iterations++;
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node* leftRotate(Node* x, int& iterations) {
		iterations++;
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node* splay(Node* root, int data, int& iterations) {
		iterations++;
        if (!root || root->data == data)
            return root;
        
        if (data < root->data) {
            if (!root->left)
                return root;
            
            if (data < root->left->data) {
                root->left->left = splay(root->left->left, data, iterations);
                root = rightRotate(root, iterations);
            } else if (data > root->left->data) {
                root->left->right = splay(root->left->right, data, iterations);
                if (root->left->right)
                    root->left = leftRotate(root->left, iterations);
            }
            return (root->left) ? rightRotate(root, iterations) : root;
        } else {
            if (!root->right)
                return root;
            
            if (data > root->right->data) {
                root->right->right = splay(root->right->right, data, iterations);
                root = leftRotate(root, iterations);
            } else if (data < root->right->data) {
                root->right->left = splay(root->right->left, data, iterations);
                if (root->right->left)
                    root->right = rightRotate(root->right, iterations);
            }
            return (root->right) ? leftRotate(root, iterations) : root;
        }
    }
    bool insert(int data, int& iterations) {
		iterations++;
        if (!root) {
            root = new Node(data);
            return true;
        }

        root = splay(root, data, iterations);
        
        if (root->data == data)
            return false;
        
        Node* newNode = new Node(data);
        if (data < root->data) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = NULL;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = NULL;
        }
        root = newNode;
        return true;
    }
	bool search(int data, int& iterations) {
		iterations++;
        if (!root) return false;
        root = splay(root, data, iterations);
        return (root->data == data);
    }
	
    bool remove(int data, int& up_points, int& iterations) {
        iterations++;
        if (!root)
            return false;
        
        root = splay(root, data, iterations);
        if (root->data != data)
            return false;
        
        Node* temp;
        if (!root->left) {
            temp = root;
            root = root->right;
        } else {
            temp = root;
            root = splay(root->left, data, iterations);
            root->right = temp->right;
        }
        delete temp;
        return true;
    }	
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
    
    void print() {
        inorder(root);
        std::cout << std::endl;
    }
};
	
class Linked_list {
	public:
    Node* head;
    Node* end;
    
    Linked_list() : head(NULL), end(NULL) {}
    ~Linked_list(){
		Node* curr = head;
		while (curr != NULL) {
			Node* next = curr->right;
			delete curr;
			curr = next;
		}
	}
    
    bool lineal_search(int data, int& iterations) {
        Node* curr = head;
        while (curr != NULL) {
            iterations++;
            if (curr->data == data) {
                return true;
            }
            curr = curr->right;
        }
        return false;
    }

    bool insert(int data, int& iterations) {
        Node* new_node = new Node(data);
        new_node->right = head;
        head = new_node;
        if (end == NULL) {
            end = new_node;
        }
        iterations++;
        return true;
    }

    bool remove(int data, int& iterations, int& up_points) {
        if (head == NULL) {
            iterations++;
            return false;
        }

        if (head->data == data) {
            iterations++;
            if (up_points >= iterations) {
                Node* temp = head;
                head = head->right;
                delete temp;
                return true;
            }
            return false;
        }

        Node* curr = head;
        while (curr->right != NULL && curr->right->data != data) {
            iterations++;
            curr = curr->right;
        }

        if (curr->right != NULL) {
            iterations++;
            if (up_points >= iterations) {
                Node* temp = curr->right;
                curr->right = curr->right->right;
                delete temp;
                if (curr->right == NULL) {
                    end = curr;
                }
                return true;
            }
        }
        return false;
    }
};



class Array {
public:
    int* arr;
    int capacity;
    int size;

    Array(int c) : capacity(c), size(0) {
        arr = new int[capacity];
    }

    ~Array() {
        delete[] arr;
    }

    bool binary_search(int data, int& iterations, int& index) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            iterations++;

            if (arr[mid] == data) {
                index = mid;
                return true;
            }
            if (arr[mid] < data) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        index = left;
        return false;
    }

    bool insert(int data, int& iterations) {
        if (size == capacity) {
            resize();
        }
	    int index;
		binary_search(data, iterations, index);

		for (int i = size; i > index; --i) {
			arr[i] = arr[i - 1];
			iterations++;
		}
		
		arr[index] = data;
		size++;
		iterations++;

    return true;
    }

    bool remove(int data, int& iterations, int& up_points) {
        int index;
        if (!binary_search(data, iterations, index)) {
            return false;
        }

        for (int i = index; i < size - 1; i++) {
            iterations++;
            if (up_points >= iterations) {
                arr[i] = arr[i + 1];
            }
        }
        size--;
        return true;
    }
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }
};
class Ship {
	public:
	string name;
	unordered_set<int> elements;
	int life;
	int price;
	virtual bool search_iterations(int num, int& iterations) = 0;
	virtual bool insert_iterations(int num, int& iterations) = 0;
    virtual bool remove_iterations(int num, int& up_points, int& iterations) = 0;
	bool search_element(int num){
		return elements.find(num) != elements.end();
	}
	Ship(string n, int l, int p): name(n), life(l), price(p){}
};
class Ship1 : public Ship{
	public:
	Linked_list* linked_list;
	Ship1(string n, int l, int p): Ship(n, l, p){
		linked_list = new Linked_list();
	}
	bool search_iterations(int num, int& iterations){	 
		return linked_list->lineal_search(num,iterations);
	}
	bool insert_iterations(int num, int& iterations){
		elements.insert(num);
		return linked_list->insert(num,iterations);
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		return linked_list->remove(num, up_points, iterations);
	}
};
class Ship2 : public Ship{
	public:
	Array* array;
	Ship2(string n, int l, int p): Ship(n, l, p){
		array = new Array(200);
	}
	bool search_iterations(int num, int& iterations){
		int index = 0;
		return array->binary_search(num,iterations,index);
	}
	bool insert_iterations(int num, int& iterations){
		elements.insert(num);
		return array->insert(num,iterations);
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		return array->remove(num, up_points, iterations);
	}
};
class Ship3 : public Ship{
	public:
	Ship3(string n, int l, int p): Ship(n, l, p){
	}
	bool search_iterations(int num, int& iterations){
		iterations += 1;
		return 1;
	}
	bool insert_iterations(int num, int& iterations){
		iterations += 1;
		elements.insert(num);
		return 1;
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		iterations += 1;
		if(search_element(num)){
			elements.erase(num);
			return 1;
		}
		return 0;
	}
};
/*class Ship4 : public Ship{
	public:
	Redblack_tree* redblack_tree;
	Ship4(string n, int l, int p): Ship(n, l, p){
		redblack_tree = new Redblack_tree();
	}
	bool search_iterations(int num, int& iterations){	
		return redblack_tree->search(num,iterations);
	}
	bool insert_iterations(int num, int& iterations){
		elements.insert(num);
		return redblack_tree->insert(num,iterations);
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		return redblack_tree->remove(num, up_points, iterations);
	}
};
class Ship5 : public Ship{
	public:
	B_tree* b_tree;
	Ship5(string n, int l, int p): Ship(n, l, p){
		b_tree = new B_tree();
	}
	bool search_iterations(int num, int& iterations){
		return b_tree->search(num,iterations);
	}
	bool insert_iterations(int num, int& iterations){
		elements.insert(num);
		return b_tree->insert(num,iterations);
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		return b_tree->remove(num, up_points, iterations);
	}
};*/
class Ship6 : public Ship{
	public:
	Splay_tree* splay_tree;
	Ship6(string n, int l, int p): Ship(n, l, p){
		splay_tree = new Splay_tree();
	}
	bool search_iterations(int num, int& iterations){
		return splay_tree->search(num,iterations);
	}
	bool insert_iterations(int num, int& iterations){
		elements.insert(num);
		return splay_tree->insert(num,iterations);
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		return splay_tree->remove(num, up_points, iterations);
	}
};

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