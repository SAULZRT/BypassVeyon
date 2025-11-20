#include <Windows.h>
#include <iostream>

HANDLE I = GetStdHandle(STD_OUTPUT_HANDLE);

void bypass(){
	//Modo usuario(No admin)
	//Captaremos la Imagen del proceso veyon-worker.exe para terminarlo en bucle , asi evitaremos su regeneracion , esto no requiere usuario de admin
	system("taskkill -f -IM veyon-worker.exe");
	
	system(
		"start /min powershell -WindowStyle Hidden -Command \""
		"$l1 = New-Object System.Net.Sockets.TcpListener(11100); $l1.Start();"
		"$l2 = New-Object System.Net.Sockets.TcpListener(11101); $l2.Start();"
		"$l3 = New-Object System.Net.Sockets.TcpListener(11102); $l3.Start();"
		"$udp = New-Object System.Net.Sockets.UdpClient(11103);"
		"while($true){ Start-Sleep -Seconds 1 }"
		"\""
	);
	std::cout << "Ocupamos todos los puertos que usa veyon , no  cierre el software mantenlo por seguridad" << std::endl;
	SetConsoleTextAttribute(I, 10);   // verde
	std::cout << "Listener iniciado. Manteniendo los puertos que usa veyon ocupados" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (true)
	{
		Sleep(1000);
		system("taskkill -f -IM veyon-worker.exe");
	}
	//Otro metodo para bypassear seria hacer como un bucle de reinicio de red y reactivarla
	//---------------------------------------------------ipconfig/release || ipconfig/renew
	//ejemplo while(true){
	//			
	//			system("ipconfig/release)
	//			sleep(2000);
	//			system("ipconfig/renew)
	//			
	// }


}
