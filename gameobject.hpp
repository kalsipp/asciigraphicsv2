#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "pixel.hpp"
#include <string>
#include <vector>
#include "imgcontainer.hpp"
class Gameobject{
public:
  Gameobject(const Img_container & img, int px = 0, int py = 0, int sizex = 0, int sizey = 0);
  const Img_container & get_img() const;
  void set_img(const Img_container & img);
  //void set_pixel(const Pixel & p, int px, int py);
  //void clear_img();
  int sizex_; //Only rects allowed
  int sizey_;
  int px_;
  int py_;
private:
protected:
  Img_container img_;
  //std::vector<std::vector<Pixel>> img_;
  
};
#endif
