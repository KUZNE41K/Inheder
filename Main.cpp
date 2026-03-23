#include<iostream>
#include<string>

// в класса видимость и доступность сквозна€(пор€док объ€влени€ не важен)




class Base {
public:
	int p_val;
	int M01() { return 1; }

	int Prot()const { return prot_val; }
	void Prot(int prot_val) { this->prot_val = prot_val;}

	int Hidden() { return M02() + M03(); }

protected:
	// доступна другим членам класса
	// дружественным функци€м и функци€
	// и классам-наследника
	int prot_val;
	int M02() { return 2; }
private:
		//доступна другим членам класса
		// дружественным функци€м и функци€
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
//в 99.99999999999999 процентов используетьс€ наследование public
// в приватных и защищенных 
//


int main(){

	Base obj1;
	//obj.M02();
	Derived obj2;
	obj2.M01();

	return 0;
}