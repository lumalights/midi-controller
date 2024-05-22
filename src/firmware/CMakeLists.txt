add_executable(firmware
        main.cpp
        )

# pull in common dependencies
target_link_libraries(firmware pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(firmware)