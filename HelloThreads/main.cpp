#include <iostream>
#include <vector>
#include <time.h>
#include <thread>

using namespace std;

vector<int> bubbleSort(vector<int>);
void asynchronousSort(vector<vector<int>>);
void synchronousSort(vector<vector<int>>);

int main(int argc, const char * argv[]) {
    int listSize = 0, poolSize = 0;
    int selectMethod;
    
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
    cout << "How do you want to sort the lists? 1)Asynchronously. 2)Synchronously. (1/2): ";
    cin >> selectMethod;
    
    if(selectMethod == 1){
        asynchronousSort(pool);
    }else{
        synchronousSort(pool);
    }
    
    
    
    return 0;
}

void asynchronousSort(vector<vector<int>> pool){
    double executionTime;
    cout << "Sorting..." << endl;
    
    clock_t tStart = clock();
    for(int i = 0; i < pool.size(); i++){
        thread t (bubbleSort, pool[i]);
        t.join();
    }
   
    executionTime = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout << "Time :" << executionTime<< "s." << endl ;
}

void synchronousSort(vector<vector<int>> pool){
    double executionTime;
    cout << "Sorting..." << endl;
    clock_t tStart = clock();
    
    for(int i = 0; i < pool.size(); i++){
        pool[i] = bubbleSort(pool[i]);
    }
    
    executionTime = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout << "Time :" << executionTime<< "s." << endl ;
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
