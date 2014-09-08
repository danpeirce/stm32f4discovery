# Example Virtual COM Port for STM32F4Discovery Board and em::blocks

The ST documentation assumes one is using a proprietary IDE. I have opted to try the 
open source free em::Blocks.

An example of using the discovery board as a USB CDC class Virtual COM Port is given at 
http://www.emblocks.org/forum/viewtopic.php?f=26&t=171 . The only file changed from the vcp_wo_rtos.zip
package at the link is *main.c*. The altered version of the file is available here.