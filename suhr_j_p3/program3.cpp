#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Node{
	public:
		Item item;
		Node* left;
		Node* right;
		Node* parent;
		Node();
};

Node::Node(){
}

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
/*	
	for(auto i: sack.items){
		cout << i.ratio << ", ";
	}
	cout << endl;
*/	
	sack.sortByRatio(0, sack.items.size());
/*	
	for(auto i: sack.items){
		cout << i.ratio << ", ";
	}
	cout << endl;
*/
	if(arv[3] == 0){
		
	} else if(argv[3] == 1){
		
	} else if(argv[3] == 2){
		
	}

	input.close();
	output.close();
	return 0;
}
