/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

/// @file Parser.hpp
#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <iostream>
#include <libconfig.h++>

#include "RayTracer/Scene/Scene.hpp"

namespace rtr {

    /// @class Parser
    /// @brief Class dedicated to the parsing of configuration files and command-line arguments.
    class Parser {

        public:

            /// @brief Parses command-line arguments.
            /// @param filePath The path to the configuration file.
            /// @return 0 on success, 1 on failure.
            static int parseArgs(const std::string &filePath);

            /// @brief Parses a configuration file and returns a Scene object.
            /// @param filePath The path to the configuration file.
            /// @return A unique_ptr to a Scene object.
            static std::unique_ptr<rtr::Scene> parseFile(const std::string &filePath);

            /// @brief Parses the renderer settings from a configuration file.
            /// @param renderer The renderer settings in the configuration file.
            /// @param scene The Scene object to update with the parsed settings.
            static void parseRenderer(const libconfig::Setting &renderer, Scene &scene);

            /// @brief Parses the camera settings from a configuration file.
            /// @param camera The camera settings in the configuration file.
            /// @param scene The Scene object to update with the parsed settings.
            static void parseCamera(const libconfig::Setting &camera, Scene &scene);

            /// @brief Parses the shape type from a string.
            /// @param type The shape type as a string.
            /// @return The parsed shape type.
            static ShapeType parseShapeType(const std::string &type);

            /// @brief Parses the shapes settings from a configuration file.
            /// @param shapesSetting The shapes settings in the configuration file.
            /// @param scene The Scene object to update with the parsed settings.
            static void parseShapes(const libconfig::Setting &shapesSetting, Scene &scene);

            /// @brief Parses the material settings from a configuration file.
            /// @param materialSetting The material settings in the configuration file.
            /// @return A unique_ptr to a Material object.
            static std::unique_ptr<AMaterial> parseMaterial(const libconfig::Setting &materialSetting);

            /// @brief Parses the light settings from a configuration file.
            /// @param type The light type as a string.
            /// @return The parsed light type.
            static LightType parseLightType(const std::string &type);

            /// @brief Parses the light settings from a configuration file.
            /// @param lightsSetting The lights settings in the configuration files.
            /// @param scene The Scene object to update with the parsed settings.
            static void parseLights(const libconfig::Setting &lightsSetting, Scene &scene);

            /// @brief Templated function to get a vector from a configuration file setting.
            /// @tparam T The type of the vector.
            /// @tparam ConversionFunc The function to convert the vector elements.
            /// @param setting The setting in the configuration file.
            /// @param convert The conversion function.
            /// @return The parsed vector.
            template <typename T, typename ConversionFunc>
            static T getVector(const libconfig::Setting &setting, ConversionFunc convert);

            /// @brief Templated function to convert an integer value from a configuration file setting.
            /// @tparam T The type of the value.
            /// @param setting The setting in the configuration file.
            /// @return The parsed value.
            template<typename T>
            static T convertInt(const libconfig::Setting &setting);

            /// @class ParserException
            /// @brief Exception class for errors in the parsers.
            class ParserException : public std::exception
            {
                public:
                    explicit ParserException(std::string msg) : m_msg{std::move(msg)} {}

                    ~ParserException() override = default;

                    ParserException(const ParserException &) = delete;
                    ParserException &operator=(const ParserException &) = delete;

                    ParserException(const ParserException &&) = delete;
                    ParserException &operator=(const ParserException &&) = delete;

                    /// @brief Returns the error message.
                    [[nodiscard]] const char *what() const noexcept override { return m_msg.c_str(); };

                private:
                    /// @brief The error message.
                    std::string m_msg{0};

        }; // class ParserException

    }; // class Parser

} // namespace RayTracer

#endif //RAYTRACER_PARSER_HPP
