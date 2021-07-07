/*

Hash Table:
A Hash table is basically a data structure that is used to store the key value pair. 
In C++, a hash table uses the hash function to compute the index in an array at which the value needs 
to be stored or searched. 
This process of computing the index is called hashing. 
Values in a hash table are not stored in the sorted order and there are huge chances of collisions in the hash table which is 
generally solved by the chaining process (creation of a linked list having all the values and the keys associated with it

*/


#include<bits/stdc++.h>
using namespace std;
class Hash
{
  private:
    int BUCKET;                 //no. of buckets in the hash table
    std::list<int> *table;      //pointer to an array containing buckets
  
  public:
    Hash(int element);    //Constructor
    
    // inserts a key into Hashtable
    void insertItem(int key);
    
    // hash function to map values to key
    int hashFunction(int value)
    {
      return (value%BUCKET);
    }

    // searches for an item in the Hash table
    bool searchItem(int item);
    
    // displays the Hash table
    void displayHashTable();
};

Hash::Hash(int buckets)
{
  this->BUCKET = buckets;
  table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
  int index = hashFunction(key);
  table[index].push_back(key);
}

bool Hash::searchItem(int item) {
  int index = hashFunction(item);
  for(auto i : table[index]){
    if(item == i)
      return true;
  }
}

void Hash::displayHashTable()
{
  for(int i=0;i<BUCKET;i++)
  {
    cout<<i;
    for(auto j:table[i])
        cout<<" --> "<<j;
    cout<<endl;
  }
}

int main()
{

  vector<int> v = {24,56,7,8,1,2,3};
  int n = v.size();
  int item = 0;

  //inserts the keys into hash table 
  Hash h(5);
  
  for(int i=0;i<n;i++)
      h.insertItem(v[i]);

  // display HashTable
  cout<<endl<<"Hash Table is: "<<endl;
  h.displayHashTable();

  cout<<endl<<"Enter an integer to search ";
  cin>>item;
  
  // searching an item in hash table
  if(h.searchItem(item))
    cout<<"Integer found";
  else
  cout<<"Integer not found";
   
  return 0;
}


