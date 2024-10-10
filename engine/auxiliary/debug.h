

#pragma once
#include "glm.hpp"

class Debug
{
public:
    static void PrintMat4(const std::string& name, const glm::mat4& matrix)
    {
        std::cout << name << std::endl;
        for (int column = 0; column < 4; column++)
        {
            for (int row = 0; row < 4; row++)
            {
                std::cout << matrix[column][row] << " ";
            }
            std::cout << std::endl;
        }
    }

    static void PrintVec3(const std::string& name, const glm::vec3& vector)
    {
        std::cout << name << std::endl;
        for (int row = 0; row < 3; row++)
        {
            std::cout << vector[row] << std::endl;
        }
    }

    static void PrintVec4(const std::string& name, const glm::vec4& vector)
    {
        std::cout << name << std::endl;
        for (int row = 0; row < 4; row++)
        {
            std::cout << vector[row] << std::endl;
        }
    }
};
