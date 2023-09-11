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

//selection sort
void selectionSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int index = i;
		for(int j = i + 1; j < n; j++){
			if(a[index] > a[j]){
				index = j;
			}
		}
		swap(a[i], a[index]); 
	}
}

//bubble sort
void bubbleSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
			}
		}
	}
}

//insertion sort
void insertionSort(int a[], int n){
	for(int i = 1; i < n; i++){
		int x = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > x){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

int main(){
	int a[100], n;
	
	input(a, n);
	cout << endl;
	
	cout << "Selection sort: ";
	selectionSort(a, n);
	output(a, n);
	
	cout << "\nBubble sort: ";
	bubbleSort(a, n);
	output(a, n);
	
	cout << "\nInsertion sort: ";
	insertionSort(a, n);
	output(a, n);
	
	return 0;
}
