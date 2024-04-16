/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Core.hpp
*/

#ifndef RAYTRACER_CORE_HPP
#define RAYTRACER_CORE_HPP

#include <memory>
#include <utility>

#include "RayTracer/Parser.hpp"
#include "RayTracer/Abstraction/IRenderer.hpp"

namespace RayTracer {

    class Core {
        public:
            Core() = default;
            ~Core() = default;

            void runRayTracer(const Scene &scene);

            class CoreException : public std::exception
            {
            public:
                explicit CoreException(std::string msg) : m_msg{std::move(msg)} {}
                ~CoreException() override = default;

                CoreException(const CoreException &) = delete;
                CoreException &operator=(const CoreException &) = delete;
                CoreException(const CoreException &&) = delete;
                CoreException &operator=(const CoreException &&) = delete;

                [[nodiscard]] const char *what() const noexcept override { return m_msg.c_str(); };

            private:
                std::string m_msg{0};

        }; // CoreException

        private:
            std::unique_ptr<IRenderer> m_renderer{nullptr};

    }; // Core

} // namespace RayTracer

#endif //RAYTRACER_CORE_HPP
