#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

class Item{
	public:
		double weight;
		double value;
		double ratio;
		Item();
		Item(double w, double v);
		double bestSet;
};

Item::Item(){
}

Item::Item(double w, double v){
	weight = w;
	value = v;
	ratio = v/w;
}

class Node{
	public:
		double profit;
		double weight;
		double bound;
		Node();
};

Node::Node(){
}

class Knapsack{
	public:
		vector<Item> items;
		vector<Node> tree;
		Knapsack();
		void sortByRatio(int, int);
		int partition(int, int);
};

Knapsack::Knapsack(){
}

//quicksort algorithm
void Knapsack::sortByRatio(int p, int q){
	int r;
	if(p < q){
		r = partition(p,q);
		sortByRatio(p, r);
		sortByRatio(r + 1, q);
	}
}
//partitioning of quicksort
int Knapsack::partition(int p, int q){
	double x = items[p].ratio;
	int i = p;
	int j;
	for(j = p + 1; j < q; j++){
		if(items[j].ratio >= x){
			i = i + 1;
			swap(items[i], items[j]);
		}
	}
	swap(items[i], items[p]);
	return i;
}

int greedy2(Knapsack sack, int maxCapacity){
	int maxIndividual = 0;
	int maxProfit = 0;
	int capacity = 0;
	sack.sortByRatio(0, sack.items.size());
	for(unsigned int i = 0; i < sack.items.size(); i++){
		if((capacity + sack.items.at(i).weight) <= maxCapacity){
			capacity += sack.items.at(i).weight;
			maxProfit += sack.items.at(i).value;
		}
	}
	for(unsigned int i = 0; i < sack.items.size(); i++){
		if((maxCapacity >= sack.items.at(i).weight) && 
				(maxIndividual < sack.items.at(i).value))
			maxIndividual = sack.items.at(i).value;
	}
	if(maxIndividual > maxProfit)
		maxProfit = maxIndividual;
	return maxProfit;
}

int max(int x, int y){
	if(x > y)
		return x;
	return y;
}

int backtracking(Knapsack sack, int numItems, int maxCapacity){
	
}

/*
int backtracking(Knapsack sack, int numItems, int maxCapacity){
	int K[numItems + 1][maxCapacity + 1];
	for(int i = 0; i <= numItems; i++){
		for(int j = 0; j <= maxCapacity; j++){
			if(i == 0 || j == 0)
				K[i][j] = 0;
			else if(sack.items.at(i - 1).weight <= j)
				K[i][j] = max((sack.items.at(i - 1).value + K[i - 1][j - (int) sack.items.at(i - 1).weight]), K[i - 1][j]);
			else
				K[i][j] = K[i - 1][j];
		}
	}
	return K[numItems][maxCapacity];
}
*/

int main(int argc, char** argv){

	if(argc != 4){
		cout << "Incorrect command line arguments" << endl;
		return 0;
	}

//clear output file
	ofstream clear;
	clear.open(argv[2], ofstream::out | ofstream::trunc);
	clear.close();

//open files
	ifstream input(argv[1], ios::in);

	ofstream output;
	output.open(argv[2], ios_base::app);
	while(true){
		const clock_t BEGIN_TIME = clock();
		Knapsack sack;
		int numItems = 0;
		int itemsConsidered = 0;
		int maxCapacity = 0;
		int capacity = 0;
		int tempWeight = 0;
		int tempValue = 0;
		int maxProfit = 0;
		int decision = atoi(argv[3]);

		input >> numItems;
		input >> maxCapacity;
		if(input.eof())
			break;
		while(itemsConsidered < numItems){
			input >> tempWeight;
			input >> tempValue;
			sack.items.push_back(Item(tempWeight, tempValue));
			itemsConsidered++;
		}
/*	
		for(auto i: sack.items){
			cout << i.ratio << ", ";
		}
		cout << endl;
*/

		if(decision == 0){
			sack.sortByRatio(0, sack.items.size());
			for(unsigned int i = 0; i < sack.items.size(); i++){
				if((capacity + sack.items.at(i).weight) <= maxCapacity){
					capacity += sack.items.at(i).weight;
					maxProfit += sack.items.at(i).value;
				}
			}
		} else if(decision == 1){
			maxProfit = greedy2(sack, maxCapacity);
		} else if(decision == 2){
			sack.sortByRatio(0, sack.items.size());
			maxProfit = backtracking(sack, numItems, maxCapacity);
		}
		
		output << numItems << " " << maxProfit << " " << ((float(clock() - BEGIN_TIME)/CLOCKS_PER_SEC) * 1000) << endl;
	}
	input.close();
	output.close();
	return 0;
}
