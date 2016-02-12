
// compilar con:
// g++ main.cpp $(pkg-config --libs opencv)

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;

int main()
{
	// nombre del fichero
	char nombreImagen[] = "loros.jpg";

	// cargar la imagen y comprobar que lo ha hecho correctamente
    cv::Mat src = cv::imread(nombreImagen);
	if (src.empty()) {
		cout << "Error al cargar la imagen: " << nombreImagen << endl;
		exit(1);
	}

	/// separar la imagen en 3 planos (RGB)
	vector<cv::Mat> bgr_planes;
    cv::split(src, bgr_planes);

	// variables para el histograma
	int histSize = 256;

	/// los rangos RGB
	const float range[] = { 0, 255 };
	const float* histRange = { range };

	bool uniform = true;
	bool accumulate = false;

    // matrices para histogramas RGB
    cv::Mat r_hist, g_hist, b_hist;

	// calcular histogramas RGB
    cv::calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
    cv::calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    cv::calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);

    // salida estándar con el histograma B
	cout << "hist: " << b_hist << endl;

	// imagen para histograma RGB
	const int hist_w = 512;
    const int hist_h = 400;
    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));

	/// normalizar el resultado a [ 0, histImage.rows ]
	normalize(r_hist, r_hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());
	normalize(b_hist, b_hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());
	normalize(g_hist, g_hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());

    // salida estándar con el histograma B normalizado
	cout << "hist: " << b_hist << endl;

    // colores RGB
    const cv::Scalar red(255, 0, 0);
    const cv::Scalar green(0, 255, 0);
    const cv::Scalar blue(0, 0, 255);

	/// dibujar para cada canal RGB
	int bin_w = cvRound((double)hist_w / histSize);
	for (int i = 1; i < histSize; i++) {

        // calcular X
        cv::Point from(bin_w * (i - 1), 0);
        cv::Point to(bin_w * (i), 0);

        // calcular Y para componente R y dibujar línea
        from.y = hist_h - cvRound(r_hist.at<float>(i - 1));
        to.y = hist_h - cvRound(r_hist.at<float>(i));
        cv::line(histImage, from, to, red, 2, 8, 0);

        // calcular Y para componente G y dibujar línea
        from.y = hist_h - cvRound(g_hist.at<float>(i - 1));
        to.y = hist_h - cvRound(g_hist.at<float>(i));
        cv::line(histImage, from, to, green, 2, 8, 0);

        // calcular Y para componente B y dibujar línea
        from.y = hist_h - cvRound(b_hist.at<float>(i - 1));
        to.y = hist_h - cvRound(b_hist.at<float>(i));
        cv::line(histImage, from, to, blue, 2, 8, 0);
	}

	// mostrar imagen
    cv::namedWindow("Imagen", CV_WINDOW_AUTOSIZE);
    cv::imshow("Imagen", src);

    // mostrar histograma
    cv::namedWindow("Histograma", CV_WINDOW_AUTOSIZE);
    cv::imshow("Histograma", histImage);

	// esperar a pulsar una tecla
	cvWaitKey(0);
	return 0;
}

// vim: tw=78:sw=4:ts=4:et
