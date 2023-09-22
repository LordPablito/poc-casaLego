// se hace la clase del lego

class piezaLego {
public:
    string tipo
    string color;

    piezaLego(string _type, string _color) : type(_type), color(_color) {}

    // Método de compatibilidad
    virtual bool sonCompatibles(const piezaLego & other)
    const {
       
    }
};

//se hace una cola(queue) para tener un orden en el cual se iran poniendo las piezas de lego
queue<piezaLego> constructionQueue;


// constructor de la casa
void construirCasa() {
    while (!constructionQueue.empty()) {
        piezaLego piezaActual = constructionQueue.front();
        constructionQueue.pop();

//para criterio de compatibilidad de piezas se considera el tipo de pieza que son y si estas tiene que seguir ciertos requisitos
//como que otras piezas tienen por debajo, cuanto espacio queda para completar la pared, que el techo necesite 4 paredes,
//la puerta debe estar en la pared correcta para la funcion que vaya a tener

        // Verifica la compatibilidad con las piezas ya construidas
        if (esCompatible(piezaActual)) {
            // Ensambla la pieza en la casa
            juntarPieza(piezaActual);
        } else {
            // La pieza no es compatible en este momento, se vuelve a encolar
            constructionQueue.push(piezaActual);
        }
    }
}

