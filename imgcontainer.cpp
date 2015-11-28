//A class container for ascii images
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <streambuf>
#include "imgcontainer.hpp"  
Img_container::Img_container(std::string filename){
    img_to_str_vector(filename, img_txt);
}

std::vector<std::vector<std::string>> & Img_container::get_img(){
    return img_txt;
}
void Img_container::print_img(){
  //Debug purposes
  for(unsigned int y = 0; y< img_txt.size() ; ++y){
    for(unsigned int x = 0; x < img_txt[y].size(); ++x){
      std::cout << img_txt[y][x] << std::endl;
    }
  }
}


void Img_container::img_to_str_vector(std::string filename, std::vector<std::vector<std::string>> & im_text_ref){
    std::ifstream file(filename.c_str());
    std::vector<std::string> tempvec;
    std::string tempstr;
    while(std::getline(file, tempstr)){
      std::vector<std::string> tempvec;
      while(tempstr.length() > 12){ // > smallest length TODO
	//Go through this row, chop it up into induvidual "pixels" and add them to their proper place in the vectorvector
	std::string s;
	while(tempstr[0] != '@'){
	  if(tempstr[0] != '\n')s+= tempstr[0];
	  if(tempstr.length() == 0) break;
	  tempstr.erase(tempstr.begin());
	}
	
	tempvec.push_back(s);

	//As the strings may be of different length, the letter @ has been added to separate them. (\033 is difficult to compare)
	if(tempstr[0] == '@')tempstr.erase(tempstr.begin());
      }
      for(int i = 0; i < tempstr.length() ; ++i){
	if(tempstr[i] == '\n') tempstr.erase(i); 
      }
      //tempvec.push_back(tempstr);
      im_text_ref.push_back(tempvec);
    } 
    file.close();
  }
