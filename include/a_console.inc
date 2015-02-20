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

#if defined _PLUGIN_CONSOLE_included
  #endinput
#endif

#include <a_samp>

#define _PLUGIN_CONSOLE_included

#define AZUL_ESCURO                     1
#define VERDE_ESCURO                    2
#define CYAN_ESCURO                     3
#define VERMELHO_ESCURO                 4
#define ROXO_ESCURO                     5

#define MARROM_MEDIO                    6

#define CINZA_CLARO                     7
#define CINZA_ESCURO                    8
#define AZUL_MEDIO                      9

#define VERDE_CLARO                     10
#define AZUL_CLARO                      11 
#define VERMELHO_NORMAL                 12

#define ROSA_NORMAL                     13
#define AMARELO_NORMAL                  14
#define BRANCO_NORMAL                   15



/**
  <sumary> Leitura de comandos Batchs e execução </sumary>
  <param name = "batched[]"> String do comando batch a ser executado</param>
  <returns> Sem retornos de valores </returns>

*/
native SetBatch(batched[]);


/**

  <sumary> Função para setar a cor de uma determinada linha</sumary>
  <param name = "colorNumber">Escolha a cor dentro das definições acima.</param>
  <returns> Sem retornos de valores </returns>

*/
native SetLineColor(colorNumber);

/**

  <sumary> Remove todas as cores do console que foram setadas.</sumary>
  <returns> Sem retornos de valores </returns>

*/
native RemoveConsoleColor();

/**
  <sumary>Pega a cor do Console.</sumary>
  <returns> Cor do console em (números) </returns>
*/

native GetConsoleColor();

/**
  <sumary>Seta Cor Full do console por linha (BACK AND Single Color) </sumary>
  <param name = "color"> Cor a ser setada </param>
  <returns> Sem retornos de valores </returns>
*/
native SetFullColor(color);


/**
  <sumary>Printa uma mensagem colorida em apenas uma linha, sem parametros.</sumary>
  <param name = "corType"> Cor predefinida a ser setada</param>
  <param name = "args[]"> Corpo da mensagem</param>
  <returns> Sem retornos de valores </returns>
*/
stock printc_line(corType, args[]) {
  SetLineColor(corType);
  print(args);
  RemoveConsoleColor();
}


/**
  <sumary>Printa uma mensagem colorida em apenas uma linha, com parametros.</sumary>
  <param name = "corType"> Cor predefinida a ser setada</param>
  <param name = "args[]"> Corpo da mensagem</param>
  <param name = "params[]"> São os parametros dos args </param>
  <returns> Sem retornos de valores </returns>
*/
stock printfc_line(corType, args[], params[]) {
  SetLineColor(corType);
  printf(args, params);
  RemoveConsoleColor();
}

/**
  <sumary>Seta uma sementação de cores no painel.</sumary>
  <param name = "corType"> Cor predefinida a ser setada</param>
  <returns> Sem retornos de valores </returns>
*/
stock SetAllSegmentColor(corType) {
  return SetLineColor(corType);
}

/**
  <sumary>Remove a sementação de cores do Console </sumary>
  <returns> Sem retornos de valores </returns>
*/
stock RemoveAllSegmentColor() {
  return RemoveConsoleColor();
}


/**
  <sumary>Pega o nome da cor que esta sendo usada no console pelo nome</sumary>
  <returns> Retorna o nome da cor usada.</returns>
*/
stock GetConsoleColorEx() {
  new colorString[50];

  switch(GetConsoleColor()) {

    case 1: colorString = "Azul Escuro";
    case 2: colorString = "Verde Escuro";
    case 3: colorString = "Cyan Escuro";
    case 4: colorString = "Vermelho Escuro";
    case 5: colorString = "Roxo Escuro";
    case 6: colorString = "Marrom Medio";
    case 7: colorString = "Default SA:MP";
    case 8: colorString = "Cinza Escuro";
    case 9: colorString = "Azul Medio";
    case 10: colorString = "Verde Claro";
    case 11: colorString = "Azul Claro";
    case 12: colorString = "Vermelho Normal";
    case 13: colorString = "Rosa Normal";
    case 14: colorString = "Amarelo Normal";
    case 15: colorString = "Branco Normal";
  }
  return colorString;
}