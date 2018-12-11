#include <iostream>

using namespace std;

int somaUm(int i) 
{

return i + 1;

}
int quadrado(int i) 
{

return i * i;

}
int sum(int *v, int tam) 
{

int soma = 0;

int i;
;

for(i = 0; i < tam; i += 1) soma += v[i]
;

return soma;

}
int potencia(int x, int n) 
{

int i;

int total;
;

if(n < 1) 
{

return -1;

};
total = x;

for(i = 1; i < n; i += 1) 
{
total *= x;

}
;

return total;

}
int fibonacci(int x) 
{

int soma = 1;

int anterior = 1;

int i;

int temp;
;

if(x <= 1) 
{

return x;

};

for(i = 2; i < x; i += 1) 
{
temp = soma;
soma += anterior;
anterior = temp;

}
;

return soma;

}
int fatorial(int x) 
{

int fat = 1;
;

while(x > 1) 
{
fat *= x;
x -= 1;

}
;

return fat;

}
bool checkNumPrimo(int x) 
{

int i;
;

bool primo = true;
;

if(x <= 1) 
{

cout << "O número não é primo!\n";

return false;

};

for(i = 2; i <= x / 2; i += 1) 
{

if(x % i == 0) 
{
primo = false;

break;

};

}
;

if(primo) 
{

cout << "O número '"<< x<< "' é primo!\n";

}else 
{

cout << "O número '"<< x<< "' não é primo!\n";

}
;

return primo;

}
int main() 
{

bool retorno[3];
;

int num;
;

int tam = 10;
;

int val[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
;
num = 7;
retorno[0] = checkNumPrimo(13);
retorno[1] = checkNumPrimo(num);
retorno[2] = checkNumPrimo(34);

cout << "27 + 1 = "<< somaUm(27)<< "\n";

cout << "3^2 = "<< quadrado(3)<< "\n";

cout << "3^4 = "<< potencia(3, 4)<< "\n";

cout << "Fibonacci(7) = "<< fibonacci(num)<< "\n";

cout << "Fibonacci(9) = "<< fibonacci(9)<< "\n";

cout << "Fatorial(4) = "<< fatorial(4)<< "\n";

cout << "Fatorial(6) = "<< fatorial(6)<< "\n";

cout << "Soma de um vetor de 10 valores '5' = "<< sum(val, tam)<< "\n";

return 0;

}