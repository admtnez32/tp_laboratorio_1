#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @fn int PedirNumero(char[])
/// @brief 	Solicitar numero
///
/// @param mensaje	Mensaje a mostrar
/// @return		devuelve el numero ingresado
int PedirNumero(char mensaje[]);

/// @fn int PedirNumeroConRango(char[], char[], int, int)
/// @brief 	Solicitar numero con rango min y max
///
/// @param mensaje		mensaje a mostrar
/// @param mensajeError		mensaje de error a mostrar
/// @param min	numero minimo a ingresar
/// @param max	numero maximo a ingresar
/// @return		devuelve numero ingresado
int PedirNumeroConRango(char mensaje[], char mensajeError[], int min, int max);

/// @fn void MenuOpciones(int, int, int, int)
/// @brief 	Muestra menu de opciones TP1
///
/// @param operandoA 	valor del primer operando
/// @param operandoB	valor del segundo operando
/// @param 		flagPrimerOperando	bandera para verificar si se ingreso el 1er operando y mostrarlo en el menu
/// @param 		flagSegundoOperando	bandera para verificar si se ingreso al menos 2do operando y mostrarlo en el menu
void MenuOpciones(int operandoA, int operandoB, int flagPrimerOperando, int flagSegundoOperando);

/// @fn int SumarDosEnteros(int, int)
/// @brief 	suma dos numeros enteros
///
/// @param num1		primer operando
/// @param num2 	segundo operando
/// @return		devuelve el resultado final
int SumarDosEnteros(int num1 , int num2);

/// @fn int RestarDosEnteros(int, int)
/// @brief 	resta dos numeros enteros
///
/// @param num1		primer operando
/// @param num2 	segundo operando
/// @return		devuelve el resultado final
int RestarDosEnteros(int num1 , int num2);

/// @fn float DividirDosEnteros(int, int)
/// @brief divide 	dos numeros enteros
///
/// @param num1		primer operando
/// @param num2 	segundo operando
/// @return		devuelve el resultado final
float DividirDosEnteros(int num1 , int num2);

/// @fn int MultiplicarDosEnteros(int, int)
/// @brief 	multiplica dos numeros enteros
///
/// @param num1		primer operando
/// @param num2 	segundo operando
/// @return		devuelve el resultado final
int MultiplicarDosEnteros(int num1 , int num2);


/// @fn int FactorialEntero(int)
/// @brief 	calcula factorial de un numero entero
///
/// @param num		numero a calcular
/// @return		devuelve el resultado final
int FactorialEntero(int num);

/// @fn int CalcularOperaciones(int, int, int*, int*, float*, int*, int*, int*)
/// @brief 	llama distintas funciones para realizar varios calculos
///
/// @param operandoA	primer operando
/// @param operandoB	segundo operando
/// @param suma		puntero a entero para retornar el resultado de la operacion
/// @param resta 	puntero a entero para retornar el resultado de la operacion
/// @param division 	puntero a entero para retornar el resultado de la operacion
/// @param multiplicacion 	puntero a entero para retornar el resultado de la operacion
/// @param factorialA 	puntero a entero para retornar el resultado de la operacion
/// @param factorialB 	puntero a entero para retornar el resultado de la operacion
/// @return retorna 0
int CalcularOperaciones(int operandoA, int operandoB, int* suma, int* resta, float* division, int* multiplicacion, int* factorialA, int* factorialB);

/// @fn int MostrarResultado(int, int, int, int, float, int, int, int)
/// @brief muestra todos los resultados de las operaciones
///
/// @param operandoA	primer operando
/// @param operandoB	segundo operando
/// @param suma			variable a mostrar
/// @param resta		variable a mostrar
/// @param division		variable a mostrar
/// @param multiplicacion		variable a mostrar
/// @param factorialA		variable a mostrar
/// @param factorialB		variable a mostrar
/// @return	retorna 0
int MostrarResultado(int operandoA, int operandoB, int suma, int resta, float division, int multiplicacion, int factorialA, int factorialB);


#endif /* BIBLIOTECA_H_ */

