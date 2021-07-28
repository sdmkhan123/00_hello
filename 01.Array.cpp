1. // C++ program for reversal algorithm of array rotation

#include <bits/stdc++.h>
using namespace std;
void reverseArray(int arr[], int start, int end)
{
    while (start < end) {
    	//swap(arr[start++], arr[end--]);
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void leftRotate(int arr[], int d, int n)
{
    if (d == 0)
        return;
    d = d % n;
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    leftRotate(arr, d, n);
    printArray(arr, n);
 
    return 0;
}



2. // Search an element in a sorted and rotated array

#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}
int findPivot(int arr[], int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        return low;
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}
int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
    if (arr[pivot] == key)
        return pivot;
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
    return binarySearch(arr, pivot + 1, n - 1, key);
}
int main()
{
    int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;
    cout << "Index of the element is : "
         << pivotedBinarySearch(arr1, n, key);
 
    return 0;
}
.................................................................................
.................................................................................
#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[l] <= arr[mid]) {
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
        return search(arr, mid + 1, h, key);
    }
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);
    return search(arr, l, mid - 1, key);
}
int main()
{
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int i = search(arr, 0, n - 1, key);
    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";
}

03. //Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’. It may be assumed that all elements in the array are distinct.
#include<iostream>
using namespace std;
bool pairInSortedRotated(int arr[], int n, int x)
{
    int i;
    for (i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            break;
    int l = (i+1)%n;
    int r = i;
    while (l != r)
    {
         if (arr[l] + arr[r] == x)
              return true;
         if (arr[l] + arr[r] < x)
              l = (l + 1)%n;
         else
              r = (n + r - 1)%n;
    }
    return false;
}

04. //C++ program to find minimum element in a sorted and rotated array contating duplicate elements.
#include <bits/stdc++.h>
using namespace std;
int findMin(int arr[], int low, int high)
{
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == arr[high])
            high--;
        else if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[high];
}
nt main()
{
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findMin(arr, 0, n);
}

05. //Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possible summation of i*arr[i].
A Simple Solution is to find all rotations one by one, check sum of every rotation and return the maximum sum. Time complexity of this solution is O(n2).
We can solve this problem in O(n) time using an Efficient Solution. 

int maxSum(int arr[], int n)
{
    int arrSum = 0; 
    int currVal = 0;
    for (int i=0; i<n; i++)
    {
        arrSum = arrSum + arr[i];
        currVal = currVal+(i*arr[i]);
    }
    int maxVal = currVal;
    for (int j=1; j<n; j++)
    {
        currVal = currVal + arrSum-n*arr[n-j];
        if (currVal > maxVal)
            maxVal = currVal;
    }
    return maxVal;
}


06. //Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.
Method 1 (Using linear search):
int countRotations(int arr[], int n)
{
    int min = arr[0], min_index;
    for (int i=0; i<n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
........................................................................................
Method 2 (Efficient Using Binary Search):
int countRotations(int arr[], int low, int high)
{
    if (high < low)
        return 0;
    if (high == low)
        return low;
    int mid = low + (high - low)/2; /*(low + high)/2;*/
    if (mid < high && arr[mid+1] < arr[mid])
       return (mid+1);
    if (mid > low && arr[mid] < arr[mid - 1])
       return mid;
    if (arr[high] > arr[mid])
       return countRotations(arr, low, mid-1);
    return countRotations(arr, mid+1, high);
}

07.//A sorted array is rotated at some unknown point, find the minimum element in it.
 
int findMin(int arr[], int low, int high)
{
    if (high < low) return arr[0];
    if (high == low) return arr[low];
    int mid = low + (high - low)/2; /*(low + high)/2;*/
    if (mid < high && arr[mid + 1] < arr[mid])
    return arr[mid + 1];
    if (mid > low && arr[mid] < arr[mid - 1])
    return arr[mid];
    if (arr[high] > arr[mid])
    return findMin(arr, low, mid - 1);
    return findMin(arr, mid + 1, high);
}

,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
How to handle duplicates? 
...........................................................
int findMin(int arr[], int low, int high)
{
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == arr[high])
            high--;
        else if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[high];
}
08. //Given an array a[] of size N, you need to count number of element occurring more than once in the given array.
Input: N = 5, a[] = {2,3,1,2,3}
Output: 2
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int duplicates(int arr[], int n) {
        int count=0;
        int ans[n] = {0};       
        for(int i=0; i<n; i++)
        {
            ans[arr[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            if(ans[i]>1)
                count++;
        }
        cout<<count<<endl;
        return {count};
    }
};
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        cout<<obj.duplicates(a, n);
    }
    return 0;
}
...............................................................
...............................................................
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int duplicates(int numRay[], int n) {
	int count =0;
	for (int i = 0; i < n; i++) {
		numRay[numRay[i] % n] = numRay[numRay[i] % n] + n;
	}
	for (int i = 0; i < n; i++) {
		if (numRay[i] >= n * 2) {
		    count++;
		}
	}
	return count;
    }
};
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        cout<<obj.duplicates(a, n);
    }
    return 0;
}
..........................................................................
..........................................................................
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int duplicates(int arr[], int n)
    {
        int count=0;
        unordered_map<int,int> hm;
        for(int i=0;i<n;i++)
        hm[arr[i]]++;
        unordered_map<int,int> :: iterator it;
        for(it=hm.begin();it!=hm.end();++it)
        {
            if(it->second>1)
            count++;
        }
        return count;
    }
};
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        cout<<obj.duplicates(a, n);
    }
    return 0;
}

09.//Given an array of n elements, create a new array which is a rotation of given array and hamming distance between both the arrays is maximum. 
Hamming distance between two arrays or strings of equal length is the number of positions at which the corresponding character(elements) are different.

int maxHamming(int arr[], int n)
{
    int brr[2 *n + 1];
    for (int i = 0; i < n; i++)
        brr[i] = arr[i];
    for (int i = 0; i < n; i++)
        brr[n+i] = arr[i];
    int maxHam = 0;
    for (int i = 1; i < n; i++)
    {
        int currHam = 0;
        for (int j = i, k=0; j < (i + n); j++,k++)
            if (brr[j] != arr[k])
                 currHam++;
        if (currHam == n)
            return n;
        maxHam = max(maxHam, currHam);
    } 
    return maxHam;
}


10.//Given an array of elements of length N, ranging from 0 to N – 1. All elements may not be present in the array. If the element is not present then there will be -1 present in the array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

void fixArray(int ar[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (ar[j] == i) {
                temp = ar[j];
                ar[j] = ar[i];
                ar[i] = temp;
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (ar[i] != i)
        {
            ar[i] = -1;
        }
    }
    for (i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
}

....................................................................
Another Approach (Swap elements in Array) : Time Complexity: O(n)
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

void fixArray(int arr[], int n)
{
    for (int i = 0; i < n;)
    {
        if (arr[i] >= 0 && arr[i] != i)
            arr[arr[i]] = (arr[arr[i]] + arr[i]) - (arr[i] = arr[arr[i]]);
        else
            i++;
    }
}

............................................................................................................
Another Approach (Using HashSet) : 
1) Store all the numbers present in the array into a HashSet 
2) Iterate through the length of the array, if the corresponding position element is present in the HashSet, 
then set A[i] = i, else A[i] = -1
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
 
 
11.//Write a program to reverse an array or string
void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
........................................
Recurssive Approch
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

void rvereseArray(int arr[], int start, int end)
{
    if (start >= end)
    return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    rvereseArray(arr, start + 1, end - 1);
}

12.//Given an array of n elements. Our task is to write a program to rearrange the array such that elements at even positions are greater than all elements before it and elements at odd positions are less than all elements before it.
Time Complexity: O(n * log n)
Auxiliary Space: O(n)

void assign(int a[], int n)
{
    sort(a, a + n);
    int ans[n];
    int p = 0, q = n - 1;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)
            ans[i] = a[q--];
        else
            ans[i] = a[p++];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
..............................................................................................
Method 2 – One other approach is to traverse the array from the second element and
swap the element with the previous one if the condition is not satisfied.
Time Complexity: O(n)
Auxiliary Space: O(1)
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
void rearrange(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[i] > arr[i - 1])
                swap(&arr[i - 1], &arr[i]);
        }
        else {
            if (arr[i] < arr[i - 1])
                swap(&arr[i - 1], &arr[i]);
        }
    }
}

13.//An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array

int* rearrange(int *a, int n){
    sort(a, a+n);
    int i=1, j=1;
    while(j<n){
        if(a[j]>0)
            break;
        j +=1;
    }
    while(a[i] < 0 && j<n){
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        i += 2;
        i += 1;
    }
    return a;
}


14.// Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same.

void pushZerosToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i]; 
    while (count < n)
        arr[count++] = 0;
}
....................................................
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
void moveZerosToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            swap(arr[count++], arr[i]);
}
15. //Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.
....................................................................................................................
A simple solution is to first count all elements less than or equals to k(say ‘good’). Now traverse for every sub-array and swap those elements whose value is greater than k. Time complexity of this approach is O(n^2)
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

Time complexity: O(n)
Auxiliary space: O(1)

#include <iostream>
using namespace std;
int minSwap(int *arr, int n, int k) {
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] <= k)
			++count;
	int bad = 0;
	for (int i = 0; i < count; ++i)
		if (arr[i] > k)
			++bad;
	int ans = bad;
	for (int i = 0, j = count; j < n; ++i, ++j) {
		if (arr[i] > k)
			--bad;
		if (arr[j] > k)
			++bad;
		ans = min(ans, bad);
	}
	return ans;
}
int main() {
	
	int arr[] = {2, 1, 5, 6, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << minSwap(arr, n, k) << "\n";
	
	int arr1[] = {2, 7, 9, 5, 8, 7, 4};
	n = sizeof(arr1) / sizeof(arr1[0]);
	k = 5;
	cout << minSwap(arr1, n, k);
	return 0;
}

16.//Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive integers in the array

void RearrangePosNeg(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        if (key > 0)
            continue;
        j = i - 1;
        while (j >= 0 && arr[j] > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
.....................................................................................

void RearrangePosNeg(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (true) {
        while (i < n && arr[i] < 0)
            i++;
        while (j >= 0 && arr[j] > 0)
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
            break;
    }
}

17.//Rearrange array such that even positioned are greater than odd

void assign(int a[], int n)
{
    sort(a, a + n);
    int ans[n];
    int p = 0, q = n - 1;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)
            ans[i] = a[q--];
        else
            ans[i] = a[p++];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

....................................................................
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void rearrange(int arr[], int n)
{
    for (int i = 1; i < n; i +=2) {
        if(arr[i]<arr[i-1]){
	        swap(&arr[i - 1], &arr[i]);
        }
        if(arr[i]<arr[i+1]){
            swap(&arr[i + 1], &arr[i]);
        }
	}
}
int main()
{
	int n = 5;
	int arr[] = { 1, 3, 2, 2, 5 };
	rearrange(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}


18.//Rearrange an array in order – smallest, largest, 2nd smallest, 2nd largest
.............................................................................................
A simple solution is to first find the smallest element, swap it with first element.
Then find largest element, swap it with second element and so on. Time complexity of 
this solution is O(n2).
.............................................................................................

........................................................................................................................
An efficient solution is to use sorting. 
1. Sort the elements of array. 
2. Take two variables say i and j and point them to the first and last index of the array respectively. 
3. Now run a loop and store the elements in the array one by one by incrementing i and decrementing j.

Time Complexity : O(n Log n) 
Auxiliary Space : O(n)
........................................................................................................................

void rearrangeArray(int arr[], int n)
{
    sort(arr, arr + n);
    int tempArr[n]; 
    int ArrIndex = 0;
    for (int i = 0, j = n-1; i <= n / 2 ||
                    j > n / 2; i++, j--) {
        tempArr[ArrIndex] = arr[i];
        ArrIndex++;
        tempArr[ArrIndex] = arr[j];
        ArrIndex++;
    }
    for (int i = 0; i < n; i++)
        arr[i] = tempArr[i];
}



19.//For a given array of n integers and assume that ‘0’ is an invalid number and all others as a valid number. Convert the array in such a way that if both current and next element is valid then double current value and replace the next number with 0. After the modification, rearrange the array such that all 0’s shifted to the end.
Input : arr[] = {2, 2, 0, 4, 0, 8}
Output : 4 4 8 0 0 0

void pushZerosToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i];
    while (count < n)
        arr[count++] = 0;
}
void modifyAndRearrangeArr(int arr[], int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] != 0) && (arr[i] == arr[i + 1])) {
            arr[i] = 2 * arr[i];
            arr[i + 1] = 0;
            i++;
        }
    }
    pushZerosToEnd(arr, n);
}


20.//Given two integer arrays of same size, “arr[]” and “index[]”, reorder elements in “arr[]” according to given index array. It is not allowed to given array arr’s length.
Input:  arr[]   = [50, 40, 70, 60, 90]
        index[] = [3,  0,  4,  1,  2]
Output: arr[]   = [40, 60, 90, 50, 70]
        index[] = [0,  1,  2,  3,   4]
        
...............................................................................................
A Simple Solution is to use an auxiliary array: Time complexity O(n) and auxiliary space O(n)
...............................................................................................
void reorder(int arr[], int index[], int n)
{
    int temp[n];
    for (int i=0; i<n; i++)
        temp[index[i]] = arr[i];
    for (int i=0; i<n; i++)
    {
       arr[i]   = temp[i];
       index[i] = i;
    }
}

..............................................................
We can solve it Without Auxiliary Array
..............................................................
void reorder(int arr[], int index[], int n)
{
    for (int i=0; i<n; i++)
    {
        while (index[i] != i)
        {
            int  oldTargetI  = index[index[i]];
            char oldTargetE  = arr[index[i]];
            arr[index[i]] = arr[i];
            index[index[i]] = index[i];
            index[i] = oldTargetI;
            arr[i]   = oldTargetE;
        }
    }
}

21.//An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. Number of positive and negative numbers need not be equal.
input [-1, 2, -3, 4, 5, 6, -7, 8, 9]
output[9, -7, 8, -3, 5, -1, 2, 4, 6]

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void rearrange(int arr[], int n)
{
	int i = -1;
	for (int j = 0; j < n; j++)
	{
		if (arr[j] < 0)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	int pos = i + 1, neg = 0;
	while (pos < n && neg < pos &&
					arr[neg] < 0)
	{
		swap(&arr[neg], &arr[pos]);
		pos++;
		neg += 2;
	}
}












