#include "Buddhabrot.h"
using namespace std;

void Buddhabrot::gen_fractal()
{

   
	// Real (-2.5, 1)
	// Imaginary (-1, 1)
      int height = get_height();
      int width = get_width();
      int i, npixels = width * height;

      int pixArray[height][width];
      memset(pixArray, 0, npixels);

      for(i = 0; i < npixels; i++){
          int x = i%width;
          int y = i/width;
          double c_r = (((double) x)/width)*3.0-2.25;
          double c_i = (((double) y)/height)*3.0 - 1.5;

          double z_r = 0;
          double z_i = 0;
	  
	  int tempPixArray[height][width];
	  memset(tempPixArray, 0, npixels);

          int max_iter = 5000;
          int n = 1;
          while((pow(z_r,2) + pow(z_i, 2) < 4) && n < max_iter){
                double z_temp = pow(z_r,2) - pow(z_i,2) + c_r;
                z_i = z_r*2*z_i + c_i;
                z_r = z_temp;
		double p_x = ((z_r+2.25)*width)/3.0;
		double p_y = ((z_i+1.5)*height)/3.0;
		if(p_y  < 0 || p_x < 0 || p_y >= height || p_x >= width){
			n++;
			continue;
		}
		tempPixArray[(int)p_y][(int)p_x]++;
                n++;
          }
	  if(n == max_iter){
		continue;
          }

   /*             double zn = x*x + y*y;
              double nu = log(1/(2*log(zn))/log(2<<16))/log(2);
                n = n + 1 - nu;
                n = pow(n,2);*/
	for(int j = 0; j < height; j++){
		for(int k = 0; k < width; k++){
			pixArray[j][k] += tempPixArray[j][k];
		}
	}
	
     }

     int R, G ,B;
     for(int j = 0; j < height; j++){
		for(int k = 0; k < width;k++){	
			R = (pow((pixArray[j][k]),0.6));
			G = (pow((pixArray[j][k]),0.5));
                        B = (pow((pixArray[j][k]),0.4));

			m_bitmap[k*m_height*4 + j*4] = R;
        		m_bitmap[k*m_height*4 + j*4 + 1] = G;
         		m_bitmap[k*m_height*4 + j*4 + 2] = B;
         		m_bitmap[k*m_height*4 + j*4 + 3] = 255;

		}
     }
 /*       int R,G,B;
         R = (pow(((double)n/max_iter), 0.6)) *255;
         G = (pow(((double)n/max_iter), 0.3)) *255;
         B = (pow(((double)n/max_iter), 0.2)) *255; */
    // Initialize a bucket array (one integer for each pixel) (this is the outer bucket array)

    // iterate over the following several thousand times (at least more times than # of pixels)
  
        // Create a temporary bucket array (one integer for each pixel
        //
        // Let C be a random point in the complex plane
        //
        // Trace the orbit of C, incrementing the temporary bucket that z falls in for each iteration
        // If Z is in the mandelbrot set, discard the temporary bucket
        // Else, merge the temporary bucket with the outer bucket array
        

     // Normalize the global bucket array by dividing each value by the maximum value
     // Color each pixel however you wish
     //
     // Parallelizing this function is tricky. It helps to have a list of temporary bucket arrays
     // Which are merged after the computation has finished.
     
     // Parallelizing is not required, but will save you a lot of time.
     

}
    

