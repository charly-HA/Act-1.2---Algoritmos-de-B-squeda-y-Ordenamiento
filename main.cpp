// =================================================================
//
// File: main.cpp
// Author: Carlos Hernández Arciniega A01709003
// Date:
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream input;
	ofstream output;

	vector<int> vecuno;
	vector<int> vecdos;
	vector<int> vectres;
	
	if (argc!=3){
		cout<<"Error"<<endl;
		return -1;
	}
	input.open(argv[1]);
	if (!input.is_open()){
		cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
		return -1;
	}
	output.open(argv[2]);
	int arreglo;
	input>>arreglo;
	vecuno.resize(arreglo);
	for(int i = 0; i<arreglo; i++){
		input>>vecuno[i];
	}
	vecdos.assign(vecuno.begin(),vecuno.end());
	vectres.assign(vecuno.begin(),vecuno.end());
	output<<bubbleSort(vecuno)<<" "<<selectionSort(vecdos)<<" "<<insertionSort(vectres)<<"\n"<<"\n";

	int buscar;
	int absorbe;
	input>>buscar;

	for (int i = 0; i<buscar;i++){
		input>>absorbe;
		sequentialSearch(vecuno,absorbe);
		output<<binarySearch(vecuno,absorbe)<<" "<<co1<<" "<<co2<<"\n";
	}
	return 0;
}
