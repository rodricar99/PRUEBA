#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class displayDevice{
	protected:
		bool activate;
		string name;
	public:
		displayDevice(){
			activate = false;
		}
		void update(){
			cout<<"se ha modificado el valor"<<endl;
		}
		virtual void stateObs() = 0;
		string getName(){
			return this->name;
		}
};

class forecast:public displayDevice{
	public:
		forecast():displayDevice(){
			name = "ForeCast";
		}
		void stateObs() override{
			activate = true;
			cout<<"Hello, I am a ForeCast"<<endl;
		}
};

class currentCondition:public displayDevice{
	public:
		currentCondition():displayDevice(){
			name = "currentCondition";
		}
		void stateObs() override{
			activate = true;
			cout<<"Hello, I am a Current Codtition"<<endl;
		}
};

class statistics:public displayDevice{
	public:
		statistics():displayDevice(){
			name = "statistics";
		}
		void stateObs() override{
			activate = true;
			cout<<"Hello, I am Statistics"<<endl;
		}
};

class weatherStation{
	private:
		vector<displayDevice*>* sensors;
	public:
		weatherStation(vector<displayDevice*>* _sensors){
			sensors = _sensors;
		}
		void registerObserver(displayDevice* device){
			sensors->push_back(device);
		}
		void removeObserver(displayDevice* device){
			sensors->erase(std::remove(sensors->begin(),sensors->end(),device),sensors->end());
		}
		void notifyObserver(string sensor_){
			for(int i=0; i<sensors->size(); i++){
				if((*sensors)[i]->getName() == sensor_){
					(*sensors)[i]->update();
				}
			}	
		}
};

int main(){
	vector<displayDevice*>* device = new vector<displayDevice*>();
	device->push_back(new forecast());
	device->push_back(new currentCondition());
	device->push_back(new statistics());
	weatherStation* station = new weatherStation(device);
	station->registerObserver(new forecast());
	station->registerObserver(new currentCondition());
	station->notifyObserver("statistics");
	return 0;
}