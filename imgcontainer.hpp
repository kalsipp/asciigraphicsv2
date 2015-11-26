#ifndef IMGCONTAINER_HPP
#define IMGCONTAINER_HPP

#include <string>
#include <vector>

class Img_container{
 public:
  Img_container(std::string filename);
  std::vector<std::vector<std::string>> & get_img();
  void print_img(); //To be removed post debug
 private:
  std::vector<std::vector<std::string>> img_txt;
  void img_to_str_vector(std::string filename, std::vector<std::vector<std::string>> & im_text_ref);
};


#endif
