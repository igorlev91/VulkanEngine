

#pragma once

#include <memory>

#include "engine.h"

class Texture
{
public:
    
    ~Texture() {}
    
    virtual bool Init(const uint width, const uint height, const void* data) = 0;
    virtual bool Init(const std::string& fileName) = 0;
    virtual bool Init(const unsigned char* data, int length) = 0;
    virtual bool Init(const uint width, const uint height, const uint rendererID) = 0;
    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual uint GetTextureSlot() const = 0;
    virtual void Resize(uint width, uint height) = 0;
    virtual void Blit(uint x, uint y, uint width, uint height, uint bpp, const void* data) = 0;
    virtual void Blit(uint x, uint y, uint width, uint height, int dataFormat, int type, const void* data) = 0;
    
    static std::shared_ptr<Texture> Create();
    static std::shared_ptr<Texture> Create(uint ID, int internalFormat, int dataFormat, int type);

};
