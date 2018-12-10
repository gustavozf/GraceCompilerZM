#include <iostream>

using namespace std;

int v[10];

void bubblesort(int *v, int n) 
{

int i = 0;

int j;
;

bool trocou = true;
;

while(i < n - 1 && trocou) 
{
trocou = false;

for(j = 0; j < n - i - 1; j += 1) 
{

if(v[j] > v[j + 1]) 
{

int aux = v[j];
;
v[j] = v[j + 1];
v[j + 1] = aux;
trocou = true;

};

}
;
i += 1;

}
;

}
int main() 
{

int i;

int x;
;

cout << "Digite os valores do arranjo:\n";

for(i = 0; i < 10; i += 1) 
{

cout << "A["<< i<< "] = ";

cin >>v[i];

}
;

bubblesort(v, 10);

cout << "Arranjo ordenado:\nA = ";

for(i = 0; i < 10; i += 1) 
{

cout << v[i]<< " ";

}
;

cout << "\n";

return 0;

}