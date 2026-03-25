#include<iostream>
#include<string>
#include<vector>

// в класса видимость и доступность сквозная(порядок объявления не важен)




class Base {
public:
	int p_val;
	int M01() { return 1; }

	int Prot()const { return prot_val; }
	void Prot(int prot_val) { this->prot_val = prot_val;}

	int Hidden() { return M02() + M03(); }

protected:
	// доступна другим членам класса
	// дружественным функциям и функция
	// и классам-наследника
	int prot_val;
	int M02() { return 2; }
private:
		//доступна другим членам класса
		// дружественным функциям и функция
	int priv_val;
	int M03() { return 3; }
};
// если не указать public автоматически private
class Derived:public Base {};

//			  |public  | protected  | private
// public     |public  | protected  | unreached(закрытый)
// protected  |protected| protected  |unreached(закрытый)
// private    |private | private    |unreached(закрытый)
//		      |
// полиморфизм только в public
//в 99.99999999999999 процентов используеться наследование public
// в приватных и защищенных 
//


// наследование - механизм построения нового класса на основе уже существующегося. Позволяет
//					 переопределять методы родительского класса для обновления функциионала.
//
// Наследование - Механизм расширения функционала существующего
//				  класса путем расширения сужения его специализации.
// 
// использование, зависимость,(использвуем код но не храним)
// агрегация, композиция,(используем чужой код и храним объекты)
// наследование, реализация(код родителя встроен без него не работаем)
// (связи в коде ) 
// 
// GRASP 
// 1 - low coupling(низкая свзяность) - состояние системы в котором счетчик сзвязности меньше критической 
// 2 - high cohesion (высокая зацепление) - наоборот высокий
// 
//
// 
//


class Animal {
public:
	// : делегирование обработки работает до создание класса
	Animal(int age, std::string name)
		:age_(age),
		name_(std::move(name))
	{ }
	int Age()const { return age_; }
	std::string Name()const { return name_; }
	void Name(const std::string &new_name) { name_ = new_name; }
	void Age(int new_age) { age_ = new_age; }

private:
	int age_;
	std::string name_;


};

class Kaban :public Animal {
public:
	Kaban():Animal(1,"Kaban"){}

	void Feed(int kalories) {
		hungry_ += kalories;
	}

private:
	int hungry_;
};
class Weapon {
public:
	virtual void Shoot()const =0;
	// pure virtual
};
class Pistol:public Weapon {
public:
	void Shoot()const {
		std::cout << "Piu!!!\n";
	}
};
class Bazooka:public Weapon {
public:
	void Shoot()const override {
		std::cout << "BAAMMM!!!\n";
	}
};
class Knife :public Weapon {
public:
	void Shoot() const override{
		std::cout << "Swing....\n";
	}
};

void Attak(const Weapon& obj) {
	obj.Shoot();

}



int main(){

	//Weapon weapon;
	//weapon.Shoot();
	Pistol pistol;
	pistol.Shoot();
	Bazooka bazooka;
	bazooka.Shoot();
	Knife knife;
	knife.Shoot();


	std::vector<Weapon*> coll;
	//coll.push_back(&weapon);
	coll.push_back(&pistol);
	coll.push_back(&bazooka);
	coll.push_back(&knife);

	for (auto& el:coll)
	{
		Attak(*el);
	}

	return 0;
}