#include <windows.h>
#include <fstream>

extern "C" __declspec(dllexport) void CALLBACK Entrypoint(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow)
{
    std::ofstream log("C:\\Users\\t696974\\Documents\\dll_log.txt", std::ios::app);
    if (log.is_open()) {
        log << "[+] Entrypoint called by rundll32.exe. PID: " << GetCurrentProcessId() << std::endl;
        log << "    Arg: " << lpszCmdLine << std::endl;
        log.close();
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
