//
//  bucketsort.h
//  nueva estructura
//
//  Created by Manolo Medina on 2/12/20.
//  Copyright © 2020 Manolo Medina. All rights reserved.
//

#ifndef bucketsort_h
#define bucketsort_h

#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std; 
 
void bucketSort(float arr[], int n) 
{ 
	// se crean los baldes vacíos
	vector<float> buc[n]; 

	// se ponen los elementos de los arrays en baldes
	for (int i = 0; i < n; i++) { 
		int bucketidx = n * arr[i];
		buc[bucketidx].push_back(arr[i]); 
	} 

	// sorting de cada balde
	for (int i = 0; i < n; i++) 
		sort(buc[i].begin(), buc[i].end()); 

	// se unen los baldes a un sólo arreglo
	int idx = 0; 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < buc[i].size(); j++) 
			arr[idx++] = buc[i][j]; 
} 

#endif /* bucketsort_h */
