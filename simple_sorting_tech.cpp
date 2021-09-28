#include <bits/stdc++.h>
using namespace std; 

int main()
{
  int N; cin >> N;
  vector<int> A(N);
  for(int &i: A)cin >> i;
  

  // Selection sort - check if ith ele has smaller ele in its suffix (right side of it) and swap them
                      // the goal is to shift the ith smallest ele to (i - 1)th pos in 0 based array


  for(int i = 0; i < N; i++){
    int mi = i;
      for(int j = i + 1; j < N; j++)
              if(A[j] < A[mi])
                      mi = j;
                    
    if(mi > i)
          swap(A[i], A[mi]);

  }




  //Bubble sort - Compare each adjacent eles and swap them so as to shift one by one the ith greatest ele to the right
                  // greatest ele sort of bubbles out to the top
  for(int i = 0; i < N - 1; i++){
    bool sorted = true;
        for(int j = 0; j < N - i - 1; j++){
              if(A[j] > A[j + 1]){
                            swap(A[j], A[j + 1]);
                            sorted = false;
                          }
                    }
    if(sorted)break;

  }


  for(auto &i :A)cout << i << " ";cout << '\n';
}




