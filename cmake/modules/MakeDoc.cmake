find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.doxygen)
    doxygen_add_docs(doc
            App/include
            App/plugins/Light/Ambient/include
            App/plugins/Light/Directional/include
            App/plugins/Light/Point/include
            App/plugins/Material/Reflective/include
            App/plugins/Material/Transparent/include
            App/plugins/Renderer/PPM/include
            App/plugins/Renderer/SFML/include
            App/plugins/Shapes/Cone/include
            App/plugins/Shapes/Cylinder/include
            App/plugins/Shapes/Plane/include
            App/plugins/Shapes/Sphere/include
            ALL
    )
    add_custom_command(TARGET doc
            POST_BUILD
            WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}/latex
            COMMAND ${CMAKE_MAKE_PROGRAM} > /dev/null
            && ${CMAKE_COMMAND} -E copy
            ${DOXYGEN_OUTPUT_DIRECTORY}/latex/refman.pdf
            ${CMAKE_SOURCE_DIR}/doc/RayTracer.pdf
            BYPRODUCTS ${CMAKE_SOURCE_DIR}/doc/RayTracer.pdf
            VERBATIM
    )
else ()
    message(WARNING "Doxygen is necessary for docs")
endif ()