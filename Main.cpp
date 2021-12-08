#include <windows.h>
#include <tchar.h>
#include<stdlib.h>
#include <iostream>
#include "Graphics.h"

//first I need to have a system that dynamicly draw the grid & updates it whenever the screen is resized

Grid grid = SetUpGrid(650,650,20);
int width, height;


int WINAPI WinMain(	_In_ HINSTANCE hInstance,
_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
);
LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

HINSTANCE hInst;
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{



    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("Snake Game");
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindowEx explained:
    // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application dows not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindowEx(
        WS_EX_COMPOSITED,
        _T("Snake Game"),
        _T("Snake Game !!"),
        WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU,
        0, 0,
        650, 650,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

    return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, Windows desktop!");
    switch (message)
    {

    case WM_SIZE:
    {

         width = LOWORD(lParam);  // Macro to get the low-order word.
         height = HIWORD(lParam); // Macro to get the high-order word.
      
    }

        break;
    case WM_PAINT:
       UpdateGrid(&grid,width,height, &hdc, &hWnd, &ps);
        break;
        case WM_CLOSE:
        if (MessageBox(hWnd, L"Do You Really Want To Quit ?", L"Snake Game", MB_OKCANCEL) == IDOK)
        {
            exit(0);
        }
        // Else: User canceled. Do nothing.
        return 0;
   
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}