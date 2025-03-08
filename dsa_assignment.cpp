#include <iostream>
#include <cstdlib> //for rand()
#include <ctime> // to measure time
#include <chrono> // to measure time
using namespace std;
using namespace chrono; // for high resolution clock

//generating random numbers
void generateRandNum(int arr[], int n){
    srand(time(0)); //random number seed
    for (int i=0; i<n; i++){
        arr[i]= rand() % 1000; //number from 0 to 999
        }
    }
    // displaying the number
    void output(int arr[], int n){
        for(int i= 0; i<n;i++){
            cout << arr[i]<< " ";
        }
        cout << endl;
    }
    //selection sort
    void selectionSort(int arr[], int n){
        for(int i =0; i<n; i++){
            int m =i;
            for (int j=i+1; j<n; j++){
                if(arr[j]< arr[m]){
                    m=j;
                }
            }
            swap(arr[i], arr[m]);
        }
    }
    //merge sort
    void mergeS(int arr[], int l, int c, int r){
        int x =c -l +1;
        int y = r-c;
        int L[x], R[y];
        for (int i=0; i<x;i++) L[i] =arr[l+i];
        for (int i=0; i< y; i++) R[i] = arr[c+1+i];
        int i = 0;
        int j=0;
        int k = l;
        while (i< x && j< y){
            if (L[i]<= R[j] arr[k++] =L[i++];
            else arr[k++] =R[j++]);
        }
        while (i < x) arr[k++] =L[i++];
        while (j<y) arr[k++] = R[j++];
        }
        void mergeS(int arr[], int l, int r){
            if (l< r){
                int c =l+ (r-l) /2;
                mergeS(arr, l c);
                mergeS(arr, c+1, r);
                merge(arr, l, c, r);
            }
        }
        //binary search
        int bSearch(int arr[], int l, int r, int key){
            while (l <= r){
                int c = l +(r -l)/2;
                if (arr[c] == key)return c;
                if (arr[c] < key)l=m+1;
                else r=m -1;
            }
            return -1;
        }
        //interpolaion search
        int iSearch(int arr[], int n, int key){
            int l=0, r= n-1;
            while (l <=r && key >= arr[l] && key <= arr[r]) {
                if (l == r){
                    if(arr[l]==key) return l;
                    return -1;
                }
                int pos = l+ (((double)(r - l)/(arr[r]-arr[l]))*(key -arr[l]));
                if (arr[pos] ==key) return pos;
                if(arr[pos]< key) l=pos+1;
                else r= pos-1;
            }
            return -1;
        }
        int main(){
            int n;
            cout "Enter a number:";
            cin>> n;
            int arr[n], arrCopy[n];
            //generate num and display
            cout << "Random numbers:";
            displayArray(arr,n);
            //sort using selection 
            copy(arr, arr+n, arrCopy);
            auto start = high_resolution_clock::now();
            selectionSort(arrCopy, n);
            auto stop =high_resolution_clock::now();
            auto durationSelection =duration_cast<nanoseconds>(stop -start);
            cout<< "Output from selection sort:";
            displayArray(arrCopy, n);
            cout<<"Time taken:"<< durationSelection.coutn()<< "ns\n";
            //merge sort
            copy(arr, arr +n, arrCopy);
            start =high_resolution_clock::now();
            mergeS(arrCopy, 0,n-1);
            stop =high_resolution_clock::now();
            auto durationMerge =duration_cast<nanoseconds>(stop -start);
            cout <<"Output from merge sort:";
            displayArray(arrCopy, n);
            cout<<"Time taken:"<<durationMerge.count() << "ns\n";
            // ask user for the number to search
            int search;
            cout <<"Enter the number you want to search:";
            cin>> search;
            // perform binary search 
            start =high_resolution_clock::now();
            int bResult =bSearch(arrCopy, 0, n-1, search);
            stop = high_resolution_clock::now();
            auto durationBinary =duration_cast<nanoseconds>(stop-start);
            if(bResult != -1)
            cout<< "Using binary search, "<< searchValue <<"number found at"<< bResult << "index" <<".\n;";
            else 
            cout << "Binary Search number "<<searchValue<<"not found.\n";
            cout <<"Binary Search Time:" <<durationBinary.count() <<"ns\n";
            //interpolation search
            start=high_resolution_clock::now();
            int iResult =iSearch(arrCopy,n,search);
            stop =high_resolution_clock::now();
            auto durationInterpolation =duration_cast<nanoseconds>(stop -start);
            if(iResult !=-1)
            cout "Using interpolation search, "<< searchValue << "number found at"<< iResult << "index"<<".\n";
            else
            cout <<"Interpolation search number" <<search <<"not found.\n";
            cout <<"Interpolation Search time:"<<durationInterpolation.count()<<"ns\n";
            return 0;
        }
