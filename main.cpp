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
        Strategy(){};
        virtual ~Strategy(){}
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
        virtual ~Five_Pair();     
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
    virtual ~Five_Impair();
};

class ES_primo: public Strategy{
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
    virtual ~ES_primo();
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
    virtual ~Three_mult10();
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
    virtual ~Two_mult25();
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
        virtual ~Player(){}
};

class empresa_xyz{
    protected:
        empresa_xyz(){}
        static empresa_xyz* system;
        vector<Player*> players;
    public:
        empresa_xyz(empresa_xyz &other) = delete;
        void operator=(const empresa_xyz &) = delete;
        static empresa_xyz *GetInstance();
        void initial_game(){
            string name = "";
            for(int i=0; i<5; i++){
                int opcion = 0;
                cout<<"Ingrese su nombre : ";
                cin>>name;
                Player* player = new Player(name);  
                cout<<"Ingrese una de las siguientes opciones: "<<endl;
                cout<<"1: Cinco pares"<<endl;
                cout<<"2: Cinco impares"<<endl;
                cout<<"3: Un numero primo"<<endl;
                cout<<"4: Tres numeros multiplos de 10"<<endl;
                cout<<"5 : Dos numeros multipos de 25"<<endl;
                cout<<"Ingrese su opcion : ";
                cin>>opcion;
                if(opcion == 1){
                    auto* five_pairs = new Five_Pair();
                    player->setStrategy(five_pairs);
                }else if(opcion == 2){
                    auto* five_impairs = new Five_Impair();
                    player->setStrategy(five_impairs);
                }else if(opcion == 3){
                    auto* is_prime = new ES_primo();
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
                uint8_t random_chars[10];
            int random = rand()%99;
            players[i]->getStrategy()->function(random);
            if(players[i]->getStrategy()->getWinner()){
                cout<<"Fin, gano el jugador "<<i+1<<endl;
                break;
            }
            if(i<players.size())
                i=0;
            i++;
        }
    }
    ~empresa_xyz(){}
};

empresa_xyz* empresa_xyz::system = nullptr;

empresa_xyz* empresa_xyz::GetInstance(){
    if(system == nullptr)
      system = new empresa_xyz();
    return system;
}

int main(){
    empresa_xyz*control = empresa_xyz::GetInstance();
    control->initial_game();
    control->play();
    delete control;
}