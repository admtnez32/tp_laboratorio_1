#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int PedirNumero(char mensaje[])
{
	int numero;

	printf(mensaje);
	scanf("%d", &numero);

	return numero;
}

int PedirNumeroConRango(char mensaje[], char mensajeError[], int min, int max)
{
	int numero;

	printf(mensaje);
	scanf("%d", &numero);

	while(numero<min || numero>max)
	{
		printf(mensajeError);
		scanf("%d", &numero);
	}

	return numero;
}

void MenuOpciones(int operandoA, int operandoB, int flagPrimerOperando, int flagSegundoOperando)
{

	printf("	*** MENU DE OPCIONES ***\n\n");

	if(flagPrimerOperando)
	{
		printf("	1- Ingresar 1er operando (A = X)\n");
	}
	else
	{
		printf("	1- Ingresar 1er operando (A = %d)\n", operandoA);
	}

	if(flagSegundoOperando)
	{
		printf("	2- Ingresar 2do operando (B = Y)\n");
	}
	else
	{
		printf("	2- Ingresar 2do operando (B = %d)\n", operandoB);
	}

	printf("	3- Calcular todas las operaciones\n");
	printf("		a) Calcular la suma (A+B)\n");
	printf("		b) Calcular la resta (A-B)\n");
	printf("		c) Calcular la division (A/B)\n");
	printf("		d) Calcular la multiplicacion (A*B)\n");
	printf("		e) Calcular el factorial (A!)\n");
	printf("	4- Informar resultados\n");
	printf("	5- Salir");

}

int CalcularOperaciones(int operandoA, int operandoB, int* suma, int* resta, float* division, int* multiplicacion, int* factorialA, int* factorialB)
{

	*suma = SumarDosEnteros(operandoA, operandoB);

	*resta = RestarDosEnteros(operandoA, operandoB);

	*division = DividirDosEnteros(operandoA, operandoB);

	*multiplicacion = MultiplicarDosEnteros(operandoA, operandoB);

	*factorialA = FactorialEntero(operandoA);

	*factorialB = FactorialEntero(operandoB);

	return 0;
}

int SumarDosEnteros(int num1 , int num2)
{
	int resultado;

	resultado = num1 + num2;

return resultado;
}

int RestarDosEnteros(int num1 , int num2)
{
	int resultado;

	resultado = num1 - num2;

return resultado;
}

float DividirDosEnteros(int num1 , int num2)
{
	float resultado;

	if(num2 != 0)
	{
		resultado = (float) num1 / num2;
	}

return resultado;

}

int MultiplicarDosEnteros(int num1 , int num2)
{
	int resultado;

	resultado = num1 * num2;

return resultado;
}

int FactorialEntero(int num)
{
	int resultado = 1;

	if(num > -1 && num < 13)
	{
		for(int i=1; i<num+1; i++)
		{
				resultado *= i;
		}
	}

return resultado;
}

int MostrarResultado(int operandoA, int operandoB, int suma, int resta, float division, int multiplicacion, int factorialA, int factorialB)
{
	printf("El resultado de %d+%d es = %d\n\n", operandoA, operandoB, suma);
	printf("El resultado de %d-%d es = %d\n\n", operandoA, operandoB, resta);

	if(operandoB != 0)
	{
		printf("El resultado de %d/%d es = %.2f\n\n", operandoA, operandoB, division);
	}
	else
	{
		printf("No se puede dividir por cero\n\n");
	}

	printf("El resultado de %d*%d es = %d\n\n", operandoA, operandoB, multiplicacion);

	if(operandoA > -1 && operandoA < 13)
	{
		printf("El factorial de %d es = %d\n\n", operandoA, factorialA);
	}
	else
	{
		printf("El factorial de %d no puede ser calculado\n\n", operandoA);
	}

	if(operandoB > -1 && operandoB < 13)
		{
			printf("El factorial de %d es = %d\n\n", operandoB, factorialB);
		}
		else
		{
			printf("El factorial de %d no puede ser calculado\n\n", operandoB);
		}

	return 0;
}
