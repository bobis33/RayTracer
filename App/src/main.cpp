/*
** EPITECH PROJECT, 2024
** Raytracer | core
** File description:
** main.cpp
*/

#include "RayTracer/Core.hpp"
#include "RayTracer/Parser.hpp"
#include "RayTracer/Exception/RunTime.hpp"

using namespace rtr;

int main(int argc, const char * argv[])
{
    try {
        if (argc != 2) {
            throw Parser::ParserException{"USAGE\n"
                                          "\t./raytracer <SCENE_FILE>\n"
                                          "SCENE_FILE\n"
                                          "\tscene configuration"};
        } if (Parser::parseArgs(argv[1]) == ERROR) {
            return SUCCESS;
        }
        Core::runRayTracer(*Parser::parseFile(argv[1]));
        PluginLoader::getInstance().closePlugins();
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
        std::cerr <<"Unknown error"<< '\n';
        return EPITECH_ERROR;
    }
}
