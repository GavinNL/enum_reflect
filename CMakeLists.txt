cmake_minimum_required(VERSION 3.10)

################################################################################
# The Project Name will the the name of the folder. Change it if you
# dont like it.
################################################################################
project( enum_reflect )
################################################################################


################################################################################
# Build the executable
#
################################################################################
set(outName              ${PROJECT_NAME})   # name of the library
set(srcFiles             "main.cpp"     )          # all the source files for this library
#-------------------------------------------------------------------------------
add_executable( ${outName} ${srcFiles} )

target_compile_features( ${outName}
                          PUBLIC
                              cxx_std_17)

################################################################################
