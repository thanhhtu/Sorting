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

//merge sort 1: tao rieng 2 mang, a[] la mang tong
void merge1(int a[], int left, int mid, int right){
	int n_left = mid - left + 1;
	int n_right = right - mid;
	
	int a_left[n_left];
	int a_right[n_right];
	
	for(int i = 0; i < n_left; i++){
		a_left[i] = a[left + i];
	}
	
	for(int j = 0; j < n_right; j++){
		a_right[j] = a[mid + 1 + j];
	}
	
	int i = 0, j = 0, cnt = left;
	while(i < n_left && j < n_right){
		if(a_left[i] <= a_right[j]){
			a[cnt++] = a_left[i];
			i++;
		}else{
			a[cnt++] = a_right[j];
			j++;
		}
	}
	
	while(i < n_left){
		a[cnt++] = a_left[i++];
	}
	while(j < n_right){
		a[cnt++] = a_right[j++];
	}
}

void mergeSort1(int a[], int left, int right){
	if(left >= right){
		return;
	}
	
	int mid = (left + right)/2;
	
	mergeSort1(a, left, mid);
	mergeSort1(a, mid + 1, right);
	merge1(a, left, mid, right);
}

//merge sort 2: temp[] la mang tong. Sau khi sx, sao chep temp[] vao a[]
void merge2(int a[], int left, int mid, int right){
	int temp[right - left + 1];
	int i = left, j = mid + 1;
	
	for(int cnt = 0; cnt < (right - left + 1); cnt++){
		if(a[i] <= a[j]){
			temp[cnt] = a[i];
			i++;
		}else{
			temp[cnt] = a[j];
			j++;
		}
		
		if(i == mid + 1){
			while(j <= right){
				cnt++;
				temp[cnt] = a[j];
				j++;
			}
			break;
		}
		
		if(j == right + 1){
			while(i <= mid){
				cnt++;
				temp[cnt] = a[i];
				i++;
			}
			break;
		}
	}
	
	//sao chep temp[] vao lai mang a[]
	for(int cnt = 0; cnt < (right - left + 1); cnt++){
		a[left + cnt] = temp[cnt];
	}	
}

void mergeSort2(int a[], int left, int right){
	if(left >= right){
		return;
	}
	
	int mid = (left + right)/2;
	
	mergeSort2(a, left, mid);
	mergeSort2(a, mid + 1, right);
	merge2(a, left, mid, right);
}

int main(){
	int a[100], n;
	
	input(a, n);
	cout << endl;

	cout << "Merge sort 1: ";
	mergeSort1(a, 0, n - 1);
	output(a, n);

	cout << "\nMerge sort 2: ";
	mergeSort2(a, 0, n - 1);
	output(a, n);
	
	return 0;
}
