#include<bits/stdc++.h>
using namespace std;

//Selection Sort 
void selectionSort(int arr[],int n) {
    // Write your code here.
    for(int i=0;i<=n-1;i++)
    {
        int min=i;
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j]<arr[min]) min=j;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << "\n";
}

//Bubble Sort
//first method of Bubble Sort
void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << "\n";
}
//second method of Bubble Sort
void bubble_sort1(int arr[], int n) {
    // bubble sort
    for (int i = 0; i <n-1; i++) {
        for (int j = 0; j < n-i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << "\n";
}

//Insertion Sort
void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << "\n";
}

//Merge Sort
void merge(vector<int>& arr, int l,int mid,int r)
{
    int left=l;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid and right<=r)
    {
        if(arr[left]<arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=r)
    {
        temp.push_back(arr[right]);
        right++;
    } 
// Here the i-l signifies that the temp has its index start from 0 so to make the index to 0 we have to subtract l from i.
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
}
void mergeSort(vector<int>& arr, int l, int r) {
    // Write Your Code Here
    //base case
    if(l>=r)
    {
        return;
    }
    //recursive case
    int mid=(l+(r-l)/2);
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
}
//Recursive Bubble Sort
void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }
}
//Recursive Insertion Sort
void insert(int arr[], int i,int n)
    {
        //code here
        if(i==n) return ;
        int j=i;
        while(j>0 and arr[j-1]>arr[j])
           {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                j--;
            }
        insert(arr,i+1,n);
    }

//Quick Sort
int partitionArray(int arr[], int start, int end) {

  int pivot=arr[start];
  int i=start;
  int j=end;
  while(i<j)
    {
      while(arr[i]<=pivot and i<=end-1)
      {
        i++;
      }
      while(arr[j]>pivot and j>=start+1)
      {
        j--;
      }
      if (i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      }
    }
    int temp = arr[j];
    arr[j] = arr[start];
    arr[start] = temp;
    return j;
}
void quickSort(int input[], int start, int end) {
  if(start<end)
  {
    int pivot=partitionArray(input,start,end);
    quickSort(input,start,pivot-1);
    quickSort(input,pivot+1,end);
  }
}
int main()
{
  int arr[] = {13,46,24,52,20,9};
  vector<int> arr1={13,46,24,52,20,9};
  int m=7;
  int n = sizeof(arr) / sizeof(arr[0]);
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
// selectionSort(arr,n);
// bubble_sort(arr,n);
// bubble_sort1(arr,n);
// insertion_sort(arr,n);
// mergeSort(arr1,0,m-1);
  return 0;
}