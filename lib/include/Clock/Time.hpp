/*
** EPITECH PROJECT, 2024
** lib
** File description:
** time.hpp
*/

#ifndef LIB_TIME_HPP
#define LIB_TIME_HPP

class Time
    {
        public:
            /**
             * @brief Construct a new Time object
             */
            explicit Time(double seconds) : m_seconds(seconds) {};

            /**
             * @brief Transform the time to seconds
             */
            [[nodiscard]] int asSeconds() const { return static_cast<int>(m_seconds); };

            /**
             * @brief Transform the time to milliseconds
             */
            [[nodiscard]] int asMilliseconds() const { return static_cast<int>(m_seconds * 1000); }
            
            /**
             * @brief Transform the time to microseconds
             */
            [[nodiscard]] int asMicroseconds() const { return static_cast<int>(m_seconds * 1000000); };

        private:
            double m_seconds{0.0F};

    }; // Time


#endif // LIB_TIME_HPP
