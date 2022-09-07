/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** RaylibModelAnimationError
*/

#ifndef RAYLIBMODELANIMATIONERROR_HPP_
#define RAYLIBMODELANIMATIONERROR_HPP_

#include "Error.hpp"

namespace Error
{
    class RaylibModelAnimationError : public Error {
        public:
            RaylibModelAnimationError(const std::string &error_desc);
            ~RaylibModelAnimationError();
    };
}

#endif /* !RAYLIBMODELANIMATIONERROR_HPP_ */
