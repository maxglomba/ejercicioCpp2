/*
Suponga que usted es un programador de videojuegos, desarrolle una aplicación sencilla para verificar la utilidad del concepto de polimorfismo. Su aplicación tendrá 3 personajes que son luchadores en un videojuego:
Codifique una interfaz "compTecnicaEspecial" que tiene un constructor por defecto, un destructor y un método virtual puro llamado "tecnicaEspecial"
Codifique una interfaz"compGolpePatada" que tiene un constructor por defecto, un destructor y un método virtual puro llamado "patada"
Codifique una interfaz "compPoder" que tiene un constructor por defecto, un destructor y un método virtual puro llamado "poder"

Diseñe 3 clases que heredan de la interfaz "compTecnicaEspecial", cada una implementa el método "tecnicaEspecial" de distinta forma de acuerdo al personaje que va a utilizar dicha técnica. Por ejemplo: El personaje Goku ejecuta como técnica especial la Genkidama, el personaje Naruto ejecuta la técnica Rasengan, etc. Estas clases cuentan con constructor por defecto y destructor.
Diseñe 3 clase que heredan de la interfaz "compGolpePatada", cada una implementa el método "patada" de acuerdo al personaje. Estas clases cuentan con constructor por defecto y destructor.
Diseñe 3 clase que heredan de la interfaz "compPoder", cada una implementa el método "poder" de acuerdo al personaje. Por ejemplo Goku hace un kame-hame-ha, Ryu lanza un ado-ken, etc. Estas clases cuentan con constructor por defecto y destructor.

Desarrolle una clase "Luchador" que tiene los siguientes miembros: un puntero "compTecnicaEspecial" a objetos de la clase "CompTecnicaEspecial", un puntero "compGolpePatada" a objetos de la clase "CompGolpePatada", un puntero "compPoder" a objetos de la clase "CompPoder", un método redefinible "saludo" que no recibe parámetros ni retorna valor alguno, un método "ejecutarEspecial" que invoca un método "tecnicaEspecial" del puntero compTecnicaEspecial, un método "ejecutarPatada" que invoca el método "patada" a través del puntero compGolpePatada, un método "ejecutarPoder" que invoca un método "poder" a través del puntero compPoder. Esta clase tiene un constructor por defecto y un destructor.
Desarrolle 3 clases que hereden de la clase "Luchador", estas clases corresponden a los personajes del videojuego (Goku, Naruto, Iron-Man, etc.) Estas clases redefinen el método "saludo" de la clase Luchador para que cada personaje haga su saludo característico. Estas clases cuentan también con un constructor por defecto en el que los punteros heredados de la clase Luchador se apuntan (reservan memoria) con el operador `new` a objetos de las clases creadas en los numerales 4, 5 y 6 dependiendo del personaje que está implementando. Las clases cuentan también con destructor para liberar con el operador delete la memoria reservada para los punteros.
Codifique una pequeña aplicación en la que se creen 3 personajes para el videojuego usando polimorfismo, es decir con punteros del tipo de la clase Luchador reserve memoria (con el operador new) para objetos de las clases que desarrolló en el numeral anterior. Con cada uno de los punteros ejecute los métodos saludo, ejecutarEspecial, ejecutarPatada y ejecutarPoder. No olvide liberar la memoria con el operador delete.

*/


#include <iostream>;
#include <stdlib.h>;

using namespace std;

//Interfaces
class compPoder {
public:
	virtual void poder() = 0;
	virtual string getNombre() = 0;
	virtual float getDamage() = 0;
};


class compGolpePatada {
public:
	virtual void patada() = 0;
	virtual string getNombre() = 0;
	virtual float getDamage() = 0;
};


class compTecnicaEspecial {
public:
	virtual void tecnicaEspecial() = 0;
	virtual string getNombre() = 0;
	virtual float getDamage() = 0;
};

//Clase abstracta para ataques

class Golpe {
protected:
	string name;
	float damage;
public:
	Golpe(string _name, float _damage) : name(_name), damage(_damage) {};
};

//Ataques

class Rasengan : public Golpe, public compPoder {
public:
	Rasengan(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void poder() override {
		cout << "Raaaaaseeeeeeengaaaaaan!!" << endl;
		cout << "Golpeo con " << name << " causando un daño de " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};

class Chidori : public Golpe, public compPoder {
public:
	Chidori(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void poder() override {
		cout << "Tsttztztzttst!!" << endl;
		cout << "El poder del " << name << " causo un daño de " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};

class Genjutsu : public Golpe, public compPoder {
public:
	Genjutsu(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void poder() override {
		cout << "tsuuumm... zzZzummm..." << endl;
		cout << "Se genera una ilusion gracias al " << name << ", gracias a esto daña al enemigo por " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};


class PatadaVoladora : public Golpe, public compGolpePatada {
public:
	PatadaVoladora(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void patada() override {
		cout << "Fiiuumm Tack!!" << endl;
		cout << "Lanza una " << name << " que lastima al contrincante por " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};

class PatadaBaja : public Golpe, public compGolpePatada {
public:
	PatadaBaja(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void patada() override {
		cout << "Trok!" << endl;
		cout << "Derriba al enemigo con " << name << " dañando por " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};

class PatadaVeloz : public Golpe, public compGolpePatada {
public:
	PatadaVeloz(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void patada() override {
		cout << "Tssak!" << endl;
		cout << "Da una " << name << "que daña por " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};


class ClonesDeSombra : public Golpe, public compTecnicaEspecial {
public:
	ClonesDeSombra(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void tecnicaEspecial() override {
		cout << "Trun trun trun trun trun trun!!" << endl;
		cout << "Se invoca " << name << ", en conjunto los clones dañan al enemigo por " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};

class CopiaMovimientos : public Golpe, public compTecnicaEspecial {
public:
	CopiaMovimientos(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void tecnicaEspecial() override {
		cout << "OooOommm" << endl;
		cout << "Realiza la copia del ultimo movimiento del enemigo gracias a " << name << ", causa daño por " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};

class MangekyoSharingan : public Golpe, public compTecnicaEspecial {
public:
	MangekyoSharingan(string _name, float _damage) : Golpe(_name, _damage) {
	}
	void tecnicaEspecial() override {
		cout << "Tsuuuuoommmmsss!" << endl;
		cout << "Una poderosa ilusion perturba al enemigo gracias a " << name << ", la misma inmoviliza al jugador unos segundos y causa daño por " << damage << endl;
	};
	string getNombre() { return name; };
	float getDamage() { return damage; };
};

//Clase abstracta para personajes

class Luchador {
protected:
	compPoder* ptr_poder;
	compGolpePatada* ptr_patada;
	compTecnicaEspecial* ptr_especial;
	string name;
	float hp;
public:
	Luchador() {};
	~Luchador() {
		cout << "Eliminando Luchador\n";
		//aca estaba el problema al hacer delete, dado que los punteros se vaciaban al hacer el delete de la clase hija, que es donde los asigno
		//delete ptr_poder;
		//delete ptr_patada;
		//delete ptr_especial;
	};
	virtual void saludo() = 0;
	void ejecutarPoder() {
		ptr_poder->poder();
	};
	void ejecutarPatada() {
		ptr_patada->patada();
	};
	void ejecutarEspecial() {
		ptr_especial->tecnicaEspecial();
	};
	//getters
	string getNombrePoder() {
		return ptr_poder->getNombre();
	};
	string getNombrePatada() {
		return ptr_patada->getNombre();
	};
	string getNombreEspecial() {
		return ptr_especial->getNombre();
	};
	float getDamagePoder() {
		return ptr_poder->getDamage();
	};
	float getDamagePatada() {
		return ptr_patada->getDamage();
	};
	float getDamageEspecial() {
		return ptr_especial->getDamage();
	};
	float applyDamage(float damage) {
		hp = hp - damage;
		return hp;
	}
	float getHp() { return hp; };
	string getName() { return name; };
};

class Naruto : public Luchador {

public:
	Naruto() : Luchador() {
		ptr_poder = new Rasengan("Rasengan", 123.00f);
		ptr_patada = new PatadaVoladora("Patada Voladora", 89.5f);
		ptr_especial = new ClonesDeSombra("Clones de Sombra", 189.0f);
		name = "Naruto";
		hp = 500;
	};
	~Naruto() {
		cout << "Eliminando punteros de Naruto\n";
		delete ptr_poder;
		delete ptr_patada;
		delete ptr_especial;
	};
	virtual void saludo() {
		cout << "Hola soy Naruto y me gusta el ramen de Ichiraku!";
	};
	void ejecutarPoder() {
		ptr_poder->poder();
	};
	void ejecutarPatada() {
		ptr_patada->patada();
	};
	void ejecutarEspecial() {
		ptr_especial->tecnicaEspecial();
	};
};


class Sasuke : public Luchador {

public:
	Sasuke() : Luchador() {
		ptr_poder = new Genjutsu("Genjutsu", 100.00f);
		ptr_patada = new PatadaBaja("Patada Baja", 90.00f);
		ptr_especial = new MangekyoSharingan("Mangekyo Sharingan", 200.0f);
		name = "Sasuke";
		hp = 450;
	};
	~Sasuke() {
		cout << "Eliminando punteros de Sasuke\n";
		delete ptr_poder;
		delete ptr_patada;
		delete ptr_especial;
	};
	virtual void saludo() {
		cout << "Hola soy Sasuke y soy cool!";
	};
	void ejecutarPoder() {
		ptr_poder->poder();
	};
	void ejecutarPatada() {
		ptr_patada->patada();
	};
	void ejecutarEspecial() {
		ptr_especial->tecnicaEspecial();
	};
};


class Kakashi : public Luchador {

public:
	Kakashi() : Luchador() {
		ptr_poder = new Chidori("Chidori", 140.00f);
		ptr_patada = new PatadaVeloz("Patada Veloz", 70.00f);
		ptr_especial = new CopiaMovimientos("Copia Movimientos", 180.0f);
		name = "Kakashi";
		hp = 580;
	};
	~Kakashi() {
		cout << "Eliminando punteros de Kakashi\n";
		delete ptr_poder;
		delete ptr_patada;
		delete ptr_especial;
	};
	virtual void saludo() {
		cout << "Hola soy Kakashi y no conoceras todo mi rostro!";
	};
	void ejecutarPoder() {
		ptr_poder->poder();
	};
	void ejecutarPatada() {
		ptr_patada->patada();
	};
	void ejecutarEspecial() {
		ptr_especial->tecnicaEspecial();
	};
};

//prototipos
void menu();
void pickCharacter(Luchador*&, int);
void deleteCharacter(Luchador*&);
void getAttacks(Luchador*&);
bool useAttacks(Luchador*&, Luchador*&, int);
void playGame(Luchador*&, Luchador*&);

//codigo de aplicacion
int main()
{
	menu();

	system("pause");
	return 0;
}

//funciones
void menu() {
	int input;
	int p1 = 0;
	int p2 = 0;
	Luchador* jugador2;
	Luchador* jugador1;
	do
	{
		system("cls");
		cout << "\t  == SELECCION DE PERSONAJES ==\n";
		cout << "1. Naruto\n";
		cout << "2. Sasuke\n";
		cout << "3. Kakashi\n";
		cout << "0. Salir\n";
		if (p1 == 0) {
			cout << "Jugador 1" << endl;
		}
		else {
			cout << "Jugador 2" << endl;
		}
		cout << "Seleccione personaje: "; cin >> input;
		if (input == 1 || input == 2 || input == 3) {
			if (p1 != 0) {
				p2 = input;
				pickCharacter(jugador2, p2);
				jugador2->saludo();
				cout << "\n\n";
				system("pause");
				input = 0;
			}
			else {
				if (input == p1) {
					cout << "Ese jugador ya fue seleccionado" << endl;
					cout << "\n\n";
					system("pause");
				}
				else {
					p1 = input;
					pickCharacter(jugador1, p1);
					jugador1->saludo();
					cout << "\n\n";
					system("pause");
				}
			}
		}

	} while (input != 0);
	system("cls");
	if (p1 != 0 && p2 != 0) {
		playGame(jugador1, jugador2);
		///*
		//en estos caso estaria mal hacer esto, dado que estoy con la clase padre Luchador, y necesito elimninar los "new" de la clase especifica que haya seleccionado, Naruto, Sasuke, Kakashi
		//intento 1
		//delete jugador1;
		//delete jugador2;
		//*/

		/*
		//intento 2
		jugador1->~Luchador();
		jugador2->~Luchador();
		*/
	}
	//implemento una funcion para hacer downcast y eliminar correctamente segun la clase que se haya instanciado
	if (p1 != 0) {
		deleteCharacter(jugador1);
	}
	if (p2 != 0) {
		deleteCharacter(jugador2);
	}
}

void pickCharacter(Luchador*& jugador, int characterID)
{
	if (characterID == 1) {
		jugador = new Naruto();
	}
	else if (characterID == 2) {
		jugador = new Sasuke();
	}
	else {
		jugador = new Kakashi();
	}
};

void deleteCharacter(Luchador*&jugador){
	//intento 3
	Kakashi* isKakashi = nullptr;
	Naruto* isNaruto = nullptr;
	Sasuke* isSasuke = nullptr;
	if (isKakashi = dynamic_cast<Kakashi*>(jugador)) {
		//isKakashi->~Kakashi();
		delete isKakashi;
	}
	else if (isNaruto = dynamic_cast<Naruto*>(jugador)) {
		//isNaruto->~Naruto();
		delete isNaruto;
	}
	else if (isSasuke = dynamic_cast<Sasuke*>(jugador)) {
		//isSasuke->~Sasuke();
		delete isSasuke;
	}
}

void getAttacks(Luchador*& jugador)
{
	cout << "1." << jugador->getNombrePoder() << endl;
	cout << "2." << jugador->getNombrePatada() << endl;
	cout << "3." << jugador->getNombreEspecial() << endl;
	cout << "0. Abandonar batalla \n\n";
}

bool useAttacks(Luchador*& atacante, Luchador*& atacado, int opcion) {
	float damage = 0;
	float enemyHp;
	switch (opcion)
	{
	case 1:
		atacante->ejecutarPoder();
		damage = atacante->getDamagePoder();
		break;
	case 2:
		atacante->ejecutarPatada();
		damage = atacante->getDamagePatada();
		break;
	case 3:
		atacante->ejecutarEspecial();
		damage = atacante->getDamageEspecial();
		break;
	}
	enemyHp = atacado->applyDamage(damage);
	if (enemyHp <= 0) {
		cout << atacado->getName() << " ha muerto." << endl;
		cout << atacante->getName() << " ha ganado el combate." << endl;
		return true;
	}
	else {
		cout << atacado->getName() << " tiene " << enemyHp << " puntos de vida." << endl;
	}
	return false;
}

void playGame(Luchador*& jugador1, Luchador*& jugador2)
{
	int input;
	int turn = 0;
	do {
		cout << "\n\t Turno: " << turn + 1 << endl;
		if (turn == 0 || turn % 2 == 0) {
			cout << "=== Jugador 1 - " << jugador1->getName() << " ===" << endl;
			getAttacks(jugador1);
			cin >> input;
			if (input == 1 || input == 2 || input == 3) {
				if (useAttacks(jugador1, jugador2, input)) {
					input = 0;
				}
				else {
					turn++;
				};

			}
		}
		else {
			cout << "Jugador 2 - " << jugador2->getName() << " ===" << endl;
			getAttacks(jugador2);
			cin >> input;
			if (input == 1 || input == 2 || input == 3) {
				if (useAttacks(jugador2, jugador1, input)) {
					input = 0;
				}
				else {
					turn++;
				};
			}
		}
	} while (input != 0);
	cout << "Juego terminado" << endl;
};