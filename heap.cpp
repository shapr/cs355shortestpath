#include "heap.h"
#include <iostream>
using namespace std;

BHeap::BHeap(){
               size = 0;
               heapsize = 0;
               array = new int[size];
}
BHeap::BHeap(int arraySize){
                 size = arraySize;
                 heapsize = 0;
                 array = new int[size];
}
int BHeap::parent(int index){
    int i = (index - 1) / 2;
    return i;
}
int BHeap::left(int index){
    int i = 2*index + 1;
    return i;
}
int BHeap::right(int index){
    int i = 2*index + 2;
    return i;
}             
void BHeap::insert(int data){
     int temp;
     int i = heapsize;
     if(heapsize == size)
                 cout<<"Heap is full"<<endl;
     else{
          array[i] = data;
          heapsize++;
          while(i != 0){
                  int prt = parent(i);
                  if(array[prt] > array[i]){
                                   temp = array[prt];
                                   array[prt] = array[i];
                                   array[i] = temp;
                                   i = parent(i);
                  }
                  else
                      i = 0;
          }
     }
}
void BHeap::remove(){
     int temp;
     int i = 0;
     if(heapsize == 0)
                 cout<<"Heap is empty"<<endl;
     else{
          array[i] = array [heapsize - 1];
          heapsize--;
          while(i < heapsize){
                  int l = left(i);
                  int r = right(i);
                  if(l < heapsize){
                       if(array[l] < array[r]){
                              temp = array[i];
                              array[i] = array[l];
                              array[l] = temp;
                              i = left(i);
                       }
                       else{
                              temp = array[i];
                              array[i] = array[r];
                              array[r] = temp;
                              i = right(i);
                       }
                  }
                  else
                      i = heapsize;
          }
     }
}                       
void BHeap::print(){
     for(int i = 0; i < heapsize; i++){
             cout<<array[i]<<"\t";
     }
     cout<<endl;
}   

int main(){
    BHeap HTree(10);
    HTree.insert(2);
    HTree.print();
    HTree.insert(5);
    HTree.print();                  
    HTree.insert(3);
    HTree.print();
    HTree.insert(7);
    HTree.print();
    HTree.insert(1);
    HTree.print();    
    HTree.insert(8);
    HTree.print();    
    HTree.insert(9);
    HTree.print();    
    HTree.insert(4);
    HTree.print();
    HTree.remove();
    HTree.print();  
    HTree.remove();
    HTree.print();  
    HTree.remove();
    HTree.print();
    HTree.remove();
    HTree.print();
    HTree.remove();
    HTree.print();
    HTree.remove();
    HTree.print();
    HTree.remove();
    HTree.print();
    system("pause");
    return 0;
}     
