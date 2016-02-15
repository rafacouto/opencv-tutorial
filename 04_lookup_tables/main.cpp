
// compilar con:
// g++ main.cpp $(pkg-config --libs opencv)

#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;

int main()
{
    // nombre del fichero
    char nombreImagen[] = "ivvi_684x684_gray.jpg";


    // cargar la imagen y comprobar que lo ha hecho correctamente
    cv::Mat imagen = cv::imread(nombreImagen);
    if (!imagen.data) {
        cout << "Error al cargar la imagen: " << nombreImagen << endl;
        exit(1);
    }

    // instanciar 3 matrices para los LUT
    cv::Mat lut1(1, 256, CV_8U);
    cv::Mat lut2(1, 256, CV_8U);
    cv::Mat lut3(1, 256, CV_8U);

    for (int i = 0; i < 256; i++) {
        lut1.at<uchar>(i) = 255 - i; // función inversa
        lut2.at<uchar>(i) = pow(255.0 * i, 0.5); // función raíz cuadrada
        lut3.at<uchar>(i) = pow(i, 3.0) / (255 * 255); // función cúbica
    }

    // aplicar los distintos LUT a la imagen original
    cv::Mat img1, img2, img3;
    cv::LUT(imagen, lut1, img1);
    cv::LUT(imagen, lut2, img2);
    cv::LUT(imagen, lut3, img3);

    // mostrar la imagen original
    cv::imshow("Original", imagen);

    // mostrar la imagen en negativo
    cv::imshow("Negativo", img1);

    // mostrar la imagen con función raíz cuadrada
    cv::imshow("Raiz cuadrada", img2);

    // mostrar la imagen con función cúbica
    cv::imshow("Cubica", img3);

    // esperar a pulsar una tecla
    cvWaitKey(0);
    return 0;
}

// vim: tw=78:sw=4:ts=4:et
