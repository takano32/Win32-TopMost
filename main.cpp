#include <windows.h>


int WINAPI WinMain(
	HINSTANCE hInstance, // handle to current instance
	HINSTANCE hPrevInstance, // handle to previous instance
	LPSTR lpCmdLine, // pointer to command line
	int nCmdShow // show state of window
	){
	char buffer[1024];
	HWND hActiveWindow = GetForegroundWindow();
	HWND hTargetWindow = hActiveWindow;// = GetNextWindow(hActiveWindow, GW_HWNDNEXT);

	while((hTargetWindow = GetNextWindow(hTargetWindow,GW_HWNDNEXT))!=NULL) {
		if(IsWindowVisible(hTargetWindow))
		  break;
	}



	GetWindowText(hTargetWindow, buffer, 1024);
	
	LONG lState;
	lState = GetWindowLong(hTargetWindow, GWL_EXSTYLE);
	if(lState & WS_EX_TOPMOST ) {
		MessageBox(NULL, buffer, "Unset Top Most", MB_OK);
		//SetWindowLong(hTargetWindow, GWL_EXSTYLE, lState ^ WS_EX_TOPMOST );
		/*
		SetWindowPos(hTargetWindow,
					 HWND_NOTOPMOST, 0, 0, 0, 0,
					 SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);
		  */
	}else {
		MessageBox(NULL, buffer, "Set Top Most", MB_OK);
		/*
		SetWindowPos(hTargetWindow,
					 HWND_TOPMOST, 0, 0, 0, 0,
					 SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);*/
	}
	return 0;
}

