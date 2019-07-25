#include <iostream>
#include <string>

using namespace std;

class Item{
	public:		
		string name;
		double price;
		double weight;
		double GST;

		Item(){
			this->price = 0;
			this->weight = 0;
			this->name = "";
			this->GST = 0;
		}

		Item(string name, double price, double weight, double GST = 0){
			this->name = name;
			this->price = ( price + price*GST/100);
			this->weight = weight;	
		}

		void print(){
			cout<<name<<" "<<weight<<" "<<price<<endl;
		}
};

class Eatable : public Item{

		double GST;
	public:
		Eatable(){}	
		Eatable(string name, double price, double weight): 
			Item(name, price, weight, 5)
		{
		}	

};

class NonEatable : public Item{
	public:
		NonEatable(){}
		NonEatable(string name, double price, double weight):
			Item(name, price, weight)
		{
		}
};

class Electronics : public Item{
	public:
		double GST;
		Electronics(){}
		Electronics(string name, double price, double weight): 
			Item(name, price, weight, 18)
		{
		}
};

class Computer : public Electronics{
	public: 
		Computer( string name, double price, double weight):
			Electronics(name, price, weight)
		{
		}
};

class Shampoo : public NonEatable{
	public:	
		Shampoo(string name, double price, double weight):
			NonEatable( name, price, weight )
		{
		}
};

class Shirt : public NonEatable{
	public:
		Shirt(string name, double price, double weight):
		NonEatable( name, price, weight )
		{
		}

};

class Books : public NonEatable{
	public:	
		Books(string name, double price, double weight):
			NonEatable( name, price, weight )
		{
		}

};

class Biscuit : public Eatable{
	public:
		Biscuit(string name, double price, double weight):
			Eatable( name, price, weight )
		{
		}

};

class DryFruit : public Eatable{
	public:
		DryFruit(string name, double price, double weight):
			Eatable( name, price, weight )
		{
		}

};

class Pulses : public Eatable{
	public:
		Pulses(string name, double price, double weight):
			Eatable( name, price, weight )
		{
		}

}; 

class Cart{

	public:
		int quantity;
		double weight;
		double price;
		int limit;
		bool isEmpty;
		Item** listOfItems;

		Cart(){
		}

		Cart(int limit){
			this->limit = limit;
			listOfItems = new Item* [ limit ]; 
			for(int i = 0; i < limit; i++){
				listOfItems[i] = NULL ;	
			}
			this->weight = 0;
			this->price = 0;
			this->quantity = 0;
			this->isEmpty = 0;
		}

		void addtoCart(Item *item){
			if( quantity < limit){
				for(int i = 0; i < limit; i++){
					if ( listOfItems[i] == NULL){
						listOfItems[i] = item;
						quantity++;
						weight += item->weight;
						price += item->price;
						break;
					}
				}
			}else{
				cout<<"Cart is full"<<endl;
			}
		}

		void removeFromCart(string name){
			if( quantity > 0){
				for(int i = 0; i < limit; i++){
					if (listOfItems[i] != NULL 
				&& listOfItems[i]->name.compare( name ) == 0){
						Item *item = listOfItems[i];
						listOfItems[i] = NULL;
						quantity--;
						weight -= item->weight;
						price -= item->price;
						item = NULL;
						break;
					}
				}
			}else{
				cout<<"Cart is Empty"<<endl;
			}
		}

		void billCart(){
			for(int i = 0; i < limit; i++){
				if( listOfItems[i] != NULL){
					listOfItems[i]->print();
				}
			}
			cout<<"Total Price: "<<price<<endl;
			cout<<"Total Weight: "<<weight<<endl;
			cout<<"Total Quntity: "<<quantity<<endl;
			
			cout<<"Cart Billing Done! "<<endl;
		}
};

class ShoppingMall{

	public:	
		Cart** carts;
		int noofCarts;

		ShoppingMall(int noofCarts){
			this->noofCarts = noofCarts;
			carts = new Cart* [noofCarts];
			for(int i = 0; i < noofCarts; i++){
				carts[i] = new Cart(20);
			}
		}

		Cart* getCart(){
			for(int i = 0; i < noofCarts; i++){
				if( carts[i]->isEmpty == 0 );
				return carts[i];
			}
			return NULL;
		}

		Cart* shoping(){

			Cart *cart = getCart();
			cart->addtoCart( new Shampoo("Dove", 50.0, 50) );
			cart->addtoCart( new Shampoo("Dove", 50.0, 50) );
			cart->addtoCart( new Shampoo("Dove", 50.0, 50) );
			cart->addtoCart( new Shampoo("Dove", 50.0, 50) );
			cart->addtoCart( new Shampoo("Dove", 50.0, 50) );
			cart->addtoCart( new Shampoo("Patnagali", 30.0, 50) );
			cart->addtoCart( new Biscuit("Orio", 60.0, 150) );
			cart->addtoCart( new Biscuit("Orio", 60.0, 150) );
			cart->addtoCart( new Biscuit("Orio", 60.0, 150) );
			cart->addtoCart( new Biscuit("ParleG", 5.0, 50) );
			cart->addtoCart( new Biscuit("ParleG", 5.0, 50) );
			cart->addtoCart( new Biscuit("ParleG", 5.0, 50) );
			cart->addtoCart( new Biscuit("ParleG", 5.0, 50) );
			cart->addtoCart( new Biscuit("ParleG", 5.0, 50) );
			cart->addtoCart( new Computer("Appel", 100000, 200) );
			cart->removeFromCart( "ParleG" );
			cart->removeFromCart( "Orio" );
			cart->addtoCart( new Computer("HP", 80000, 300) );
			//cart->removeFromCart( "Dove" );

		return cart;
		}

		void billing(Cart* cart){
			cart->billCart();
			cout<<"Billing Done!"<<endl;
		}
};

int main(){
	ShoppingMall sm(10);
	Cart *cart = sm.shoping();	
	sm.billing( cart );
	cout<<"Done"<<endl;	
return 0;
}
