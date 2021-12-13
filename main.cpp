#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <string>

void show_image(std::string image_file);
void grayscale_image(std::string image_file);
void blur_image(std::string image_file);

int main(int argc, char *argv[])
{
    int c;

    while((c = getopt(argc, argv, "fbg:")) != 1) {
        switch(c) {
            case 'f':
                show_image(argv[1]); //std::string(argv[2])
                break;
            case 'b':
                blur_image(argv[1]);
                break;
            case 'g':
                grayscale_image(argv[1]);
                break;
            case '?':
                break;
            default:
                abort();
                break;
        }
    }
    return 0;
}

void show_image(std::string image_file) {
    cv::Mat image = cv::imread(image_file, cv::IMREAD_UNCHANGED);

    if(image.empty()) {
        std::cout << "Could not read image: " << image_file << std::endl;
    }

    cv::imshow(image_file, image);
    int k = cv::waitKey(0);
    if(k == 's') {
        cv::imwrite(image_file, image);
    }
}

void grayscale_image(std::string image_file) {
    cv::Mat image = cv::imread(image_file, cv::IMREAD_GRAYSCALE);



    if(image.empty()) {
        std::cout << "Could not read image: " << image_file << std::endl;
    }

    std::string window_name = image_file + " - Grayscaled";
    cv::imshow(window_name, image);
    int k = cv::waitKey(0);
    if(k == 's') {
        cv::imwrite(image_file, image);
    }
}

void blur_image(std::string image_file) {
    cv::Mat image = cv::imread(image_file, cv::IMREAD_UNCHANGED);

    if(image.empty()) {
        std::cout << "Could not read image: " << image_file << std::endl;
    }

    cv::blur(image, image, cv::Size(100, 100));

    cv::imshow(image_file, image);
    int k = cv::waitKey(0);
    if(k == 's') {
        cv::imwrite(image_file, image);
    }
}
