#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << "\n";
}

void siftDown(std::vector<int>& arr, int v, int n){
	
	while(2*v<=n){
		int u = 2 * v;
		if( 2 * v + 1 <= n && arr[2*v+1] < arr[2*v]){
			u = 2*v+1;
		}
		if(arr[u] < arr[v]){
			std::swap(arr[u],arr[v]);
			v = u;
		}
		else{
		    break;
		}	
	}
}

void Build(std::vector<int>& arr) {
    int n = arr.size()-1;
    for (int i = n; i >= 1; i--){
        siftDown(arr, i, n);
    }
}

void HeapSort(std::vector<int>& arr){
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = -arr[i];
    }
    
    Build(arr); // куча корректна
    int n = arr.size()-1;
    
    
    for (int i = n; i > 0; i--) {
        std::swap(arr[1], arr[i]);
        siftDown(arr, 1, i-1);

    }
    
    for (int i = 1; i <= n; i++) {
        arr[i] = -arr[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cout<<arr[i] << " ";
    }
}


int main() {
    std::vector<int> arr = {0,4,3,2,-2,-3,0,1, 100,5, 3,-6,2,3,1};
    HeapSort(arr);

}
