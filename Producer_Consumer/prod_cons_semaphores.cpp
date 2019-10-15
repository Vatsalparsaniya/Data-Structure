#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

const int ITEMS = 20 , LEN = 5;
int v[LEN]; 
sem_t prod;
sem_t cons;  

int print_array(int v[], int pos)
{
   cout << "Consuming element in pos: " << pos << endl;
   for(int i = 0; i < LEN; i++){
      cout << v[i] << " ";
   }
   cout << endl;
}


void  producer_func(  )
{
   for( int i = 0 ; i < ITEMS ; i++ )
   {
      sem_wait(&prod);
      v[i%LEN] = 1;            //"Producing item"
      sem_post(&cons);
   }
}

void consumer_func(  )
{
   int pos = 0;
   for( int i = 0 ; i < ITEMS ; i++ )
   {
      sem_wait(&cons);
      v[i%LEN] = 0;           //"Consuming item"
      print_array(v, i%LEN);         //Printing array when consuming
      sem_post(&prod);
    }
}

int main()
{
   cout << "Producer Consumer Problem Solved With Sempaphores." << endl;
   sem_init(&prod,0 , LEN);
   sem_init(&cons,0 ,  0);
   thread producer( producer_func ), consumer( consumer_func );

   //Waiting threads to end
   producer.join();
   consumer.join();

   sem_destroy(&prod);
   sem_destroy(&cons);

}
