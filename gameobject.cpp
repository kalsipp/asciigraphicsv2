#include "pixel.hpp"
#include <string>
#include <vector>
#include "gameobject.hpp"
#include "imgcontainer.hpp"
//#include <iostream>


Gameobject::Gameobject(Img_container & img, int px, int py, int depth):img_(img), px_(px), py_(py), depth_(depth){
  sizey_ = img_.img_txt.size();
  if(sizey_ != 0) sizex_ = img_.img_txt[0].size();
}

Gameobject::Gameobject(std::string file, int px, int py){
  px_ = px;
  py_ = py;
  img_.init_img(file);
  sizey_ = img_.img_txt.size();
  if(sizey_ != 0) sizex_ = img_.img_txt[0].size();
}
Gameobject::Gameobject(){}
const Img_container & Gameobject::get_img()const { return img_;}
void Gameobject::set_img(const Img_container & img){img_ = img;}
/*
void Gameobject::set_pixel(const Pixel & p, int px, int py){
  if(py < 0 || py > img_.size()) return;
  if(px < 0 || px > img_[py].size()) return;
  img_[py][px] = p; 
} 
void Gameobject::clear_img(){
  //While still keeping the old size this sets all pixels to spaces to visually clear it. Note that this does not make it transparent. 
  for(int y = 0; y < img_.size(); ++y){
    for(int x = 0; x < img_[y].size(); ++x){
      Pixel p("  "); //Visually empty pixel
      set_pixel(p, x,y);
    }
  }
}
*/
