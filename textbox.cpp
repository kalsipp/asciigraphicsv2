#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include "gameobject.hpp"
#include <string>
#include <vector>
class Gameobject;
class Textbox:public Gameobject{
  /*Textbox handles nicely formatted text output
The system will simply say "Add row" and the class will append the new text to the bottom, shift the text up and remove the oldest text. 

It's the handlers job not to print more than the textbox's capacity (vertically).

Horizontal overflow will be truncated.
No extra effects added from class
  */
public:
  Textbox(int px, int py, int sizex, int sizey, const Pixel & borderstyle);
  void add_row(std::string);
private:
  std::vector<std::string> rows_;
  void format_img();
  void init_img();
  int max_rows_ = 100; //As one pixel is two chars wide
  int max_cols_ = 100; //This one is twice the "cols" used in other files
};
Textbox::Textbox(int px, int py, int sizex, int sizey, 
  const Pixel & borderstyle) {
  init_img();
  px_ = px;
  py_ = py;
  sizex_ = sizex;
  sizey_ = sizey_;
  //1. Manually Initialize imgcontainer
  //2. Manually Initialize gameobject
}
void Textbox::init_img(){
  
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

#endif
