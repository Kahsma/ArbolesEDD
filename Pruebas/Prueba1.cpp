#include <iostream>
#include <vector>

using namespace std;

// Definición de la clase Paciente
class Paciente
{
public:
    int tension_arterial;
    int frecuencia_cardiaca;
    string diagnostico;

    Paciente(int tension_arterial, int frecuencia_cardiaca, string diagnostico)
        : tension_arterial(tension_arterial), frecuencia_cardiaca(frecuencia_cardiaca), diagnostico(diagnostico) {}
};

// Definición de la clase Nodo del quad tree
class Nodo
{
public:
    int x_min, y_min, x_max, y_max;
    vector<Paciente *> pacientes;
    Nodo *hijos[4];

    Nodo(int x_min, int y_min, int x_max, int y_max)
        : x_min(x_min), y_min(y_min), x_max(x_max), y_max(y_max)
    {
        for (int i = 0; i < 4; i++)
        {
            hijos[i] = NULL;
        }
    }

    ~Nodo()
    {
        for (int i = 0; i < 4; i++)
        {
            delete hijos[i];
        }
    }

    // Función para insertar un paciente en el quad tree
    void insertar(Paciente *paciente)
    {
        if (paciente->tension_arterial < x_min || paciente->tension_arterial > x_max ||
            paciente->frecuencia_cardiaca < y_min || paciente->frecuencia_cardiaca > y_max)
        {
            return; // El paciente no cae dentro de la región de este nodo
        }
        pacientes.push_back(paciente);
        if (hijos[0] == NULL)
        {
            // Este nodo no tiene hijos aún, por lo que dividimos la región en cuatro hijos
            int x_med = (x_min + x_max) / 2;
            int y_med = (y_min + y_max) / 2;
            hijos[0] = new Nodo(x_min, y_min, x_med, y_med);
            hijos[1] = new Nodo(x_med + 1, y_min, x_max, y_med);
            hijos[2] = new Nodo(x_min, y_med + 1, x_med, y_max);
            hijos[3] = new Nodo(x_med + 1, y_med + 1, x_max, y_max);
        }
        // Insertamos el paciente en el hijo correspondiente
        for (int i = 0; i < 4; i++)
        {
            hijos[i]->insertar(paciente);
        }
    }

    // Función para buscar el nodo correspondiente a un paciente dado su tensión arterial y frecuencia cardiaca
    Nodo *buscar(int x, int y)
    {
        if (x < x_min || x > x_max || y < y_min || y > y_max)
        {
            return NULL; // El paciente no cae dentro de la región de este nodo
        }
        if (pacientes.size() > 0)
        {
            return this; // Encontramos un nodo con pacientes en su lista
        }
        // Buscamos en los hijos
        Nodo *nodo = NULL;
        for (int i = 0; i < 4; i++)
        {
            Nodo *hijo = hijos[i]->buscar(x, y);
            if (hijo != NULL)
            {
                if (nodo == NULL || hijo->pacientes.size() > nodo->pacientes.size())
                {
                    nodo = hijo; // Actualizamos el nodo si encontramos uno con más pacientes
                    return nodo;
                }
            }
        }
    }
};

int main()
{
    Nodo *raiz = new Nodo(0, 0, 100, 200);
    // Creamos algunos pacientes de prueba
    Paciente *p1 = new Paciente(80, 150, "Hipertensión");
    Paciente *p2 = new Paciente(30, 100, "Arritmia");
    Paciente *p3 = new Paciente(70, 180, "Hipertensión");
    Paciente *p4 = new Paciente(20, 50, "Normal");
    Paciente *p5 = new Paciente(90, 120, "Hipertensión");

    // Insertamos los pacientes en el quad tree
    raiz->insertar(p1);
    raiz->insertar(p2);
    raiz->insertar(p3);
    raiz->insertar(p4);
    raiz->insertar(p5);

    // Buscamos el nodo correspondiente a un paciente dado su tensión arterial y frecuencia cardiaca
    Nodo *nodo_paciente = raiz->buscar(80, 150);

    // Imprimimos el diagnóstico del paciente encontrado
    if (nodo_paciente != NULL && nodo_paciente->pacientes.size() > 0)
    {
        cout << "El paciente tiene diagnóstico de " << nodo_paciente->pacientes[0]->diagnostico << endl;
    }
    else
    {
        cout << "No se encontró ningún paciente con las características buscadas." << endl;
    }

    // Liberamos la memoria asignada
    delete raiz;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}