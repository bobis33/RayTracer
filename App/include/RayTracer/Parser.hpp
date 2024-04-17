/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include "Scene.hpp"

namespace RayTracer {

    struct Material_t {
        std::string name;
        std::tuple<u_int8_t, u_int8_t, u_int8_t> color{0, 0, 0};
    };

    struct Light_t {
        std::tuple<u_int16_t, u_int16_t, u_int16_t> position{0, 0, 0};
        u_int8_t intensity{0};
    };

    struct Plane_t {
        std::string material;
        std::tuple<u_int16_t, u_int16_t, u_int16_t> position{0, 0, 0};
    };

    struct Sphere_t {
        std::string material;
        std::tuple<u_int16_t, u_int16_t, u_int16_t> position{0, 0, 0};
        u_int16_t radius{0};
    };

    struct Cylinder_t {
        std::string material;
        std::tuple<u_int16_t, u_int16_t, u_int16_t> position{0, 0, 0};
        u_int8_t radius{0};
        u_int16_t height;
    };

    struct Cone_t {
        std::string material;
        std::tuple<u_int16_t, u_int16_t, u_int16_t> position{0, 0, 0};
        u_int8_t radius{0};
        u_int16_t height;
    };

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

        }; // ParserException

    }; // Parser

} // namespace RayTracer

#endif //RAYTRACER_PARSER_HPP
