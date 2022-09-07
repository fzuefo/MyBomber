/*
** EPITECH PROJECT, 2022
** B-YEP-400-LYN-4-1-indiestudio-abdelkarim.bengrine
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

namespace Error
{
    class Error : public std::exception {
        public:
            Error(const std::string &error_desc);
            ~Error();
            const char *what() const noexcept override;

        protected:
            const std::string _error_desc;
    };
}

#endif /* !ERROR_HPP_ */
