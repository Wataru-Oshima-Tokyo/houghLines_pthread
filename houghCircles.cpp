#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <pthread.h>
#include <time.h>
#include <string.h>
using namespace cv;
using namespace std;
struct timespec start, stop;
double fstart, fstop;
int main(int argc, char** argv)
{

    int NUM_THREADS =8;
    int videoNum=0;
    //imshow("frame100", src);
    if(argc>=2 )
    {
        try
        {
            videoNum = atoi(argv[1]);
            NUM_THREADS =atoi(argv[2]);
        }
        catch(const std::exception& e)
        {
        std::cerr << e.what() << '\n';
        return -1;
        }
    }
    const char* filename = argc >=2 ? argv[1] : "../data/smarties.png";
    // Loads an image
    VideoCapture cap;
    cap.open(videoNum);
    if( !cap.isOpened() )
    {
        std::cerr << "***Could not initialize capturing...***\n";
        std::cerr << "Current parameter's value: \n";
        return -1;
    }
    while(1){
        Mat src;
        cap>>src;
        // Check if image is loaded fine
        if(src.empty()){
            printf(" Error opening image\n");
            // printf(" Program Arguments: [image_name -- default %s] \n", default_file);
            return -1;
        }
        clock_gettime(CLOCK_MONOTONIC, &start); fstart=(double)start.tv_sec + ((double)start.tv_nsec/1000000000.0);

        Mat gray;
        cvtColor(src, gray, COLOR_BGR2GRAY);
        medianBlur(gray, gray, 5);
        vector<Vec3f> circles;
        HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
                    gray.rows/16,  // change this value to detect circles with different distances to each other
                    10, 30, 1, 30 // change the last two parameters
                // (min_radius & max_radius) to detect larger circles
        );
        for( size_t i = 0; i < circles.size(); i++ )
        {
            Vec3i c = circles[i];
            Point center = Point(c[0], c[1]);
            // circle center
            circle( src, center, 1, Scalar(0,100,100), 3, LINE_AA);
            // circle outline
            int radius = c[2];
            circle( src, center, radius, Scalar(255,0,255), 3, LINE_AA);
        }
        clock_gettime(CLOCK_MONOTONIC, &stop); fstop=(double)stop.tv_sec + ((double)stop.tv_nsec/1000000000.0);
        
        string str = "The FPS is " + to_string(1/(fstop-fstart));
        putText(src,str,cv::Point(50,50),cv::FONT_HERSHEY_DUPLEX,1,cv::Scalar(0,255,0),2,false);
        imshow("detected circles", src);
        
        waitKey(3);
        // pthread_exit(NULL);
    
     }


    return 0;
}
