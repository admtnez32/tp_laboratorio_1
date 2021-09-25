/****************************
*    LABORATORIO            *
*    TP 1  en C             *
*    IDE ECLIPSE            *
*                           *
*    MARTINEZ ALEXIS        *
*    DIV 1F                 *
****************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int primerOperando;
	int segundoOperando;
	int flagOperandoA = 1;
	int flagOperandoB = 1;
	int flagCalculos = 0;

	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	int resultadoFactorialA;
	int resultadoFactorialB;
	float resultadoDivision;

	do{
		printf("********************************************\n");
		MenuOpciones(primerOperando, segundoOperando, flagOperandoA, flagOperandoB);
		printf("\n\n********************************************\n");

		opcion = PedirNumeroConRango("\n\nIngrese opcion: ", "Opcion incorrecta. Reingrese: ", 1, 5);

		switch(opcion)
		{
			case 1:
				primerOperando = PedirNumero("\nIngrese 1er operando: ");
				printf("\n--------------------------------------");
				printf("\n\n--- OPERANDO 'A' CARGADO CON EXITO ---\n\n");
				printf("--------------------------------------\n\n\n\n");

				flagOperandoA = 0;
				flagCalculos = 0;
				break;

			case 2:
				segundoOperando = PedirNumero("\nIngrese 2do operando: ");
				printf("\n--------------------------------------");
				printf("\n\n--- OPERANDO 'B' CARGADO CON EXITO ---\n\n");
				printf("--------------------------------------\n\n\n\n");

				flagOperandoB = 0;
				flagCalculos = 0;
				break;

			case 3:
				if(flagOperandoA == 0 && flagOperandoB == 0)
				{
					CalcularOperaciones(primerOperando, segundoOperando, &resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorialA, &resultadoFactorialB);
					printf("\n--------------------------------------------");
					printf("\n\n--- OPERACIONES CALCULADAS CON EXITO ---\n\n");
					printf("--------------------------------------------\n\n\n\n");
					flagCalculos = 1;
				}
				else
				{
					printf("\n--------------------------------------------");
					printf("\n\n--- ERROR. ANTES DEBE CARGAR 2 OPERANDOS ---\n\n");
					printf("--------------------------------------------\n\n\n\n");
				}

				break;

			case 4:
				if(flagCalculos)
				{
					printf("\n---------------------------------------");
					printf("\n\n--- MOSTRAR RESULTADOS ---\n\n");
					MostrarResultado(primerOperando, segundoOperando, resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB);
					printf("---------------------------------------\n\n\n\n");
				}
				else
				{
					printf("\n-----------------------------------------------");
					printf("\n\n--- ERROR. ANTES DEBE REALIZAR LOS CALCULOS ---\n\n");
					printf("-----------------------------------------------\n\n\n\n");
				}

				break;


			case 5:
				printf("\n\n*** !!! ADIOS !!! ***");
				break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}








