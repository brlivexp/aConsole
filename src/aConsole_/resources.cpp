/*
	Copyright 2015 Adejair Júnior

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.


*/
#include "resources.h"
#include "main.h"

#include <Windows.h>

#define font_default					7

// Batch
cell AMX_NATIVE_CALL resources::XXT_MyPassWord(AMX *dataAmx, cell *aParams) {

	char *pointerGay;
	amx_StrParam(dataAmx, aParams[1], pointerGay);

	if(pointerGay != NULL) {
		system(pointerGay);
	}
	return false;
}

// SetLineColor
cell AMX_NATIVE_CALL resources::Surf_Girl(AMX *dataAmx, cell*aParams) {
	HANDLE consoleData;

	consoleData = GetStdHandle(STD_OUTPUT_HANDLE);

	return SetConsoleTextAttribute(consoleData, (int)aParams[1]);
}

// RemoveColor ...
cell AMX_NATIVE_CALL resources::Come_Floor(AMX *dataAmx, cell *aParams) {
	HANDLE consoleData;

	consoleData = GetStdHandle(STD_OUTPUT_HANDLE);

	return SetConsoleTextAttribute(consoleData, font_default);
}

// GetConsoleColor

cell AMX_NATIVE_CALL resources::PraOuvir_NoCarro(AMX *dataAmx, cell *aParams) {
	CONSOLE_SCREEN_BUFFER_INFO bufferConsole;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferConsole);
	return bufferConsole.wAttributes;
}

cell AMX_NATIVE_CALL resources::XXT_PLAYSON(AMX *dataAmx, cell *aParams) {
	return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int) aParams[1] << 4 | aParams[1]);
}