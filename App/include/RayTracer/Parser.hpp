/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <iostream>
#include <libconfig.h++>

#include "RayTracer/Scene/Scene.hpp"

namespace RayTracer {

    class Parser {

        public:

            static int parseArgs(const std::string &filePath);
            static std::unique_ptr<RayTracer::Scene> parseFile(const std::string &filePath);

            static void parseRenderer(const libconfig::Setting &renderer, Scene &scene);
            static void parseCamera(const libconfig::Setting &camera, Scene &scene);
            static ShapeType parseShapeType(const std::string &type);
            static void parseShapes(const libconfig::Setting &shapesSetting, Scene &scene);
            static std::unique_ptr<AMaterial> parseMaterial(const libconfig::Setting &materialSetting);
            static void parseLights(const libconfig::Setting &lightsSetting, Scene &scene);

            template <typename T, typename ConversionFunc>
            static T getVector(const libconfig::Setting &setting, ConversionFunc convert);

            template<typename T>
            static T convertInt(const libconfig::Setting &setting);

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
