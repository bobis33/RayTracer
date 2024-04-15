find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.doxygen)
    doxygen_add_docs(doc
            App/include
            App/plugins/Renderer/include
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