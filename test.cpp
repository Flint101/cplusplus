#include<iostream>
#include<vector>
using namespace std;


/*template <typename T> void merge(vector<T>& a, int l, int m, int r) {
    
    int n1 = m - l + 1;
    int n2 = r - m;
    //vector<T> temp(a.size());
    vector<T> L(n1);
    vector<T> R(n2);
    //cout << L.size() << " " << R.size() << endl;

    for (int i = 0; i < n1; i++) {
        L.at(i) = a.at(l + i);
        //cout << "L.at(i) = " << L.at(i) << endl;
    }
    for (int j = 0; j < n2; j++) {
        R.at(j) = a.at(m + 1 + j);
        //cout << "R.at(j) = " << R.at(j) << endl;
    }

    int i = 0;
    int j = 0;
    int k = 1;
    
    while(i < n1 && j < n2) {
        if(L.at(i) <= R.at(j)){
            a.at(k++) = L.at(i++);
        }
        else{
            a.at(k++) = R.at(j++);
        }
    }
    while(i < n1){
        a.at(k++) = L.at(i++);
    }
    while(j < n2){
        a.at(k++)  = R.at(j++);
    }
    
    //We need to copy all element to original arrays
    /*for(int i = s; i <= e; i++){
        sorted[i] = temp[i];
    }*/
    
    
//} */

void merge(vector<int> a, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(vector<int>& a, int l, int r){
    
    if (l < r) {
        int m = l + (r - 1) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m+1, r);

        merge(a, l, m, r);

    }

}
    
   
int main(){

    //vector<string> a { "Frits", "Hugo", "Adam", "Catherine", "Joliet", "Xu", "Quirin"};
    vector<int> a { 42, -7, 1001, -16, 2, 0, -17 };
    //vector<double> sorted;
    //sorted.resize(a.size());
	
	mergeSort(a, 0, a.size() - 1);
	
	/*for(int i = 0; i < sorted.size(); i++){
	    cout << sorted[i] <<" ";
	}*/


}