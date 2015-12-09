#include "textbox.hpp"
#include "pixel.hpp"
#include <vector>
Textbox::Textbox(int px, int py, int sizex, int sizey, 
  const Pixel & borderstyle) {
  px_ = px;
  py_ = py;
  sizex_ = sizex;
  sizey_ = sizey;
  init_img(borderstyle);
  
  //1. Manually Initialize imgcontainer
  //2. Manually Initialize gameobject
}
Textbox::Textbox(int px, int py, int sizex, int sizey){
  border_enabled = false;
  px_ = px;
  py_ = py;
  sizex_ = sizex;
  sizey_ = sizey;
  Pixel p;
  init_img(p);
}

void Textbox::init_img(const Pixel & border){
  //Creates an image filled with spaces and with a border

  for(int y = 0; y < sizey_; ++y){
    std::vector<Pixel> v;
    for(int x = 0; x < sizex_; ++x){
      if(x == 0 || y == 0 || x == sizex_-1 || y == sizey_-1 && border_enabled){
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

void Textbox::add_row(std::string newrow){
  //Add in the new row to the vector
  update_area();
  //std::cout << "new go " << std::endl;
  if(rows_.size() >= max_rows_){
    rows_.erase(rows_.begin());
    rows_.push_back(newrow);
  }
  else{
    rows_.push_back(newrow);
  }
  //std::cout << "Put the new row in place" << std::endl;
  //Generate a new image from the stored rows
  int py =  offset_up;
  for(int i = 0; i < rows_.size(); ++i){
    //std::cout << "Next row... " << std::endl;
    int px =  offset_left;
    std::string tempstr = rows_[i];
    //std::cout << tempstr << std::endl;
    while (px <= max_cols_){
      //std::cout << "Next pixel..." << std::endl;
      if(tempstr.length() > 1){
	std::string s;
	s+= tempstr[0];
	tempstr.erase(tempstr.begin());
	s+= tempstr[0];
	tempstr.erase(tempstr.begin());
	Pixel p(s);
	//std::cout << "px " << px << std::endl;
	//std::cout << "py " << py << std::endl;
	//std::cout << "len " << tempstr << std::endl;
	img_.set_pixel(p, px, py);
      }
      //If uneven length add in the last char
      else if(tempstr.length() == 1){
	//std::cout << "Adding last char" << std::endl;
	std::string s;
	s += tempstr[0];
	tempstr.erase(tempstr.begin());
	s += ' ';
	Pixel p(s);
	img_.set_pixel(p, px, py);
      }
      else{
	Pixel p("  ");
	img_.set_pixel(p, px, py);
      }
      ++px;
    }
    ++py;
  }
  //std::cout << "Finished " << std::endl;
}

void Textbox::update_area(){
  max_rows_ = sizey_ - offset_up - offset_down;
  max_cols_ = sizex_ - offset_right - offset_left;
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


