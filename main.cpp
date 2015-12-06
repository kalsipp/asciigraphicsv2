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
  Img_container i("img_output");
  p.add_image(i.get_img(), 5,-5);
  //p.clear_grid_specific(0,0, 10, 10);
  //p.fill_grid(h);
  Pixel pix(214);

  p.add_border(pix, 0, 0, p.cols_, p.rows_);
  Textbox tb(0, p.rows_-20, p.cols_, 20, pix);
  tb.add_row("Hello fagit");
  tb.add_row("I have come for your penis");
  for(int i = 0; i < 0; ++i){
    tb.add_row("asdasf");
  }
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
