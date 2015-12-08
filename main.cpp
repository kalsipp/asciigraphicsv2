#include "textgraphics.hpp"
#include "imgcontainer.hpp"
#include "pixel.hpp"
#include "textbox.hpp"
#include <string>
#include <vector>
#include <unistd.h> 
int main(){

  //Initial setup
  Textgrafs p; //The graphical unit
  p.clear_screen(); //Empty the screen
  Img_container i("img_output"); //An image
  p.add_image(i.get_img(), 5,-5); //Add this image to GU
  Pixel pix(214); //A Pixel
  p.add_border(pix, 0, 0, p.cols_, p.rows_); //Create a border using this pixeltype
  p.add_fill(0 , p.rows_-5, p.cols_, 5); //Just fill area with spaces 
  Textbox tb(0, p.rows_-20, p.cols_, 15, pix); //Create a textbox, child to Gameobject
  tb.add_row("Hello fagit"); //Add text
  tb.add_row("I have come for your penis");
  p.add_gameobject(tb); //Now add this textbox to GU
  p.print(); //Print changes to screen
  //Showing use
  while(1){
    std::string s;
    p.cursorpos(1, p.rows_-4);  //Place the cursor at a nice spot
    getline(std::cin, s); //Read the input
    tb.add_row(s); //Add this row to the textbox. It will format correctly
    p.add_gameobject(tb); //Add this change
    p.print(); //Print 
  }
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
