#include "textbox.hpp"
#include "pixel.hpp"
#include <vector>
Textbox::Textbox(int px, int py, int sizex, int sizey, 
  const Pixel & borderstyle) {
  px_ = px;
  py_ = py;
  sizex_ = sizex;
  sizey_ = sizey_;
  init_img(borderstyle);
  
  //1. Manually Initialize imgcontainer
  //2. Manually Initialize gameobject
}
void Textbox::init_img(const Pixel & border){
  //Creates an image filled with spaces and with a border

  for(int y = 0; y < sizey_; ++y){
    std::vector<Pixel> v;
    for(int x = 0; x - sizex_; ++x){
      if(x == 0 || y == 0 || x == sizex_ || y == sizey_){
       v.push_back(border);
     }
     else{
       Pixel p("  ");
       v.push_back(p);
     }
   }
   img_.img_txt.push_back(v);
 }

}
/*
void Textbox::add_row(std::string newrow){
  if(rows_.size() > max_rows_){
    for(int i = 0; i < rows_.size()-1; ++i){
      rows_[i] = rows_[i+1];
    }
    rows_.erase(rows_.end()-1); //Needs testing
    rows_.push_back(newrow);
  }
  else{
    rows_.push_back(newrow);
  }
  clear_img();
  format_img();
}
void Textbox::format_img(){
  //1. Clear the old img and fill with space according to the defined space. DONE
  //Converts the strings into pixels (A mess since a pixel is tzwo chars
  //chews every char in a string and puts them in pairs, made into pixels put into image. 
  //If the chars is an uneven image the last char gets paired with a space. Should work.
  int px = 1;
  int y_offset = 0;
  int x_offset = 0;
  for(int y = 0; y < rows_.size(); ++y){
    std::string tempstr = rows_[y]; //copy I hope
    while(tempstr.length() > 1){ 
      std::string s;
      s += tempstr[0];
      tempstr.erase(0);
      s += tempstr[0];
      tempstr.erase(0);
      Pixel p(s);
      set_pixel(p, px+x_offset, y+y_offset);
      ++px;
    }
    if(tempstr.length() == 1){ //Dealing with the final item
      std::string s;
      s+= tempstr[0];
      s+= ' ';
      Pixel p(s);
      set_pixel(p, px+x_offset, y+y_offset);
    } 
  }
}

  */


