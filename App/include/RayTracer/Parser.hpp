/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <iostream>

#include "RayTracer/Scene/Scene.hpp"

namespace RayTracer {

    class Parser {

        public:

            static int parseArgs(const std::string &filePath);
            static Scene parseFile(const std::string &filePath);

            class ParserException : public std::exception
            {
                public:
                    explicit ParserException(std::string msg) : m_msg{std::move(msg)} {}
                    ~ParserException() override = default;

                    ParserException(const ParserException &) = delete;
                    ParserException &operator=(const ParserException &) = delete;
                    ParserException(const ParserException &&) = delete;
                    ParserException &operator=(const ParserException &&) = delete;

                    [[nodiscard]] const char *what() const noexcept override { return m_msg.c_str(); };

                private:
                    std::string m_msg{0};

        }; // class ParserException

    }; // class Parser

} // namespace RayTracer

#endif //RAYTRACER_PARSER_HPP
