# stm32f1xx_drivers

MCU   :   stm32f103c8

OpenOCD Debugger and Semi-hosting
======================================
Set the linker arguments 
-specs=rdimon.specs -lc -lrdimon

Add semi-hosting run command
monitor arm semihosting enable 

Add the below function call to main.c 
extern void initialise_monitor_handles(void);
initialise_monitor_handles(void);


if openocd not work:


C:\Ac6\SystemWorkbench\plugins\fr.ac6.mcu.debug_2.5.0.201904120827\resources\openocd\st_scripts\target\stm32f1x.cfg

add this line before first if statement

set CPUTAPID 0

it solves all openocd stlink id errors

(or)

C:\Ac6\SystemWorkbench\plugins\fr.ac6.mcu.debug_2.5.0.201904120827\resources\openocd\st_scripts\interface\stlink.cfg(or stlink-v2.cfg or stlink-v2-1.cfg)

add hla_vid_pid 0
