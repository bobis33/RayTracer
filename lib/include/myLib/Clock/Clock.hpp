/*
** EPITECH PROJECT, 2024
** lib
** File description:
** Clock.hpp
*/

#ifndef LIB_CLOCK_HPP
#define LIB_CLOCK_HPP

#include <chrono>

#include "myLib/Clock/Time.hpp"

/**
 * @brief TimePoint is a type alias for a time point which is a very long and complicated type in the standard library
 */
using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;


class Clock
    {

        public:
            /**
             * @brief Construct a new Clock object
             */
            Clock() { restart(); };

            ~Clock() = default;

            /**
             * @brief Restart the clock
             */
            void restart() { m_start = std::chrono::high_resolution_clock::now(); };

            /**
             * @brief Pause the clock
             */
            void pause();

            /**
             * @brief Resume the clock
             */
            void resume();
            
            /**
             * @brief Get the elapsed time since the last restart
             * 
             * @return Time The elapsed time
             */
            [[nodiscard]] Time getElapsedTime() const;

        private:
            TimePoint m_start;
            TimePoint m_pause;
            bool m_paused{false};

    }; // Clock


#endif // LIB_CLOCK_HPP
