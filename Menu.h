#ifndef MENU_H
#define MENU_H
#include <iostream>
// Clases generales
#include "Escritor.h"
#include "Lectura.h"
#include "Lista.h"
#include "CONSTANTES.h"
// Subclases
#include "Novela.h"
#include "Novela_historica.h"
#include "Cuento.h"
#include "Poema.h"
// Para la opcion de sortear una lectura
#include <stdlib.h>
#include <time.h>
// Para la cola de lecturas
#include "Cola.h"
//Para pedir datos al usuario
#include "Printer.h"

#include "Lista_escritores.h"
#include "Lista_lecturas.h"

using namespace std;

class Menu {

private:

    int opcion;
    Printer printer;
    Lista_lecturas* lista_lecturas;
    Lista_escritores* lista_escritores;
    Cola<Lectura*>* cola_lecturas;

    //!Opcion 1
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea y almacena en lista_lecturas la lectura con los atributos ingresados por el usuario.
    void agregar_lectura();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Pide al usuario los atributos necesarios y crea el objeto correspondiente (Poema, Cuento, Novela, Novela_historica)
    Lectura* crear_lectura();

    //!Opcion2
    //PRE: La lista_lecturas debe estar bien definida.
    /*POST: Quita de lista_lecturas la lectura ingresada por el usuario.
            De no existir, se lo comunica al usuario. */
    void quitar_lectura();

    //PRE:
    //POST:
    void actualizar_cola(Lectura* lectura_nueva);

    //!Opcion 3
    //PRE: La lista_escritores debe estar ben definida.
    //POST: Crea y almacena en lista_escritores el escritor con los atributos ingresados por el usuario.
    void agregar_escritor();

    //PRE: La lista_escritores debe estar ben definida.
    //POST: Pide al usuario los atributos necesarios y crea al Escritor.
    Escritor* crear_escritor();

    //!Opcion 4
    //PRE: La lista_escritores debe estar bien definida.
    //POST: Modifica el atributos anio_dfallecimiento del Escritor ingresado por el usuario.
    void modificar_fallecimiento();

    //!Opcion 8
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Lista las lecturas entre dos a??os ingresados por el usuario.
    void listar_lecturas_entre_anios();

    //!Opcion 9
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Lista las lecturas que pertenezcan al escritor ingresado por el usuario.
    void listar_por_escritor();

    //!Opcion 10
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Imprime las novelas del g??nero ingresado por el usuario.
    void listar_novelas_de_genero();

    //!Opcion 11
    //PRE: La lista_lecturas y la cola_lecturas deben estar bien definidas.
    //POST: Crea una cola de lecturas y perite leer la del frente de la cola.
    void proximas_lecturas();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea una cola de lecturas, ordenada por minutos de lectura.
    void cola_de_lecturas();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Devuelve una lista con las lecturas, ordenada por minutos de lectura.
    Lista<Lectura*>* ordenar_por_minutos();

    //PRE: la lista_lecturas y lecturas_ordenadas deben estar bien definidas.
    /*POST: Devuelve el indice de la lista_lecturas donde se debe almacenar
            la lectura para mantener la lista ordenada por minutos de lectura. */
    int obtener_posicion_segun_minutos(Lista<Lectura*>* lecturas_ordenadas, Lectura* lectura);

    //PRE: La cola_lecturas debe estar bien definida.
    //POST: Poregunta al usuario si desea leet la lectura al frente de la cola.
    void marcar_como_leida();

    //!Opcion 12 -> salir()

public:

    //PRE: -
    //POST: Construye un Menu.
    Menu();

    //PRE: -
    //POST: Destruye un Menu.
    ~Menu();

    //PRE: Menu debe ser un objeto v??lido.
    //POST: Impriem las opcines del Menu.
    void mostrar_menu();

    //PRE: Menu debe ser un objeto v??lido.
    //POST: Pide al usuario la opcion que desea ejecutar del Menu.
    void elegir_opcion();

    //PRE: Menu debe ser un objeto v??lido.
    //POST: Dependiendo de la opcion ingresada por el usuario, se ejecuta la acci??n correspondiente.
    bool selector_menu();
};

#endif
