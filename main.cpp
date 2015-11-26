#include "textgraphics.hpp"
#include "imgcontainer.hpp"
#include <string>
#include <vector>
#include <unistd.h> 
int main(){
  Textgrafs p;
  p.clear_screen();
  Img_container i("img_output");
  p.add_image(i.get_img(), 20,5);
  p.print();
  
  float px = 0;
  float py = 0;
  float sx = 0.00001;
  float sy = 0.00001;
  while(1){
    p.clear_grid();
    px += sx;
    py += sy;
    //p.add_image(i.get_img(),20, 10);
    p.print();
  }


}
