#!/bin/sh
DAEMON=/usr/bin/wlan_service
NAME=wlan_service
ARGS=""

#test -f $DAEMON || exit 0

#set -e

echo "Mac Address copy test"

set_wifi_macAddr()
{
WLAN_MAC_BIN="wlan_mac.bin"
WLAN_MAC_DPS="wifiMac"
BIN_PREFIX0="Intf0MacAddress="
BIN_PREFIX1="Intf1MacAddress="

if [ -e "$WLAN_MAC_BIN" ]
then
    echo "Found wlan_mac.bin, setting MAC address"
else
    #Create the wlan_mac.bin file for the QCA driver
    echo "wlan_mac.bin was not found, creating...."
    echo "" > $WLAN_MAC_BIN
    chmod 775 $WLAN_MAC_BIN
fi

if [ -e "$WLAN_MAC_DPS" ]
then
    echo "Reading MAC address from /dps"
    #Remove the ":" from the address in dps
    macAddress=$(cat "$WLAN_MAC_DPS")
    macAddress="${macAddress//:}"
else
    echo "The dps file was not present!"
    return
fi

echo "Setting MAC address in wlan_mac.bin"
echo "$BIN_PREFIX0$macAddress" > $WLAN_MAC_BIN
echo "$BIN_PREFIX1$macAddress" >> $WLAN_MAC_BIN
echo "END" >> $WLAN_MAC_BIN
}


set_wifi_macAddr


echo "$macAddress"

exit 0

