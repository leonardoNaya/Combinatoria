#include <iostream>
using namespace std;
int Menu(){
	int opcion;
	system("cls");
	cout << "-----------Menu-----------" << endl;
	cout << "1- Variacion sin repeticion" << endl << "2- Variacion con repeticion" << endl << "3- Combinatoria sin repeticion" << endl << "4- Combinatoria con repeticion" << endl << "5- Permutaciones sin repeticion" << endl << "6- Permutaciones con repeticion" << endl << "7- Salir" << endl;
	cin >> opcion;
	return opcion;
}
int SuperIndice(){
	int superIndice;
	system("cls");
	cout << "Ingrese el valor maximo" << endl;
	cin >> superIndice;
	return superIndice;
}
int SubIndice(){
	int subIndice;
	system("cls");
	cout << "Ingrese la cantidad de elementos a escoger:" << endl;
	cin >> subIndice;
	return subIndice;
}
float Factorial(float num){
	for (int i = num - 1; i > 1; i--)
	{
		num *= i;
	}
	return num;
}
int Elevar(int superIndice, int subIndice){
	int total = 1;
    for (int i = 0; i < subIndice; i++) {
        total *= superIndice;
    }
	return total;
}
void VariacionSR(int superIndice, int subIndice){
	int divisor, superIndiceAux, total;
	superIndiceAux = superIndice;
	divisor = (superIndice-subIndice);
	superIndiceAux = Factorial(superIndiceAux);
	divisor = Factorial(divisor);
	total = superIndiceAux/divisor;
	system("cls");
	cout << "El valor total es " << total << endl;
}
void VariacionCR(int superIndice, int subIndice){
    int total = Elevar(superIndice, subIndice);
	system("cls");
    cout << "La cantidad de variaciones con repeticion es: " << total << endl;
}
void CombinatoriaSR(int superIndice, int subIndice){
	int divisor, superIndiceAux, multiplo, total;
	superIndiceAux = superIndice;
	divisor = (superIndice-subIndice);
	multiplo = subIndice;
	superIndiceAux = Factorial(superIndiceAux);
	divisor = Factorial(divisor);
	multiplo = Factorial(multiplo);
	total = superIndiceAux/(divisor*multiplo);
	system("cls");
	cout << "El valor total es " << total << endl;
}
void CombinatoriaCR(int superIndice, int subIndice){
	int divisor, superIndiceAux, multiplo, total;
	superIndiceAux = superIndice + subIndice - 1;
	divisor = subIndice;
	multiplo = superIndice - 1;
	superIndiceAux = Factorial(superIndiceAux);
	divisor = Factorial(divisor);
	multiplo = Factorial(multiplo);
	total = superIndiceAux/(divisor*multiplo);
	system("cls");
	cout << "El valor total es " << total << endl;
}
void PermutacionesSR(){
	int total;
	system("cls");
	cout << "Ingrese la cantidad de elementos:" << endl;
	cin >> total;
	total = Factorial(total);
	system("cls");
	cout << "El valor total es " << total << endl;
}
void PermutacionesCR(int superIndice){
	int elementos, divisor, total, listElementos[5] = {1, 1, 1, 1, 1};
	cout << "Ingrese la cantidad de elementos (maximo 5):" << endl;
	cin >> elementos;
	for (int i = elementos; i > 0; i--)
	{
		cout << "Ingrese el numero del elemento " << i << endl;
		cin >> listElementos[i-1];
	}
	superIndice = Factorial(superIndice);
	for (int i = 4; i >= 0; i--)
	{
		listElementos[i] = Factorial(listElementos[i]);
	}
	divisor = listElementos[0]*listElementos[1]*listElementos[2]*listElementos[3]*listElementos[4];
	total = superIndice/divisor;
	system("cls");
	cout << "El total es " << total << endl;
}
int main() {
	int opcion, superIndice, subIndice;
	opcion = Menu();
	while (opcion!=7)
	{
		switch (opcion)
		{
		case 1:
			superIndice = SuperIndice();
			subIndice = SubIndice();
			VariacionSR(superIndice, subIndice);
			system("pause");
			break;
		case 2:
			superIndice = SuperIndice();
			subIndice = SubIndice();
			VariacionCR(superIndice, subIndice);
			system("pause");
			break;
		case 3:
			superIndice = SuperIndice();
			subIndice = SubIndice();
			CombinatoriaSR(superIndice, subIndice);
			system("pause");
			break;
		case 4:
			superIndice = SuperIndice();
			subIndice = SubIndice();
			CombinatoriaCR(superIndice, subIndice);
			system("pause");
			break;
		case 5:
			PermutacionesSR();
			system("pause");
			break;
		case 6:
			superIndice = SuperIndice();
			PermutacionesCR(superIndice);
			system("pause");
			break;
		case 7:
			break;
		default:
			cout << "No se reconoce el comando";
			system("pause");
			break;
		}
		opcion = Menu();
	}
	return 0;
}
