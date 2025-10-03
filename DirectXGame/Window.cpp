#include "Window.h"

Window* window = nullptr;

Window::Window() : m_hwnd(nullptr), m_is_run(false)
{
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        // Event fired when the window will be created
        window->onCreate();
        break;
    }

    case WM_DESTROY:
    {
        // Event fired when the window will be destroyed
        window->onDestroy();
        ::PostQuitMessage(0);
        break;
    }

    default:
        return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }

    return NULL;
}

bool Window::init()
{
    // setting up WNDCLASSEX object
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"MyWindowClass";
    wc.lpfnWndProc = WndProc;

    if (!::RegisterClassEx(&wc)) // if the registration of class fails, the function will return false
        return false;

    if (!window)
        window = this;

    m_hwnd = ::CreateWindowEx(0, L"MyWindowClass", L"C++ 3D Game Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1536, 864,
        NULL, NULL, GetModuleHandle(NULL), NULL);

    if (!m_hwnd)
        return false;

    // show up the window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);

    // set this flag to true to indicate that the window is initialized and running
    m_is_run = true;

    return true;
}

bool Window::broadcast()
{
    MSG msg = {};

    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    window->onUpdate();

    ::Sleep(0);

    return true;
}

bool Window::release()
{
    // Destroy the window
    if (!::DestroyWindow(m_hwnd))
        return false;

    return true;
}

bool Window::isRun()
{
    return m_is_run;
}

void Window::onDestroy()
{
    m_is_run = false;
}

Window::~Window()
{
}
