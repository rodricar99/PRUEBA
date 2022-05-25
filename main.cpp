#include <iostream>
#include <vector>
#include <random>
#include <ctime> 
using namespace std;

class Strategy{
    protected:
        string type;
        int count;
        bool winner = false;
    public:
        Strategy(){}
        ~Strategy(){}
        string getType(){return type;}
        int getCount(){return count;}
        bool getWinner(){return winner;}
        virtual void function(int n) = 0;
};

class Five_Pair: public Strategy{
    public:
        void function(int n) override{
            if(count == 5){
                cout<<"Ganaste";
                winner = true;
            }
            else if(n%2 == 0)
                count++;
        }   
};

class Five_Impair: public Strategy{
    public:
        void function(int n) override{
            if(count == 5){
                cout<<"Ganaste"<<endl;
                winner = true;
            }
            if(n%2 != 0)
                count++;
        }
};

class Is_Prime: public Strategy{
    public:
        void function(int n)override{
            int divisor = 1;
            int divisores = 0;
            do{
                if(n % divisor == 0)
                    divisores++;
            divisor++;
            }while(divisor <= n);
            if(count == 1){
                cout<<"Ganaste"<<endl;
                winner = true;
            }
            else if(divisores == 2)
                count++;
        }
};

class Three_mult10: public Strategy{
    public:
        void function(int n)override{
            if(count == 3){
                cout<<"Ganaste"<<endl;
                winner = true;
            }
            else if(n%10==0)
                count++;
        }
};

class Two_mult25: public Strategy{
    public:
        void function(int n)override{
            if(count == 2){
                cout<<"Ganaste"<<endl;
                winner = true;
            }
            else if(n%25 == 0)
                count++;
        }
};

class Player{
    private:
        string name;
        Strategy* strategy;
    public:
        Player(string name){
            this->name = name;
        }
        string getName(){return name;}
        void displayData(){
            cout<<"Nombre: "<<name<<endl;
            cout<<"Estrategia ganadora: "<<strategy->getType()<<endl;
        }
        void setStrategy(Strategy* strategy){
            this->strategy = strategy;
        }
        Strategy* getStrategy(){return strategy;}
        ~Player(){}
};

class XYZ{
    protected:
        XYZ(){}
        static XYZ* system;
        vector<Player*> players;
    public:
        XYZ(XYZ &other) = delete;
        void operator=(const XYZ &) = delete;
        static XYZ *GetInstance();
        void initial_game(){
            string name = "";
            for(int i=0; i<5; i++){
                int opcion = 0;
                cout<<"Ingrese su nombre : ";
                cin>>name;
                Player* player = new Player(name);  
                cout<<"Ingrese una de las siguientes opciones: "<<endl;
                cout<<"Opcion 1 : Cinco pares"<<endl;
                cout<<"Opcion 2 : Cinco impares"<<endl;
                cout<<"Opcion 3 : Un numero primo"<<endl;
                cout<<"Opcion 4 : Tres numeros multiplos de 10"<<endl;
                cout<<"Opcion 5 : Dos numeros multipos de 25"<<endl;
                cout<<"Ingrese su opcion : ";
                cin>>opcion;
                if(opcion == 1){
                    auto* five_pairs = new Five_Pair();
                    player->setStrategy(five_pairs);
                }else if(opcion == 2){
                    auto* five_impairs = new Five_Impair();
                    player->setStrategy(five_impairs);
                }else if(opcion == 3){
                    auto* is_prime = new Is_Prime();
                    player->setStrategy(is_prime);
                }else if(opcion == 4){
                    auto* three_mult10 = new Three_mult10();
                    player->setStrategy(three_mult10);
                }else if(opcion == 5){
                    auto* two_mult25 =  new Two_mult25();
                    player->setStrategy(two_mult25);
                }
                players.push_back(player);
            }
        }
    void play(){
        srand(time(NULL));
        int i = 0;
        while(true){
            int random = rand()%100;
            players[i]->getStrategy()->function(random);
            if(players[i]->getStrategy()->getWinner()){
                cout<<"Fin del juego, gano el jugador "<<i+1<<endl;
                break;
            }
            if(i<players.size())
                i=0;
            i++;
        }
    }
    ~XYZ(){}
};

XYZ* XYZ::system = nullptr;

XYZ* XYZ::GetInstance(){
    if(system == nullptr)
      system = new XYZ();
    return system;
}

int main(){
    XYZ*control = XYZ::GetInstance();
    control->initial_game();
    control->play();
    delete control;
}