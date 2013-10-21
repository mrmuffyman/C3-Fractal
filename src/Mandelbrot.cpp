#include "Mandelbrot.h"

void Mandelbrot::gen_fractal()
{
	// Real (-2.5, 1)
	// Imaginary (-1, 1)
      int height = get_height();
      int width = get_width();
//      cout << height << " " << width <<endl;
      int i, npixels = width * height;
      
//      int pixArray[height][width];
      
      for(i = 0; i < npixels; i++){
	  int x = i%width;
	  int y = i/width;
// 	  cout << x << " " << y << endl;
	  double c_r = (((double) x)/width)*3.0-2.25;
	  double c_i = (((double) y)/height)*3.0 - 1.5;
	
	  double z_r = 0; 
	  double z_i = 0;

	  int max_iter = 1000;
	  int n = 1;
	  while((pow(z_r,2) + pow(z_i, 2) < 4) && n < max_iter){
		double z_temp = pow(z_r,2) - pow(z_i,2) + c_r;
		z_i = z_r*2*z_i + c_i;
		z_r = z_temp;
		n++;
	  }
	 int R = (pow(((double)n/max_iter), 0.6)) *255;
	 int G = (pow(((double)n/max_iter), 0.5)) *255;
         int B = (pow(((double)n/max_iter), 0.4)) *255;
	 cout << "R:" << R << " G:" << G << " B:" << B <<endl;
	 
	 m_bitmap[x*m_height*4 + y*4] = R;
	 m_bitmap[x*m_height*4 + y*4 + 1] = G;
	 m_bitmap[x*m_height*4 + y*4 + 2] = B;
	 m_bitmap[x*m_height*4 + y*4 + 3] = 255;
//	cout << m_bitmap[x*m_height*4 + y*4] <<endl;
     }

	  	
    // Iterate over each pixel and determine the corresponding complex coordinate (or several complex coordinates if you're anti-aliasing)
        

        // For each pixel, compute the corresponding complex coordinate C (or multiple sub-coordinates, for AA)   

        // let z_r and z_i be 0
        // Begin iterating... while z is not infinity and not too many iterations have passed...
        
            // Z = Z^2 + C
            // increment an iteration counter

        // Color each pixel...

}
