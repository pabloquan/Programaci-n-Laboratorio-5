#include <iostream>

using namespace std;

int sumaParImpar(int tope, int opcion);
int factorial(int tope);
int cantDigitos(int num);
void ordenarNumeros(int a, int b, int c);
int sumaDigitos(int num);

void repeticion();

char respuesta;
bool repetir;

int main(){
	do{
		system("cls");
		int opcion;
		cout << "\tMenu:\n\n";
		cout << "1. Suma de pares o impares\n";
		cout << "2. Factorial\n";
		cout << "3. Cantidad de digitos de un numero\n";
		cout << "4. Ordenar numeros de menor a mayor\n";
		cout << "5. Suma de digitos de un numero\n";
		cout << "6. Salir del menu\n\n";
		cout << "Opcion a elegir: ";
		cin >> opcion;
		system("cls");
		switch(opcion){
			 case 1:
			 	int opcionSuma;
				int numUsuario;
			 	cout << "\tSuma de pares o impares\n\n";
			 	cout << "1. Suma de pares\n2. Suma de impares\n\n";
			 	cout << "Opcion a elegir: ";
			 	cin >> opcionSuma;
			 	if (opcionSuma == 1){
			 		system("cls");
			 		cout << "\tSuma de pares: \n";
			 		cout << "Elige el numero hasta donde llegara la suma: ";
			 		cin >> numUsuario;
			 		cout << "\nLa sumatoria de los numeros pares hasta el " << numUsuario << " es de: " << sumaParImpar(numUsuario, opcionSuma) << endl;
				 }
				 else if (opcionSuma == 2){
				 	system("cls");
			 		cout << "\tSuma de impares: \n";
			 		cout << "Elige el numero hasta donde llegara la suma: ";
			 		cin >> numUsuario;
			 		cout << "\nLa sumatoria de los numeros impares hasta el " << numUsuario << " es de: " << sumaParImpar(numUsuario, opcionSuma) << endl;
				 }
				system("pause");
			 	repeticion();
			 	break;
			case 2:
				int numFactorial;
				cout << "\tFactorial\n";
				cout << "Escribe un numero el cual se obtendra el factorial: ";
				cin >> numFactorial;
				cout << "\nEl factorial de " << numFactorial << " es: " << factorial(numFactorial) << endl;
				system("pause");
				repeticion();
				break;
			case 3:
				int numDigitos;
				cout << "\tCantidad de digitos de un numero\n";
				cout << "Escribe un numero: ";
				cin >> numDigitos;
				cout << "\nLa cantidad de digitos de " << numDigitos << " es de: " << cantDigitos(numDigitos) << " digitos"<< endl;
				system("pause");
				repeticion();
				break;
			case 4:
				int num1, num2, num3;
				cout << "\tOrdenar numeros de menor a mayor\n";
				cout << "Escribe 3 numeros: \n\n";
				cout << "Numero 1: ";
				cin >> num1;
				cout << "Numero 2: ";
				cin >> num2;
				cout << "Numero 3: ";
				cin >> num3;
				ordenarNumeros(num1, num2, num3);
				system("pause");
				repeticion();
				break;
			case 5:
				int numDigito;
				cout << "\tSuma de digitos de un numero\n";
				cout << "Escribe un numero: ";
				cin >> numDigito;
				cout << "\nLa suma de los digitos de " << numDigito << " es de: " << sumaDigitos(numDigito) << endl;
				system("pause");
				repeticion();
				break;
			case 6:
				return 0;
			default:
				repetir = true;	
		}	
	} while(repetir == true);
	
	return 0;
}

int sumaParImpar(int tope, int opcion){
	int sumatoria = 0;
	
	if (opcion == 1){
		for (int x = 0; x <= tope; x +=2){
			sumatoria = sumatoria + x;
		}
		return sumatoria;
	}
	
	else if (opcion == 2){
		for (int x = 1; x <= tope; x +=2){
			sumatoria = sumatoria + x;
		}
		return sumatoria;
	}
}

int factorial(int tope){
	int producto = 1;
	for (int x = 1; x <= tope; x++){
		producto = producto * x;
	}
	return producto;
}

int cantDigitos(int num){
	int suma;
	
	/*
	
	Se hace un ciclo el cual cada vez que se realice una division, habra un contador que se ira 
	sumando. Por ejemplo, en el caso de 120, siguiendo el procedimiento del do while, seria:
	
	1er ciclo: 
	120 / 10 = 12
	suma (cantidad de digitos) = 0+1
	
	2do ciclo:
	
	12 / 10 = 1.2 (pero terminaria siendo 1 ya que no se consideran los decimales por ser de tipo int)
	suma (cantidad de digitos) = 1+1
	
	3er ciclo:
	
	1 / 10 = 0.1 (el cual daria como resultado 0) 
	suma (cantidad de digitos = 2+1
	
	4to ciclo: antes de comenzar se evalua si el numero sigue siendo mayor a 0, como ya no lo es
	se termina el ciclo.
	
	*/
	
	suma = 0;
	do{
		num = num / 10;
		suma += 1;
	}while(num > 0);
	return suma;
}





void ordenarNumeros(int a, int b, int c){
	bool cambio;
	/*
	
	El ciclo de do while evalua que cuando el numero de la izquierda es mayor al de la derecha
	realice un cambio, si en dado caso se cumple con al menos una vez con esa condicion, existe
	la certeza de que el ciclo se volvera a ejecutar hasta comprobar que todos los numeros esten
	ordenados correctamente de menor a mayor.
	
	*/
	do{
		cambio = false;
		if (a > b){
			swap(a, b);
			cambio = true;
		}
		if (b > c){
			swap(b, c);
			cambio = true;
		}
	}while(cambio == true);

	cout << "\nEl orden de menor a mayor de los numeros ingresados es: " << a << ", " << b << ", " << c << endl;
}

int sumaDigitos(int num){
	
	/*
	
	Lo que se realiza con el operador de residuo de una division, es que diviendo el numero por 10
	se sabe que el residuo que queda es el digito de la unidad, y ese digito es el que se ira sumando,
	luego el siguiente proceso es dividir por 10 el numero, sabiedno que por ejemplo 1023 / 10, por 
	haber sido declarado como entero y diviendolo por 10, el decimal 102.3 no sera tomado en cuenta
	por lo que de esa forma se elimina el digito que ya no se desea.
	
	*/
	int suma;
	suma = 0;
	do{
		suma += num % 10;
		num = num / 10;
	}while(num > 0);
	
	return suma;
}

void repeticion(){
	do{
		system("cls");
		cout << "Desea realizar otra accion? S/N: ";
		cin >> respuesta;
	} while(respuesta !='n' and respuesta !='N' and respuesta !='S' and respuesta !='s');
		
	if (respuesta == 's' or respuesta == 'S'){
		repetir = true;
	}
	else if (respuesta == 'n' or respuesta == 'N'){
		repetir = false;
	} 
}

