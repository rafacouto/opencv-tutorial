
// compilar con:
// g++ main.cpp $(pkg-config --libs opencv)

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;

int main()
{
    // nombre de la imagen que se va a cargar
    char nombreImagen[] = "ivvi_684x684_gray.jpg";

    // cargar la imagen y comprobar que lo ha hecho correctamente
    cv::Mat imagen = cv::imread(nombreImagen);
    if (!imagen.data) {
        cout << "Error al cargar la imagen: " << nombreImagen << endl;
        exit(1);
    }

    // instanciar color como vector RGB
    cv::Vec3b color = cv::Vec3b(0, 255, 0); // verde puro

    // fijar el máximo de X e Y a 3/4 de cada eje
    int maxX = imagen.cols * 3 / 4;
    int maxY = imagen.rows * 3 / 4;

    // dibujar un rectangulo desde 1/4 a 3/4 de cada eje
    for (int x = imagen.rows / 4; x < maxX; x++) {
        for (int y = imagen.cols / 4; y < maxY; y++) {

            // acceso al pixel en x,y para cambiarlo
            imagen.at<cv::Vec3b>(cv::Point(x,y)) = color;
        }
    }

    // mostrar la imagen
    cv::namedWindow("02", CV_WINDOW_AUTOSIZE);
    cv::imshow("02", imagen);

    // guardar el resultado
    cv::imwrite("resultado.jpg", imagen);

    // esperar a pulsar una tecla para salir
    cvWaitKey(0);
    return 0;
}


// vim: tw=78:sw=4:ts=4:et
