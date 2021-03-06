#include <iostream>
#include <stdlib.h>
#include <time.h>

void Print_Arr(int Arr[], int size, std::string name, int print){

    if (print == 1){  
        std::cout << std::endl;
        std::cout << name << std::endl;
        for (int i = 0; i < size; i++){
            std::cout << "[" <<  Arr[i] << "]";
        }
        std::cout << std::endl;
    }else{

    }
    

}

void Generate_Arr(int Arr[], int print, int size){
    
    for (int i = 0; i < size; i++){
        Arr[i] = i + 1;
    }

    //Print_Arr(Arr, size, "Array:", print);

}

void Shuffle_Arr(int Arr[], int print, int size){

    srand(time(NULL));

    for (int i = 0; i < size; i++){
        int x = rand() % size;
        int temp = Arr[i];
        Arr[i] = Arr[x];
        Arr[x] = temp;
    }

    Print_Arr(Arr, size, "Shuffled Array:", print);

}

void Bubble_Sort(int Arr[], int print, double T_Arr[], int size){
    
    int N_Arr[size];

    for (int i = 0; i < size; i++){
        N_Arr[i] = Arr[i];
    }

    clock_t start = clock();

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(N_Arr[j] > N_Arr[j+1]){
                int te = N_Arr[j];
                N_Arr[j] = N_Arr[j+1];
                N_Arr[j+1] = te;
            }
        }
    }

    clock_t end = clock();

    double time = (double) (end - start) / CLOCKS_PER_SEC;

    Print_Arr(N_Arr, size, "Bubble Sorted Array:", print);
    T_Arr[0] = time;

}

void Insertion_Sort(int Arr[], int print, double T_Arr[], int size){
    
    int N_Arr[size];

    for (int i = 0; i < size; i++){
        N_Arr[i] = Arr[i];
    }

    clock_t start = clock();

    for(int i = 0; i < size; i++){
        int hold = N_Arr[i];
        int count = i - 1;

        while(count >= 0 && N_Arr[count] > hold){
            N_Arr[count + 1] = N_Arr[count];
            count = count - 1;
        }
        N_Arr[count + 1] = hold;
    }    

    clock_t end = clock();

    double time = (double) (end - start) / CLOCKS_PER_SEC;

    Print_Arr(N_Arr, size, "Insertion Sorted Array:", print);
    T_Arr[1] = time;

}

void Selection_Sort(int Arr[], int print, double T_Arr[], int size){
    
    int N_Arr[size];

    for (int i = 0; i < size; i++){
        N_Arr[i] = Arr[i];
    }

    clock_t start = clock();

    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(N_Arr[j] < N_Arr[min]){
                min = j;
            }
        }
        int tp = N_Arr[min];
        N_Arr[min] = N_Arr[i];
        N_Arr[i] = tp;
    } 

    clock_t end = clock();

    double time = (double) (end - start) / CLOCKS_PER_SEC;

    Print_Arr(N_Arr, size, "Selection Sorted Array:", print);
    T_Arr[2] = time;

}


void Print_Results(double T_Arr[], std::string NT_Arr[]){
    
    std::cout << std::endl;
    std::cout << "Final Results" << std::endl;
    std::cout << "-------------" << std::endl;

    for(int i = 0; i < 3; i++){
        std::cout << NT_Arr[i] << ": " << T_Arr[i] << " seconds" << std::endl;
    }
}