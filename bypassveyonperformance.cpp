#include <Windows.h>
#include <iostream>



void bypass(){
	//Modo usuario(No admin)
	//Captaremos la Imagen del proceso veyon-worker.exe para terminarlo en bucle , asi evitaremos su regeneracion , esto no requiere usuario de admin
	system("taskkill -f -IM veyon-worker.exe");
	system(
		"start /min powershell -WindowStyle Hidden -Command \""
		"$listener = New-Object System.Net.Sockets.TcpListener(11100);"
		"$listener.Start();"
		"while($true){ Start-Sleep -Seconds 1 }"
		"\""
	);

	std::cout << "Listener iniciado. Manteniendo ocupado el puerto..." << std::endl;
	while (true)
	{
		
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
