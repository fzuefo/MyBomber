/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Error
*/

#include "Error.hpp"

namespace Error
{
    Error::Error(const std::string &error_desc)
    : _error_desc(error_desc)
    {
        
    }

    Error::~Error()
    {

    }

    const char *Error::what() const noexcept
    {
        return _error_desc.c_str();
    }
}
