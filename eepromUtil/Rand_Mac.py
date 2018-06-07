
#*****************************************************************************/
#
# Rand_Mac.py - sets a random mac address into the bdwlan30.bin and uploads to TCU
#
#*****************************************************************************

'''Rand_Mac.py:

Description:
Run the Rand_Mac.py to load a TCU with a random wlan MAC address

Requiremnets:
    zip file containing: EepromUtilTxt2Bin_ar6320.exe
                         eeprom_ar6320_1.tpl
                         bdwlan30_org.txt
                         bdwlan30.bin
    TCU with adb connection:

Usage:
      python Rand_Mac.py

'''

#---------------------------------------------------------#
# Import libraries                                        #
#---------------------------------------------------------#
import sys
import os
import subprocess
import random
import fileinput
from random import *

#---------------------------------------------------------#
# Define a handler to exit when Ctrl+C is pressed         #
#---------------------------------------------------------#
def interrupt_handler(signum, frame):
   sys.exit("Exiting")

#---------------------------------------------------------#
# Define fuction to call eepromUtil and convert txt to bin#
#---------------------------------------------------------#
def Convert_bin():
    print 'Running eeprom Tool to convert bdwlan30.txt to .bin file (text output hidden)'

    #using subprocess to run Eeprom cmd to avoid overflowing the screen with prints
    subprocess.check_output(['EepromUtilTxt2Bin_ar6320.exe','eeprom_ar6320_1.tpl','bdwlan30.txt','bdwlan30.bin'], shell=True)

#---------------------------------------------------------#
# Define fuction to input a random Mac address to bin.txt #
#---------------------------------------------------------#
def update_mac_address():
    Mac_address = "macAddr__0_0"
    Mac_print =""

    if not os.path.exists('bdwlan30.txt'):
        sys.exit('Error - Missing bdwlan30.txt file...')

    for x in range(0,6):
        hex_num = os.urandom(1).encode('hex')
        y = str(hex_num)
        Mac_address += ' 0x' + y
        if x < 5:
            Mac_print += y + ":"
        else:
            Mac_print += y
    print "TCU will be updated to have a MAC address of - " + Mac_print + "\n"

    f = fileinput.FileInput("bdwlan30.txt", inplace=True, backup='.bak')
    for line in f:
        if line.startswith("macAddr"):
            print Mac_address
        else:
            print line, #comma after line prevents a newline from printing
    f.close()

#---------------------------------------------------------#
# Define fuction to call adb and push .bin file to TCU    #
#---------------------------------------------------------#
def push_bin_to_TCU():

    if not os.path.exists('bdwlan30.bin'):
        sys.exit('Error - No bdwlan30.bin file found')

    print "Running adb devices to ensure adb server is running...\n"
    os.system("adb devices")
    os.system("adb push bdwlan30.bin /lib/firmware/image/bdwlan30.bin")
    os.system("adb shell \"chmod 775 /lib/firmware/image/bdwlan30.bin\"")
    os.system("adb shell \"rmmod wlan_sdio.ko\"")
    print "Waiting for driver to load....\n"
    os.system("adb shell \"insmod /lib/modules/3.18.66/extra/wlan_sdio.ko\"")
    os.system("adb shell \"ifconfig wlan0\"")
#---------------------------------------------------------#
# Define main code                                        #
#---------------------------------------------------------#
if __name__ == "__main__":
    update_mac_address()
    Convert_bin()
    push_bin_to_TCU()
    print 'TCU has been updated with a random MAC Address'
