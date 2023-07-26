#! /bin/sh

function compile_dependencies
{
    if [[ `find submodules/glfw/ -name build` ]]; then
        echo "Found glfw build at $cwd/submodules/glfw/"
        return
    fi
    if [[ `find -name glfw` && ! `find submodules/glfw/ -name build` ]]; then
        pushd submodules/glfw
        mkdir build && cd build
        cmake .. && make -j4
        popd
    fi
}

function install
{
    git submodule update --init --recursive
    compile_dependencies
    mkdir build && cd build
    cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DBACKEND_CONTEXT=OPENGL && make -j4
    cd ..
}

install