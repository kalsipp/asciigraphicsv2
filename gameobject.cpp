#include "pixel.hpp"
#include <string>
#include <vector>
//#include <iostream>
class Gameobject{
public:
  Gameobject(const std::vector<std::vector<Pixel>> & img, int px = 0, int py = 0, int sizex = 0, int sizey = 0);
  const std::vector<std::vector<Pixel>> & get_img() const;
  void set_img(const std::vector<std::vector<Pixel>> & img);
  void set_pixel(const Pixel & p, int px, int py);
  int sizex_; //Only rects allowed
  int sizey_;
  int px_;
  int py_;
private:
  std::vector<std::vector<Pixel>> img_;

};

Gameobject::Gameobject(const std::vector<std::vector<Pixel>> & img, int px, int py, int sizex, int sizey){
  px_ = px;
  py_ = py;
  if(sizey == 0)sizey == img.size(); //If you send in an empty image this object will not have any physical effect
  if(sizex == 0)sizex == img[0].size();
  sizey_ = sizey;
  img_ = img;
}
const std::vector<std::vector<Pixel>> & Gameobject::get_img()const { return img_;}
void Gameobject::set_img(const std::vector<std::vector<Pixel>> & img){
  img_ = img;
}
void Gameobject::set_pixel(const Pixel & p, int px, int py){
  img_[py][px] = p; 
} 
