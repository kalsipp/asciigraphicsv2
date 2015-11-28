#include "textgraphics.hpp"
#include "imgcontainer.hpp"
#include "pixel.hpp"
#include <string>
#include <vector>
#include <unistd.h> 
int main(){
  Textgrafs p;
  p.clear_screen();
  Img_container i("img_output");
  p.add_image(i.get_img(), 50,5);
  p.add_image(i.get_img(), -20, 0);
  Pixel h(20);
  p.add_pixel(h, 30, 30);
  p.add_pixel(h, 30, 20);
  p.add_border(h, 0, 0, 5, 5);
  //p.clear_grid_specific(0,0, 10, 10);
  //p.fill_grid(h);
  p.print();
  while(1){}

}
/*
Scene 1
set background color
add background image
add image 1
add image 2
add border around everything
add textbox border
write text //Need textsystem to easily print text
p.print()
write text
write text //These will print when added
set background image
set image 1
set image 2 different pos
p.print() shit this will clear the text.
A mess to set all things over and over again.
If I have defined rects which have defined position, size and depth these can be saved in textgrapgics. 
when textgraphics prints it goes through all depths -> adds the rects with that depth in whatever order -> print
Textbox is a rect, or a Gameobject!

Need to make a Gameobject class.
Gameobject has a pos, size, depth, and an image (2d vector of pixels
has a get image function which the graphics class will add and then print. 

Make textbox class
Textbox has a defined px, py, sizex, sizey and background color
has defined indention and offsets of text
has a function add text where it will nicely fit it the requested text into the box. Prints when added. 

Waiting etc is not handled by textbox. 
Only job is to give a single function add_text(String).

Has clear box, set background color, set foreground color
Border around is not its problem
 */
