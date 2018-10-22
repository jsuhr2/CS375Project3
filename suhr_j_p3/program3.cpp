#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Item{
	public:
		double weight;
		double value;
		double ratio;
		Item();
		Item(double w, double v);
};

Item::Item(){
}

Item::Item(double w, double v){
	weight = w;
	value = v;
	ratio = v/w;
}

class Knapsack{
	public:
		vector<Item> knapsack;
		Knapsack();
		void sortByRatio();
};

Knapsack::Knapsack(){
}

int main(int argc, char** argv){
	
	int numItems = 0;
	int capacity = 0;

	ofstream clear;
	clear.open(argv[2], ofstream::out | ofstream::trunc);
	clear.close();

	ifstream input(argv[1], ios::in);

	ofstream output;
	output.open(argv[2], ios_base::app);
	
	
	
	input.close();
	output.close();
	return 0;
}
