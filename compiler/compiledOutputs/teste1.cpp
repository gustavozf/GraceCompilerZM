#include <iostream>

using namespace std;

void calcDados(int ns, int cp, int am) 
{

cout << "SALA = "<< ns<< "\n";

cout << "CAPACIDADE = "<< cp<< "\n";

cout << "CADEIRAS OCUPADAS = "<< am<< "\n";

if(am >= cp) 
{

cout << "A sala"<< ns<< " está lotada!";

}else 
{

cout << "A sala"<< ns<< " ainda possui vagas!";

}
;

}
int main() 
{

int numSala;

int capacidade;

int alunosMat;
;

int luno;

int capacidad;
;

cout << "Digite o número da sala: ";

cin >>numSala;

cout << "Digite a capacidade da sala: ";

cin >>capacidade;

cout << "Digite a quantidade de alunos matriculados: ";

cin >>alunosMat;

calcDados(numSala, capacidade, alunosMat);

return 0;

}