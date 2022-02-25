
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <pthread.h>
#include <time.h>
using namespace cv;
using namespace std;
struct timespec start, stop;
double fstart, fstop;

struct arg_struct {
    size_t num_lines;
    int index;
    // vector<Vec2f> lines;
    int num_threads;
    // Mat cdst;
};
Mat dst, cdst, cdstP;
vector<Vec2f> _lines;
void *DrawLines(void *arguments) // function that finds the maximum prime number smaller than Number
{
  //  struct arg_struct *args = arguments;
   size_t num_lines = ((struct arg_struct*)arguments)->num_lines;
   int idx = ((struct arg_struct*)arguments)->index;
   int NUM_THREADS = ((struct arg_struct*)arguments)->num_threads;
  //  Mat cdst = ((struct arg_struct*)arguments)->cdst;
  //  vector<Vec2f> lines = ((struct arg_struct*)arguments)->lines;
  //  long idx = (long)threadid;
   size_t startval = (idx*(num_lines/NUM_THREADS))+1;
   size_t endval = (idx*(num_lines/NUM_THREADS))+(num_lines/NUM_THREADS);
   for(size_t k= startval; k<endval; k++){
      float rho = _lines[k][0],theta = _lines[k][1];; 
      Point pt1, pt2;
      double a = cos(theta), b = sin(theta);
      double x0 = a*rho, y0 = b*rho;
      pt1.x = cvRound(x0 + 1000*(-b));
      pt1.y = cvRound(y0 + 1000*(a));
      pt2.x = cvRound(x0 - 1000*(-b));
      pt2.y = cvRound(y0 - 1000*(a));
      line(cdst, pt1, pt2, Scalar(0,0,255), 3, LINE_AA);
      //check if it is the prime number
   }

    // Probabilistic Line Transform
    vector<Vec4i> linesP; // will hold the results of the detection
    HoughLinesP(dst, linesP, 1, CV_PI/180, 50, 50, 10 ); // runs the actual detection
    // Draw the lines
    for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        line( cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
    }

       // Draw the lines
    // for( size_t i = 0; i < lines.size(); i++ )
    // {

    // }

    // printf("idex:  %d\n", idx);
    // printf("startval: %zu\n", startval);
    // printf()
    // printf("endval%zu\n", endval);
   return 0;
}







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

  VideoCapture cap;
  cap.open(videoNum);
  if( !cap.isOpened() )
  {
      std::cerr << "***Could not initialize capturing...***\n";
      std::cerr << "Current parameter's value: \n";
      return -1;
  }
  while(1){
    // Declare the output variables

    // const char* default_file = "../data/sudoku.png";
    // const char* filename = argc >=2 ? argv[1] : default_file;
    // Loads an image
    // Mat src = imread( filename, IMREAD_GRAYSCALE );
    Mat src;
    cap>>src;
    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        // printf(" Program Arguments: [image_name -- default %s] \n", default_file);
        return -1;
    }
    clock_gettime(CLOCK_MONOTONIC, &start); fstart=(double)start.tv_sec + ((double)start.tv_nsec/1000000000.0);
    // Edge detection
    Canny(src, dst, 50, 200, 3);
    // Copy edges to the images that will display the results in BGR
    cvtColor(dst, cdst, COLOR_GRAY2BGR);
    cdstP = cdst.clone();
    // Standard Hough Line Transform
    vector<Vec2f> lines; // will hold the results of the detection
    HoughLines(dst, lines, 1, CV_PI/180, 100, 0, 0 ); // runs the actual detection

    /*

`     HoughLines(image, lines, rho, theta, threshold, minilinelength, maxlinegap );
      image	          8-bit, single-channel binary source image. The image may be modified by the function.
      lines  	        Output vector of lines. Each line is represented by a 4-element vector (x1,y1,x2,y2) , where (x1,y1) and (x2,y2) are the ending points of each detected line segment.
      rho	            Distance resolution of the accumulator in pixels.
      theta 	        Angle resolution of the accumulator in radians.
      threshold	      Accumulator threshold parameter. Only those lines are returned that get enough votes ( >𝚝𝚑𝚛𝚎𝚜𝚑𝚘𝚕𝚍 ).
      minLineLength	  Minimum line length. Line segments shorter than that are rejected.
      maxLineGap	    Maximum allowed gap between points on the same line to link them.


    */

    // ------------------------ start of multiple threads ---------------------------------------------


      pthread_t threads[NUM_THREADS];
      int rc;
      int i;
      _lines =lines;
      for( i = 0; i < NUM_THREADS; i++ ) {
        //  args = malloc(sizeof(struct arg_struct) * 1);
         struct arg_struct *args = (struct arg_struct *)malloc(sizeof(struct arg_struct));

         args->index = i;
         args->num_lines =lines.size(); 
        // cout << lines[0][0] << endl;
        if(lines.size()>0)
          //  args->lines = lines;
         args->num_threads = NUM_THREADS;
        //  args->cdst = cdst;
        //  cout << "main() : creating thread, " << i << endl;
         rc = pthread_create(&threads[i], NULL, DrawLines, args);
         
         if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
         }
      }
      
      for(int i=0; i<NUM_THREADS;i++)
         pthread_join(threads[i], NULL);
      


    //--------------------- end of multiple threads ------------------------

    //-------------------- single Thread from here -------------------------
    // Draw the lines
    // for( size_t i = 0; i < lines.size(); i++ )
    // {
    //     float rho = lines[i][0], theta = lines[i][1];
    //     Point pt1, pt2;
    //     double a = cos(theta), b = sin(theta);
    //     double x0 = a*rho, y0 = b*rho;
    //     pt1.x = cvRound(x0 + 1000*(-b));
    //     pt1.y = cvRound(y0 + 1000*(a));
    //     pt2.x = cvRound(x0 - 1000*(-b));
    //     pt2.y = cvRound(y0 - 1000*(a));
    //     line( cdst, pt1, pt2, Scalar(0,0,255), 3, LINE_AA);
    // }
    // // Probabilistic Line Transform
    // vector<Vec4i> linesP; // will hold the results of the detection
    // HoughLinesP(dst, linesP, 1, CV_PI/180, 50, 50, 10 ); // runs the actual detection
    // // Draw the lines
    // for( size_t i = 0; i < linesP.size(); i++ )
    // {
    //     Vec4i l = linesP[i];
    //     line( cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
    // }

    //-------------------------- end of single thread -----------------------


    //Show results
    clock_gettime(CLOCK_MONOTONIC, &stop); fstop=(double)stop.tv_sec + ((double)stop.tv_nsec/1000000000.0);
    printf("The FPS is %f\n", 1/(fstop-fstart));
    imshow("Source", src);
    imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
    imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
    // Wait and Exit
    waitKey(3);
    // pthread_exit(NULL);
    
  }
  return 0;
}
