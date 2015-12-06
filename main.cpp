#include "textgraphics.hpp"
#include "imgcontainer.hpp"
#include "pixel.hpp"
#include "textbox.hpp"
#include <string>
#include <vector>
#include <unistd.h> 
int main(){
  Textgrafs p;
  p.clear_screen();
  /*
  Img_container i("img_output");
  p.add_image(i.get_img(), 50,5);
  p.add_image(i.get_img(), -20, 0);
  Pixel h(20);
  p.add_pixel(h, 30, 30);
  p.add_pixel(h, 30, 20);
  p.add_border(h, 0, 0, 5, 5);
  //p.clear_grid_specific(0,0, 10, 10);
  //p.fill_grid(h);
  */
  Pixel pix(40);
  Textbox tb(5, 5, 10, 10, pix);
  p.add_image(tb.get_img(), tb.px_, tb.py_);
  p.print();

}
/*

 

Intro
   unique
Main Game
   1. Define scene, render background and enemies
   2. Wait for user input
   3. Interpret user input
   4. Act out user input
   5. Act out world
   6. End turn



*/
