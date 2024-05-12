/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Core.hpp
*/

/// @file Core.hpp
#ifndef RAYTRACER_CORE_HPP
#define RAYTRACER_CORE_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Scene/Scene.hpp"

namespace rtr {

    /// @class Core
    /// @brief A class representing the core functionality of the ray tracer.
    class Core {
        /// @file
        public:
            Core() = default;

            ~Core() = default;

            /// @brief Runs the ray tracer with a given Scene object.
            /// @param scene The Scene object used for ray tracing.
            static void runRayTracer(Scene &scene);

            /// @class CoreException
            /// @brief An exception class for core errors.
            class CoreException : public std::exception
            {
            public:
                explicit CoreException(std::string msg) : m_msg{std::move(msg)} {}

                ~CoreException() override = default;

                CoreException(const CoreException &) = delete;
                CoreException &operator=(const CoreException &) = delete;


                CoreException(const CoreException &&) = delete;
                CoreException &operator=(const CoreException &&) = delete;

                /// @brief Returns the error message.
                [[nodiscard]] const char *what() const noexcept override { return m_msg.c_str(); };

            private:
                /// @brief The error message.
                std::string m_msg{0};

            }; // CoreException

    }; // Core

} // namespace RayTracer

#endif //RAYTRACER_CORE_HPP
