cmake_minimum_required(VERSION 3.20)

function(set_target_cxx_standard target standard)
set_target_properties(
    ${target}
    PROPERTIES
        CXX_STANDARD ${standard}
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)
endfunction()

function(enable_target_cxx_warnings target)
    target_compile_options(
        ${target}
        PRIVATE
          -Wall
          -Wextra
          -Werror
          -Wundef
          -Wuninitialized
          -Wshadow
          -Wpointer-arith
          -Wcast-align
          -Wcast-qual
          -Wunused-parameter
          #-Wlogical-op
          -Wdouble-promotion
          #-Wduplicated-cond
          #-Wduplicated-branches
          -Wnull-dereference
    )
endfunction()
