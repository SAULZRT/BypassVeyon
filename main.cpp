#include <iostream>
#include <Windows.h>
#include "bypass.h"
#include <cstdlib> 
//Made by saul -_-
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int main() {
	
	std::cout << "Made by saul" << std::endl;
	SetConsoleTextAttribute(h, 10);   // verde
	std::cout << "<Apoyame en mi github -_- >https://github.com/SAULZRT?tab=repositories"<<std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	std::cout << "Pulse enter para comenzar con el bypass a veyon : " << std::endl;
	std::cout << ">";
	while (true)
	{
		//SOLO ESCUCHA LA TECLA ENTER
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {

			int confirmacion = MessageBoxA(
				NULL,
				"CONFIRMACION",
				"CONTINUAR BYPASS",
				MB_OKCANCEL | MB_ICONEXCLAMATION
			);
			if (confirmacion == IDCANCEL) 
			{
				exit(0);
			}
			//Llamamos a nuestra funcion
			bypass();
		}

	}
		
	

}