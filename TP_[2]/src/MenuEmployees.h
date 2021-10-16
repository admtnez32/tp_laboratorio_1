#ifndef MENUEMPLOYEES_H_
#define MENUEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#define PRINCIPAL 1
#define MODIFICAR 2


/// @fn int MenuPrincipal(void)
/// @brief muestra menu principal
///
/// @return 0
int MenuPrincipal(void);

/// @fn int MenuModificar(void)
/// @brief muestra menu modificar
///
/// @return 0
int MenuModificar(void);

/// @fn int MenuInformes(void)
/// @brief muestra menu de informes
///
/// @return 0
int MenuInformes(void);

/// @fn int PrintMenu(int)
/// @brief llama a la funcion correspondiente
///
/// @param numberMenu numero de menu a mostrar
/// @return -1 si el menu a mostrar no existe, 0 si es OK
int PrintMenu(int numberMenu);


#endif /* MENUEMPLOYEES_H_ */
