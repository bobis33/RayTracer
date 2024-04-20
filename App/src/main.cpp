/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** main.cpp
*/

#include "RayTracer/Core.hpp"
#include "RayTracer/Parser.hpp"
#include "RayTracer/Exceptions/RuntimeException.hpp"

static constexpr char const * USAGE_MSG = "USAGE\n"
                                          "\t./raytracer <SCENE_FILE>\n"
                                          "SCENE_FILE\n"
                                          "\tscene configuration";

using namespace RayTracer;

int main(int argc, const char * argv[])
{
    try {
        if (argc != 2) {
            throw Parser::ParserException{USAGE_MSG};
        } if (Parser::parseArgs(argv[1]) == ERROR) {
            return SUCCESS;
        }
        Core::runRayTracer(*Parser::parseFile(argv[1]));
    } catch (const Parser::ParserException &e) {
        std::cerr <<"Parser exception: "<< e.what() << '\n';
        return EPITECH_ERROR;
    } catch (const Core::CoreException &e) {
        std::cerr <<"Core exception: " << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (const RunTimeException &e) {
        std::cerr << "Runtime exception: " << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (...) {
        std::cerr <<"Unknow error"<< '\n';
        return EPITECH_ERROR;
    }
}
