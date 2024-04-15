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

namespace RayTracer {

    enum class PrimitiveType : u_int8_t {
        SPHERE,
        PLANE,
        CYLINDER,
        CONE,
        NONE
    };

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

    struct Primitive_t {
        Primitive_t() {}
        ~Primitive_t() {}
        Material_t material;
        PrimitiveType type{PrimitiveType::NONE};
        union {
            Sphere_t sphere;
            Plane_t plane;
            Cylinder_t cylinder;
            Cone_t cone;
        };
    };

    struct Camera_t {
        std::tuple<u_int16_t, u_int16_t, u_int16_t> position{0, 0, 0};
        u_int16_t fov{0};
    };

    struct Scene {
        std::string fileName;
        std::pair<u_int16_t, u_int16_t> resolution{1920, 1080};
        Camera_t camera;
        std::vector<Material_t> materials;
        std::vector<Primitive_t> primitives;
        std::vector<Light_t> lights;
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
