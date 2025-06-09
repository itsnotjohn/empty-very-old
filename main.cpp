#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include "imgui_internal.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Security.hpp"
#include "xor.hpp"
#include <dinput.h>
#include <tchar.h>
#include <thread>
#include <windows.h>
#include <string>
#include <iostream>
#include <cctype>
#include <Windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <conio.h>
#include <stdio.h>
#include "array"
#include <strsafe.h>
#include <Windows.h>
#include <strsafe.h>
#include <algorithm>
#include <WinINet.h>
#include <tlhelp32.h>
#define SELF_REMOVE_STRING TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

//Design

static int delaywtap = 100;
static int delaystap = 100;
static int authstatus = 0;
static int selectedItem = 0;
static int switchTabs = 4;
static bool exitclick = false;
static bool randomizerclick = true;
static bool soundclick = false;

//Clicker
static int counter = 0;
static bool wtapteste2 = false;
static bool stapteste2 = false;
static bool clicker = false;
static bool toggleac = false;
static bool wtap = false;
static int cps = 1;
bool pressedclicker = false;
bool mouseDown;
HHOOK hookdoMouse;
static char specificwindowname[20] = { "Minecraft" };
int keybindchoose = 0;
int keybind = 0;
static bool jogo = false;
std::string key_bind_ac_text = "Toggle Key";
std::string sla = "";

std::string checkkeybind(int k)
{

    const char* const
        KeyNames[] =
    {
"Unknown",
"LBUTTON",
"RBUTTON",
"CANCEL",

"MBUTTON",
"XBUTTON1",
"XBUTTON2",
"Unknown",
"BACK",

"TAB",
"Unknown",
"Unknown",
"CLEAR",
"RETURN",

"Unknown",
"Unknown",
"SHIFT",
"CONTROL",
"MENU",

"PAUSE",
"CAPITAL",
"KANA",
"Unknown",
"JUNJA",

"FINAL",
"KANJI",
"Unknown",
"ESCAPE",
"CONVERT",

"NONCONVERT",
"ACCEPT",
"MODECHANGE",
"SPACE",
"PRIOR",

"NEXT",
"END",
"HOME",
"LEFT",
"UP",
"RIGHT",

"DOWN",
"SELECT",
"PRINT",
"EXECUTE",
"SNAPSHOT",

"INSERT",
"DELETE",
"HELP",
"0",
"1",
"2",

"3",
"4",
"5",
"6",
"7",
"8",
"9",

"Unknown",
"Unknown",
"Unknown",
"Unknown",
"Unknown",

"Unknown",
"Unknown",
"A",
"B",
"C",
"D",
"E",

"F",
"G",
"H",
"I",
"J",
"K",
"L",
"M",

"N",
"O",
"P",
"Q",
"R",
"S",
"T",
"U",

"V",
"W",
"X",
"Y",
"Z",
"LWIN",
"RWIN",

"APPS",
"Unknown",
"SLEEP",
"NUMPAD0",
"NUMPAD1",

"NUMPAD2",
"NUMPAD3",
"NUMPAD4",
"NUMPAD5",
"NUMPAD6",

"NUMPAD7",
"NUMPAD8",
"NUMPAD9",
"MULTIPLY",
"ADD",

"SEPARATOR",
"SUBTRACT",
"DECIMAL",
"DIVIDE",
"F1",

"F2",
"F3",
"F4",
"F5",
"F6",
"F7",
"F8",

"F9",
"F10",
"F11",
"F12",
"F13",
"F14",

"F15",
"F16",
"F17",
"F18",
"F19",
"F20",

"F21",
"F22",
"F23",
"F24",
"Unknown",
"Unknown",

"Unknown",
"Unknown",
"Unknown",
"Unknown",
"Unknown",

"Unknown",
"NUMLOCK",
"SCROLL",
"OEM_NEC_EQUAL",

"OEM_FJ_MASSHOU",
"OEM_FJ_TOUROKU",
"OEM_FJ_LOYA",

"OEM_FJ_ROYA",
"Unknown",
"Unknown",
"Unknown",

"Unknown",
"Unknown",
"Unknown",
"Unknown",
"Unknown",

"Unknown",
"LSHIFT",
"RSHIFT",
"LCONTROL",
"RCONTROL",

"LMENU",
"RMENU"
    };


    return std::string(KeyNames[k]);

}

LRESULT __stdcall mouse_callback(int code, WPARAM wparam, LPARAM lparam)
{

    MSLLHOOKSTRUCT* hook = (MSLLHOOKSTRUCT*)lparam;


    if ((hook->flags == LLMHF_INJECTED)
        || (hook->flags == LLMHF_LOWER_IL_INJECTED))

        return false;

    if ((hook->flags & LLMHF_INJECTED) == LLMHF_INJECTED)

    {

        return false;

    }


    if (wparam != WM_MOUSEMOVE)

    {

        if ((hook->flags == LLMHF_INJECTED)
            || (hook->flags == LLMHF_LOWER_IL_INJECTED))

            return false;


        switch (wparam)
        {


        case WM_LBUTTONDOWN:

            mouseDown = true;

            break;

        case WM_LBUTTONUP:

            mouseDown = false;

            break;


        }


    }


    return CallNextHookEx(hookdoMouse, code, wparam, lparam);

}
DWORD WINAPI hookmouse()
{


    hookdoMouse = SetWindowsHookEx(WH_MOUSE_LL, &mouse_callback, NULL, 0);


    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0))
    {


        TranslateMessage(&msg);

        DispatchMessage(&msg);

    }


    UnhookWindowsHookEx(hookdoMouse);


    return 0;

}

void stapteste()
{
    HWND window;
    while (true)
    {
        window = GetForegroundWindow();
        char windowname[128]{};

        GetWindowTextA(window, windowname, 128);
        if (GetKeyState(0x57))
        {
            if (mouseDown)
            {

                if (stapteste2)
                {
                    if (strstr(windowname, specificwindowname))
                    {
                        Sleep(120);
                        keybd_event(0x53, 0, 0, 0);
                        Sleep(delaystap);

                        keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);

                        Sleep(delaystap);
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}

void wtapteste()
{
    HWND window;
    while (true)
    {
        window = GetForegroundWindow();
        char windowname[128]{};

        GetWindowTextA(window, windowname, 128);
        {
            if (mouseDown)
            {

                if (wtapteste2)
                {
                    if (strstr(windowname, specificwindowname))
                    {
                        Sleep(120);
                        keybd_event(0x53, 0, 0, 0);
                        Sleep(delaystap);

                        keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);

                        Sleep(delaystap);
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}


void DelMe()
{
    TCHAR szModuleName[MAX_PATH];
    TCHAR szCmd[2 * MAX_PATH];
    STARTUPINFO si = { 0 };
    PROCESS_INFORMATION pi = { 0 };

    GetModuleFileName(NULL, szModuleName, MAX_PATH);

    StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);

    CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen((cmd), "r"), _pclose);
    if (!pipe) {
        return "";
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        ((result)) += buffer.data();
    }
    std::string output;
    (output.reserve(result.length()));

    std::copy_if(result.begin(), result.end(),
        std::back_inserter(((output))),
        [](char c) { return c != '\r' && c != '\n' && c != ' '; });
    return ((output));
}


void autoclickerthread()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    HWND window;

    int cu = 1;
    while (cu == 1)
    {
        window = GetForegroundWindow();
        char windowname[128]{};

        GetWindowTextA(window, windowname, 128);

        if (GetKeyState(keybind) & 0x8000 && !pressedclicker)
        {

            pressedclicker = true;
            sla = ("On");
        }

        else if (!(GetKeyState(keybind) & 0x8000) && pressedclicker)
        {
            sla = ("Off");
            toggleac = !toggleac;
            pressedclicker = false;

        }

        if (mouseDown && toggleac)
        {
            if (strstr(windowname, specificwindowname))
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                counter++;
            }

            if (cps == 20) {

                Sleep(20 % cps + 38 + rand() % 2);

            }
            if (cps == 19) {

                Sleep(20 % cps + 48 + rand() % 2);

            }
            if (cps == 18) {

                Sleep(20 % cps + 50 + rand() % 2);

            }
            if (cps == 17) {



                Sleep(20 % cps + 56 + rand() % 1);

            }
            if (cps == 16) {


                Sleep(20 % cps + 54 + rand() % 1);

            }
            if (cps == 15) {

                Sleep(20 % cps + 59 + rand() % 1);

            }
            if (cps == 14) {


                Sleep(20 % cps + 64 + rand() % 1);

            }
            if (cps == 13) {


                Sleep(20 % cps + 73 + rand() % 1);

            }
            if (cps == 12) {
                Sleep(20 % cps + 76 + rand() % 1);
            }
            if (cps == 11) {

                Sleep(20 % cps + 83 + rand() % 1);

            }
            if (cps == 10) {


                Sleep(20 % cps + 90 + rand() % 1);

            }
            if (cps == 9) {


                Sleep(20 % cps + 97 + rand() % 1);

            }
            if (cps == 8) {


                Sleep(20 % cps + 110 + rand() % 1);

            }
            if (cps == 7) {


                Sleep(20 % cps + 120 + rand() % 1);

            }
            if (cps == 6) {

                Sleep(20 % cps + 140 + rand() % 1);

            }
            if (cps == 5) {

                Sleep(20 % cps + 160 + rand() % 1);

            }
            if (cps == 4) {


                Sleep(20 % cps + 180 + rand() % 1);

            }
            if (cps == 3) {

                Sleep(rand() % cps + 200 + rand() % 1);

            }
            if (cps == 2) {

                Sleep(rand() % cps + 240 + rand() % 1);

            }
            if (cps == 1) {

                Sleep(rand() % cps + 280);

            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }
}

int main(int, char**)
{
    //ShowWindow(GetConsoleWindow(), 1);
    //if (authstatus == 0)
    //{
    //    authme();
    //}

    CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)& autoclickerthread, nullptr, 0, 0);
    CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)& hookmouse, nullptr, 0, 0);
    CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)& stapteste, nullptr, 0, 0);
    CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)& wtapteste, nullptr, 0, 0);

    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    GLFWwindow* window = glfwCreateWindow(390, 400, "", NULL, NULL); //Tamanho dessa merda
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO & io = ImGui::GetIO(); (void)io;

    //Cor de fundo
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    bool    _window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImGuiStyle & style = ImGui::GetStyle();

    style.FramePadding = ImVec2(5, 5);
    style.ItemSpacing = ImVec2(5, 3);
    style.WindowBorderSize = 0;
    style.IndentSpacing = 15.0f;
    style.ScrollbarSize = 1.0f;

    style.WindowPadding = ImVec2(7, 15); //Altura botão
    style.WindowRounding = 5.0f;
    style.FramePadding = ImVec2(5, 5);
    style.ScrollbarSize = 15.0f;
    style.ScrollbarRounding = 9.0f;
    style.FrameRounding = 2.0f; //deixar redondo ou sla
    style.GrabMinSize = 2.0f; //deixar redondo ou sla
    style.GrabRounding = 2.0f; //deixar redondo ou sla

    ImVec4 * colors = style.Colors;

    colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.45f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.15f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.25f, 0.00f, 0.50f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.0f, 0.00f, 0.00f, 0.50f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.25f, 0.00f, 0.50f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.25f, 0.00f, 0.50f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.00f, 0.50f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.30f, 0.00f, 0.50f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.25f, 0.00f, 0.50f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        switch (keybindchoose)
        {
        case 1:
            keybind = 0;
            while (keybind == 0)
            {
                for (int i = 3; i < 256; i++)

                {

                    if (i != 13)

                    {

                        if (GetAsyncKeyState((i)& SHRT_MAX)
                            && keybind == 0)

                        {

                            keybind = i;
                            key_bind_ac_text = checkkeybind(i);

                        }

                    }


                }
            }
            keybindchoose = 0;
            break;
        }

        ImGui::SetNextWindowPos(ImVec2(-3, -15));
        ImGui::SetNextWindowSize(ImVec2(768, 420));
        ImGui::Begin("svchost", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

        //ImGui::SameLine(13.f, 0.f);
        //ImGui::Text("EmptyClicker - ", ImVec2(200, 200));
        //ImGui::SameLine();
        //ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "v2", wtap);
        //if (ImGui::IsItemHovered())
        //    ImGui::SetTooltip(("emptyclub.wtf/Changelog"));

        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::SameLine();

        if (ImGui::Button("Latencyx", ImVec2(70, 25)))
        {
            switchTabs = 0;
        }
        ImGui::SameLine();

        if (ImGui::Button("Movement", ImVec2(70, 25)))
        {
            switchTabs = 1;
        }
        ImGui::SameLine();

        if (ImGui::Button("Misc", ImVec2(70, 25)))
        {
            switchTabs = 2;
        }
        ImGui::SameLine();

        if (ImGui::Button("Destruct", ImVec2(70, 25)))
        {
            switchTabs = 3;
        }
        ImGui::SameLine();

        if (exitclick == false)
        {
            ImGui::PushID("Exit");
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(3 / 0.1f, 0.80f, 1.00f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(3 / 0.1f, 1.0f, 0.75f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(3 / 7.0f, 1.0, 1.0));
            ImGui::Button("Exit", ImVec2(70, 25));
            if (ImGui::IsItemClicked(0))
            {
                {
                    Sleep(600);
                    exit(0);
                }
            }
            ImGui::PopStyleColor(3);
            ImGui::PopID();
        }
        switch (switchTabs) {
        case 0: //Clicker
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing(); ImGui::SameLine(13.f, 0.f);
            if (randomizerclick)
            {
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::SameLine(13.f, 0.f);
                ImGui::PushItemWidth(370.0f);
                ImGui::SliderInt(" ", &cps, 1, 20);
            }

            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(13.f, 0.f);
            if (toggleac == true)
            {
                ImGui::PushID(("ToggleClicker"));
                ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(3 / 0.1f, 1.59f, 0.95f));
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(3 / 0.1f, 0.59f, 0.95f));
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(3 / 0.1f, 0.59f, 0.95f));
                ImGui::Button("Toggle Off", ImVec2(182, 32));
                if (ImGui::IsItemClicked(0))
                {
                    toggleac = !toggleac;
                }
                ImGui::PopStyleColor(3);
                ImGui::PopID();
            }
            else
            {
                if (ImGui::Button("Toggle On", ImVec2(182, 32)))
                    toggleac = true;
            }
            ImGui::SameLine();

            if (ImGui::Button(key_bind_ac_text.c_str(), ImVec2(182, 32)))
            {
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip(("Toggle Key"));
                keybindchoose = 1;
            }
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(13.f, 0.f);
            ImGui::Text("Specific Window");
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(13.f, 0.f);
            ImGui::InputText("", specificwindowname, 20);

            //Contador de Clicks
            ImGui::Text("");
            ImGui::Text("");
            ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();  ImGui::Spacing();  ImGui::Spacing();
            ImGui::SameLine(13, 0); ImGui::Text("%d", counter); ImGui::SameLine();
            ImGui::Text(" Clicks");
            break;
        case 1: // Movement

            ImGui::SetNextWindowPos(ImVec2(9, 65));
            ImGui::SetNextWindowSize(ImVec2(360, 280));
            ImGui::Begin("chrome", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);


            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(13.f, 0.f);
            ImGui::Checkbox("STap", &stapteste2);
            if (stapteste2)
            {
                ImGui::PushItemWidth(310.0f);

                ImGui::SliderInt("Delay", &delaystap, 100, 800);
            }

            ImGui::Checkbox("WTap", &wtapteste2);
            if (wtapteste2)
            {
                ImGui::PushItemWidth(310.0f);

                ImGui::SliderInt("Delay", &delaywtap, 100, 800);
            }


            ImGui::End();

            break;
        case 2: // Misc
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(13.f, 0.f);
            ImGui::Text("coming soon");
            break;
        case 3: //Destruct
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(120.f, 0.f);
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(120.f, 0.f);
            if (ImGui::Button("Clear Strings", ImVec2(155, 32)))
            {
                Sleep(2600);
                int messsge1 = MessageBoxA(NULL, "Strings cleaned!\nAny mistake contact Support!", "", MB_OK | MB_ICONINFORMATION);
            }
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SameLine(120.f, 0.f);
            if (ImGui::Button("Destroy and Exit", ImVec2(155, 32)))
            {
                system("start timeout 3");
                DelMe();
                exit(0);
            }
            break;
        case 4:
#define INFO_BUFFER_SIZE 32767
            TCHAR  infoBuf[INFO_BUFFER_SIZE];
            DWORD  bufCharCount = INFO_BUFFER_SIZE;
            GetUserName(infoBuf, &bufCharCount);
            ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
            ImGui::SameLine(13.f, 0.f); ImGui::Text("Welcolme, %s", infoBuf);
            ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
            ImGui::SameLine(13.f, 0.f); ImGui::Text("Time Left: "); ImGui::SameLine();
            ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "lifetime");
            break;
        }
        ImGui::End();

        io.IniFilename = nullptr;
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }
    exec("powershell Disable - MMAgent - mc");
    io.IniFilename = nullptr;
    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
