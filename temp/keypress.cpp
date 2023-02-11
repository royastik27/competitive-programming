#include <windows.h>
#include <iostream>

using namespace std;

HKL currentKBL = GetKeyboardLayout(0);

void PressKey(char key) {
  INPUT input = { 0 };
  input.type = INPUT_KEYBOARD;
  input.ki.wVk = VkKeyScanEx( key, currentKBL );
  input.ki.dwFlags = 0;
  SendInput(1, &input, sizeof(input));
}

void ReleaseKey(char key) {
  INPUT input = { 0 };
  input.type = INPUT_KEYBOARD;
  input.ki.wVk = VkKeyScanEx( key, currentKBL );;
  input.ki.dwFlags = KEYEVENTF_KEYUP;
  SendInput(1, &input, sizeof(input));
}

int main() {

    Sleep(5000);

    cout << "Waiting done!\n";

    string str = "My name is Astik Roy. I am a student of Computer Science and Engineering";

    

    for(int i = 0; i < str.length(); ++i)
        PressKey(str[i]), ReleaseKey(str[i]);
    return 0;
}