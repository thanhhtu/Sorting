#include <iostream>
#include<iomanip>
using namespace std;

void input(int a[], int &n){
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	cout << "Enter elements of the array: " << endl;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void output(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

//radix sort 
//function to get the largest element from an array
int getMax(int a[], int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}

//using counting sort to sort the elements in the basis of significant places
void countingSort(int a[], int n, int place){
	const int max = 10;		//from 0 to 9
	int output[n];
	int count[max];
	
	for(int i = 0; i < max; i++){
		count[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		int index = (a[i]/place) % 10;
		count[index]++;
	}
	
	for(int i = 1; i < max; i++){
		count[i] += count[i - 1];
	}
	
	//place elements in sorted order
	for(int i = n - 1; i >= 0; i--){
		int index = (a[i]/place) % 10;
		output[count[index] - 1] = a[i];
		count[index]--;
	}
	
	for(int i = 0; i < n; i++){
		a[i] = output[i];
	}
	
}

void radixSort(int a[], int n){
	int max = getMax(a, n);
	
	for(int place = 1; max/place > 0; place *= 10){
		countingSort(a, n, place);
	}
}

int main(){
	int a[100], n;
	
	input(a, n);
	cout << endl;

	cout << "Radix sort: ";
	radixSort(a, n);
	output(a, n);
	
	return 0;
}
