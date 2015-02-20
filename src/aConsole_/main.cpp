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

#include "main.h"
#include "resources.h"

typedef void (*logprintf_t)(char* format, ...);
logprintf_t logprintf;
extern void *pAMXFunctions;


PLUGIN_EXPORT bool PLUGIN_CALL Load(void **pointerf)  {

	pAMXFunctions = pointerf[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t) pointerf[PLUGIN_DATA_LOGPRINTF];

	logprintf("=======================================");
	logprintf(" aConsole carregado com sucesso ! ");
	logprintf(" Criador %s ", AUTOR_PLUGIN);
	logprintf("=======================================");

	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	logprintf(" aConsole foi desconectado !");
}


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

AMX_NATIVE_INFO registrarCodigo[] = {
	{"SetBatch", resources::XXT_MyPassWord},
	{"SetLineColor", resources::Surf_Girl},
	{"RemoveConsoleColor", resources::Come_Floor},
	{"GetConsoleColor", resources::PraOuvir_NoCarro},
	{"SetFullColor", resources::XXT_PLAYSON},
	{0,0}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *dataAmx) {
	return amx_Register(dataAmx, registrarCodigo, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *dataAmx) {
	return AMX_ERR_NONE;
}
