#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include "gameobject.hpp"
#include "pixel.hpp"
#include <string>
#include <vector>
//class Gameobject;
class Textbox:public Gameobject{
  /*Textbox handles nicely formatted text output
The system will simply say "Add row" and the class will append the new text to the bottom, shift the text up and remove the oldest text. 

It's the handlers job not to print more than the textbox's capacity (vertically).

Horizontal overflow will be truncated.
No extra effects added from class
  */
public:
  Textbox(int px, int py, int sizex, int sizey, const Pixel & borderstyle);
  Textbox(int px, int py, int sizex, int sizey);
  void add_row(std::string);
  void set_border_enabled(bool);
private:
  bool border_enabled = true;
  std::vector<std::string> rows_;
  void format_img();
  void init_img(const Pixel & border);
  void update_area();
  int max_rows_ = 100; //As one pixel is two chars wide
  int max_cols_ = 100; //This one is twice the "cols" used in other files
  int offset_left = 2; //nr of pixels
  int offset_right = 2;
  int offset_up = 2;
  int offset_down = 2;
};
#endif
