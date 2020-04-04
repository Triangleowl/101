#include <Windows.h>
#include <stdio.h>

#define MY_IDET 0x01
#define MY_BUTTON1 0x02
#define MY_BUTTON2 0x03

TCHAR window_name[] = TEXT("first window");
TCHAR class_name[] = TEXT("window class name");
TCHAR err_msg[1024];
HINSTANCE	hinst;

LRESULT CALLBACK window_process(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	)
{
	hinst = hInstance;

	WNDCLASS wndclass;
	ZeroMemory(&wndclass, sizeof(WNDCLASS));	
	wndclass.lpszClassName = class_name;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = window_process;
	if (!RegisterClass(&wndclass)) {
		sprintf(err_msg, "RegisterClass() error: %d\n", GetLastError());
		MessageBox(NULL, err_msg, "ERROR", MB_OK);
		return 1;
	}

	HWND hwnd = CreateWindow(
		class_name,
		window_name,
		WS_OVERLAPPEDWINDOW,
		500, 300, 800, 600,
		0,
		0,
		hinst,
		nullptr);

	if (!hwnd) {
		sprintf(err_msg, "CreateWindow() error: %d\n", GetLastError());
		MessageBox(NULL, err_msg, "ERROR", MB_OK);
		return 1;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return 0;
}

LRESULT CALLBACK window_process(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	//case WM_COMMAND:
	/*
	case WM_CHAR:
		sprintf(err_msg, "%c key down", wParam);
		MessageBox(NULL, err_msg, "keybord down", MB_OK);
		return  0;
	*/

	case WM_CREATE:
		// create EDIT
		CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE, 0, 0, 600, 600, hwnd, (HMENU)MY_IDET, hinst, nullptr);
		//CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE, 0, 0, 600, 600, hwnd, (HMENU)MY_IDET, hinst, nullptr);
		// create BUTTON1
		CreateWindow("BUTTON", "填充", WS_CHILD|WS_VISIBLE, 650, 200, 100, 50, hwnd, (HMENU)MY_BUTTON1, hinst, nullptr);
		// create BUTTON2
		CreateWindow("BUTTON", "抓取", WS_CHILD|WS_VISIBLE, 650, 350, 100, 50, hwnd, (HMENU)MY_BUTTON2, hinst, nullptr);

		return 0;

	
	case WM_COMMAND:
	{
					   switch (LOWORD(wParam)) {
					   case MY_BUTTON1:
						   SetDlgItemText(hwnd, MY_IDET, "Hello, this is a test");
						   return 0;
					   case MY_BUTTON2:
						   GetDlgItemText(hwnd, MY_IDET, err_msg, 1023);
						   MessageBox(hwnd, err_msg, "抓取", MB_OK);
						   return 0;
					   }
					   
	}
	
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}