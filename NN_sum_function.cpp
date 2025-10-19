#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int f(int x1, int x2)
{
  return x1+x2;
}

int random(int min, int max)
{
  return rand()%(max-min) + min;
}

int main()
{
  //The whole code only has ingle Neuron
srand(time(0));
 /* int tr_data[5][2] = {
{random(0,9),random(0,9)},
{random(0,9),random(0,9)},
{random(0,9),random(0,9)},
{random(0,9),random(1,9)},
{random(0,9),random(1,9)}};
*/
int tr_data[5][2] = {
{2,3},
{4,5},
{5,6},
{1,3},
{5,7}};
  double w1 = 0.2;
  int epo;
  cout << "Enter epo you want:";
  cin >> epo;
  double w2 = 0.3;
  double b = 0.1;
  double lr = 0.0001;
  for (int ep = 0; ep<epo; ep++) {
     for (int t = 0; t<5; t++) {
 cout << "Doing attempt number " << ep << "..." << endl;
      int x1 =  tr_data[t][0];
      int x2 = tr_data[t][1];
      double h = w1*x1 + w2*x2 + b;
      cout << "Current Guess: " << h << endl;
      //Below is the code that train it
      w1 -= 2*(h-f(x1,x2))*x1*lr;
      w2 -= 2*(h-f(x1,x2))*x2*lr;
      b -= 2*(h-f(x1,x2))*lr;
    }
 }
int x1 = random(1,10);
int x2 = random(1,10);
double h = w1*x1 + w2*x2 + b;
cout << "Test Case after training:" <<
endl << " x1: " << x1 << " x2: " << x2
<< " Result: " << round(h*100)/100 << endl << " Correct Answer: " 
<< f(x1,x2) << endl;
return 0;
}
