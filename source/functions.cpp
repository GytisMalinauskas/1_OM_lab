#include "../headers/main.h"

void interval_method(int a, int b, double l, double r) {
  int n = 0, m = 0; // n - žingsnių skaičius, m - funkcijų kvietimų skaičius
  cout << "[INFO] Interval limits: [" << l << ", " << r << "]\n";

  double xm, x1, x2, ym, y1, y2;
  double L = r - l, e = 0.0001;

  // Algoritmo vykdymas
  while (L > e) {
      // 1. Randame xm ir jo funkcijos reikšmę
      xm = (l + r) / 2;
      ym = funkcija(xm, a, b);
      m++;

      // 2. Randame x1 ir x2 bei jų funkcijų reikšmes
      x1 = l + L / 4;
      x2 = r - L / 4;
      y1 = funkcija(x1, a, b);
      y2 = funkcija(x2, a, b);
      m += 2;

      // 3. Tikriname, kuris taškas geriausias
      if (y1 < ym) {
          r = xm;
          xm = x1;
          ym = y1;
      } 
      else if (y2 < ym) {
          l = xm;
          xm = x2;
          ym = y2;
      } 
      else {
          l = x1;
          r = x2;
      }

      // 6. Atnaujiname intervalo ilgį
      L = r - l;
      n++;
  }

  // Apskaičiuotas minimumo įvertis
  double xmin = (l + r) / 2;
  double ymin = funkcija(xmin, a, b);
  m++;

  // Rezultatų išvedimas
  cout << "\n[OUTPUT] Rastas minimumo įvertis: x = " << xmin << ", f(x) = " << ymin;
  cout << "\n[OUTPUT] Atliktų žingsnių skaičius: " << n;
  cout << "\n[OUTPUT] Atliktų funkcijos skaičiavimų skaičius: " << m << "\n";
}

void golden_section_method(int a, int b, double l, double r) {
  int n = 0, m = 0; // n - žingsnių skaičius, m - funkcijos kvietimų skaičius
  cout << "[INFO] Interval limits: [" << l << ", " << r << "]\n";

  const double tau = (sqrt(5) - 1) / 2;  // Auksinio pjūvio santykis
  const double epsilon = 0.0001;  // Tikslumo riba

  double L = r - l;
  double x1 = r - tau * L, x2 = l + tau * L;
  double y1 = funkcija(x1, a, b), y2 = funkcija(x2, a, b);
  m += 2;  // Jau atlikti 2 funkcijų skaičiavimai

  while (L > epsilon) {
      if (y2 < y1) {
          // 2. Atmetame [l, x1), perkeliam taškus
          l = x1;
          L = r - l;
          x1 = x2;
          y1 = y2;
          x2 = l + tau * L;
          y2 = funkcija(x2, a, b);
      } else {
          // 3. Atmetame (x2, r], perkeliam taškus
          r = x2;
          L = r - l;
          x2 = x1;
          y2 = y1;
          x1 = r - tau * L;
          y1 = funkcija(x1, a, b);
      }
      m++;  // Naujas funkcijos skaičiavimas
      n++;  // Naujas iteracijos žingsnis
  }

  // Apskaičiuotas minimumo įvertis
  double xmin = (x1 + x2) / 2;
  double ymin = funkcija(xmin, a, b);
  m++;

  // Rezultatų išvedimas
  cout << "\n[OUTPUT] Rastas minimumo įvertis: x = " << xmin << ", f(x) = " << ymin;
  cout << "\n[OUTPUT] Atliktų žingsnių skaičius: " << n;
  cout << "\n[OUTPUT] Atliktų funkcijos skaičiavimų skaičius: " << m<<endl;
}

void newton_method(int a, int b) {
  double x = 5.0; // Initial guess
  double tolerance = 1e-4;
  double step;
  int n = 0, m = 0;
  
  do {
      double f_prime = 4 * x * (x * x - a) / (b - 1); // First derivative f'(x)
      double f_double_prime = (12 * x * x - 4 * a) / (b - 1); // Second derivative f''(x)
      m+=2;
      if (fabs(f_double_prime) < 1e-6) {
          std::cout << "[ERROR] Second derivative is too small, Newton's method may not converge.\n";
          return;
      }
      
      step = f_prime / f_double_prime;
      x -= step;
      n++;
  } while (fabs(step) > tolerance);
  double ymin = funkcija(x, a, b);
  cout << "\n[OUTPUT] Rastas minimumo įvertis: x = " << x << ", f(x) = " << ymin;
  cout << "\n[OUTPUT] Atliktų žingsnių skaičius: " << n;
  cout << "\n[OUTPUT] Atliktų funkcijos skaičiavimų skaičius: " << m<<endl;

}

double funkcija(double x, int a, int b) {
  return (pow((x * x - a), 2) / b) - 1;
}


int getSingleDigitSum(int num) {
  while (num >= 10) {
      int sum = 0;
      while (num > 0) {
          sum += num % 10;
          num /= 10;
      }
      num = sum;
  }
  return num;
}