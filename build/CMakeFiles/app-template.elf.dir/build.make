# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.20.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.20.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cristian/Documents/Development/iOLED/firmware/inti

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cristian/Documents/Development/iOLED/firmware/inti/build

# Include any dependencies generated for this target.
include CMakeFiles/app-template.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app-template.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app-template.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app-template.elf.dir/flags.make

project_elf_src_esp32.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/cristian/Documents/Development/iOLED/firmware/inti/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating project_elf_src_esp32.c"
	/usr/local/Cellar/cmake/3.20.5/bin/cmake -E touch /Users/cristian/Documents/Development/iOLED/firmware/inti/build/project_elf_src_esp32.c

CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj: CMakeFiles/app-template.elf.dir/flags.make
CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj: project_elf_src_esp32.c
CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj: CMakeFiles/app-template.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristian/Documents/Development/iOLED/firmware/inti/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj"
	/Users/cristian/.espressif/tools/xtensa-esp32-elf/esp-2021r1-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj -MF CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj.d -o CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj -c /Users/cristian/Documents/Development/iOLED/firmware/inti/build/project_elf_src_esp32.c

CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.i"
	/Users/cristian/.espressif/tools/xtensa-esp32-elf/esp-2021r1-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cristian/Documents/Development/iOLED/firmware/inti/build/project_elf_src_esp32.c > CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.i

CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.s"
	/Users/cristian/.espressif/tools/xtensa-esp32-elf/esp-2021r1-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cristian/Documents/Development/iOLED/firmware/inti/build/project_elf_src_esp32.c -o CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.s

# Object files for target app-template.elf
app__template_elf_OBJECTS = \
"CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj"

# External object files for target app-template.elf
app__template_elf_EXTERNAL_OBJECTS =

app-template.elf: CMakeFiles/app-template.elf.dir/project_elf_src_esp32.c.obj
app-template.elf: CMakeFiles/app-template.elf.dir/build.make
app-template.elf: esp-idf/mbedtls/libmbedtls.a
app-template.elf: esp-idf/efuse/libefuse.a
app-template.elf: esp-idf/app_update/libapp_update.a
app-template.elf: esp-idf/bootloader_support/libbootloader_support.a
app-template.elf: esp-idf/esp_ipc/libesp_ipc.a
app-template.elf: esp-idf/spi_flash/libspi_flash.a
app-template.elf: esp-idf/nvs_flash/libnvs_flash.a
app-template.elf: esp-idf/pthread/libpthread.a
app-template.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
app-template.elf: esp-idf/espcoredump/libespcoredump.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: esp-idf/esp_system/libesp_system.a
app-template.elf: esp-idf/esp_rom/libesp_rom.a
app-template.elf: esp-idf/hal/libhal.a
app-template.elf: esp-idf/vfs/libvfs.a
app-template.elf: esp-idf/esp_eth/libesp_eth.a
app-template.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
app-template.elf: esp-idf/esp_netif/libesp_netif.a
app-template.elf: esp-idf/esp_event/libesp_event.a
app-template.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
app-template.elf: esp-idf/esp_wifi/libesp_wifi.a
app-template.elf: esp-idf/lwip/liblwip.a
app-template.elf: esp-idf/log/liblog.a
app-template.elf: esp-idf/heap/libheap.a
app-template.elf: esp-idf/soc/libsoc.a
app-template.elf: esp-idf/esp_hw_support/libesp_hw_support.a
app-template.elf: esp-idf/esp_pm/libesp_pm.a
app-template.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
app-template.elf: esp-idf/driver/libdriver.a
app-template.elf: esp-idf/xtensa/libxtensa.a
app-template.elf: esp-idf/perfmon/libperfmon.a
app-template.elf: esp-idf/esp32/libesp32.a
app-template.elf: esp-idf/esp_common/libesp_common.a
app-template.elf: esp-idf/esp_timer/libesp_timer.a
app-template.elf: esp-idf/freertos/libfreertos.a
app-template.elf: esp-idf/newlib/libnewlib.a
app-template.elf: esp-idf/cxx/libcxx.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: esp-idf/asio/libasio.a
app-template.elf: esp-idf/cbor/libcbor.a
app-template.elf: esp-idf/unity/libunity.a
app-template.elf: esp-idf/cmock/libcmock.a
app-template.elf: esp-idf/coap/libcoap.a
app-template.elf: esp-idf/console/libconsole.a
app-template.elf: esp-idf/nghttp/libnghttp.a
app-template.elf: esp-idf/esp-tls/libesp-tls.a
app-template.elf: esp-idf/esp_adc_cal/libesp_adc_cal.a
app-template.elf: esp-idf/esp_hid/libesp_hid.a
app-template.elf: esp-idf/tcp_transport/libtcp_transport.a
app-template.elf: esp-idf/esp_http_client/libesp_http_client.a
app-template.elf: esp-idf/esp_http_server/libesp_http_server.a
app-template.elf: esp-idf/esp_https_ota/libesp_https_ota.a
app-template.elf: esp-idf/esp_lcd/libesp_lcd.a
app-template.elf: esp-idf/protobuf-c/libprotobuf-c.a
app-template.elf: esp-idf/protocomm/libprotocomm.a
app-template.elf: esp-idf/mdns/libmdns.a
app-template.elf: esp-idf/esp_local_ctrl/libesp_local_ctrl.a
app-template.elf: esp-idf/sdmmc/libsdmmc.a
app-template.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
app-template.elf: esp-idf/esp_websocket_client/libesp_websocket_client.a
app-template.elf: esp-idf/expat/libexpat.a
app-template.elf: esp-idf/wear_levelling/libwear_levelling.a
app-template.elf: esp-idf/fatfs/libfatfs.a
app-template.elf: esp-idf/freemodbus/libfreemodbus.a
app-template.elf: esp-idf/jsmn/libjsmn.a
app-template.elf: esp-idf/json/libjson.a
app-template.elf: esp-idf/libsodium/liblibsodium.a
app-template.elf: esp-idf/mqtt/libmqtt.a
app-template.elf: esp-idf/openssl/libopenssl.a
app-template.elf: esp-idf/spiffs/libspiffs.a
app-template.elf: esp-idf/ulp/libulp.a
app-template.elf: esp-idf/wifi_provisioning/libwifi_provisioning.a
app-template.elf: esp-idf/main/libmain.a
app-template.elf: esp-idf/led_strip/libled_strip.a
app-template.elf: esp-idf/asio/libasio.a
app-template.elf: esp-idf/cbor/libcbor.a
app-template.elf: esp-idf/cmock/libcmock.a
app-template.elf: esp-idf/unity/libunity.a
app-template.elf: esp-idf/coap/libcoap.a
app-template.elf: esp-idf/esp_adc_cal/libesp_adc_cal.a
app-template.elf: esp-idf/esp_hid/libesp_hid.a
app-template.elf: esp-idf/esp_lcd/libesp_lcd.a
app-template.elf: esp-idf/esp_local_ctrl/libesp_local_ctrl.a
app-template.elf: esp-idf/esp_websocket_client/libesp_websocket_client.a
app-template.elf: esp-idf/expat/libexpat.a
app-template.elf: esp-idf/fatfs/libfatfs.a
app-template.elf: esp-idf/wear_levelling/libwear_levelling.a
app-template.elf: esp-idf/freemodbus/libfreemodbus.a
app-template.elf: esp-idf/jsmn/libjsmn.a
app-template.elf: esp-idf/libsodium/liblibsodium.a
app-template.elf: esp-idf/mqtt/libmqtt.a
app-template.elf: esp-idf/openssl/libopenssl.a
app-template.elf: esp-idf/spiffs/libspiffs.a
app-template.elf: esp-idf/wifi_provisioning/libwifi_provisioning.a
app-template.elf: esp-idf/protocomm/libprotocomm.a
app-template.elf: esp-idf/protobuf-c/libprotobuf-c.a
app-template.elf: esp-idf/mdns/libmdns.a
app-template.elf: esp-idf/console/libconsole.a
app-template.elf: esp-idf/json/libjson.a
app-template.elf: esp-idf/mbedtls/libmbedtls.a
app-template.elf: esp-idf/efuse/libefuse.a
app-template.elf: esp-idf/app_update/libapp_update.a
app-template.elf: esp-idf/bootloader_support/libbootloader_support.a
app-template.elf: esp-idf/esp_ipc/libesp_ipc.a
app-template.elf: esp-idf/spi_flash/libspi_flash.a
app-template.elf: esp-idf/nvs_flash/libnvs_flash.a
app-template.elf: esp-idf/pthread/libpthread.a
app-template.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
app-template.elf: esp-idf/espcoredump/libespcoredump.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: esp-idf/esp_system/libesp_system.a
app-template.elf: esp-idf/esp_rom/libesp_rom.a
app-template.elf: esp-idf/hal/libhal.a
app-template.elf: esp-idf/vfs/libvfs.a
app-template.elf: esp-idf/esp_eth/libesp_eth.a
app-template.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
app-template.elf: esp-idf/esp_netif/libesp_netif.a
app-template.elf: esp-idf/esp_event/libesp_event.a
app-template.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
app-template.elf: esp-idf/esp_wifi/libesp_wifi.a
app-template.elf: esp-idf/lwip/liblwip.a
app-template.elf: esp-idf/log/liblog.a
app-template.elf: esp-idf/heap/libheap.a
app-template.elf: esp-idf/soc/libsoc.a
app-template.elf: esp-idf/esp_hw_support/libesp_hw_support.a
app-template.elf: esp-idf/esp_pm/libesp_pm.a
app-template.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
app-template.elf: esp-idf/driver/libdriver.a
app-template.elf: esp-idf/xtensa/libxtensa.a
app-template.elf: esp-idf/perfmon/libperfmon.a
app-template.elf: esp-idf/esp32/libesp32.a
app-template.elf: esp-idf/esp_common/libesp_common.a
app-template.elf: esp-idf/esp_timer/libesp_timer.a
app-template.elf: esp-idf/freertos/libfreertos.a
app-template.elf: esp-idf/newlib/libnewlib.a
app-template.elf: esp-idf/cxx/libcxx.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: esp-idf/nghttp/libnghttp.a
app-template.elf: esp-idf/esp-tls/libesp-tls.a
app-template.elf: esp-idf/tcp_transport/libtcp_transport.a
app-template.elf: esp-idf/esp_http_client/libesp_http_client.a
app-template.elf: esp-idf/esp_http_server/libesp_http_server.a
app-template.elf: esp-idf/esp_https_ota/libesp_https_ota.a
app-template.elf: esp-idf/sdmmc/libsdmmc.a
app-template.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
app-template.elf: esp-idf/ulp/libulp.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
app-template.elf: esp-idf/mbedtls/libmbedtls.a
app-template.elf: esp-idf/efuse/libefuse.a
app-template.elf: esp-idf/app_update/libapp_update.a
app-template.elf: esp-idf/bootloader_support/libbootloader_support.a
app-template.elf: esp-idf/esp_ipc/libesp_ipc.a
app-template.elf: esp-idf/spi_flash/libspi_flash.a
app-template.elf: esp-idf/nvs_flash/libnvs_flash.a
app-template.elf: esp-idf/pthread/libpthread.a
app-template.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
app-template.elf: esp-idf/espcoredump/libespcoredump.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: esp-idf/esp_system/libesp_system.a
app-template.elf: esp-idf/esp_rom/libesp_rom.a
app-template.elf: esp-idf/hal/libhal.a
app-template.elf: esp-idf/vfs/libvfs.a
app-template.elf: esp-idf/esp_eth/libesp_eth.a
app-template.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
app-template.elf: esp-idf/esp_netif/libesp_netif.a
app-template.elf: esp-idf/esp_event/libesp_event.a
app-template.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
app-template.elf: esp-idf/esp_wifi/libesp_wifi.a
app-template.elf: esp-idf/lwip/liblwip.a
app-template.elf: esp-idf/log/liblog.a
app-template.elf: esp-idf/heap/libheap.a
app-template.elf: esp-idf/soc/libsoc.a
app-template.elf: esp-idf/esp_hw_support/libesp_hw_support.a
app-template.elf: esp-idf/esp_pm/libesp_pm.a
app-template.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
app-template.elf: esp-idf/driver/libdriver.a
app-template.elf: esp-idf/xtensa/libxtensa.a
app-template.elf: esp-idf/perfmon/libperfmon.a
app-template.elf: esp-idf/esp32/libesp32.a
app-template.elf: esp-idf/esp_common/libesp_common.a
app-template.elf: esp-idf/esp_timer/libesp_timer.a
app-template.elf: esp-idf/freertos/libfreertos.a
app-template.elf: esp-idf/newlib/libnewlib.a
app-template.elf: esp-idf/cxx/libcxx.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: esp-idf/nghttp/libnghttp.a
app-template.elf: esp-idf/esp-tls/libesp-tls.a
app-template.elf: esp-idf/tcp_transport/libtcp_transport.a
app-template.elf: esp-idf/esp_http_client/libesp_http_client.a
app-template.elf: esp-idf/esp_http_server/libesp_http_server.a
app-template.elf: esp-idf/esp_https_ota/libesp_https_ota.a
app-template.elf: esp-idf/sdmmc/libsdmmc.a
app-template.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
app-template.elf: esp-idf/ulp/libulp.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
app-template.elf: esp-idf/mbedtls/libmbedtls.a
app-template.elf: esp-idf/efuse/libefuse.a
app-template.elf: esp-idf/app_update/libapp_update.a
app-template.elf: esp-idf/bootloader_support/libbootloader_support.a
app-template.elf: esp-idf/esp_ipc/libesp_ipc.a
app-template.elf: esp-idf/spi_flash/libspi_flash.a
app-template.elf: esp-idf/nvs_flash/libnvs_flash.a
app-template.elf: esp-idf/pthread/libpthread.a
app-template.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
app-template.elf: esp-idf/espcoredump/libespcoredump.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: esp-idf/esp_system/libesp_system.a
app-template.elf: esp-idf/esp_rom/libesp_rom.a
app-template.elf: esp-idf/hal/libhal.a
app-template.elf: esp-idf/vfs/libvfs.a
app-template.elf: esp-idf/esp_eth/libesp_eth.a
app-template.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
app-template.elf: esp-idf/esp_netif/libesp_netif.a
app-template.elf: esp-idf/esp_event/libesp_event.a
app-template.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
app-template.elf: esp-idf/esp_wifi/libesp_wifi.a
app-template.elf: esp-idf/lwip/liblwip.a
app-template.elf: esp-idf/log/liblog.a
app-template.elf: esp-idf/heap/libheap.a
app-template.elf: esp-idf/soc/libsoc.a
app-template.elf: esp-idf/esp_hw_support/libesp_hw_support.a
app-template.elf: esp-idf/esp_pm/libesp_pm.a
app-template.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
app-template.elf: esp-idf/driver/libdriver.a
app-template.elf: esp-idf/xtensa/libxtensa.a
app-template.elf: esp-idf/perfmon/libperfmon.a
app-template.elf: esp-idf/esp32/libesp32.a
app-template.elf: esp-idf/esp_common/libesp_common.a
app-template.elf: esp-idf/esp_timer/libesp_timer.a
app-template.elf: esp-idf/freertos/libfreertos.a
app-template.elf: esp-idf/newlib/libnewlib.a
app-template.elf: esp-idf/cxx/libcxx.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: esp-idf/nghttp/libnghttp.a
app-template.elf: esp-idf/esp-tls/libesp-tls.a
app-template.elf: esp-idf/tcp_transport/libtcp_transport.a
app-template.elf: esp-idf/esp_http_client/libesp_http_client.a
app-template.elf: esp-idf/esp_http_server/libesp_http_server.a
app-template.elf: esp-idf/esp_https_ota/libesp_https_ota.a
app-template.elf: esp-idf/sdmmc/libsdmmc.a
app-template.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
app-template.elf: esp-idf/ulp/libulp.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
app-template.elf: esp-idf/mbedtls/libmbedtls.a
app-template.elf: esp-idf/efuse/libefuse.a
app-template.elf: esp-idf/app_update/libapp_update.a
app-template.elf: esp-idf/bootloader_support/libbootloader_support.a
app-template.elf: esp-idf/esp_ipc/libesp_ipc.a
app-template.elf: esp-idf/spi_flash/libspi_flash.a
app-template.elf: esp-idf/nvs_flash/libnvs_flash.a
app-template.elf: esp-idf/pthread/libpthread.a
app-template.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
app-template.elf: esp-idf/espcoredump/libespcoredump.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: esp-idf/esp_system/libesp_system.a
app-template.elf: esp-idf/esp_rom/libesp_rom.a
app-template.elf: esp-idf/hal/libhal.a
app-template.elf: esp-idf/vfs/libvfs.a
app-template.elf: esp-idf/esp_eth/libesp_eth.a
app-template.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
app-template.elf: esp-idf/esp_netif/libesp_netif.a
app-template.elf: esp-idf/esp_event/libesp_event.a
app-template.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
app-template.elf: esp-idf/esp_wifi/libesp_wifi.a
app-template.elf: esp-idf/lwip/liblwip.a
app-template.elf: esp-idf/log/liblog.a
app-template.elf: esp-idf/heap/libheap.a
app-template.elf: esp-idf/soc/libsoc.a
app-template.elf: esp-idf/esp_hw_support/libesp_hw_support.a
app-template.elf: esp-idf/esp_pm/libesp_pm.a
app-template.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
app-template.elf: esp-idf/driver/libdriver.a
app-template.elf: esp-idf/xtensa/libxtensa.a
app-template.elf: esp-idf/perfmon/libperfmon.a
app-template.elf: esp-idf/esp32/libesp32.a
app-template.elf: esp-idf/esp_common/libesp_common.a
app-template.elf: esp-idf/esp_timer/libesp_timer.a
app-template.elf: esp-idf/freertos/libfreertos.a
app-template.elf: esp-idf/newlib/libnewlib.a
app-template.elf: esp-idf/cxx/libcxx.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: esp-idf/nghttp/libnghttp.a
app-template.elf: esp-idf/esp-tls/libesp-tls.a
app-template.elf: esp-idf/tcp_transport/libtcp_transport.a
app-template.elf: esp-idf/esp_http_client/libesp_http_client.a
app-template.elf: esp-idf/esp_http_server/libesp_http_server.a
app-template.elf: esp-idf/esp_https_ota/libesp_https_ota.a
app-template.elf: esp-idf/sdmmc/libsdmmc.a
app-template.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
app-template.elf: esp-idf/ulp/libulp.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
app-template.elf: esp-idf/mbedtls/libmbedtls.a
app-template.elf: esp-idf/efuse/libefuse.a
app-template.elf: esp-idf/app_update/libapp_update.a
app-template.elf: esp-idf/bootloader_support/libbootloader_support.a
app-template.elf: esp-idf/esp_ipc/libesp_ipc.a
app-template.elf: esp-idf/spi_flash/libspi_flash.a
app-template.elf: esp-idf/nvs_flash/libnvs_flash.a
app-template.elf: esp-idf/pthread/libpthread.a
app-template.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
app-template.elf: esp-idf/espcoredump/libespcoredump.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: esp-idf/esp_system/libesp_system.a
app-template.elf: esp-idf/esp_rom/libesp_rom.a
app-template.elf: esp-idf/hal/libhal.a
app-template.elf: esp-idf/vfs/libvfs.a
app-template.elf: esp-idf/esp_eth/libesp_eth.a
app-template.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
app-template.elf: esp-idf/esp_netif/libesp_netif.a
app-template.elf: esp-idf/esp_event/libesp_event.a
app-template.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
app-template.elf: esp-idf/esp_wifi/libesp_wifi.a
app-template.elf: esp-idf/lwip/liblwip.a
app-template.elf: esp-idf/log/liblog.a
app-template.elf: esp-idf/heap/libheap.a
app-template.elf: esp-idf/soc/libsoc.a
app-template.elf: esp-idf/esp_hw_support/libesp_hw_support.a
app-template.elf: esp-idf/esp_pm/libesp_pm.a
app-template.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
app-template.elf: esp-idf/driver/libdriver.a
app-template.elf: esp-idf/xtensa/libxtensa.a
app-template.elf: esp-idf/perfmon/libperfmon.a
app-template.elf: esp-idf/esp32/libesp32.a
app-template.elf: esp-idf/esp_common/libesp_common.a
app-template.elf: esp-idf/esp_timer/libesp_timer.a
app-template.elf: esp-idf/freertos/libfreertos.a
app-template.elf: esp-idf/newlib/libnewlib.a
app-template.elf: esp-idf/cxx/libcxx.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: esp-idf/nghttp/libnghttp.a
app-template.elf: esp-idf/esp-tls/libesp-tls.a
app-template.elf: esp-idf/tcp_transport/libtcp_transport.a
app-template.elf: esp-idf/esp_http_client/libesp_http_client.a
app-template.elf: esp-idf/esp_http_server/libesp_http_server.a
app-template.elf: esp-idf/esp_https_ota/libesp_https_ota.a
app-template.elf: esp-idf/sdmmc/libsdmmc.a
app-template.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
app-template.elf: esp-idf/ulp/libulp.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
app-template.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: esp-idf/esp_phy/libesp_phy.a
app-template.elf: /Users/cristian/esp/esp-idf/components/xtensa/esp32/libxt_hal.a
app-template.elf: esp-idf/newlib/libnewlib.a
app-template.elf: esp-idf/pthread/libpthread.a
app-template.elf: esp-idf/cxx/libcxx.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: esp-idf/app_trace/libapp_trace.a
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.ld
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.api.ld
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.libgcc.ld
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-data.ld
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.syscalls.ld
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-funcs.ld
app-template.elf: /Users/cristian/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-time.ld
app-template.elf: esp-idf/esp32/esp32_out.ld
app-template.elf: esp-idf/esp32/ld/esp32.project.ld
app-template.elf: /Users/cristian/esp/esp-idf/components/esp32/ld/esp32.peripherals.ld
app-template.elf: CMakeFiles/app-template.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cristian/Documents/Development/iOLED/firmware/inti/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable app-template.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app-template.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app-template.elf.dir/build: app-template.elf
.PHONY : CMakeFiles/app-template.elf.dir/build

CMakeFiles/app-template.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app-template.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app-template.elf.dir/clean

CMakeFiles/app-template.elf.dir/depend: project_elf_src_esp32.c
	cd /Users/cristian/Documents/Development/iOLED/firmware/inti/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cristian/Documents/Development/iOLED/firmware/inti /Users/cristian/Documents/Development/iOLED/firmware/inti /Users/cristian/Documents/Development/iOLED/firmware/inti/build /Users/cristian/Documents/Development/iOLED/firmware/inti/build /Users/cristian/Documents/Development/iOLED/firmware/inti/build/CMakeFiles/app-template.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app-template.elf.dir/depend

