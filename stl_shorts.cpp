#include <bits/stdc++.h>
#define ll long long 
#define rep(i,a,b)  for(int i=a; i<b; i++)
#define all(v) (v).begin() ,(v).end()

using namespace std;


int main()
{
   pair<int,string> p;       
   p= make_pair(2,"aditya");                    //PAIRS
   p={1,"aditya"};
   cout<<p.first<<" "<<p.second<<endl;




   pair<int,string> p_array[2];   
   p_array[0]={1,"aditya"};
   p_array[1]={2,"rahul"};                             //ARRAY OF PAIRS
   swap(p_array[0],p_array[1]);
   cout<<p_array[0].second<<p_array[1].second<<endl;




        
   vector<int> v;  
   v.push_back(3);
   v.push_back(-1);                                    //VECTORS
   v.push_back(1);
   v.pop_back();
    cout<<v.size()<<" "<<v[0] <<v[1]<< v[2]<<endl;




   vector<int> nv[3];   
   rep(i,0,3){
      rep(j,0,2){
         int x;
         cin>>x;                               //ARRAY OF VECTORS
         nv[i].push_back(x);
      }
   }
   cout<<nv[1][0];





   int n0;
   cin >> n0;
   vector<vector<int>> vec;
   for(int i=0;i<N;i++){
      int n;
      cin>>n;
      vector<int>temp;
      for(int j=0;j<n;j++){
         int x;                                //VECTORS OF VECTORS
         cin>>x;
         temp.push_back(x);    
      }
      vec.push_back(temp);
   }




   vector<int> v={1,2,-5,6};
   vector<int> ::iterator it;
   for(it=v.begin(); it!=v.end(); it++){
      cout<<*it<<" ";
   }
   cout<<endl;
   for(int x:v){
      cout<<x<<" ";
   }
   cout<<endl;

   vector<pair<int,int>> v_p ={{1,1},{2,4},{3,9},{4,16}};                   //ITERATORS
   vector<pair<int,int>> ::iterator it1;
   for(it1=v_p.begin();it1!=v_p.end();it1++){

      cout<<it1->first<< " "<<it1->second<<endl;
      // cout<<(*it1).first<< " "<<(*it1).second<<endl;
   }

   for(auto x :v_p){
      cout<<x.first<< " "<<x.second<<endl;
   }







   map<int,string> m;  //unordered_map<int,string> m;
   m[3]="aditya";
   m[1]="mani";
   m[4]="rahul";
   m[5]="okie";

   // map<int,string> ::iterator it;
   // for(it=m.begin();it!=m.end();it++){
   //    cout<<it->first <<" "<< it->second;
   //    cout<<endl;
   // }

   m.insert({6,"dokie"});
   m.insert(make_pair(2,"tbd"));                                           //MAP
   
   auto it2=m.find(2);   
   if(it2!=m.end()){
   m.erase(it2);}

   //m.clear();
   cout<<m.size()<<endl;
   //m[5]="tbr";
   
   for(auto &pr: m){
      cout<<pr.first<< " "<< pr.second;
      cout<<endl;
   }


 



   stack<int> st;
   st.push(3);
   st.push(6);
   st.push(-1);                        //STACK
   st.push(0);
   while(!st.empty()){
      cout<< st.top()<<" "<<endl;
      st.pop();
   }



   queue<string> qu;
   qu.push("ab");
   qu.push("1652");
   qu.push(" ");                       //QUEUE
   while(!qu.empty()){
      cout<< qu.front()<< endl;
      qu.pop();
   }

   
     // max-heap->priority_queue<int> q; //10 9 3 1
     
    
     priority_queue<int ,vector<int> , greater<int> > q; //min-heap -> priority_queue
     q.push(3);
     q.push(1);
     q.push(9);
     q.push(10);
     //1 3 9 10
     while(!q.empty()){
         cout<<q.top()<<" ";
         q.pop();
     }
    





   set<string> se;
    se.insert("rahul");
    se.insert("sgbspp");
    se.insert("aditya");
    se.insert("mani");
    se.insert("rahul");                               //SET

    cout<<se.size()<<endl;
    for(string s:se){
        cout<<s<<endl;
    }
    auto it3=se.find("rahul");
    if(it3!=se.end()){
        cout<<*it3;
    }
    se.erase(it3);
    se.insert(*it3);





   int n;
   vector<int> v0(n);
   rep(i,0,n){
        cin>>v0[i];
    }
    sort(all(v0));
     cout<<*lower_bound(all(v0),4)<<endl;
    cout<<*upper_bound(all(v0),4)<<endl;

                                            //auto it= s.lower_bound(3);   in sets
                                            


    cout<<*max_element(all(v0))<<endl;
    cout<<*min_element(all(v0))<<endl;


    cout<<count(all(v0),4)<<endl;

    cout<<accumulate(all(v0),0)<<endl;                //sum with initial value 0
    cout<<*find(all(v0),4)<<endl;                     //find *iterator with 1st occur of 4

    string s="adityainam";
    reverse(all(s));
    cout<<s<<endl;
  

    vector<int> v0={1,2,3,4};
    cout<< [](int y){return y>0;}(4);   //check if passed value(4) is positive
    auto sum=[](int x){return x*x;};
    cout<<sum(3);

    cout<< all_of(all(v0), [](int a){return a>1;})<<endl;

    cout<< any_of(all(v0), [](int a){return a>1;})<<endl;                    //Lambda function

    cout<< none_of(all(v0), [](int a){return a>1;})<<endl;
}