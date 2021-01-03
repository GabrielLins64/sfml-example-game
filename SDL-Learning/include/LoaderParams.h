#ifndef __LoaderParams__
#define __LoaderParams__

#include <iostream>

class LoaderParams
{
public:

    LoaderParams(int _x, int _y, int _width, int _height, 
                 std::string _textureID) : x(_x), y(_y),
                 width(_width), height(_height),
                 textureID(_textureID)
    {
        
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::string getTextureID() const { return textureID; }

private:

    int x;
    int y;
    int width;
    int height;
    std::string textureID;
};

#endif /* defined(__LoaderParams__) */
