
// compilar con:
// g++ main.cpp $(pkg-config --libs opencv)

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;

int main()
{
    // nombre de la imagen que se va a cargar
    char nombreImagen[] = "ivvi.jpg";

    // cargar la imagen y comprobar que lo ha hecho correctamente
    cv::Mat imagen = cv::imread(nombreImagen);
    if (imagen.empty())
    {
        cout << "Error al cargar la imagen: " << nombreImagen << endl;
        exit(1);
    }

    // mostrar la imagen
    cv::imshow("01", imagen);

    // esperar a pulsar una tecla para salir
    cvWaitKey(0);
    return 0;
}


// vim: tw=78:sw=4:ts=4:et
