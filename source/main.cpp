#include "../headers/main.h"

int main ()
{
  int ch;
  double l = 0, r = 10;
  cout<<"\n[INFO] Starting the program...\n";
  cout<<"[OPTIONS] Choose the algorithm:\n"<<
        "[1] Intervalo dalijimo pusiau metodas\n"<<
        "[2] Auksinio pjūvio algoritmas\n"<<
        "[3] Niutono metodas\n"<<
        "[INPUT] Type number: ";
  cin>>ch;
  cout << "\n[INPUT] Type students ID number: ";
  long long id;
  cin >> id;
  int a = (id / 10) % 10; // Priešpaskutinis skaitmuo
  int b = id % 10; // Paskutinis skaitmuo  
  if (b == 0) 
  {
    int suma = 0;
    long long temp = id;
    while (temp > 0) 
    {
      suma += temp % 10;
      temp /= 10;
    }
    b = getSingleDigitSum(suma);
  }
  cout << "[INFO] a = " << a <<"\n";
  cout << "[INFO] b = " << b <<"\n";
  switch (ch)
  {
    case 1:
    interval_method(a, b, l, r);
    break;
    case 2:
    golden_section_method(a, b, l, r);
    break;
    case 3:
    newton_method(a, b);
    break;
  }
  return 0;
}