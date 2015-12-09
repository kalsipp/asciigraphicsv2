#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "pixel.hpp"
#include <string>
#include <vector>
#include "imgcontainer.hpp"

class Img_container;
class Gameobject{
public:
  Gameobject(Img_container & img, int px = 0, int py = 0, int depth = 0);
  Gameobject(std::string file, int px = 0, int py = 0);
  const Img_container & get_img() const;
  void set_img(const Img_container & img);
  //void set_pixel(const Pixel & p, int px, int py);
  //void clear_img();
  int sizex_; //Only rects allowed
  int sizey_;
  int px_;
  int py_;
  int depth_= 0;
private:
protected:

  Gameobject();
  Img_container img_;
  //std::vector<std::vector<Pixel>> img_;
  
};

#endif
