#include<iostream>
using namespace std;
int Menu(){
	float opcion;
	system("cls");
	cout << "------Menu------" << endl;
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
float Factorizar(float num){
	for (int i = num - 1; i > 1; i--)
	{
		num *= i;
	}
	return num;
}
void VariacionSR(int superIndice, int subIndice){
	float divisor, superIndiceAux, total;
	superIndiceAux = superIndice;
	divisor = (superIndice-subIndice);
	for (int i = superIndice - 1;i >= 1; i--) {
		superIndiceAux = superIndiceAux * i;
	}
	for (int i = divisor - 1; i >= 1; i--) {
		divisor = divisor * i;
	}
	total = superIndiceAux/divisor;
	system("cls");
	cout << "El valor total es " << total << endl;
}
void VariacionCR(int superIndice, int subIndice){
    float total = 1;
    for (int i = 0; i < subIndice; i++) {
        total = total * superIndice;
    }
	system("cls");
    cout << "La cantidad de variaciones con repeticion es: " << total << endl;
}
void CombinatoriaSR(int superIndice, int subIndice){
	float divisor, superIndiceAux, multiplo, total;
	superIndiceAux = superIndice;
	divisor = (superIndice-subIndice);
	multiplo = subIndice;
	superIndiceAux = Factorizar(superIndiceAux);
	divisor = Factorizar(divisor);
	multiplo = Factorizar(multiplo);
	total = superIndiceAux/(divisor*multiplo);
	system("cls");
	cout << "El valor total es " << total << endl;
}
void CombinatoriaCR(int superIndice, int subIndice){
	float divisor, superIndiceAux, multiplo, total;
	superIndiceAux = superIndice + subIndice - 1;
	divisor = subIndice;
	multiplo = superIndice - 1;
	superIndiceAux = Factorizar(superIndiceAux);
	divisor = Factorizar(divisor);
	multiplo = Factorizar(multiplo);
	total = superIndiceAux/(divisor*multiplo);
	system("cls");
	cout << "El valor total es " << total << endl;
}
void PermutacionesSR(){
	float total;
	system("cls");
	cout << "Ingrese la cantidad de elementos:" << endl;
	cin >> total;
	total = Factorizar(total);
	system("cls");
	cout << "El valor total es " << total << endl;
}
void PermutacionesCR(int superIndice){
	float elementos, divisor, total, listElementos[5] = {1, 1, 1, 1, 1};
	cout << "Ingrese la cantidad de elementos (maximo 5):" << endl;
	cin >> elementos;
	for (int i = elementos; i > 0; i--)
	{
		cout << "Ingrese el numero del elemento " << i << endl;
		cin >> listElementos[i-1];
	}
	superIndice = Factorizar(superIndice);
	for (int i = 4; i >= 0; i--)
	{
		listElementos[i] = Factorizar(listElementos[i]);
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
			break;
		}
		opcion = Menu();
	}
	return 0;
}