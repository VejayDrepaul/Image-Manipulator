#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <unistd.h>
#include <string>

void show_image(std::string image_file);

int main(int argc, char *argv[])
{
    int c;

    while((c = getopt(argc, argv, "fgbc:")) != 1) {
        switch(c) {
            case 'f':
                show_image(std::string(argv[2]));
                break;
            case 'g':
                break;
            default:
                abort();
                break;
        }
    }
    show_image(std::string(argv[1]));
    return 0;
}

void show_image(std::string image_file) {
    cv::Mat image = cv::imread(image_file, cv::IMREAD_UNCHANGED);

    if(image.empty()) {
        std::cout << "Could not read image: " << image_file << std::endl;
    }

    cv::imshow("Display Window", image);
    int k = cv::waitKey(0);
    if(k == 's') {
        cv::imwrite(image_file, image);
    }
}
