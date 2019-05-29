#include <graphics.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
int graph(int b[]) {
  int a=1;
    cleardevice();
    int y= getmaxy();
   for(int i=0;i<55;i++){

   bar(a,y-b[i],a+10,y);
    a=a+10;
     }
   return 0;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]); 
		graph(arr) ;
		delay(100);
    }  
}  

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
      /*  	graph(arr) ;
		delay(100);*/
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
        		graph(arr) ;
				delay(30);
            j = j - 1;  
        }  
       arr[j + 1] = key;
		graph(arr);
		delay(30); 
    }  
}  



// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	
   int i, j;
   for (i = 0; i < n-1; i++)
   {

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++){
	   if (arr[j] > arr[j+1])
	      swap(&arr[j], &arr[j+1]);}
	      graph(arr);
	      delay(100);}
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            	graph(arr) ;
		delay(30);
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            	graph(arr) ;
		delay(30);
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        	graph(arr) ;
		delay(30);
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        graph(arr) ;
		delay(30);
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m);
        graph(arr);
        delay(30);
        
        mergeSort(arr, m+1, r); 
        graph(arr);
        delay(30);
        
  
        merge(arr, l, m, r); 
        graph(arr);
        delay(30);
    } 
} 



// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
        graph(arr) ;
		delay(30);
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
        graph(arr);
		delay(30);
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(&arr[0], &arr[i]);
		graph(arr); 
		delay(30);
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
        	graph(arr) ;
		delay(30);
    } 
} 

 int rad(int arr[]){
 
 	for(int z=0;z<55;z++){
    int random = rand()%400;
    arr[z]=random;
    }
    
 	
 }

// Driver program to test above functions
int main()
{
	
	srand(time(0));
	int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    char input;

    int arr[55];
    rad(arr);
   
     settextstyle(8,0,5); 
  outtext("Bubble sort......");
  delay(1000);
    int n = sizeof(arr)/sizeof(arr[0]);
    graph(arr);
    delay(500);
    bubbleSort(arr, n);
    rad(arr);
    
   
    cleardevice();
    outtext("Selection sort......");
    delay(1000);
    graph(arr);
    delay(500);
    selectionSort(arr,n);
    
    rad(arr);

    cleardevice();
    outtext("Insertion sort......");
    delay(1000);
    graph(arr);
    delay(500);
    insertionSort(arr,n);
    
    rad(arr);
    
    
    cleardevice();
    outtext("Merge sort......");
    delay(1000);
    graph(arr);
    delay(500);
    mergeSort(arr, 0, n - 1); 
    
    rad(arr);
    
   
    cleardevice();
    outtext("Heap sort......");
    delay(1000);
    graph(arr);
    delay(500);
    heapSort(arr, n); 
    
    
    cleardevice();
     outtext("THANK YOU......");
	
	 
	getch();
	closegraph();
	return 0;
}
