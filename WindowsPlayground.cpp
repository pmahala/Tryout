#include<Windows.h>  //same as windows.h as the window filenames are case insensitive
#include<tchar.h>    //gives access to wchar_t 

static const wchar_t CLASSNAME[] = L"My Class";


LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
) {
	WNDCLASSEX wce;
	wce.lpfnWndProc = WndProc;
	wce.hInstance = hInstance;
	wce.lpszClassName = CLASSNAME;

	if (!RegisterClassEx(&wce))  //we are using the RegisterClassEx as we are using WNDCLASSEX  to define windows structure
	{
		MessageBox(NULL, _T("Cannot register the windows class"), _T("Windows Playground"), NULL);
		return 1;
	}
}