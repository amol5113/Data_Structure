#include <iostream>

using namespace std;

template <typename T>

class Sort{

	public:	

		T* inserationSort(T *array, int size){
			for(int i = 1; i < size; i++){
				int key = array[i];
				int j = i - 1;
				while( j >= 0 && key < array[j] ){
					array[j + 1] = array[j];
					j--;
				} 
				array[j + 1] = key;
				/*
				cout<<i<<" > ";
				for(int k = 0; k < size; k++){
					cout<<array[k]<<" ";
				}
				cout<<endl;
				*/
			}			
		return array;
		}

		T* selectionSort(T *array, int size){

			for(int i = 0; i < size; i++){
				int max = 0;
				for(int j = 0; j < size - i; j++){
					if( array[j] > array[max] ){
						max = j;
					}
				}
				T temp =  array[ max ];
				array[ max ] = array[(size - 1) - i];	
				array[ ( size - 1) - i ] = temp;	
			}
		return array;
		}

		T* bubleSort(T *array, int size){

		}

};

int main(){

	Sort<int> sort;
	int size;
	cin>>size;
	int *array = new int[size];
	

	for(int i = 0; i < size; i++){
		cin>>array[i];
	}

	//int* sorted = sort.inserationSort( array, size );
	int* sorted = sort.selectionSort( array, size );
	for(int i = 0; i < size; i++){
		cout<<sorted[i]<<" ";
	}

	cout<<endl;
	return 0;
}
