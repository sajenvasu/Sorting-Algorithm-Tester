#include <iostream>
#include "Additional_Files/Sort_Functions.h"

static double T_Arr[3];
static std:: string NT_Arr[3] = {"Bubble Sort", "Insertion Sort", "Selection Sort"};


int main(){
    int size = 0;
    std::string choice;
    int loop = 1;
    int print = 0;

    std::cout << "\n\nEnter the number of elements to sort >> ";
    std::cin >> size;
    int Arr[size];

    while(loop == 1){
        std::cout << "Would you like to see the array printed out (Y/N)>> ";
        std::cin >> choice;

        if (choice == "Y" || choice == "y"){
            print = 1;
            loop = 0;
        }else if(choice == "N" || choice == "n"){
            print = 0;
            loop = 0;
        }else{
            std::cout << "Try Again" << std::endl;
        }
    }

    /*
    Bubble Sort
    Insertion Sort
    Selection Sort
    Merge Sort
    Quick Sort
    Heap Sort
    Make an Instructions File
    Add Sleep function 
    */
    
    std::cout << "\nPlease wait" << std::endl;
    //Add Sleep

    Generate_Arr(Arr, print, size);
    Shuffle_Arr(Arr, print, size);
    Bubble_Sort(Arr, print, T_Arr, size);
    Insertion_Sort(Arr, print, T_Arr, size);
    Selection_Sort(Arr, print, T_Arr, size);

    Print_Results(T_Arr, NT_Arr);
    
    std::cout << "\n\nPress the enter key to exit" << std::endl;
    std::cin.ignore();
    std::cin.get();

    return 0;
}