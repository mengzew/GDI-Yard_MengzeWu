// GDI+Yard_MengzeWu.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "GDI+Yard_MengzeWu.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

//VOID OnPaint(HDC hdc)
//{
//	Graphics graphics(hdc);
//	Pen      pen(Color(255, 0, 0, 255));
//	graphics.DrawLine(&pen, 0, 0, 200, 100);
//}



VOID DrawRectangle(HDC hdc)
{
	Graphics graphics(hdc);

	// Create a Pen object.
	Pen blackPen(Color(255, 0, 0, 0), 2);
	/* Create Brush objects*/
	SolidBrush grayBrush(Color(150, 192, 192, 192));
	SolidBrush greenBrush(Color(150, 0, 255, 0));
	SolidBrush redBrush(Color(150, 255, 0, 0));
	SolidBrush yellowBrush(Color(150, 255, 255, 0));
	
	/* Create Font Family*/
	FontFamily   fontFamily(L"Arial");
	Font         font(&fontFamily, 10, FontStyleBold, UnitPoint);
	SolidBrush   fontBrush(Color::Black);

	/* Create String Format*/
	StringFormat strFormat;
	strFormat.SetAlignment(StringAlignmentCenter);
	strFormat.SetLineAlignment(StringAlignmentCenter);


	// Create A-Group RectF object.
	RectF rectA1(50.0f, 10.0f, 60.0f, 20.0f);
	RectF rectA2(50.0f, 40.0f, 60.0f, 20.0f);
	RectF rectA3(50.0f, 70.0f, 60.0f, 20.0f);
	RectF rectA4(50.0f, 100.0f, 60.0f, 20.0f);
	RectF rectA5(50.0f, 130.0f, 60.0f, 20.0f);
	RectF rectA6(50.0f, 160.0f, 60.0f, 20.0f);
	RectF rectA7(50.0f, 190.0f, 60.0f, 20.0f);
	RectF rectA8(50.0f, 220.0f, 60.0f, 20.0f);
	RectF rectA9(50.0f, 250.0f, 60.0f, 20.0f);

	// Create B-Group RectF object.

	// Draw Strings.
	graphics.DrawString(L"A1", -1, &font, rectA1, &strFormat, &fontBrush);
	graphics.DrawString(L"A2", -1, &font, rectA2, &strFormat, &fontBrush);
	graphics.DrawString(L"A3", -1, &font, rectA3, &strFormat, &fontBrush);
	graphics.DrawString(L"A4", -1, &font, rectA4, &strFormat, &fontBrush);
	graphics.DrawString(L"A5", -1, &font, rectA5, &strFormat, &fontBrush);
	graphics.DrawString(L"A6", -1, &font, rectA6, &strFormat, &fontBrush);
	graphics.DrawString(L"A7", -1, &font, rectA7, &strFormat, &fontBrush);
	graphics.DrawString(L"A8", -1, &font, rectA8, &strFormat, &fontBrush);
	graphics.DrawString(L"A9", -1, &font, rectA9, &strFormat, &fontBrush);


	// Draw A-Group rect.
	graphics.DrawRectangle(&blackPen, rectA1);
	graphics.FillRectangle(&grayBrush, rectA1);


	graphics.DrawRectangle(&blackPen, rectA2);
	graphics.FillRectangle(&greenBrush, rectA2);

	graphics.DrawRectangle(&blackPen, rectA3);
	graphics.FillRectangle(&grayBrush, rectA3);

	graphics.DrawRectangle(&blackPen, rectA4);
	graphics.FillRectangle(&grayBrush, rectA4);

	graphics.DrawRectangle(&blackPen, rectA5);
	graphics.FillRectangle(&redBrush, rectA5);

	graphics.DrawRectangle(&blackPen, rectA6);
	graphics.FillRectangle(&grayBrush, rectA6);

	graphics.DrawRectangle(&blackPen, rectA7);
	graphics.FillRectangle(&yellowBrush, rectA7);

	graphics.DrawRectangle(&blackPen, rectA8);
	graphics.FillRectangle(&grayBrush, rectA8);

	graphics.DrawRectangle(&blackPen, rectA9);
	graphics.FillRectangle(&redBrush, rectA9);
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	HWND                hWnd;
	MSG                 msg;
	WNDCLASS            wndClass;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("YardDiag");

	RegisterClass(&wndClass);

	hWnd = CreateWindow(
		TEXT("YardDiag"),   // window class name
		TEXT("Yard Diag"),  // window caption
		WS_OVERLAPPEDWINDOW,      // window style
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		CW_USEDEFAULT,            // initial x size
		CW_USEDEFAULT,            // initial y size
		NULL,                     // parent window handle
		NULL,                     // window menu handle
		hInstance,                // program instance handle
		NULL);                    // creation parameters

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC          hdc;
	PAINTSTRUCT  ps;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawRectangle(hdc);           //这里call函数
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
} // WndProc
