# DFT-and-DCT-of-the-image
Generates Fourier transformed image and cosine transformed image.


# function
## dft_idft_2d(converted:,original:,transMode)
  Creates a DFT image or IDFT image.
  
  ### Parameters
  * converted  
    A matrix of complex numbers that stores the transformed image.  
    <br>
    
  * original  
    A matrix of complex numbers that contains the images to be transformed.  
    <br>
    
  * transmode
      The key for deciding whether to perform a Discrete Fourier Transform or a Discrete Inverse Fourier Transform.  
      <br>
      
      
      
 ## dct_2d(converted:,original:)
  Creates a DCT image.
  
  ### Parameters
  * converted  
    A matrix of complex numbers that stores the transformed image.  
    <br>
    
  * original  
    A matrix of complex numbers that contains the images to be transformed.  
    <br>
   
 
# Requirement
The size of the input image must be N x N. (The value of N can be specified in `SIZE` in settings.h.)
