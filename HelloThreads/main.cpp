#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<int> bubbleSort(vector<int>);

int main(int argc, const char * argv[]) {
    int listSize = 0, poolSize = 0;
    double executionTime;
    
    cout << "Enter the number of lists: ";
    cin >> poolSize;
    cout << "Enter the size of the lists: ";
    cin >> listSize;
    
    vector<vector<int>> pool(poolSize);
    
    cout << "Creating " << poolSize << " of " << listSize << " numbers in decrement..." << endl;
    for (int i = 0; i < poolSize; i++) {
        vector<int> temp;
        for(int j = listSize; j > 0; j--){
            temp.push_back(j);
        }
        pool.push_back(temp);
    }
    
    cout << "Successfully created lists." << endl;
    
    clock_t tStart = clock();
    
    for(int i = 0; i < pool.size(); i++){
        pool[i] = bubbleSort(pool[i]);
    }
    
    executionTime = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    
    cout << "Time sorting the lists :" << executionTime << endl << "s.";
    
    return 0;
}

vector<int> bubbleSort(vector<int> numbers){
    int temp;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){
            if(numbers[j] > numbers[j+1]){
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    return numbers;
}
