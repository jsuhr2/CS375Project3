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
		vector<Item> items;
		Knapsack();
		void sortByRatio();
};

Knapsack::Knapsack(){
}

int main(int argc, char** argv){
	
	Knapsack sack;
	int numItems = 0;
	int capacity = 0;
	int tempWeight = 0;
	int tempValue = 0;

//clear output file
	ofstream clear;
	clear.open(argv[2], ofstream::out | ofstream::trunc);
	clear.close();

//open files
	ifstream input(argv[1], ios::in);

	ofstream output;
	output.open(argv[2], ios_base::app);
	
	input >> numItems;
	input >> capacity;

	while(true){
		input >> tempWeight;
		if(input.eof())
			break;
		input >> tempValue;
		sack.items.push_back(Item(tempWeight, tempValue));
	}
	
	input.close();
	output.close();
	return 0;
}
